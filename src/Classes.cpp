#include <bits/stdc++.h>

#include "ClassDefs.h"

using namespace std;
#define TBS cout << '\t';

Prog::Prog(class fieldDecls* decls, class statementBlock* statements){
  this->methods = methods;
  this->statements = statements;
}


vector<class Var*> Vars::getVarsList(){
  return vars_list;
}

void Vars::push_back(class Var* var){
  vars_list.push_back(var);
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

stringLiteral::stringLiteral(string val){

  val = val.substr(1,val.length()-2);
  val = replace_newline(val);
  this->value = val;
  this->ltype = literalType::String;
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



declarationBlock::declarationBlock(class Stmts* decls){
  this->decl_list = decls;
}

Stmts::Stmts(){
  this->cnt = 0;
}


void Stmts::push_back(class Stmt* stmt){
  stmts.push_back(stmt);
  cnt++;
}

Assignment::Assignment(class Location* loc, string oper, class Expr* expr){
  this->stype = stmtType::NonReturn;
  this->loc = loc;
  this->opr = oper;
  this->expr = expr;
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


whileStmt::	whileStmt(class BoolExpr* condition, class statementBlock* body){
  this->condition = condition;
  this->body = body;
}

gotoStmt:: gotoStmt(string location, class BoolExpr*condition){
  this->condition = condition;
  this->location = location;
}
