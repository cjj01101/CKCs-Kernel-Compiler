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
    OP_DADD = 271,                 /* OP_DADD  */
    OP_DSUB = 272,                 /* OP_DSUB  */
    OP_SHL = 273,                  /* OP_SHL  */
    OP_SHR = 274,                  /* OP_SHR  */
    OP_GT = 275,                   /* OP_GT  */
    OP_LT = 276,                   /* OP_LT  */
    OP_GTE = 277,                  /* OP_GTE  */
    OP_LTE = 278,                  /* OP_LTE  */
    OP_EQ = 279,                   /* OP_EQ  */
    OP_NEQ = 280,                  /* OP_NEQ  */
    OP_AND = 281,                  /* OP_AND  */
    OP_XOR = 282,                  /* OP_XOR  */
    OP_OR = 283,                   /* OP_OR  */
    OP_NOT = 284,                  /* OP_NOT  */
    OP_LOGAND = 285,               /* OP_LOGAND  */
    OP_LOGOR = 286,                /* OP_LOGOR  */
    OP_LOGNOT = 287,               /* OP_LOGNOT  */
    OP_ASSIGN = 288,               /* OP_ASSIGN  */
    OP_ADD_ASSIGN = 289,           /* OP_ADD_ASSIGN  */
    OP_SUB_ASSIGN = 290,           /* OP_SUB_ASSIGN  */
    OP_MUL_ASSIGN = 291,           /* OP_MUL_ASSIGN  */
    OP_DIV_ASSIGN = 292,           /* OP_DIV_ASSIGN  */
    OP_MOD_ASSIGN = 293,           /* OP_MOD_ASSIGN  */
    OP_SHL_ASSIGN = 294,           /* OP_SHL_ASSIGN  */
    OP_SHR_ASSIGN = 295,           /* OP_SHR_ASSIGN  */
    OP_AND_ASSIGN = 296,           /* OP_AND_ASSIGN  */
    OP_OR_ASSIGN = 297,            /* OP_OR_ASSIGN  */
    OP_XOR_ASSIGN = 298,           /* OP_XOR_ASSIGN  */
    LP = 299,                      /* LP  */
    RP = 300,                      /* RP  */
    LBR = 301,                     /* LBR  */
    RBR = 302,                     /* RBR  */
    SEM = 303,                     /* SEM  */
    COMMA = 304,                   /* COMMA  */
    QUEST = 305,                   /* QUEST  */
    COLON = 306,                   /* COLON  */
    IF = 307,                      /* IF  */
    ELSE = 308,                    /* ELSE  */
    DO = 309,                      /* DO  */
    WHILE = 310,                   /* WHILE  */
    FOR = 311,                     /* FOR  */
    BREAK = 312,                   /* BREAK  */
    CONTINUE = 313,                /* CONTINUE  */
    RETURN = 314,                  /* RETURN  */
    IFX = 315                      /* IFX  */
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
#define OP_DADD 271
#define OP_DSUB 272
#define OP_SHL 273
#define OP_SHR 274
#define OP_GT 275
#define OP_LT 276
#define OP_GTE 277
#define OP_LTE 278
#define OP_EQ 279
#define OP_NEQ 280
#define OP_AND 281
#define OP_XOR 282
#define OP_OR 283
#define OP_NOT 284
#define OP_LOGAND 285
#define OP_LOGOR 286
#define OP_LOGNOT 287
#define OP_ASSIGN 288
#define OP_ADD_ASSIGN 289
#define OP_SUB_ASSIGN 290
#define OP_MUL_ASSIGN 291
#define OP_DIV_ASSIGN 292
#define OP_MOD_ASSIGN 293
#define OP_SHL_ASSIGN 294
#define OP_SHR_ASSIGN 295
#define OP_AND_ASSIGN 296
#define OP_OR_ASSIGN 297
#define OP_XOR_ASSIGN 298
#define LP 299
#define RP 300
#define LBR 301
#define RBR 302
#define SEM 303
#define COMMA 304
#define QUEST 305
#define COLON 306
#define IF 307
#define ELSE 308
#define DO 309
#define WHILE 310
#define FOR 311
#define BREAK 312
#define CONTINUE 313
#define RETURN 314
#define IFX 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "./bison/parser.y"

    int intNum;
    float floatNum;
    bool boolNum;
    char str[MAXVARLEN];
    Declarator declarator;
    ASTNode *node;
    TypeNode *type;
    IdentifierNode *identifier;
    ExpressionNode *expression;
    StatementNode *statement;
    CompoundStatementNode *compound;
    DeclarationNode *declaration;
    DeclaratorListNode *declarators;
    ParameterListNode *parameters;
    ArgumentListNode *arguments;
    TranslationUnitNode *unit;

#line 206 "./include/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */
