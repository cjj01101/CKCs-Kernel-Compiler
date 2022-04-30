%{
    #include <stdio.h>
    #include "AbstractSyntaxTree.h"
    #include "ArithmeticNode.h"

    int yylex(void);
    void yyerror(char *);

    ASTNode *root = nullptr;
%}

%union {
    int intNum;
    ASTNode *node;
}

%token <intNum> INT
%token ADD SUB MUL DIV LP RP SEM

%type <node> exp term factor

%%

   command : sentence
           | command sentence
           ;

  sentence : exp SEM { $1->PrintInLevel(0); }
           | SEM 
           ;

       exp : exp ADD term { $$ = new ArithOpNode('+', $1, $3); }
           | exp SUB term { $$ = new ArithOpNode('-', $1, $3); }
           | SUB term { $$ = new ArithOpNode('-', new IntegerNode(0), $2); }
           | term { $$ = $1; }
           ;

      term : term MUL factor { $$ = new ArithOpNode('*', $1, $3); }
           | term DIV factor { $$ = new ArithOpNode('/', $1, $3); }
           | factor { $$ = $1; }
           ;

    factor : INT { $$ = new IntegerNode($1); }
           | LP exp RP { $$ = $2; }
           ;

%%

void yyerror(char *e) {
    fprintf(stderr, "error: %s\n", e);
}

int yywrap(){
    return 1;
}

void GenerateSyntaxTree(FILE *input, AbstractSyntaxTree &tree){
    extern FILE *yyin;
    yyin = input;
    yyparse();
}