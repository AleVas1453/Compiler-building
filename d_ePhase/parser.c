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
#ifndef QUADFUNC_H
#define QUADFUNC_H
#include "quadfunc.h"
#endif
#include "instructions.h"

int scope = 0;
int metritis=0;
int loopcounter = 0;
int infunctioncounter = 0;

void yyerror(const char* yaccProvidedMessage);
int yylex(void);

extern int yylineno;
extern char* yytext;
extern FILE* yyin;

/*---------- C Phase -------- */
stackkk* scopeoffsetstack = NULL; /* stack pou afora to offset */
stackkk* loopcounterstack = NULL; /* stack pou afora ton loopcounter, gia na elegxw an eimai se block kapoiou loop */


#line 97 "parser.c"

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
  YYSYMBOL_STRING = 6,                     /* "string"  */
  YYSYMBOL_IF = 7,                         /* "if"  */
  YYSYMBOL_ELSE = 8,                       /* "else"  */
  YYSYMBOL_THEN = 9,                       /* "then"  */
  YYSYMBOL_FOR = 10,                       /* "for"  */
  YYSYMBOL_WHILE = 11,                     /* "while"  */
  YYSYMBOL_BREAK = 12,                     /* "break"  */
  YYSYMBOL_CONTINUE = 13,                  /* "continue"  */
  YYSYMBOL_RETURN = 14,                    /* "return"  */
  YYSYMBOL_TRUE = 15,                      /* "true"  */
  YYSYMBOL_FALSE = 16,                     /* "false"  */
  YYSYMBOL_NOT = 17,                       /* "not"  */
  YYSYMBOL_AND = 18,                       /* "and"  */
  YYSYMBOL_OR = 19,                        /* "or"  */
  YYSYMBOL_FUNCTION = 20,                  /* "function"  */
  YYSYMBOL_NIL = 21,                       /* "nil"  */
  YYSYMBOL_SIMPLESPACE = 22,               /* "simplespace"  */
  YYSYMBOL_NEWLINE = 23,                   /* "newline"  */
  YYSYMBOL_MULTISPACE = 24,                /* "multispace"  */
  YYSYMBOL_LINECOMMENT = 25,               /* "linecomment"  */
  YYSYMBOL_LEFTBRACKET = 26,               /* "["  */
  YYSYMBOL_RIGHTBRACKET = 27,              /* "]"  */
  YYSYMBOL_LEFTPARENTHESES = 28,           /* "("  */
  YYSYMBOL_RIGHTPARENTHESES = 29,          /* ")"  */
  YYSYMBOL_LEFTBRACES = 30,                /* "{"  */
  YYSYMBOL_RIGHTBRACES = 31,               /* "}"  */
  YYSYMBOL_COLON = 32,                     /* ":"  */
  YYSYMBOL_SEMICOLON = 33,                 /* ";"  */
  YYSYMBOL_COMMA = 34,                     /* ","  */
  YYSYMBOL_FULLSTOP = 35,                  /* "."  */
  YYSYMBOL_DFULLSTOP = 36,                 /* ".."  */
  YYSYMBOL_PLUS = 37,                      /* "+"  */
  YYSYMBOL_SUB = 38,                       /* "-"  */
  YYSYMBOL_MULTIPLY = 39,                  /* "*"  */
  YYSYMBOL_DIVISION = 40,                  /* "/"  */
  YYSYMBOL_PERCENT = 41,                   /* "%"  */
  YYSYMBOL_PLUSPLUS = 42,                  /* "++"  */
  YYSYMBOL_MINUSMINUS = 43,                /* "--"  */
  YYSYMBOL_EQUAL = 44,                     /* "="  */
  YYSYMBOL_NOTEQUAL = 45,                  /* "!="  */
  YYSYMBOL_GREATER = 46,                   /* ">"  */
  YYSYMBOL_LESS = 47,                      /* "<"  */
  YYSYMBOL_LESSEQUAL = 48,                 /* "<="  */
  YYSYMBOL_GREATEREQUAL = 49,              /* ">="  */
  YYSYMBOL_EQUALEQUAL = 50,                /* "=="  */
  YYSYMBOL_SCOPERESOLUTION = 51,           /* "::"  */
  YYSYMBOL_LOCAL = 52,                     /* LOCAL  */
  YYSYMBOL_UMINUS = 53,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_stmt = 57,                      /* stmt  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_assignexpr = 60,                /* assignexpr  */
  YYSYMBOL_primary = 61,                   /* primary  */
  YYSYMBOL_lvalue = 62,                    /* lvalue  */
  YYSYMBOL_member = 63,                    /* member  */
  YYSYMBOL_call = 64,                      /* call  */
  YYSYMBOL_callsuffix = 65,                /* callsuffix  */
  YYSYMBOL_normcall = 66,                  /* normcall  */
  YYSYMBOL_methodcall = 67,                /* methodcall  */
  YYSYMBOL_elist = 68,                     /* elist  */
  YYSYMBOL_objectdef = 69,                 /* objectdef  */
  YYSYMBOL_indexed = 70,                   /* indexed  */
  YYSYMBOL_indexedelem = 71,               /* indexedelem  */
  YYSYMBOL_block = 72,                     /* block  */
  YYSYMBOL_73_1 = 73,                      /* $@1  */
  YYSYMBOL_funcname = 74,                  /* funcname  */
  YYSYMBOL_funcprefix = 75,                /* funcprefix  */
  YYSYMBOL_funcargs = 76,                  /* funcargs  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_funcbody = 78,                  /* funcbody  */
  YYSYMBOL_funcdef = 79,                   /* funcdef  */
  YYSYMBOL_const = 80,                     /* const  */
  YYSYMBOL_idlist = 81,                    /* idlist  */
  YYSYMBOL_ifprefix = 82,                  /* ifprefix  */
  YYSYMBOL_elseprefix = 83,                /* elseprefix  */
  YYSYMBOL_ifstmt = 84,                    /* ifstmt  */
  YYSYMBOL_whilestart = 85,                /* whilestart  */
  YYSYMBOL_whilecond = 86,                 /* whilecond  */
  YYSYMBOL_whilestmt = 87,                 /* whilestmt  */
  YYSYMBOL_N = 88,                         /* N  */
  YYSYMBOL_M = 89,                         /* M  */
  YYSYMBOL_forprefix = 90,                 /* forprefix  */
  YYSYMBOL_forstmt = 91,                   /* forstmt  */
  YYSYMBOL_returnstmt = 92                 /* returnstmt  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   693

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   130,   136,   139,   144,   147,   150,   153,
     156,   159,   171,   182,   185,   188,   191,   193,   199,   205,
     211,   217,   223,   232,   241,   250,   259,   268,   277,   283,
     289,   293,   296,   304,   316,   330,   346,   359,   375,   380,
     394,   397,   400,   403,   411,   415,   439,   463,   473,   477,
     480,   486,   490,   498,   505,   526,   534,   535,   538,   547,
     557,   568,   587,   592,   605,   615,   616,   638,   650,   650,
     663,   666,   673,   699,   699,   711,   718,   733,   735,   737,
     739,   744,   746,   753,   771,   787,   790,   797,   803,   810,
     829,   833,   840,   850,   855,   859,   868,   880,   888
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
  "\"double\"", "\"string\"", "\"if\"", "\"else\"", "\"then\"", "\"for\"",
  "\"while\"", "\"break\"", "\"continue\"", "\"return\"", "\"true\"",
  "\"false\"", "\"not\"", "\"and\"", "\"or\"", "\"function\"", "\"nil\"",
  "\"simplespace\"", "\"newline\"", "\"multispace\"", "\"linecomment\"",
  "\"[\"", "\"]\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\":\"", "\";\"",
  "\",\"", "\".\"", "\"..\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"",
  "\"++\"", "\"--\"", "\"=\"", "\"!=\"", "\">\"", "\"<\"", "\"<=\"",
  "\">=\"", "\"==\"", "\"::\"", "LOCAL", "UMINUS", "$accept", "program",
  "statement", "stmt", "expr", "term", "assignexpr", "primary", "lvalue",
  "member", "call", "callsuffix", "normcall", "methodcall", "elist",
  "objectdef", "indexed", "indexedelem", "block", "$@1", "funcname",
  "funcprefix", "funcargs", "$@2", "funcbody", "funcdef", "const",
  "idlist", "ifprefix", "elseprefix", "ifstmt", "whilestart", "whilecond",
  "whilestmt", "N", "M", "forprefix", "forstmt", "returnstmt", YY_NULLPTR
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
     305,   306,   307,   308
};
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-5)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     121,  -161,     5,   259,  -161,  -161,  -161,  -161,  -161,   -19,
     -15,  -161,     4,    12,   300,  -161,  -161,   379,    45,  -161,
     319,   360,  -161,  -161,   379,     0,     0,    55,    69,  -161,
     395,  -161,  -161,  -161,   -20,  -161,     3,  -161,  -161,    68,
    -161,  -161,   259,  -161,    70,  -161,  -161,  -161,  -161,   379,
     379,  -161,  -161,  -161,   419,  -161,  -161,  -161,   379,   598,
      20,    22,  -161,   443,    56,   173,  -161,    75,   -16,     3,
     -16,  -161,  -161,   379,   379,  -161,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,    94,
      96,  -161,  -161,   379,  -161,  -161,  -161,   379,   379,   100,
    -161,    76,    97,   379,   259,   379,   457,    -7,  -161,   481,
    -161,   379,  -161,    77,  -161,    82,   216,    83,   629,   615,
      48,    48,  -161,  -161,  -161,   643,    -5,    -5,    -5,    -5,
     643,   496,    -4,  -161,    86,   598,   520,    30,  -161,   108,
    -161,  -161,  -161,   259,   534,  -161,    31,  -161,  -161,   379,
     598,  -161,   379,  -161,    82,  -161,  -161,   379,  -161,  -161,
    -161,    32,  -161,  -161,  -161,   379,   558,    33,    57,  -161,
     112,   259,   582,  -161,  -161,  -161,  -161,  -161,  -161,  -161
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     0,     2,     1,    45,    77,    78,    79,     0,
       0,    90,     0,     0,     0,    81,    82,     0,    71,    80,
      62,     0,    68,    15,     0,     0,     0,     0,     0,     3,
       0,    30,    16,    38,    40,    48,    41,    42,    13,     0,
      14,    44,     0,     7,     0,     8,    93,     9,    10,     0,
      62,    11,    12,    97,     0,    33,    70,    72,     0,    60,
       0,     0,    65,     0,     0,     0,    32,     0,    34,     0,
      36,    47,    46,     0,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,    35,    37,     0,    54,    56,    57,     0,    62,     0,
      73,     0,    88,     0,     0,    62,     0,     0,    98,     0,
      63,     0,    64,     0,    31,    43,     0,     0,    28,    29,
      17,    18,    19,    20,    21,    27,    22,    24,    25,    23,
      26,     0,     0,    49,     0,    39,     0,     0,    51,    85,
      75,    76,    87,     0,     0,    92,     0,    86,    94,     0,
      61,    66,    62,    69,     0,    50,    58,    62,    52,    53,
      83,     0,    89,    91,    93,     0,     0,     0,     0,    74,
       0,     0,     0,    67,    55,    59,    84,    93,    95,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,    51,   -41,    -3,  -161,  -161,  -161,    43,  -161,
      67,  -161,  -161,  -161,   -48,  -161,  -161,     6,    16,  -161,
    -161,  -161,  -161,  -161,  -161,   -14,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -160,  -161,  -161,  -161,  -161
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    29,    59,    31,    32,    33,    34,    35,
      36,    94,    95,    96,    60,    37,    61,    62,    38,    65,
      57,    39,   101,   139,   141,    40,    41,   161,    42,   143,
      43,    44,   104,    45,   105,   165,    46,    47,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,   102,   107,     5,   171,     4,    87,    64,    88,    49,
      87,    54,    88,    50,    55,    89,    90,   179,    63,    89,
      90,    66,    91,    92,    93,   156,   148,   111,    67,    97,
     111,    98,    76,    77,    78,    79,    80,    51,    99,    30,
     132,    -5,    -5,    -5,    -5,    52,   106,   110,    56,   112,
     137,    27,    28,   117,   111,   109,   113,   146,    71,   159,
     164,   169,   174,   145,   111,   111,   170,   111,    68,    70,
     118,   119,    72,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   115,   175,    78,    79,    80,
     135,   111,    69,    69,   136,    18,   100,   133,   103,   134,
     144,    30,   162,   138,   167,   142,    22,    58,   150,   168,
     152,   160,   154,    30,   157,   176,   116,   140,     0,   151,
       0,    -4,     1,     0,    -4,    -4,    -4,    -4,    -4,     0,
     177,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      30,    -4,    -4,     0,     0,     0,   166,    -4,     0,    -4,
       0,    -4,     0,     0,    -4,     0,     0,     0,     0,    -4,
       0,     0,   172,    -4,    -4,     0,     0,     0,    30,     0,
       0,     0,    -4,    -4,     1,     0,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,     0,     0,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,
       0,    -4,     0,     0,     0,    -4,    -4,     0,     0,     5,
       6,     7,     8,     9,    -4,    -4,    10,    11,    12,    13,
      14,    15,    16,    17,     0,     0,    18,    19,     0,     0,
       0,     0,    20,     0,    21,     0,    22,   153,     0,    23,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
       0,     0,     5,     6,     7,     8,     9,    27,    28,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,    18,
      19,     0,     0,     0,     0,    20,     0,    21,     0,    22,
       0,     0,    23,     0,     0,     0,     0,    24,     0,     0,
       0,    25,    26,     5,     6,     7,     8,     0,     0,     0,
      27,    28,     0,     0,     0,    15,    16,    17,     0,     0,
       0,    19,     5,     6,     7,     8,    20,     0,    21,     0,
       0,     0,     0,    53,    15,    16,    17,     0,    24,     0,
      19,     0,    25,    26,     0,    20,     0,    21,     0,    58,
       0,    27,    28,     0,     0,     0,     0,    24,     0,     0,
       0,    25,    26,     5,     6,     7,     8,     0,     0,     0,
      27,    28,     0,     0,     0,    15,    16,    17,     0,     0,
      18,    19,     5,     6,     7,     8,    20,     0,    21,     0,
       0,     0,     0,     0,    15,    16,    17,     0,    24,     0,
      19,     0,    25,    26,     0,    20,     0,    21,     0,     0,
       0,    27,    28,    73,    74,     0,     0,    24,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,    75,     0,
      27,    28,    76,    77,    78,    79,    80,    73,    74,     0,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,    76,    77,    78,    79,
      80,    73,    74,     0,    81,    82,    83,    84,    85,    86,
       0,     0,   114,     0,     0,    73,    74,     0,     0,     0,
      76,    77,    78,    79,    80,     0,   147,     0,    81,    82,
      83,    84,    85,    86,    76,    77,    78,    79,    80,    73,
      74,     0,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,   149,    73,    74,     0,     0,    76,    77,
      78,    79,    80,   155,     0,     0,    81,    82,    83,    84,
      85,    86,     0,    76,    77,    78,    79,    80,    73,    74,
       0,    81,    82,    83,    84,    85,    86,   158,     0,     0,
       0,     0,    73,    74,     0,     0,     0,    76,    77,    78,
      79,    80,     0,   163,     0,    81,    82,    83,    84,    85,
      86,    76,    77,    78,    79,    80,    73,    74,     0,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,   173,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      73,    74,     0,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,     0,   178,    73,    74,     0,    76,
      77,    78,    79,    80,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    73,     0,    76,    77,    78,    79,    80,
       0,     0,     0,    81,    82,    83,    84,    85,    86,     0,
       0,     0,    76,    77,    78,    79,    80,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    76,    77,    78,    79,
      80,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      76,    77,    78,    79,    80,     0,     0,     0,    -5,    82,
      83,    84,    85,    -5
};

static const yytype_int16 yycheck[] =
{
       3,    42,    50,     3,   164,     0,    26,    21,    28,    28,
      26,    14,    28,    28,    17,    35,    36,   177,    21,    35,
      36,    24,    42,    43,    44,    29,    33,    34,    28,    26,
      34,    28,    37,    38,    39,    40,    41,    33,    35,    42,
      88,    46,    47,    48,    49,    33,    49,    27,     3,    27,
      98,    51,    52,    67,    34,    58,    34,   105,     3,    29,
      29,    29,    29,   104,    34,    34,    34,    34,    25,    26,
      73,    74,     3,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    29,    29,    39,    40,    41,
      93,    34,    25,    26,    97,    20,    28,     3,    28,     3,
     103,   104,   143,     3,   152,     8,    30,    30,   111,   157,
      28,     3,    29,   116,    28,     3,    65,   101,    -1,   113,
      -1,     0,     1,    -1,     3,     4,     5,     6,     7,    -1,
     171,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
     143,    20,    21,    -1,    -1,    -1,   149,    26,    -1,    28,
      -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,   165,    42,    43,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    51,    52,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,
      -1,    28,    -1,    30,    31,    -1,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    43,    -1,    -1,     3,
       4,     5,     6,     7,    51,    52,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    20,    21,    -1,    -1,
      -1,    -1,    26,    -1,    28,    -1,    30,    31,    -1,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    43,
      -1,    -1,     3,     4,     5,     6,     7,    51,    52,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    43,     3,     4,     5,     6,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    21,     3,     4,     5,     6,    26,    -1,    28,    -1,
      -1,    -1,    -1,    33,    15,    16,    17,    -1,    38,    -1,
      21,    -1,    42,    43,    -1,    26,    -1,    28,    -1,    30,
      -1,    51,    52,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    43,     3,     4,     5,     6,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      20,    21,     3,     4,     5,     6,    26,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    38,    -1,
      21,    -1,    42,    43,    -1,    26,    -1,    28,    -1,    -1,
      -1,    51,    52,    18,    19,    -1,    -1,    38,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      51,    52,    37,    38,    39,    40,    41,    18,    19,    -1,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    18,    19,    -1,    45,    46,    47,    48,    49,    50,
      -1,    -1,    29,    -1,    -1,    18,    19,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    -1,    29,    -1,    45,    46,
      47,    48,    49,    50,    37,    38,    39,    40,    41,    18,
      19,    -1,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    32,    18,    19,    -1,    -1,    37,    38,
      39,    40,    41,    27,    -1,    -1,    45,    46,    47,    48,
      49,    50,    -1,    37,    38,    39,    40,    41,    18,    19,
      -1,    45,    46,    47,    48,    49,    50,    27,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    -1,    29,    -1,    45,    46,    47,    48,    49,
      50,    37,    38,    39,    40,    41,    18,    19,    -1,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      18,    19,    -1,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    18,    19,    -1,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    18,    -1,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    55,    56,     0,     3,     4,     5,     6,     7,
      10,    11,    12,    13,    14,    15,    16,    17,    20,    21,
      26,    28,    30,    33,    38,    42,    43,    51,    52,    57,
      58,    59,    60,    61,    62,    63,    64,    69,    72,    75,
      79,    80,    82,    84,    85,    87,    90,    91,    92,    28,
      28,    33,    33,    33,    58,    58,     3,    74,    30,    58,
      68,    70,    71,    58,    79,    73,    58,    28,    62,    64,
      62,     3,     3,    18,    19,    33,    37,    38,    39,    40,
      41,    45,    46,    47,    48,    49,    50,    26,    28,    35,
      36,    42,    43,    44,    65,    66,    67,    26,    28,    35,
      28,    76,    57,    28,    86,    88,    58,    68,    33,    58,
      27,    34,    27,    34,    29,    29,    56,    79,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    68,     3,     3,    58,    58,    68,     3,    77,
      72,    78,     8,    83,    58,    57,    68,    29,    33,    32,
      58,    71,    28,    31,    29,    27,    29,    28,    27,    29,
       3,    81,    57,    29,    29,    89,    58,    68,    68,    29,
      34,    88,    58,    31,    29,    29,     3,    57,    33,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    66,    67,
      68,    68,    68,    69,    69,    70,    70,    71,    73,    72,
      74,    74,    75,    77,    76,    78,    79,    80,    80,    80,
      80,    80,    80,    81,    81,    81,    82,    83,    84,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     3,
       4,     3,     4,     4,     2,     6,     1,     1,     3,     5,
       1,     3,     0,     3,     3,     1,     3,     5,     0,     4,
       1,     0,     2,     0,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     4,     1,     2,     4,
       1,     3,     3,     0,     0,     7,     7,     2,     3
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
  case 2: /* program: statement  */
