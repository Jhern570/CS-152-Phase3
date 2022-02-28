/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "miniL.y" /* yacc.c:339  */

#define YY_NO_INPUT
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

extern int yylex();
extern int yyparse();
extern FILE *yyin;

int yyerror(const char *msg);

int param_counter = -1;	
int temp_counter = 0;
int label_counter = 0;
stringstream out;

std::vector<string>funct_;
std::vector<string>param_;
std::vector<string>var_;
std::vector<string>type_;
std::vector<string>temp_;
std::vector<int>temp_value;


string create_temp();
string create_label();
enum Types { Integer, Array };

struct Symbols{
	std::string name;
	Types type;
};

struct Functions{
	std::string name;
        vector<Symbols> decla;
};

std::vector<Functions>symbol_table;

Functions* getFunction(){
	int last = symbol_table.size() - 1;
       	return &symbol_table[last];
}

bool find(std::string str){
	Functions* funct = getFunction();
	for(int i = 0; i < funct->decla.size(); i++){
                if(funct->decla[i].name == str){
                	return true;
                }
         }
         return false;
}

bool find_function_name(std::string str){
	

	for(int i = 0; i < symbol_table.size(); i++){
		if(symbol_table[i].name == str){
			return true;
		}
	}
	return false;
}

void addFunction(std::string &str){
	Functions f;
        f.name = str;
        symbol_table.push_back(f);
}

void addSymbol(std::string &str, Types t){
 	Symbols s;
        s.name = str;
        s.type = t;
        Functions* f = getFunction();
        f->decla.push_back(s);
 }

/*void print_symbol_table(void) {
  if(symbol_table.empty()){
	printf("SYMBOL TABLE EMPTY\n");
  }
  printf("symbol table:\n");
  printf("--------------------\n");
  for(int i=0; i<symbol_table.size(); i++) {
    printf("function: %s\n", symbol_table[i].name.c_str());
    for(int j=0; j<symbol_table[i].decla.size(); j++) {
      printf("  locals: %s\n", symbol_table[i].decla[j].name.c_str());
    }
  }
  printf("--------------------\n");
}*/

struct CodeNode{
	string name;
	string code;
	bool arr;
};	

#line 178 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    NUMBER = 259,
    FUNCTION = 260,
    BEGIN_PARAMS = 261,
    END_PARAMS = 262,
    BEGIN_LOCALS = 263,
    END_LOCALS = 264,
    BEGIN_BODY = 265,
    END_BODY = 266,
    INTEGER = 267,
    ARRAY = 268,
    OF = 269,
    IF = 270,
    THEN = 271,
    ENDIF = 272,
    ELSE = 273,
    WHILE = 274,
    DO = 275,
    FOR = 276,
    BEGINLOOP = 277,
    ENDLOOP = 278,
    CONTINUE = 279,
    BREAK = 280,
    READ = 281,
    WRITE = 282,
    NOT = 283,
    TRUE = 284,
    FALSE = 285,
    AND = 286,
    OR = 287,
    RETURN = 288,
    SUB = 289,
    ADD = 290,
    MULT = 291,
    DIV = 292,
    MOD = 293,
    EQ = 294,
    NEQ = 295,
    LT = 296,
    GT = 297,
    LTE = 298,
    GTE = 299,
    SEMICOLON = 300,
    COLON = 301,
    COMMA = 302,
    L_PAREN = 303,
    R_PAREN = 304,
    L_SQUARE_BRACKET = 305,
    R_SQUARE_BRACKET = 306,
    ASSIGN = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 115 "miniL.y" /* yacc.c:355  */

  /* put your types here */
	int num;
	char *id;
	struct CodeNode* code_node;			

