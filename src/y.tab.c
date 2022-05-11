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
#line 1 "./bison/parser.y"

    #include <stdio.h>
    #include "AbstractSyntaxTree.h"
    #include "TranslationUnitNode.h"
    #include "DeclarationNode.h"
    #include "FunctionNode.h"
    #include "StatementNode.h"
    #include "FunctionCallNode.h"
    #include "OperatorNode.h"
    #include "ExpressionNode.h"
    #include "ConstantNode.h"
    #include "TypeNode.h"

    extern "C" int yylex(void);
    void yyerror(char *);

    ASTNode *root = nullptr;

#line 90 "./src/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM_INT = 3,                    /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 4,                  /* NUM_FLOAT  */
  YYSYMBOL_NUM_BOOL = 5,                   /* NUM_BOOL  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_TYPE_INT = 7,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 8,                 /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_BOOL = 9,                  /* TYPE_BOOL  */
  YYSYMBOL_TYPE_VOID = 10,                 /* TYPE_VOID  */
  YYSYMBOL_OP_ADD = 11,                    /* OP_ADD  */
  YYSYMBOL_OP_SUB = 12,                    /* OP_SUB  */
  YYSYMBOL_OP_MUL = 13,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 14,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 15,                    /* OP_MOD  */
  YYSYMBOL_OP_DADD = 16,                   /* OP_DADD  */
  YYSYMBOL_OP_DSUB = 17,                   /* OP_DSUB  */
  YYSYMBOL_OP_SHL = 18,                    /* OP_SHL  */
  YYSYMBOL_OP_SHR = 19,                    /* OP_SHR  */
  YYSYMBOL_OP_GT = 20,                     /* OP_GT  */
  YYSYMBOL_OP_LT = 21,                     /* OP_LT  */
  YYSYMBOL_OP_GTE = 22,                    /* OP_GTE  */
  YYSYMBOL_OP_LTE = 23,                    /* OP_LTE  */
  YYSYMBOL_OP_EQ = 24,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 25,                    /* OP_NEQ  */
  YYSYMBOL_OP_AND = 26,                    /* OP_AND  */
  YYSYMBOL_OP_XOR = 27,                    /* OP_XOR  */
  YYSYMBOL_OP_OR = 28,                     /* OP_OR  */
  YYSYMBOL_OP_NOT = 29,                    /* OP_NOT  */
  YYSYMBOL_OP_LOGAND = 30,                 /* OP_LOGAND  */
  YYSYMBOL_OP_LOGOR = 31,                  /* OP_LOGOR  */
  YYSYMBOL_OP_LOGNOT = 32,                 /* OP_LOGNOT  */
  YYSYMBOL_OP_ASSIGN = 33,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_ADD_ASSIGN = 34,             /* OP_ADD_ASSIGN  */
  YYSYMBOL_OP_SUB_ASSIGN = 35,             /* OP_SUB_ASSIGN  */
  YYSYMBOL_OP_MUL_ASSIGN = 36,             /* OP_MUL_ASSIGN  */
  YYSYMBOL_OP_DIV_ASSIGN = 37,             /* OP_DIV_ASSIGN  */
  YYSYMBOL_OP_MOD_ASSIGN = 38,             /* OP_MOD_ASSIGN  */
  YYSYMBOL_OP_SHL_ASSIGN = 39,             /* OP_SHL_ASSIGN  */
  YYSYMBOL_OP_SHR_ASSIGN = 40,             /* OP_SHR_ASSIGN  */
  YYSYMBOL_OP_AND_ASSIGN = 41,             /* OP_AND_ASSIGN  */
  YYSYMBOL_OP_OR_ASSIGN = 42,              /* OP_OR_ASSIGN  */
  YYSYMBOL_OP_XOR_ASSIGN = 43,             /* OP_XOR_ASSIGN  */
  YYSYMBOL_LP = 44,                        /* LP  */
  YYSYMBOL_RP = 45,                        /* RP  */
  YYSYMBOL_LBR = 46,                       /* LBR  */
  YYSYMBOL_RBR = 47,                       /* RBR  */
  YYSYMBOL_SEM = 48,                       /* SEM  */
  YYSYMBOL_COMMA = 49,                     /* COMMA  */
  YYSYMBOL_QUEST = 50,                     /* QUEST  */
  YYSYMBOL_COLON = 51,                     /* COLON  */
  YYSYMBOL_IF = 52,                        /* IF  */
  YYSYMBOL_ELSE = 53,                      /* ELSE  */
  YYSYMBOL_WHILE = 54,                     /* WHILE  */
  YYSYMBOL_FOR = 55,                       /* FOR  */
  YYSYMBOL_RETURN = 56,                    /* RETURN  */
  YYSYMBOL_IFX = 57,                       /* IFX  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_externdef = 60,                 /* externdef  */
  YYSYMBOL_function = 61,                  /* function  */
  YYSYMBOL_parameters = 62,                /* parameters  */
  YYSYMBOL_parameter = 63,                 /* parameter  */
  YYSYMBOL_declaration = 64,               /* declaration  */
  YYSYMBOL_declarators = 65,               /* declarators  */
  YYSYMBOL_declarator = 66,                /* declarator  */
  YYSYMBOL_type = 67,                      /* type  */
  YYSYMBOL_identifier = 68,                /* identifier  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_compoundstmt = 70,              /* compoundstmt  */
  YYSYMBOL_items = 71,                     /* items  */
  YYSYMBOL_item = 72,                      /* item  */
  YYSYMBOL_exprstmt = 73,                  /* exprstmt  */
  YYSYMBOL_optexpr = 74,                   /* optexpr  */
  YYSYMBOL_expr = 75,                      /* expr  */
  YYSYMBOL_assignexpr = 76,                /* assignexpr  */
  YYSYMBOL_condexpr = 77,                  /* condexpr  */
  YYSYMBOL_logorexpr = 78,                 /* logorexpr  */
  YYSYMBOL_logandexpr = 79,                /* logandexpr  */
  YYSYMBOL_orexpr = 80,                    /* orexpr  */
  YYSYMBOL_xorexpr = 81,                   /* xorexpr  */
  YYSYMBOL_andexpr = 82,                   /* andexpr  */
  YYSYMBOL_ecmprexpr = 83,                 /* ecmprexpr  */
  YYSYMBOL_cmprexpr = 84,                  /* cmprexpr  */
  YYSYMBOL_shiftexpr = 85,                 /* shiftexpr  */
  YYSYMBOL_addexpr = 86,                   /* addexpr  */
  YYSYMBOL_mulexpr = 87,                   /* mulexpr  */
  YYSYMBOL_primaryexpr = 88,               /* primaryexpr  */
  YYSYMBOL_constant = 89,                  /* constant  */
  YYSYMBOL_arguments = 90,                 /* arguments  */
  YYSYMBOL_ctrlstmt = 91,                  /* ctrlstmt  */
  YYSYMBOL_inititem = 92,                  /* inititem  */
  YYSYMBOL_jumpstmt = 93                   /* jumpstmt  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    75,    78,    79,    82,    85,    86,    87,
      88,    91,    96,    99,   100,   103,   104,   107,   108,   109,
     110,   113,   116,   117,   118,   119,   122,   125,   126,   129,
     130,   133,   136,   137,   140,   141,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   158,   159,
     162,   163,   166,   167,   170,   171,   174,   175,   178,   179,
     182,   183,   184,   187,   188,   189,   190,   191,   194,   195,
     196,   199,   200,   201,   204,   205,   206,   207,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   222,   223,
     224,   227,   228,   229,   232,   233,   235,   236,   239,   240,
     243
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM_INT", "NUM_FLOAT",
  "NUM_BOOL", "ID", "TYPE_INT", "TYPE_FLOAT", "TYPE_BOOL", "TYPE_VOID",
  "OP_ADD", "OP_SUB", "OP_MUL", "OP_DIV", "OP_MOD", "OP_DADD", "OP_DSUB",
  "OP_SHL", "OP_SHR", "OP_GT", "OP_LT", "OP_GTE", "OP_LTE", "OP_EQ",
  "OP_NEQ", "OP_AND", "OP_XOR", "OP_OR", "OP_NOT", "OP_LOGAND", "OP_LOGOR",
  "OP_LOGNOT", "OP_ASSIGN", "OP_ADD_ASSIGN", "OP_SUB_ASSIGN",
  "OP_MUL_ASSIGN", "OP_DIV_ASSIGN", "OP_MOD_ASSIGN", "OP_SHL_ASSIGN",
  "OP_SHR_ASSIGN", "OP_AND_ASSIGN", "OP_OR_ASSIGN", "OP_XOR_ASSIGN", "LP",
  "RP", "LBR", "RBR", "SEM", "COMMA", "QUEST", "COLON", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "IFX", "$accept", "program", "externdef",
  "function", "parameters", "parameter", "declaration", "declarators",
  "declarator", "type", "identifier", "statement", "compoundstmt", "items",
  "item", "exprstmt", "optexpr", "expr", "assignexpr", "condexpr",
  "logorexpr", "logandexpr", "orexpr", "xorexpr", "andexpr", "ecmprexpr",
  "cmprexpr", "shiftexpr", "addexpr", "mulexpr", "primaryexpr", "constant",
  "arguments", "ctrlstmt", "inititem", "jumpstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-134)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -134,    23,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
       5,  -134,    12,  -134,   -31,  -134,     5,   199,   100,  -134,
       3,  -134,  -134,  -134,   199,   199,     5,     5,   199,   199,
     199,   211,  -134,  -134,   -26,    28,    16,     0,    73,    58,
     125,    86,   103,   147,  -134,  -134,    36,   -39,  -134,     5,
      83,  -134,  -134,  -134,  -134,  -134,  -134,   -11,  -134,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
      56,   113,  -134,  -134,   199,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,    -8,    28,   -37,
      16,     0,    73,    58,   125,   125,    86,    86,    86,    86,
     103,   103,   147,   147,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,   199,   199,    84,  -134,  -134,  -134,    85,    88,
      91,   199,  -134,     5,  -134,  -134,  -134,  -134,    89,   114,
    -134,  -134,   199,   199,   169,   116,  -134,    -6,    14,  -134,
    -134,   199,  -134,   138,   138,   117,   115,  -134,   199,   138,
     121,  -134,   138,  -134
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,    17,    18,    19,    20,     2,     4,     5,
       0,    21,     0,    14,    15,    12,     0,     0,    10,    13,
      15,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,    78,    16,    47,    49,    51,    53,    55,    57,    59,
      62,    67,    70,    73,    77,    79,     9,     0,     8,     0,
      78,    82,    83,    86,    87,    84,    85,     0,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    80,     0,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    92,     0,    50,     0,
      52,    54,    56,    58,    60,    61,    63,    64,    65,    66,
      68,    69,    71,    72,    74,    75,    76,    28,     6,     7,
      34,    81,     0,     0,    33,    91,    48,    26,     0,     0,
       0,    33,    29,     0,    30,    22,    27,    23,     0,    32,
      24,    25,     0,     0,    33,     0,    31,     0,     0,    99,
      98,    33,   100,    33,    33,     0,    94,    96,    33,    33,
       0,    95,    33,    97
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,  -134,    78,  -125,  -134,   155,    -1,
      -9,   -66,    93,  -134,  -134,    33,  -133,   -27,   -13,    55,
    -134,   118,   122,   123,   124,   120,    34,    77,    68,    32,
      -3,  -134,  -134,  -134,  -134,  -134
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,     8,    47,    48,     9,    12,    13,    49,
      31,   144,   145,   134,   146,   147,   148,   149,    58,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   107,   150,   161,   151
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    14,    17,    57,    32,    71,    90,    20,   155,   142,
      91,    11,    94,    18,   133,    50,    50,    53,    54,    50,
      50,    51,    52,     2,    72,    55,    56,    75,   165,   159,
       3,     4,     5,     6,    93,   170,    17,   131,    94,   163,
      92,   132,   -20,    94,    74,   109,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    73,   164,
      15,    16,    50,    94,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,   130,    77,    78,   124,   125,   126,    21,    22,    23,
      11,     3,     4,     5,     6,    24,    25,   166,   167,    76,
      26,    27,   127,   171,    83,    84,   173,     3,     4,     5,
      46,   114,   115,    28,    85,    86,    29,   122,   123,   135,
       3,     4,     5,     6,    50,   157,   158,    70,    30,   152,
     127,   137,   153,   143,    20,   154,   138,   156,   139,   140,
     141,    21,    22,    23,    11,    79,    80,    81,    82,    24,
      25,   120,   121,   143,    26,    27,   116,   117,   118,   119,
      87,    88,    89,    94,   162,   168,   172,    28,   169,   129,
      29,    19,    21,    22,    23,    11,     3,     4,     5,     6,
      24,    25,    30,   128,   127,    26,    27,   160,   136,   108,
     138,     0,   139,   140,   141,   110,   113,   111,    28,   112,
       0,    29,    21,    22,    23,    11,     0,     0,     0,     0,
      24,    25,     0,    30,     0,    26,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
       1,    10,    33,    30,    17,    31,    45,    16,   141,   134,
      49,     6,    49,    44,    51,    24,    25,    26,    27,    28,
      29,    24,    25,     0,    50,    28,    29,    27,   161,   154,
       7,     8,     9,    10,    45,   168,    33,    45,    49,    45,
      49,    49,     6,    49,    28,    72,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    30,    45,
      48,    49,    71,    49,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    94,    24,    25,    87,    88,    89,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   163,   164,    26,
      16,    17,    46,   169,    18,    19,   172,     7,     8,     9,
      10,    77,    78,    29,    11,    12,    32,    85,    86,   132,
       7,     8,     9,    10,   133,   152,   153,    44,    44,    44,
      46,    47,    44,   134,   143,    44,    52,    48,    54,    55,
      56,     3,     4,     5,     6,    20,    21,    22,    23,    11,
      12,    83,    84,   154,    16,    17,    79,    80,    81,    82,
      13,    14,    15,    49,    48,    48,    45,    29,    53,    91,
      32,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    44,    90,    46,    16,    17,   154,   133,    71,
      52,    -1,    54,    55,    56,    73,    76,    74,    29,    75,
      -1,    32,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      11,    12,    -1,    44,    -1,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,     0,     7,     8,     9,    10,    60,    61,    64,
      67,     6,    65,    66,    68,    48,    49,    33,    44,    66,
      68,     3,     4,     5,    11,    12,    16,    17,    29,    32,
      44,    68,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    10,    62,    63,    67,
      68,    88,    88,    68,    68,    88,    88,    75,    76,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    31,    50,    30,    28,    27,    26,    24,    25,    20,
      21,    22,    23,    18,    19,    11,    12,    13,    14,    15,
      45,    49,    68,    45,    49,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    90,    79,    75,
      80,    81,    82,    83,    84,    84,    85,    85,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    46,    70,    63,
      76,    45,    49,    51,    71,    76,    77,    47,    52,    54,
      55,    56,    64,    67,    69,    70,    72,    73,    74,    75,
      91,    93,    44,    44,    44,    74,    48,    75,    75,    64,
      73,    92,    48,    45,    45,    74,    69,    69,    48,    53,
      74,    69,    45,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    62,    62,    62,
      62,    63,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    68,    69,    69,    69,    69,    70,    71,    71,    72,
      72,    73,    74,    74,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    83,    84,    84,    84,    84,    84,    85,    85,
      85,    86,    86,    86,    87,    87,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    89,    89,
      89,    90,    90,    90,    91,    91,    91,    91,    92,    92,
      93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     6,     3,     1,     1,
       0,     2,     3,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     0,     1,
       1,     2,     1,     0,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       3,     4,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     3,     1,     0,     5,     7,     5,     8,     1,     1,
       3
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
  case 2: /* program: program externdef  */
