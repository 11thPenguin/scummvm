/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     UNARY = 258,
     CASTREF = 259,
     VOID = 260,
     VAR = 261,
     POINT = 262,
     RECT = 263,
     ARRAY = 264,
     SYMBOL = 265,
     OBJECT = 266,
     INT = 267,
     THEENTITY = 268,
     THEENTITYWITHID = 269,
     FLOAT = 270,
     BLTIN = 271,
     BLTINNOARGS = 272,
     BLTINNOARGSORONE = 273,
     BLTINONEARG = 274,
     BLTINARGLIST = 275,
     ID = 276,
     STRING = 277,
     HANDLER = 278,
     tDOWN = 279,
     tELSE = 280,
     tNLELSIF = 281,
     tEND = 282,
     tEXIT = 283,
     tFRAME = 284,
     tGLOBAL = 285,
     tGO = 286,
     tIF = 287,
     tINTO = 288,
     tLOOP = 289,
     tMACRO = 290,
     tMOVIE = 291,
     tNEXT = 292,
     tOF = 293,
     tPREVIOUS = 294,
     tPUT = 295,
     tREPEAT = 296,
     tSET = 297,
     tTHEN = 298,
     tTO = 299,
     tWHEN = 300,
     tWITH = 301,
     tWHILE = 302,
     tNLELSE = 303,
     tFACTORY = 304,
     tMETHOD = 305,
     tOPEN = 306,
     tPLAY = 307,
     tDONE = 308,
     tPLAYACCEL = 309,
     tINSTANCE = 310,
     tGE = 311,
     tLE = 312,
     tGT = 313,
     tLT = 314,
     tEQ = 315,
     tNEQ = 316,
     tAND = 317,
     tOR = 318,
     tNOT = 319,
     tMOD = 320,
     tAFTER = 321,
     tBEFORE = 322,
     tCONCAT = 323,
     tCONTAINS = 324,
     tSTARTS = 325,
     tSPRITE = 326,
     tINTERSECTS = 327,
     tWITHIN = 328,
     tON = 329,
     tSOUND = 330
   };
#endif
/* Tokens.  */
#define UNARY 258
#define CASTREF 259
#define VOID 260
#define VAR 261
#define POINT 262
#define RECT 263
#define ARRAY 264
#define SYMBOL 265
#define OBJECT 266
#define INT 267
#define THEENTITY 268
#define THEENTITYWITHID 269
#define FLOAT 270
#define BLTIN 271
#define BLTINNOARGS 272
#define BLTINNOARGSORONE 273
#define BLTINONEARG 274
#define BLTINARGLIST 275
#define ID 276
#define STRING 277
#define HANDLER 278
#define tDOWN 279
#define tELSE 280
#define tNLELSIF 281
#define tEND 282
#define tEXIT 283
#define tFRAME 284
#define tGLOBAL 285
#define tGO 286
#define tIF 287
#define tINTO 288
#define tLOOP 289
#define tMACRO 290
#define tMOVIE 291
#define tNEXT 292
#define tOF 293
#define tPREVIOUS 294
#define tPUT 295
#define tREPEAT 296
#define tSET 297
#define tTHEN 298
#define tTO 299
#define tWHEN 300
#define tWITH 301
#define tWHILE 302
#define tNLELSE 303
#define tFACTORY 304
#define tMETHOD 305
#define tOPEN 306
#define tPLAY 307
#define tDONE 308
#define tPLAYACCEL 309
#define tINSTANCE 310
#define tGE 311
#define tLE 312
#define tGT 313
#define tLT 314
#define tEQ 315
#define tNEQ 316
#define tAND 317
#define tOR 318
#define tNOT 319
#define tMOD 320
#define tAFTER 321
#define tBEFORE 322
#define tCONCAT 323
#define tCONTAINS 324
#define tSTARTS 325
#define tSPRITE 326
#define tINTERSECTS 327
#define tWITHIN 328
#define tON 329
#define tSOUND 330




/* Copy the first part of user declarations.  */
#line 49 "engines/director/lingo/lingo-gr.y"

#define FORBIDDEN_SYMBOL_ALLOW_ALL

#include "common/hash-str.h"

#include "director/lingo/lingo.h"
#include "director/lingo/lingo-gr.h"

extern int yylex();
extern int yyparse();

