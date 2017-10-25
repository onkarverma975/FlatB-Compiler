%{
  #include "Classes.h"
  #include <bits/stdc++.h>
  
  extern "C" FILE *yyin;
  extern "C" int errors;
  extern union Node yylval;
  extern "C" int yylex();
  extern "C" int yyparse();
  void yyerror (char const *s);
  extern "C" int line_num;
  int errors=0;
  class Prog* start=NULL;
%}

%union {
	unsigned int number;
	char * value;
}

%token declaration_list
%token statement_list
%token <number> INTEGER
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

%type <prog> program
%type <var> Var_dec_name
%type <vars> Var_dec_names
%type <field> Variable_declaration
%type <fields> Variable_declarations
%type <printcan> Print_Var
%type <printcans> Print_Seq
%type <readcans> Read_Seq
%type <arith_expr> Arith_Expression Arith_Factor Arith_Factor1
%type <bool_expr> Bool_Expression Bool_Term Bool_Factor
%type <location> Variable
%type <stmts> Statements
%type <for_stmt> For_Statement
%type <if_stmt> Conditional
%type <while_stmt> While_Statement
%type <goto_stmt> GoTo_Statement
%type <print_stmt> Print_Statement
%type <read_stmt> Read_Statement
%type <stmt> Statement
%type <assignment> Assignment
%type <stblock> statement_Block
%type <declblock> declaration_Block
%type <bool_literal> Bool_Literal;

%define parse.error verbose

%left EQUAL NOT_EQUAL
%left COND_AND COND_OR
%left LT GT LE GE
%left ADD SUB
%left MUL DIV MOD

%%
program:declaration_list declaration_Block statement_list statement_Block
{
	$$ = new Prog($2,$4);
	start = $$;
}
	;

declaration_Block: 
	OB Variable_declarations CB {$$ = new declarationBlock($2);}
	;

statement_Block: 
	OB Statements CB {$$ = new statementBlock($2);}
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
	;
Read_Statement:
	READ Read_Seq { $$ = new readStmt($2);}
	;
Read_Seq:
	Variable {$$ = new readCands(); $$->push_back($1);}
	| Read_Seq COMMA Variable {$$->push_back($3);}
	;
Print_Statement:
	PRINT Print_Seq {$$ = new printStmt(0, $2);}
	| PRINTLN Print_Seq {$$ = new printStmt(1, $2);}
	;

Print_Seq:
	Print_Var {$$ = new printCands; $$->push_back($1);}
	| Print_Seq COMMA Print_Var  {$$->push_back($3);}
	;
Print_Var:
	Variable { $$ = new printCand($1); }
	| STRING 	{$$ = new printCand(new stringLiteral($1));}
	| INTEGER 	{$$ = new printCand(new intLiteral($1));}
	;

For_Statement:
	FOR Variable EQ Arith_Expression COMMA Arith_Expression COMMA Arith_Expression statement_Block
	{$$ = new forStmt($2,$4,$6,$8,$9);}
	| FOR Variable EQ Arith_Expression COMMA Arith_Expression statement_Block
	{ $$ = new forStmt($2,$4,$6,1,$7);}
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

Arith_Expression:
	Arith_Expression ADD Arith_Expression {$$ = new binArithExpr($1,string($2),$3);}
	| Arith_Expression SUB Arith_Expression	{$$ = new binArithExpr($1,string($2),$3);}
	| Arith_Factor { $$ = $1; }
	;

Arith_Factor:
	Arith_Factor MUL Arith_Factor1  {$$ = new binArithExpr($1,string($2),$3);}
	| Arith_Factor DIV Arith_Factor1  {$$ = new binArithExpr($1,string($2),$3);}
	| Arith_Factor MOD Arith_Factor1  {$$ = new binArithExpr($1,string($2),$3);}
	| SUB Arith_Factor1  {$$ = new unArithExpr(string($1),$2);}
	| Arith_Factor1 {$$=$1;}
	;
Arith_Factor1:
	OP Arith_Factor CP {$$ = $2;}
	| INTEGER {$$ = new intLiteral($1);}
	| Variable {$$ = $1;}
	;

Bool_Expression:
	Bool_Expression COND_OR Bool_Term {$$ = new binBoolExpr($1,string($2),$3);}
	| Bool_Expression EQUAL Bool_Term {$$ = new binBoolExpr($1,string($2),$3);}
	| Bool_Expression NOT_EQUAL Bool_Term {$$ = new binBoolExpr($1,string($2),$3);}
	| Bool_Term { $$ = $1; }
	;

Bool_Term:
	Bool_Term COND_AND Bool_Factor {$$ = new binBoolExpr($1,string($2),$3);}
	| Bool_Factor { $$ = $1; }
	;

Bool_Factor:
	OP Bool_Expression CP {$$ = $2;}
	| Bool_Literal { $$ = $1; }
	| NOT Bool_Factor {$$ = new unBoolExpr(string($1),$2);}
	;

Bool_Literal:
	BOOLEAN {$$ = new boolLiteral($1);}
	| Arith_Expression LT Arith_Expression {$$ = new boolLiteral($1,string($2),$3);}
	| Arith_Expression GT Arith_Expression {$$ = new boolLiteral($1,string($2),$3);}
	| Arith_Expression LE Arith_Expression {$$ = new boolLiteral($1,string($2),$3);}
	| Arith_Expression GE Arith_Expression {$$ = new boolLiteral($1,string($2),$3);}
	| Arith_Expression EQUAL Arith_Expression {$$ = new boolLiteral($1,string($2),$3);}
	| Arith_Expression NOT_EQUAL Arith_Expression {$$ = new boolLiteral($1,string($2),$3);}
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
	if(start){
		Visitor * visitor = new Visitor();
		start->accept(visitor);
	}
}


void yyerror(const char *s) {
	fprintf(stderr,"EEK, parse error on line %d!  Message: %s\n",line_num,s);
	// might as well halt now:
	exit(-1);
}