#include <bits/stdc++.h>
using namespace std;
union Node{
	int number;
	char* value;
	class Prog* prog;
	class fieldDecls* fields;
	class fieldDecl* field;
	class Vars* vars;
	class Var* var;
	class Block* block;
	class varDecls* var_decls;
	class varDecl* var_decl;
	class Stmts* stmts;
	class Stmt* stmt;
	class ArithExpr* arith_expr;
	class BoolExpr* bool_expr;
	class Location* location;
	class Assignment* assignment;
	class ArithLiteral* arith_literal;
	class BoolLiteral* bool_literal;
	class stringList* mylist;
};
class reportError{
	/* Class for error handling */
    public:
        static llvm::Value* ErrorV(string str) {
            cout<<str<<endl;
            return 0;
        }
};

class astNode{
};


class Prog:public astNode{
private:
	class fieldDecls* fields; /* list of fields */
	class statementBlock* statements; /* list of statement block */
public:
	Prog(class fieldDecls*, class statementBlock*);
	void traverse();
};


class Var:public astNode{
private:
	string declType; /* Array or Normal */
	string name; /* Name of the variable */
	string dataType; /* type of variable */
	unsigned int length; /* if it is an Array then length */
public:
	/* Constructors */
	Var(string,string,unsigned int);
	Var(string,string);
	bool isArray();
	/* Methods */
	void setDataType(string); /* Set the data Type */
	void traverse();
	string getName();
	int getLength(){return length;}
};

class Vars:public astNode{
private:
	vector<class Var*> vars_list;
public:
	Vars(){}
	void push_back(class Var*);
	vector<class Var*> getVarsList();
	void traverse();
};

class fieldDecl:public astNode{
private:
	string dataType; /* Field declaration can have datatype and vaariables */
	vector<class Var*> var_list;
public:
	fieldDecl(string,class Vars*);
	vector<class Var*> getVarsList();
	void traverse();
};

class fieldDecls:public astNode{
private:
	vector<class fieldDecl*> decl_list;
	int cnt;
public:
	fieldDecls();
	void push_back(class fieldDecl*);
	void traverse();
};

class ArithExpr:public astNode{
protected:
	exprType etype; /* Binary or unary or literal or location */
public:
	void setEtype(exprType x){etype = x;}
	exprType getEtype(){return etype;}
	virtual string toString(){}
	virtual void traverse(){}
	virtual Value* codegen(){}
};

class EnclExpr:public ArithExpr{
private:
	class Expr* expr;
public:
	EnclExpr(class Expr*);
	void traverse();
	Value* codegen();
};

class unExpr:public ArithExpr{
private:
	class Expr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unExpr(string,class Expr*);
	void traverse();
	Value* codegen();
};

class binExpr:public ArithExpr{
private:
	class Expr* lhs; /* left hand side */
	class Expr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binExpr(class Expr*, string, class Expr*);
	void traverse();
	Value* codegen();
};

class BoolExpr:public astNode{
protected:
	exprType etype; /* Binary or unary or literal or location */
public:
	void setEtype(exprType x){etype = x;}
	exprType getEtype(){return etype;}
	virtual string toString(){}
	virtual void traverse(){}
	virtual Value* codegen(){}
};

class EnclExpr:public BoolExpr{
private:
	class Expr* expr;
public:
	EnclExpr(class Expr*);
	void traverse();
	Value* codegen();
};

class unExpr:public BoolExpr{
private:
	class Expr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unExpr(string,class Expr*);
	void traverse();
	Value* codegen();
};

class binExpr:public BoolExpr{
private:
	class Expr* lhs; /* left hand side */
	class Expr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binExpr(class Expr*, string, class Expr*);
	void traverse();
	Value* codegen();
};

class Location:public ArithExpr{
private:
	string var; /* name used in location */
	string location_type; /* Array or normal */
	class Expr* expr; /* if it is array then we have the address */
public:
	Location(string,string,class Expr*);
	Location(string,string);
	void traverse();
	string getVar();/* returns the var name */
	bool is_array(); /* tells if its array or not */
	class Expr* getExpr();
	Value* codegen();
};

class Literal:public Expr{
protected:
	literalType ltype; /* Integer bool or char */
public:
	virtual void traverse(){}
	virtual int getValue(){}
	virtual string toString(){}
	virtual Value* codegen(){}
};

class intLiteral:public Literal{
private:
	int value;
public:
	intLiteral(int);
	void traverse();
	int getValue();
	string toString();
	Value* codegen();
};

class boolLiteral:public Literal{
private:
	string value;
public:
	boolLiteral(string);
	void traverse();
	string toString();
	Value* codegen();
};

class charLiteral:public Literal{
private:
	char value;
public:
	charLiteral(string);
	void traverse();
};

class stringLiteral:public Literal{
private:
	string value;
public:
	stringLiteral(string);
	void traverse();
	Value* codegen();
};

class Stmt:public astNode{
protected:
		stmtType stype;
public:
	virtual void traverse(){}
	virtual Value* codegen(){}
	virtual bool has_return(){return false;}
	void setStype(stmtType x){this->stype = x;}
	stmtType getStype(){return this->stype;}
};

class Stmts:public astNode{
private:
	vector<class Stmt*> stmts;
	int cnt;
public:
	Stmts();
	void push_back(class Stmt*);
	void traverse();
	bool has_return();
	Value* codegen();
};

class Assignment:public Stmt{
private:
	class Location* loc;/* location to which assignment is done */
	class Expr* expr; /* what is assigned */
	string opr; /* how it is assigned = or -= or += */
public:
	Assignment(class Location*, string, class Expr*);
	void traverse();
	Value* codegen();
};

class Block:public Stmt{
private:
	class varDecls* decls_list; /* list of variable declarations */
	class Stmts* stmts_list; /* list of statement declarations */
public:
	Block(class varDecls*,class Stmts*);
	void traverse();
	bool has_return();
	Value* codegen();
};

class varDecl:public astNode{
private:
	string type; /* type of variable declaraion */
	vector<string> var_list; /* list of variables */
	int cnt;
public:
	varDecl(string,class stringList*);
	void push_back(string);
	void traverse();
	Value* codegen(map<string,llvm::AllocaInst *>&);
};

class stringList{
private:
	vector<string> list; /* class to store vector of strings */
public:
	stringList(){}
	void push_back(string);
	vector<string> getList();
};
class forStmt:public Stmt{
private:
	string var;/* variable to be initialised */
	class Expr* init; /* Value for initialisation */
	class Expr* condition; /* condition for loop */
	class Block* body; /* body of the loop */
public:
	forStmt(string, class Expr*, class Expr*, class Block*);
	bool has_return(){this->body->has_return();}
	void traverse();
	Value* codegen();
};

class ifElseStmt:public Stmt{
private:
	class Expr* condition; /* condition for if statement */
	class Block* if_block; /* if block */
	class Block* else_block;/* else block */
public:
	ifElseStmt(class Expr*, class Block*, class Block*);
	void traverse();
	Value* codegen();
	bool has_return(){
		bool status = false;
		if(if_block != NULL){
			status = status | if_block->has_return();
		}
		if(else_block != NULL){
			status = status | if_block->has_return();
		}
		return status;
	}
};

class breakStmt:public Stmt{
public:
	breakStmt(){this->stype = stmtType::NonReturn;}
	void traverse();
	Value* codegen();
};

class continueStmt:public Stmt{
public:
	continueStmt(){this->stype = stmtType::NonReturn;}
	void traverse();
	Value* codegen();
};
