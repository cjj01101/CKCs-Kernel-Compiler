%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ASTNode.h"
    #include "y.tab.h"

    void yyerror(char *);
%}

integer ([1-9]+[0-9]*|0)
real ([1-9]+[0-9]*|0)(\.[0-9]+)?
blank [ \f\n\r\t\v]+

%%

{integer}     { yylval.intNum = atoi(yytext); return INT; }
"+"          return ADD;
"-"          return SUB;
"*"          return MUL;
"/"          return DIV;
"("          return LP;
")"          return RP;
";"          return SEM;
{blank}      ;
.            { printf("Input parsing failure: %s.\n", yytext); }

%%