using namespace Director;
void yyerror(const char *s) {
	g_lingo->_hadError = true;
	warning("%s at line %d col %d", s, g_lingo->_linenumber, g_lingo->_colnumber);
}




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 69 "engines/director/lingo/lingo-gr.y"
{
	Common::String *s;
	int i;
	double f;
	int e[2];	// Entity + field
	int code;
	int narg;	/* number of arguments */
	Common::Array<double> *arr;
}
/* Line 193 of yacc.c.  */
#line 276 "engines/director/lingo/lingo-gr.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 289 "engines/director/lingo/lingo-gr.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  97
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNRULES -- Number of states.  */
#define YYNSTATES  289

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      83,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    82,    77,     2,
      84,    85,    80,    78,    88,    79,     2,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      87,    76,    86,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    12,    14,    15,    17,    19,
      21,    23,    25,    30,    35,    40,    45,    50,    56,    61,
      66,    72,    74,    76,    78,    80,    89,   101,   114,   118,
     127,   139,   151,   158,   169,   180,   181,   185,   188,   190,
     193,   195,   202,   204,   210,   212,   216,   220,   223,   227,
     229,   231,   232,   233,   234,   237,   240,   244,   246,   248,
     250,   252,   254,   259,   261,   263,   266,   268,   272,   276,
     280,   284,   288,   292,   296,   300,   304,   308,   312,   316,
     319,   323,   327,   331,   335,   339,   342,   345,   349,   354,
     359,   362,   364,   366,   369,   371,   374,   377,   380,   383,
     385,   388,   393,   396,   400,   402,   406,   408,   412,   415,
     418,   421,   424,   428,   431,   434,   436,   440,   443,   446,
     449,   453,   456,   457,   466,   469,   470,   479,   480,   481,
     492,   493,   495,   499,   504,   505,   509,   510,   512
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      90,     0,    -1,    90,    91,    92,    -1,    92,    -1,     1,
      91,    -1,    83,    -1,    -1,   119,    -1,   112,    -1,   126,
      -1,    93,    -1,    95,    -1,    40,   111,    33,    21,    -1,
      40,   111,    66,   111,    -1,    40,   111,    67,   111,    -1,
      42,    21,    76,   111,    -1,    42,    13,    76,   111,    -1,
      42,    14,   111,    76,   111,    -1,    42,    21,    44,   111,
      -1,    42,    13,    44,   111,    -1,    42,    14,   111,    44,
     111,    -1,   111,    -1,   112,    -1,    94,    -1,    96,    -1,
     103,    84,   102,    85,   109,   108,    27,    41,    -1,   104,
      76,   111,   108,    44,   111,   108,   109,   108,    27,    41,
      -1,   104,    76,   111,   108,    24,    44,   111,   108,   109,
     108,    27,    41,    -1,   110,   111,   108,    -1,   105,   102,
      43,    91,   109,   108,    27,    32,    -1,   105,   102,    43,
      91,   109,   108,    48,   109,   108,    27,    32,    -1,   105,
     102,    43,    91,   109,   108,   107,    98,   108,    27,    32,
      -1,   105,   102,    43,   107,    94,   108,    -1,   105,   102,
      43,   107,    94,   108,    48,   107,    94,   108,    -1,   105,
     102,    43,   107,    94,   108,    99,   108,    97,   108,    -1,
      -1,    48,   107,    94,    -1,    98,   101,    -1,   101,    -1,
      99,   100,    -1,   100,    -1,   106,   102,    43,   107,    95,
     108,    -1,    99,    -1,   106,   102,    43,   109,   108,    -1,
     111,    -1,   111,    76,   111,    -1,    84,   102,    85,    -1,
      41,    47,    -1,    41,    46,    21,    -1,    32,    -1,    26,
      -1,    -1,    -1,    -1,   109,    91,    -1,   109,    95,    -1,
      45,    21,    43,    -1,    12,    -1,    15,    -1,    10,    -1,
      22,    -1,    17,    -1,    21,    84,   127,    85,    -1,    21,
      -1,    13,    -1,    14,   111,    -1,    93,    -1,   111,    78,
     111,    -1,   111,    79,   111,    -1,   111,    80,   111,    -1,
     111,    81,   111,    -1,   111,    65,   111,    -1,   111,    86,
     111,    -1,   111,    87,   111,    -1,   111,    61,   111,    -1,
     111,    56,   111,    -1,   111,    57,   111,    -1,   111,    62,
     111,    -1,   111,    63,   111,    -1,    64,   111,    -1,   111,
      77,   111,    -1,   111,    66,   111,    -1,   111,    68,   111,
      -1,   111,    69,   111,    -1,   111,    70,   111,    -1,    78,
     111,    -1,    79,   111,    -1,    84,   111,    85,    -1,    71,
     111,    72,   111,    -1,    71,   111,    73,   111,    -1,    40,
     111,    -1,   115,    -1,   118,    -1,    28,    41,    -1,    28,
      -1,    30,   113,    -1,    55,   114,    -1,    19,   111,    -1,
      18,   111,    -1,    18,    -1,    20,   127,    -1,    51,   111,
      46,   111,    -1,    51,   111,    -1,    75,    21,   127,    -1,
      21,    -1,   113,    88,    21,    -1,    21,    -1,   114,    88,
      21,    -1,    31,    34,    -1,    31,    37,    -1,    31,    39,
      -1,    31,   116,    -1,    31,   116,   117,    -1,    31,   117,
      -1,    29,   111,    -1,   111,    -1,    38,    36,   111,    -1,
      36,   111,    -1,    52,    53,    -1,    52,   116,    -1,    52,
     116,   117,    -1,    52,   117,    -1,    -1,    35,    21,   120,
     107,   124,    91,   125,   109,    -1,    49,    21,    -1,    -1,
      50,    21,   121,   107,   124,    91,   125,   109,    -1,    -1,
      -1,    74,    21,   122,   107,   123,   124,    91,   125,   109,
      27,    -1,    -1,    21,    -1,   124,    88,    21,    -1,   124,
      91,    88,    21,    -1,    -1,    21,   107,   127,    -1,    -1,
     111,    -1,   127,    88,   111,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   107,   108,   111,   116,   117,   118,   119,
     120,   121,   124,   130,   131,   132,   138,   146,   154,   160,
     168,   177,   178,   180,   181,   186,   197,   213,   225,   233,
     240,   249,   258,   268,   278,   289,   290,   293,   294,   297,
     298,   301,   309,   310,   318,   319,   320,   322,   324,   330,
     336,   343,   345,   347,   348,   349,   352,   358,   359,   362,
     365,   368,   371,   374,   378,   385,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     417,   418,   419,   420,   421,   423,   424,   425,   428,   431,
     434,   435,   436,   437,   440,   441,   444,   445,   456,   457,
     458,   459,   462,   465,   470,   471,   474,   475,   478,   479,
     482,   485,   515,   515,   521,   524,   524,   529,   530,   529,
     542,   543,   544,   545,   547,   551,   559,   560,   561
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNARY", "CASTREF", "VOID", "VAR",
  "POINT", "RECT", "ARRAY", "SYMBOL", "OBJECT", "INT", "THEENTITY",
  "THEENTITYWITHID", "FLOAT", "BLTIN", "BLTINNOARGS", "BLTINNOARGSORONE",
  "BLTINONEARG", "BLTINARGLIST", "ID", "STRING", "HANDLER", "tDOWN",
  "tELSE", "tNLELSIF", "tEND", "tEXIT", "tFRAME", "tGLOBAL", "tGO", "tIF",
  "tINTO", "tLOOP", "tMACRO", "tMOVIE", "tNEXT", "tOF", "tPREVIOUS",
  "tPUT", "tREPEAT", "tSET", "tTHEN", "tTO", "tWHEN", "tWITH", "tWHILE",
  "tNLELSE", "tFACTORY", "tMETHOD", "tOPEN", "tPLAY", "tDONE",
  "tPLAYACCEL", "tINSTANCE", "tGE", "tLE", "tGT", "tLT", "tEQ", "tNEQ",
  "tAND", "tOR", "tNOT", "tMOD", "tAFTER", "tBEFORE", "tCONCAT",
  "tCONTAINS", "tSTARTS", "tSPRITE", "tINTERSECTS", "tWITHIN", "tON",
  "tSOUND", "'='", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "'\\n'",
  "'('", "')'", "'>'", "'<'", "','", "$accept", "program", "nl",
  "programline", "asgn", "stmtoneliner", "stmt", "ifstmt",
  "elsestmtoneliner", "elseifstmt", "elseifstmtoneliner",
  "elseifstmtoneliner1", "elseifstmt1", "cond", "repeatwhile",
  "repeatwith", "if", "elseif", "begin", "end", "stmtlist", "when", "expr",
  "func", "globallist", "instancelist", "gotofunc", "gotoframe",
  "gotomovie", "playfunc", "defn", "@1", "@2", "@3", "@4", "argdef",
  "argstore", "macro", "arglist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    61,    38,    43,    45,
      42,    47,    37,    10,    40,    41,    62,    60,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    90,    91,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   101,   101,   102,   102,   102,   103,   104,   105,
     106,   107,   108,   109,   109,   109,   110,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   118,   118,
     118,   118,   120,   119,   119,   121,   119,   122,   123,   119,
     124,   124,   124,   124,   125,   126,   127,   127,   127
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     2,     1,     0,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     5,     4,     4,
       5,     1,     1,     1,     1,     8,    11,    12,     3,     8,
      11,    11,     6,    10,    10,     0,     3,     2,     1,     2,
       1,     6,     1,     5,     1,     3,     3,     2,     3,     1,
       1,     0,     0,     0,     2,     2,     3,     1,     1,     1,
       1,     1,     4,     1,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     2,     2,     3,     4,     4,
       2,     1,     1,     2,     1,     2,     2,     2,     2,     1,
       2,     4,     2,     3,     1,     3,     1,     3,     2,     2,
       2,     2,     3,     2,     2,     1,     3,     2,     2,     2,
       3,     2,     0,     8,     2,     0,     8,     0,     0,    10,
       0,     1,     3,     4,     0,     3,     0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    59,    57,    64,     0,    58,    61,    99,     0,
     136,    51,    60,    94,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,    66,    23,    11,    24,
       0,     0,     0,     0,    21,     8,    91,    92,     7,     9,
       5,     4,    63,     0,    66,    65,    98,    97,   137,   100,
     136,   136,    93,   104,    95,     0,   108,     0,   109,     0,
     110,   115,   111,   113,   122,    90,     0,    47,     0,     0,
       0,     0,   124,   125,   102,   118,   119,   121,   106,    96,
      79,     0,   127,   136,    85,    86,     0,     1,     6,     0,
       0,     0,     0,    44,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,     0,   114,   117,     0,
     112,    51,     0,     0,     0,    48,     0,     0,     0,     0,
       0,    56,    51,     0,   120,     0,     0,     0,    51,   103,
      87,     2,     0,    52,     0,     0,    51,     0,    28,    75,
      76,    74,    77,    78,    71,    81,    82,    83,    84,    80,
      67,    68,    69,    70,    72,    73,   138,    62,   105,   116,
     130,    12,    13,    14,    19,    16,     0,     0,    18,    15,
     130,   101,   107,    88,    89,   128,    53,     0,    46,    53,
       0,    45,   131,     0,    20,    17,     0,   130,    52,     0,
       0,    52,    52,    22,     0,   134,   134,     0,    54,    55,
       0,     0,    52,    51,    32,   132,     0,    53,    53,   134,
       0,    52,    53,     0,    53,     0,    50,    51,    52,    40,
       0,   133,   123,   126,    53,    25,    53,    52,    29,    52,
      52,    42,    38,     0,     0,    39,    35,     0,     0,    52,
       0,     0,    37,     0,     0,    52,    51,    52,    51,   129,
       0,     0,     0,     0,    51,    33,     0,    34,     0,     0,
      26,    30,    31,    52,    36,    52,    27,    43,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    34,   218,    35,    54,    37,   219,    39,   267,   250,
     251,   239,   252,   102,    40,    41,    42,   240,   278,   158,
     208,    43,    44,   213,    64,    89,    46,    72,    73,    47,
      48,   131,   142,   148,   207,   203,   227,    49,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -221
