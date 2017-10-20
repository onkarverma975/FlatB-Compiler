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
	class statementBlock* block;
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
	virtual void traverse(){}
};

class EnclArithExpr:public ArithExpr{
private:
	class ArithExpr* expr;
public:
	EnclExpr(class ArithExpr*);
	void traverse();
};

class unArithExpr:public ArithExpr{
private:
	class ArithExpr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unExpr(string,class ArithExpr*);
	void traverse();
};

class binArithExpr:public ArithExpr{
private:
	class ArithExpr* lhs; /* left hand side */
	class ArithExpr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binExpr(class ArithExpr*, string, class ArithExpr*);
	void traverse();
};

class BoolExpr:public astNode{
protected:
	exprType etype; /* Binary or unary or literal or location */
public:
	void setEtype(exprType x){etype = x;}
	exprType getEtype(){return etype;}
	virtual string toString(){}
	virtual void traverse(){}
};

class EnclBoolExpr:public BoolExpr{
private:
	class BoolExpr* expr;
public:
	EnclExpr(class BoolExpr*);
	void traverse();
};

class unBoolExpr:public BoolExpr{
private:
	class BoolExpr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unExpr(string,class BoolExpr*);
	void traverse();
};

class binBoolExpr:public BoolExpr{
private:
	class BoolExpr* lhs; /* left hand side */
	class BoolExpr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binExpr(class BoolExpr*, string, class BoolExpr*);
	void traverse();
};

class binBoolExpr:public BoolExpr{
private:
	class BoolExpr* lhs; /* left hand side */
	class BoolExpr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binExpr(class BoolExpr*, string, class BoolExpr*);
	void traverse();
};


class Location:public ArithExpr{
private:
	string var; /* name used in location */
	string location_type; /* Array or normal */
	class ArithExpr* expr; /* if it is array then we have the address */
public:
	Location(string,string,class ArithExpr*);
	Location(string,string);
	void traverse();
	string getVar();/* returns the var name */
	bool is_array(); /* tells if its array or not */
	class ArithExpr* getExpr();
};

class aLiteral:public ArithExpr{
protected:
	literalType ltype; /* Integer bool or char */
public:
	virtual void traverse(){}
	virtual int getValue(){}
	virtual string toString(){}
};

class bLiteral:public BoolExpr{
protected:
	literalType ltype; /* Integer bool or char */
public:
	virtual void traverse(){}
	virtual int getValue(){}
	virtual string toString(){}
};

class intLiteral:public aLiteral{
private:
	int value;
public:
	intLiteral(int);
	void traverse();
	int getValue();
	string toString();
};


class charLiteral:public aLiteral{
private:
	char value;
public:
	charLiteral(string);
	void traverse();
};

class stringLiteral:public aLiteral{
private:
	string value;
public:
	stringLiteral(string);
	void traverse();
};

class boolLiteral:public bLiteral{
private:
	string value;
public:
	boolLiteral(string);
	void traverse();
	string toString();
	Value* codegen();
};

class Stmt:public astNode{
protected:
public:
	virtual void traverse(){}
};

class Stmts:public astNode{
private:
	vector<class Stmt*> stmts;
	int cnt;
public:
	Stmts();
	void push_back(class Stmt*);
	void traverse();
};

class Assignment:public Stmt{
private:
	class Location* loc;/* location to which assignment is done */
	class ArithExpr* expr; /* what is assigned */
	string opr; /* how it is assigned = or -= or += */
public:
	Assignment(class Location*, string, class ArithExpr*);
	void traverse();
};

class statementBlock:public Stmt{
private:
	class Stmts* stmts_list; /* list of statement declarations */
public:
	statementBlock(class Stmts*);
	void traverse();
};

class forStmt:public Stmt{
private:
	class Location* var;/* variable to be initialised */
	class ArithExpr* min_range; 
	class ArithExpr* max_range; 
	class ArithExpr* step; 
	class statementBlock* body; 
public:
	forStmt(class Location*, class ArithExpr*, class ArithExpr*, class ArithExpr*, class statementBlock*);
	bool has_return(){this->body->has_return();}
	void traverse();
};

class ifElseStmt:public Stmt{
private:
	class BoolExpr* condition; /* condition for if statement */
	class statementBlock* if_block; /* if block */
	class statementBlock* else_block;/* else block */
public:
	ifElseStmt(class BoolExpr*, class statementBlock*, class statementBlock*);
	void traverse();	
};

class whileStmt:public Stmt{
private:
	class BoolExpr* condition; 
	class statementBlock* body; 
public:
	whileStmt(class BoolExpr*, class statementBlock*);
	void traverse();
};
