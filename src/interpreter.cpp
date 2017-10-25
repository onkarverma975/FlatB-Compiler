#include<bits/stdc++.h>
#include "Classes.h"
using namespace std;
map <string,int> integer;
map <string,vector<int> > array_dec;
string type;
// int mode;
//1 : declaration
//2 : print
//3 : read
//4 : assign
//5 : use
int newLine;
int interVisitor::visit(class binArithExpr* obj){
	int left_val = obj->getLhs()->accept(this);
	int right_val = obj->getRhs()->accept(this);
	string op = obj->getOpr();
	if(op=="+"){
		return left_val + right_val ; 
	}

	else if(op=="-"){
		return left_val - right_val ; 
	}

	else if(op=="*"){
		return left_val * right_val ; 
	}
	else if(op=="/"){
		return left_val / right_val ; 
	}
	else if(op=="%"){
		return left_val % right_val ; 
	}
	else{
		cout << "Error in binops"<<endl;
	}
	
}

void interVisitor::visit(class Prog* obj){
	obj->getDecls()->accept(this);
	obj->getStmts()->accept(this);
}
void interVisitor::visit(class declarationBlock* obj){
	obj->getFieldDecls()->accept(this);
}
void interVisitor::visit(class statementBlock* obj){
	obj->getStatements()->accept(this);
}

void interVisitor::visit(class fieldDecls* obj){
	for(auto cs : obj->getDeclList()){
		cs->accept(this);
	}
}
void interVisitor::visit(class fieldDecl* obj){
	type = obj->getDataType();
	for(auto cs : obj->getVarsList()){
		cs->accept(this);
	}
}

void interVisitor::visit(class Vars* obj){
	for(auto cs : obj->getVarsList()){
		cs->accept(this);
	}
}

void interVisitor::visit(class Var* obj){
	obj->setDataType(type);
	string decl_type = obj->getType();
	string name = obj->getName();
	if(decl_type=="Array"){
		int length = obj->getLength();
		for(int i=0;i<length;i++)
			array_dec[name].push_back(0);	
	}
	else if(decl_type=="Normal"){
		integer[name]=0;
	}
}

void interVisitor::visit(class Stmts* obj){
	for(auto cs : obj->getStmts()){
		cs->accept(this);
	}
}
void interVisitor::visit(class forStmt* obj){
	class statementBlock * block = obj->getBlock();
	int low, high, step;	
	class Location* var=obj->getVar();
	if(obj->getForm()==0){ //predef
		low = obj->getMin()->accept(this);
		high= obj->getMax()->accept(this);
		step= obj->getStepInt();
		for(int i=low;i<=high;i+=step){
			var->accept(this,i);
			block->accept(this);
			low = obj->getMin()->accept(this);
			high= obj->getMax()->accept(this);
		}
	}
	else{ //expr
		low = obj->getMin()->accept(this);
		high= obj->getMax()->accept(this);
		step= obj->getStepExpr()->accept(this);
		for(int i=low;i<=high;i+=step){
			var->accept(this,i);
			block->accept(this);
			low = obj->getMin()->accept(this);
			high= obj->getMax()->accept(this);
			step= obj->getStepExpr()->accept(this);
		}
	}
}
void interVisitor::visit(class whileStmt* obj){
	while(obj->getCond()->accept(this)){
		obj->getBlock()->accept(this);
	}
}

void interVisitor::visit(class ifElseStmt* obj){
	if(obj->getCond()->accept(this)){
		obj->getIfBlock()->accept(this);
	}
	else{
		obj->getElseBlock()->accept(this);
	}
}


void interVisitor::visit(class gotoStmt* obj){
	if(obj->getCond()->accept(this)){
		
		// obj->getIfBlock()->accept(this);
	}
}

void interVisitor::visit(class printStmt* obj){
	newLine = obj->getNLFlag();
	obj->getPrintCands()->accept(this);
}

void interVisitor::visit(class readStmt* obj){
	obj->getReadCands()->accept(this);
}

