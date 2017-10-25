#include <bits/stdc++.h>
#include "visitor.h"
using namespace std;

union Node{
	int number;
	char* value;
	class Prog* prog;
	class Var* var;
	class Vars* vars;
	class fieldDecl* field;
	class fieldDecls* fields;
	class printCand* printcan;
	class printCands* printcans;
	class readCands* readcans;
	class ArithExpr* arith_expr;
	class BoolExpr* bool_expr;
	class Location* location;
	class Stmt* stmt;
	class Stmts* stmts;
	class forStmt* for_stmt;
	class ifElseStmt* if_stmt;
	class whileStmt* while_stmt;
	class gotoStmt* goto_stmt;
	class printStmt* print_stmt;
	class readStmt* read_stmt;
	class Assignment* assignment;
	class statementBlock* stblock;
	class declarationBlock* declblock;
	class aLiteral* arith_literal;
	class bLiteral* bool_literal;
	class stringList* mylist;
};

typedef union Node YYSTYPE;

#define YYSTYPE_IS_DECLARED 1

class astNode{
public:
};


class Prog:public astNode{
private:
	class declarationBlock* decls; /* list of fields */
	class statementBlock* statements; /* list of statement block */
public:
	Prog(class declarationBlock*, class statementBlock*);
	class declarationBlock* getDecls(){return decls;}
	class statementBlock* getStmts(){return statements;}
    void accept(Visitor * v) {
		v->visit(this);
    }
};


class Var:public astNode{
private:
	string declType; /* Array or Normal */
	string name; /* Name of the variable */
	string dataType; /* type of variable */
	int length; /* if it is an Array then length */
public:
	/* Constructors */
	Var(string,string, int);
	Var(string,string);
	bool isArray();
	/* Methods */  
	void setDataType(string datatype){this->dataType = datatype;}
	string getName(){return name;}
	unsigned int getLength(){return length;}
	string getType(){return declType;}
	string getDataType(){return dataType;}
	void accept(Visitor *v) {
		v->visit(this);
    }
};

class Vars:public astNode{
private:
	vector<class Var*> vars_list;
public:
	Vars(){}
	void push_back(class Var*);
	vector<class Var*> getVarsList();
    void accept(Visitor *v) {
		v->visit(this);
    }
};


class printCand:public astNode{
private:
	class Location* loc;
	class stringLiteral* str;
	class charLiteral* chr;
	class intLiteral* int_lit;
public:
	printCand(class Location*);
	printCand(class stringLiteral*);
	printCand(class charLiteral*);
	printCand(class intLiteral*);
};

class printCands:public astNode{
private:
	vector<class printCand*> printcans;
public:
	void push_back(class printCand*);
	vector<class printCand*> getVarsList();
};



class readCands:public astNode{
private:
	vector<class Location*> vars_list;
public:
	void push_back(class Location*);
	vector<class Location*> getVarsList();
};



class fieldDecl:public astNode{
private:
	string dataType; /* Field declaration can have datatype and vaariables */
	vector<class Var*> var_list;
public:
	fieldDecl(string,class Vars*);
	vector<class Var*> getVarsList();
	string getDataType(){return dataType;}
    void accept(Visitor *v) {
		v->visit(this);
    }
};

class fieldDecls:public astNode{
private:
	vector<class fieldDecl*> decl_list;
	int cnt;
public:
	fieldDecls();
	void push_back(class fieldDecl*);
	vector<class fieldDecl*> getDeclList(){return decl_list;}
    void accept(Visitor *v) {
		v->visit(this);
    }
};


class ArithExpr:public astNode{
protected:
public:
	virtual int accept(Visitor *);
};

class EnclArithExpr:public ArithExpr{
private:
	class ArithExpr* expr;
public:
	EnclArithExpr(class ArithExpr*);
	int accept(Visitor * v) {
		v->visit(this);
    }
};

class unArithExpr:public ArithExpr{
private:
	class ArithExpr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unArithExpr(string,class ArithExpr*);
	int accept(Visitor *v) {
		v->visit(this);
    }
};

class binArithExpr:public ArithExpr{
private:
	class ArithExpr* lhs; /* left hand side */
	class ArithExpr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binArithExpr(class ArithExpr*, string, class ArithExpr*);
    int accept(Visitor *v) {
		v->visit(this);
    }
    class ArithExpr* getLhs(){return lhs;}
    class ArithExpr* getRhs(){return rhs;}
    string getOpr(){return opr;}
};

class BoolExpr:public astNode{
protected:
public:
};

class EnclBoolExpr:public BoolExpr{
private:
	class BoolExpr* expr;
public:
	EnclBoolExpr(class BoolExpr*);
};

class unBoolExpr:public BoolExpr{
private:
	class BoolExpr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unBoolExpr(string,class BoolExpr*);
};

class binBoolExpr:public BoolExpr{
private:
	class BoolExpr* lhs; /* left hand side */
	class BoolExpr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binBoolExpr(class BoolExpr*, string, class BoolExpr*);
};

