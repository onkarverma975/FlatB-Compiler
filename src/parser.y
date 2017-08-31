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
%define parse.error verbose
/* -------------	Left Precedence		------------- */


%left EQUAL NOT_EQUAL
%left COND_AND COND_OR
%left LT GT LE GE
%left ADD SUB
%left MUL DIV MOD

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
	| Arith_Expression SC
	| Bool_Expression SC
	;
Read_Statement:
	READ Variable Read_Seq
	;
Read_Seq:
	/*Empty*/
	| COMMA Variable Read_Seq 
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
	FOR Variable EQ Arith_Expression COMMA Arith_Expression COMMA Arith_Expression statement_Block
	| FOR Variable EQ Arith_Expression COMMA Arith_Expression statement_Block
	;

While_Statement:
	WHILE Bool_Expression statement_Block
	;

GoTo_Statement:
	GOTO ID IF Bool_Expression
	|GOTO ID
	;

Conditional:
	IF Bool_Expression statement_Block ELSE statement_Block 
	| IF Bool_Expression statement_Block 
	;

Assignment:
	Variable EQ Arith_Expression
	| Variable SUBEQ Arith_Expression
	| Variable ADDEQ Arith_Expression
	;

Variable:
	ID
	| ID OSB Arith_Expression CSB
	;

Literal:
	INTEGER
	| ID
	| ID OSB Arith_Expression CSB
	;
/*
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
	| OP Expression CP 
	;
*/
Arith_Expression:
	Literal
	| Arith_Expression ADD Arith_Expression 
	| Arith_Expression SUB Arith_Expression 
	| Arith_Expression MUL Arith_Expression 
	| Arith_Expression DIV Arith_Expression 
	| Arith_Expression MOD Arith_Expression 
	| SUB Arith_Expression 
	| OP Arith_Expression CP 
	;


Bool_Literal:
	BOOLEAN
	| Arith_Expression LT Arith_Expression
	| Arith_Expression GT Arith_Expression
	| Arith_Expression LE Arith_Expression
	| Arith_Expression GE Arith_Expression
	| Arith_Expression EQUAL Arith_Expression
	| Arith_Expression NOT_EQUAL Arith_Expression
	;

Bool_Expression:
	Bool_Literal
	| Bool_Expression COND_OR Bool_Expression
	| Bool_Expression COND_AND Bool_Expression
	| Bool_Expression EQUAL Bool_Expression
	| Bool_Expression NOT_EQUAL Bool_Expression
	| OP Bool_Expression CP
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