#line 278 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 309 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,   179,   179,   187,   188,   191,   191,   221,   226,   232,
     246,   258,   263,   270,   284,   296,   302,   308,   344,   353,
     368,   369,   380,   391,   397,   403,   411,   418,   424,   425,
     435,   440,   445,   450,   455,   460,   468,   474,   484,   496,
     501,   509,   517,   529,   544,   551,   557,   569,   574,   579,
     585,   597,   610
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "NUMBER", "FUNCTION",
  "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY",
  "END_BODY", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "FOR", "BEGINLOOP", "ENDLOOP", "CONTINUE", "BREAK",
  "READ", "WRITE", "NOT", "TRUE", "FALSE", "AND", "OR", "RETURN", "SUB",
  "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE",
  "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "ASSIGN", "$accept", "Program", "Functions", "Funct",
  "$@1", "Declar-Param", "Declar-Params", "Declaration", "Declarations",
  "Statement", "Statements", "Else-State", "BoolExp", "Comp", "Expression",
  "MultExp", "Term", "Exp-Paren", "Var", "Identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,    10,    16,   -58,    -2,   -58,   -58,   -58,   -58,   -20,
      21,    10,    24,   -11,    -5,    37,    10,    31,    10,   -58,
     -58,     7,    40,    17,    18,    62,    57,    10,    39,    22,
      66,   -58,   -58,    25,    54,     5,     5,    49,   -58,   -58,
      10,    10,     2,    61,    29,    27,    30,    73,    70,   -58,
       5,     2,    71,    67,    20,   -17,   -58,   -26,    72,    66,
     -58,   -58,   -58,   -58,    66,     2,     2,    32,   -58,   -58,
      46,    66,   -58,   -58,   -58,   -58,   -58,   -58,     2,     2,
       2,     2,     2,     2,     2,    66,    74,   -58,   -58,    38,
      82,   -58,    80,   -58,   -58,   -58,   -58,   -58,   -58,    53,
      52,    79,    84,   -58,    93,    66,    95,     2,   -58,   -58,
       5,   -58,   -58,   -58,   -58,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     4,    52,     5,     1,     3,     0,
       0,     8,     0,     0,     0,     0,     8,     0,    12,     7,
       9,     0,     0,     0,     0,     0,     0,    12,     0,     0,
      16,    11,    13,     0,     0,     0,     0,     0,    23,    24,
       0,     0,     0,     0,     0,     0,    50,     0,     0,    44,
       0,     0,     0,     0,    36,    39,    43,    50,     0,    16,
      21,    22,    25,     6,    16,     0,     0,     0,    10,    28,
       0,    16,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,    49,    16,     0,    15,    17,     0,
       0,    45,    27,    29,    38,    37,    40,    41,    42,    47,
       0,     0,     0,    51,     0,    16,     0,    49,    46,    19,
       0,    14,    26,    18,    48,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   109,   -58,   -58,    98,   -58,    88,   -58,   -57,
     -58,   -58,   -32,   -58,   -19,   -45,   -58,     9,   -29,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    12,    13,    22,    23,    43,
      44,   106,    52,    78,    53,    54,    55,   100,    56,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    45,    86,     1,    58,     5,    49,    87,     5,    49,
      14,    60,    61,     5,    92,    14,     7,    24,    69,    81,
      82,    83,    84,    62,    66,    10,    24,    11,   101,    46,
      45,    15,    70,    50,    16,    45,    96,    97,    98,    46,
      46,    17,    45,    20,    21,    18,    88,    89,   112,    26,
      51,    32,    33,    51,    79,    80,    45,    25,    46,    93,
      94,    95,    27,    46,    28,    99,    29,    30,    48,     5,
      46,    59,    63,    34,    64,    47,    45,    67,   115,    65,
      66,    35,    68,    90,    46,    36,    37,    71,    99,   103,
      38,    39,    40,    41,    85,    91,   104,   102,   105,    42,
     107,   108,   109,   110,    46,   111,    72,    73,    74,    75,
      76,    77,   113,     8,    19,    31,   114
};

