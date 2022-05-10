#include <stdio.h>
#include "AbstractSyntaxTree.h"
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
        synTree.AnalyzeSemantic();

        synTree.Print();

        CodeGenerator::InitializeLLVM();
        CodeGenerator cg;
        synTree.GenerateIR(&cg);

        cg.PrintIR();
    } catch (ASTException &e) {
        e.PrintMessage();
    }

    

    return 0;
}