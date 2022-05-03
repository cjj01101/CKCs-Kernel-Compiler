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
    ID = 260,                      /* ID  */
    TYPE_INT = 261,                /* TYPE_INT  */
    TYPE_FLOAT = 262,              /* TYPE_FLOAT  */
    TYPE_VOID = 263,               /* TYPE_VOID  */
    OP_ADD = 264,                  /* OP_ADD  */
    OP_SUB = 265,                  /* OP_SUB  */
    OP_MUL = 266,                  /* OP_MUL  */
    OP_DIV = 267,                  /* OP_DIV  */
    OP_MOD = 268,                  /* OP_MOD  */
    OP_GT = 269,                   /* OP_GT  */
    OP_LT = 270,                   /* OP_LT  */
    OP_GTE = 271,                  /* OP_GTE  */
    OP_LTE = 272,                  /* OP_LTE  */
    OP_EQ = 273,                   /* OP_EQ  */
    OP_NEQ = 274,                  /* OP_NEQ  */
    OP_AND = 275,                  /* OP_AND  */
    OP_XOR = 276,                  /* OP_XOR  */
    OP_OR = 277,                   /* OP_OR  */
    OP_NOT = 278,                  /* OP_NOT  */
    OP_LOGAND = 279,               /* OP_LOGAND  */
    OP_LOGOR = 280,                /* OP_LOGOR  */
    OP_ASSIGN = 281,               /* OP_ASSIGN  */
    LP = 282,                      /* LP  */
    RP = 283,                      /* RP  */
    LBR = 284,                     /* LBR  */
    RBR = 285,                     /* RBR  */
    SEM = 286,                     /* SEM  */
    COMMA = 287,                   /* COMMA  */
    IF = 288,                      /* IF  */
    ELSE = 289,                    /* ELSE  */
    WHILE = 290,                   /* WHILE  */
    FOR = 291,                     /* FOR  */
    RETURN = 292,                  /* RETURN  */
    IFX = 293                      /* IFX  */
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
#define ID 260
#define TYPE_INT 261
#define TYPE_FLOAT 262
#define TYPE_VOID 263
#define OP_ADD 264
#define OP_SUB 265
#define OP_MUL 266
#define OP_DIV 267
#define OP_MOD 268
#define OP_GT 269
#define OP_LT 270
#define OP_GTE 271
#define OP_LTE 272
#define OP_EQ 273
#define OP_NEQ 274
#define OP_AND 275
#define OP_XOR 276
#define OP_OR 277
#define OP_NOT 278
#define OP_LOGAND 279
#define OP_LOGOR 280
#define OP_ASSIGN 281
#define LP 282
#define RP 283
#define LBR 284
#define RBR 285
#define SEM 286
#define COMMA 287
#define IF 288
#define ELSE 289
#define WHILE 290
#define FOR 291
#define RETURN 292
#define IFX 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "./bison/parser.y"

    int intNum;
    float floatNum;
    char str[MAXVARLEN];
    ASTNode *node;
    CompoundStatementNode *compound;
    ParameterListNode *parameters;
    ArgumentListNode *arguments;
    TranslationUnitNode *unit;
    struct {
        ASTNode *type;
        ASTNode *name;
    } declarator;

#line 158 "./include/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */
