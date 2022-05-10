#include <assert.h>
#include <stdio.h>
#include "OperatorNode.h"
#include "Utility.h"
#include "CodeGenerator.h"

using namespace TypeUtils;

/*        CONSTRUCT FUNCTION        */

BinaryOpNode::BinaryOpNode(Operator op, ExpressionNode *left, ExpressionNode *right)
	: ExpressionNode(), leftOperand(left), rightOperand(right), op(op)
{
	assert(NOT_NULL(left));
	assert(NOT_NULL(right));
}

BinaryOpNode::~BinaryOpNode() {
	delete leftOperand;
	delete rightOperand;
}

AssignOpNode::AssignOpNode(IdentifierNode *left, ExpressionNode *right)
	: ExpressionNode(), leftValue(left), rightValue(right)
{ 
	assert(NOT_NULL(left));
	assert(NOT_NULL(right));
}

AssignOpNode::~AssignOpNode() {
	delete leftValue;
	delete rightValue;
}

/*      CONSTRUCT FUNCTION END      */

/*         SEMANTIC ANALYZE         */

void BinaryOpNode::AnalyzeSemantic(SymbolTable *intab) {

	leftOperand->AnalyzeSemantic(intab);
	rightOperand->AnalyzeSemantic(intab);

	/* Start Type Checking */
	Type leftType = leftOperand->GetValueType();
	Type rightType = rightOperand->GetValueType();

    /* Validate Operand Types */
	if((leftType == Type::VOID || rightType == Type::VOID) ||
	   (IsIntegerOperator() && (leftType == Type::FLOAT || rightType == Type::FLOAT)))
	{
	   	char message[128];
		sprintf(message, "invalid operands of type '%s' and '%s' to binary operator '%s'.",
			GetTypeName(leftType), GetTypeName(rightType), GetOperatorName(op));
		throw ASTException(message);
	}

	/* Determine Value Type */
	valueType = IsLogicalOperator() ? Type::BOOLEAN
			  : IsRelationalOperator() ? Type::BOOLEAN
			  : IsIntegerOperator() ? Type::INTEGER
			  : IsArithmeticOperator() ? GetPromotedTypeBetween(Type::INTEGER, GetPromotedTypeBetween(leftType, rightType))
			  : GetPromotedTypeBetween(leftType, rightType);
}

void AssignOpNode::AnalyzeSemantic(SymbolTable *intab) {
	
	leftValue->AnalyzeSemantic(intab);
	rightValue->AnalyzeSemantic(intab);

	/* Start Type Checking */
	Type leftType = leftValue->GetValueType();
	Type rightType = rightValue->GetValueType();

	/* Validate Operand Types */
	if(!CanConvert(rightType, leftType)) {
		char message[128];
		sprintf(message, "cannot convert '%s' to '%s' in initialization.",
			GetTypeName(leftType), GetTypeName(rightType));
		throw ASTException(message);
	}

	/* Determine Value Type */
	valueType = leftType;

}

/*       SEMANTIC ANALYZE END       */

/*          PRINT FUNCTION          */

void BinaryOpNode::PrintContentInLevel(int level) const {

	printf("%s(%s)\n", GetOperatorName(op), GetTypeName(valueType));

	if(leftOperand) PRINT_CHILD_WITH_HINT(leftOperand, "LEFT");
	if(rightOperand) PRINT_CHILD_WITH_HINT(rightOperand, "RIGHT");

}

void AssignOpNode::PrintContentInLevel(int level) const {
	printf("Assign Expression\n");

	PRINT_CHILD_WITH_HINT(leftValue, "LEFT");
	PRINT_CHILD_WITH_HINT(rightValue, "RIGHT");
}

/*        PRINT FUNCTION END        */

/*         GENERATE IR CODE         */

