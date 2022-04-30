%{
    #include <stdio.h>
    #include "AbstractSyntaxTree.h"
    #include "ValueNode.h"
    #include "OperatorNode.h"
    #include "StatementNode.h"

    int yylex(void);
    void yyerror(char *);

    ASTNode *root = nullptr;
%}

%union {
    int intNum;
    char str[MAXVARLEN];
    ASTNode *node;
}

%token <intNum> INT
%token <str> ID
%token ADD SUB MUL DIV MOD EQ LP RP SEM

%type <node> statement exp arithexp term factor identifier integer

%%

    program : statement { if($1) $1->PrintInLevel(0); } program
            | /* empty */
            ;

  statement : exp SEM { $$ = new ExpressionStatementNode($1); }
            | SEM  { $$ = nullptr; }
            ;

        exp : identifier EQ exp { $$ = new AssignOpNode($1, $3); }
            | arithexp { $$ = $1; }
            ;

   arithexp : arithexp ADD term { $$ = new ArithOpNode('+', $1, $3); }
            | arithexp SUB term { $$ = new ArithOpNode('-', $1, $3); }
            | SUB term { $$ = new ArithOpNode('-', new IntegerNode(0), $2); }
            | term { $$ = $1; }
            ;

       term : term MUL factor { $$ = new ArithOpNode('*', $1, $3); }
            | term DIV factor { $$ = new ArithOpNode('/', $1, $3); }
            | term MOD factor { $$ = new ArithOpNode('%', $1, $3); }
            | factor { $$ = $1; }
            ;

     factor : identifier { $$ = $1; }
            | integer { $$ = $1; }
            | LP exp RP { $$ = $2; }
            ;

 identifier : ID { $$ = new VariableNode($1); }
            ;
 
    integer : INT { $$ = new IntegerNode($1); }
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