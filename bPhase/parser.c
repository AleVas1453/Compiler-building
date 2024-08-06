/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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

// Definitions of Macros/Functions/Variables 
#include <stdio.h>
#include "symtab.h"

int yyerror(const char* yaccProvidedMessage);
int yylex(void);
const char* getType(enum SymbolType type);
void print_syntax(const char *name, enum SymbolType type, unsigned int line, unsigned int scope);


extern int yylineno;
extern char* yytext;
extern FILE* yyin;


#line 88 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* "id"  */
  YYSYMBOL_INT = 4,                        /* "int"  */
  YYSYMBOL_DOUBLE = 5,                     /* "double"  */
  YYSYMBOL_IF = 6,                         /* "if"  */
  YYSYMBOL_ELSE = 7,                       /* "else"  */
  YYSYMBOL_THEN = 8,                       /* "then"  */
  YYSYMBOL_FOR = 9,                        /* "for"  */
  YYSYMBOL_WHILE = 10,                     /* "while"  */
  YYSYMBOL_BREAK = 11,                     /* "break"  */
  YYSYMBOL_CONTINUE = 12,                  /* "continue"  */
  YYSYMBOL_RETURN = 13,                    /* "return"  */
  YYSYMBOL_TRUE = 14,                      /* "true"  */
  YYSYMBOL_FALSE = 15,                     /* "false"  */
  YYSYMBOL_NOT = 16,                       /* "not"  */
  YYSYMBOL_AND = 17,                       /* "and"  */
  YYSYMBOL_OR = 18,                        /* "or"  */
  YYSYMBOL_FUNCTION = 19,                  /* "function"  */
  YYSYMBOL_NIL = 20,                       /* "nil"  */
  YYSYMBOL_SIMPLESPACE = 21,               /* "simplespace"  */
  YYSYMBOL_NEWLINE = 22,                   /* "newline"  */
  YYSYMBOL_MULTISPACE = 23,                /* "multispace"  */
  YYSYMBOL_LINECOMMENT = 24,               /* "linecomment"  */
  YYSYMBOL_LEFTBRACKET = 25,               /* "["  */
  YYSYMBOL_RIGHTBRACKET = 26,              /* "]"  */
  YYSYMBOL_LEFTPARENTHESES = 27,           /* "("  */
  YYSYMBOL_RIGHTPARENTHESES = 28,          /* ")"  */
  YYSYMBOL_LEFTBRACES = 29,                /* "{"  */
  YYSYMBOL_RIGHTBRACES = 30,               /* "}"  */
  YYSYMBOL_COLON = 31,                     /* ":"  */
  YYSYMBOL_SEMICOLON = 32,                 /* ";"  */
  YYSYMBOL_COMMA = 33,                     /* ","  */
  YYSYMBOL_FULLSTOP = 34,                  /* "."  */
  YYSYMBOL_DFULLSTOP = 35,                 /* ".."  */
  YYSYMBOL_PLUS = 36,                      /* "+"  */
  YYSYMBOL_SUB = 37,                       /* "-"  */
  YYSYMBOL_MULTIPLY = 38,                  /* "*"  */
  YYSYMBOL_DIVISION = 39,                  /* "/"  */
  YYSYMBOL_PERCENT = 40,                   /* "%"  */
  YYSYMBOL_PLUSPLUS = 41,                  /* "++"  */
  YYSYMBOL_MINUSMINUS = 42,                /* "--"  */
  YYSYMBOL_EQUAL = 43,                     /* "="  */
  YYSYMBOL_NOTEQUAL = 44,                  /* "!="  */
  YYSYMBOL_GREATER = 45,                   /* ">"  */
  YYSYMBOL_LESS = 46,                      /* "<"  */
  YYSYMBOL_LESSEQUAL = 47,                 /* "<="  */
  YYSYMBOL_GREATEREQUAL = 48,              /* ">="  */
  YYSYMBOL_EQUALEQUAL = 49,                /* "=="  */
  YYSYMBOL_SCOPERESOLUTION = 50,           /* "::"  */
  YYSYMBOL_LOCALY = 51,                    /* LOCALY  */
  YYSYMBOL_UMINUS = 52,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_stmt = 55,                      /* stmt  */
  YYSYMBOL_expr = 56,                      /* expr  */
  YYSYMBOL_term = 57,                      /* term  */
  YYSYMBOL_assignexpr = 58,                /* assignexpr  */
  YYSYMBOL_primary = 59,                   /* primary  */
  YYSYMBOL_lvalue = 60,                    /* lvalue  */
  YYSYMBOL_member = 61,                    /* member  */
  YYSYMBOL_call = 62,                      /* call  */
  YYSYMBOL_callsuffix = 63,                /* callsuffix  */
  YYSYMBOL_normcall = 64,                  /* normcall  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_methodcall = 66,                /* methodcall  */
  YYSYMBOL_elist = 67,                     /* elist  */
  YYSYMBOL_objectdef = 68,                 /* objectdef  */
  YYSYMBOL_indexed = 69,                   /* indexed  */
  YYSYMBOL_indexedelem = 70,               /* indexedelem  */
  YYSYMBOL_block = 71,                     /* block  */
  YYSYMBOL_funcdef = 72,                   /* funcdef  */
  YYSYMBOL_73_2 = 73,                      /* $@2  */
  YYSYMBOL_const = 74,                     /* const  */
  YYSYMBOL_idlist = 75,                    /* idlist  */
  YYSYMBOL_ifstmt = 76,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 77,                 /* whilestmt  */
  YYSYMBOL_forstmt = 78,                   /* forstmt  */
  YYSYMBOL_returnstmt = 79                 /* returnstmt  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   576

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   104,   104,   105,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   137,   138,
     139,   140,   141,   142,   143,   144,   147,   150,   151,   152,
     153,   154,   157,   159,   160,   161,   164,   165,   166,   167,
     170,   171,   172,   175,   176,   179,   179,   182,   185,   186,
     189,   190,   193,   194,   197,   200,   203,   203,   206,   207,
     208,   209,   209,   212,   213,   216,   217,   220,   223,   226,
     227
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"id\"", "\"int\"",
  "\"double\"", "\"if\"", "\"else\"", "\"then\"", "\"for\"", "\"while\"",
  "\"break\"", "\"continue\"", "\"return\"", "\"true\"", "\"false\"",
  "\"not\"", "\"and\"", "\"or\"", "\"function\"", "\"nil\"",
  "\"simplespace\"", "\"newline\"", "\"multispace\"", "\"linecomment\"",
  "\"[\"", "\"]\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\":\"", "\";\"",
  "\",\"", "\".\"", "\"..\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"",
  "\"++\"", "\"--\"", "\"=\"", "\"!=\"", "\">\"", "\"<\"", "\"<=\"",
  "\">=\"", "\"==\"", "\"::\"", "LOCALY", "UMINUS", "$accept", "program",
  "stmt", "expr", "term", "assignexpr", "primary", "lvalue", "member",
  "call", "callsuffix", "normcall", "$@1", "methodcall", "elist",
  "objectdef", "indexed", "indexedelem", "block", "funcdef", "$@2",
  "const", "idlist", "ifstmt", "whilestmt", "forstmt", "returnstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     136,   -43,   -43,   -43,   -21,   -11,    -6,   -14,     0,   165,
     -43,   -43,   248,     5,   -43,   205,   208,   136,   248,    -2,
      -2,    34,    40,    56,   136,   264,   -43,   -43,   -43,   -15,
     -43,     4,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     248,   248,   248,   -43,   -43,   -43,   288,   -43,    54,   248,
     475,   -19,    -9,   -43,   312,    33,    48,    37,    63,   -12,
       4,   -12,   -43,   -43,   -43,   -43,   248,   248,   -43,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,    89,    96,   -43,   -43,   248,   -43,   -43,   -43,
     248,   248,    97,   326,     7,   350,   -43,    75,   374,   -43,
     248,   -43,    74,   -43,    77,   -43,    78,   513,   499,    37,
      37,   -43,   -43,   -43,   527,    49,    49,    49,    49,   527,
     389,    72,   -43,    80,   475,   413,     8,   -43,   136,   248,
     136,    81,   248,   475,   -43,   248,    77,   -43,    82,   248,
     -43,   -43,   102,   437,   -43,   -43,   461,    18,   -43,    19,
     136,   248,   109,   -43,   -43,   -43,   -43,    22,   -43,    25,
     136,    86,   113,   -43,   -43,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    42,    68,    69,     0,     0,     0,     0,     0,     0,
      71,    72,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,    27,    13,    35,    37,
      45,    38,    39,    11,    12,    41,     5,     6,     7,     8,
       0,     0,     0,     9,    10,    79,     0,    30,     0,     0,
      58,     0,     0,    62,     0,     0,     0,    29,     0,    31,
       0,    33,    44,    43,     1,     3,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    34,     0,    51,    53,    54,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    60,
       0,    61,     0,    28,    40,    65,     0,    25,    26,    14,
      15,    16,    17,    18,    24,    19,    21,    22,    20,    23,
       0,    55,    46,     0,    36,     0,     0,    48,     0,     0,
       0,     0,     0,    59,    63,     0,     0,    47,     0,     0,
      49,    50,    75,     0,    77,    66,     0,     0,    56,     0,
       0,     0,     0,    64,    52,    57,    76,     0,    73,     0,
       0,     0,     0,    78,    67,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,    93,   -17,    -7,   -43,   -43,   -43,    61,   -43,    71,
     -43,   -43,   -43,   -43,   -37,   -43,   -43,    16,   -42,   -13,
     -43,   -43,   -43,   -43,   -43,   -43,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      87,    88,   138,    89,    51,    32,    52,    53,    33,    34,
     152,    35,   159,    36,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,     1,    46,    55,    94,    47,    40,    99,    50,    54,
      80,    57,    81,    80,   100,    81,    41,   101,    43,    82,
      83,    42,    82,    83,   102,    58,    84,    85,    86,    90,
      48,    91,    44,    93,    50,    95,   141,    62,    92,   129,
     100,   100,    98,    63,   121,   106,   154,   155,    21,    22,
     160,   100,   100,   161,   126,   100,    64,    97,   162,   107,
     108,   104,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    50,    71,    72,    73,   105,   124,
      59,    61,    13,   125,    50,    69,    70,    71,    72,    73,
      60,    60,   122,   133,    -1,    -1,    -1,    -1,   147,   123,
     127,   131,   149,    49,   135,   100,   136,   139,   145,   150,
     148,   142,   158,   144,   157,    17,   165,    65,   134,   164,
       0,     0,   143,     0,     0,   146,     0,     0,    50,     0,
       0,     0,    50,   156,     0,     0,     0,     0,     0,     1,
       2,     3,     4,   163,    50,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,    13,    14,     0,     0,     0,
       0,    15,     0,    16,     0,    17,     0,     0,     1,     2,
       3,     0,     0,    18,     0,     0,     0,    19,    20,    10,
      11,    12,     0,     0,     0,    14,    21,    22,     0,     0,
      15,     0,    16,     0,     0,     0,     0,    45,     0,     0,
       0,     0,    18,     0,     0,     0,    19,    20,     1,     2,
       3,     1,     2,     3,     0,    21,    22,     0,     0,    10,
      11,    12,    10,    11,    12,    14,     0,    13,    14,     0,
      15,     0,    16,    15,    49,    16,     0,     0,     0,     0,
       0,     0,    18,     0,     0,    18,    19,    20,     0,    19,
      20,     1,     2,     3,     0,    21,    22,     0,    21,    22,
       0,     0,    10,    11,    12,     0,     0,     0,    14,     0,
       0,     0,     0,    15,     0,    16,     0,     0,     0,     0,
       0,    66,    67,     0,     0,    18,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,    68,     0,    21,    22,
      69,    70,    71,    72,    73,    66,    67,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,     0,     0,     0,
      96,     0,     0,     0,    69,    70,    71,    72,    73,    66,
      67,     0,    74,    75,    76,    77,    78,    79,     0,     0,
     103,     0,     0,    66,    67,     0,     0,     0,    69,    70,
      71,    72,    73,     0,   128,     0,    74,    75,    76,    77,
      78,    79,    69,    70,    71,    72,    73,    66,    67,     0,
      74,    75,    76,    77,    78,    79,     0,     0,   130,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    66,    67,     0,    74,    75,    76,    77,    78,    79,
       0,     0,     0,     0,     0,   132,    66,    67,     0,     0,
      69,    70,    71,    72,    73,   137,     0,     0,    74,    75,
      76,    77,    78,    79,     0,    69,    70,    71,    72,    73,
      66,    67,     0,    74,    75,    76,    77,    78,    79,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    66,    67,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,     0,     0,   151,
       0,     0,     0,    69,    70,    71,    72,    73,    66,    67,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,   153,    66,    67,     0,     0,     0,    69,    70,    71,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    69,    70,    71,    72,    73,    66,     0,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    69,
      70,    71,    72,    73,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    69,    70,    71,    72,    73,     0,     0,
       0,    -1,    75,    76,    77,    78,    -1
};

static const yytype_int16 yycheck[] =
{
      17,     3,     9,    16,    41,    12,    27,    26,    15,    16,
      25,    18,    27,    25,    33,    27,    27,    26,    32,    34,
      35,    27,    34,    35,    33,    27,    41,    42,    43,    25,
      25,    27,    32,    40,    41,    42,    28,     3,    34,    32,
      33,    33,    49,     3,    81,    58,    28,    28,    50,    51,
      28,    33,    33,    28,    91,    33,     0,     3,    33,    66,
      67,    28,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    38,    39,    40,    30,    86,
      19,    20,    19,    90,    91,    36,    37,    38,    39,    40,
      19,    20,     3,   100,    45,    46,    47,    48,   135,     3,
       3,    26,   139,    29,    27,    33,    28,    27,    27,     7,
      28,   128,     3,   130,   151,    29,     3,    24,   102,   161,
      -1,    -1,   129,    -1,    -1,   132,    -1,    -1,   135,    -1,
      -1,    -1,   139,   150,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,   160,   151,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    25,    -1,    27,    -1,    29,    -1,    -1,     3,     4,
       5,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,    14,
      15,    16,    -1,    -1,    -1,    20,    50,    51,    -1,    -1,
      25,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    41,    42,     3,     4,
       5,     3,     4,     5,    -1,    50,    51,    -1,    -1,    14,
      15,    16,    14,    15,    16,    20,    -1,    19,    20,    -1,
      25,    -1,    27,    25,    29,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    37,    41,    42,    -1,    41,
      42,     3,     4,     5,    -1,    50,    51,    -1,    50,    51,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    37,    -1,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    32,    -1,    50,    51,
      36,    37,    38,    39,    40,    17,    18,    -1,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    36,    37,    38,    39,    40,    17,
      18,    -1,    44,    45,    46,    47,    48,    49,    -1,    -1,
      28,    -1,    -1,    17,    18,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    28,    -1,    44,    45,    46,    47,
      48,    49,    36,    37,    38,    39,    40,    17,    18,    -1,
      44,    45,    46,    47,    48,    49,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    17,    18,    -1,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    31,    17,    18,    -1,    -1,
      36,    37,    38,    39,    40,    26,    -1,    -1,    44,    45,
      46,    47,    48,    49,    -1,    36,    37,    38,    39,    40,
      17,    18,    -1,    44,    45,    46,    47,    48,    49,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    17,    18,    -1,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    17,    18,
      -1,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    30,    17,    18,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    36,    37,    38,    39,    40,    17,    -1,    -1,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    10,    11,    12,    13,
      14,    15,    16,    19,    20,    25,    27,    29,    37,    41,
      42,    50,    51,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    68,    71,    72,    74,    76,    77,    78,    79,
      27,    27,    27,    32,    32,    32,    56,    56,    25,    29,
      56,    67,    69,    70,    56,    72,    55,    56,    27,    60,
      62,    60,     3,     3,     0,    54,    17,    18,    32,    36,
      37,    38,    39,    40,    44,    45,    46,    47,    48,    49,
      25,    27,    34,    35,    41,    42,    43,    63,    64,    66,
      25,    27,    34,    56,    67,    56,    32,     3,    56,    26,
      33,    26,    33,    28,    28,    30,    72,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    67,     3,     3,    56,    56,    67,     3,    28,    32,
      28,    26,    31,    56,    70,    27,    28,    26,    65,    27,
      26,    28,    55,    56,    55,    27,    56,    67,    28,    67,
       7,    32,    73,    30,    28,    28,    55,    67,     3,    75,
      28,    28,    33,    55,    71,     3
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    61,    61,    61,    61,
      62,    62,    62,    63,    63,    65,    64,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    73,    72,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    77,    78,    79,
      79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     2,
       2,     2,     2,     2,     2,     1,     3,     1,     1,     1,
       3,     1,     1,     2,     2,     1,     3,     4,     3,     4,
       4,     2,     6,     1,     1,     0,     4,     5,     1,     3,
       3,     3,     1,     3,     5,     3,     0,     9,     1,     1,
       1,     1,     1,     1,     3,     5,     7,     5,     9,     2,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 42: /* lvalue: "id"  */