static const yytype_int16 yypact[] =
{
     267,   -34,  -221,  -221,  -221,   790,  -221,  -221,   790,   790,
     790,  1059,  -221,    -6,    36,   711,  -221,    42,   790,   -22,
      52,    57,    59,    60,   790,   745,    62,   790,   790,    68,
      69,   790,   790,   790,     4,  -221,     5,  -221,  -221,  -221,
     -20,    15,   823,   790,  1032,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,     8,   790,  -221,  1032,  1032,  1032,  1032,     7,
     790,   790,  -221,  -221,    11,   790,  -221,   790,  -221,    58,
    -221,  1032,    41,  -221,  -221,   843,    72,  -221,   -37,   790,
     -30,    54,  -221,  -221,   897,  -221,    41,  -221,  -221,    14,
     -46,   924,  -221,   790,   -46,   -46,   978,  -221,   342,   823,
     790,   823,    63,  1005,  1032,   790,   790,   790,   790,   790,
     790,   790,   790,   790,   790,   790,   790,   790,   790,   790,
     790,   790,   843,   790,   -26,     7,    84,  1032,  1032,   790,
    -221,  -221,    86,   790,   790,  -221,   790,   790,   870,   790,
     790,  -221,  -221,   790,  -221,    88,   790,   790,  -221,     7,
    -221,  -221,    26,  1032,    27,   951,   -34,   790,  -221,   396,
     396,   396,   -46,   -46,   -46,  1032,  1032,   396,   396,   179,
     471,   471,   -46,   -46,  1032,  1032,  1032,  -221,  -221,  1032,
      92,  -221,  1032,  1032,  1032,  1032,   790,   790,  1032,  1032,
      92,  1032,  -221,  1032,  1032,  -221,  -221,     6,  -221,  -221,
     638,  1032,  -221,   -60,  1032,  1032,   -60,    92,   490,    70,
     790,   490,  -221,  -221,    94,    28,    28,   -60,  -221,  -221,
      90,   790,  1032,    -1,   -15,  -221,    97,  -221,  -221,    28,
      78,  1032,  -221,    91,  -221,    98,  -221,  -221,    98,  -221,
     823,  -221,   490,   490,  -221,  -221,  -221,   490,  -221,   490,
      98,    98,  -221,   823,   638,  -221,    77,    83,   415,   490,
      93,   100,  -221,   101,    87,  -221,  -221,  -221,  -221,  -221,
     102,    96,    99,   103,   -11,  -221,   638,  -221,   565,   104,
    -221,  -221,  -221,   490,  -221,  -221,  -221,  -221,  -221
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,     9,    35,     2,  -194,     0,  -221,  -221,  -221,
     -90,  -220,  -111,   -72,  -221,  -221,  -221,  -214,   -10,   -13,
    -190,  -221,    43,     3,  -221,  -221,  -221,   116,   -17,  -221,
    -221,  -221,  -221,  -221,  -221,  -173,  -197,  -221,   -48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -64
static const yytype_int16 yytable[] =
{
      38,    61,    36,    45,    97,   -10,   212,   136,    87,   211,
      51,   236,   124,   125,   139,   -53,   -53,   206,   255,   228,
     111,   253,   112,    50,    76,    77,   233,   152,   214,   154,
     209,   255,   244,   237,   217,    62,   253,   242,   243,   137,
     120,   121,   247,    98,   249,   149,   140,   234,    55,    50,
     210,    56,    57,    58,   258,   130,   259,    63,    71,   177,
     265,    75,   123,    74,    99,    78,    79,    84,    71,   144,
      90,    91,   -53,    80,    94,    95,    96,    67,    81,    69,
      82,    83,   284,    88,   283,   103,   104,    50,   -10,    92,
      93,   100,    60,   135,   129,   123,   122,   141,    38,   126,
      36,    45,   145,    58,    58,   178,   156,   181,   127,   192,
     128,   196,   198,   202,   221,   225,   226,   230,   241,   245,
     271,   180,   138,   248,   236,   266,   268,   272,   273,   279,
     274,   281,   190,   151,   238,   282,    58,   280,   195,   262,
     197,    86,   103,   153,   155,   286,   200,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   199,   176,     0,   257,     0,
       0,     0,   179,     0,     0,     0,   182,   183,     0,   184,
     185,   264,   188,   189,     0,     0,   191,     0,     0,   193,
     194,     0,     0,     0,     0,   220,     0,     0,   223,   224,
     201,     0,     0,     0,     0,     0,     0,     0,     0,   232,
       0,     0,   215,   235,     0,   216,     0,     0,   246,     0,
       0,     0,     0,     0,     0,   256,   229,   254,     0,   204,
     205,     0,     0,     0,   260,     0,   261,   263,     0,     0,
       0,   108,   109,     0,   110,   111,   270,   112,     0,     0,
       0,     0,   275,   222,   277,     0,   276,   116,   117,   118,
     119,     0,     0,     0,   231,   120,   121,    -6,     1,     0,
     287,     0,   288,     0,     0,     0,     0,     2,   285,     3,
       4,     5,     6,   103,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,    13,   103,    14,    15,    16,
       0,     0,    17,     0,     0,     0,     0,    18,    19,    20,
       0,     0,    21,     0,     0,     0,    22,    23,    24,    25,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,    28,     0,
       0,    29,    30,     0,     0,    31,    32,     0,     0,     0,
      -6,    33,     2,     0,     3,     4,     5,     6,     0,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
      13,     0,    14,    15,    16,     0,     0,    17,     0,     0,
       0,     0,    18,    19,    20,     0,     0,    21,     0,     0,
       0,    22,    23,    24,    25,     0,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,    28,     0,     0,    29,    30,     0,     0,
      31,    32,     0,     0,     0,     2,    33,     3,     4,     5,
       6,     0,     7,     8,     9,    10,    52,    12,     0,     0,
       0,     0,   269,    13,     0,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,   108,   109,
      21,   110,   111,     0,   112,     0,    24,    25,     0,     0,
      26,     0,     0,   115,   116,   117,   118,   119,     0,    27,
       0,     0,   120,   121,     0,     0,    28,     0,     0,     0,
      30,     0,     0,    31,    32,     0,     0,     0,    50,    33,
       2,     0,     3,     4,     5,     6,     0,     7,     8,     9,
      10,    52,    12,     0,     0,     0,     0,     0,    13,     0,
      14,    15,    16,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,   108,   109,    21,   110,   111,     0,   112,
       0,    24,    25,     0,     0,    26,     0,     0,     0,     0,
       0,   118,   119,     0,    27,     0,     0,   120,   121,     0,
       0,    28,     0,     0,     0,    30,     0,     0,    31,    32,
       0,     0,     0,    50,    33,     2,     0,     3,     4,     5,
       6,     0,     7,     8,     9,    10,    52,    12,     0,     0,
       0,     0,     0,    13,     0,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,     0,     0,
      21,     0,     0,     0,     0,     0,    24,    25,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
      30,     0,     0,    31,    32,     0,     0,     0,     2,    33,
       3,     4,     5,     6,     0,     7,     8,     9,    10,    52,
      12,     0,     0,     0,     0,     0,    13,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,    28,
       0,     0,     0,    30,     0,     0,    31,    32,     0,     0,
       0,     2,    33,     3,     4,     5,     6,     0,     7,     0,
       0,     0,    52,    12,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,    66,     0,    67,    68,    69,
      70,    53,     0,    20,     0,     2,     0,     3,     4,     5,
       6,     0,     7,     0,     0,     0,    52,    12,     0,     0,
       0,     0,     0,     0,    65,    27,     0,     0,     0,     0,
       0,    67,    28,    69,     0,    53,     0,    20,     0,    31,
      32,     0,     0,     0,     0,    33,     0,     0,    85,     0,
       2,     0,     3,     4,     5,     6,     0,     7,     0,    27,
       0,    52,    12,     0,     0,     0,    28,     0,     0,     0,
       0,     0,     0,    31,    32,     0,     0,     0,     0,    33,
      53,     0,    20,     2,     0,     3,     4,     5,     6,     0,
       7,     0,     0,     0,    52,    12,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,    28,     0,    53,     0,    20,     0,     0,    31,    32,
       0,     0,     0,     0,    33,     0,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,   105,
     106,    31,    32,     0,   107,   108,   109,   101,   110,   133,
     134,   112,   113,   114,   186,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,     0,   105,   106,     0,   120,
     121,   107,   108,   109,     0,   110,   111,     0,   112,   113,
     114,     0,     0,   143,     0,     0,   187,   115,   116,   117,
     118,   119,     0,   105,   106,     0,   120,   121,   107,   108,
     109,     0,   110,   111,     0,   112,   113,   114,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,     0,
     105,   106,     0,   120,   121,   107,   108,   109,     0,   110,
     111,     0,   112,   113,   114,     0,   146,   147,     0,     0,
       0,   115,   116,   117,   118,   119,     0,   105,   106,     0,
     120,   121,   107,   108,   109,     0,   110,   111,     0,   112,
     113,   114,     0,     0,     0,     0,     0,   157,   115,   116,
     117,   118,   119,     0,   105,   106,   150,   120,   121,   107,
     108,   109,     0,   110,   111,     0,   112,   113,   114,     0,
       0,     0,     0,     0,     0,   115,   116,   117,   118,   119,
       0,   105,   106,   150,   120,   121,   107,   108,   109,     0,
     110,   111,     0,   112,   113,   114,     0,     0,     0,     0,
       0,   157,   115,   116,   117,   118,   119,     0,   105,   106,
       0,   120,   121,   107,   108,   109,     0,   110,   111,     0,
     112,   113,   114,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,     0,   -63,   -63,     0,   120,   121,
     -63,   -63,   -63,     0,   -63,   -63,     0,   -63,   -63,   -63,
       0,     0,     0,     0,     0,     0,   -63,     0,     0,   -63,
     -63,     0,     0,    60,     0,   -63,   -63
};

static const yytype_int16 yycheck[] =
{
       0,    11,     0,     0,     0,     0,   200,    44,    25,   199,
       1,    26,    60,    61,    44,    26,    27,   190,   238,   216,
      66,   235,    68,    83,    46,    47,    27,    99,    88,   101,
      24,   251,   229,    48,   207,    41,   250,   227,   228,    76,
      86,    87,   232,    34,   234,    93,    76,    48,     5,    83,
      44,     8,     9,    10,   244,    72,   246,    21,    15,    85,
     254,    18,    88,    21,    84,    13,    14,    24,    25,    86,
      27,    28,    83,    21,    31,    32,    33,    36,    21,    38,
      21,    21,   276,    21,   274,    42,    43,    83,    83,    21,
      21,    76,    84,    21,    36,    88,    53,    43,    98,    88,
      98,    98,    88,    60,    61,    21,    43,    21,    65,    21,
      67,    85,    85,    21,    44,    21,    88,    27,    21,    41,
      27,   131,    79,    32,    26,    48,    43,    27,    27,    27,
      43,    32,   142,    98,   224,    32,    93,    41,   148,   250,
     153,    25,    99,   100,   101,    41,   156,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   156,   123,    -1,   240,    -1,
      -1,    -1,   129,    -1,    -1,    -1,   133,   134,    -1,   136,
     137,   253,   139,   140,    -1,    -1,   143,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,   208,    -1,    -1,   211,   212,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   222,
      -1,    -1,   203,   223,    -1,   206,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,   238,   217,   237,    -1,   186,
     187,    -1,    -1,    -1,   247,    -1,   249,   250,    -1,    -1,
      -1,    62,    63,    -1,    65,    66,   259,    68,    -1,    -1,
      -1,    -1,   265,   210,   267,    -1,   266,    78,    79,    80,
      81,    -1,    -1,    -1,   221,    86,    87,     0,     1,    -1,
     283,    -1,   285,    -1,    -1,    -1,    -1,    10,   278,    12,
      13,    14,    15,   240,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    28,   253,    30,    31,    32,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,
      83,    84,    10,    -1,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    45,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    75,    -1,    -1,
      78,    79,    -1,    -1,    -1,    10,    84,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    62,    63,
      45,    65,    66,    -1,    68,    -1,    51,    52,    -1,    -1,
      55,    -1,    -1,    77,    78,    79,    80,    81,    -1,    64,
      -1,    -1,    86,    87,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    -1,    -1,    -1,    83,    84,
      10,    -1,    12,    13,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    62,    63,    45,    65,    66,    -1,    68,
      -1,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    64,    -1,    -1,    86,    87,    -1,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      -1,    -1,    -1,    83,    84,    10,    -1,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    -1,    -1,    -1,    10,    84,
      12,    13,    14,    15,    -1,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,
      -1,    10,    84,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,    38,
      39,    40,    -1,    42,    -1,    10,    -1,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    64,    -1,    -1,    -1,    -1,
      -1,    36,    71,    38,    -1,    40,    -1,    42,    -1,    78,
      79,    -1,    -1,    -1,    -1,    84,    -1,    -1,    53,    -1,
      10,    -1,    12,    13,    14,    15,    -1,    17,    -1,    64,
      -1,    21,    22,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    84,
      40,    -1,    42,    10,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    40,    -1,    42,    -1,    -1,    78,    79,
      -1,    -1,    -1,    -1,    84,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    56,
      57,    78,    79,    -1,    61,    62,    63,    84,    65,    66,
      67,    68,    69,    70,    44,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    -1,    56,    57,    -1,    86,
      87,    61,    62,    63,    -1,    65,    66,    -1,    68,    69,
      70,    -1,    -1,    46,    -1,    -1,    76,    77,    78,    79,
      80,    81,    -1,    56,    57,    -1,    86,    87,    61,    62,
      63,    -1,    65,    66,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      56,    57,    -1,    86,    87,    61,    62,    63,    -1,    65,
      66,    -1,    68,    69,    70,    -1,    72,    73,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    -1,    56,    57,    -1,
      86,    87,    61,    62,    63,    -1,    65,    66,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    -1,    56,    57,    85,    86,    87,    61,
      62,    63,    -1,    65,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      -1,    56,    57,    85,    86,    87,    61,    62,    63,    -1,
      65,    66,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81,    -1,    56,    57,
      -1,    86,    87,    61,    62,    63,    -1,    65,    66,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    56,    57,    -1,    86,    87,
      61,    62,    63,    -1,    65,    66,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    80,
      81,    -1,    -1,    84,    -1,    86,    87
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    10,    12,    13,    14,    15,    17,    18,    19,
      20,    21,    22,    28,    30,    31,    32,    35,    40,    41,
      42,    45,    49,    50,    51,    52,    55,    64,    71,    74,
      75,    78,    79,    84,    90,    92,    93,    94,    95,    96,
     103,   104,   105,   110,   111,   112,   115,   118,   119,   126,
      83,    91,    21,    40,    93,   111,   111,   111,   111,   127,
      84,   107,    41,    21,   113,    29,    34,    36,    37,    38,
      39,   111,   116,   117,    21,   111,    46,    47,    13,    14,
      21,    21,    21,    21,   111,    53,   116,   117,    21,   114,
     111,   111,    21,    21,   111,   111,   111,     0,    91,    84,
      76,    84,   102,   111,   111,    56,    57,    61,    62,    63,
      65,    66,    68,    69,    70,    77,    78,    79,    80,    81,
      86,    87,   111,    88,   127,   127,    88,   111,   111,    36,
     117,   120,    33,    66,    67,    21,    44,    76,   111,    44,
      76,    43,   121,    46,   117,    88,    72,    73,   122,   127,
      85,    92,   102,   111,   102,   111,    43,    76,   108,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,    85,    21,   111,
     107,    21,   111,   111,   111,   111,    44,    76,   111,   111,
     107,   111,    21,   111,   111,   107,    85,   108,    85,    91,
     107,   111,    21,   124,   111,   111,   124,   123,   109,    24,
      44,   109,    94,   112,    88,    91,    91,   124,    91,    95,
     108,    44,   111,   108,   108,    21,    88,   125,   125,    91,
      27,   111,   108,    27,    48,   107,    26,    48,    99,   100,
     106,    21,   109,   109,   125,    41,   108,   109,    32,   109,
      98,    99,   101,   106,   107,   100,   108,   102,   109,   109,
     108,   108,   101,   108,   102,    94,    48,    97,    43,    27,
     108,    27,    27,    27,    43,   108,   107,   108,   107,    27,
      41,    32,    32,   109,    94,    95,    41,   108,   108
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 108 "engines/director/lingo/lingo-gr.y"
    { yyerrok; ;}
    break;

  case 5:
#line 111 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->_linenumber++;
		g_lingo->_colnumber = 1;
	;}
    break;

  case 10:
#line 120 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_xpop); ;}
    break;

  case 12:
#line 124 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_varpush);
		g_lingo->codeString((yyvsp[(4) - (4)].s)->c_str());
		g_lingo->code1(g_lingo->c_assign);
		(yyval.code) = (yyvsp[(2) - (4)].code);
		delete (yyvsp[(4) - (4)].s); ;}
    break;

  case 13:
