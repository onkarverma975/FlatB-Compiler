#include<bits/stdc++.h>
#include "Classes.h"
using namespace std;
map <string,int> decl_integer;
map <string,vector<int> > decl_array;
string type;
// int mode;
//1 : declaration
//2 : print
//3 : read
//4 : assign
//5 : use
int newLine;
int semanVisitor::visit(class binArithExpr* obj){
	return 0;
}

void semanVisitor::visit(class Prog* obj){
}
void semanVisitor::visit(class declarationBlock* obj){
}
void semanVisitor::visit(class statementBlock* obj){
}

void semanVisitor::visit(class fieldDecls* obj){
}
void semanVisitor::visit(class fieldDecl* obj){
}

void semanVisitor::visit(class Vars* obj){
}

void semanVisitor::visit(class Var* obj){
}

void semanVisitor::visit(class Stmts* obj){
}
void semanVisitor::visit(class forStmt* obj){
}
void semanVisitor::visit(class whileStmt* obj){
}

void semanVisitor::visit(class ifElseStmt* obj){
}


void semanVisitor::visit(class gotoStmt* obj){
}

void semanVisitor::visit(class printStmt* obj){
}

void semanVisitor::visit(class readStmt* obj){
}

void semanVisitor::visit(class printCands* obj){
}

void semanVisitor::visit(class printCand* obj){
}

void semanVisitor::visit(class readCands* obj){
}

//pending
void semanVisitor::visit(class Assignment* obj){
}

bool semanVisitor::visit(class boolLiteral* obj){
	return 0;
}
string semanVisitor::visit(class stringLiteral* obj){
	return "";
}
int semanVisitor::visit(class intLiteral* obj){
	return 0;
}
//assignment
int semanVisitor::visit(class Location* obj, int value){
	return 0;
}
//fetch
int semanVisitor::visit(class Location* obj){
	return 0;
}

bool semanVisitor::visit(class binBoolExpr* obj){
	return 0;
}

bool semanVisitor::visit(class unBoolExpr* obj){
	return 0;
}

int semanVisitor::visit(class unArithExpr* obj){
	return 0;
}