#line 127 "parser.y"
                                {   printf("---STARTING---\n");   }
#line 1684 "parser.c"
    break;

  case 3: /* statement: statement stmt  */
#line 130 "parser.y"
                                {   
                                    /* Enwnw tis 2 listes(statement, stmt) gia ta 2 xaraktiristika tous
                                        (breakList, contList) */
                                    (yyval.stmtValue)->breakList = mergelist((yyvsp[-1].stmtValue)->breakList, (yyvsp[0].stmtValue)->breakList); 
                                    (yyval.stmtValue)->contList =  mergelist((yyvsp[-1].stmtValue)->contList,(yyvsp[0].stmtValue)->contList);
                                }
#line 1695 "parser.c"
    break;

  case 4: /* statement: %empty  */
#line 136 "parser.y"
                                {   
                                    (yyval.stmtValue) = make_stmt((yyval.stmtValue)); /* Anagkastiki klisi tis make_stmt, alliws error */
                                }
#line 1703 "parser.c"
    break;

  case 5: /* statement: error  */
#line 139 "parser.y"
                                {}
#line 1709 "parser.c"
    break;

  case 6: /* stmt: expr ";"  */
#line 144 "parser.y"
                                    {       
                                        (yyval.stmtValue) = make_stmt((yyval.stmtValue));
                                    }
