#include <bits/stdc++.h>

#include "Classes.h"

using namespace std;
using namespace llvm;
extern int errors;

static Module *TheModule = new Module("FlatB Compiler",llvm::getGlobalContext());
static LLVMContext &Context = getGlobalContext();
static IRBuilder<> Builder(Context);
static std::map<std::string, llvm::AllocaInst *> NamedValues;
FunctionType *FT = llvm::FunctionType::get(Type::getInt32Ty(getGlobalContext()), false);
Function *MainF = llvm::Function::Create(FT, Function::ExternalLinkage, "main", TheModule);

Prog::Prog(class declarationBlock* decls, class statementBlock* statements){
	this->decls = decls;
	this->statements = statements;
}


vector<class Var*> Vars::getVarsList(){
	return vars_list;
}

void Vars::push_back(class Var* var){
	vars_list.push_back(var);
}



Var::Var(string declType, string name, int length){
	this->declType = declType;
	this->name = name;
	this->length = length;
}

Var::Var(string declType, string name){
	this->declType = declType;
	this->name = name;
	this->length = 0;
}




bool Var::isArray(){
	return (declType.compare("Array") == 0);
}

void fieldDecls::push_back(class fieldDecl* var){
	decl_list.push_back(var);
}



fieldDecls::fieldDecls(){
}

vector<class Var*> fieldDecl::getVarsList(){
	return var_list;
}


fieldDecl::fieldDecl(string dataType, class Vars* vars){
	this->dataType = dataType;
	this->var_list = vars->getVarsList();
	for(int i = 0; i < var_list.size(); i++){
		var_list[i]->setDataType(dataType);
	}
}



unArithExpr::unArithExpr(string opr, class ArithExpr* expr){
	this->opr = opr;
	this->body = expr;
	this->etype = exprType::Unexpr;
}

binArithExpr::binArithExpr(class ArithExpr* lhs, string opr, class ArithExpr* rhs){
	this->lhs = lhs;
	this->rhs = rhs;
	this->opr = opr;
	this->etype = exprType::binary;
}


unBoolExpr::unBoolExpr(string opr, class BoolExpr* expr){
	this->opr = opr;
	this->body = expr;
}

binBoolExpr::binBoolExpr(class BoolExpr* lhs, string opr, class BoolExpr* rhs){
	this->lhs = lhs;
	this->rhs = rhs;
	this->opr = opr;
}

stringLiteral::stringLiteral(string val){

	val = val.substr(1,val.length()-2);
	this->value = val;
}

intLiteral::intLiteral(int value){
	this->value = value;
}

boolLiteral::boolLiteral(string value){
	this->value = value;
	this->type = "value";
}

statementBlock::statementBlock(class Stmts* stmts){
	this->stmts_list = stmts;
}



declarationBlock::declarationBlock(class fieldDecls* decls){
	this->decl_list = decls;
}

Stmts::Stmts(){
}


void Stmts::push_back(class Stmt* stmt){
	stmts.push_back(stmt);
}

void Stmts::push_back(class Stmt* stmt, string label){
	stmts.push_back(stmt);
	if(this->ltable.find(label) == this->ltable.end()){
		this->ltable[label] = stmt;
	}
	else{
		cout << "Error: redeclaration of label "<<label << endl;
	}
}
bool Stmts::checkLabel(string name){
	if(ltable.find(name)==this->ltable.end()){
		return false;
	}
	else{
		return true;
	}
}


Assignment::Assignment(class Location* loc, string oper, class ArithExpr* expr){
	this->loc = loc;
	this->opr = oper;
	this->expr = expr;
}



forStmt::forStmt(class Location* var, class ArithExpr* min_range, class ArithExpr* max_range, class ArithExpr* step , class statementBlock* body)
{
	this->name = "for";
	this->var = var;
	this->min_range = min_range;
	this->max_range = max_range;
	this->step = step;
	this->body = body;
	this->flag = 1;
}

forStmt::forStmt(class Location* var, class ArithExpr* min_range, class ArithExpr*max_range, int step_int, class statementBlock* body)
{
	this->name = "for";

	this->var = var;
	this->min_range = min_range;
	this->max_range = max_range;
	this->step_int = step_int;
	this->body = body; 
	this->flag = 0;
}

