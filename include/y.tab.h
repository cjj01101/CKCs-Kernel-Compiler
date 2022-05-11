/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INCLUDE_Y_TAB_H_INCLUDED
# define YY_YY_INCLUDE_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM_INT = 258,                 /* NUM_INT  */
    NUM_FLOAT = 259,               /* NUM_FLOAT  */
    NUM_BOOL = 260,                /* NUM_BOOL  */
    ID = 261,                      /* ID  */
    TYPE_INT = 262,                /* TYPE_INT  */
    TYPE_FLOAT = 263,              /* TYPE_FLOAT  */
    TYPE_BOOL = 264,               /* TYPE_BOOL  */
    TYPE_VOID = 265,               /* TYPE_VOID  */
    OP_ADD = 266,                  /* OP_ADD  */
    OP_SUB = 267,                  /* OP_SUB  */
    OP_MUL = 268,                  /* OP_MUL  */
    OP_DIV = 269,                  /* OP_DIV  */
    OP_MOD = 270,                  /* OP_MOD  */
    OP_SHL = 271,                  /* OP_SHL  */
    OP_SHR = 272,                  /* OP_SHR  */
    OP_GT = 273,                   /* OP_GT  */
    OP_LT = 274,                   /* OP_LT  */
    OP_GTE = 275,                  /* OP_GTE  */
    OP_LTE = 276,                  /* OP_LTE  */
    OP_EQ = 277,                   /* OP_EQ  */
    OP_NEQ = 278,                  /* OP_NEQ  */
    OP_AND = 279,                  /* OP_AND  */
    OP_XOR = 280,                  /* OP_XOR  */
    OP_OR = 281,                   /* OP_OR  */
    OP_NOT = 282,                  /* OP_NOT  */
    OP_LOGAND = 283,               /* OP_LOGAND  */
    OP_LOGOR = 284,                /* OP_LOGOR  */
    OP_LOGNOT = 285,               /* OP_LOGNOT  */
    OP_ASSIGN = 286,               /* OP_ASSIGN  */
    OP_ADD_ASSIGN = 287,           /* OP_ADD_ASSIGN  */
    OP_SUB_ASSIGN = 288,           /* OP_SUB_ASSIGN  */
    OP_MUL_ASSIGN = 289,           /* OP_MUL_ASSIGN  */
    OP_DIV_ASSIGN = 290,           /* OP_DIV_ASSIGN  */
    OP_MOD_ASSIGN = 291,           /* OP_MOD_ASSIGN  */
    OP_SHL_ASSIGN = 292,           /* OP_SHL_ASSIGN  */
    OP_SHR_ASSIGN = 293,           /* OP_SHR_ASSIGN  */
    OP_AND_ASSIGN = 294,           /* OP_AND_ASSIGN  */
    OP_OR_ASSIGN = 295,            /* OP_OR_ASSIGN  */
    OP_XOR_ASSIGN = 296,           /* OP_XOR_ASSIGN  */
    LP = 297,                      /* LP  */
    RP = 298,                      /* RP  */
    LBR = 299,                     /* LBR  */
    RBR = 300,                     /* RBR  */
    SEM = 301,                     /* SEM  */
    COMMA = 302,                   /* COMMA  */
    QUEST = 303,                   /* QUEST  */
    COLON = 304,                   /* COLON  */
    IF = 305,                      /* IF  */
    ELSE = 306,                    /* ELSE  */
    WHILE = 307,                   /* WHILE  */
    FOR = 308,                     /* FOR  */
    RETURN = 309,                  /* RETURN  */
    IFX = 310                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM_INT 258
#define NUM_FLOAT 259
#define NUM_BOOL 260
#define ID 261
#define TYPE_INT 262
#define TYPE_FLOAT 263
#define TYPE_BOOL 264
#define TYPE_VOID 265
#define OP_ADD 266
#define OP_SUB 267
#define OP_MUL 268
#define OP_DIV 269
#define OP_MOD 270
#define OP_SHL 271
#define OP_SHR 272
#define OP_GT 273
#define OP_LT 274
#define OP_GTE 275
#define OP_LTE 276
#define OP_EQ 277
#define OP_NEQ 278
#define OP_AND 279
#define OP_XOR 280
#define OP_OR 281
#define OP_NOT 282
#define OP_LOGAND 283
#define OP_LOGOR 284
#define OP_LOGNOT 285
#define OP_ASSIGN 286
#define OP_ADD_ASSIGN 287
#define OP_SUB_ASSIGN 288
#define OP_MUL_ASSIGN 289
#define OP_DIV_ASSIGN 290
#define OP_MOD_ASSIGN 291
#define OP_SHL_ASSIGN 292
#define OP_SHR_ASSIGN 293
#define OP_AND_ASSIGN 294
#define OP_OR_ASSIGN 295
#define OP_XOR_ASSIGN 296
#define LP 297
#define RP 298
#define LBR 299
#define RBR 300
#define SEM 301
#define COMMA 302
#define QUEST 303
#define COLON 304
#define IF 305
#define ELSE 306
#define WHILE 307
#define FOR 308
#define RETURN 309
#define IFX 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "./bison/parser.y"

    int intNum;
    float floatNum;
    bool boolNum;
    char str[MAXVARLEN];
    ASTNode *node;
    TypeNode *type;
    IdentifierNode *identifier;
    ExpressionNode *expression;
    StatementNode *statement;
    DeclarationNode *declaration;
    CompoundStatementNode *compound;
    ParameterListNode *parameters;
    ArgumentListNode *arguments;
    TranslationUnitNode *unit;

#line 194 "./include/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */
