#include <bits/stdc++.h>

#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/IR/Verifier.h>
//#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/IR/IRBuilder.h>
//#include <llvm/ModuleProvider.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/raw_ostream.h>
#include "visitor.h"
using namespace std;
using namespace llvm;
enum exprType { binary = 1, location = 2, literal = 3 , Unexpr = 4};

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

class reportError{
	/* Class for error handling */
    public:
        static llvm::Value* ErrorV(string str) {
            cout<<str<<endl;
            return 0;
        }
};

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
    Value* codegen();
    void generateCode();
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
    Value* codegen();
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
    Value* codegen();
};


class printCand:public astNode{
private:
	class Location* loc;
	class stringLiteral* str;
	class intLiteral* int_lit;
	string type;
public:
	string getType(){return type;}
	class intLiteral* getInt(){return int_lit;}
	class stringLiteral* getString(){return str;}
	class Location* getLocation(){return loc;}
	printCand(class Location*);
	printCand(class stringLiteral*);
	printCand(class intLiteral*);
    void accept(Visitor *v) {
		v->visit(this);
    }
    Value* codegen();
};

class printCands:public astNode{
private:
	vector<class printCand*> printcans;
public:
	void push_back(class printCand*);
	vector<class printCand*> getVarsList(){return printcans;}
    void accept(Visitor *v) {
		v->visit(this);
    }
    Value* codegen();
};



class readCands:public astNode{
private:
	vector<class Location*> vars_list;
public:
	void push_back(class Location*);
	vector<class Location*> getVarsList(){return vars_list;}
    void accept(Visitor *v) {
		v->visit(this);
    }
    Value* codegen();
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
    Value* codegen();
};

class fieldDecls:public astNode{
private:
	vector<class fieldDecl*> decl_list;
public:
	fieldDecls();
	void push_back(class fieldDecl*);
	vector<class fieldDecl*> getDeclList(){return decl_list;}
    void accept(Visitor *v) {
		v->visit(this);
    }
    Value* codegen();
};


class ArithExpr:public astNode{
protected:
	exprType etype;
public:
	virtual int accept(Visitor *) = 0;
	virtual int accept(Visitor *, int) = 0;
    virtual Value* codegen() = 0;
    exprType getEtype(){return etype;}
    void setEtype(exprType x){etype = x;}
};


class unArithExpr:public ArithExpr{
private:
	class ArithExpr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unArithExpr(string,class ArithExpr*);
	class ArithExpr* getExpr(){return body;}
	string getOpr(){return opr;}
	int accept(Visitor *v) {
		v->visit(this);
    }
    int accept(Visitor *v, int value) {
		return v->visit(this);
    }
    Value* codegen();
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
    int accept(Visitor *v, int value) {
		return v->visit(this);
    }
    Value* codegen();

};

class BoolExpr:public astNode{
protected:
public:
	virtual bool accept(Visitor *) = 0;
    virtual Value* codegen() = 0;
};


class unBoolExpr:public BoolExpr{
private:
	class BoolExpr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unBoolExpr(string,class BoolExpr*);
	class BoolExpr* getExpr(){return body;} 
	string getOpr(){return opr;} 
	bool accept(Visitor *v) {
		v->visit(this);
    }
    Value* codegen();
};

class binBoolExpr:public BoolExpr{
private:
	class BoolExpr* lhs; /* left hand side */
	class BoolExpr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binBoolExpr(class BoolExpr*, string, class BoolExpr*);
	bool accept(Visitor *v) {
		v->visit(this);
    }
    class BoolExpr* getLhs(){return lhs;}
    class BoolExpr* getRhs(){return rhs;}
    string getOpr(){return opr;} 
    Value* codegen();
};

class Location:public ArithExpr{
private:
	string var; /* name used in location */
	string location_type; /* Array or normal */
	class ArithExpr* expr; /* if it is array then we have the address */
public:
	Location(string,string,class ArithExpr*);
	Location(string,string);
	string getVar(){return var;}/* returns the var name */
	string getType(){return location_type;}
	bool is_array(); 
	class ArithExpr* getExpr(){return expr;}
	//value fetch
    int accept(Visitor *v) {
		return v->visit(this);
    }
    //assignment
    int accept(Visitor *v, int value) {
		return v->visit(this, value);
    }
    Value* codegen();
};

class aLiteral:public ArithExpr{
protected:
public:
    virtual Value* codegen() = 0;
};

class bLiteral:public BoolExpr{
protected:
public:
    virtual Value* codegen() = 0;
};

class intLiteral:public aLiteral{
private:
	int value;
public:
	intLiteral(int);
	int getValue(){return value;}
    int accept(Visitor *v) {
    	// cout << value << endl;
		return v->visit(this);
    }
    int accept(Visitor *v, int value) {
    	// cout << value << endl;

		return v->visit(this);
    }
    Value* codegen();
};

class stringLiteral:public astNode{
private:
	string value;
public:
	stringLiteral(string);
	string getValue(){return value;}
    string accept(Visitor *v) {
		return v->visit(this);
    }
    Value* codegen();
};


class charLiteral:public aLiteral{
private:
	char value;
public:
	charLiteral(string);
    Value* codegen();
};

class boolLiteral:public bLiteral{
private:
	string value;
	class ArithExpr* lhs;
	class ArithExpr* rhs;
	string op;
	string type;
public:
	boolLiteral(string);
	boolLiteral(class ArithExpr*, string, class ArithExpr*);
	string getValue(){return value;}
	string getType(){return type;}
	string getOpr(){return op;}
	class ArithExpr* getLhs(){return lhs;}
	class ArithExpr* getRhs(){return rhs;}
    bool accept(Visitor *v) {
		return v->visit(this);
    }
    Value* codegen();
};

class Stmt:public astNode{
protected:
	string name;
	string label;
public:
	virtual void accept(Visitor *) = 0;
	string getName(){return name;}
	string getLabel(){return label;}
	string setName(string this_name){name = this_name;}
	string setLabel(string this_name){label = this_name;}
    virtual Value* codegen() = 0;
};

class Stmts:public astNode{
private:
	vector<class Stmt*> stmts;
	map<string,class Stmt*> ltable;
public:
	Stmts();
	void push_back(class Stmt*);
	void push_back(class Stmt*, string);
	vector<class Stmt*> getStmts(){return stmts;}
	map<string,class Stmt*> getLTable(){return ltable;}
	bool checkLabel(string name);
    void accept(Visitor *v) {
		v->visit(this);
    }
    Value* codegen();
};

class Assignment:public Stmt{
private:
	class Location* loc;/* location to which assignment is done */
	class ArithExpr* expr; /* what is assigned */
	string opr; /* how it is assigned = or -= or += */
public:
	Assignment(class Location*, string, class ArithExpr*);
	class Location* getLhs(){return loc;}
	class ArithExpr* getRhs(){return expr;}
	string getOpr(){return opr;} 
    void accept(Visitor *v) {
		v->visit(this);
    }
    Value* codegen();
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
    Value* codegen();
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
    Value* codegen();
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
	class Location* getVar(){return var;}
	int getForm(){return flag; }
	class ArithExpr* getMin(){return min_range; }
	class ArithExpr* getMax(){return max_range; }
	class ArithExpr* getStepExpr(){return step; }
	class statementBlock* getBlock(){return body; }
	int getStepInt(){return step_int; }
    void accept(Visitor *v) {
		v->visit(this);
    }
    Value* codegen();
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
    Value* codegen();
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
    Value* codegen();
};

class gotoStmt:public Stmt{
private:
	string location;
	class BoolExpr* condition; 
public:
	gotoStmt(string, class BoolExpr*);
	string getLocation(){return location;}
	class BoolExpr* getCond(){return condition;}
    void accept(Visitor *v) {
		v->visit(this);
    }
    Value* codegen();

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
    Value* codegen();

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
    Value* codegen();
};