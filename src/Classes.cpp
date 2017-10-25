#include <bits/stdc++.h>

#include "Classes.h"

using namespace std;

Prog::Prog(class declarationBlock* decls, class statementBlock* statements){
  this->decls = decls;
  this->statements = statements;
}


vector<class Var*> Vars::getVarsList(){
  return vars_list;
}

void Vars::push_back(class Var* var){
  vars_list.push_back(var);
}



Var::Var(string declType, string name, int length){
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

void fieldDecls::push_back(class fieldDecl* var){
  decl_list.push_back(var);
  cnt++;
}



fieldDecls::fieldDecls(){
  this->cnt = 0;
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



unArithExpr::unArithExpr(string opr, class ArithExpr* expr){
  this->opr = opr;
  this->body = expr;
}

binArithExpr::binArithExpr(class ArithExpr* lhs, string opr, class ArithExpr* rhs){
  this->lhs = lhs;
  this->rhs = rhs;
  this->opr = opr;
}


unBoolExpr::unBoolExpr(string opr, class BoolExpr* expr){
  this->opr = opr;
  this->body = expr;
}

binBoolExpr::binBoolExpr(class BoolExpr* lhs, string opr, class BoolExpr* rhs){
  this->lhs = lhs;
  this->rhs = rhs;
  this->opr = opr;
}

stringLiteral::stringLiteral(string val){

  val = val.substr(1,val.length()-2);
  this->value = val;
}

intLiteral::intLiteral(int value){
  this->value = value;
}

boolLiteral::boolLiteral(string value){
  this->value = value;
  this->type = "value";
}

charLiteral::charLiteral(string val){
  this->value = val[0];
}



statementBlock::statementBlock(class Stmts* stmts){
  this->stmts_list = stmts;
}



declarationBlock::declarationBlock(class fieldDecls* decls){
  this->decl_list = decls;
}

Stmts::Stmts(){
  this->cnt = 0;
}


void Stmts::push_back(class Stmt* stmt){
  stmts.push_back(stmt);
  cnt++;
}

Assignment::Assignment(class Location* loc, string oper, class ArithExpr* expr){
  this->loc = loc;
  this->opr = oper;
  this->expr = expr;
}



forStmt::forStmt(class Location* var, class ArithExpr* min_range, class ArithExpr* max_range, class ArithExpr* step , class statementBlock* body)
{
  this->var = var;
  this->min_range = min_range;
  this->max_range = max_range;
  this->step = step;
  this->body = body;
  this->flag = 1;
}

forStmt::forStmt(class Location* var, class ArithExpr* min_range, class ArithExpr*max_range, int step_int, class statementBlock* body)
{
  this->var = var;
  this->min_range = min_range;
  this->max_range = max_range;
  this->step_int = step_int;
  this->body = body; 
  this->flag = 0;
}

ifElseStmt::ifElseStmt(class BoolExpr* cond, class statementBlock* block1, class statementBlock* block2){
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

readStmt::readStmt(class readCands* cands){
  this->read = cands;
}
void readCands::push_back(class Location* loc){
  this->vars_list.push_back(loc);
}
printStmt::printStmt(int new_line, class printCands* candidates){
  this->new_line = new_line;
  this->print_candidates = candidates;
}
void printCands::push_back(class printCand* cand){
  this->printcans.push_back(cand);
}
printCand::printCand(class Location* cand){
  type = "location";
  this->loc = cand;
}

printCand::printCand(class stringLiteral* cand){
  this->str = cand;
  type = "string";
}

printCand::printCand(class intLiteral* cand){
  this->int_lit = cand;
  type = "integer";
}

Location::Location(string var, string location_type, class ArithExpr* expr){
  this->var = var;
  this->location_type = location_type;
  this->expr = expr;
}

Location::Location(string var, string location_type){
  this->var = var;
  this->location_type = location_type;
}
boolLiteral::boolLiteral(class ArithExpr* lhs, string op , class ArithExpr* rhs){
  this->lhs = lhs;
  this->op = op;
  this->rhs = rhs;
  this->type = "comp";
}