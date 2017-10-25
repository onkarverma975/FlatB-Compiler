#include<bits/stdc++.h>
#include "Classes.h"
using namespace std;
map <string,int> integer;
map <string,vector<int> > array_dec;
string type;
int mode;
//1 : declaration
//2 : print
//3 : read
//4 : assign
//5 : use
int newLine;
void Visitor::visit(class binArithExpr* obj){
	int left_val = obj->getLhs()->accept(this);
	int right_val = obj->getRhs()->accept(this);
	string op = obj->getOpr();
	// switch(op){
	// 	case '+':{
	// 		return left_val + right_val ; 
	// 	}

	// 	case '-':{
	// 		return left_val - right_val ; 
	// 	}

	// 	case '*':{
	// 		return left_val * right_val ; 
	// 	}
	// 	case '/':{
	// 		return left_val / right_val ; 
	// 	}
	// 	case '%':{
	// 		return left_val % right_val ; 
	// 	}
	// }
}

void Visitor::visit(class Prog* obj){
	obj->getDecls()->accept(this);
	obj->getStmts()->accept(this);
}
void Visitor::visit(class declarationBlock* obj){
	obj->getFieldDecls()->accept(this);
}
void Visitor::visit(class statementBlock* obj){
	obj->getStatements()->accept(this);
}

void Visitor::visit(class fieldDecls* obj){
	for(auto cs : obj->getDeclList()){
		cs->accept(this);
	}
}
void Visitor::visit(class fieldDecl* obj){
	type = obj->getDataType();
	for(auto cs : obj->getVarsList()){
		cs->accept(this);
	}
}

void Visitor::visit(class Vars* obj){
	for(auto cs : obj->getVarsList()){
		cs->accept(this);
	}
}

void Visitor::visit(class Var* obj){
	obj->setDataType(type);
	string decl_type = obj->getType();
	string name = obj->getName();
	if(decl_type=="Array"){
		unsigned int length = obj->getLength();
		array_dec[name] = new vector<int>(length);
	}
	else if(decl_type=="Normal"){
		integer[name]=0;
	}
}

void Visitor::visit(class Stmts* obj){
	for(auto cs : obj->getStmts()){
		cs->accept(this,type);
	}
}
void Visitor::visit(class forStmt* obj){
	class statementBlock * block = getBlock();
	int low,high;	
	string var=getVar();
	if(obj->getForm()==0){ //predef
		low = getMin()->accept();
		high= getMax()->accept();
		step= getStepInt();
		for(int i=low;i<=high;i+=step){
			integer[var]=i;
			block->accept();
			integer[var]=i;
			low = getMin()->accept();
			high= getMax()->accept();
			step= getStepInt()->accept();
		}
	}
	else{ //expr
		low = getMin()->accept();
		high= getMax()->accept();
		step= getStepExpr()->accept();
		for(int i=low;i<=high;i+=step){
			integer[var]=i;
			block->accept();
			integer[var]=i;
			low = getMin()->accept();
			high= getMax()->accept();
			step= getStepInt()->accept();
		}
	}
}
void Visitor::visit(class whileStmt* obj){
	while(getCond()->accept()){
		getBlock()->accept();
	}
}

void Visitor::visit(class ifElseStmt* obj){
	if(getCond()->accept()){
		getIfBlock()->accept();
	}
	else{
		getElseBlock()->accept();
	}
}

void Visitor::visit(class printStmt* obj){
	mode=2;
	newLine = getNLFlag();
	getPrintCands()->accept();
}

void Visitor::visit(class readStmt* obj){
	mode=3;
	getReadCands()->accept();
}
