#include<bits/stdc++.h>
#include "Classes.h"
using namespace std;
// int mode;
//1 : declaration
//2 : print
//3 : read
//4 : assign
//5 : use
interVisitor::interVisitor(){
	this->Flag_Goto = 0;
	this->Goto_Label = "";
	this->newLine=0;
	this->type="";
	integer.clear();
	array_dec.clear();
}
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
		if(integer.find(name)==integer.end() && array_dec.find(name)==array_dec.end()){
			int length = obj->getLength();
			for(int i=0;i<length;i++)
				array_dec[name].push_back(0);	
		}
		else{
			cout << "Error: Redeclaration of array variable " << name << endl; 
			exit(-1);
		}
	}
	else if(decl_type=="Normal"){
		if(integer.find(name)==integer.end() && array_dec.find(name)==array_dec.end()){
			integer[name]=0;
		}
		else{
			cout << "Error: Redeclaration of variable " << name << endl; 
			exit(-1);
		}
	}
}

void interVisitor::visit(class Stmts* obj){
	// for(auto cs : obj->getStmts()){
	int minus=0;
	vector<class Stmt*> statements = obj->getStmts();
	for(vector<class Stmt*>::iterator cs= statements.begin();cs!=statements.end();cs++){
		if(minus==1){
			cs--;
			minus=0;
		}
		(*cs)->accept(this);
		if(Flag_Goto==1){
			if(obj->checkLabel(Goto_Label)==true){
				cs = find(statements.begin(),statements.end(),obj->getLTable()[Goto_Label]);
			}
			else{
				cout << "Error: label not declared "<< Goto_Label << endl;
				exit(-1);
			}
			Flag_Goto=0;
			minus=1;
		}
	}
}
void interVisitor::visit(class forStmt* obj){
	class statementBlock * block = obj->getBlock();
	int low, high, step;	
	class Location* var=obj->getVar();
	if(obj->getForm()==0){ //predef
		if(obj->getMin()==NULL || obj->getMax()==NULL){
			cout << "Error: declaration of for loop is not proper" << endl;
			exit(-1);
		}
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
		if(obj->getMin()==NULL || obj->getMax()==NULL || obj->getStepExpr()==NULL){
			cout << "Error: declaration of for loop is not proper" << endl;
			exit(-1);
		}
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
	if(obj->getCond()==NULL){
			cout << "Error: declaration of while loop is not proper" << endl;
			exit(-1);
	}
	while(obj->getCond()->accept(this)){
		obj->getBlock()->accept(this);
	}
}

void interVisitor::visit(class ifElseStmt* obj){
	if(obj->getCond()==NULL){
			cout << "Error: declaration of while loop is not proper" << endl;
			exit(-1);
	}
	if(obj->getCond()->accept(this)){
		obj->getIfBlock()->accept(this);
	}
	else{
		if(obj->getElseBlock()!=NULL){
			obj->getElseBlock()->accept(this);
		}
	}
}


void interVisitor::visit(class gotoStmt* obj){
	if (obj->getCond() != NULL){
		if(obj->getCond()->accept(this)){
			this->Flag_Goto=1;
			this->Goto_Label=obj->getLocation();		
		}
	}
	else{
		Flag_Goto=1;
		Goto_Label=obj->getLocation();		
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
		if(array_dec.find(obj->getVar()) == array_dec.end()){
			cout << "Error: array not declared before" << obj->getVar() <<endl;
			exit(-1);
		}
		int index = obj->getExpr()->accept(this);

		if(index >= array_dec[obj->getVar()].size() ){
			cout << "Error: index out of range" << obj->getVar() << "["<<index<<"]"<<endl;
			exit(-1);
		}
		array_dec[obj->getVar()][index] = value;
	}
	else if(obj->getType()=="Normal"){

		if(integer.find(obj->getVar()) == integer.end()){
			cout << "Error: integer not declared before " << obj->getVar() <<endl;
			exit(-1);
		}
		integer[obj->getVar()] = value;
	}
	return 0;
}
//fetch
int interVisitor::visit(class Location* obj){
	if(obj->getType()=="Array"){
		if(array_dec.find(obj->getVar()) == array_dec.end()){
			cout << "Error: array not declared before" << obj->getVar() <<endl;
			exit(-1);
		}
		int index = obj->getExpr()->accept(this);
		if(index >= array_dec[obj->getVar()].size() ){
			cout << "Error: index out of range" << obj->getVar() << "["<<index<<"]"<<endl;
			exit(-1);
		}
		return array_dec[obj->getVar()][index];
	}
	else if(obj->getType()=="Normal"){
		if(integer.find(obj->getVar()) == integer.end()){
			cout << "Error: integer not declared before" << obj->getVar() <<endl;
			exit(-1);
		}
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