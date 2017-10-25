#include<bits/stdc++.h>

using namespace std;

class Visitor{
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
		int visit(class Location*);
		int visit(class Location*, int);
		int visit(class intLiteral*);
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