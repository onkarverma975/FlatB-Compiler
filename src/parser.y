%{
  #include <bits/stdc++.h>
  
  extern "C" FILE *yyin;
  extern "C" int errors;

  extern "C" int yylex();
  extern "C" int yyparse();
  void yyerror (char const *s);
  extern "C" int line_num;
  int errors=0;

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

/* Non-terminal types */

%type <prog> Program
%type <fields> Field_declarations
%type <field> Field_declaration
%type <vars> Variables
%type <var> Variable
%type <methods> Method_declarations
%type <method> Method_declaration
%type <method_args> Method_Args
%type <method_args> Method_Arg
%type <block> Block
%type <var_decls> Var_declarations
%type <var_decl> Var_declaration
%type <stmts> Statements
%type <stmt> Statement
%type <assignment> Assignment
%type <parameters> Params
%type <method_call> Method_Call
%type <location> Location
%type <expr> Expression
%type <callout_args> Callout_Args
%type <callout_arg> Callout_Arg
%type <literal> Literal;
%type <mylist> Var_names

%define parse.error verbose
/* -------------	Left Precedence		------------- */


%left EQUAL NOT_EQUAL
%left COND_AND COND_OR
%left LT GT LE GE
%left ADD SUB
%left MUL DIV MOD

%%
program:declaration_list declaration_Block statement_list statement_Block
{
	$$ = new Prog($2,$4);
	start=$$;
}
	;

declaration_Block: 
	OB Variable_declarations CB {$$ = $2;}
	;

statement_Block: 
	OB Statements CB {$$ = new Block($2);}
	;

Variable_declarations:
	/*Empty*/
	{
		$$ = new fieldDecls();
	}
	| Variable_declarations Variable_declaration SC  {$$->push_back($2);}
	;

Variable_declaration:
	TYPE Var_dec_names {$$ = new fieldDecl(string($1),$2);}
	;
Var_dec_names:
	Var_dec_name {$$ = new Vars();$$->push_back($1);}
	| Var_dec_names COMMA Var_dec_name { $$->push_back($3); }
	;
Var_dec_name:
	ID { $$ = new Var(string("Normal"),string($1));}
	| ID OSB INTEGER CSB  { $$ = new Var(string("Array"),string($1),$3);}
	;

Statements: 
	/*Empty*/ {$$ = new Stmts();}
	| Statements Statement {$$->push_back($2);}
	| Statements ID COL Statement { $$->push_back($4);} 
	;

Statement:
	Assignment SC {$$ = $1;}
	| For_Statement { $$ = $1;}
	| While_Statement { $$ = $1;}
	| Conditional { $$ = $1;}
	| GoTo_Statement SC { $$ = $1;}
	| Read_Statement SC { $$ = $1;}
	| Print_Statement SC { $$ = $1;}
	| PrintLN_Statement SC { $$ = $1;}
	;
Read_Statement:
	READ Read_Seq { $$ = new Reads();}
	;
Read_Seq:
	Variable {$$->push_back($1);}
	| Read_Seq COMMA Variable  {$$->push_back($3);}
	;
Print_Statement:
	PRINT Print_Seq {$$ = new Prints();}
	;
PrintLN_Statement:
	PRINTLN Print_Seq {$$ = new Printsln();}
	;
Print_Seq:
	Print_Var {$$->push_back($1);}
	| Print_Seq COMMA Print_Var  {$$->push_back($3);}
	;
Print_Var:
	Variable {$$->push_back($1, "Location");}
	| STRING {$$ = new stringLiteral($1);}
	;

For_Statement:
	FOR Variable EQ Arith_Expression COMMA Arith_Expression COMMA Arith_Expression statement_Block
	{$$ = new forStmt($2,$4,$6,$8,$9);}
	| FOR Variable EQ Arith_Expression COMMA Arith_Expression statement_Block
	{$$ = new forStmt($2,$4,$6,1,$9);}
	;

While_Statement:
	WHILE Bool_Expression statement_Block
	{$$ = new whileStmt($2,$3);}
	;

GoTo_Statement:
	GOTO ID IF Bool_Expression {$$ = new gotoStmt($2,$4);}
	|GOTO ID {$$ = new gotoStmt($2,NULL);}
	;

Conditional:
	IF Bool_Expression statement_Block ELSE statement_Block {$$ = new ifElseStmt($2,$3,$5);}
	| IF Bool_Expression statement_Block {$$ = new ifElseStmt($2,$3,NULL);}
	;

Assignment:
	Variable EQ Arith_Expression {$$ = new Assignment($1,string($2),$3);}
	| Variable SUBEQ Arith_Expression {$$ = new Assignment($1,string($2),$3);}
	| Variable ADDEQ Arith_Expression {$$ = new Assignment($1,string($2),$3);}
	;

Variable:
	ID {$$ = new Location(string($1),string("Normal"));}
	| ID OSB Arith_Expression CSB {$$ = new Location(string($1),string("Array"),$3);}
	;

Literal:
	OP Arith_Expression CP {$$ = new unExpr(string($1),$2);}
	| INTEGER {$$ = new intLiteral($1);}
	| ID { $$ = new Location(string($1),string("Normal"));}
	| ID OSB Arith_Expression CSB {$$ = new Location(string($1),string("Array"),$3);}
	;
Arith_Expression:
	Arith_Expression ADD Arith_Expression {$$ = new binExpr($1,string($2),$3);}
	| Arith_Expression SUB Arith_Expression	{$$ = new binExpr($1,string($2),$3);}
	| Arith_Factor { $$ = $1; }
	;

Arith_Factor:
	Arith_Factor MUL Literal  {$$ = new binExpr($1,string($2),$3);}
	| Arith_Factor DIV Literal  {$$ = new binExpr($1,string($2),$3);}
	| Arith_Factor MOD Literal  {$$ = new binExpr($1,string($2),$3);}
	| SUB Literal  {$$ = new unExpr(string($1),$2);}
	| Literal {$$=$1;}
	;

Bool_Expression:
	Bool_Expression COND_OR Bool_Term {$$ = new binBoolExpr($1,string($2),$3);}
	| Bool_Expression EQUAL Bool_Term {$$ = new binBoolExpr($1,string($2),$3);}
	| Bool_Expression NOT_EQUAL Bool_Term {$$ = new binBoolExpr($1,string($2),$3);}
	| Bool_Term { $$ = $1; }
	;

Bool_Term:
	Bool_Term COND_AND Bool_Literal {$$ = new binBoolExpr($1,string($2),$3);}
	| Bool_Literal { $$ = $1; }
	;

Bool_Literal:
	OP Bool_Expression CP {$$ = new EnclBoolExpr($2);}
	| Bool_Hola { $$ = $1; }
	| NOT Bool_Literal {$$ = new unBoolExpr(string($1),$2);}
	;

Bool_Hola:
	BOOLEAN {$$ = new boolLiteral($1);}
	| Arith_Expression LT Arith_Expression {$$ = new binExpr($1,string($2),$3);}
	| Arith_Expression GT Arith_Expression {$$ = new binExpr($1,string($2),$3);}
	| Arith_Expression LE Arith_Expression {$$ = new binExpr($1,string($2),$3);}
	| Arith_Expression GE Arith_Expression {$$ = new binExpr($1,string($2),$3);}
	| Arith_Expression EQUAL Arith_Expression {$$ = new binExpr($1,string($2),$3);}
	| Arith_Expression NOT_EQUAL Arith_Expression {$$ = new binExpr($1,string($2),$3);}
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