ifElseStmt::ifElseStmt(class BoolExpr* cond, class statementBlock* block1, class statementBlock* block2){
	this->name = "if";

	this->condition = cond;
	this->if_block = block1;
	this->else_block = block2;
}


whileStmt::	whileStmt(class BoolExpr* condition, class statementBlock* body){
	this->name = "while";

	this->condition = condition;
	this->body = body;
}

gotoStmt:: gotoStmt(string location, class BoolExpr*condition){
	this->name = "gotoStmt";

	this->condition = condition;
	this->location = location;
}

readStmt::readStmt(class readCands* cands){
	this->name = "read";

	this->read = cands;
}
void readCands::push_back(class Location* loc){

	this->vars_list.push_back(loc);
}
printStmt::printStmt(int new_line, class printCands* candidates){
	this->name = "print";

	this->new_line = new_line;
	this->print_candidates = candidates;
}
void printCands::push_back(class printCand* cand){
	this->printcans.push_back(cand);
}
printCand::printCand(class Location* cand){
	type = "location";
	this->loc = cand;
}

printCand::printCand(class stringLiteral* cand){
	this->str = cand;
	type = "string";
}

printCand::printCand(class intLiteral* cand){
	this->int_lit = cand;
	type = "integer";
}

Location::Location(string var, string location_type, class ArithExpr* expr){
	this->var = var;
	this->location_type = location_type;
	this->expr = expr;
	this->etype = exprType::location;
}

Location::Location(string var, string location_type){
	this->var = var;
	this->location_type = location_type;
	this->etype = exprType::location;
}
boolLiteral::boolLiteral(class ArithExpr* lhs, string op , class ArithExpr* rhs){
	this->lhs = lhs;
	this->op = op;
	this->rhs = rhs;
	this->type = "comp";
}
// ********************codegen****************

Value* fieldDecl::codegen(){
	for(int i = 0; i < var_list.size(); i++){
    /* Allocate one location of global variable for all */
		class Var* var = var_list[i];
		llvm::Type *ty;
		if(dataType == "int"){
			ty = Type::getInt32Ty(Context);
		}
		if(var->isArray()){
			ArrayType* arrType = ArrayType::get(ty,var->getLength());
			PointerType* PointerTy_1 = PointerType::get(ArrayType::get(ty,var->getLength()),0);
			GlobalVariable* gv = new GlobalVariable(*TheModule,arrType,false,GlobalValue::ExternalLinkage,0,var->getName());
			gv->setInitializer(ConstantAggregateZero::get(arrType));
		}
		else{
			PointerType* ptrTy = PointerType::get(ty,0);
			GlobalVariable* gv = new GlobalVariable(*TheModule,ptrTy , false,GlobalValue::ExternalLinkage, 0, var->getName());
		}
	}
	Value* v = ConstantInt::get(getGlobalContext(), APInt(32,1));
	return v;
}

Value* fieldDecls::codegen(){
	for(auto cs : decl_list){
		cs->codegen();
	}
	Value* v = ConstantInt::get(getGlobalContext(), APInt(32,1));
	return v;
}


Value* binArithExpr::codegen(){
	Value* left = lhs->codegen();
	Value* right = rhs->codegen();
	if(lhs->getEtype() == exprType::location){
		left = Builder.CreateLoad(left);
	}
	if(rhs->getEtype() == exprType::location){
		right = Builder.CreateLoad(right);
	}
	if(left == 0){
		errors++;
		return reportError::ErrorV("Error in left operand of " + opr);
	}
	else if(right == 0){
		errors++;
		return reportError::ErrorV("Error in right operand of " + opr);
	}
	Value* v;
	if(opr == "+"){
		v = Builder.CreateAdd(left,right,"addtmp");
	}
	else if (opr == "-"){
		v = Builder.CreateSub(left,right,"subtmp");
	}
	else if (opr == "*"){
		v = Builder.CreateMul(left,right,"multmp");
	}
	else if (opr == "/"){
		v = Builder.CreateUDiv(left,right,"divtmp");
	}
	else if(opr == "%"){
		v = Builder.CreateURem(left,right,"modtmp");
	}
	return v;
}