#line 1717 "parser.c"
    break;

  case 7: /* stmt: ifstmt  */
#line 147 "parser.y"
                                    {
                                        (yyval.stmtValue) = (yyvsp[0].stmtValue);
                                    }
#line 1725 "parser.c"
    break;

  case 8: /* stmt: whilestmt  */
#line 150 "parser.y"
                                    {
                                        (yyval.stmtValue) = (yyvsp[0].stmtValue);
                                    }
#line 1733 "parser.c"
    break;

  case 9: /* stmt: forstmt  */
#line 153 "parser.y"
                                    {
                                        (yyval.stmtValue) = (yyvsp[0].stmtValue);
                                    }
#line 1741 "parser.c"
    break;

  case 10: /* stmt: returnstmt  */
#line 156 "parser.y"
                                    {
                                        (yyval.stmtValue) = make_stmt((yyval.stmtValue));
                                    }
#line 1749 "parser.c"
    break;

  case 11: /* stmt: "break" ";"  */
#line 159 "parser.y"
                                    {   
                                        if(loopcounter == 0){
                                            fprintf(stderr,"You are not in loop\n");
                                            exit(1);
                                        }else{
                                            struct stmt_t *giatobreak = (stmt_t*)malloc(sizeof(stmt_t));
                                            (yyval.stmtValue) = make_stmt((yyval.stmtValue));
                                            giatobreak = (yyval.stmtValue);
                                            giatobreak->breakList = newlist(nextquadlabel());
                                            emit(jump, NULL, NULL, NULL, 0, yylineno);
                                        }
                                    }
#line 1766 "parser.c"
    break;

  case 12: /* stmt: "continue" ";"  */
#line 171 "parser.y"
                                    {   if(loopcounter == 0){
                                            fprintf(stderr,"You are not in loop\n");
                                            exit(1);
                                        }else{
                                            struct stmt_t *giatocont = (stmt_t*)malloc(sizeof(stmt_t));
                                            (yyval.stmtValue) = make_stmt((yyval.stmtValue));
                                            giatocont = (yyval.stmtValue);
                                            giatocont->contList = newlist(nextquadlabel());
                                            emit(jump, NULL, NULL, NULL, 0, yylineno);
                                        }
                                    }
#line 1782 "parser.c"
    break;

  case 13: /* stmt: block  */
#line 182 "parser.y"
                                    {
                                        (yyval.stmtValue)=(yyvsp[0].stmtValue);    
                                    }
#line 1790 "parser.c"
    break;

  case 14: /* stmt: funcdef  */
#line 185 "parser.y"
                                    {
                                        (yyval.stmtValue) = make_stmt((yyval.stmtValue));
                                    }
#line 1798 "parser.c"
    break;

  case 15: /* stmt: ";"  */
#line 188 "parser.y"
                                    { (yyval.stmtValue) = make_stmt((yyval.stmtValue));}
#line 1804 "parser.c"
    break;

  case 16: /* expr: assignexpr  */
#line 191 "parser.y"
                                        {       (yyval.exprValue) = (yyvsp[0].exprValue);
                                        }
#line 1811 "parser.c"
    break;

  case 17: /* expr: expr "+" expr  */
#line 193 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(arithexpr_e); /* vazei ton antistoixo typo expr_t se kathe expr */
                                                (yyval.exprValue)->sym = newtemp();        /* Dinei onoma se kryfi var+elegxei an yparxei to expr sto symtable */
                                                emit(add, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0, yylineno); /* Dimiourgei quad */
                                        }