#line 74 "./bison/parser.y"
                                    { (yyval.unit) = (yyvsp[-1].unit); (yyval.unit)->AppendDefinition((yyvsp[0].node)); }
#line 1313 "./src/y.tab.c"
    break;

  case 3: /* program: %empty  */
#line 75 "./bison/parser.y"
                              { (yyval.unit) = new TranslationUnitNode(); root = (yyval.unit); }
#line 1319 "./src/y.tab.c"
    break;

  case 4: /* externdef: function  */
#line 78 "./bison/parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1325 "./src/y.tab.c"
    break;

  case 5: /* externdef: declaration  */
#line 79 "./bison/parser.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1331 "./src/y.tab.c"
    break;

  case 6: /* function: type identifier LP parameters RP compoundstmt  */
#line 82 "./bison/parser.y"
                                                                { (yyval.node) = new FunctionNode((yyvsp[-5].type), (yyvsp[-4].identifier), (yyvsp[-2].parameters), (yyvsp[0].compound)); }
#line 1337 "./src/y.tab.c"
    break;

  case 7: /* parameters: parameters COMMA parameter  */
#line 85 "./bison/parser.y"
                                             { (yyval.parameters) = (yyvsp[-2].parameters); (yyvsp[-2].parameters)->AppendParameter((yyvsp[0].declaration)); }
