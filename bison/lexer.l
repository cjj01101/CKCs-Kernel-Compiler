%{
    #include <stdio.h>
    #include "ASTNode.h"
    #include "StatementNode.h"
    #include "DeclarationNode.h"
    #include "y.tab.h"

    void yyerror(char *);
%}

integer ([1-9]+[0-9]*|0)
real ([1-9]+[0-9]*|0)(\.[0-9]+)?
identifier [A-Za-z_][0-9A-Za-z_]*
blank [ \f\n\r\t\v]+

%%

"+"             return OP_ADD;
"-"             return OP_SUB;
"*"             return OP_MUL;
"/"             return OP_DIV;
"%"             return OP_MOD;
">"             return OP_GT;
"<"             return OP_LT;
">="            return OP_GTE;
"<="            return OP_LTE;
"=="            return OP_EQ;
"!="            return OP_NEQ;
"&"             return OP_AND;
"^"             return OP_XOR;
"|"             return OP_OR;
"&&"            return OP_LOGAND;
"||"            return OP_LOGOR;
"="             return OP_ASSIGN;
"("             return LP;
")"             return RP;
"{"             return LBR;
"}"             return RBR;
";"             return SEM;
","             return COMMA;
"if"            return IF;
"else"          return ELSE;
"while"         return WHILE;
"for"           return FOR;
"int"           return TYPE_INT;
"void"          return TYPE_VOID;
{identifier}    { strncpy(yylval.str, yytext, 64); return ID; }
{integer}       { yylval.intNum = atoi(yytext); return INT; }
{blank}         ;
.               { printf("Input parsing failure: %s.\n", yytext); }

%%