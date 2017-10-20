#include <bits/stdc++.h>

#include "ClassDefs.h"

using namespace std;
#define TBS cout << '\t';

Prog::Prog(class fieldDecls* decls, class statementBlock* statements){
  this->methods = methods;
  this->statements = statements;
}

void Prog::traverse(){
  TBS;
  out << "<program>\n";
  tabs_needed++;
  fields->traverse();
  methods->traverse();
  tabs_needed--;
  TBS;
  out << "</program>\n";
}

vector<class Var*> Vars::getVarsList(){
  return vars_list;
}

void Vars::push_back(class Var* var){
  vars_list.push_back(var);
}


void Vars::push_back(){
	for(int i=0;i<vars_list.size();i++){
		vars_list[i].traverse();
	}
}

Var::Var(string declType, string name, unsigned int length){
  this->declType = declType;
  this->name = name;
  this->length = length;
}

Var::Var(string declType, string name){
  this->declType = declType;
  this->name = name;
  this->length = 0;
}


void Var::traverse(){
  TBS;
  out << declType << endl;
  TBS;
  out << "<declaration name=\"" << name << "\" type=\"" << dataType << "\" ";
  if(declType.compare("Array") == 0){
    out << "size=\"" << length << "\" ";
  }
  out << "/>\n";
}


bool Var::isArray(){
  return (declType.compare("Array") == 0);
}

void Var::setDataType(string datatype){
  /* Sets the data type for the variable */
  this->dataType = datatype;
}

string Var::getName(){
  return name;
}


void fieldDecls::push_back(class fieldDecl* var){
  decl_list.push_back(var);
  cnt++;
}


void fieldDecls::traverse(){
  TBS;
  out << "<field_declarations count=\"" << cnt << "\">\n";
  tabs_needed++;
  for (int i = 0; i < decl_list.size(); i++){
    decl_list[i]->traverse();
  }
  tabs_needed--;
  TBS;
  out << "</field_declarations>\n";

}

fieldDecls::fieldDecls(){
  this->cnt = 0;
}

void fieldDecls::push_back(class fieldDecl* var){
  decl_list.push_back(var);
  cnt++;
}

vector<class Var*> fieldDecl::getVarsList(){
  return var_list;
}


void fieldDecl::traverse(){
  for(int i = 0;  i < var_list.size(); i++){
    var_list[i]->traverse();
  }
}

fieldDecl::fieldDecl(string dataType, class Vars* vars){
  this->dataType = dataType;
  this->var_list = vars->getVarsList();
  for(int i = 0; i < var_list.size(); i++){
    var_list[i]->setDataType(dataType);
  }
}

vector<class Var*> fieldDecl::getVarsList(){
  return var_list;
}


EnclArithExpr::EnclArithExpr(class Expr* expr){
  this->expr = expr;
  this->etype = exprType::enclExpr;
}

unArithExpr::unArithExpr(string opr, class Expr* expr){
  this->opr = opr;
  this->body = expr;
  this->etype = exprType::Unexpr;
}

binArithExpr::binArithExpr(class Expr* lhs, string opr, class Expr* rhs){
  this->lhs = lhs;
  this->rhs = rhs;
  this->opr = opr;
  this->etype = exprType::binary;
}

void EnclArithExpr::traverse(){
  expr->traverse();
}

void binArithExpr::traverse(){
  TBS;
  out << "<binary_expression type=\"" << (opr) <<"\">\n";
  tabs_needed++;
  lhs->traverse();
  rhs->traverse();
  tabs_needed--;
  TBS;
  out << "</binary_expression>\n";
}

void unArithExpr::traverse(){
  TBS;
  string operation  = "Unary Negitive";
  if(opr == "!"){
    operation = "Unary NOT";
  }
  out << "<unary_expression type=\"" << operation <<"\">\n";
  tabs_needed++;
  body->traverse();
  tabs_needed--;
  TBS;
  out << "</unary_expression>\n";
}


EnclBoolExpr::EnclBoolExpr(class Expr* expr){
  this->expr = expr;
  this->etype = exprType::enclExpr;
}

unBoolExpr::unBoolExpr(string opr, class Expr* expr){
  this->opr = opr;
  this->body = expr;
  this->etype = exprType::Unexpr;
}

binBoolExpr::binBoolExpr(class Expr* lhs, string opr, class Expr* rhs){
  this->lhs = lhs;
  this->rhs = rhs;
  this->opr = opr;
  this->etype = exprType::binary;
}

void EnclBoolExpr::traverse(){
  expr->traverse();
}

void binBoolExpr::traverse(){
  TBS;
  out << "<binary_expression type=\"" << (opr) <<"\">\n";
  tabs_needed++;
  lhs->traverse();
  rhs->traverse();
  tabs_needed--;
  TBS;
  out << "</binary_expression>\n";
}

void unBoolExpr::traverse(){
  TBS;
  string operation  = "Unary Negitive";
  if(opr == "!"){
    operation = "Unary NOT";
  }
  out << "<unary_expression type=\"" << operation <<"\">\n";
  tabs_needed++;
  body->traverse();
  tabs_needed--;
  TBS;
  out << "</unary_expression>\n";
}


stringLiteral::stringLiteral(string val){

  val = val.substr(1,val.length()-2);
  val = replace_newline(val);
  this->value = val;
  this->ltype = literalType::String;
}

void stringLiteral::traverse(){
  TBS;
  out << "<string value=\"" << value << "\" />\n";
}


void intLiteral::traverse(){
  TBS;
  out << "<integer value=\"" << value << "\" />\n";
}

void boolLiteral::traverse(){
  TBS;
  out << "<boolean value=\"" << value << "\" />\n";
}

void charLiteral::traverse(){
  TBS;
  out << "<char value=\"" << value << "\" />\n";
}

intLiteral::intLiteral(int value){
  this->value = value;
  this->ltype = literalType::Int;
}

boolLiteral::boolLiteral(string value){
  this->value = value;
  this->ltype = literalType::Bool;
}

charLiteral::charLiteral(string val){
  this->value = val[0];
  this->ltype = literalType::Char;
}

stringLiteral::stringLiteral(string val){

  val = val.substr(1,val.length()-2);
  val = replace_newline(val);
  this->value = val;
  this->ltype = literalType::String;
}


statementBlock::statementBlock(class Stmts* stmts){
  this->stmts_list = stmts;
}

void statementBlock::traverse(){
  TBS;
  out << "<block>\n";
  tabs_needed++;
  decls_list->traverse();
  stmts_list->traverse();
  tabs_needed--;
  TBS;
  out << "</block>\n";
}

Stmts::Stmts(){
  this->cnt = 0;
}


void Stmts::push_back(class Stmt* stmt){
  stmts.push_back(stmt);
  cnt++;
}

void Stmts::traverse(){
  TBS;
  out << "<statements count=\"" << cnt << "\">\n";
  tabs_needed++;
  for(int i = 0; i < stmts.size(); i++){
    stmts[i]->traverse();
  }
  tabs_needed--;
  TBS;
  out << "</statements>\n";
}

Assignment::Assignment(class Location* loc, string oper, class Expr* expr){
  this->stype = stmtType::NonReturn;
  this->loc = loc;
  this->opr = oper;
  this->expr = expr;
}


void Assignment::traverse(){
  TBS;
  out << "<assignment>\n";
  tabs_needed++;
  TBS;
  out << "<LHS name =\"" << loc->getVar() << "\">\n";
  if(loc->is_array()){
    tabs_needed++;
    loc->getExpr()->traverse();
    tabs_needed--;
  }
  TBS;
  out << "</LHS>\n";
  TBS;
  out << "<operation =\"" << (opr) <<"\">\n";
  TBS;
  out << "<RHS>\n";
  tabs_needed++;
  expr->traverse();
  tabs_needed--;
  TBS;
  out << "</RHS>\n";
  tabs_needed--;
  TBS;
  out << "</assignment>\n";
}



void forStmt::traverse(){
  TBS;
  out << "<for_statement>\n";
  tabs_needed++;
  TBS;
  out << "<initialisation>\n";
  tabs_needed++;
  TBS;
  out << "<variable name=\"" << var << "\" />\n";
  init->traverse();
  tabs_needed--;
  TBS;
  out << "</initialisation>\n";
  TBS;
  out << "<condition>\n";
  tabs_needed++;
  condition->traverse();
  tabs_needed--;
  TBS;
  out << "</condition>\n";
  tabs_needed++;
  body->traverse();
  tabs_needed--;
  tabs_needed--;
  TBS;
  out << "</for_statement>\n";
}


forStmt::forStmt(class Location* loc, class ArithExpr* min_range, class ArithExpr* max_range, class ArithExpr* step , class statementBlock* body){
  this->var = loc;
  this->init = min_range;
  this->max_range = max_range;
  this->step = step;
  this->body = body; 
}

ifElseStmt::ifElseStmt(class Expr* cond, class Block* block1, class Block* block2){
  this->stype = stmtType::NonReturn;
  this->condition = cond;
  this->if_block = block1;
  this->else_block = block2;
}


void ifElseStmt::traverse(){
  TBS;
  out << "<if_else_statement>\n";
  tabs_needed++;
  TBS;
  out << "<condition>\n";
  tabs_needed++;
  condition->traverse();
  tabs_needed--;
  TBS;
  out << "</condition>\n";
  TBS;
  out << "<ifblock>\n";
  tabs_needed++;
  if_block->traverse();
  tabs_needed--;
  TBS;
  out << "</ifblock>\n";
  if(else_block!=NULL){
    TBS;
    out << "<else_block>\n";
    tabs_needed++;
    else_block->traverse();
    tabs_needed--;
    TBS;
    out << "</elseblock>\n";
  }
  tabs_needed--;
  TBS;
  out << "</if_else_statement>\n";
}


void whileStmt::traverse(){
  cout <<"output for while statement\n" ;
}


whileStmt::	whileStmt(class BoolExpr* condition, class statementBlock* body){
  this->condition = condition;
  this->body = body;
}