#line 130 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->code1(g_lingo->c_after); ;}
    break;

  case 14:
#line 131 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->code1(g_lingo->c_before); ;}
    break;

  case 15:
#line 132 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_varpush);
		g_lingo->codeString((yyvsp[(2) - (4)].s)->c_str());
		g_lingo->code1(g_lingo->c_assign);
		(yyval.code) = (yyvsp[(4) - (4)].code);
		delete (yyvsp[(2) - (4)].s); ;}
    break;

  case 16:
#line 138 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(0); // Put dummy id
		g_lingo->code1(g_lingo->c_theentityassign);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(2) - (4)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(2) - (4)].e)[1]);
		g_lingo->code2(e, f);
		(yyval.code) = (yyvsp[(4) - (4)].code); ;}
    break;

  case 17:
#line 146 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_swap);
		g_lingo->code1(g_lingo->c_theentityassign);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(2) - (5)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(2) - (5)].e)[1]);
		g_lingo->code2(e, f);
		(yyval.code) = (yyvsp[(5) - (5)].code); ;}
    break;

  case 18:
#line 154 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_varpush);
		g_lingo->codeString((yyvsp[(2) - (4)].s)->c_str());
		g_lingo->code1(g_lingo->c_assign);
		(yyval.code) = (yyvsp[(4) - (4)].code);
		delete (yyvsp[(2) - (4)].s); ;}
    break;

  case 19:
#line 160 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(0); // Put dummy id
		g_lingo->code1(g_lingo->c_theentityassign);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(2) - (4)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(2) - (4)].e)[1]);
		g_lingo->code2(e, f);
		(yyval.code) = (yyvsp[(4) - (4)].code); ;}
    break;

  case 20:
#line 168 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_swap);
		g_lingo->code1(g_lingo->c_theentityassign);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(2) - (5)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(2) - (5)].e)[1]);
		g_lingo->code2(e, f);
		(yyval.code) = (yyvsp[(5) - (5)].code); ;}
    break;

  case 21:
#line 177 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_xpop); ;}
    break;

  case 25:
#line 186 "engines/director/lingo/lingo-gr.y"
    {
		inst body = 0, end = 0;
		WRITE_UINT32(&body, (yyvsp[(5) - (8)].code));
		WRITE_UINT32(&end, (yyvsp[(6) - (8)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (8)].code) + 1] = body;	/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (8)].code) + 2] = end; ;}
    break;

  case 26:
#line 197 "engines/director/lingo/lingo-gr.y"
    {
		inst init = 0, finish = 0, body = 0, end = 0, inc = 0;
		WRITE_UINT32(&init, (yyvsp[(3) - (11)].code));
		WRITE_UINT32(&finish, (yyvsp[(6) - (11)].code));
		WRITE_UINT32(&body, (yyvsp[(8) - (11)].code));
		WRITE_UINT32(&end, (yyvsp[(9) - (11)].code));
		WRITE_UINT32(&inc, 1);
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 1] = init;	/* initial count value */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 2] = finish;/* final count value */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 3] = body;	/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 4] = inc;	/* increment */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 5] = end; ;}
    break;

  case 27:
