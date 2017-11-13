#include <bits/stdc++.h>

#include "Classes.h"

using namespace std;
using namespace llvm;
extern int errors;

static Module *TheModule = new Module("FlatB Compiler",llvm::getGlobalContext());
static LLVMContext &Context = getGlobalContext();
static IRBuilder<> Builder(Context);
FunctionType *FT = llvm::FunctionType::get(Type::getVoidTy(getGlobalContext()), false);
Function *MainF = llvm::Function::Create(FT, Function::ExternalLinkage, "main", TheModule);
map<string, BasicBlock *> GlobalLTable;
Prog::Prog(class declarationBlock* decls, class statementBlock* statements){
	this->decls = decls;
	this->statements = statements;
}
int print_new_line;


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
	stmt->setLabel(label);
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
	this->label = "None123456";
	this->loc = loc;
	this->opr = oper;
	this->expr = expr;
}



forStmt::forStmt(class Location* var, class ArithExpr* min_range, class ArithExpr* max_range, class ArithExpr* step , class statementBlock* body)
{
	this->name = "for";
	this->label = "None123456";
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
	this->label = "None123456";

	this->var = var;
	this->min_range = min_range;
	this->max_range = max_range;
	this->step_int = step_int;
	this->body = body; 
	this->flag = 0;
}

ifElseStmt::ifElseStmt(class BoolExpr* cond, class statementBlock* block1, class statementBlock* block2){
	this->name = "if";
	this->label = "None123456";

	this->condition = cond;
	this->if_block = block1;
	this->else_block = block2;
}


whileStmt::whileStmt(class BoolExpr* condition, class statementBlock* body){
	this->name = "while";
	this->label = "None123456";

	this->condition = condition;
	this->body = body;
}

gotoStmt::gotoStmt(string location, class BoolExpr*condition){
	this->label = "None123456";
	this->name = "gotoStmt";
	this->condition = condition;
	this->location = location;
}

readStmt::readStmt(class readCands* cands){
	this->label = "None123456";
	this->name = "read";

	this->read = cands;
}
void readCands::push_back(class Location* loc){

	this->vars_list.push_back(loc);
}
printStmt::printStmt(int new_line, class printCands* candidates){
	this->label = "None123456";
	this->name = "print";

	this->new_line = new_line;
	print_new_line = new_line;
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
		if(value == "true") val = 1;
		else if (value == "false") val = 0;
		v = ConstantInt::get(getGlobalContext(), llvm::APInt(1,val));
	}
	else if(type=="comp"){
		Value* left = lhs->codegen();
		Value* right = rhs->codegen();
		if(lhs->getEtype() == exprType::location){
			left = Builder.CreateLoad(left);
		}
		if(rhs->getEtype() == exprType::location){
			right = Builder.CreateLoad(right);
		}
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
	Builder.CreateRetVoid();
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
		if(cs->getLabel()!="None123456"){
			cout << cs->getLabel() << endl;
			string label = cs->getLabel();
			Function * ThisFunction = MainF;
			BasicBlock *newBlock = BasicBlock::Create(Context,label,ThisFunction);
			Builder.CreateBr(newBlock);
			Builder.SetInsertPoint(newBlock);

			if(GlobalLTable.find(label) == GlobalLTable.end()){
				GlobalLTable[label] = newBlock;
			}
			else{
				cout << "Error: redeclaration of label "<<label << endl;
			}
		}
		V = cs->codegen();
	}
	return V;
}


Value* printStmt::codegen(){
	print_new_line = new_line;
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
		stringLiteral* temp_str;
		if(print_new_line==1)
			temp_str = new stringLiteral(string("0%d\n0"));
		else if(print_new_line==0)
			temp_str = new stringLiteral(string("0%d0"));

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
		stringLiteral* temp_str;
		if(print_new_line==1)
			temp_str = new stringLiteral(string("0%s\n0"));
		else if(print_new_line==0)
			temp_str = new stringLiteral(string("0%s0"));
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

		stringLiteral* temp_str;
		if(print_new_line==1)
			temp_str = new stringLiteral(string("0%d\n0"));
		else if(print_new_line==0)
			temp_str = new stringLiteral(string("0%d0"));
		//strlit
		Value* tmp = temp_str->codegen();
		if(tmp == 0){
			return 0;
		}
		Args.push_back(tmp);
		argTypes.push_back(tmp->getType());
		//location
		tmp = loc->codegen();
		tmp = Builder.CreateLoad(tmp);
		if(tmp == 0){
			return 0;
		}
		Args.push_back(tmp);
		argTypes.push_back(tmp->getType());

	}
	llvm::ArrayRef<llvm::Type*>  argsRef(argTypes);
	llvm::ArrayRef<llvm::Value*>  funcargs(Args);
	llvm::FunctionType *FType = FunctionType::get(Type::getInt32Ty(Context), argsRef, false);
	Constant* func = TheModule->getOrInsertFunction(string("printf"), FType);
	Value* v = Builder.CreateCall(func, funcargs);
	return v;
}