#line 1822 "parser.c"
    break;

  case 18: /* expr: expr "-" expr  */
#line 199 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(arithexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(sub, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0, yylineno); 
                                        }
#line 1833 "parser.c"
    break;

  case 19: /* expr: expr "*" expr  */
#line 205 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(arithexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(mul_1, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0, yylineno);
                                        }
#line 1844 "parser.c"
    break;

  case 20: /* expr: expr "/" expr  */
#line 211 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(arithexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(div_1, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0, yylineno);
                                        }
#line 1855 "parser.c"
    break;

  case 21: /* expr: expr "%" expr  */
#line 217 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(arithexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(mod, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0, yylineno);
                                        }
#line 1866 "parser.c"
    break;

  case 22: /* expr: expr ">" expr  */
#line 223 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(boolexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(if_greater, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, (yyval.exprValue), 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, (yyval.exprValue), 0, yylineno);
                                        }
#line 1880 "parser.c"
    break;

  case 23: /* expr: expr ">=" expr  */
#line 232 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(boolexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(if_greatereq, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, (yyval.exprValue), 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, (yyval.exprValue), 0, yylineno);
                                        }
#line 1894 "parser.c"
    break;

  case 24: /* expr: expr "<" expr  */
#line 241 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(boolexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(if_less, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, (yyval.exprValue), 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, (yyval.exprValue), 0, yylineno);
                                        }
#line 1908 "parser.c"
    break;

  case 25: /* expr: expr "<=" expr  */
#line 250 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(boolexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(if_lesseq, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, (yyval.exprValue), 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, (yyval.exprValue), 0, yylineno);
                                        }
#line 1922 "parser.c"
    break;

  case 26: /* expr: expr "==" expr  */
#line 259 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(boolexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(if_eq, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, (yyval.exprValue), 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, (yyval.exprValue), 0, yylineno);
                                        }
#line 1936 "parser.c"
    break;

  case 27: /* expr: expr "!=" expr  */
#line 268 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(boolexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(if_noteq, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), NULL, nextquadlabel()+3, yylineno);
                                                emit(assign, newexpr_constbool(0), NULL, (yyval.exprValue), 0, yylineno);
                                                emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                emit(assign, newexpr_constbool(1), NULL, (yyval.exprValue), 0, yylineno);
                                        }
#line 1950 "parser.c"
    break;

  case 28: /* expr: expr "and" expr  */
#line 277 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(boolexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(and, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0, yylineno);
                                        }
#line 1961 "parser.c"
    break;

  case 29: /* expr: expr "or" expr  */
#line 283 "parser.y"
                                        {   
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol)); 
                                                (yyval.exprValue) = newexpr(boolexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(or, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0, yylineno);
                                        }
#line 1972 "parser.c"
    break;

  case 30: /* expr: term  */
#line 289 "parser.y"
                                        {       (yyval.exprValue)=(yyvsp[0].exprValue);
                                        }
#line 1979 "parser.c"
    break;

  case 31: /* term: "(" expr ")"  */
#line 293 "parser.y"
                                                    {
                                                (yyval.exprValue) = (yyvsp[-1].exprValue);
                                                    }
#line 1987 "parser.c"
    break;

  case 32: /* term: "-" expr  */
#line 296 "parser.y"
                                        {

                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol));
                                                check_arith((yyvsp[0].exprValue),"Illegal expr used in uminus"); /*thelei mallon prwta na tsekarei ti eidous type einai*/
                                                (yyval.exprValue) = newexpr(arithexpr_e);
                                                (yyval.exprValue)->sym = istempexpr((yyvsp[0].exprValue))?(yyvsp[0].exprValue)->sym:newtemp();
                                                emit(uminus, (yyvsp[0].exprValue), NULL, (yyval.exprValue), 0,yylineno);
                                        }
#line 2000 "parser.c"
    break;

  case 33: /* term: "not" expr  */
#line 304 "parser.y"
                                        {
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol));
                                                (yyval.exprValue) = newexpr(boolexpr_e);
                                                (yyval.exprValue)->sym = newtemp();
                                                emit(not, (yyvsp[0].exprValue), NULL, (yyval.exprValue), 0, yylineno); 
                                                // meriki apotimisi
                                                // emit(if_eq, $2, newexpr_constbool(1), NULL, nextquadlabel()+5, yylineno);
                                                // emit(jump, NULL, NULL, NULL,nextquadlabel()+2, yylineno);
                                                // emit(assign, newexpr_constbool(1), NULL, $$, 0, yylineno);
                                                // emit(jump, NULL, NULL, NULL,nextquadlabel()+3, yylineno);
                                                // emit(assign, newexpr_constbool(0), NULL, $$, 0, yylineno);
                                        }
#line 2017 "parser.c"
    break;

  case 34: /* term: "++" lvalue  */
#line 316 "parser.y"
                                        {
                                                check_arith((yyvsp[0].exprValue),"Illegal expr used in ++lvalue");
                                                struct symbol *lvalue =(symbol*)malloc(sizeof(symbol));
                                                if((yyvsp[0].exprValue)->type == tableitem_e){    /* an einai stoixeio pinaka */
                                                    (yyval.exprValue)= emit_iftableitem((yyvsp[0].exprValue));   /* tou allazw typo */
                                                    emit(add, (yyval.exprValue), newexpr_constnum(1), (yyval.exprValue), 0, yylineno);
                                                    emit(tablesetelem, (yyvsp[0].exprValue), (yyvsp[0].exprValue)->index, (yyval.exprValue), 0, yylineno);
                                                }else{
                                                    emit(add, (yyvsp[0].exprValue), newexpr_constnum(1), (yyvsp[0].exprValue), 0, yylineno);
                                                    (yyval.exprValue) = newexpr(arithexpr_e); /* Xrisi neas krifis metavlitis, logw assignment */
                                                    (yyval.exprValue)->sym = newtemp();
                                                    emit(assign, (yyvsp[0].exprValue), NULL, (yyval.exprValue), 0, yylineno);
                                                }
                                        }
#line 2036 "parser.c"
    break;

  case 35: /* term: lvalue "++"  */
#line 330 "parser.y"
                                         {
                                                /*d10 slide33*/
                                                struct symbol *lvalue =(symbol*)malloc(sizeof(symbol));
                                                check_arith((yyvsp[-1].exprValue),"Illegal expr used in lvalue++");
                                                (yyval.exprValue) = newexpr(var_e);
                                                (yyval.exprValue)->sym=newtemp();
                                                if((yyvsp[-1].exprValue)->type == tableitem_e){
                                                    expr* val = emit_iftableitem((yyvsp[-1].exprValue));
                                                    emit(assign, val, NULL, (yyval.exprValue), 0, yylineno);
                                                    emit(add, val, newexpr_constnum(1), val, 0, yylineno);
                                                    emit(tablesetelem, (yyvsp[-1].exprValue), (yyvsp[-1].exprValue)->index, val, 0, yylineno);
                                                }else{
                                                    emit(assign, (yyvsp[-1].exprValue), NULL, (yyval.exprValue), 0, yylineno);
                                                    emit(add, (yyvsp[-1].exprValue), newexpr_constnum(1), (yyvsp[-1].exprValue), 0, yylineno);
                                                }
                                        }
#line 2057 "parser.c"
    break;

  case 36: /* term: "--" lvalue  */
#line 346 "parser.y"
                                        {       check_arith((yyvsp[0].exprValue),"Illegal expr used in --lvalue");
                                                struct symbol *lvalue =(symbol*)malloc(sizeof(symbol));
                                                if((yyvsp[0].exprValue)->type==tableitem_e){
                                                    (yyval.exprValue)= emit_iftableitem((yyvsp[0].exprValue));
                                                    emit(sub, (yyval.exprValue), newexpr_constnum(1), (yyval.exprValue), 0, yylineno);
                                                    emit(tablesetelem, (yyvsp[0].exprValue), (yyvsp[0].exprValue)->index, (yyval.exprValue), 0, yylineno);
                                                }else{
                                                    emit(sub, (yyvsp[0].exprValue), newexpr_constnum(1), (yyvsp[0].exprValue), 0, yylineno);
                                                    (yyval.exprValue) = newexpr(arithexpr_e);
                                                    (yyval.exprValue)->sym = newtemp();
                                                    emit(assign, (yyvsp[0].exprValue), NULL, (yyval.exprValue), 0, yylineno);
                                                }
                                        }
#line 2075 "parser.c"
    break;

  case 37: /* term: lvalue "--"  */
