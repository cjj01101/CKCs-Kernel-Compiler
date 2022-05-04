%{
    #include <stdio.h>
    #include "AbstractSyntaxTree.h"
    #include "TranslationUnitNode.h"
    #include "DeclarationNode.h"
    #include "FunctionNode.h"
    #include "StatementNode.h"
    #include "OperatorNode.h"
    #include "ExpressionNode.h"
    #include "ConstantNode.h"

    int yylex(void);
    void yyerror(char *);

    ASTNode *root = nullptr;
%}

%union {
    int intNum;
    float floatNum;
    char str[MAXVARLEN];
    ASTNode *node;
    TypeNode *type;
    IdentifierNode *identifier;
    CompoundStatementNode *compound;
    ParameterListNode *parameters;
    ArgumentListNode *arguments;
    TranslationUnitNode *unit;
    struct {
        TypeNode *type;
        IdentifierNode *name;
    } declarator;
}

%token <intNum> NUM_INT
%token <floatNum> NUM_FLOAT
%token <str> ID
%token TYPE_INT TYPE_FLOAT TYPE_VOID
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD
%token OP_GT OP_LT OP_GTE OP_LTE OP_EQ OP_NEQ
%token OP_AND OP_XOR OP_OR OP_NOT OP_LOGAND OP_LOGOR
%token OP_ASSIGN
%token LP RP LBR RBR SEM COMMA
%token IF ELSE WHILE FOR RETURN

%type <node> externdef function item declaration statement 
%type <node> exprstmt ctrlstmt jumpstmt initstmt
%type <node> expr logorexpr logandexpr orexpr xorexpr andexpr ecmprexpr cmprexpr addexpr mulexpr
%type <node> factor constant

%type <unit> program
%type <compound> compoundstmt items
%type <parameters> parameters
%type <arguments> arguments
%type <declarator> declarator
%type <identifier> identifier
%type <type> type

%nonassoc IFX
%nonassoc ELSE

