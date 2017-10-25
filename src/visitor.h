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
		void visit(class ArithExpr*);
		void visit(class EnclArithExpr*);
		void visit(class unArithExpr*);
		void visit(class binArithExpr*);
		void visit(class BoolExpr*);
		void visit(class EnclBoolExpr*);
		void visit(class unBoolExpr*);
		void visit(class binBoolExpr*);
		void visit(class Location*);
		void visit(class aLiteral*);
		void visit(class bLiteral*);
		void visit(class intLiteral*);
		void visit(class charLiteral*);
		void visit(class stringLiteral*);
		void visit(class boolLiteral*);
		void visit(class Stmt*);
		void visit(class Stmts*);
		void visit(class Assignment*);
		void visit(class statementBlock*);
		void visit(class declarationBlock*);
		void visit(class forStmt*);
		void visit(class ifElseStmt*);
		void visit(class whileStmt*);
		void visit(class codeLocation*);
		void visit(class gotoStmt*);
		void visit(class printStmt*);
		void visit(class readStmt*);
};