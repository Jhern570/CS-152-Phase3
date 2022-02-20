/* cs152-miniL phase3 */
%{
#define YY_NO_INPUT
#include <iostream>
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
	
int temp_counter = 0;

std::vector<string>funct_;
std::vector<string>param_;
std::vector<string>var_;
std::vector<string>type_;
std::vector<string>temp_;
std::vector<int>temp_value;


string create_temp();

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

Functions getFunction(){
	int last = symbol_table.size() - 1;
       	return symbol_table.at(last);
}

bool find(std::string str){
	Functions funct = getFunction();
        for(vector<Symbols>::iterator it = funct.decla.begin(); it != funct.decla.end(); it++){
        	Symbols s = *it;
                if(s.name == str){
                	return true;
                }
         }
         return false;
}

void addFunction(std::string str){
	Functions f;
        f.name = str;
        symbol_table.push_back(f);
}

void addSymbol(std::string str, Types t){
 	Symbols s;
        s.name = str;
        s.type = t;
        Functions f = getFunction();
        f.decla.push_back(s);
 }

struct CodeNode{
	string name;
	string code;
	bool arr;
};	
%}


%union{
  /* put your types here */
	int num;
	char *id;
	struct CodeNode* code_node;			
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
%type<code_node> Identifier Var Term MultExp Statements Expression Statement Declarations Declaration 

%% 

  /* write your rules here */
Program:	Functions { };

Functions:	Funct Functions { }
		| /* empty */ { }
		;

Funct:		FUNCTION Identifier {
			cout << "func " << $2->name << endl;					 	
		}
		SEMICOLON BEGIN_PARAMS Declaration END_PARAMS BEGIN_LOCALS Declaration END_LOCALS BEGIN_BODY Statement END_BODY 
		{
	        	CodeNode* node = new CodeNode;
			
			node->code += $6->code + $9->code + $12->code + "endfunc\n\n";
			
			cout << node->code;
			
		}
		;

Declaration: 	Declarations SEMICOLON Declaration{
			CodeNode* node = new CodeNode;
			node->code += $1->code + $3->code;
			$$ = node;
		} 
		| /* empty */ {
			CodeNode* node = new CodeNode;
                        $$ = node;
		}
		;
 
Declarations: 	Identifier COLON INTEGER {
			CodeNode*  node = new CodeNode;
			node->name = $1->name;
			node->code += ". " + $1->name + "\n";
			/*addSymbol($1->name, Integer);*/
			$$ = node;
			
		} 
		| Identifier COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER{
			cout << ".[] " << $1->name << ", " << $5 << endl;			
		}	
		;

Statement:	Statements SEMICOLON Statement {
			CodeNode* node = new CodeNode;
			
			node->code += $1->code + $3->code;
			$$ = node;
		}
		| /* empty */ {
			CodeNode* node = new CodeNode;
			$$ = node;
		}
		;

Statements:	Var ASSIGN Expression {
			string var = $1->name;
			
			/*if(!find(var)){
				cout << "Error. Variable not declared" << endl;
			}*/

			CodeNode* node = new CodeNode;
			
			node->code = $1->code + $3->code;
			
			string temp = $3->name;

			if($1->arr && $3->arr){
			}
			else if($1->arr){
			}
			else if($3->arr){
			}
			else{
				node->code += "= ";
			} 

			node->code += $1->name + ", " + temp + "\n";
			
			$$ = node;
				 				
					
					
		}
		| IF BoolExp THEN Statement Else-State ENDIF { }
		| WHILE BoolExp BEGINLOOP Statement ENDLOOP { }
		| DO BEGINLOOP Statement ENDLOOP WHILE BoolExp { }
		| READ Var {}
		| WRITE Var {
			CodeNode* node = new CodeNode;
			node->code += $2->code + ".> " + $2->name + "\n";
			$$ = node;  
		}
		| CONTINUE { }
		| BREAK { }
		| RETURN Expression { }
		;

Else-State:	ELSE Statement { }
		| /* empty */ { }
		;	

BoolExp: 	NOT BoolExp {  }
		| Expression Comp Expression { }
		;

Comp: 		EQ 
		| NEQ 
		| LT 
		| GT 
		| LTE 
		| GTE 
		;

Expression: 	MultExp { 
			CodeNode* node = new CodeNode;
			node->name = $1->name;
			node->code = $1->code;
			$$ = $1;
	 	}
		| MultExp ADD Expression{
			string temp = create_temp();
			CodeNode* node = new CodeNode;

			node->name = strdup(temp.c_str());
			node->code += $1->code + $3->code + ". " + node->name + "\n" + "+ " + temp + ", " + $1->name + ", "+ $3->name + "\n";
			$$ = node;  
			

		}
		| MultExp SUB Expression{
			string temp = create_temp();
                        CodeNode* node = new CodeNode;

                        node->name = strdup(temp.c_str());
                        node->code += $1->code + $3->code + ". " + node->name + "\n" + "- " + temp + ", " + $1->name + ", "+ $3->name + "\n";
                        $$ = node;
		} 
		;

/*addOp:		ADD {
			
		}
		| SUB { }
		;*/

MultExp: 	Term {

			$$ = $1;
		 	
		} 
		| Term MULT MultExp {
			string temp = create_temp();
                        CodeNode* node = new CodeNode;

                        node->name = strdup(temp.c_str());
                        node->code += $1->code + $3->code + ". " + node->name + "\n" + "* " + temp + ", " + $1->name + ", "+ $3->name + "\n";
                        $$ = node;
		}
		| Term DIV MultExp { 
			string temp = create_temp();
                        CodeNode* node = new CodeNode;

                        node->name = strdup(temp.c_str());
                        node->code += $1->code + $3->code + ". " + node->name + "\n" + "/ " + temp + ", " + $1->name + ", "+ $3->name + "\n";
                        $$ = node;
		}
		| Term MOD MultExp {
			string temp = create_temp();
                        CodeNode* node = new CodeNode;

                        node->name = strdup(temp.c_str());
                        node->code += $1->code + $3->code + ". " + node->name + "\n" + "% " + temp + ", " + $1->name + ", "+ $3->name + "\n";
                        $$ = node;
		}
		;


		
Term: 		Var {
			$$ = $1;	 
		}
		| NUMBER {
			CodeNode* node = new CodeNode;
                        std::string str = to_string($1);
			node->name = str;
			node->code = "";
			$$ = node;
		}
		| L_PAREN Expression R_PAREN {  }
		| Identifier L_PAREN Exp-Paren R_PAREN { } 
		;

Exp-Paren: 	Expression Exp-Comma { }
		;

Exp-Comma:	COMMA Exp-Paren { }
		| /* empty */ { }
		; 

Var: 		Identifier {
			$$ = $1;
		}
		| Identifier L_SQUARE_BRACKET Expression  R_SQUARE_BRACKET { }
		;

Identifier: 	IDENT {
			CodeNode* node = new CodeNode;
			node->code = "";
			node->name = $1;	
			$$ = node;
		}
		; 
		
		
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

string create_temp(){
	
	string temp = "_temp" + to_string(temp_counter++);
	return temp;
}

int yyerror(string msg) {
    /* implement your error handling */
  extern int line;
  extern int col;
  extern char* yytext;
  cerr << msg << " Error: On line " << line << ", column " << col << ": " << yytext << endl;
  exit(1);
    
}

int yyerror(const char *msg){
	return yyerror(string(msg));
}
