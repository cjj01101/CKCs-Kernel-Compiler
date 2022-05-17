#include <stdio.h>
#include "AbstractSyntaxTree.h"
#include "SemanticAnalyzer.h"
#include "CodeGenerator.h"

extern ASTNode *parse_and_generate_syntax_tree(FILE *input);

int main(int argc, char ** argv){

	FILE *input_file = stdin;

    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp != NULL) input_file = fp;
    }

    ASTNode *root = parse_and_generate_syntax_tree(input_file);
    AbstractSyntaxTree synTree(root);

    try {
        SemanticAnalyzer analyzer;
        synTree.AnalyzeSemantic(&analyzer);

        synTree.Print();

        CodeGenerator::InitializeLLVM();
        CodeGenerator generator;
        synTree.GenerateIR(&generator);

        generator.PrintIR();
        generator.GenerateTarget();

    } catch (ASTException &e) {
        e.PrintMessage();
    }

    

    return 0;
}