#line 157 "parser.y"
                                    {insert_symtab((yyvsp[0].stringValue), LOCAL, 0, scope, yylineno);
                                    print_syntax((yyvsp[0].stringValue), LOCAL, yylineno, scope);}
#line 1629 "parser.c"
    break;

  case 43: /* lvalue: LOCALY "id"  */
#line 159 "parser.y"
                                     {insert_symtab((yyvsp[0].stringValue), LOCAL, 0, scope, yylineno);}
#line 1635 "parser.c"
    break;

  case 44: /* lvalue: "::" "id"  */
#line 160 "parser.y"
                                    {insert_symtab((yyvsp[0].stringValue), LOCAL, 0, scope, yylineno);}
#line 1641 "parser.c"
    break;

  case 46: /* member: lvalue "." "id"  */
#line 164 "parser.y"
                                                    {insert_symtab((yyvsp[0].stringValue), LOCAL, 0, scope, yylineno);}
#line 1647 "parser.c"
    break;

  case 48: /* member: call "." "id"  */
#line 166 "parser.y"
                                                    {insert_symtab((yyvsp[0].stringValue), LOCAL, 0, scope, yylineno);}
#line 1653 "parser.c"
    break;

  case 55: /* $@1: %empty  */
#line 179 "parser.y"
                                  {scope++;}