class Location:public ArithExpr{
private:
	string var; /* name used in location */
	string location_type; /* Array or normal */
	class ArithExpr* expr; /* if it is array then we have the address */
public:
	Location(string,string,class ArithExpr*);
	Location(string,string);
	string getVar();/* returns the var name */
	bool is_array(); /* tells if its array or not */
	class ArithExpr* getExpr();
};

class aLiteral:public ArithExpr{
protected:
public:
};

class bLiteral:public BoolExpr{
protected:
public:
};

class intLiteral:public aLiteral{
private:
	int value;
public:
	intLiteral(int);
	int getValue();
	string toString();
};


class charLiteral:public aLiteral{
private:
	char value;
public:
	charLiteral(string);
};

class stringLiteral:public aLiteral{
private:
	string value;
public:
	stringLiteral(string);
};

class boolLiteral:public bLiteral{
private:
	string value;
	class ArithExpr* lhs;
	class ArithExpr* rhs;
	string op;
public:
	boolLiteral(string);
	boolLiteral(class ArithExpr*, string, class ArithExpr*);
	string toString();
};

class Stmt:public astNode{
protected:
public:
	virtual void accept(Visitor *);
};

class Stmts:public astNode{
private:
	vector<class Stmt*> stmts;
	int cnt;
public:
	Stmts();
	void push_back(class Stmt*);
	vector<class Stmt*> getStmts(){return stmts;}
    void accept(Visitor *v) {
		v->visit(this);
    }
};

class Assignment:public Stmt{
private:
	class Location* loc;/* location to which assignment is done */
	class ArithExpr* expr; /* what is assigned */
	string opr; /* how it is assigned = or -= or += */
public:
	Assignment(class Location*, string, class ArithExpr*);
	class Location* getLhs(){return loc};
	class ArithExpr* getRhs(){return expr;}
	string getOpr(){return opr;} 
    void accept(Visitor *v) {
		v->visit(this);
    }
};

class statementBlock:public astNode{
private:
	class Stmts* stmts_list;
public:
	statementBlock(class Stmts*);
	class Stmts* getStatements(){return stmts_list;}
    void accept(Visitor *v) {
		v->visit(this);
    }
};

class declarationBlock:public astNode{
private:
	class fieldDecls* decl_list; 
public:
	declarationBlock(class fieldDecls*);
	class fieldDecls* getFieldDecls(){return decl_list;}
    void accept(Visitor *v) {
		v->visit(this);
    }
};

class forStmt:public Stmt{
private:
	class Location* var;/* variable to be initialised */
	class ArithExpr* min_range; 
	class ArithExpr* max_range; 
	class ArithExpr* step; 
	class statementBlock* body; 
	int   step_int;
	int   flag;
public:
	forStmt(class Location*, class ArithExpr*, class ArithExpr*, class ArithExpr*, class statementBlock*);
	forStmt(class Location*, class ArithExpr*, class ArithExpr*, int , class statementBlock*);
	class Location* getVar(){return var};
	int getForm(){return flag; }
	class ArithExpr* getMin(){return min_range; }
	class ArithExpr* getMax(){return max_range; }
	class ArithExpr* getStepExpr(){return step; }
	class statementBlock* getBlock(){return body; }
	int getStepInt(){return step_int; }
    void accept(Visitor *v) {
		v->visit(this);
    }
};

class ifElseStmt:public Stmt{
private:
	class BoolExpr* condition; /* condition for if statement */
	class statementBlock* if_block; /* if block */
	class statementBlock* else_block;/* else block */
public:
	ifElseStmt(class BoolExpr*, class statementBlock*, class statementBlock*);
	class statementBlock* getIfBlock(){return if_block; }
	class BoolExpr* getCond(){return condition; }
	class statementBlock* getElseBlock(){return else_block; }
	void accept(Visitor *v) {
		v->visit(this);
    }
};

class whileStmt:public Stmt{
private:
	class BoolExpr* condition; 
	class statementBlock* body; 
public:
	whileStmt(class BoolExpr*, class statementBlock*);
	class BoolExpr* getCond(){return condition; }
	class statementBlock* getBlock(){return body; }
	void accept(Visitor *v) {
		v->visit(this);
    }
};

class gotoStmt:public Stmt{
private:
	string location;
	class BoolExpr* condition; 
public:
	gotoStmt(string, class BoolExpr*);
};

class printStmt:public Stmt{
private:
	class printCands* print_candidates;
	int new_line;
public:
	printStmt(int flag, class printCands*);
	class printCands* getPrintCands(){return print_candidates;}
	int getNLFlag(){return new_line;}
	void accept(Visitor *v) {
		v->visit(this);
    }
};

class readStmt:public Stmt{
private:
	class readCands* read;
public:
	readStmt(class readCands*);
	class readCands* getReadCands(){return read;}
	void accept(Visitor *v) {
		v->visit(this);
    }
};