#line 213 "engines/director/lingo/lingo-gr.y"
    {
		inst init = 0, finish = 0, body = 0, end = 0, inc = 0;
		WRITE_UINT32(&init, (yyvsp[(3) - (12)].code));
		WRITE_UINT32(&finish, (yyvsp[(7) - (12)].code));
		WRITE_UINT32(&body, (yyvsp[(9) - (12)].code));
		WRITE_UINT32(&end, (yyvsp[(10) - (12)].code));
		WRITE_UINT32(&inc, -1);
		(*g_lingo->_currentScript)[(yyvsp[(1) - (12)].code) + 1] = init;	/* initial count value */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (12)].code) + 2] = finish;/* final count value */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (12)].code) + 3] = body;	/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (12)].code) + 4] = inc;	/* increment */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (12)].code) + 5] = end; ;}
    break;

  case 28:
#line 225 "engines/director/lingo/lingo-gr.y"
    {
			inst end = 0;
			WRITE_UINT32(&end, (yyvsp[(3) - (3)].code));
			g_lingo->code1(STOP);
			(*g_lingo->_currentScript)[(yyvsp[(1) - (3)].code) + 1] = end;
		;}
    break;

  case 29:
#line 233 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(5) - (8)].code));
		WRITE_UINT32(&end, (yyvsp[(6) - (8)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (8)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (8)].code) + 3] = end;	/* end, if cond fails */
		g_lingo->processIf(0, 0); ;}
    break;

  case 30:
#line 240 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(5) - (11)].code));
		WRITE_UINT32(&else1, (yyvsp[(8) - (11)].code));
		WRITE_UINT32(&end, (yyvsp[(9) - (11)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 3] = end;	/* end, if cond fails */
		g_lingo->processIf(0, 0); ;}
    break;

  case 31:
#line 249 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(5) - (11)].code));
		WRITE_UINT32(&else1, (yyvsp[(7) - (11)].code));
		WRITE_UINT32(&end, (yyvsp[(9) - (11)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (11)].code) + 3] = end;	/* end, if cond fails */
		g_lingo->processIf(0, (yyvsp[(9) - (11)].code)); ;}
    break;

  case 32:
#line 258 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(4) - (6)].code));
		WRITE_UINT32(&else1, 0);
		WRITE_UINT32(&end, (yyvsp[(6) - (6)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (6)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (6)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (6)].code) + 3] = end; 	/* end, if cond fails */

		g_lingo->processIf(0, 0); ;}
    break;

  case 33:
