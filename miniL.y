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

Declare-Type:	INTEGER { printf("Declare-Type -> INTEGER\n"); }
		| ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER 
		{ printf("Declaration -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n"); }
		;


Statement:	Statements SEMICOLON Statement { printf("Statement -> Statements SEMICOLON Statement\n"); }
		| /* empty */ { printf("Statement -> epsilon\n"); }
		;

Statements:	Var ASSIGN Expression {printf("Statement -> Var ASSIGN Expression\n"); }
		| IF BoolExp THEN Statement Else-State ENDIF { printf("Statement -> IF BoolExp THEN Statement Else-State ENDIF\n"); }
		| WHILE BoolExp BEGINLOOP Statement ENDLOOP { printf("Statement -> WHILE BoolExp BEGINLOOP Statement ENDLOOP\n"); }
		| DO BEGINLOOP Statement ENDLOOP WHILE BoolExp { printf("Statement -> DO BEGINLOOP Statement ENDLOOP WHILE BoolExp\n"); }
		| READ Var { printf("Statement -> READ Var\n"); }
		| WRITE Var { printf("Statement -> WRITE Var\n"); }
		| CONTINUE { printf("Statement -> CONTINUE\n"); }
		| BREAK { printf("Statement -> BREAK\n"); }
		| RETURN Expression { printf("Statement -> RETURN Expression\n"); }
		;

Else-State:	ELSE Statement { printf("Else-State -> ELSE Statement\n"); }
		| /* empty */ { printf("Else-State -> epsilon\n"); }
		;	

BoolExp: 	NOT BoolExp { printf("BoolExp -> NOT BoolExp\n"); }
		| Expression Comp Expression { printf("BoolExp -> Expression Comp Expression\n"); }
		;

Comp: 		EQ { printf("Comp -> EQ\n"); }
		| NEQ { printf("Comp -> NEQ\n"); }
		| LT { printf("Comp -> LT\n"); }
		| GT { printf("Comp -> GT\n"); }
		| LTE { printf("Comp -> LTE\n"); }
		| GTE { printf("Comp -> GTE\n"); }
		;

Expression: 	MultExp Exp { printf("Expression -> MultExp Exp\n"); }
		;

Exp:		addOp MultExp { printf("Exp -> addOp MultExp\n"); }
		| /* empty */ { printf("Exp -> epsilon\n"); }
		;

addOp:		ADD { printf("addOp -> ADD\n"); }
		| SUB { printf("addOp -> SUB\n"); }
		;

MultExp: 	Term  Exp-Mult { printf("MultExp -> Term Exp-Mult\n"); }
		;

Exp-Mult:	multOp Term { printf("Exp-Mult -> multOp Term\n"); }
		| /* empty */ { printf("Exp-Mult -> epsilon\n"); }
		;

multOp:		MULT { printf("multOp -> MULT\n"); }
		| DIV { printf("multOp -> DIV\n"); }
		| MOD { printf("multOp -> MOD\n"); }
		;

Term: 		Var { printf("Term -> Var\n"); }
		| NUMBER { printf("Term -> NUMBER %d\n", $1); }
		| L_PAREN Expression R_PAREN { printf("Term -> L_PAREN EXPRESSINO R_PAREN\n"); }
		| Identifier L_PAREN Exp-Paren R_PAREN { printf("Term -> IDENT L-PAREN Exp-Paren R_PAREN\n"); } 
		;

Exp-Paren: 	Expression Exp-Comma { printf("Exp-Paren -> Expression Exp-Paren\n"); }
		;

Exp-Comma:	COMMA Exp-Paren { printf("Exp-Comma -> COMMA Exp-Paren\n"); }
		| /* empty */ { printf("Exp-Comma -> epsilon\:wn"); }
		; 

Var: 		Identifier { printf("Var -> Identifier\n"); }
		| Identifier L_SQUARE_BRACKET Expression  R_SQUARE_BRACKET { printf("Var -> Identifier L_SQUARE_BRACKET Expression R_SQUARE_BRACKET\n"); }
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