Value* unArithExpr::codegen(){
	Value* v = body->codegen();
	if(body->getEtype() == exprType::location){
		v = Builder.CreateLoad(v);
	}
	if(opr == "-"){
		return Builder.CreateNeg(v,"negtmp");
	}
	else if (opr == "!"){
		return Builder.CreateNot(v,"nottmp");
	}
}


Value* binBoolExpr::codegen(){
	Value* left = lhs->codegen();
	Value* right = rhs->codegen();
	if(left == 0){
		errors++;
		return reportError::ErrorV("Error in left operand of " + opr);
	}
	else if(right == 0){
		errors++;
		return reportError::ErrorV("Error in right operand of " + opr);
	}
	Value* v;
	if (opr == "||"){
		v = Builder.CreateOr(left,right,"ltcomparetmp");
	}
	else if (opr == "&&"){
		v = Builder.CreateAnd(left,right,"gtcomparetmp");
	}
	else if (opr == "=="){
		v = Builder.CreateICmpEQ(left,right,"lecomparetmp");
	}
	else if (opr == "!="){
		v = Builder.CreateICmpNE(left,right,"gecomparetmp");
	}

	return v;
}

Value* unBoolExpr::codegen(){
	Value* v = body->codegen();
	if(opr == "-"){
		return Builder.CreateNeg(v,"negtmp");
	}
	else if (opr == "!"){
		return Builder.CreateNot(v,"nottmp");
	}
}

Value* intLiteral::codegen(){
	Value* v = ConstantInt::get(getGlobalContext(), llvm::APInt(32,value));
	return v;
}

Value* boolLiteral::codegen(){
	bool val;
	Value* v = ConstantInt::get(getGlobalContext(), llvm::APInt(1,false));
	if(type=="value"){
		if(value == "true") val = true;
		else if (value == "false") val = false;
		v = ConstantInt::get(getGlobalContext(), llvm::APInt(1,0));
	}
	else if(type=="comp"){
		Value* left = lhs->codegen();
		Value* right = rhs->codegen();
		string opr = op;
		if(left == 0){
			errors++;
			return reportError::ErrorV("Error in left operand of " + opr);
		}
		else if(right == 0){
			errors++;
			return reportError::ErrorV("Error in right operand of " + opr);
		}
		if (opr == "<"){
			v = Builder.CreateICmpULT(left,right,"ltcomparetmp");
		}
		else if (opr == ">"){
			v = Builder.CreateICmpUGT(left,right,"gtcomparetmp");
		}
		else if (opr == "<="){
			v = Builder.CreateICmpULE(left,right,"lecomparetmp");
		}
		else if (opr == ">="){
			v = Builder.CreateICmpUGE(left,right,"gecomparetmp");
		}
		else if (opr == "=="){
			v = Builder.CreateICmpEQ(left,right,"equalcomparetmp");
		}
		else if (opr == "!="){
			v = Builder.CreateICmpNE(left,right,"notequalcomparetmp");
		}
	}
	return v;
}

Value* stringLiteral::codegen(){
	return Builder.CreateGlobalStringPtr(value);
}

Value* Prog::codegen(){
	Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
	V = decls->codegen();
	BasicBlock *mainStmtBlock = BasicBlock::Create(getGlobalContext(),"B1",MainF);
	Builder.SetInsertPoint(mainStmtBlock);
	V = statements->codegen();
	return V;
}
void Prog::generateCode(){
	cout << "Generating LLVM IR Code\n";
	TheModule->dump();
}

Value* statementBlock::codegen(){
	Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
	V = stmts_list->codegen();
	return V;
}

Value* declarationBlock::codegen(){
	Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
	V = decl_list->codegen();
	return V;
}

Value* Stmts::codegen(){
	Value* V = ConstantInt::get(getGlobalContext(), llvm::APInt(32,1));
	for(auto cs : stmts){
		V = cs->codegen();
	}
	return V;
}


Value* printStmt::codegen(){
	Value* V = print_candidates->codegen();
	return V;
}

Value* printCands::codegen(){
	Value* V = ConstantInt::get(getGlobalContext(), llvm::APInt(32,1));
	for(auto cs : printcans){
		V = cs->codegen();
	}
	return V;
}

