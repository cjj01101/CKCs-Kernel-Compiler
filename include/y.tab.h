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
    INT = 258,                     /* INT  */
    ID = 259,                      /* ID  */
    TYPE_INT = 260,                /* TYPE_INT  */
    TYPE_VOID = 261,               /* TYPE_VOID  */
    OP_ADD = 262,                  /* OP_ADD  */
    OP_SUB = 263,                  /* OP_SUB  */
    OP_MUL = 264,                  /* OP_MUL  */
    OP_DIV = 265,                  /* OP_DIV  */
    OP_MOD = 266,                  /* OP_MOD  */
    OP_GT = 267,                   /* OP_GT  */
    OP_LT = 268,                   /* OP_LT  */
    OP_GTE = 269,                  /* OP_GTE  */
    OP_LTE = 270,                  /* OP_LTE  */
    OP_EQ = 271,                   /* OP_EQ  */
    OP_NEQ = 272,                  /* OP_NEQ  */
    OP_AND = 273,                  /* OP_AND  */
    OP_XOR = 274,                  /* OP_XOR  */
    OP_OR = 275,                   /* OP_OR  */
    OP_NOT = 276,                  /* OP_NOT  */
    OP_LOGAND = 277,               /* OP_LOGAND  */
    OP_LOGOR = 278,                /* OP_LOGOR  */
    OP_ASSIGN = 279,               /* OP_ASSIGN  */
    LP = 280,                      /* LP  */
    RP = 281,                      /* RP  */
    LBR = 282,                     /* LBR  */
    RBR = 283,                     /* RBR  */
    SEM = 284,                     /* SEM  */
    COMMA = 285,                   /* COMMA  */
    IF = 286,                      /* IF  */
    ELSE = 287,                    /* ELSE  */
    WHILE = 288,                   /* WHILE  */
    FOR = 289,                     /* FOR  */
    RETURN = 290,                  /* RETURN  */
    IFX = 291                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define ID 259
#define TYPE_INT 260
#define TYPE_VOID 261
#define OP_ADD 262
#define OP_SUB 263
#define OP_MUL 264
#define OP_DIV 265
#define OP_MOD 266
#define OP_GT 267
#define OP_LT 268
#define OP_GTE 269
#define OP_LTE 270
#define OP_EQ 271
#define OP_NEQ 272
#define OP_AND 273
#define OP_XOR 274
#define OP_OR 275
#define OP_NOT 276
#define OP_LOGAND 277
#define OP_LOGOR 278
#define OP_ASSIGN 279
#define LP 280
#define RP 281
#define LBR 282
#define RBR 283
#define SEM 284
#define COMMA 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define FOR 289
#define RETURN 290
#define IFX 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "./bison/parser.y"

    int intNum;
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

#line 153 "./include/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */
