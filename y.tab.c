/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include "AbstractSyntaxTree.h"
    #include "ValueNode.h"
    #include "OperatorNode.h"
    #include "DeclarationNode.h"
    #include "StatementNode.h"

    int yylex(void);
    void yyerror(char *);
    
    enum class type;

    ASTNode *root = nullptr;

#line 87 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    OP_ADD = 261,                  /* OP_ADD  */
    OP_SUB = 262,                  /* OP_SUB  */
    OP_MUL = 263,                  /* OP_MUL  */
    OP_DIV = 264,                  /* OP_DIV  */
    OP_MOD = 265,                  /* OP_MOD  */
    OP_GT = 266,                   /* OP_GT  */
    OP_LT = 267,                   /* OP_LT  */
    OP_GTE = 268,                  /* OP_GTE  */
    OP_LTE = 269,                  /* OP_LTE  */
    OP_EQ = 270,                   /* OP_EQ  */
    OP_NEQ = 271,                  /* OP_NEQ  */
    OP_AND = 272,                  /* OP_AND  */
    OP_XOR = 273,                  /* OP_XOR  */
    OP_OR = 274,                   /* OP_OR  */
    OP_LOGAND = 275,               /* OP_LOGAND  */
    OP_LOGOR = 276,                /* OP_LOGOR  */
    OP_ASSIGN = 277,               /* OP_ASSIGN  */
    LP = 278,                      /* LP  */
    RP = 279,                      /* RP  */
    LBR = 280,                     /* LBR  */
    RBR = 281,                     /* RBR  */
    SEM = 282,                     /* SEM  */
    COMMA = 283,                   /* COMMA  */
    IF = 284,                      /* IF  */
    ELSE = 285,                    /* ELSE  */
    WHILE = 286,                   /* WHILE  */
    FOR = 287,                     /* FOR  */
    IFX = 288                      /* IFX  */
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
#define OP_ADD 261
#define OP_SUB 262
#define OP_MUL 263
#define OP_DIV 264
#define OP_MOD 265
#define OP_GT 266
#define OP_LT 267
#define OP_GTE 268
#define OP_LTE 269
#define OP_EQ 270
#define OP_NEQ 271
#define OP_AND 272
#define OP_XOR 273
#define OP_OR 274
#define OP_LOGAND 275
#define OP_LOGOR 276
#define OP_ASSIGN 277
#define LP 278
#define RP 279
#define LBR 280
#define RBR 281
#define SEM 282
#define COMMA 283
#define IF 284
#define ELSE 285
#define WHILE 286
#define FOR 287
#define IFX 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    int intNum;
    char str[MAXVARLEN];
    ASTNode *node;

#line 212 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_TYPE_INT = 5,                   /* TYPE_INT  */
  YYSYMBOL_OP_ADD = 6,                     /* OP_ADD  */
  YYSYMBOL_OP_SUB = 7,                     /* OP_SUB  */
  YYSYMBOL_OP_MUL = 8,                     /* OP_MUL  */
  YYSYMBOL_OP_DIV = 9,                     /* OP_DIV  */
  YYSYMBOL_OP_MOD = 10,                    /* OP_MOD  */
  YYSYMBOL_OP_GT = 11,                     /* OP_GT  */
  YYSYMBOL_OP_LT = 12,                     /* OP_LT  */
  YYSYMBOL_OP_GTE = 13,                    /* OP_GTE  */
  YYSYMBOL_OP_LTE = 14,                    /* OP_LTE  */
  YYSYMBOL_OP_EQ = 15,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 16,                    /* OP_NEQ  */
  YYSYMBOL_OP_AND = 17,                    /* OP_AND  */
  YYSYMBOL_OP_XOR = 18,                    /* OP_XOR  */
  YYSYMBOL_OP_OR = 19,                     /* OP_OR  */
  YYSYMBOL_OP_LOGAND = 20,                 /* OP_LOGAND  */
  YYSYMBOL_OP_LOGOR = 21,                  /* OP_LOGOR  */
  YYSYMBOL_OP_ASSIGN = 22,                 /* OP_ASSIGN  */
  YYSYMBOL_LP = 23,                        /* LP  */
  YYSYMBOL_RP = 24,                        /* RP  */
  YYSYMBOL_LBR = 25,                       /* LBR  */
  YYSYMBOL_RBR = 26,                       /* RBR  */
  YYSYMBOL_SEM = 27,                       /* SEM  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_IFX = 33,                       /* IFX  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_declaration = 37,               /* declaration  */
  YYSYMBOL_type = 38,                      /* type  */
  YYSYMBOL_idlist = 39,                    /* idlist  */
  YYSYMBOL_statement = 40,                 /* statement  */
  YYSYMBOL_compoundstmt = 41,              /* compoundstmt  */
  YYSYMBOL_items = 42,                     /* items  */
  YYSYMBOL_item = 43,                      /* item  */
  YYSYMBOL_exprstmt = 44,                  /* exprstmt  */
  YYSYMBOL_expr = 45,                      /* expr  */
  YYSYMBOL_logorexpr = 46,                 /* logorexpr  */
  YYSYMBOL_logandexpr = 47,                /* logandexpr  */
  YYSYMBOL_orexpr = 48,                    /* orexpr  */
  YYSYMBOL_xorexpr = 49,                   /* xorexpr  */
  YYSYMBOL_andexpr = 50,                   /* andexpr  */
  YYSYMBOL_ecmprexpr = 51,                 /* ecmprexpr  */
  YYSYMBOL_cmprexpr = 52,                  /* cmprexpr  */
  YYSYMBOL_arithexpr = 53,                 /* arithexpr  */
  YYSYMBOL_term = 54,                      /* term  */
  YYSYMBOL_factor = 55,                    /* factor  */
  YYSYMBOL_variable = 56,                  /* variable  */
  YYSYMBOL_identifier = 57,                /* identifier  */
  YYSYMBOL_integer = 58,                   /* integer  */
  YYSYMBOL_ctrlstmt = 59,                  /* ctrlstmt  */
  YYSYMBOL_initstmt = 60                   /* initstmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    43,    44,    47,    50,    53,    56,    57,
      58,    61,    64,    65,    68,    69,    72,    73,    76,    77,
      80,    81,    84,    85,    88,    89,    92,    93,    96,    97,
     100,   101,   102,   105,   106,   107,   108,   109,   112,   113,
     114,   115,   118,   119,   120,   121,   124,   125,   126,   129,
     132,   135,   138,   139,   141,   142,   143,   146,   147
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "ID",
  "TYPE_INT", "OP_ADD", "OP_SUB", "OP_MUL", "OP_DIV", "OP_MOD", "OP_GT",
  "OP_LT", "OP_GTE", "OP_LTE", "OP_EQ", "OP_NEQ", "OP_AND", "OP_XOR",
  "OP_OR", "OP_LOGAND", "OP_LOGOR", "OP_ASSIGN", "LP", "RP", "LBR", "RBR",
  "SEM", "COMMA", "IF", "ELSE", "WHILE", "FOR", "IFX", "$accept",
  "program", "$@1", "declaration", "type", "idlist", "statement",
  "compoundstmt", "items", "item", "exprstmt", "expr", "logorexpr",
  "logandexpr", "orexpr", "xorexpr", "andexpr", "ecmprexpr", "cmprexpr",
  "arithexpr", "term", "factor", "variable", "identifier", "integer",
  "ctrlstmt", "initstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      71,   -34,   -34,   -34,    18,    61,    71,   -34,   -19,   -12,
      19,    26,   -34,    44,   -34,   -34,   -34,   -34,    23,    40,
      49,    64,    69,    76,    51,     3,    65,    10,   -34,    79,
      84,   -34,   -34,    10,   -34,    80,    20,   -34,    61,    61,
       5,   -34,    81,   -34,    71,   -34,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    18,    18,    18,
      18,    18,    61,   -34,   -34,   -34,    86,    88,   -34,   -34,
      50,   -34,   -34,    49,    64,    69,    76,    51,     3,     3,
      65,    65,    65,    65,    10,    10,   -34,   -34,   -34,   -34,
      82,    82,    56,    87,   -34,    82,    94,    82,   -34,    82,
     -34,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    51,    50,     6,     0,     0,     0,    17,     0,     0,
       0,     0,    14,     0,    15,     8,     2,     9,     0,    19,
      21,    23,    25,    27,    29,    32,    37,    41,    45,     0,
      46,    47,    10,    40,    46,     0,     0,    13,     0,     0,
       0,     1,     0,     7,     4,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    11,    12,     0,     0,    58,    57,
       0,     5,     3,    20,    22,    24,    26,    28,    30,    31,
      33,    34,    35,    36,    38,    39,    42,    43,    44,    18,
       0,     0,     0,    52,    54,     0,     0,     0,    56,     0,
      53,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,    75,   -34,    83,   -34,   -34,    25,   -34,   -34,    -3,
     -33,    -4,   -34,    85,    74,    89,    90,    91,    30,    72,
      -2,   -30,   -34,     0,   -34,   -34,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    44,    12,    13,    42,    14,    15,    36,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    34,    31,    32,    70
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    35,    33,    37,    38,    30,    30,    69,     1,     2,
       3,    39,     4,    43,    53,    54,    55,    56,    59,    60,
      61,     1,     2,     1,     2,     3,    41,     4,     5,    86,
      87,    88,     7,    65,    66,    67,    30,    92,    30,    30,
      30,     5,    40,     5,    30,     6,    64,     7,     2,     8,
      45,     9,    10,     1,     2,    84,    85,     4,    89,     1,
       2,    46,    30,     4,     1,     2,    51,    52,     4,    47,
      30,    57,    58,     5,     1,     2,     3,     7,     4,     5,
      95,    78,    79,    48,     5,     1,     2,    49,    96,     4,
      30,    30,    30,    50,     5,    30,     6,    30,     7,    30,
       8,    62,     9,    10,    63,     5,   -49,     6,    71,     7,
      90,     8,    91,     9,    10,    93,    94,    97,    99,    72,
      98,    74,   100,    68,   101,    80,    81,    82,    83,     0,
       0,    73,     0,     0,     0,     0,     0,    75,     0,    76,
       0,    77
};

static const yytype_int8 yycheck[] =
{
       0,     5,     4,     6,    23,     5,     6,    40,     3,     4,
       5,    23,     7,    13,    11,    12,    13,    14,     8,     9,
      10,     3,     4,     3,     4,     5,     0,     7,    23,    59,
      60,    61,    27,    36,    38,    39,    36,    70,    38,    39,
      40,    23,    23,    23,    44,    25,    26,    27,     4,    29,
      27,    31,    32,     3,     4,    57,    58,     7,    62,     3,
       4,    21,    62,     7,     3,     4,    15,    16,     7,    20,
      70,     6,     7,    23,     3,     4,     5,    27,     7,    23,
      24,    51,    52,    19,    23,     3,     4,    18,    92,     7,
      90,    91,    92,    17,    23,    95,    25,    97,    27,    99,
      29,    22,    31,    32,    24,    23,    22,    25,    27,    27,
      24,    29,    24,    31,    32,    90,    91,    30,    24,    44,
      95,    47,    97,    40,    99,    53,    54,    55,    56,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    48,    -1,    49,
      -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,    23,    25,    27,    29,    31,
      32,    35,    37,    38,    40,    41,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    54,    57,    45,    42,    43,    23,    23,
      23,     0,    39,    57,    36,    27,    21,    20,    19,    18,
      17,    15,    16,    11,    12,    13,    14,     6,     7,     8,
       9,    10,    22,    24,    26,    43,    45,    45,    37,    44,
      60,    27,    35,    47,    48,    49,    50,    51,    52,    52,
      53,    53,    53,    53,    54,    54,    55,    55,    55,    45,
      24,    24,    44,    40,    40,    24,    45,    30,    40,    24,
      40,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    36,    35,    35,    37,    38,    39,    40,    40,
      40,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    52,    52,    52,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    54,    55,    55,    55,    56,
      57,    58,    59,    59,    59,    59,    59,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     3,     2,     1,     1,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       2,     1,     3,     3,     3,     1,     1,     1,     3,     1,
       1,     1,     5,     7,     5,     7,     6,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 43 "parser.y"
                       { if((yyvsp[0].node)) (yyvsp[0].node)->PrintInLevel(0); }
#line 1325 "y.tab.c"
    break;

  case 5: /* declaration: type idlist SEM  */
#line 47 "parser.y"
                                  { (yyval.node) = new DeclarationNode((yyvsp[-1].node), (yyvsp[-2].node)); }
#line 1331 "y.tab.c"
    break;

  case 6: /* type: TYPE_INT  */
#line 50 "parser.y"
                           { (yyval.node) = new TypeNode(Type::INTEGER); }
#line 1337 "y.tab.c"
    break;

  case 7: /* idlist: identifier  */
#line 53 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1343 "y.tab.c"
    break;

  case 8: /* statement: compoundstmt  */
#line 56 "parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1349 "y.tab.c"
    break;

  case 9: /* statement: exprstmt  */
#line 57 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1355 "y.tab.c"
    break;

  case 10: /* statement: ctrlstmt  */
#line 58 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1361 "y.tab.c"
    break;

  case 11: /* compoundstmt: LBR items RBR  */
#line 61 "parser.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1367 "y.tab.c"
    break;

  case 12: /* items: items item  */
#line 64 "parser.y"
                             { (yyval.node) = (yyvsp[-1].node); dynamic_cast<CompoundStatementNode*>((yyval.node))->AppendStatement((yyvsp[0].node)); }
#line 1373 "y.tab.c"
    break;

  case 13: /* items: item  */
#line 65 "parser.y"
                       { auto node = new CompoundStatementNode(); node->AppendStatement((yyvsp[0].node)); (yyval.node) = node; }