%%

        program : program externdef { $$ = $1; $$->AppendDefinition($2); }
                | /* empty */ { $$ = new TranslationUnitNode(); root = $$; } 
                ;

      externdef : function { $$ = $1; }
                | declaration { $$ = $1; }
                ;

       function : declarator LP parameters RP compoundstmt { $$ = new FunctionNode($1.name, $1.type, $3, $5); }
                ;

     parameters : parameters COMMA declarator { $$ = $1; $1->AppendParameter(new DeclarationNode($3.name, $3.type)); }
                | declarator { $$ = new ParameterListNode(); $$->AppendParameter(new DeclarationNode($1.name, $1.type)); }
                | TYPE_VOID { $$ = new ParameterListNode(); }
                | /* empty */ { $$ = new ParameterListNode(); }
                ;

    declaration : declarator SEM { $$ = new DeclarationNode($1.name, $1.type); }
                | declarator OP_ASSIGN expr SEM { $$ = new DeclarationNode($1.name, $1.type, $3); }
                ;

     declarator : type identifier { $$ = { $1, $2 }; }
                ;

           type : TYPE_INT { $$ = new TypeNode(Type::INTEGER); }
                | TYPE_FLOAT { $$ = new TypeNode(Type::FLOAT); }
                | TYPE_VOID { $$ = new TypeNode(Type::VOID); }
                ;

     identifier : ID { $$ = new IdentifierNode($1); }
                ;

      statement : compoundstmt { $$ = $1; }
                | exprstmt { $$ = $1; }
                | ctrlstmt { $$ = $1; }
                | jumpstmt { $$ = $1; }
                ;

   compoundstmt : LBR items RBR { $$ = $2; }
                ;

          items : items item { $$ = $1; $$->AppendStatement($2); }
                | /* empty */ { $$ = new CompoundStatementNode(); }
                ;

           item : declaration { $$ = $1; }
                | statement { $$ = $1; }
                ;

       exprstmt : expr SEM { $$ = new ExpressionStatementNode($1); }
                | SEM  { $$ = new ExpressionStatementNode(); }
                ;

           expr : identifier OP_ASSIGN expr { $$ = new AssignOpNode($1, $3); }
                | logorexpr { $$ = $1; }
                ;

      logorexpr : logorexpr OP_LOGOR logandexpr { $$ = new BinaryOpNode(Operator::LOGOR, $1, $3); }
                | logandexpr { $$ = $1; }
                ;

     logandexpr : logandexpr OP_LOGAND orexpr { $$ = new BinaryOpNode(Operator::LOGAND, $1, $3); }
                | orexpr { $$ = $1; }
                ;

         orexpr : orexpr OP_OR xorexpr { $$ = new BinaryOpNode(Operator::OR, $1, $3); }
                | xorexpr { $$ = $1; }
                ;

        xorexpr : xorexpr OP_XOR andexpr { $$ = new BinaryOpNode(Operator::XOR, $1, $3); }
                | andexpr { $$ = $1; }
                ;

        andexpr : andexpr OP_AND ecmprexpr { $$ = new BinaryOpNode(Operator::AND, $1, $3); }
                | ecmprexpr { $$ = $1; }
                ;

      ecmprexpr : ecmprexpr OP_EQ cmprexpr { $$ = new BinaryOpNode(Operator::EQ, $1, $3); }
                | ecmprexpr OP_NEQ cmprexpr { $$ = new BinaryOpNode(Operator::NEQ, $1, $3); }
                | cmprexpr { $$ = $1; }
                ;

       cmprexpr : cmprexpr OP_GT addexpr { $$ = new BinaryOpNode(Operator::GT, $1, $3); }
                | cmprexpr OP_LT addexpr { $$ = new BinaryOpNode(Operator::LT, $1, $3); }
                | cmprexpr OP_GTE addexpr { $$ = new BinaryOpNode(Operator::GTE, $1, $3); }
                | cmprexpr OP_LTE addexpr { $$ = new BinaryOpNode(Operator::LTE, $1, $3); }
                | addexpr { $$ = $1; }
                ;

        addexpr : addexpr OP_ADD mulexpr { $$ = new BinaryOpNode(Operator::ADD, $1, $3); }
                | addexpr OP_SUB mulexpr { $$ = new BinaryOpNode(Operator::SUB, $1, $3); }
                | mulexpr { $$ = $1; }
                ;

        mulexpr : mulexpr OP_MUL factor { $$ = new BinaryOpNode(Operator::MUL, $1, $3); }
                | mulexpr OP_DIV factor { $$ = new BinaryOpNode(Operator::DIV, $1, $3); }
                | mulexpr OP_MOD factor { $$ = new BinaryOpNode(Operator::MOD, $1, $3); }
                | factor { $$ = $1; }
                ;

         factor : identifier { $$ = $1; }
                | constant { $$ = $1; }
                | LP expr RP { $$ = $2; }
                | identifier LP arguments RP { $$ = new FunctionCallNode($1, $3); }
                | OP_SUB factor { $$ = new BinaryOpNode(Operator::SUB, new IntegerNode(0), $2); }
                | OP_NOT factor { $$ = new BinaryOpNode(Operator::XOR, new IntegerNode(0), $2); }
                ;
     
       constant : NUM_INT { $$ = new IntegerNode($1); }
                | NUM_FLOAT { $$ = new FloatNode($1); }
                ;

      arguments : arguments COMMA expr { $$ = $1; $1->AppendArgument($3); }
                | expr { $$ = new ArgumentListNode(); $$->AppendArgument($1); }
                | /* empty */ { $$ = new ArgumentListNode(); }
                ;

       ctrlstmt : IF LP expr RP statement %prec IFX { $$ = new IfStatementNode($3, $5, new ExpressionStatementNode()); }
                | IF LP expr RP statement ELSE statement { $$ = new IfStatementNode($3, $5, $7); }
                // | DO statement WHILE LP expr RP {  }
                | WHILE LP expr RP statement { $$ = new WhileStatementNode($3, $5); }
                | FOR LP initstmt exprstmt expr RP statement { $$ = new ForStatementNode($3, $4, $5, $7); }
                | FOR LP initstmt exprstmt RP statement { $$ = new ForStatementNode($3, $4, new EmptyExpressionNode() ,$6); }
                ;

       initstmt : exprstmt { $$ = $1; }
                | declaration { $$ = $1; }
                ;

       jumpstmt : RETURN exprstmt { $$ = new ReturnStatementNode($2); }
                ;

%%

void yyerror(char *e) {
    fprintf(stderr, "error: %s\n", e);
}

int yywrap(){
    return 1;
}

ASTNode *parse_and_generate_syntax_tree(FILE *input){
    extern FILE *yyin;
    yyin = input;
    yyparse();
    return root;
}