#line 1343 "./src/y.tab.c"
    break;

  case 8: /* parameters: parameter  */
#line 86 "./bison/parser.y"
                            { (yyval.parameters) = new ParameterListNode(); (yyval.parameters)->AppendParameter((yyvsp[0].declaration)); }
#line 1349 "./src/y.tab.c"
    break;

  case 9: /* parameters: TYPE_VOID  */
#line 87 "./bison/parser.y"
                            { (yyval.parameters) = new ParameterListNode(); }
#line 1355 "./src/y.tab.c"
    break;

  case 10: /* parameters: %empty  */
#line 88 "./bison/parser.y"
                              { (yyval.parameters) = new ParameterListNode(); }
#line 1361 "./src/y.tab.c"
    break;

  case 11: /* parameter: type identifier  */
#line 91 "./bison/parser.y"
                                  { auto list = new DeclaratorListNode();
                                    list->AppendDeclarator({(yyvsp[0].identifier), nullptr});
                                    (yyval.declaration) = new DeclarationNode((yyvsp[-1].type), list); }
#line 1369 "./src/y.tab.c"
    break;

  case 12: /* declaration: type declarators SEM  */
#line 96 "./bison/parser.y"
                                       { (yyval.node) = new DeclarationNode((yyvsp[-2].type), (yyvsp[-1].declarators)); }