static const yytype_uint8 yycheck[] =
{
       1,    30,    59,     5,    36,     3,     4,    64,     3,     4,
      11,    40,    41,     3,    71,    16,     0,    18,    50,    36,
      37,    38,    48,    42,    50,    45,    27,     6,    85,    30,
      59,     7,    51,    28,    45,    64,    81,    82,    83,    40,
      41,    46,    71,    12,    13,     8,    65,    66,   105,     9,
      48,    12,    13,    48,    34,    35,    85,    50,    59,    78,
      79,    80,    45,    64,    46,    84,     4,    10,    14,     3,
      71,    22,    11,    51,    45,    50,   105,     4,   110,    52,
      50,    15,    12,    51,    85,    19,    20,    16,   107,    51,
      24,    25,    26,    27,    22,    49,    14,    23,    18,    33,
      47,    49,    23,    19,   105,    12,    39,    40,    41,    42,
      43,    44,    17,     4,    16,    27,   107
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    54,    55,    56,     3,    72,     0,    55,    57,
      45,     6,    58,    59,    72,     7,    45,    46,     8,    58,
      12,    13,    60,    61,    72,    50,     9,    45,    46,     4,
      10,    60,    12,    13,    51,    15,    19,    20,    24,    25,
      26,    27,    33,    62,    63,    71,    72,    50,    14,     4,
      28,    48,    65,    67,    68,    69,    71,    72,    65,    22,
      71,    71,    67,    11,    45,    52,    50,     4,    12,    65,
      67,    16,    39,    40,    41,    42,    43,    44,    66,    34,
      35,    36,    37,    38,    48,    22,    62,    62,    67,    67,
      51,    49,    62,    67,    67,    67,    68,    68,    68,    67,
      70,    62,    23,    51,    14,    18,    64,    47,    49,    23,
      19,    12,    62,    17,    70,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    57,    56,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      71,    71,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,    13,     3,     0,     3,
       8,     3,     0,     3,     8,     3,     0,     3,     6,     5,
       6,     2,     2,     1,     1,     2,     2,     0,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     3,     4,     1,     3,     0,
       1,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 179 "miniL.y" /* yacc.c:1646  */
    {
			if(!find_function_name("main")){
                                yyerror("Error. Function main name not declared\n");
                        }
			
		}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 187 "miniL.y" /* yacc.c:1646  */
    { }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 188 "miniL.y" /* yacc.c:1646  */
    { }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 191 "miniL.y" /* yacc.c:1646  */
    {
			/* CHECK IF SYMBOL TABLE IS EMPTY. IF TRUE, THEN AUTOMATICALLY ADD THE FIRST FUNCTION
			   IF FALSE, CHECK THAT IDENTIFIER IS NOT ALREADY BEING USED*/
			if(symbol_table.empty()){
				
				addFunction((yyvsp[0].code_node)->name);
				out <<  "func " << (yyvsp[0].code_node)->name << endl;
			}
			else{
				if(find_function_name((yyvsp[0].code_node)->name)){
					cerr << "Error. Funciton already declared" << endl; 
				}
				else{
					addFunction((yyvsp[0].code_node)->name);
					out <<  "func " << (yyvsp[0].code_node)->name << endl;
				}
			}					 	
		}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 210 "miniL.y" /* yacc.c:1646  */
    {
	        	CodeNode* node = new CodeNode;
			
			node->code += (yyvsp[-7].code_node)->code + (yyvsp[-4].code_node)->code + (yyvsp[-1].code_node)->code + "endfunc\n\n";
			
			
			out << node->code;
			param_counter = -1;	
		}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 221 "miniL.y" /* yacc.c:1646  */
    {
                        CodeNode* node = new CodeNode;
                        node->code += (yyvsp[-2].code_node)->code + "= " + (yyvsp[-2].code_node)->name + ", $" + to_string(param_counter--) + "\n" + (yyvsp[0].code_node)->code;
                        (yyval.code_node) = node;
                }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 226 "miniL.y" /* yacc.c:1646  */
    {
                        CodeNode* node = new CodeNode;
                        (yyval.code_node) = node;
                }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 232 "miniL.y" /* yacc.c:1646  */
    {
			if(find((yyvsp[-2].code_node)->name)){
				string str = "Variable " + (yyvsp[-2].code_node)->name + " has already been declared as a parameter\n";
				yyerror(str.c_str());
			}
			addSymbol((yyvsp[-2].code_node)->name, Integer);
			param_counter++;
                        CodeNode*  node = new CodeNode;
                        node->name = (yyvsp[-2].code_node)->name;
                        node->code += ". " + (yyvsp[-2].code_node)->name + "\n";
                       
                        (yyval.code_node) = node;

                }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 246 "miniL.y" /* yacc.c:1646  */
    {
			   if(find((yyvsp[-7].code_node)->name)){
                                string str = "Array variable " + (yyvsp[-7].code_node)->name + " has already been declared as a parameter\n";
                                yyerror(str.c_str());
                           }
                           addSymbol((yyvsp[-7].code_node)->name, Array);
                           CodeNode* node = new CodeNode;
                           node->code += ".[] " + (yyvsp[-7].code_node)->name + ", " + to_string((yyvsp[-3].num)) + "\n";
                           (yyval.code_node) = node;
                }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 258 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->code += (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code;
			(yyval.code_node) = node;
		}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 263 "miniL.y" /* yacc.c:1646  */
    {
			
			CodeNode* node = new CodeNode;
                        (yyval.code_node) = node;
		}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 270 "miniL.y" /* yacc.c:1646  */
    {
			if(find((yyvsp[-2].code_node)->name)){
                                string str = "Variable " + (yyvsp[-2].code_node)->name + " has already been declared\n";
                                yyerror(str.c_str());
                        }
                        addSymbol((yyvsp[-2].code_node)->name, Integer);

			
			CodeNode*  node = new CodeNode;
			node->name = (yyvsp[-2].code_node)->name;
			node->code += ". " + (yyvsp[-2].code_node)->name + "\n";
			(yyval.code_node) = node;
			
		}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 284 "miniL.y" /* yacc.c:1646  */
    {
			   if(find((yyvsp[-7].code_node)->name)){
                                string str = "Variable " + (yyvsp[-7].code_node)->name + " has already been declared\n";
                                yyerror(str.c_str());
                           }
                           addSymbol((yyvsp[-7].code_node)->name, Array);
			   CodeNode* node = new CodeNode;
   			   node->code += ".[] " + (yyvsp[-7].code_node)->name + ", " + to_string((yyvsp[-3].num)) + "\n";
   			   (yyval.code_node) = node; 			
		}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 296 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			
			node->code += (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code;
			(yyval.code_node) = node;
		}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 302 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			(yyval.code_node) = node;
		}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 308 "miniL.y" /* yacc.c:1646  */
    {
			string var = (yyvsp[-2].code_node)->name;
			
			/*if(!find(var)){
				cout << "Error. Variable not declared" << endl;
			}*/

			CodeNode* node = new CodeNode;
			
			node->code += (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code;
			
			

			
			if((yyvsp[-2].code_node)->arr){
				node->code += "[]= ";
			}
			else if((yyvsp[0].code_node)->arr){
				node->code += "=[] ";
			}
			else{
				node->code += "= ";
			} 

			node->code += (yyvsp[-2].code_node)->name + ", " + (yyvsp[0].code_node)->name + "\n";
			
			if((yyvsp[-2].code_node)->arr){
				string temp = create_temp();
				node->name = temp;
				node->code +=  ". " + temp + "\n";
			}
			(yyval.code_node) = node;
				 				
					
					
		}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 344 "miniL.y" /* yacc.c:1646  */
    { 
			CodeNode* node = new CodeNode;
			string label_begin = create_label();
			string label_after = create_label();
			node->code += (yyvsp[-4].code_node)->code + "?:= " + label_begin + ", " + (yyvsp[-4].code_node)->name + "\n" + ":= " + label_after + "\n" + ": " + label_begin + "\n" + (yyvsp[-2].code_node)->code;
			string label_end = create_label();
			node->code += ":= " + label_end + "\n"  + ": " + label_after + "\n" + (yyvsp[-1].code_node)->code + ": " + label_end + "\n"; 			
			(yyval.code_node) = node;
		}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 353 "miniL.y" /* yacc.c:1646  */
    { 
			CodeNode* node = new CodeNode;
			string beginLoop = create_label();
			string loopBody = create_label();
			string endLoop = create_label();
			string code = (yyvsp[-1].code_node)->code;
			while(code.find("break") != string::npos){
				code.replace(code.find("break"), 5, endLoop);  
			}
			while(code.find("continue") != string::npos){
                                code.replace(code.find("continue"), 8, beginLoop);
                        }	
			node->code += ": " + beginLoop + "\n" + (yyvsp[-3].code_node)->code + "?:= " + loopBody + ", " + (yyvsp[-3].code_node)->name + "\n" + ":= " + endLoop + "\n" + ": " + loopBody + "\n" + code + ":= " + beginLoop + "\n" + ": " + endLoop + "\n";
			(yyval.code_node) = node;
		}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 368 "miniL.y" /* yacc.c:1646  */
    { }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 369 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			if((yyvsp[0].code_node)->arr){

                                node->code += (yyvsp[0].code_node)->code + ".[]< " + (yyvsp[0].code_node)->name + "\n";
                        }
                        else{
                                node->code += (yyvsp[0].code_node)->code + ".< " + (yyvsp[0].code_node)->name + "\n";
                        }
                        (yyval.code_node) = node;
		}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 380 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			if((yyvsp[0].code_node)->arr){
				 
				node->code += (yyvsp[0].code_node)->code + ".[]> " + (yyvsp[0].code_node)->name + "\n";
			}
			else{
				node->code += (yyvsp[0].code_node)->code + ".> " + (yyvsp[0].code_node)->name + "\n";
			}
			(yyval.code_node) = node;  
		}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 391 "miniL.y" /* yacc.c:1646  */
    { 
			CodeNode* node = new CodeNode;
                        string break_label = ":= continue\n";
                        node->code = break_label;
                        (yyval.code_node) = node;
		}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 397 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			string break_label = ":= break\n"; 	
			node->code = break_label;
			(yyval.code_node) = node;
		}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 403 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->code += (yyvsp[0].code_node)->code + "ret " + (yyvsp[0].code_node)->name + "\n";
			(yyval.code_node) = node;
			
		}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 411 "miniL.y" /* yacc.c:1646  */
    {
		
			CodeNode* node = new CodeNode;
			node->code += (yyvsp[0].code_node)->code;
			(yyval.code_node) = node; 
			
		}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 418 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			(yyval.code_node) = node;
		}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 424 "miniL.y" /* yacc.c:1646  */
    {  }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 425 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			string temp = create_temp();
			node->name = temp;
			node->code = (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code + ". " + temp + "\n" + (yyvsp[-1].code_node)->name + " " + temp  + ", " + (yyvsp[-2].code_node)->name +  ", " + (yyvsp[0].code_node)->name + "\n";
			(yyval.code_node) = node;
			
		}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 435 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->name = "== ";
			(yyval.code_node) = node;
			}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 440 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->name = "!=";
			(yyval.code_node) = node;
			}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 445 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->name = "< ";
			(yyval.code_node) = node;
			}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 450 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->name = "> ";
			(yyval.code_node) = node;
			}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 455 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->name = "<= ";
			(yyval.code_node) = node;
			}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 460 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->name = ">= ";
			(yyval.code_node) = node;

	}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 468 "miniL.y" /* yacc.c:1646  */
    { 
			CodeNode* node = new CodeNode;
			node->name = (yyvsp[0].code_node)->name;
			node->code = (yyvsp[0].code_node)->code;
			(yyval.code_node) = (yyvsp[0].code_node);
	 	}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 474 "miniL.y" /* yacc.c:1646  */
    {
			string temp = create_temp();
			CodeNode* node = new CodeNode;

			node->name = strdup(temp.c_str());
			node->code += (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code + ". " + node->name + "\n" + "+ " + temp + ", " + (yyvsp[-2].code_node)->name + ", "+ (yyvsp[0].code_node)->name + "\n";
			(yyval.code_node) = node;  
			

		}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 484 "miniL.y" /* yacc.c:1646  */
    {
			string temp = create_temp();
                        CodeNode* node = new CodeNode;

                        node->name = strdup(temp.c_str());
                        node->code += (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code + ". " + node->name + "\n" + "- " + temp + ", " + (yyvsp[-2].code_node)->name + ", "+ (yyvsp[0].code_node)->name + "\n";
                        (yyval.code_node) = node;
		}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 496 "miniL.y" /* yacc.c:1646  */
    {

			(yyval.code_node) = (yyvsp[0].code_node);
		 	
		}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 501 "miniL.y" /* yacc.c:1646  */
    {
			string temp = create_temp();
                        CodeNode* node = new CodeNode;

                        node->name = strdup(temp.c_str());
                        node->code += (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code + ". " + node->name + "\n" + "* " + temp + ", " + (yyvsp[-2].code_node)->name + ", " + (yyvsp[0].code_node)->name + "\n";
                        (yyval.code_node) = node;
		}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 509 "miniL.y" /* yacc.c:1646  */
    { 
			string temp = create_temp();
                        CodeNode* node = new CodeNode;

                        node->name = strdup(temp.c_str());
                        node->code += (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code + ". " + node->name + "\n" + "/ " + temp + ", " + (yyvsp[-2].code_node)->name + ", "+ (yyvsp[0].code_node)->name + "\n";
                        (yyval.code_node) = node;
		}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 517 "miniL.y" /* yacc.c:1646  */
    {
			string temp = create_temp();
                        CodeNode* node = new CodeNode;

                        node->name = strdup(temp.c_str());
                        node->code += (yyvsp[-2].code_node)->code + (yyvsp[0].code_node)->code + ". " + node->name + "\n" + "% " + temp + ", " + (yyvsp[-2].code_node)->name + ", "+ (yyvsp[0].code_node)->name + "\n";
                        (yyval.code_node) = node;
		}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 529 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			if((yyvsp[0].code_node)->arr){
				string temp = create_temp();
				node->code += (yyvsp[0].code_node)->code + ". " + temp + "\n" + "=[] " + temp + ", " + (yyvsp[0].code_node)->name + "\n";
				(yyval.code_node)->arr = false;
				node->name = temp;
				
			} 
			else{
				node->name = (yyvsp[0].code_node)->name;
				node->code = (yyvsp[0].code_node)->code;
			}
			(yyval.code_node) = node;
		}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 544 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
                        std::string str = to_string((yyvsp[0].num));
			node->name = str;
			node->code = "";
			(yyval.code_node) = node;
		}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 551 "miniL.y" /* yacc.c:1646  */
    {  
			CodeNode* node = new CodeNode;
			node->name = (yyvsp[-1].code_node)->name;
			node->code += (yyvsp[-1].code_node)->code;
			(yyval.code_node) = node;
		}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 557 "miniL.y" /* yacc.c:1646  */
    {
			if(!find_function_name((yyvsp[-3].code_node)->name)){
				yyerror("Function name is not declared\n");
			}
			CodeNode* node = new CodeNode;
			string temp = create_temp();
			node->name = temp;
			node->code += (yyvsp[-1].code_node)->code + ". " + temp + "\n" + "call " + (yyvsp[-3].code_node)->name + ", " + temp + "\n";  
			(yyval.code_node) = node; 
		}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 569 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->code += (yyvsp[0].code_node)->code + "param " + (yyvsp[0].code_node)->name + "\n";
			(yyval.code_node) = node;
		}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 574 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
                        node->code += (yyvsp[-2].code_node)->code + "param " + (yyvsp[-2].code_node)->name + "\n" + (yyvsp[0].code_node)->code;
                        (yyval.code_node) = node;
		}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 579 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			(yyval.code_node) = node;
		}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 585 "miniL.y" /* yacc.c:1646  */
    {
			string str = "Variable " + (yyvsp[0].code_node)->name + " not declared\n";
			
			if(!find((yyvsp[0].code_node)->name)){
				yyerror(str.c_str());
			}
			CodeNode* node = new CodeNode;
			node->name = (yyvsp[0].code_node)->name;
			node->arr = false;
			node->code = "";
			(yyval.code_node) = node;
		}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 597 "miniL.y" /* yacc.c:1646  */
    {
			string str = "Array variable " + (yyvsp[-3].code_node)->name + " not declared\n";
			if(!find((yyvsp[-3].code_node)->name)){
                                yyerror(str.c_str());
                        }
			CodeNode* node = new CodeNode;
			node->name = (yyvsp[-3].code_node)->name + ", " + (yyvsp[-1].code_node)->name;
			node->code += (yyvsp[-1].code_node)->code;
			node->arr = true;
		 	(yyval.code_node) = node;	
 		}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 610 "miniL.y" /* yacc.c:1646  */
    {
			CodeNode* node = new CodeNode;
			node->code = "";
			node->name = (yyvsp[0].id);	
			(yyval.code_node) = node;
		}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2211 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
  return yyresult;
}
#line 619 "miniL.y" /* yacc.c:1906  */
 

int main(int argc, char **argv) {
    if (argc >= 2) {
    	yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            yyin = stdin;
        }
    }
    else {
        yyin = stdin;
    }
    yyparse();
    ofstream file("out.mil");
    file << out.str() << endl;
    file.close();
    return 1;
}

string create_temp(){
	
	string temp = "_temp" + to_string(temp_counter++);
	return temp;
}
string create_label(){
	string label = "_label"+to_string(label_counter++);
	return label;
}
int yyerror(string msg) {
    /* implement your error handling */
  extern int line;
  extern int col;
  extern char* yytext;
  cerr << msg << "Error: On line " << line << ", column " << col << ": " << yytext << endl;
  
    
}

int yyerror(const char *msg){
	return yyerror(string(msg));
}
