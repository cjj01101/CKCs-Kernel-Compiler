%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ASTNode.h"
    #include "y.tab.h"

    void yyerror(char *);
%}

integer ([1-9]+[0-9]*|0)
real ([1-9]+[0-9]*|0)(\.[0-9]+)?
identifier [A-Za-z_][0-9A-Za-z_]*
blank [ \f\n\r\t\v]+

%%

{integer}    { yylval.intNum = atoi(yytext); return INT; }
{identifier} { strncpy(yylval.str, yytext, 64); return ID; }
"+"          return ADD;
"-"          return SUB;
"*"          return MUL;
"/"          return DIV;
"%"          return MOD;
"="          return EQ;
"("          return LP;
")"          return RP;
";"          return SEM;
{blank}      ;
.            { printf("Input parsing failure: %s.\n", yytext); }

%%