#line 1375 "./src/y.tab.c"
    break;

  case 13: /* declarators: declarators COMMA declarator  */
#line 99 "./bison/parser.y"
                                               { (yyval.declarators) = (yyvsp[-2].declarators); (yyval.declarators)->AppendDeclarator((yyvsp[0].declarator)); }
#line 1381 "./src/y.tab.c"
    break;

  case 14: /* declarators: declarator  */
#line 100 "./bison/parser.y"
                             { (yyval.declarators) = new DeclaratorListNode(); (yyval.declarators)->AppendDeclarator((yyvsp[0].declarator)); }
#line 1387 "./src/y.tab.c"
    break;

  case 15: /* declarator: identifier  */
#line 103 "./bison/parser.y"
                             { (yyval.declarator) = { (yyvsp[0].identifier), nullptr }; }
#line 1393 "./src/y.tab.c"
    break;

  case 16: /* declarator: identifier OP_ASSIGN assignexpr  */
#line 104 "./bison/parser.y"
                                                  { (yyval.declarator) = { (yyvsp[-2].identifier), (yyvsp[0].expression) }; }
#line 1399 "./src/y.tab.c"
    break;

  case 17: /* type: TYPE_INT  */
#line 107 "./bison/parser.y"
                           { (yyval.type) = new TypeNode(Type::INTEGER); }
#line 1405 "./src/y.tab.c"
    break;

  case 18: /* type: TYPE_FLOAT  */