#line 268 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(4) - (10)].code));
		WRITE_UINT32(&else1, (yyvsp[(8) - (10)].code));
		WRITE_UINT32(&end, (yyvsp[(10) - (10)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 3] = end; 	/* end, if cond fails */

		g_lingo->processIf(0, 0); ;}
    break;

  case 34:
#line 278 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[(4) - (10)].code));
		WRITE_UINT32(&else1, (yyvsp[(6) - (10)].code));
		WRITE_UINT32(&end, (yyvsp[(10) - (10)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 2] = else1;	/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[(1) - (10)].code) + 3] = end; 	/* end, if cond fails */

		g_lingo->processIf(0, (yyvsp[(10) - (10)].code)); ;}
    break;

  case 35:
#line 289 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = 0; ;}
    break;

  case 36:
#line 290 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = (yyvsp[(2) - (3)].code); ;}
    break;

  case 41:
#line 301 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0;
		WRITE_UINT32(&then, (yyvsp[(4) - (6)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (6)].code) + 1] = then;	/* thenpart */

		g_lingo->codeLabel((yyvsp[(1) - (6)].code)); ;}
    break;

  case 43:
#line 310 "engines/director/lingo/lingo-gr.y"
    {
		inst then = 0;
		WRITE_UINT32(&then, (yyvsp[(4) - (5)].code));
		(*g_lingo->_currentScript)[(yyvsp[(1) - (5)].code) + 1] = then;	/* thenpart */

		g_lingo->codeLabel((yyvsp[(1) - (5)].code)); ;}
    break;

  case 44:
#line 318 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(STOP); ;}
    break;

  case 45:
#line 319 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code2(g_lingo->c_eq, STOP); ;}
    break;

  case 47:
#line 322 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->code3(g_lingo->c_repeatwhilecode, STOP, STOP); ;}
    break;

  case 48:
#line 324 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code3(g_lingo->c_repeatwithcode, STOP, STOP);
		g_lingo->code3(STOP, STOP, STOP);
		g_lingo->codeString((yyvsp[(3) - (3)].s)->c_str());
		delete (yyvsp[(3) - (3)].s); ;}
    break;

  case 49:
#line 330 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_ifcode);
		g_lingo->code3(STOP, STOP, STOP);
		g_lingo->code1(0);  // Do not skip end
		g_lingo->codeLabel(0); ;}
    break;

  case 50:
#line 336 "engines/director/lingo/lingo-gr.y"
    {
		inst skipEnd;
		WRITE_UINT32(&skipEnd, 1); // We have to skip end to avoid multiple executions
		(yyval.code) = g_lingo->code1(g_lingo->c_ifcode);
		g_lingo->code3(STOP, STOP, STOP);
		g_lingo->code1(skipEnd); ;}
    break;

  case 51:
#line 343 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->_currentScript->size(); ;}
    break;

  case 52:
#line 345 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(STOP); (yyval.code) = g_lingo->_currentScript->size(); ;}
    break;

  case 53:
#line 347 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->_currentScript->size(); ;}
    break;

  case 56:
#line 352 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_whencode);
		g_lingo->code1(STOP);
		g_lingo->codeString((yyvsp[(2) - (3)].s)->c_str());
		delete (yyvsp[(2) - (3)].s); ;}
    break;

  case 57:
#line 358 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = g_lingo->codeConst((yyvsp[(1) - (1)].i)); ;}
    break;

  case 58:
#line 359 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_fconstpush);
		g_lingo->codeFloat((yyvsp[(1) - (1)].f)); ;}
    break;

  case 59:
#line 362 "engines/director/lingo/lingo-gr.y"
    {											// D3
		(yyval.code) = g_lingo->code1(g_lingo->c_symbolpush);
		g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str()); ;}
    break;

  case 60:
#line 365 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_stringpush);
		g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str()); ;}
    break;

  case 61:
#line 368 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->_handlers[*(yyvsp[(1) - (1)].s)]->u.func);
		delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 62:
#line 371 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->codeFunc((yyvsp[(1) - (4)].s), (yyvsp[(3) - (4)].narg));
		delete (yyvsp[(1) - (4)].s); ;}
    break;

  case 63:
#line 374 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_eval);
		g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str());
		delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 64:
#line 378 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->codeConst(0); // Put dummy id
		g_lingo->code1(g_lingo->c_theentitypush);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(1) - (1)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(1) - (1)].e)[1]);
		g_lingo->code2(e, f); ;}
    break;

  case 65:
#line 385 "engines/director/lingo/lingo-gr.y"
    {
		(yyval.code) = g_lingo->code1(g_lingo->c_theentitypush);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[(1) - (2)].e)[0]);
		WRITE_UINT32(&f, (yyvsp[(1) - (2)].e)[1]);
		g_lingo->code2(e, f); ;}
    break;

  case 67:
#line 392 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_add); ;}
    break;

  case 68:
#line 393 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_sub); ;}
    break;

  case 69:
#line 394 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_mul); ;}
    break;

  case 70:
#line 395 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_div); ;}
    break;

  case 71:
#line 396 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_mod); ;}
    break;

  case 72:
#line 397 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_gt); ;}
    break;

  case 73:
#line 398 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_lt); ;}
    break;

  case 74:
#line 399 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_neq); ;}
    break;

  case 75:
#line 400 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_ge); ;}
    break;

  case 76:
#line 401 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_le); ;}
    break;

  case 77:
#line 402 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_and); ;}
    break;

  case 78:
#line 403 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_or); ;}
    break;

  case 79:
#line 404 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_not); ;}
    break;

  case 80:
#line 405 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_ampersand); ;}
    break;

  case 81:
#line 406 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_after); ;}
    break;

  case 82:
#line 407 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_concat); ;}
    break;

  case 83:
#line 408 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_contains); ;}
    break;

  case 84:
#line 409 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_starts); ;}
    break;

  case 85:
#line 410 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = (yyvsp[(2) - (2)].code); ;}
    break;

  case 86:
#line 411 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = (yyvsp[(2) - (2)].code); g_lingo->code1(g_lingo->c_negate); ;}
    break;

  case 87:
#line 412 "engines/director/lingo/lingo-gr.y"
    { (yyval.code) = (yyvsp[(2) - (3)].code); ;}
    break;

  case 88:
#line 413 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_intersects); ;}
    break;

  case 89:
#line 414 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_within); ;}
    break;

  case 90:
#line 417 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_printtop); ;}
    break;

  case 93:
#line 420 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_exitRepeat); ;}
    break;

  case 94:
#line 421 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeConst(0); // Push fake value on stack
							  g_lingo->code1(g_lingo->c_procret); ;}
    break;

  case 97:
#line 425 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->_handlers[*(yyvsp[(1) - (2)].s)]->u.func);
		delete (yyvsp[(1) - (2)].s); ;}
    break;

  case 98:
#line 428 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->_handlers[*(yyvsp[(1) - (2)].s)]->u.func);
		delete (yyvsp[(1) - (2)].s); ;}
    break;

  case 99:
#line 431 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code2(g_lingo->c_voidpush, g_lingo->_handlers[*(yyvsp[(1) - (1)].s)]->u.func);
		delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 100:
#line 434 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeFunc((yyvsp[(1) - (2)].s), (yyvsp[(2) - (2)].narg)); ;}
    break;

  case 101:
#line 435 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_open); ;}
    break;

  case 102:
#line 436 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code2(g_lingo->c_voidpush, g_lingo->c_open); ;}
    break;

  case 103:
#line 437 "engines/director/lingo/lingo-gr.y"
    { Common::String s("sound-"); s += *(yyvsp[(2) - (3)].s); g_lingo->codeFunc(&s, (yyvsp[(3) - (3)].narg)); ;}
    break;

  case 104:
#line 440 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_global); g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str()); delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 105:
#line 441 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_global); g_lingo->codeString((yyvsp[(3) - (3)].s)->c_str()); delete (yyvsp[(3) - (3)].s); ;}
    break;

  case 106:
#line 444 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_instance); g_lingo->codeString((yyvsp[(1) - (1)].s)->c_str()); delete (yyvsp[(1) - (1)].s); ;}
    break;

  case 107:
#line 445 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_instance); g_lingo->codeString((yyvsp[(3) - (3)].s)->c_str()); delete (yyvsp[(3) - (3)].s); ;}
    break;

  case 108:
#line 456 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_gotoloop); ;}
    break;

  case 109:
#line 457 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_gotonext); ;}
    break;

  case 110:
#line 458 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_gotoprevious); ;}
    break;

  case 111:
#line 459 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(1);
		g_lingo->code1(g_lingo->c_goto); ;}
    break;

  case 112:
#line 462 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(3);
		g_lingo->code1(g_lingo->c_goto); ;}
    break;

  case 113:
#line 465 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(2);
		g_lingo->code1(g_lingo->c_goto); ;}
    break;

  case 118:
#line 478 "engines/director/lingo/lingo-gr.y"
    { g_lingo->code1(g_lingo->c_playdone); ;}
    break;

  case 119:
#line 479 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(1);
		g_lingo->code1(g_lingo->c_play); ;}
    break;

  case 120:
#line 482 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(3);
		g_lingo->code1(g_lingo->c_play); ;}
    break;

  case 121:
#line 485 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->codeConst(2);
		g_lingo->code1(g_lingo->c_play); ;}
    break;

  case 122:
#line 515 "engines/director/lingo/lingo-gr.y"
    { g_lingo->_indef = true; g_lingo->_currentFactory.clear(); ;}
    break;

  case 123:
#line 516 "engines/director/lingo/lingo-gr.y"
    {
			g_lingo->codeConst(0); // Push fake value on stack
			g_lingo->code1(g_lingo->c_procret);
			g_lingo->define(*(yyvsp[(2) - (8)].s), (yyvsp[(4) - (8)].code), (yyvsp[(5) - (8)].narg));
			g_lingo->_indef = false; ;}
    break;

  case 124:
#line 521 "engines/director/lingo/lingo-gr.y"
    {
			g_lingo->codeFactory(*(yyvsp[(2) - (2)].s));
		;}
    break;

  case 125:
#line 524 "engines/director/lingo/lingo-gr.y"
    { g_lingo->_indef = true; ;}
    break;

  case 126:
#line 525 "engines/director/lingo/lingo-gr.y"
    {
			g_lingo->code1(g_lingo->c_procret);
			g_lingo->define(*(yyvsp[(2) - (8)].s), (yyvsp[(4) - (8)].code), (yyvsp[(5) - (8)].narg) + 1, &g_lingo->_currentFactory);
			g_lingo->_indef = false; ;}
    break;

  case 127:
#line 529 "engines/director/lingo/lingo-gr.y"
    { g_lingo->_indef = true; g_lingo->_currentFactory.clear(); ;}
    break;

  case 128:
#line 530 "engines/director/lingo/lingo-gr.y"
    { g_lingo->_ignoreMe = true; ;}
    break;

  case 129:
#line 530 "engines/director/lingo/lingo-gr.y"
    {
				g_lingo->codeConst(0); // Push fake value on stack
				g_lingo->code1(g_lingo->c_procret);
				g_lingo->define(*(yyvsp[(2) - (10)].s), (yyvsp[(4) - (10)].code), (yyvsp[(6) - (10)].narg));
				g_lingo->_indef = false;
				g_lingo->_ignoreMe = false;

				//if (*$2 != *$11) {
				//	yyerror("on vs end handler mismatch");
				//}
			;}
    break;

  case 130:
#line 542 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = 0; ;}
    break;

  case 131:
#line 543 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeArg((yyvsp[(1) - (1)].s)); (yyval.narg) = 1; ;}
    break;

  case 132:
#line 544 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeArg((yyvsp[(3) - (3)].s)); (yyval.narg) = (yyvsp[(1) - (3)].narg) + 1; ;}
    break;

  case 133:
#line 545 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeArg((yyvsp[(4) - (4)].s)); (yyval.narg) = (yyvsp[(1) - (4)].narg) + 1; ;}
    break;

  case 134:
#line 547 "engines/director/lingo/lingo-gr.y"
    { g_lingo->codeArgStore(); ;}
    break;

  case 135:
#line 551 "engines/director/lingo/lingo-gr.y"
    {
		g_lingo->code1(g_lingo->c_call);
		g_lingo->codeString((yyvsp[(1) - (3)].s)->c_str());
		inst numpar = 0;
		WRITE_UINT32(&numpar, (yyvsp[(3) - (3)].narg));
		g_lingo->code1(numpar); ;}
    break;

  case 136:
#line 559 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = 0; ;}
    break;

  case 137:
#line 560 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = 1; ;}
    break;

  case 138:
#line 561 "engines/director/lingo/lingo-gr.y"
    { (yyval.narg) = (yyvsp[(1) - (3)].narg) + 1; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2694 "engines/director/lingo/lingo-gr.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 564 "engines/director/lingo/lingo-gr.y"