#line 359 "parser.y"
                                        {
                                                struct symbol *lvalue =(symbol*)malloc(sizeof(symbol));
                                                check_arith((yyvsp[-1].exprValue),"Illegal expr used in lvalue--");
                                                (yyval.exprValue) = newexpr(var_e);
                                                (yyval.exprValue)->sym=newtemp();
                                                if((yyvsp[-1].exprValue)->type==tableitem_e){
                                                    expr* val = emit_iftableitem((yyvsp[-1].exprValue));
                                                    emit(assign, val, NULL, (yyval.exprValue), 0, yylineno);
                                                    emit(sub, val, newexpr_constnum(1), val, 0, yylineno);
                                                    emit(tablesetelem, (yyvsp[-1].exprValue), (yyvsp[-1].exprValue)->index, val, 0, yylineno);
                                                }
                                                else{
                                                    emit(assign, (yyvsp[-1].exprValue), NULL, (yyval.exprValue), 0, yylineno);
                                                    emit(sub, (yyvsp[-1].exprValue), newexpr_constnum(1), (yyvsp[-1].exprValue), 0, yylineno);
                                                }
                                        }
#line 2096 "parser.c"
    break;

  case 38: /* term: primary  */
#line 375 "parser.y"
                                        {
                                                (yyval.exprValue) = (yyvsp[0].exprValue);
                                        }
#line 2104 "parser.c"
    break;

  case 39: /* assignexpr: lvalue "=" expr  */
#line 380 "parser.y"
                                        {       
                                                if((yyvsp[-2].exprValue)->type == tableitem_e){
                                                    emit(tablesetelem, (yyvsp[-2].exprValue), (yyvsp[-2].exprValue)->index, (yyvsp[0].exprValue), 0, yylineno);
                                                    (yyval.exprValue)=emit_iftableitem((yyvsp[-2].exprValue));
                                                    (yyval.exprValue)->type=assignexpr_e;
                                                }else{
                                                    emit(assign, (yyvsp[0].exprValue), NULL, (yyvsp[-2].exprValue), 0, yylineno);
                                                    (yyval.exprValue) = newexpr(assignexpr_e);
                                                    (yyval.exprValue)->sym = newtemp();
                                                    emit(assign, (yyvsp[-2].exprValue), NULL, (yyval.exprValue), 0, yylineno);
                                                }
                                        }
#line 2121 "parser.c"
    break;

  case 40: /* primary: lvalue  */
#line 394 "parser.y"
                                        {
                                                (yyval.exprValue) = emit_iftableitem((yyvsp[0].exprValue));
                                        }
#line 2129 "parser.c"
    break;

  case 41: /* primary: call  */
#line 397 "parser.y"
                                        {       /* Kalw olokliro ton termatiko kanona kai ektelw oti kanei */
                                                (yyval.exprValue) = (yyvsp[0].exprValue);
                                        }
#line 2137 "parser.c"
    break;

  case 42: /* primary: objectdef  */
#line 400 "parser.y"
                                        {
                                                (yyval.exprValue) = (yyvsp[0].exprValue);
                                        }
#line 2145 "parser.c"
    break;

  case 43: /* primary: "(" funcdef ")"  */
#line 404 "parser.y"
                                        {
                                                /*dialexi 10 slide 31*/
                                                struct symbol *sym = (symbol*)malloc(sizeof(symbol));
                                                (yyval.exprValue) = newexpr(programfunc_e);
                                                (yyval.exprValue)->sym = (yyvsp[-1].symValue);

                                        }
#line 2157 "parser.c"
    break;

  case 44: /* primary: const  */
#line 411 "parser.y"
                                        {       (yyval.exprValue)=(yyvsp[0].exprValue);
                                        }
#line 2164 "parser.c"
    break;

  case 45: /* lvalue: "id"  */
#line 416 "parser.y"
                                    {   struct symbol *symtab = (symbol*)malloc(sizeof(symbol)); /*new*/
                                        int i;
                                        for(i=scope; i>=0; i--){
                                            symtab = lookup((yyvsp[0].stringValue),i); /* Anti gia counter, pairnei tin lookup kai tin elegxei */
                                            if(symtab != NULL){
                                                break;
                                            }
                                        }
                                        if(symtab == NULL){
                                            if(scope == 0){
                                                symtab=insert_symtab((yyvsp[0].stringValue), GLOBAL, scope, yylineno);
                                                symtab->space = currscopespace(); 
                                                symtab->offset = currscopeoffset(); 
                                                inccurrscopeoffset();
                                            }else{
                                                symtab=insert_symtab((yyvsp[0].stringValue), LOCAAL, scope, yylineno);
                                                symtab->space = currscopespace(); 
                                                symtab->offset = currscopeoffset(); 
                                                inccurrscopeoffset();
                                            }
                                        }
                                        (yyval.exprValue)=lvalue_expr(symtab);
                                    }
#line 2192 "parser.c"
    break;

  case 46: /* lvalue: LOCAL "id"  */
#line 439 "parser.y"
                                   {    struct symbol *symtab = (symbol*)malloc(sizeof(symbol)); /*new*/
                                        void* kati;
                                        if(scope!=0 && lookup_libfunc((yyvsp[0].stringValue), scope)){
                                            fprintf(stderr, "INPUT is lib func NOT VALID\n");
                                            exit(1);
                                        }
                                        kati = lookup((yyvsp[0].stringValue), scope);
                                        if(kati == NULL){ // ==NULL -->Diladi den to exei vrei (alliws tha to eixe epistrepsei)
                                            if(scope !=0){
                                                symtab=insert_symtab((yyvsp[0].stringValue), LOCAAL, scope, yylineno);
                                            }else{
                                                symtab=insert_symtab((yyvsp[0].stringValue), GLOBAL, scope, yylineno);
                                                symtab->space = currscopespace();
                                                symtab->offset = currscopeoffset(); 
                                                inccurrscopeoffset(); 
                                            }
                                        }else if(lookup_libfunc((yyvsp[0].stringValue), 0)==0){
                                            fprintf(stderr, "Local variable redefined in scope %d\n",scope);
                                            exit(1);
                                        }else{
                                            symtab=kati;
                                        }
                                        (yyval.exprValue)=lvalue_expr(symtab);
                                    }
#line 2221 "parser.c"
    break;

  case 47: /* lvalue: "::" "id"  */
#line 463 "parser.y"
                                    {   struct symbol *symtab = (symbol*)malloc(sizeof(symbol)); 
                                        void* kati = lookup((yyvsp[0].stringValue), 0);
                                        if(kati == NULL ){
                                            fprintf(stderr, "Didn't find in scope 0\n");
                                            exit(1);
                                        }else{
                                            symtab=kati;
                                            (yyval.exprValue)=lvalue_expr(symtab);
                                        }
                                    }
#line 2236 "parser.c"
    break;

  case 48: /* lvalue: member  */
#line 473 "parser.y"
                                    {   (yyval.exprValue)=(yyvsp[0].exprValue);
                                    }
#line 2243 "parser.c"
    break;

  case 49: /* member: lvalue "." "id"  */
#line 477 "parser.y"
                                                    {   
                                                        (yyval.exprValue) = member_item((yyvsp[-2].exprValue), (yyvsp[0].stringValue));
                                                   }
#line 2251 "parser.c"
    break;

  case 50: /* member: lvalue "[" expr "]"  */
#line 480 "parser.y"
                                                    {
                                                        (yyvsp[-3].exprValue) = emit_iftableitem((yyvsp[-3].exprValue));  /* vazei to expression */
                                                        (yyval.exprValue) = newexpr(tableitem_e);  /* vazei typo scopeoffset */
                                                        (yyval.exprValue)->sym = (yyvsp[-3].exprValue)->sym;
                                                        (yyval.exprValue)->index = (yyvsp[-1].exprValue);
                                                    }
#line 2262 "parser.c"
    break;

  case 51: /* member: call "." "id"  */
#line 486 "parser.y"
                                                    {   /*epeidi einai paromoios grammatikos kanonas
                                                        me to lvalue evala kai sto call to idio motivo*/
                                                        (yyval.exprValue) = member_item((yyvsp[-2].exprValue), (yyvsp[0].stringValue));
                                                    }
#line 2271 "parser.c"
    break;

  case 52: /* member: call "[" expr "]"  */