Value* readStmt::codegen(){
	Value* V = read->codegen();
	return V;
}


Value* readCands::codegen(){

	for (auto cs : vars_list){
		Value* V = ConstantInt::get(getGlobalContext(), llvm::APInt(32,1));
		llvm::Type* ScanfArgs[] = { Type::getInt8PtrTy(Context) };
		llvm::FunctionType *FType = FunctionType::get(Type::getInt32Ty(Context), ScanfArgs, true);
		Constant* func = TheModule->getOrInsertFunction(string("scanf"), FType);
		vector<Value* > Args;
		stringLiteral* temp_str = new stringLiteral(string("0%d0"));
		//strlit
		Value* tmp = temp_str->codegen();
		Args.push_back(tmp);
		Value* lhs_addr = cs->codegen();
		// location
		Args.push_back(lhs_addr);

		llvm::ArrayRef<llvm::Value*>  funcargs(Args);
		
		Value* v = Builder.CreateCall(func, funcargs);
	}
	return ConstantInt::get(getGlobalContext(), llvm::APInt(32,1));
}


Value* ifElseStmt::codegen(){
	Value *cond = condition->codegen();
	if(cond==0){
		errors++;
		return reportError::ErrorV("Invalid Expression in the IF");
	}
	Function * ThisFunction = MainF;
	BasicBlock *ifBlock = BasicBlock::Create(Context,"if",ThisFunction);
	BasicBlock *elseBlock = BasicBlock::Create(Context,"else",ThisFunction);
	BasicBlock *nextBlock = BasicBlock::Create(Context,"next",ThisFunction);
	Builder.CreateCondBr(cond, ifBlock, elseBlock);
	//begin if block
	Builder.SetInsertPoint(ifBlock);
	Value* ifval = if_block->codegen();
	if(ifval == 0){
		return 0;
	}
	Builder.CreateBr(nextBlock);

	ifBlock = Builder.GetInsertBlock();

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
	Function * ThisFunction = MainF;
	BasicBlock *whileBlock = BasicBlock::Create(Context,"while",ThisFunction);
	BasicBlock *nextBlock = BasicBlock::Create(Context,"next",ThisFunction);
	Builder.CreateCondBr(cond, whileBlock, nextBlock);
	//begin while block
	Builder.SetInsertPoint(whileBlock);
	Value* block = body->codegen();
	if(block == 0){
		return 0;
	}
	cond = condition->codegen();
	Builder.CreateCondBr(cond, whileBlock, nextBlock);

	// begin the next block  	

	Builder.SetInsertPoint(nextBlock);
	Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
	return V;
}