#line 108 "./bison/parser.y"
                             { (yyval.type) = new TypeNode(Type::FLOAT); }
#line 1411 "./src/y.tab.c"
    break;

  case 19: /* type: TYPE_BOOL  */
#line 109 "./bison/parser.y"
                            { (yyval.type) = new TypeNode(Type::BOOLEAN); }
#line 1417 "./src/y.tab.c"
    break;

  case 20: /* type: TYPE_VOID  */
#line 110 "./bison/parser.y"
                            { (yyval.type) = new TypeNode(Type::VOID); }
#line 1423 "./src/y.tab.c"
    break;

  case 21: /* identifier: ID  */
#line 113 "./bison/parser.y"
                     { (yyval.identifier) = new IdentifierNode((yyvsp[0].str)); }
#line 1429 "./src/y.tab.c"
    break;

  case 22: /* statement: compoundstmt  */
#line 116 "./bison/parser.y"
                               { (yyval.statement) = (yyvsp[0].compound); }
#line 1435 "./src/y.tab.c"
    break;

  case 23: /* statement: exprstmt  */
#line 117 "./bison/parser.y"
                           { (yyval.statement) = (yyvsp[0].statement); }
#line 1441 "./src/y.tab.c"
    break;

  case 24: /* statement: ctrlstmt  */
#line 118 "./bison/parser.y"
                           { (yyval.statement) = (yyvsp[0].statement); }
#line 1447 "./src/y.tab.c"
    break;

  case 25: /* statement: jumpstmt  */
#line 119 "./bison/parser.y"
                           { (yyval.statement) = (yyvsp[0].statement); }
#line 1453 "./src/y.tab.c"
    break;

  case 26: /* compoundstmt: LBR items RBR  */
#line 122 "./bison/parser.y"
                                { (yyval.compound) = (yyvsp[-1].compound); }
#line 1459 "./src/y.tab.c"
    break;

  case 27: /* items: items item  */
#line 125 "./bison/parser.y"
                             { (yyval.compound) = (yyvsp[-1].compound); (yyval.compound)->AppendStatement((yyvsp[0].node)); }
#line 1465 "./src/y.tab.c"
    break;

  case 28: /* items: %empty  */
#line 126 "./bison/parser.y"
                              { (yyval.compound) = new CompoundStatementNode(); }
#line 1471 "./src/y.tab.c"
    break;

  case 29: /* item: declaration  */
#line 129 "./bison/parser.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1477 "./src/y.tab.c"
    break;

  case 30: /* item: statement  */
#line 130 "./bison/parser.y"
                            { (yyval.node) = (yyvsp[0].statement); }
#line 1483 "./src/y.tab.c"
    break;

  case 31: /* exprstmt: optexpr SEM  */
#line 133 "./bison/parser.y"
                              { (yyval.statement) = new ExpressionStatementNode((yyvsp[-1].expression)); }
#line 1489 "./src/y.tab.c"
    break;

  case 32: /* optexpr: expr  */
#line 136 "./bison/parser.y"
                       { (yyval.expression) = (yyvsp[0].expression); }
#line 1495 "./src/y.tab.c"
    break;

  case 33: /* optexpr: %empty  */
#line 137 "./bison/parser.y"
                              { (yyval.expression) = new EmptyExpressionNode(); }
#line 1501 "./src/y.tab.c"
    break;

  case 34: /* expr: expr COMMA assignexpr  */
#line 140 "./bison/parser.y"
                                        { (yyval.expression) = new BinaryOpNode(Operator::COM, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1507 "./src/y.tab.c"
    break;

  case 35: /* expr: assignexpr  */
#line 141 "./bison/parser.y"
                             { (yyval.expression) = (yyvsp[0].expression); }
#line 1513 "./src/y.tab.c"
    break;

  case 36: /* assignexpr: identifier OP_ASSIGN assignexpr  */
#line 144 "./bison/parser.y"
                                                  { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), (yyvsp[0].expression)); }
#line 1519 "./src/y.tab.c"
    break;

  case 37: /* assignexpr: identifier OP_ADD_ASSIGN assignexpr  */
