#include <stdio.h>
#include "AbstractSyntaxTree.h"

extern void GenerateSyntaxTree(FILE *input, AbstractSyntaxTree &tree);

int main(int argc, char ** argv){

	FILE *input_file = stdin;

    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp != NULL) input_file = fp;
    }

    AbstractSyntaxTree synTree;
    GenerateSyntaxTree(input_file, synTree);

    return 0;
}