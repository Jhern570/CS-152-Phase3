/* cs152-miniL phase3 */
%{
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
stack<string> continue_stack;

vector<string> reserved_words = {"TRUE","function", "beginparams", "endparams", "beginlocals", "endlocals", "integer", "array", "of", "they", "beginbody", "endbody", "beginloop", "endloop", "if", "endif", "continue", "break", "while", "else", "read", "do", "write", "not", "true", "false", "return"};

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

bool find_reserved_word(string str){
	for(int i = 0; i < reserved_words.size(); i++){
		if(str == reserved_words[i]){
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
%left SUB ADD MULT DIV MOD
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
%type<code_node> Identifier Var Term MultExp Statements Expression Statement Declarations Declaration Funct Exp-Paren
%type<code_node> Declar-Param Declar-Params Else-State BoolExp Comp

%% 
  /* write your rules here */		

Program:	Functions {
			if(!find_function_name("main")){
                                yyerror("Error. Function main name not declared\n");
                        }
			
		}			
		;

Functions:	Funct Functions { }
		| /* empty */ { }
		;

Funct:		FUNCTION Identifier {
			/* CHECK IF SYMBOL TABLE IS EMPTY. IF TRUE, THEN AUTOMATICALLY ADD THE FIRST FUNCTION
			   IF FALSE, CHECK THAT IDENTIFIER IS NOT ALREADY BEING USED*/
			if(symbol_table.empty()){
				
				addFunction($2->name);
				out <<  "func " << $2->name << endl;
			}
			else{
				if(find_function_name($2->name)){
					cerr << "Error. Funciton already declared" << endl; 
				}
				else if(find_reserved_word($2->name)){
					string str = "Variable " + $2->name + " is a reserved word\n";
                                	yyerror(str.c_str());
				}	
				else{
					addFunction($2->name);
					out <<  "func " << $2->name << endl;
				}
			}					 	
		}
		SEMICOLON BEGIN_PARAMS Declar-Param END_PARAMS BEGIN_LOCALS Declaration END_LOCALS BEGIN_BODY Statement END_BODY 
		{
	        	CodeNode* node = new CodeNode;
			if(!continue_stack.empty()){
                                cerr << "Error. Continue not declared inside loop\n";
                        }
			node->code += $6->code + $9->code + $12->code + "endfunc\n\n";
			
		        	
			out << node->code;
			param_counter = -1;	
		}
		;

Declar-Param:    Declar-Params SEMICOLON Declar-Param{
                        CodeNode* node = new CodeNode;
                        node->code += $1->code + "= " + $1->name + ", $" + to_string(param_counter--) + "\n" + $3->code;
                        $$ = node;
                }
                | /* empty */ {
                        CodeNode* node = new CodeNode;
                        $$ = node;
                }
                ;

Declar-Params:   Identifier COLON INTEGER {
			if(find($1->name)){
				string str = "Variable " + $1->name + " has already been declared as a parameter\n";
				yyerror(str.c_str());
			}
			if(find_reserved_word($1->name)){
				string str = "Variable " + $1->name + " is a reserved word\n";
				/*yyerror(str.c_str());*/
				cerr << str;
			}
			addSymbol($1->name, Integer);
			param_counter++;
                        CodeNode*  node = new CodeNode;
                        node->name = $1->name;
                        node->code += ". " + $1->name + "\n";
                       
                        $$ = node;

                }
                | Identifier COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER{
			   if(find($1->name)){
                                string str = "Array variable " + $1->name + " has already been declared as a parameter\n";
                                yyerror(str.c_str());
                           }
			   if(find_reserved_word($1->name)){
                                string str = "Variable " + $1->name + " is a reserved word\n";
                                yyerror(str.c_str());
                           }
                           addSymbol($1->name, Array);
                           CodeNode* node = new CodeNode;
                           node->code += ".[] " + $1->name + ", " + to_string($5) + "\n";
                           $$ = node;
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
			if(find($1->name)){
                                string str = "Variable " + $1->name + " has already been declared\n";
                                yyerror(str.c_str());
                        }
                        addSymbol($1->name, Integer);

			
			CodeNode*  node = new CodeNode;
			node->name = $1->name;
			node->code += ". " + $1->name + "\n";
			$$ = node;
			
		} 
		| Identifier COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER{
			   if(find($1->name)){
                                string str = "Variable " + $1->name + " has already been declared\n";
                                yyerror(str.c_str());
                           }
			   if($5 <= 0){
                                if($5 == 0){
					cerr << "Error. Array size cannot be 0\n";
				}
				else{
					cerr << "Error. Array size cannot be less then 0\n";
				}
				
                           }
                           addSymbol($1->name, Array);
			   CodeNode* node = new CodeNode;
   			   node->code += ".[] " + $1->name + ", " + to_string($5) + "\n";
   			   $$ = node; 			
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
			
			node->code += $1->code + $3->code;
			
			

			
			if($1->arr){
				node->code += "[]= ";
			}
			else if($3->arr){
				node->code += "=[] ";
			}
			else{
				node->code += "= ";
			} 

			node->code += $1->name + ", " + $3->name + "\n";
			
			if($1->arr){
				string temp = create_temp();
				node->name = temp;
				node->code +=  ". " + temp + "\n";
			}
			$$ = node;
				 				
					
					
		}
		| IF BoolExp THEN Statement Else-State ENDIF { 
			CodeNode* node = new CodeNode;
			string label_begin = create_label();
			string label_after = create_label();
			node->code += $2->code + "?:= " + label_begin + ", " + $2->name + "\n" + ":= " + label_after + "\n" + ": " + label_begin + "\n" + $4->code;
			string label_end = create_label();
			node->code += ":= " + label_end + "\n"  + ": " + label_after + "\n" + $5->code + ": " + label_end + "\n"; 			
			$$ = node;
		}
		| WHILE BoolExp BEGINLOOP Statement ENDLOOP { 
			CodeNode* node = new CodeNode;
			string beginLoop = create_label();
			string loopBody = create_label();
			string endLoop = create_label();
			string code = $4->code;
			while(code.find("break") != string::npos){
				code.replace(code.find("break"), 5, endLoop);  
			}
			while(code.find("continue") != string::npos){
                                code.replace(code.find("continue"), 8, beginLoop);
                        }	
			node->code += ": " + beginLoop + "\n" + $2->code + "?:= " + loopBody + ", " + $2->name + "\n" + ":= " + endLoop + "\n" + ": " + loopBody + "\n" + code + ":= " + beginLoop + "\n" + ": " + endLoop + "\n";
			if(!continue_stack.empty()){
                                continue_stack.pop();
                                continue_stack.pop();
                        }
			$$ = node;
		}
		| DO BEGINLOOP Statement ENDLOOP WHILE BoolExp {
 			CodeNode* node = new CodeNode;
		
			string beginLoop = create_label();
			string loopBody = create_label();
			string endLoop = create_label();
			string code = $3->code;
			while(code.find("break") != string::npos){
                                code.replace(code.find("break"), 5, endLoop);
                        }			
			node->code += ": " + loopBody + "\n" + code + ": " + beginLoop + "\n" + $6->code + "?:= " + loopBody + ", "  + $6->name + "\n"  + ":= " + endLoop + "\n" + ": " + endLoop + "\n";
			if(!continue_stack.empty()){
				continue_stack.pop();
				continue_stack.pop();
			}
			$$ = node;	 
		}
		| READ Var {
			CodeNode* node = new CodeNode;
			if($2->arr){

                                node->code += $2->code + ".[]< " + $2->name + "\n";
                        }
                        else{
                                node->code += $2->code + ".< " + $2->name + "\n";
                        }
                        $$ = node;
		}
		| WRITE Var {
			CodeNode* node = new CodeNode;
			if($2->arr){
				 
				node->code += $2->code + ".[]> " + $2->name + "\n";
			}
			else{
				node->code += $2->code + ".> " + $2->name + "\n";
			}
			$$ = node;  
		}
		| CONTINUE { 
			CodeNode* node = new CodeNode;
                        string break_label = ":= continue\n";
			continue_stack.push("begin");
			continue_stack.push("continue");
                        node->code = break_label;
                        $$ = node;
		}
		| BREAK {
			CodeNode* node = new CodeNode;
			string break_label = ":= break\n"; 	
			node->code = break_label;
			$$ = node;
		}
		| RETURN Expression {
			CodeNode* node = new CodeNode;
			node->code += $2->code + "ret " + $2->name + "\n";
			$$ = node;
			
		}
		;

Else-State:	ELSE Statement {
		
			CodeNode* node = new CodeNode;
			node->code += $2->code;
			$$ = node; 
			
		}
		| /* empty */ {
			CodeNode* node = new CodeNode;
			$$ = node;
		}
		;	

BoolExp: 	NOT BoolExp {  }
		| Expression Comp Expression {
			CodeNode* node = new CodeNode;
			string temp = create_temp();
			node->name = temp;
			node->code = $1->code + $3->code + ". " + temp + "\n" + $2->name + " " + temp  + ", " + $1->name +  ", " + $3->name + "\n";
			$$ = node;
			
		}
		;

Comp: 		EQ	{
			CodeNode* node = new CodeNode;
			node->name = "== ";
			$$ = node;
			} 
		| NEQ	{
			CodeNode* node = new CodeNode;
			node->name = "!=";
			$$ = node;
			} 
		| LT  	{
			CodeNode* node = new CodeNode;
			node->name = "< ";
			$$ = node;
			}
		| GT 	{
			CodeNode* node = new CodeNode;
			node->name = "> ";
			$$ = node;
			}
		| LTE 	{
			CodeNode* node = new CodeNode;
			node->name = "<= ";
			$$ = node;
			}
		| GTE 	{
			CodeNode* node = new CodeNode;
			node->name = ">= ";
			$$ = node;

	}
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



MultExp: 	Term {

			$$ = $1;
		 	
		} 
		| Term MULT MultExp {
			string temp = create_temp();
                        CodeNode* node = new CodeNode;

                        node->name = strdup(temp.c_str());
                        node->code += $1->code + $3->code + ". " + node->name + "\n" + "* " + temp + ", " + $1->name + ", " + $3->name + "\n";
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
			CodeNode* node = new CodeNode;
			if($1->arr){
				string temp = create_temp();
				node->code += $1->code + ". " + temp + "\n" + "=[] " + temp + ", " + $1->name + "\n";
				$$->arr = false;
				node->name = temp;
				
			} 
			else{
				node->name = $1->name;
				node->code = $1->code;
			}
			$$ = node;
		}
		| NUMBER {
			CodeNode* node = new CodeNode;
                        std::string str = to_string($1);
			node->name = str;
 			node->arr = false;
			node->code = "";
			$$ = node;
		}
		| SUB NUMBER {
			CodeNode* node = new CodeNode;
			string str = to_string($2);
			node->name = "-" + str;
			node->code += "-" + str + "\n";
			$$ = node; 
		}
		| L_PAREN Expression R_PAREN {  
			CodeNode* node = new CodeNode;
			node->name = $2->name;
			node->code += $2->code;
			$$ = node;
		}
		| Identifier L_PAREN Exp-Paren R_PAREN {
			if(!find_function_name($1->name)){
				yyerror("Function name is not declared\n");
			}
			CodeNode* node = new CodeNode;
			string temp = create_temp();
			node->name = temp;
			node->code += $3->code + ". " + temp + "\n" + "call " + $1->name + ", " + temp + "\n";  
			$$ = node; 
		} 
		;

Exp-Paren: 	Expression  {
			CodeNode* node = new CodeNode;
			node->code += $1->code + "param " + $1->name + "\n";
			$$ = node;
		}
		| Expression COMMA Exp-Paren{
			CodeNode* node = new CodeNode;
                        node->code += $1->code + "param " + $1->name + "\n" + $3->code;
                        $$ = node;
		}
		| /* empty */ {
			CodeNode* node = new CodeNode;
			$$ = node;
		}
		; 

Var: 		Identifier {
			string str = "Variable " + $1->name + " not declared\n";
			
			if(!find($1->name)){
				yyerror(str.c_str());
			}
			CodeNode* node = new CodeNode;
			node->name = $1->name;
			node->arr = false;
			node->code = "";
			$$ = node;
		}
		| Identifier L_SQUARE_BRACKET Expression  R_SQUARE_BRACKET {
			string str = "Array variable " + $1->name + " not declared\n";
			if(!find($1->name)){
                                yyerror(str.c_str());
                        }
			if($3->name[0] == '-'){
				
				cerr << "Error. Array size cannot be less then 0\n";
			}
			CodeNode* node = new CodeNode;
			node->name = $1->name + ", " + $3->name;
			node->code += $3->code;
			node->arr = true;
		 	$$ = node;	
 		}
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
  cerr << msg << "\nError: On line " << line << ", column " << col << ": " << yytext << endl;
  
    
}

int yyerror(const char *msg){
	return yyerror(string(msg));
}
