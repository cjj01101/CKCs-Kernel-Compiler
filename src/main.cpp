#include <stdio.h>
#include "AbstractSyntaxTree.h"

ASTNode *root = nullptr;

extern void GenerateSyntaxTree(FILE *input);

int main(int argc, char ** argv){

	FILE *input_file = stdin;

    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp != NULL) input_file = fp;
    }

    GenerateSyntaxTree(input_file);
    AbstractSyntaxTree synTree(root);

    synTree.Print();

    return 0;
}