void interVisitor::visit(class printCands* obj){
	for(auto cs : obj->getVarsList()){
		cs->accept(this);
	}
}

void interVisitor::visit(class printCand* obj){
	type = obj->getType();
	if(type=="integer"){
		cout << obj->getInt()->accept(this);
	}
	else if(type=="string"){
		cout << obj->getString()->accept(this);
	}
	else if(type=="location"){
		int value = obj->getLocation()->accept(this);
		cout << value;
	}
	if (newLine==1){
		cout << endl;
	}
}

void interVisitor::visit(class readCands* obj){
	for(auto cs : obj->getVarsList()){
		int temp;
		cin >> temp;
		cs->accept(this,temp);
	}
}









//pending
void interVisitor::visit(class Assignment* obj){
	string opr = obj->getOpr();
	int rhsvalue = obj->getRhs()->accept(this);
	//idea pass the value of rhs operator to the accept of the location operator
	if(opr=="="){
		obj->getLhs()->accept(this,rhsvalue);
	}
	else if(opr=="+="){
		int val = obj->getLhs()->accept(this);
		obj->getLhs()->accept(this,val+rhsvalue);
	}
	else if(opr=="-="){
		int val = obj->getLhs()->accept(this);
		obj->getLhs()->accept(this,val-rhsvalue);
	}
}

bool interVisitor::visit(class boolLiteral* obj){
	if(obj->getType()=="comp"){
		string opr = obj->getOpr();
		int left = obj->getLhs()->accept(this);
		int right = obj->getRhs()->accept(this);
		if(opr==">"){
			if(left > right){
				return true;
			}
			else{
				return false;
			}
		}
		else if(opr=="<"){
			if(left < right){
				return true;
			}
			else{
				return false;
			}
		}
		else if(opr==">="){
			if(left >= right){
				return true;
			}
			else{
				return false;
			}
		}
		else if(opr=="<="){
			if(left <= right){
				return true;
			}
			else{
				return false;
			}
		}
		else if(opr=="=="){
			if(left == right){
				return true;
			}
			else{
				return false;
			}
		}
		else if(opr=="!="){
			if(left != right){
				return true;
			}
			else{
				return false;
			}
		}
	}
	else if(obj->getType()=="value"){
		if(obj->getValue()=="true")
			return true;
		else if(obj->getValue()=="false")
			return false;
	}
}
string interVisitor::visit(class stringLiteral* obj){
	return obj->getValue();
}
int interVisitor::visit(class intLiteral* obj){
	return obj->getValue();
}
//assignment
int interVisitor::visit(class Location* obj, int value){
	if(obj->getType()=="Array"){
		int index = obj->getExpr()->accept(this);
		array_dec[obj->getVar()][index] = value;
	}
	else if(obj->getType()=="Normal"){
		integer[obj->getVar()] = value;
	}
	return 0;
}
//fetch
int interVisitor::visit(class Location* obj){
	if(obj->getType()=="Array"){
		int index = obj->getExpr()->accept(this);
		return array_dec[obj->getVar()][index];
	}
	else if(obj->getType()=="Normal"){
		return integer[obj->getVar()];
	}
}

bool interVisitor::visit(class binBoolExpr* obj){
	bool left_val = obj->getLhs()->accept(this);
	bool right_val = obj->getRhs()->accept(this);
	string op = obj->getOpr();
	if(op=="||"){
		return left_val || right_val ; 
	}

	else if(op=="&&"){
		return left_val && right_val ; 
	}

	else if(op=="=="){
		return left_val == right_val ; 
	}
	else if(op=="!="){
		return left_val != right_val ; 
	}
	else{
		cout << "Error in binBool"<<endl;
	}
}

bool interVisitor::visit(class unBoolExpr* obj){
	bool val = obj->getExpr()->accept(this);
	string op = obj->getOpr();
	if(op=="!")
		return !val;
}

int interVisitor::visit(class unArithExpr* obj){
	int val = obj->getExpr()->accept(this);
	string op = obj->getOpr();
	if(op=="-")
		return -val;
}