#line 490 "parser.y"
                                                    {
                                                        (yyvsp[-3].exprValue)= emit_iftableitem((yyvsp[-3].exprValue));
                                                        (yyval.exprValue) = newexpr(tableitem_e);
                                                        (yyval.exprValue)->sym = (yyvsp[-3].exprValue)->sym;
                                                        (yyval.exprValue)->index = (yyvsp[-1].exprValue);
                                                    }
#line 2282 "parser.c"
    break;

  case 53: /* call: call "(" elist ")"  */
#line 498 "parser.y"
                                                        {
/* H ektypwsi twn orismatwn ginetai apo to telos->arxi p.x. f(a,b,c), ta quads ektypwnontai ws c meta b meta a.
Episis an exw nested func arg p.x. f(a, g(x,y,z), b,c) ta quads ektypwnontai ws z,y,x,(pou aforoun to elist)
(krataei (olo) to "g" se mia temp p.x.t_0) kai telos c, b, a. Ara--> c, b, t_0, a */
/* Anagkastika loipon i lista se auto to grammar rule einai local */    
                                                            (yyval.exprValue) = make_call((yyvsp[-3].exprValue), (yyvsp[-1].listValue)); /* eksaitias twn parapanw to arg to onomazei reversed_list */
                                                        }
#line 2294 "parser.c"
    break;

  case 54: /* call: lvalue callsuffix  */
#line 505 "parser.y"
                                                        {
                                                            (yyvsp[-1].exprValue) = emit_iftableitem((yyvsp[-1].exprValue));
                                                            if((yyvsp[0].callValue)->method){
                                                                struct expr* t = (yyvsp[-1].exprValue);
                                                                (yyvsp[-1].exprValue) = emit_iftableitem(member_item(t,(yyvsp[0].callValue)->name));
                                                                /* Pairnw mnimi, epeidi kanw eisagwgi ..Kanw neo komvo gia na mpei 1os */
                                                                struct list_t* newNode = (list_t*)malloc(sizeof(list_t)); 
                                                                
                                                                newNode->arg = t; 
                                                                newNode->previous = NULL;
                                                                newNode->next= (yyvsp[0].callValue)->elist; /* vazw sto next ton twrino 1o komvo */
/* Eisagw ena neo stoixeio stin ARXI tis listas. Efoson to elist deixnei stin arxi tis listas, 
vazw to elist stin 2i thesi kai to neo stoixeio stin 1i thesi */
                                                                if((yyvsp[0].callValue)->elist!=NULL){
                                                                    (yyvsp[0].callValue)->elist->previous=newNode; /* vazw stin prev thesi tis idi yparxousa lista ton newNode */
                                                                }
                                                                (yyvsp[0].callValue)->elist=newNode; /* 1os komvos ginetai o newNode */

                                                            }
                                                            (yyval.exprValue) = make_call((yyvsp[-1].exprValue),(yyvsp[0].callValue)->elist);
                                                        }
#line 2320 "parser.c"
    break;

  case 55: /* call: "(" funcdef ")" "(" elist ")"  */
#line 527 "parser.y"
                                                        {
                                                            struct expr* func = newexpr(programfunc_e);
                                                            func->sym=(yyvsp[-4].symValue);
                                                            (yyval.exprValue)=make_call(func, (yyvsp[-1].listValue)); 
                                                        }
#line 2330 "parser.c"
    break;

  case 56: /* callsuffix: normcall  */
#line 534 "parser.y"
                            {   (yyval.callValue)=(yyvsp[0].callValue);  }
#line 2336 "parser.c"
    break;

  case 57: /* callsuffix: methodcall  */
#line 535 "parser.y"
                            {   (yyval.callValue)=(yyvsp[0].callValue);  }
#line 2342 "parser.c"
    break;

  case 58: /* normcall: "(" elist ")"  */
#line 538 "parser.y"
                                                        {   
                                                            struct call_l* newnormal = (call_l*)malloc(sizeof(call_l));
                                                            (yyval.callValue) = newnormal;
                                                            (yyval.callValue)->elist = (yyvsp[-1].listValue);
                                                            (yyval.callValue)->method = 0;
                                                            (yyval.callValue)->name = NULL;
                                                        }
#line 2354 "parser.c"
    break;

  case 59: /* methodcall: ".." "id" "(" elist ")"  */
#line 547 "parser.y"
                                                                    {   /* Desmeuw mnimi, wste na mporei na kanei tin ektypwsi  */
                                                                        struct call_l* newmethod = (call_l*)malloc(sizeof(call_l));
                                                                        (yyval.callValue) = newmethod; /* Pairnei to $$ tin mnimi */

                                                                        (yyval.callValue)->elist = (yyvsp[-1].listValue);
                                                                        (yyval.callValue)->method = 1;
                                                                        (yyval.callValue)->name = strdup((yyvsp[-3].stringValue)); /* epistrefei pointer se auto pou kanei duplicate */
                                                                    }
#line 2367 "parser.c"
    break;

  case 60: /* elist: expr  */
#line 558 "parser.y"
                                                {
                                                    /* Dimiourgw lista gia ta stoixeia tou pinaka.
                                                       Antistoixia value me theseis pinaka */
                                                    struct list_t* mylist = (list_t*)malloc(sizeof(list_t));
                                                    mylist->previous = NULL;
                                                    mylist->next = NULL;
                                                    mylist->arg =(yyvsp[0].exprValue);
                                                    (yyval.listValue) = mylist;

                                                }
#line 2382 "parser.c"
    break;

  case 61: /* elist: elist "," expr  */
#line 568 "parser.y"
                                                {
                                                    struct list_t* mylist = (list_t*)malloc(sizeof(list_t));
                                                    struct list_t* node = (list_t*)malloc(sizeof(list_t)); 
                                                    /*Dimiourgw nea lista pou tha apothikeuei ola ta stoixeia. Autin tha diatreksw */
                                                    node = (yyval.listValue);

                                                    while(node->next!=NULL){
                                                        node=node->next;    /* Kanw next gia na paw ston last node,wste na kanw ekei tin eisagwgi */          
                                                    }
                                                    //node = last komvos tou node(list_t node);
                                                    //node->next=NULL
                                                    //mylist = newnode;
                                                    mylist->previous = node;
                                                    mylist->next = NULL;
                                                    mylist->arg = (yyvsp[0].exprValue);
                                                    node->next = mylist;
                                                    /* To $$ to pira idi apo to expr(apo panw). Prosthesa to $3 se nea thesi tou node
                                                        Ara twra den xreiazetai na kanw $$ = $3 */
                                                }
#line 2406 "parser.c"
    break;

  case 62: /* elist: %empty  */
#line 587 "parser.y"
                                                {
                                                    (yyval.listValue)=NULL;
                                                }
#line 2414 "parser.c"
    break;

  case 63: /* objectdef: "[" elist "]"  */
#line 592 "parser.y"
                                                    {   
/* Edw ginetai dimiourgia pinaka p.x. x=[4,5,14,6], diladi
thesi 0 exei to 4, thesi 1->5 k.o.k.
tablegetelem 8 t_2 1, diavazetai ws: to 8 mpainei stin 1i thesi tou t_2*/
                                                        int i;
                                                        struct expr* t = newexpr(newtable_e);
                                                        t->sym = newtemp();
                                                        emit(tablecreate, t, NULL, NULL, 0, yylineno);
                                                        for(i=0; (yyvsp[-1].listValue); (yyvsp[-1].listValue) = (yyvsp[-1].listValue)->next){
                                                            emit(tablesetelem, t, newexpr_constnum(i++), (yyvsp[-1].listValue)->arg, 0, yylineno);
                                                        }
                                                        (yyval.exprValue) = t;
                                                    }
#line 2432 "parser.c"
    break;

  case 64: /* objectdef: "[" indexed "]"  */
#line 605 "parser.y"
                                                    {   int i;
                                                        struct expr* t = newexpr(newtable_e);
                                                        t->sym = newtemp();
                                                        emit(tablecreate, t, NULL, NULL, 0, yylineno);
                                                        for(i=0; (yyvsp[-1].listValue); (yyvsp[-1].listValue) = (yyvsp[-1].listValue)->next){
                                                            emit(tablesetelem, t, (yyvsp[-1].listValue)->arg, (yyvsp[-1].listValue)->value, 0, yylineno);
                                                        }
                                                        (yyval.exprValue) = t;}
#line 2445 "parser.c"
    break;

  case 65: /* indexed: indexedelem  */
#line 615 "parser.y"
                                                    {   (yyval.listValue) = (yyvsp[0].listValue);    }
#line 2451 "parser.c"
    break;

  case 66: /* indexed: indexed "," indexedelem  */