llvm::Value *BinaryOpNode::GenerateIR(CodeGenerator *generator) {
    
    llvm::Value *L = leftOperand->GenerateIR(generator);
    llvm::Value *R = rightOperand->GenerateIR(generator);

    assert(L != nullptr && R != nullptr);

    Type leftType = leftOperand->GetValueType();
    Type rightType = rightOperand->GetValueType();
    Type opType = TypeUtils::GetPromotedTypeBetween(leftType, rightType);

    /* Cast Operands */

    /* Downcast to BOOLEAN if Logical Operation */
    if(IsLogicalOperator()) {
        L = generator->CastValueType(L, leftType, Type::BOOLEAN);
        R = generator->CastValueType(R, rightType, Type::BOOLEAN);
    }

    /* Upcast from BOOLEAN to INTEGER if Integer Operation
     * or Relational Operation with at Least 1 Interger Operands and no Float Operands
     * or Arithmetic Operation with Non-float Operands */
    else if(opType == Type::INTEGER || valueType == Type::INTEGER) {
        L = generator->CastValueType(L, leftType, Type::INTEGER);
        R = generator->CastValueType(R, rightType, Type::INTEGER);
    }

    /* Upcast to Float if Arithmetic/Relational Operation with at Least 1 Float Operands */
    else if (opType == Type::FLOAT) {
        L = generator->CastValueType(L, leftType, Type::FLOAT);
        R = generator->CastValueType(R, rightType, Type::FLOAT);
    }

    /* Compute Result */
    llvm::Value *res = nullptr;
    switch(op) {

        case Operator::ADD: {

            res = valueType == Type::FLOAT ? generator->builder.CreateFAdd(L, R, "faddtmp")
                : generator->builder.CreateAdd(L, R, "iaddtmp");
            break;

        }
        case Operator::SUB: {

            res = valueType == Type::FLOAT ? generator->builder.CreateFSub(L, R, "fsubtmp")
                : generator->builder.CreateSub(L, R, "isubtmp");
            break;

        }
        case Operator::MUL: {
        
            res = valueType == Type::FLOAT ? generator->builder.CreateFMul(L, R, "fmultmp")
                : generator->builder.CreateMul(L, R, "imultmp");
            break;

        }
        case Operator::DIV: {
        
            res = valueType == Type::FLOAT ? generator->builder.CreateFDiv(L, R, "fdivtmp")
                : generator->builder.CreateSDiv(L, R, "idivtmp");
            break;

        }
        case Operator::MOD: {

            res = generator->builder.CreateSRem(L, R, "modtmp");
            break;

        }
        case Operator::SHL: {

            res = generator->builder.CreateShl(L, R, "shltmp");
            break;

        }
        case Operator::SHR: {

            res = generator->builder.CreateAShr(L, R, "shrtmp");
            break;

        }
        case Operator::AND: {

            res = generator->builder.CreateAnd(L, R, "andtmp");
            break;

        }
        case Operator::OR: {

            res = generator->builder.CreateOr(L, R, "ortmp"); 
            break;

        }
        case Operator::XOR: {

            res = generator->builder.CreateXor(L, R, "xortmp"); 
            break;

        }
        case Operator::EQ: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOEQ(L, R, "feqtmp")
                : generator->builder.CreateICmpEQ(L, R, "ieqtmp");
            break;

        }
        case Operator::NEQ: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpONE(L, R, "fnetmp")
                : generator->builder.CreateICmpNE(L, R, "inetmp");
            break;

        }
        case Operator::GT: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOGT(L, R, "fgttmp")
                : generator->builder.CreateICmpSGT(L, R, "igttmp");
            break;
        
        }
        case Operator::GTE: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOGE(L, R, "fgetmp")
                : generator->builder.CreateICmpSGE(L, R, "igetmp");
            break;
        
        }
        case Operator::LT: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOLT(L, R, "flttmp")
                : generator->builder.CreateICmpSLT(L, R, "ilttmp");
            break;
        
        }
        case Operator::LTE: {

            res = opType == Type::FLOAT ? generator->builder.CreateFCmpOLE(L, R, "fletmp")
                : generator->builder.CreateICmpSLE(L, R, "iletmp");
            break;

        }
        case Operator::LOGAND: {

            res = generator->builder.CreateLogicalAnd(L, R, "logicandtmp");
            break;

        }
        case Operator::LOGOR: {

            res = generator->builder.CreateLogicalOr(L, R, "logicortmp");
            break;

        }
    }

    assert(res != nullptr);
    return res;
}

llvm::Value *AssignOpNode::GenerateIR(CodeGenerator *generator) {
    
    llvm::Value *L = generator->FindValue(std::string(leftValue->GetName()));
    assert(L != nullptr);

    llvm::Value *R = rightValue->GenerateIR(generator);
    R = generator->CastValueType(R, rightValue->GetValueType(), valueType);

    generator->builder.CreateStore(R, L);
    return R;
}

/*       GENERATE IR CODE END       */

/*        AUXILIARY FUNCTION        */

bool BinaryOpNode::IsArithmeticOperator() {
	return (op == Operator::ADD || op == Operator::SUB ||
	   		op == Operator::MUL || op == Operator::DIV);
}

bool BinaryOpNode::IsIntegerOperator() {
	return (op == Operator::OR || op == Operator::XOR ||
	   		op == Operator::AND || op == Operator::MOD ||
            op == Operator::SHL || op == Operator::SHR);
}

bool BinaryOpNode::IsLogicalOperator() {
	return (op == Operator::LOGOR || op == Operator::LOGAND);
}

bool BinaryOpNode::IsRelationalOperator() {
	return (op == Operator::EQ || op == Operator::NEQ ||
			op == Operator::LT || op == Operator::LTE || 
			op == Operator::GT || op == Operator::GTE);
}

const char *BinaryOpNode::GetOperatorName(Operator op) {

	const static char *operatorName[] = {
		#define OP(op) #op,
		OPERATORS
		#undef OP
	};

	return operatorName[static_cast<int>(op)];

}

/*      AUXILIARY FUNCTION END      */