Value* printCand::codegen(){
	vector<llvm::Type *> argTypes;
	vector<Value* > Args;
	if(type=="integer"){

		stringLiteral* temp_str = new stringLiteral("%d");
		//strlit
		Value* tmp = temp_str->codegen();
		if(tmp == 0){
			return 0;
		}
		Args.push_back(tmp);
		argTypes.push_back(tmp->getType());
		//int_lit
		tmp = int_lit->codegen();
		if(tmp == 0){
			return 0;
		}
		Args.push_back(tmp);
		argTypes.push_back(tmp->getType());
	}
	else if(type=="string"){
		stringLiteral* temp_str = new stringLiteral("%s");
		//strlit
		Value* tmp = temp_str->codegen();
		if(tmp == 0){
			return 0;
		}
		Args.push_back(tmp);
		argTypes.push_back(tmp->getType());
		//str
		tmp = str->codegen();
		if(tmp == 0){
			return 0;
		}
		Args.push_back(tmp);
		argTypes.push_back(tmp->getType());
	}
	else if(type=="location"){

		stringLiteral* temp_str = new stringLiteral("%d");
		//strlit
		Value* tmp = temp_str->codegen();
		if(tmp == 0){
			return 0;
		}
		Args.push_back(tmp);
		argTypes.push_back(tmp->getType());
		//location
		tmp = loc->codegen();
		if(tmp == 0){
			return 0;
		}
		Args.push_back(tmp);
		argTypes.push_back(tmp->getType());

	}
	llvm::ArrayRef<llvm::Type*>  argsRef(argTypes);
	llvm::ArrayRef<llvm::Value*>  funcargs(Args);
	llvm::FunctionType *FType = FunctionType::get(Type::getInt32Ty(Context), argsRef, false);
	Constant* func = TheModule->getOrInsertFunction("printf", FType);
	Value* v = Builder.CreateCall(func, funcargs);
	return v;
}

Value* readStmt::codegen(){
	Value* V = read->codegen();
	return V;
}

Value* readCands::codegen(){
	Value* V = ConstantInt::get(getGlobalContext(), llvm::APInt(32,1));
	for(auto cs : vars_list){
		V = cs->codegen();
	}
	return V;
}


Value* ifElseStmt::codegen(){
	Value *cond = condition->codegen();
	if(cond==0){
		errors++;
		return reportError::ErrorV("Invalid Expression in the IF");
	}
	Function * ThisFunction = Builder.GetInsertBlock()->getParent();
	BasicBlock *ifBlock = BasicBlock::Create(Context,"if",ThisFunction);
	BasicBlock *elseBlock = BasicBlock::Create(Context,"else");
	BasicBlock *nextBlock = BasicBlock::Create(Context,"next");
	Builder.CreateCondBr(cond, ifBlock, elseBlock);
	//begin if block
	Builder.SetInsertPoint(ifBlock);
	Value* ifval = if_block->codegen();
	if(ifval == 0){
		return 0;
	}
	Builder.CreateBr(nextBlock);

	ifBlock = Builder.GetInsertBlock();
	ThisFunction->getBasicBlockList().push_back(elseBlock);

	//begin else block

	Builder.SetInsertPoint(elseBlock);
	Value* elseval;
	if(else_block != NULL)
	{
		elseval = else_block->codegen();
		if(elseval == 0){
			return 0;
		}
	}
	Builder.CreateBr(nextBlock);
	elseBlock = Builder.GetInsertBlock();
	ThisFunction->getBasicBlockList().push_back(nextBlock);

	// begin the next block  	

	Builder.SetInsertPoint(nextBlock);
	Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
	return V;
}

Value* whileStmt::codegen(){
	Value *cond = condition->codegen();
	if(cond==0){
		errors++;
		return reportError::ErrorV("Invalid Expression in the IF");
	}
	Function * ThisFunction = Builder.GetInsertBlock()->getParent();
	BasicBlock *whileBlock = BasicBlock::Create(Context,"while",ThisFunction);
	BasicBlock *nextBlock = BasicBlock::Create(Context,"next");
	Builder.CreateCondBr(cond, whileBlock, nextBlock);
	//begin while block
	Builder.SetInsertPoint(whileBlock);
	Value* block = body->codegen();
	if(block == 0){
		return 0;
	}
	Builder.CreateCondBr(cond, whileBlock, nextBlock);

	whileBlock = Builder.GetInsertBlock();
	ThisFunction->getBasicBlockList().push_back(nextBlock);

	// begin the next block  	

	Builder.SetInsertPoint(nextBlock);
	Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
	return V;
}

