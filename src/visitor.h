#include<bits/stdc++.h>

using namespace std;

class Visitor{
	public:
		virtual void visit(class Prog*) = 0;
		virtual void visit(class Var*) = 0;
		virtual void visit(class Vars*) = 0;
		virtual void visit(class printCand*) = 0;
		virtual void visit(class printCands*) = 0;
		virtual void visit(class readCands*) = 0;
		virtual void visit(class fieldDecl*) = 0;
		virtual void visit(class fieldDecls*) = 0;
		virtual int  visit(class unArithExpr*) = 0;
		virtual int  visit(class binArithExpr*) = 0;
		virtual bool visit(class unBoolExpr*) = 0;
		virtual bool visit(class binBoolExpr*) = 0;
		virtual int  visit(class Location*) = 0;
		virtual int  visit(class Location*, int) = 0;
		virtual int  visit(class intLiteral*) = 0;
		virtual string visit(class stringLiteral*) = 0;
		virtual bool visit(class boolLiteral*) = 0;
		virtual void visit(class Stmts*) = 0;
		virtual void visit(class Assignment*) = 0;
		virtual void visit(class statementBlock*) = 0;
		virtual void visit(class declarationBlock*) = 0;
		virtual void visit(class forStmt*) = 0;
		virtual void visit(class gotoStmt*) = 0;
		virtual void visit(class ifElseStmt*) = 0;
		virtual void visit(class whileStmt*) = 0;
		virtual void visit(class printStmt*) = 0;
		virtual void visit(class readStmt*) = 0;
};

class interVisitor:public Visitor{
public:
	void visit(class Prog*);
	void visit(class Var*);
	void visit(class Vars*);
	void visit(class printCand*);
	void visit(class printCands*);
	void visit(class readCands*);
	void visit(class fieldDecl*);
	void visit(class fieldDecls*);
	int  visit(class unArithExpr*);
	int  visit(class binArithExpr*);
	bool visit(class unBoolExpr*);
	bool visit(class binBoolExpr*);
	int  visit(class Location*);
	int  visit(class Location*, int);
	int  visit(class intLiteral*);
	string visit(class stringLiteral*);
	bool visit(class boolLiteral*);
	void visit(class Stmts*);
	void visit(class Assignment*);
	void visit(class statementBlock*);
	void visit(class declarationBlock*);
	void visit(class forStmt*);
	void visit(class gotoStmt*);
	void visit(class ifElseStmt*);
	void visit(class whileStmt*);
	void visit(class printStmt*);
	void visit(class readStmt*);
};

class semanVisitor:public Visitor{
public:
	void visit(class Prog*);
	void visit(class Var*);
	void visit(class Vars*);
	void visit(class printCand*);
	void visit(class printCands*);
	void visit(class readCands*);
	void visit(class fieldDecl*);
	void visit(class fieldDecls*);
	int  visit(class unArithExpr*);
	int  visit(class binArithExpr*);
	bool visit(class unBoolExpr*);
	bool visit(class binBoolExpr*);
	int  visit(class Location*);
	int  visit(class Location*, int);
	int  visit(class intLiteral*);
	string visit(class stringLiteral*);
	bool visit(class boolLiteral*);
	void visit(class Stmts*);
	void visit(class Assignment*);
	void visit(class statementBlock*);
	void visit(class declarationBlock*);
	void visit(class forStmt*);
	void visit(class gotoStmt*);
	void visit(class ifElseStmt*);
	void visit(class whileStmt*);
	void visit(class printStmt*);
	void visit(class readStmt*);
};