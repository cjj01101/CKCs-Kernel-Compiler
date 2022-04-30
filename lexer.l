%{
    #include <stdio.h>
    #include "ASTNode.h"
    #include "y.tab.h"

    void yyerror(char *);
%}

integer ([1-9]+[0-9]*|0)
real ([1-9]+[0-9]*|0)(\.[0-9]+)?
identifier [A-Za-z_][0-9A-Za-z_]*
blank [ \f\n\r\t\v]+

%%

"+"          return ADD;
"-"          return SUB;
"*"          return MUL;
"/"          return DIV;
"%"          return MOD;
"="          return EQ;
"("          return LP;
")"          return RP;
";"          return SEM;
","          return COMMA;
"if"         return IF;
"else"       return ELSE;
"while"      return WHILE;
"for"        return FOR;
"int"        return TYPE_INT;
{identifier} { strncpy(yylval.str, yytext, 64); return ID; }
{integer}    { yylval.intNum = atoi(yytext); return INT; }
{blank}      ;
.            { printf("Input parsing failure: %s.\n", yytext); }

%%