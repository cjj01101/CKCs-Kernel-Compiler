%{
    #include <stdio.h>
    #include "common.h"
    #include "DeclarationNode.h"
    #include "y.tab.h"

    extern "C" int yylex();
%}

integer ([1-9]+[0-9]*|0)
real {integer}(\.[0-9]+)
boolean (true|false)
identifier [A-Za-z_][0-9A-Za-z_]*
blank [ \f\n\r\t\v]+

%%

"+"             return OP_ADD;
"-"             return OP_SUB;
"*"             return OP_MUL;
"/"             return OP_DIV;
"%"             return OP_MOD;
"<<"            return OP_SHL;
">>"            return OP_SHR;
">"             return OP_GT;
"<"             return OP_LT;
">="            return OP_GTE;
"<="            return OP_LTE;
"=="            return OP_EQ;
"!="            return OP_NEQ;
"&"             return OP_AND;
"^"             return OP_XOR;
"|"             return OP_OR;
"~"             return OP_NOT;
"&&"            return OP_LOGAND;
"||"            return OP_LOGOR;
"!"             return OP_LOGNOT;
"++"            return OP_DADD;
"--"            return OP_DSUB;
"="             return OP_ASSIGN;
"+="            return OP_ADD_ASSIGN;
"-="            return OP_SUB_ASSIGN;
"*="            return OP_MUL_ASSIGN;
"/="            return OP_DIV_ASSIGN;
"%="            return OP_MOD_ASSIGN;
"<<="           return OP_SHL_ASSIGN;
">>="           return OP_SHR_ASSIGN;
"&="            return OP_AND_ASSIGN;
"|="            return OP_OR_ASSIGN;
"^="            return OP_XOR_ASSIGN;
"("             return LP;
")"             return RP;
"{"             return LBR;
"}"             return RBR;
";"             return SEM;
","             return COMMA;
"?"             return QUEST;
":"             return COLON;
"if"            return IF;
"else"          return ELSE;
"do"            return DO;
"while"         return WHILE;
"for"           return FOR;
"break"         return BREAK;
"continue"      return CONTINUE;
"return"        return RETURN;
"int"           return TYPE_INT;
"float"         return TYPE_FLOAT;
"bool"          return TYPE_BOOL;
"void"          return TYPE_VOID;
"puti"          return FUNC_PUTI;
{integer}       { yylval.intNum = atoi(yytext); return NUM_INT; }
{real}          { yylval.floatNum = atof(yytext); return NUM_FLOAT; }
{boolean}       { yylval.boolNum = (yytext[0] == 't'); return NUM_BOOL;  }
{identifier}    { strncpy(yylval.str, yytext, 64); return ID; }
{blank}         ;
.               { fprintf(stderr, "Input parsing failure: %s.\n", yytext); }

%%