%{
  #include <stdio.h>
  #include <stdlib.h>
  FILE *yyin;
  int yylex (void);
  void yyerror (char const *s);
  extern int line_num;
%}

%union {
	int number;
	char * value;
}

%token declaration_list
%token statement_list
%token <value> INTEGER
%token <value> BOOLEAN ID TYPE STRING
%token ETOK
%token PRINT PRINTLN READ
%token IF ELSE FOR WHILE GOTO
%token <value> COMMA SC COL
%token OB CB OSB CSB OP CP
%token <value> COND_AND COND_OR NOT
%token <value> ADD SUB MUL DIV MOD
%token <value> LT GT LE GE
%token <value> EQUAL NOT_EQUAL
%token <value> EQ ADDEQ SUBEQ
/*%define parse.error verbose*/
/* -------------	Left Precedence		------------- */


%left EQUAL NOT_EQUAL
%left COND_AND COND_OR
%left LT GT LE GE
%left ADD SUB
%left MUL DIV MOD
%nonassoc NOT

%%
program:	dl cl
	;

dl: 
	declaration_list declaration_Block 
	;

cl: 
	statement_list statement_Block
	;

declaration_Block: 
	OB Variable_declarations CB
	;

statement_Block: 
	OB Statements CB
	;

Variable_declarations:
	/*Empty*/
	| Variable_declaration SC Variable_declarations 
	;

Variable_declaration:
	TYPE Var_dec_name Var_dec_names
	;
Var_dec_names:
	/*Empty*/
	| COMMA Var_dec_name Var_dec_names 
	;
Var_dec_name:
	ID
	| ID OSB INTEGER CSB 
	;

Statements: /*Empty*/
	| Statements Statement
	| Statements ID COL Statement 
	;

Statement:
	Assignment SC
	| For_Statement
	| While_Statement
	| Conditional
	| GoTo_Statement SC
	| Read_Statement SC
	| Print_Statement SC
	| PrintLN_Statement SC
	;
Read_Statement:
	READ Variable
	;
Print_Statement:
	PRINT Print_Var Print_Seq
	;
PrintLN_Statement:
	PRINTLN Print_Var Print_Seq
	;
Print_Seq:
	/*Empty*/
	| COMMA Print_Var Print_Seq 
	;
Print_Var:
	Variable
	| STRING
	;

For_Statement:
	FOR Variable EQ Literal COMMA Literal COMMA Literal statement_Block
	| FOR Variable EQ Literal COMMA Literal statement_Block
	;

While_Statement:
	WHILE Expression statement_Block
	;

GoTo_Statement:
	GOTO ID IF Expression
	|GOTO ID
	;

Conditional:
	IF Expression statement_Block ELSE statement_Block 
	| IF Expression statement_Block 
	;

Assignment:
	Variable EQ Expression
	| Variable SUBEQ Expression
	| Variable ADDEQ Expression
	;

Variable:
	ID
	| ID OSB Expression CSB
	;

Literal:
	INTEGER
	| ID
	| ID OSB Expression CSB
	;

Expression:
	Literal
	| Expression ADD Expression 
	| Expression SUB Expression 
	| Expression MUL Expression 
	| Expression DIV Expression 
	| Expression MOD Expression 
	| Expression LT Expression 
	| Expression GT Expression 
	| Expression LE Expression 
	| Expression GE Expression 
	| Expression EQUAL Expression 
	| Expression NOT_EQUAL Expression 
	| Expression COND_OR Expression 
	| Expression COND_AND Expression 
	| SUB Expression 
	| NOT Expression 
	| OP Expression CP 
	;

%%

int main(int argc, char *argv[])
{
	if (argc == 1 ) {
		fprintf(stderr, "Correct usage: bcc filename\n");
		exit(1);
	}

	if (argc > 2) {
		fprintf(stderr, "Passing more arguments than necessary.\n");
		fprintf(stderr, "Correct usage: bcc filename\n");
	}

	yyin = fopen(argv[1], "r");

	yyparse();
}


void yyerror(const char *s) {
	fprintf(stderr,"EEK, parse error on line %d!  Message: %s\n",line_num,s);
	// might as well halt now:
	exit(-1);
}