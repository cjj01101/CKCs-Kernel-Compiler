%{
    #include <stdio.h>
    #include "AbstractSyntaxTree.h"
    #include "ValueNode.h"
    #include "OperatorNode.h"
    #include "DeclarationNode.h"
    #include "StatementNode.h"

    int yylex(void);
    void yyerror(char *);
    
    enum class type;

    ASTNode *root = nullptr;
%}

%union {
    int intNum;
    char str[MAXVARLEN];
    ASTNode *node;
}

%token <intNum> INT
%token <str> ID
%token TYPE_INT
%token ADD SUB MUL DIV MOD EQ LP RP SEM COMMA
%token IF ELSE WHILE FOR

%type <node> declaration type idlist
%type <node> statement exprstmt ctrlstmt
%type <node> expr arithexpr term factor identifier integer

%nonassoc IFX
%nonassoc ELSE

%%

    program : declaration { if($1) $1->PrintInLevel(0); } program
            | /* empty */
            ;

declaration : type idlist SEM { $$ = new DeclarationNode($2, $1); }
            | statement { $$ = $1; }
            ;

       type : TYPE_INT { $$ = new TypeNode(Type::INTEGER); }
            ;

     idlist : identifier { $$ = $1; }
            ;

  statement : exprstmt { $$ = $1; }
            | ctrlstmt { $$ = $1; }
            ;

   exprstmt : expr SEM { $$ = new ExpressionStatementNode($1); }
            | SEM  { $$ = new EmptyStatementNode(); }
            ;

       expr : identifier EQ expr { $$ = new AssignOpNode($1, $3); }
            | arithexpr { $$ = $1; }
            ;

  arithexpr : arithexpr ADD term { $$ = new ArithOpNode('+', $1, $3); }
            | arithexpr SUB term { $$ = new ArithOpNode('-', $1, $3); }
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
            | LP expr RP { $$ = $2; }
            ;

 identifier : ID { $$ = new VariableNode($1); }
            ;
 
    integer : INT { $$ = new IntegerNode($1); }
            ;

   ctrlstmt : IF LP expr RP statement %prec IFX { $$ = new IfStatementNode($3, $5, new EmptyStatementNode()); }
            | IF LP expr RP statement ELSE statement { $$ = new IfStatementNode($3, $5, $7); }
            | WHILE LP expr RP statement { $$ = new WhileStatementNode($3, $5); }
            | FOR LP exprstmt exprstmt expr RP statement { $$ = new ForStatementNode($3, $4, $5, $7); }
            | FOR LP exprstmt exprstmt RP statement { $$ = new ForStatementNode($3, $4, new EmptyExpressionNode() ,$6); }
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