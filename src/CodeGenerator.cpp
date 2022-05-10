#include "CodeGenerator.h"

#include "llvm/Support/TargetSelect.h"

void CodeGenerator::InitializeLLVM() {
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
}

void CodeGenerator::PrintIR() {
    module.print(llvm::outs(), nullptr);
}

llvm::Type *CodeGenerator::ConvertToLLVMType(Type type) {
    switch (type)
    {
        case Type::INTEGER: return llvm::Type::getInt32Ty(context);
        case Type::FLOAT: return llvm::Type::getDoubleTy(context);
        case Type::VOID: return llvm::Type::getVoidTy(context);
        default: return nullptr;
    }
}

llvm::Type *CodeGenerator::ConvertToLLVMPtrType(Type type) {
    switch (type)
    {
        case Type::INTEGER: return llvm::Type::getInt32PtrTy(context);
        case Type::FLOAT: return llvm::Type::getDoublePtrTy(context);
        case Type::VOID: return llvm::Type::getInt32PtrTy(context);
        default: return nullptr;
    }
}

llvm::Constant *CodeGenerator::GetTypeDefaultValue(Type type) {
    switch(type) {
        // TO DO : analyze int a = 1 + b * 3; Type::VOID
        case Type::INTEGER: return llvm::ConstantInt::get(builder.getInt32Ty(), 0);
        case Type::FLOAT: return llvm::ConstantFP::get(builder.getDoubleTy(), 0.0);
        case Type::VOID: return nullptr;
        default: return nullptr;
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

llvm::Value *CodeGenerator::FindValue(const std::string &name) {
    for(auto it = tables.rbegin(); it != tables.rend(); it++) {
        auto vit = it->find(name);
        if(vit != it->end()) return vit->second;
    }
    return nullptr;
}