#line 1379 "y.tab.c"
    break;

  case 14: /* item: declaration  */
#line 68 "parser.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1385 "y.tab.c"
    break;

  case 15: /* item: statement  */
#line 69 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1391 "y.tab.c"
    break;

  case 16: /* exprstmt: expr SEM  */
#line 72 "parser.y"
                           { (yyval.node) = new ExpressionStatementNode((yyvsp[-1].node)); }
#line 1397 "y.tab.c"
    break;

  case 17: /* exprstmt: SEM  */
#line 73 "parser.y"
                       { (yyval.node) = new EmptyStatementNode(); }
#line 1403 "y.tab.c"
    break;

  case 18: /* expr: variable OP_ASSIGN expr  */
#line 76 "parser.y"
                                          { (yyval.node) = new AssignOpNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1409 "y.tab.c"
    break;

  case 19: /* expr: logorexpr  */
#line 77 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1415 "y.tab.c"
    break;

  case 20: /* logorexpr: logorexpr OP_LOGOR logandexpr  */
#line 80 "parser.y"
                                                { (yyval.node) = new BinaryOpNode(Operator::LOGOR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1421 "y.tab.c"
    break;

  case 21: /* logorexpr: logandexpr  */
#line 81 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1427 "y.tab.c"
    break;

  case 22: /* logandexpr: logandexpr OP_LOGAND orexpr  */
#line 84 "parser.y"
                                              { (yyval.node) = new BinaryOpNode(Operator::LOGAND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1433 "y.tab.c"
    break;

  case 23: /* logandexpr: orexpr  */
#line 85 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1439 "y.tab.c"
    break;

  case 24: /* orexpr: orexpr OP_OR xorexpr  */
#line 88 "parser.y"
                                       { (yyval.node) = new BinaryOpNode(Operator::OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1445 "y.tab.c"
    break;

  case 25: /* orexpr: xorexpr  */
#line 89 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1451 "y.tab.c"
    break;

  case 26: /* xorexpr: xorexpr OP_XOR andexpr  */
#line 92 "parser.y"
                                         { (yyval.node) = new BinaryOpNode(Operator::XOR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1457 "y.tab.c"
    break;

  case 27: /* xorexpr: andexpr  */
#line 93 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1463 "y.tab.c"
    break;

  case 28: /* andexpr: andexpr OP_AND ecmprexpr  */
#line 96 "parser.y"
                                           { (yyval.node) = new BinaryOpNode(Operator::AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1469 "y.tab.c"
    break;

  case 29: /* andexpr: ecmprexpr  */
#line 97 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1475 "y.tab.c"
    break;

  case 30: /* ecmprexpr: ecmprexpr OP_EQ cmprexpr  */
#line 100 "parser.y"
                                           { (yyval.node) = new BinaryOpNode(Operator::EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1481 "y.tab.c"
    break;

  case 31: /* ecmprexpr: ecmprexpr OP_NEQ cmprexpr  */
#line 101 "parser.y"
                                            { (yyval.node) = new BinaryOpNode(Operator::NEQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1487 "y.tab.c"
    break;

  case 32: /* ecmprexpr: cmprexpr  */
#line 102 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1493 "y.tab.c"
    break;

  case 33: /* cmprexpr: cmprexpr OP_GT arithexpr  */
#line 105 "parser.y"
                                           { (yyval.node) = new BinaryOpNode(Operator::GT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1499 "y.tab.c"
    break;

  case 34: /* cmprexpr: cmprexpr OP_LT arithexpr  */
#line 106 "parser.y"
                                           { (yyval.node) = new BinaryOpNode(Operator::LT, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1505 "y.tab.c"
    break;

  case 35: /* cmprexpr: cmprexpr OP_GTE arithexpr  */
#line 107 "parser.y"
                                            { (yyval.node) = new BinaryOpNode(Operator::GTE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1511 "y.tab.c"
    break;

  case 36: /* cmprexpr: cmprexpr OP_LTE arithexpr  */
#line 108 "parser.y"
                                            { (yyval.node) = new BinaryOpNode(Operator::LTE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1517 "y.tab.c"
    break;

  case 37: /* cmprexpr: arithexpr  */
#line 109 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1523 "y.tab.c"
    break;

  case 38: /* arithexpr: arithexpr OP_ADD term  */
#line 112 "parser.y"
                                        { (yyval.node) = new BinaryOpNode(Operator::ADD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1529 "y.tab.c"
    break;

  case 39: /* arithexpr: arithexpr OP_SUB term  */
#line 113 "parser.y"
                                        { (yyval.node) = new BinaryOpNode(Operator::SUB, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1535 "y.tab.c"
    break;

  case 40: /* arithexpr: OP_SUB term  */
#line 114 "parser.y"
                              { (yyval.node) = new BinaryOpNode(Operator::SUB, new IntegerNode(0), (yyvsp[0].node)); }
#line 1541 "y.tab.c"
    break;

  case 41: /* arithexpr: term  */
#line 115 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1547 "y.tab.c"
    break;

  case 42: /* term: term OP_MUL factor  */
#line 118 "parser.y"
                                     { (yyval.node) = new BinaryOpNode(Operator::MUL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1553 "y.tab.c"
    break;

  case 43: /* term: term OP_DIV factor  */
#line 119 "parser.y"
                                     { (yyval.node) = new BinaryOpNode(Operator::DIV, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1559 "y.tab.c"
    break;

  case 44: /* term: term OP_MOD factor  */
#line 120 "parser.y"
                                     { (yyval.node) = new BinaryOpNode(Operator::MOD, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1565 "y.tab.c"
    break;

  case 45: /* term: factor  */
#line 121 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1571 "y.tab.c"
    break;

  case 46: /* factor: identifier  */
#line 124 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1577 "y.tab.c"
    break;

  case 47: /* factor: integer  */
#line 125 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1583 "y.tab.c"
    break;

  case 48: /* factor: LP expr RP  */
#line 126 "parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 1589 "y.tab.c"
    break;

  case 49: /* variable: identifier  */
#line 129 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1595 "y.tab.c"
    break;

  case 50: /* identifier: ID  */
#line 132 "parser.y"
                     { (yyval.node) = new VariableNode((yyvsp[0].str)); }
#line 1601 "y.tab.c"
    break;

  case 51: /* integer: INT  */
#line 135 "parser.y"
                      { (yyval.node) = new IntegerNode((yyvsp[0].intNum)); }
#line 1607 "y.tab.c"
    break;

  case 52: /* ctrlstmt: IF LP expr RP statement  */
#line 138 "parser.y"
                                                    { (yyval.node) = new IfStatementNode((yyvsp[-2].node), (yyvsp[0].node), new EmptyStatementNode()); }
#line 1613 "y.tab.c"
    break;

  case 53: /* ctrlstmt: IF LP expr RP statement ELSE statement  */
#line 139 "parser.y"
                                                         { (yyval.node) = new IfStatementNode((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1619 "y.tab.c"
    break;

  case 54: /* ctrlstmt: WHILE LP expr RP statement  */
#line 141 "parser.y"
                                             { (yyval.node) = new WhileStatementNode((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1625 "y.tab.c"
    break;

  case 55: /* ctrlstmt: FOR LP initstmt exprstmt expr RP statement  */
#line 142 "parser.y"
                                                             { (yyval.node) = new ForStatementNode((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1631 "y.tab.c"
    break;

  case 56: /* ctrlstmt: FOR LP initstmt exprstmt RP statement  */
#line 143 "parser.y"
                                                        { (yyval.node) = new ForStatementNode((yyvsp[-3].node), (yyvsp[-2].node), new EmptyExpressionNode() ,(yyvsp[0].node)); }
#line 1637 "y.tab.c"
    break;

  case 57: /* initstmt: exprstmt  */
#line 146 "parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1643 "y.tab.c"
    break;

  case 58: /* initstmt: declaration  */
#line 147 "parser.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1649 "y.tab.c"
    break;


#line 1653 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 150 "parser.y"


void yyerror(char *e) {
    fprintf(stderr, "error: %s\n", e);
}

int yywrap(){
    return 1;
}

void GenerateSyntaxTree(FILE *input, AbstractSyntaxTree &tree){
    extern FILE *yyin;
    yyin = input;
    yyparse();
}