#line 1659 "parser.c"
    break;

  case 56: /* normcall: "(" elist $@1 ")"  */
#line 179 "parser.y"
                                                                {scope--;}
#line 1665 "parser.c"
    break;

  case 57: /* methodcall: ".." "id" "(" elist ")"  */
#line 182 "parser.y"
                                                                    {insert_symtab((yyvsp[-4].stringValue), LOCAL, 0, scope, yylineno);}
#line 1671 "parser.c"
    break;

  case 66: /* $@2: %empty  */
#line 203 "parser.y"
                                                                 {scope++;}
#line 1677 "parser.c"
    break;

  case 67: /* funcdef: "function" "[" "id" "]" "(" $@2 idlist ")" block  */
#line 203 "parser.y"
                                                                                                          {scope--;}
#line 1683 "parser.c"
    break;

  case 80: /* returnstmt: "return" expr ";"  */
#line 227 "parser.y"
                                   {scope--;}
#line 1689 "parser.c"
    break;


#line 1693 "parser.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 230 "parser.y"



int yyerror(const char* yaccProvidedMessage){
    fprintf(stderr, "%s: at line %d, before token %s\n", yaccProvidedMessage, yylineno, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
    return 1;           /* Oxi aparaitito to return (To function mporei na einai void) */
}

const char* getType(enum SymbolType type) 
{
   switch (type) 
   {
      case GLOBAL: return "GLOBAL";
      case LOCAL: return "LOCAL";
      case FORMAL: return "FORMAL";
      case USERFUNC: return "USERFUNC";
      case LIBFUNC: return "LIBFUNC";
   }
}

void print_syntax(const char *name, enum SymbolType type, unsigned int line, unsigned int scope){
    printf(" \"%s\" \t [%s] (line %d) (scope %d) \n", name, getType(type), line, scope);

}

int main(int argc, char **argv) {
    
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr, "Cannot read file: %s\n", argv[1]);
            return 1;
        }
    }else{
        yyin = stdin;
    }

    yyparse();
    return 0;
}
