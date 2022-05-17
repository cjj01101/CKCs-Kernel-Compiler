#include "CodeGenerator.h"

#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/IR/LegacyPassManager.h"

void CodeGenerator::InitializeLLVM() {
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
}

void CodeGenerator::PrintIR() {
    module.print(llvm::outs(), nullptr);
}

void CodeGenerator::GenerateTarget() {
    // Initialize the target registry etc.
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    auto targetTriple = llvm::sys::getDefaultTargetTriple();
    module.setTargetTriple(targetTriple);

    std::string error;
    auto target = llvm::TargetRegistry::lookupTarget(targetTriple, error);
    if (!target) {
        llvm::errs() << error;
        // return 1;
        return;
    }

    llvm::TargetOptions opt;
    auto rm = llvm::Optional<llvm::Reloc::Model>();
    auto targetMachine = target->createTargetMachine(targetTriple, "generic", "", opt, rm);

    module.setDataLayout(targetMachine->createDataLayout());

    auto filename = "cc.o";
    std::error_code errorCode;
    llvm::raw_fd_ostream dest(filename, errorCode, llvm::sys::fs::OF_None);

    if (errorCode) {
        llvm::errs() << "Could not open file: " << errorCode.message();
        return;
    }

    llvm::legacy::PassManager pass;
    auto fileType = llvm::CGFT_ObjectFile;

    if (targetMachine->addPassesToEmitFile(pass, dest, nullptr, fileType)) {
        llvm::errs() << "Target Machine can't emit a file of this type";
        return;
    }

    pass.run(module);
    dest.flush();

    return;
}

llvm::Type *CodeGenerator::ConvertToLLVMType(Type type) {
    switch (type)
    {
        case Type::INTEGER: return llvm::Type::getInt32Ty(context);
        case Type::FLOAT: return llvm::Type::getDoubleTy(context);
        case Type::BOOLEAN: return llvm::Type::getInt1Ty(context);
        case Type::VOID: return llvm::Type::getVoidTy(context);
        default: fprintf(stderr, "Unknown Type."); return nullptr;
    }
}

llvm::Type *CodeGenerator::ConvertToLLVMPtrType(Type type) {
    switch (type)
    {
        case Type::INTEGER: return llvm::Type::getInt32PtrTy(context);
        case Type::FLOAT: return llvm::Type::getDoublePtrTy(context);
        case Type::BOOLEAN: return llvm::Type::getInt1PtrTy(context);
        case Type::VOID: return llvm::Type::getInt32PtrTy(context);
        default: fprintf(stderr, "Unknown Type."); return nullptr;
    }
}

llvm::Value *CodeGenerator::CastValueType(llvm::Value *origin, Type from, Type to) {

    switch(to) {

        case Type::BOOLEAN:
            switch(from) {
                case Type::BOOLEAN: return origin;
                case Type::INTEGER: return builder.CreateICmpNE(origin, builder.getInt32(0), "bcasttmp");
                case Type::FLOAT: return builder.CreateFCmpONE(origin, llvm::ConstantFP::get(builder.getDoubleTy(), 0.0), "bcasttmp");
            }

        case Type::INTEGER:
            switch(from) {
                case Type::BOOLEAN: return builder.CreateIntCast(origin, builder.getInt32Ty(), false, "icasttmp");
                case Type::INTEGER: return origin;
                case Type::FLOAT: return builder.CreateFPToSI(origin, builder.getInt32Ty(), "icasttmp");
            }

        case Type::FLOAT:
            switch(from) {
                case Type::BOOLEAN: return builder.CreateUIToFP(origin, builder.getDoubleTy(), "fcasttmp");
                case Type::INTEGER: return builder.CreateSIToFP(origin, builder.getDoubleTy(), "fcasttmp");
                case Type::FLOAT: return origin;
            }

    }

    assert(false);
    return nullptr;
}

llvm::Value *CodeGenerator::CastValueType(llvm::Value *origin, Type from, llvm::Type *to) {

    if(to->isIntegerTy(1)) {

        switch(from) {
            case Type::BOOLEAN: return origin;
            case Type::INTEGER: return builder.CreateICmpNE(origin, builder.getInt32(0), "bcasttmp");
            case Type::FLOAT: return builder.CreateFCmpONE(origin, llvm::ConstantFP::get(builder.getDoubleTy(), 0.0), "bcasttmp");
        }

    }

    else if(to->isIntegerTy(32)) {

        switch(from) {
            case Type::BOOLEAN: return builder.CreateIntCast(origin, builder.getInt32Ty(), false, "icasttmp");
            case Type::INTEGER: return origin;
            case Type::FLOAT: return builder.CreateFPToSI(origin, builder.getInt32Ty(), "icasttmp");
        }
    }

    else if(to->isFloatingPointTy()) {
        switch(from) {
            case Type::BOOLEAN: return builder.CreateUIToFP(origin, builder.getDoubleTy(), "fcasttmp");
            case Type::INTEGER: return builder.CreateSIToFP(origin, builder.getDoubleTy(), "fcasttmp");
            case Type::FLOAT: return origin;
        }
    }

    assert(false);
    return nullptr;
}

llvm::Value *CodeGenerator::FindValue(const std::string &name) {
    for(auto it = tables.rbegin(); it != tables.rend(); it++) {
        auto vit = it->find(name);
        if(vit != it->end()) return vit->second;
    }
    return nullptr;
}