#line 145 "./bison/parser.y"
                                                      { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::ADD, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1525 "./src/y.tab.c"
    break;

  case 38: /* assignexpr: identifier OP_SUB_ASSIGN assignexpr  */
#line 146 "./bison/parser.y"
                                                      { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::SUB, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1531 "./src/y.tab.c"
    break;

  case 39: /* assignexpr: identifier OP_MUL_ASSIGN assignexpr  */
#line 147 "./bison/parser.y"
                                                      { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::MUL, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1537 "./src/y.tab.c"
    break;

  case 40: /* assignexpr: identifier OP_DIV_ASSIGN assignexpr  */
#line 148 "./bison/parser.y"
                                                      { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::DIV, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1543 "./src/y.tab.c"
    break;

  case 41: /* assignexpr: identifier OP_MOD_ASSIGN assignexpr  */
#line 149 "./bison/parser.y"
                                                      { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::MOD, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1549 "./src/y.tab.c"
    break;

  case 42: /* assignexpr: identifier OP_SHL_ASSIGN assignexpr  */
#line 150 "./bison/parser.y"
                                                      { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::SHL, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1555 "./src/y.tab.c"
    break;

  case 43: /* assignexpr: identifier OP_SHR_ASSIGN assignexpr  */
#line 151 "./bison/parser.y"
                                                      { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::SHR, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1561 "./src/y.tab.c"
    break;

  case 44: /* assignexpr: identifier OP_AND_ASSIGN assignexpr  */
#line 152 "./bison/parser.y"
                                                      { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::AND, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1567 "./src/y.tab.c"
    break;

  case 45: /* assignexpr: identifier OP_OR_ASSIGN assignexpr  */
#line 153 "./bison/parser.y"
                                                     { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::OR, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1573 "./src/y.tab.c"
    break;

  case 46: /* assignexpr: identifier OP_XOR_ASSIGN assignexpr  */
#line 154 "./bison/parser.y"
                                                      { (yyval.expression) = new AssignOpNode((yyvsp[-2].identifier), new BinaryOpNode(Operator::XOR, (yyvsp[-2].identifier), (yyvsp[0].expression))); }
#line 1579 "./src/y.tab.c"
    break;

  case 47: /* assignexpr: condexpr  */
#line 155 "./bison/parser.y"
                           { (yyval.expression) = (yyvsp[0].expression); }
#line 1585 "./src/y.tab.c"
    break;

  case 48: /* condexpr: logorexpr QUEST expr COLON condexpr  */
#line 158 "./bison/parser.y"
                                                      { (yyval.expression) = new TernaryOpNode((yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1591 "./src/y.tab.c"
    break;

  case 49: /* condexpr: logorexpr  */
#line 159 "./bison/parser.y"
                            { (yyval.expression) = (yyvsp[0].expression); }
#line 1597 "./src/y.tab.c"
    break;

  case 50: /* logorexpr: logorexpr OP_LOGOR logandexpr  */
#line 162 "./bison/parser.y"
                                                { (yyval.expression) = new BinaryOpNode(Operator::LOGOR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1603 "./src/y.tab.c"
    break;

  case 51: /* logorexpr: logandexpr  */
#line 163 "./bison/parser.y"
                             { (yyval.expression) = (yyvsp[0].expression); }
#line 1609 "./src/y.tab.c"
    break;

  case 52: /* logandexpr: logandexpr OP_LOGAND orexpr  */
#line 166 "./bison/parser.y"
                                              { (yyval.expression) = new BinaryOpNode(Operator::LOGAND, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1615 "./src/y.tab.c"
    break;

  case 53: /* logandexpr: orexpr  */
#line 167 "./bison/parser.y"
                         { (yyval.expression) = (yyvsp[0].expression); }
#line 1621 "./src/y.tab.c"
    break;

  case 54: /* orexpr: orexpr OP_OR xorexpr  */
#line 170 "./bison/parser.y"
                                       { (yyval.expression) = new BinaryOpNode(Operator::OR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1627 "./src/y.tab.c"
    break;

  case 55: /* orexpr: xorexpr  */
#line 171 "./bison/parser.y"
                          { (yyval.expression) = (yyvsp[0].expression); }
#line 1633 "./src/y.tab.c"
    break;

  case 56: /* xorexpr: xorexpr OP_XOR andexpr  */
#line 174 "./bison/parser.y"
                                         { (yyval.expression) = new BinaryOpNode(Operator::XOR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1639 "./src/y.tab.c"
    break;

  case 57: /* xorexpr: andexpr  */
#line 175 "./bison/parser.y"
                          { (yyval.expression) = (yyvsp[0].expression); }
#line 1645 "./src/y.tab.c"
    break;

  case 58: /* andexpr: andexpr OP_AND ecmprexpr  */
#line 178 "./bison/parser.y"
                                           { (yyval.expression) = new BinaryOpNode(Operator::AND, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1651 "./src/y.tab.c"
    break;

  case 59: /* andexpr: ecmprexpr  */
#line 179 "./bison/parser.y"
                            { (yyval.expression) = (yyvsp[0].expression); }
#line 1657 "./src/y.tab.c"
    break;

  case 60: /* ecmprexpr: ecmprexpr OP_EQ cmprexpr  */
#line 182 "./bison/parser.y"
                                           { (yyval.expression) = new BinaryOpNode(Operator::EQ, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1663 "./src/y.tab.c"
    break;

  case 61: /* ecmprexpr: ecmprexpr OP_NEQ cmprexpr  */
#line 183 "./bison/parser.y"
                                            { (yyval.expression) = new BinaryOpNode(Operator::NEQ, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1669 "./src/y.tab.c"
    break;

  case 62: /* ecmprexpr: cmprexpr  */
#line 184 "./bison/parser.y"
                           { (yyval.expression) = (yyvsp[0].expression); }
#line 1675 "./src/y.tab.c"
    break;

  case 63: /* cmprexpr: cmprexpr OP_GT shiftexpr  */
#line 187 "./bison/parser.y"
                                           { (yyval.expression) = new BinaryOpNode(Operator::GT, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1681 "./src/y.tab.c"
    break;

  case 64: /* cmprexpr: cmprexpr OP_LT shiftexpr  */
#line 188 "./bison/parser.y"
                                           { (yyval.expression) = new BinaryOpNode(Operator::LT, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1687 "./src/y.tab.c"
    break;

  case 65: /* cmprexpr: cmprexpr OP_GTE shiftexpr  */
#line 189 "./bison/parser.y"
                                            { (yyval.expression) = new BinaryOpNode(Operator::GTE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1693 "./src/y.tab.c"
    break;

  case 66: /* cmprexpr: cmprexpr OP_LTE shiftexpr  */
#line 190 "./bison/parser.y"
                                            { (yyval.expression) = new BinaryOpNode(Operator::LTE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1699 "./src/y.tab.c"
    break;

  case 67: /* cmprexpr: shiftexpr  */
#line 191 "./bison/parser.y"
                            { (yyval.expression) = (yyvsp[0].expression); }
#line 1705 "./src/y.tab.c"
    break;

  case 68: /* shiftexpr: shiftexpr OP_SHL addexpr  */
#line 194 "./bison/parser.y"
                                           { (yyval.expression) = new BinaryOpNode(Operator::SHL, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1711 "./src/y.tab.c"
    break;

  case 69: /* shiftexpr: shiftexpr OP_SHR addexpr  */
#line 195 "./bison/parser.y"
                                           { (yyval.expression) = new BinaryOpNode(Operator::SHR, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1717 "./src/y.tab.c"
    break;

  case 70: /* shiftexpr: addexpr  */
#line 196 "./bison/parser.y"
                          { (yyval.expression) = (yyvsp[0].expression); }
#line 1723 "./src/y.tab.c"
    break;

  case 71: /* addexpr: addexpr OP_ADD mulexpr  */
#line 199 "./bison/parser.y"
                                         { (yyval.expression) = new BinaryOpNode(Operator::ADD, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1729 "./src/y.tab.c"
    break;

  case 72: /* addexpr: addexpr OP_SUB mulexpr  */
#line 200 "./bison/parser.y"
                                         { (yyval.expression) = new BinaryOpNode(Operator::SUB, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1735 "./src/y.tab.c"
    break;

  case 73: /* addexpr: mulexpr  */
#line 201 "./bison/parser.y"
                          { (yyval.expression) = (yyvsp[0].expression); }
#line 1741 "./src/y.tab.c"
    break;

  case 74: /* mulexpr: mulexpr OP_MUL primaryexpr  */
#line 204 "./bison/parser.y"
                                             { (yyval.expression) = new BinaryOpNode(Operator::MUL, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1747 "./src/y.tab.c"
    break;

  case 75: /* mulexpr: mulexpr OP_DIV primaryexpr  */
#line 205 "./bison/parser.y"
                                             { (yyval.expression) = new BinaryOpNode(Operator::DIV, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1753 "./src/y.tab.c"
    break;

  case 76: /* mulexpr: mulexpr OP_MOD primaryexpr  */
#line 206 "./bison/parser.y"
                                             { (yyval.expression) = new BinaryOpNode(Operator::MOD, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1759 "./src/y.tab.c"
    break;

  case 77: /* mulexpr: primaryexpr  */
#line 207 "./bison/parser.y"
                              { (yyval.expression) = (yyvsp[0].expression); }
#line 1765 "./src/y.tab.c"
    break;

  case 78: /* primaryexpr: identifier  */
#line 210 "./bison/parser.y"
                             { (yyval.expression) = (yyvsp[0].identifier); }
#line 1771 "./src/y.tab.c"
    break;

  case 79: /* primaryexpr: constant  */
#line 211 "./bison/parser.y"
                           { (yyval.expression) = (yyvsp[0].expression); }
#line 1777 "./src/y.tab.c"
    break;

  case 80: /* primaryexpr: LP expr RP  */
#line 212 "./bison/parser.y"
                             { (yyval.expression) = (yyvsp[-1].expression); }
#line 1783 "./src/y.tab.c"
    break;

  case 81: /* primaryexpr: identifier LP arguments RP  */
#line 213 "./bison/parser.y"
                                             { (yyval.expression) = new FunctionCallNode((yyvsp[-3].identifier), (yyvsp[-1].arguments)); }
#line 1789 "./src/y.tab.c"
    break;

  case 82: /* primaryexpr: OP_ADD primaryexpr  */
#line 214 "./bison/parser.y"
                                     { (yyval.expression) = (yyvsp[0].expression); }
#line 1795 "./src/y.tab.c"
    break;

  case 83: /* primaryexpr: OP_SUB primaryexpr  */
#line 215 "./bison/parser.y"
                                     { (yyval.expression) = new BinaryOpNode(Operator::SUB, new IntegerNode(0), (yyvsp[0].expression)); }
#line 1801 "./src/y.tab.c"
    break;

  case 84: /* primaryexpr: OP_NOT primaryexpr  */
#line 216 "./bison/parser.y"
                                     { (yyval.expression) = new BinaryOpNode(Operator::XOR, new IntegerNode(0), (yyvsp[0].expression)); }
#line 1807 "./src/y.tab.c"
    break;

  case 85: /* primaryexpr: OP_LOGNOT primaryexpr  */
#line 217 "./bison/parser.y"
                                        { (yyval.expression) = new BinaryOpNode(Operator::EQ, new IntegerNode(0), (yyvsp[0].expression)); }
#line 1813 "./src/y.tab.c"
    break;

  case 86: /* primaryexpr: OP_DADD identifier  */
#line 218 "./bison/parser.y"
                                     { (yyval.expression) = new AssignOpNode((yyvsp[0].identifier), new BinaryOpNode(Operator::ADD, (yyvsp[0].identifier), new IntegerNode(1))); }
#line 1819 "./src/y.tab.c"
    break;

  case 87: /* primaryexpr: OP_DSUB identifier  */
#line 219 "./bison/parser.y"
                                     { (yyval.expression) = new AssignOpNode((yyvsp[0].identifier), new BinaryOpNode(Operator::SUB, (yyvsp[0].identifier), new IntegerNode(1))); }
#line 1825 "./src/y.tab.c"
    break;

  case 88: /* constant: NUM_INT  */
#line 222 "./bison/parser.y"
                          { (yyval.expression) = new IntegerNode((yyvsp[0].intNum)); }
#line 1831 "./src/y.tab.c"
    break;

  case 89: /* constant: NUM_FLOAT  */
#line 223 "./bison/parser.y"
                            { (yyval.expression) = new FloatNode((yyvsp[0].floatNum)); }
#line 1837 "./src/y.tab.c"
    break;

  case 90: /* constant: NUM_BOOL  */
#line 224 "./bison/parser.y"
                           { (yyval.expression) = new BooleanNode((yyvsp[0].boolNum)); }
#line 1843 "./src/y.tab.c"
    break;

  case 91: /* arguments: arguments COMMA assignexpr  */
#line 227 "./bison/parser.y"
                                             { (yyval.arguments) = (yyvsp[-2].arguments); (yyvsp[-2].arguments)->AppendArgument((yyvsp[0].expression)); }
#line 1849 "./src/y.tab.c"
    break;

  case 92: /* arguments: assignexpr  */
#line 228 "./bison/parser.y"
                             { (yyval.arguments) = new ArgumentListNode(); (yyval.arguments)->AppendArgument((yyvsp[0].expression)); }
#line 1855 "./src/y.tab.c"
    break;

  case 93: /* arguments: %empty  */
#line 229 "./bison/parser.y"
                              { (yyval.arguments) = new ArgumentListNode(); }
#line 1861 "./src/y.tab.c"
    break;

  case 94: /* ctrlstmt: IF LP expr RP statement  */
#line 232 "./bison/parser.y"
                                                    { (yyval.statement) = new IfStatementNode((yyvsp[-2].expression), (yyvsp[0].statement), new ExpressionStatementNode(new EmptyExpressionNode())); }
#line 1867 "./src/y.tab.c"
    break;

  case 95: /* ctrlstmt: IF LP expr RP statement ELSE statement  */
#line 233 "./bison/parser.y"
                                                         { (yyval.statement) = new IfStatementNode((yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1873 "./src/y.tab.c"
    break;

  case 96: /* ctrlstmt: WHILE LP expr RP statement  */
#line 235 "./bison/parser.y"
                                             { (yyval.statement) = new WhileStatementNode((yyvsp[-2].expression), (yyvsp[0].statement)); }
#line 1879 "./src/y.tab.c"
    break;

  case 97: /* ctrlstmt: FOR LP inititem optexpr SEM optexpr RP statement  */
#line 236 "./bison/parser.y"
                                                                   { (yyval.statement) = new ForStatementNode((yyvsp[-5].node), (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].statement)); }
#line 1885 "./src/y.tab.c"
    break;

  case 98: /* inititem: exprstmt  */
#line 239 "./bison/parser.y"
                           { (yyval.node) = (yyvsp[0].statement); }
#line 1891 "./src/y.tab.c"
    break;

  case 99: /* inititem: declaration  */
#line 240 "./bison/parser.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1897 "./src/y.tab.c"
    break;

  case 100: /* jumpstmt: RETURN optexpr SEM  */
#line 243 "./bison/parser.y"
                                     { (yyval.statement) = new ReturnStatementNode((yyvsp[-1].expression)); }
#line 1903 "./src/y.tab.c"
    break;


#line 1907 "./src/y.tab.c"

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

#line 246 "./bison/parser.y"


void yyerror(char *e) {
    fprintf(stderr, "error: %s\n", e);
}

int yywrap(){
    return 1;
}

ASTNode *parse_and_generate_syntax_tree(FILE *input){
    extern FILE *yyin;
    yyin = input;
    yyparse();
    return root;
}
