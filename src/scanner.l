%{
#include <bits/stdc++.h>
#include "parser.tab.h"
int line_num = 1;
#define YY_DECL extern "C" int yylex()
	using namespace std;
%}
digit [0-9]
letter [a-zA-Z]
alpha [0-9a-zA-Z]
delim [ \t]+
char [ -~]
string (\\n|\\t|\\'|\\\\|\\\"|[^\\"'])
%%
"declblock" { yylval.value = strdup(yytext);return declaration_list; }
"codeblock" { yylval.value = strdup(yytext);return statement_list; }
"int" { yylval.value = strdup(yytext); return TYPE; }
"bool" { yylval.value = strdup(yytext); return TYPE; }
"for" { return FOR; }
"goto" { return GOTO; }
"while" { return WHILE; }
"print" { return PRINT; }
"println" { return PRINTLN; }
"read" { return READ; }
"if" { return IF; }
"else" { return ELSE; }
"true" { yylval.value = strdup(yytext);return BOOLEAN; }
"false" { yylval.value = strdup(yytext);return BOOLEAN; }
"-" { yylval.value = strdup(yytext);return SUB; }
"+" { yylval.value = strdup(yytext);return ADD; }
"*" { yylval.value = strdup(yytext);return MUL; }
"/" { yylval.value = strdup(yytext);return DIV; }
"%" { yylval.value = strdup(yytext);return MOD; }
">" { yylval.value = strdup(yytext);return GT; }
"<" { yylval.value = strdup(yytext);return LT; }
">=" {yylval.value = strdup(yytext);return GE; }
"<=" { yylval.value = strdup(yytext);return LE; }
"==" { yylval.value = strdup(yytext);return EQUAL; }
"!=" { yylval.value = strdup(yytext);return NOT_EQUAL; }
"=" { yylval.value = strdup(yytext);return EQ; }
"+=" { yylval.value = strdup(yytext);return ADDEQ; }
"-=" { yylval.value = strdup(yytext);return SUBEQ; }
"&&" { yylval.value = strdup(yytext);return COND_AND; }
"||" { yylval.value = strdup(yytext);return COND_OR; }
"," { yylval.value = strdup(yytext);return COMMA; }
"}" { return CB; }
"{" { return OB; }
"]" {return CSB; }
"[" {return OSB; }
")" {return CP; }
"(" {return OP; }
";" { yylval.value = strdup(yytext);return SC; }
":" { yylval.value = strdup(yytext);return COL; }
"!" { yylval.value = strdup(yytext);return NOT; }
{letter}{alpha}* { yylval.value = strdup(yytext);return ID; }
{digit}+ {yylval.value = strdup(yytext); return INTEGER;}
\"{string}*\" { yylval.value = strdup(yytext);return STRING; }
{delim}						/* Ignore whitespaces tabs and newlines */
"//".*						/* Inline comments So Ignore */
\n { line_num++; }
.		{ 
		  printf("Unexpected token encountered: %s\n", yytext); 
		  return ETOK;
		}

%%