#line 616 "parser.y"
                                                    {
                                                    /* Afora tin periptwsi pou exw polla key-values se ena pinaka */
                                                    /* Dictionary creation: Kathe value exei to diko tou key --> x = [{"x":0},{"y":1}], 0=value, "x"=key */
                                                    struct list_t* mylist = (list_t*)malloc(sizeof(list_t));
                                                    struct list_t* node = (list_t*)malloc(sizeof(list_t));
                                                    node = (yyval.listValue);

                                                    while(node->next!=NULL){
                                                        node=node->next;                   
                                                    }
                                                    //  Skeptiko:
                                                    //  node = last;
                                                    //  node->next=NULL
                                                    //  mylist = newnode;
                                                    mylist->previous = node;
                                                    mylist->next = NULL;
                                                    mylist->arg = (yyvsp[0].listValue)->arg;      /* key */
                                                    mylist->value = (yyvsp[0].listValue)->value;  /* value */
                                                    node->next = mylist;
                                                    }
#line 2476 "parser.c"
    break;

  case 67: /* indexedelem: "{" expr ":" expr "}"  */
#line 639 "parser.y"
                                                    {   /* Afora ton pinaka me ena key-value */
                                                        struct list_t* mylist = (list_t*)malloc(sizeof(list_t));
                                                        mylist->previous = NULL;
                                                        mylist->next = NULL;
                                                        mylist->arg =(yyvsp[-3].exprValue);
                                                        mylist->value= (yyvsp[-1].exprValue);
                                                        (yyval.listValue) = mylist;
                                                    }
#line 2489 "parser.c"
    break;

  case 68: /* $@1: %empty  */
#line 650 "parser.y"
                       {++scope;}
#line 2495 "parser.c"
    break;

  case 69: /* block: "{" $@1 statement "}"  */
#line 651 "parser.y"
                                                    {   
/* Prokeimenou na metaferw ta break/continue pou yparxoun idi se ena block(
    diladi ta break/cont you statement(ta opoia exoun ginei merged)) se kapoion allo kanona pou kalei to block.
    Diaforetika ta xanw, kai den kserw pou na kanw jump */                                                      
                                                        hide(scope--); 
                                                        (yyval.stmtValue) = make_stmt((yyval.stmtValue));     /* Midenizei ola ta break/cont pou yparxoun  */
                                                        (yyval.stmtValue)->contList = (yyvsp[-1].stmtValue)->contList;
                                                        (yyval.stmtValue)->breakList = (yyvsp[-1].stmtValue)->breakList;
                                                    }
#line 2509 "parser.c"
    break;

  case 70: /* funcname: "id"  */
#line 663 "parser.y"
                {   
                    (yyval.stringValue) = (yyvsp[0].stringValue); 
                }
#line 2517 "parser.c"
    break;

  case 71: /* funcname: %empty  */
#line 666 "parser.y"
                {   char* onoma = malloc(10);
                
                    (yyval.stringValue) = newFunName(onoma, metritis);
                    metritis++;
                }
#line 2527 "parser.c"
    break;

  case 72: /* funcprefix: "function" funcname  */
#line 673 "parser.y"
                                {   
                                    
                                    void* kati = lookup((yyvsp[0].stringValue), scope);

                                    if(lookup_libfunc((yyvsp[0].stringValue), scope)){
                                    fprintf(stderr, "INPUT is lib func NOT VALID\n");
                                        exit(1);
                                    }else if( kati != NULL ){
                                        fprintf(stderr, "Function redefined ERROR\n");
                                        exit(1);
                                    }else {
                                        (yyval.symValue) = insert_symtab((yyvsp[0].stringValue), USERFUNC, scope, yylineno);
                                    }

                                    (yyval.symValue)->iaddress = nextquadlabel(); /* iaddress idio typo me nextquadlabel()*/
                                    expr* f = (expr*)malloc(sizeof(expr));
                                    f->type = programfunc_e;        /* tou vazw ton typo gia func */
                                    f->sym = (yyval.symValue);                    /* sto symbol vazw ton grammar rule */
                                    emit(funcstart, f, NULL, NULL, 0, yylineno);
                                    /* kanw push to offset stin sto stack */
                                    push(&scopeoffsetstack, currscopeoffset()); /* "&": epeidi theloume tin dieuthinsi */
                                    enterscopespace();
                                    resetformalargsoffset();
                                }
#line 2556 "parser.c"
    break;

  case 73: /* $@2: %empty  */
#line 699 "parser.y"
                            {scope++;}
#line 2562 "parser.c"
    break;

  case 74: /* funcargs: "(" $@2 idlist ")"  */
#line 700 "parser.y"
                                {
                                    scope--;
                                    infunctioncounter++;
                                    enterscopespace();
                                    resetfunctionlocaloffset();
                                    /* kanw push ton loopcounter sto stack */
                                    push(&loopcounterstack, loopcounter);   /* "&": epeidi theloume tin dieuthinsi */
                                    loopcounter=0;
                                }
#line 2576 "parser.c"
    break;

  case 75: /* funcbody: block  */
#line 711 "parser.y"
                                {
                                    (yyval.intValue) = currscopeoffset();
                                    existscopespace();
                                    infunctioncounter--;
                                    loopcounter = pop(&loopcounterstack);   /* "&": epeidi theloume tin dieuthinsi */
                                }
#line 2587 "parser.c"
    break;

  case 76: /* funcdef: funcprefix funcargs funcbody  */
#line 719 "parser.y"
                                {
                                    existscopespace();
                                    (yyvsp[-2].symValue)->totalLocals = (yyvsp[0].intValue); /* totalLocals idio typo me funcbody */
                                    int offset = pop(&scopeoffsetstack);
                                    restorecurrscopeoffset(offset);
                                    (yyval.symValue) = (yyvsp[-2].symValue);
                                    /* Dimiourgw tin stoiva gia na apothikeyei to scopeoffset */
                                    expr* ff = (expr*)malloc(sizeof(expr));
                                    ff->type = programfunc_e;
                                    ff->sym = (yyval.symValue);
                                    emit(funcend, ff, NULL, NULL, 0, yylineno);
                                }
#line 2604 "parser.c"
    break;

  case 77: /* const: "int"  */
#line 733 "parser.y"
                        {   (yyval.exprValue) = newexpr_constnum((double)(yyvsp[0].intValue)); 
                        }
#line 2611 "parser.c"
    break;

  case 78: /* const: "double"  */
#line 735 "parser.y"
                        {   (yyval.exprValue) = newexpr_constnum((yyvsp[0].doubValue)); 
                        }
#line 2618 "parser.c"
    break;

  case 79: /* const: "string"  */
#line 737 "parser.y"
                        {   (yyval.exprValue) = newexpr_conststring((yyvsp[0].stringValue));
                        }
#line 2625 "parser.c"
    break;

  case 80: /* const: "nil"  */
#line 739 "parser.y"
                        {   /* Dimiourgia neou expr xwris symvola, me typo nil_e */
                            expr* nothing = (expr*)malloc(sizeof(expr));
                            nothing->type = nil_e;
                            (yyval.exprValue) = nothing;
                        }
#line 2635 "parser.c"
    break;

  case 81: /* const: "true"  */
#line 744 "parser.y"
                        {   (yyval.exprValue) = newexpr_constbool((unsigned int)1);
                        }
#line 2642 "parser.c"
    break;

  case 82: /* const: "false"  */
#line 746 "parser.y"
                        {   (yyval.exprValue) = newexpr_constbool((unsigned int)0);
                        }
#line 2649 "parser.c"
    break;

  case 83: /* idlist: "id"  */
#line 753 "parser.y"
                                {   void* kati = lookup((yyvsp[0].stringValue), scope);
                                    
                                    if(lookup_libfunc((yyvsp[0].stringValue), scope)){
                                        fprintf(stderr, "ERROR: arg is lib func NOT VALID\n");
                                        exit(1);
                                    }else if(kati != NULL){
                                        fprintf(stderr, "ERROR: formal arg redifined \n");
                                        exit(1);
                                    }else{
                                        //insert_symtab($1, FORMAL, scope, yylineno);


                                        symbol* symtab=insert_symtab((yyvsp[0].stringValue), FORMAL, scope, yylineno);
                                        symtab->space = currscopespace(); 
                                        symtab->offset = currscopeoffset(); 
                                        inccurrscopeoffset();
                                    }
                                }
#line 2672 "parser.c"
    break;

  case 84: /* idlist: idlist "," "id"  */
