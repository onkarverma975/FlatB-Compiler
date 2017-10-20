#include <bits/stdc++.h>
using namespace std;

enum exprType { binary = 1, location = 2, literal = 3, enclExpr = 4 , Unexpr = 5};
enum literalType { Int = 1, Bool = 2, Char = 3, String = 4 };
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
};


class Prog:public astNode{
private:
	class declarationBlock* decls; /* list of fields */
	class statementBlock* statements; /* list of statement block */
public:
	Prog(class declarationBlock*, class statementBlock*);
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
};


class printCand:public astNode{
private:
	class Location* loc;
	class stringLiteral* str;
	class charLiteral* chr;
	class intLiteral* intlit;
public:
	printCand(class Location*);
	printCand(class stringLiteral*);
	printCand(class charLiteral*);
	printCand(class intLiteral*);
};

class printCands:public astNode{
private:
	vector<class printCand*> vars_list;
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
};

class fieldDecls:public astNode{
private:
	vector<class fieldDecl*> decl_list;
	int cnt;
public:
	fieldDecls();
	void push_back(class fieldDecl*);
};


class ArithExpr:public astNode{
protected:
	exprType etype; /* Binary or unary or literal or location */
public:
	void setEtype(exprType x){etype = x;}
	exprType getEtype(){return etype;}
};

class EnclArithExpr:public ArithExpr{
private:
	class ArithExpr* expr;
public:
	EnclArithExpr(class ArithExpr*);
};

class unArithExpr:public ArithExpr{
private:
	class ArithExpr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unArithExpr(string,class ArithExpr*);
};

class binArithExpr:public ArithExpr{
private:
	class ArithExpr* lhs; /* left hand side */
	class ArithExpr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binArithExpr(class ArithExpr*, string, class ArithExpr*);
};

class BoolExpr:public astNode{
protected:
	exprType etype; /* Binary or unary or literal or location */
public:
	void setEtype(exprType x){etype = x;}
	exprType getEtype(){return etype;}
	virtual string toString(){}
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
	literalType ltype; /* Integer bool or char */
public:
	virtual int getValue(){}
	virtual string toString(){}
};

class bLiteral:public BoolExpr{
protected:
	literalType ltype; /* Integer bool or char */
public:
	virtual int getValue(){}
	virtual string toString(){}
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
public:
	boolLiteral(string);
	boolLiteral(class ArithExpr*, string, class ArithExpr*);
	string toString();
};

class Stmt:public astNode{
protected:
public:
};

class Stmts:public astNode{
private:
	vector<class Stmt*> stmts;
	int cnt;
public:
	Stmts();
	void push_back(class Stmt*);
};

class Assignment:public Stmt{
private:
	class Location* loc;/* location to which assignment is done */
	class ArithExpr* expr; /* what is assigned */
	string opr; /* how it is assigned = or -= or += */
public:
	Assignment(class Location*, string, class ArithExpr*);
};

class statementBlock:public astNode{
private:
	class Stmts* stmts_list;
public:
	statementBlock(class Stmts*);
};

class declarationBlock:public astNode{
private:
	class fieldDecls* decl_list; 
public:
	declarationBlock(class fieldDecls*);
};

class forStmt:public Stmt{
private:
	class Location* var;/* variable to be initialised */
	class ArithExpr* min_range; 
	class ArithExpr* max_range; 
	class ArithExpr* step; 
	class statementBlock* body; 
	int step_int;
public:
	forStmt(class Location*, class ArithExpr*, class ArithExpr*, class ArithExpr*, class statementBlock*);
	forStmt(class Location*, class ArithExpr*, class ArithExpr*, int , class statementBlock*);
};

class ifElseStmt:public Stmt{
private:
	class BoolExpr* condition; /* condition for if statement */
	class statementBlock* if_block; /* if block */
	class statementBlock* else_block;/* else block */
public:
	ifElseStmt(class BoolExpr*, class statementBlock*, class statementBlock*);
};

class whileStmt:public Stmt{
private:
	class BoolExpr* condition; 
	class statementBlock* body; 
public:
	whileStmt(class BoolExpr*, class statementBlock*);
};
class codeLocation:public astNode{
private:
	string name;
	int line_num;
public:
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
	class printCands* print;
public:
	printStmt(int flag, class printCands*);
};

class readStmt:public Stmt{
private:
	class readCands* read;
public:
	readStmt(class readCands*);
};