Value* forStmt::codegen(){
	// Value* cur = TheModule->getGlobalVariable(var->getVar());
	// if(cur==0){
	// 	errors++;
	// 	return reportError::ErrorV("Invalid Expression in the IF");
	// }
	// Function * ThisFunction = Builder.GetInsertBlock()->getParent();
	// BasicBlock *forBlock = BasicBlock::Create(Context,"for",ThisFunction);
	// BasicBlock *nextBlock = BasicBlock::Create(Context,"next");
	
	// Builder.CreateCondBr(cond, ifBlock, elseBlock);
	
	// //begin if block
	// Builder.SetInsertPoint(ifBlock);
	// Value* ifval = if_block->codegen();
	// if(ifval == 0){
	// 	return 0;
	// }
	// Builder.CreateBr(nextBlock);

	// ifBlock = Builder.GetInsertBlock();
	// ThisFunction->getBasicBlockList().push_back(elseBlock);

	// //begin else block

	// Builder.SetInsertPoint(elseBlock);
	// Value* elseval;
	// if(else_block != NULL)
	// {
	// 	elseval = else_block->codegen();
	// 	if(elseval == 0){
	// 		return 0;
	// 	}
	// }
	// Builder.CreateBr(nextBlock);
	// elseBlock = Builder.GetInsertBlock();
	// ThisFunction->getBasicBlockList().push_back(nextBlock);

	// // begin the next block  	

	// Builder.SetInsertPoint(nextBlock);
	// Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
	// return V;
}
Value* gotoStmt::codegen(){}
Value* Assignment::codegen(){
	Value* cur = TheModule->getGlobalVariable(loc->getVar());//lhs check
	if(cur == 0){
		errors++;
		return reportError::ErrorV("Unknown Variable Name");
	}

	Value* lhs = loc->codegen(); // lhs load
	cur = Builder.CreateLoad(lhs);

	Value* val = expr->codegen(); // rhs load
	if(expr->getEtype() == exprType::location){
		val = Builder.CreateLoad(val);
	}

	if(val == 0){
		errors++;
		return reportError::ErrorV("Error in right hand side of the Assignment");
	}

	if(opr == "+="){
		val = Builder.CreateAdd(cur, val,"addEqualToTmp");
	}
	else if (opr == "-="){
		val = Builder.CreateSub(cur, val,"subEqualToTmp");
	}
	cur = Builder.CreateStore(val, lhs);
	return cur;
}


Value* Location::codegen(){
	Value* V = TheModule->getNamedGlobal(var);
	if(V == 0){
		errors++;
		return reportError::ErrorV("Unknown Variable name " + var);
	}
	if(this->location_type == "Normal"){
		return V;
	}
	if(this->expr != NULL){
		Value* index = expr->codegen();
		if(expr->getEtype() == exprType::location){
			index = Builder.CreateLoad(index);
		}
		if(index == 0){
			errors++;
			return reportError::ErrorV("Invalid array index");
		}
		vector<Value*> array_index;
		array_index.push_back(Builder.getInt32(0));
		array_index.push_back(index);
		V = Builder.CreateGEP(V, array_index, var+"_Index");
		return V;
	}
}

// Function *createFunc(std::string Name){
// 	Type *u32Ty = Type::getInt32Ty(Context);
// 	Type *vecTy = VectorType::get(u32Ty, 2);
// 	Type *ptrTy = vecTy->getPointerTo(0);
// 	FunctionType *funcType = Function::get(Builder.getInt32Ty(), ptrTym false);
// 	Function *fooFunc = Function::Create(funcType, Function::ExternalLinkage, Name, ModuleOb);
// 	return fooFunc;
// }
// Value *getGEP (Value *Base, Value *Offset){
// 	return Builder.CreateGEP(Builder.getInt32Ty(), Base, Offset, "a1");
// }