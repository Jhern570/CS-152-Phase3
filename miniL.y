/* cs152-miniL phase3 */
%{
#define YY_NO_INPUT
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char *msg);
%}

%union{
  /* put your types here */
	int num;
	char* id;

	bool param_flag = false;
	bool local_flag = false;


	vector<string>funct_;
	vector<string>param_;
	vector<string>var_;
	vector<string>type_;
}

%error-verbose
%locations

/* %start program */
%start Program
%token<id> IDENT
%token<num> NUMBER
%token FUNCTION
%token BEGIN_PARAMS
%token END_PARAMS
%token BEGIN_LOCALS
%token END_LOCALS
%token BEGIN_BODY
%token END_BODY
%token INTEGER
%token ARRAY
%token OF
%token IF
%token THEN
%token ENDIF
%token ELSE
%token WHILE
%token DO
%token FOR
%token BEGINLOOP
%token ENDLOOP
%token CONTINUE
%token BREAK
%token READ
%token WRITE
%token NOT
%token TRUE
%token FALSE
%token AND
%token OR
%token RETURN
%token SUB
%token ADD
%token MULT
%token DIV
%token MOD
%token EQ
%token NEQ
%token LT
%token GT
%token LTE
%token GTE
%token SEMICOLON
%token COLON
%token COMMA
%token L_PAREN
%token R_PAREN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token ASSIGN
%token equal
%% 

  /* write your rules here */
Program:	Functions { };

Functions:	Funct Functions { }
		| /* empty */ { }
		;

Funct:		FUNCTION Identifier {
			string func_name = $2;
			fuct_.push_back(func_name);
			cout << "func " << func_name << endl;					 	
		}
		SEMICOLON BEGIN_PARAMS{
			param_flag = true;
		}
		Declaration END_PARAMS BEGIN_LOCALS Declaration END_LOCALS BEGIN_BODY Statement END_BODY {
	        		
		}
		;

Declaration: 	Declarations SEMICOLON Declaration 
		| /* empty */ { }
		;
 
Declarations: 	Identifier COLON Declare-Type
		;

Declare-Type:	INTEGER {  }
		| ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER 
		{ }
		;


Statement:	Statements SEMICOLON Statement { }
		| /* empty */ {  }
		;

Statements:	Var ASSIGN Expression {}
		| IF BoolExp THEN Statement Else-State ENDIF {}
		| WHILE BoolExp BEGINLOOP Statement ENDLOOP {}
		| DO BEGINLOOP Statement ENDLOOP WHILE BoolExp {}
		| READ Var {}
		| WRITE Var {}
		| CONTINUE { }
		| BREAK { }
		| RETURN Expression {}
		;

Else-State:	ELSE Statement {}
		| /* empty */ {}
		;	

BoolExp: 	NOT BoolExp {}
		| Expression Comp Expression {}
		;

Comp: 		EQ { printf("Comp -> EQ\n"); }
		| NEQ { printf("Comp -> NEQ\n"); }
		| LT { printf("Comp -> LT\n"); }
		| GT { printf("Comp -> GT\n"); }
		| LTE { printf("Comp -> LTE\n"); }
		| GTE { printf("Comp -> GTE\n"); }
		;

Expression: 	MultExp Exp {}
		;

Exp:		addOp MultExp {}
		| /* empty */ {}
		;

addOp:		ADD {}
		| SUB {}
		;

MultExp: 	Term  Exp-Mult {}
		;

Exp-Mult:	multOp Term {}
		| /* empty */ {}
		;

multOp:		MULT {}
		| DIV {}
		| MOD {}
		;

Term: 		Var {}
		| NUMBER {}
		| L_PAREN Expression R_PAREN {}
		| Identifier L_PAREN Exp-Paren R_PAREN {} 
		;

Exp-Paren: 	Expression Exp-Comma {}
		;

Exp-Comma:	COMMA Exp-Paren { }
		| /* empty */ { }
		; 

Var: 		Identifier {}
		| Identifier L_SQUARE_BRACKET Expression  R_SQUARE_BRACKET {}
		;

Identifier: 	IDENT {
		$$ = $1;
		if(param_flag){
			param_.push_back(*($1));
		}
		if(local_flag){
			local_.push_back(*($1));
		}
		}; 
		
		
%% 

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
    return 1;
}

void yyerror(const char *msg) {
    /* implement your error handling */
  extern int line;
  extern int col;
  extern char* yytext;
  printf("\n%s Error: On line %d, column %d: %s \n", msg, line, col, yytext);
    
}