Value* gotoStmt::codegen(){
	Value *cond;
	Function * ThisFunction = MainF;
	if(GlobalLTable.find(location) == GlobalLTable.end()){
		errors++;
		return reportError::ErrorV("Goto not supported for blocks declared after this.");
	}
	BasicBlock *Block = GlobalLTable[location];
	BasicBlock *nextBlock = BasicBlock::Create(Context,"next", ThisFunction);
	cout << "asdf" << endl;
	if(condition==NULL)
		Builder.CreateBr(Block);
	else{
		cond = condition->codegen();
		Builder.CreateCondBr(cond, Block, nextBlock);
	}
	
	Builder.SetInsertPoint(nextBlock);
	
	Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
	return V;
}
Value* Assignment::codegen(){
	Value* lhs_addr = loc->codegen(); // lhs load
	
	Value* rhs = expr->codegen(); // rhs load
	if(expr->getEtype() == exprType::location){
		rhs = Builder.CreateLoad(rhs);
	}

	if(opr == "+="){
		Value* lhs_value = Builder.CreateLoad(lhs_addr);
		rhs = Builder.CreateAdd(rhs, lhs_value,"addEqualToTmp");
	}
	else if (opr == "-="){
		Value* lhs_value = Builder.CreateLoad(lhs_addr);
		rhs = Builder.CreateAdd(rhs, lhs_value,"subEqualToTmp");
	}
	Builder.CreateStore(rhs, lhs_addr);
	return ConstantInt::get(getGlobalContext(), APInt(32,1));
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

Value* forStmt::codegen(){
	Function * ThisFunction = MainF;
	BasicBlock *forBlock = BasicBlock::Create(Context,"for",ThisFunction);
	BasicBlock *nextBlock = BasicBlock::Create(Context,"next",ThisFunction);
	BasicBlock *upperBB=Builder.GetInsertBlock();
	Value* lhs_addr = var->codegen(); //get lhs addr
	if(lhs_addr==0){
		//error;
	}
	
	Value* start_val = min_range->codegen(); // start
	if(min_range->getEtype() == exprType::location){
		start_val = Builder.CreateLoad(start_val);
	}
	Builder.CreateStore(start_val, lhs_addr);

	Value* end_val = max_range->codegen(); // end
	if(max_range->getEtype() == exprType::location){
		end_val = Builder.CreateLoad(end_val);
	}

	Value* cond = Builder.CreateICmpEQ(start_val, end_val,"lecomparetmp");

	Builder.CreateCondBr(cond, nextBlock, forBlock);
	// Builder.CreateBr(forBlock);
	//begin if block
	Builder.SetInsertPoint(forBlock);
	PHINode *Variable = Builder.CreatePHI(Type::getInt32Ty(llvm::getGlobalContext()), 2, var->getVar());
  	Variable->addIncoming(start_val, upperBB);
	Value* ifval = body->codegen();
	if(ifval == 0){
		return 0;
	}

	//begin else block

	lhs_addr = var->codegen(); // lhs load
	Value* lhs = Builder.CreateLoad(lhs_addr);
	Value* step_value;
	if(flag){
		step_value = step->codegen(); // step load
		if(step->getEtype() == exprType::location){
			step_value = Builder.CreateLoad(step_value);
		}
	}
	else{
		step_value = ConstantInt::get(getGlobalContext(), APInt(32,step_int));
	}

	lhs = Builder.CreateAdd(lhs, step_value,"addEqualToTmp");
	Builder.CreateStore(lhs, lhs_addr);

	end_val = max_range->codegen(); // end
	if(max_range->getEtype() == exprType::location){
		end_val = Builder.CreateLoad(end_val);
	}
	cond = Builder.CreateICmpEQ(lhs, end_val,"lecomparetmp");
	BasicBlock *endBB = Builder.GetInsertBlock();
	Builder.CreateCondBr(cond, nextBlock, forBlock);
	// begin the next block  
	Builder.SetInsertPoint(nextBlock);
	Variable->addIncoming(lhs, endBB);

	Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
	return V;
}
Value* fieldDecl::codegen(){
  for(auto cs : var_list)
  {
    class Var* var=cs;
    llvm::Type *ty;
    ty=Type::getInt32Ty(Context);
    if(cs->isArray()==false)
    {
      TheModule->getOrInsertGlobal(cs->getName(),Builder.getInt32Ty());
      PointerType* ptrTy = PointerType::get(ty,0);
      GlobalVariable* gv = TheModule->getNamedGlobal(cs->getName());
      gv->setLinkage(GlobalValue::CommonLinkage);
      ConstantInt* const_int_val = ConstantInt::get(Context, APInt(32,0));
      gv->setInitializer(const_int_val);
    }
    else
    {
      int arrlg=cs->getLength();
      ArrayType* arrType= ArrayType::get(ty,arrlg);
      PointerType* PointerTy_1 = PointerType::get(ArrayType::get(ty,arrlg),0);
      GlobalVariable* gv = new GlobalVariable(*TheModule,arrType,false,GlobalValue::CommonLinkage,0,cs->getName());
      gv->setInitializer(ConstantAggregateZero::get(arrType));
    }
  }
  Value* v = ConstantInt::get(getGlobalContext(), APInt(32,500));
  return v;
}