#line 771 "parser.y"
                                {   void* kati = lookup((yyvsp[0].stringValue), scope);
                                    
                                    if(lookup_libfunc((yyvsp[0].stringValue), scope)){
                                        fprintf(stderr, "arg is lib func NOT VALID\n");
                                        exit(1);
                                    }else if(kati != NULL){
                                        fprintf(stderr, "formal arg redifined ERROR\n");
                                        exit(1);
                                    }else{
                                        //insert_symtab($3, FORMAL, scope, yylineno);
                                        symbol* symtab=insert_symtab((yyvsp[0].stringValue), FORMAL, scope, yylineno);
                                        symtab->space = currscopespace(); 
                                        symtab->offset = currscopeoffset(); 
                                        inccurrscopeoffset();
                                    } 
                                }
#line 2693 "parser.c"
    break;

  case 85: /* idlist: %empty  */
#line 787 "parser.y"
              {}
#line 2699 "parser.c"
    break;

  case 86: /* ifprefix: "if" "(" expr ")"  */
#line 790 "parser.y"
                                                    {   
                                                        emit(if_eq, (yyvsp[-1].exprValue), newexpr_constbool(1), NULL, nextquadlabel()+2, yylineno);
                                                        (yyval.intValue) = nextquadlabel();    
                                                        emit(jump, NULL, NULL, NULL, 0, yylineno);
                                                    }
#line 2709 "parser.c"
    break;

  case 87: /* elseprefix: "else"  */
#line 797 "parser.y"
                                                    {
                                                        (yyval.intValue) = nextquadlabel();    
                                                        emit(jump, NULL, NULL, NULL, 0, yylineno);
                                                    }
#line 2718 "parser.c"
    break;

  case 88: /* ifstmt: ifprefix stmt  */
#line 803 "parser.y"
                                                    {   
/* An exw ena stmt, arkei na krataw tis breakList/contList pou emfanizontai ekei */
                                                        (yyval.stmtValue) = make_stmt((yyval.stmtValue));
                                                        (yyval.stmtValue)->contList = (yyvsp[0].stmtValue)->contList;
                                                        (yyval.stmtValue)->breakList = (yyvsp[0].stmtValue)->breakList;
                                                        patchlabel((yyvsp[-1].intValue), nextquadlabel());
                                                    }
#line 2730 "parser.c"
    break;

  case 89: /* ifstmt: ifprefix stmt elseprefix stmt  */
#line 810 "parser.y"
                                                    {
                                                        (yyval.stmtValue) = make_stmt((yyval.stmtValue));
/* An exw polla stmt, prepei na apothikeuw ola ta breakList/contList(ta idi yparxwn me ekeina kathe neou stmt) 
--> meta ta kanw merge ola metaksu tous, gia na ta parei o grammar rule */
                                                        struct stmt_t *prwtoStmt =(stmt_t*)malloc(sizeof(stmt_t));
                                                        struct stmt_t *deuteroStmt =(stmt_t*)malloc(sizeof(stmt_t));
                                                        prwtoStmt->contList = (yyvsp[-2].stmtValue)->contList;
                                                        prwtoStmt->breakList = (yyvsp[-2].stmtValue)->breakList;
                                                        
                                                        deuteroStmt->contList = (yyvsp[0].stmtValue)->contList;
                                                        deuteroStmt->breakList = (yyvsp[0].stmtValue)->breakList;
                                                        (yyval.stmtValue)->breakList = mergelist(prwtoStmt->breakList, deuteroStmt->breakList);
                                                        (yyval.stmtValue)->contList =  mergelist(prwtoStmt->contList,deuteroStmt->contList);

                                                        patchlabel((yyvsp[-3].intValue), (yyvsp[-1].intValue)+1);
                                                        patchlabel((yyvsp[-1].intValue), nextquadlabel());
                                                    }
#line 2752 "parser.c"
    break;

  case 90: /* whilestart: "while"  */
#line 829 "parser.y"
                                                    {  
                                                        (yyval.intValue) = nextquadlabel();  
                                                    }
#line 2760 "parser.c"
    break;

  case 91: /* whilecond: "(" expr ")"  */
#line 833 "parser.y"
                                                    {
                                                        emit(if_eq, (yyvsp[-1].exprValue), newexpr_constbool(1), NULL, nextquadlabel()+2, yylineno);
                                                        (yyval.intValue) = nextquadlabel();
                                                        emit(jump, NULL, NULL, NULL, 0, yylineno);
                                                        ++loopcounter;
                                                    }
#line 2771 "parser.c"
    break;

  case 92: /* whilestmt: whilestart whilecond stmt  */
#line 840 "parser.y"
                                                    {   
                                                        (yyval.stmtValue) = make_stmt((yyval.stmtValue));
                                                        emit(jump, NULL, NULL, NULL, (yyvsp[-2].intValue), yylineno);
                                                        patchlabel((yyvsp[-1].intValue), nextquadlabel());
                                                        patchlist((yyvsp[0].stmtValue)->breakList, nextquadlabel());
                                                        patchlist((yyvsp[0].stmtValue)->contList, (yyvsp[-2].intValue));
                                                        --loopcounter;
                                                    }
#line 2784 "parser.c"
    break;

  case 93: /* N: %empty  */
#line 850 "parser.y"
            {   
                (yyval.intValue) = nextquadlabel();  
                emit(jump, NULL, NULL, NULL, 0, yylineno);
            }
#line 2793 "parser.c"
    break;

  case 94: /* M: %empty  */
#line 855 "parser.y"
            {   
                (yyval.intValue) = nextquadlabel();   
            }
#line 2801 "parser.c"
    break;

  case 95: /* forprefix: "for" "(" elist ";" M expr ";"  */
#line 859 "parser.y"
                                                                    { 
                                                                        ++loopcounter;
                                                                        /* Desmeusi xwrou logw eisagwgis */
                                                                        struct for_t* newFor = (for_t*)malloc(sizeof(for_t));
                                                                        newFor->test = (yyvsp[-2].intValue);
                                                                        newFor->enter = nextquadlabel();
                                                                        emit(if_eq, (yyvsp[-1].exprValue), newexpr_constbool(1), NULL, 0, yylineno);
                                                                        (yyval.forValue)=newFor;  }
#line 2814 "parser.c"
    break;

  case 96: /* forstmt: forprefix N elist ")" N stmt N  */
#line 868 "parser.y"
                                                                    {   
                                                                        (yyval.stmtValue) = make_stmt((yyval.stmtValue));
                                                                        patchlabel((yyvsp[-6].forValue)->enter, (yyvsp[-2].intValue) +1);
                                                                        patchlabel((yyvsp[-5].intValue), nextquadlabel());
                                                                        patchlabel((yyvsp[-2].intValue), (yyvsp[-6].forValue)->test);
                                                                        patchlabel((yyvsp[0].intValue), (yyvsp[-5].intValue) +1);
                                                                        patchlist((yyvsp[-1].stmtValue)->breakList, nextquadlabel());
                                                                        patchlist((yyvsp[-1].stmtValue)->contList, (yyvsp[-5].intValue)+1);
                                                                        --loopcounter;
                                                                    }
#line 2829 "parser.c"
    break;

  case 97: /* returnstmt: "return" ";"  */
#line 880 "parser.y"
                                    {
                                        if(infunctioncounter > 0){
                                            emit(ret, NULL, NULL, NULL, 0, yylineno);   
                                        }else{
                                            printf("You are not inside a function\n");
                                            exit(1);
                                        }
                                    }
#line 2842 "parser.c"
    break;

  case 98: /* returnstmt: "return" expr ";"  */
#line 888 "parser.y"
                                    {
                                        if(infunctioncounter > 0){
                                            emit(ret, (yyvsp[-1].exprValue), NULL, NULL, 0, yylineno);   
                                        }else{
                                            printf("You are not inside a function\n");
                                            exit(1);
                                        }
                                    }
#line 2855 "parser.c"
    break;


#line 2859 "parser.c"

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

#line 898 "parser.y"


void yyerror(const char* yaccProvidedMessage){
    fprintf(stderr, "%s: at line %d, before token %s\n", yaccProvidedMessage, yylineno, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
    exit(1);
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

    /* Quads */
    init_lib_func();
    yyparse();

   /* Instructions */
    //print_s();
    generate_code();

    /* print_s(); */
    printmyQuad();
    printf("\n\n-----------------------------------------------------------------");
    printf("\n-------------------------INSTRUCTIONS------------------------\n\n");
    printmyInstructions ();

    binaryFile_Creation();

    return 0;
}
