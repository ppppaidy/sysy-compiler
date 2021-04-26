// eeyoregen.cpp
// gen eeyore code

#include "eeyoregen.h"

int EeyoreGenner::printFinal(NodeBase* root){
    print(root);
    return 0;
}

int EeyoreGenner::print(NodeBase* node){
    if(node == NULL) return 0;
    if(node->type_name == "Identifier") return printIdentifier((Identifier*)node);
    if(node->type_name == "Number") return printNumber((Number*)node);
    if(node->type_name == "CompUnit") return printCompUnit((CompUnit*)node);
    if(node->type_name == "Decl") return printDecl((Decl*)node);
    if(node->type_name == "ConstDecl") return printConstDecl((ConstDecl*)node);
    if(node->type_name == "ConstDef") return printConstDef((ConstDef*)node);
    if(node->type_name == "ConstInitVal") return printConstInitVal((ConstInitVal*)node);
    if(node->type_name == "VarDecl") return printVarDecl((VarDecl*)node);
    if(node->type_name == "VarDef") return printVarDef((VarDef*)node);
    if(node->type_name == "InitVal") return printInitVal((InitVal*)node);
    if(node->type_name == "FuncDef") return printFuncDef((FuncDef*)node);
    if(node->type_name == "FuncFParam") return printFuncFParam((FuncFParam*)node);
    if(node->type_name == "Block") return printBlock((Block*)node);
    if(node->type_name == "BlockItem") return printBlockItem((BlockItem*)node);
    if(node->type_name == "Stmt") return printStmt((Stmt*)node);
    if(node->type_name == "AssignStmt") return printAssignStmt((AssignStmt*)node);
    if(node->type_name == "ExpStmt") return printExpStmt((ExpStmt*)node);
    if(node->type_name == "BlockStmt") return printBlockStmt((BlockStmt*)node);
    if(node->type_name == "IfStmt") return printIfStmt((IfStmt*)node);
    if(node->type_name == "WhileStmt") return printWhileStmt((WhileStmt*)node);
    if(node->type_name == "BreakStmt") return printBreakStmt((BreakStmt*)node);
    if(node->type_name == "ContinueStmt") return printContinueStmt((ContinueStmt*)node);
    if(node->type_name == "ReturnStmt") return printReturnStmt((ReturnStmt*)node);
    if(node->type_name == "Exp") return printExp((Exp*)node);
    if(node->type_name == "Cond") return printCond((Cond*)node);
    if(node->type_name == "LVal") return printLVal((LVal*)node);
    if(node->type_name == "PrimaryExp") return printPrimaryExp((PrimaryExp*)node);
    if(node->type_name == "FuncExp") return printFuncExp((FuncExp*)node);
    if(node->type_name == "UnaryExp") return printUnaryExp((UnaryExp*)node);
    if(node->type_name == "UnaryOp") return printUnaryOp((UnaryOp*)node);
    if(node->type_name == "MulExp") return printMulExp((MulExp*)node);
    if(node->type_name == "AddExp") return printAddExp((AddExp*)node);
    if(node->type_name == "RelExp") return printRelExp((RelExp*)node);
    if(node->type_name == "EqExp") return printEqExp((EqExp*)node);
    if(node->type_name == "LAndExp") return printLAndExp((LAndExp*)node);
    if(node->type_name == "LOrExp") return printLOrExp((LOrExp*)node);
    if(node->type_name == "ConstExp") return printConstExp((ConstExp*)node);
    return 0;
}

int EeyoreGenner::printIdentifier(Identifier* node){
    printf("Identifier\n");
    return 0;
}

int EeyoreGenner::printNumber(Number* node){
    printf("Number\n");
    return 0;
}

int EeyoreGenner::printCompUnit(CompUnit* node){
    printf("CompUnit\n");
    return 0;
}

int EeyoreGenner::printDecl(Decl* node){
    printf("Decl\n");
    return 0;
}

int EeyoreGenner::printConstDecl(ConstDecl* node){
    printf("ConstDecl\n");
    return 0;
}

int EeyoreGenner::printConstDef(ConstDef* node){
    printf("ConstDef\n");
    return 0;
}

int EeyoreGenner::printConstInitVal(ConstInitVal* node){
    printf("ConstInitVal\n");
    return 0;
}

int EeyoreGenner::printVarDecl(VarDecl* node){
    printf("VarDecl\n");
    return 0;
}

int EeyoreGenner::printVarDef(VarDef* node){
    printf("VarDef\n");
    return 0;
}

int EeyoreGenner::printInitVal(InitVal* node){
    printf("InitVal\n");
    return 0;
}

int EeyoreGenner::printFuncDef(FuncDef* node){
    printf("FuncDef\n");
    return 0;
}

int EeyoreGenner::printFuncFParam(FuncFParam* node){
    printf("FuncFParam\n");
    return 0;
}

int EeyoreGenner::printBlock(Block* node){
    printf("Block\n");
    return 0;
}

int EeyoreGenner::printBlockItem(BlockItem* node){
    printf("BlockItem\n");
    return 0;
}

int EeyoreGenner::printStmt(Stmt* node){
    printf("Stmt\n");
    return 0;
}

int EeyoreGenner::printAssignStmt(AssignStmt* node){
    printf("AssignStmt\n");
    return 0;
}

int EeyoreGenner::printExpStmt(ExpStmt* node){
    printf("ExpStmt\n");
    return 0;
}

int EeyoreGenner::printBlockStmt(BlockStmt* node){
    printf("BlockStmt\n");
    return 0;
}

int EeyoreGenner::printIfStmt(IfStmt* node){
    printf("IfStmt\n");
    return 0;
}

int EeyoreGenner::printWhileStmt(WhileStmt* node){
    printf("WhileStmt\n");
    return 0;
}

int EeyoreGenner::printBreakStmt(BreakStmt* node){
    printf("BreakStmt\n");
    return 0;
}

int EeyoreGenner::printContinueStmt(ContinueStmt* node){
    printf("ContinueStmt\n");
    return 0;
}

int EeyoreGenner::printReturnStmt(ReturnStmt* node){
    printf("ReturnStmt\n");
    return 0;
}

int EeyoreGenner::printExp(Exp* node){
    printf("Exp\n");
    return 0;
}

int EeyoreGenner::printCond(Cond* node){
    printf("Cond\n");
    return 0;
}

int EeyoreGenner::printLVal(LVal* node){
    printf("LVal\n");
    return 0;
}

int EeyoreGenner::printPrimaryExp(PrimaryExp* node){
    printf("PrimaryExp\n");
    return 0;
}

int EeyoreGenner::printFuncExp(FuncExp* node){
    printf("FuncExp\n");
    return 0;
}

int EeyoreGenner::printUnaryExp(UnaryExp* node){
    printf("UnaryExp\n");
    return 0;
}

int EeyoreGenner::printUnaryOp(UnaryOp* node){
    printf("UnaryOp\n");
    return 0;
}

int EeyoreGenner::printMulExp(MulExp* node){
    printf("MulExp\n");
    return 0;
}

int EeyoreGenner::printAddExp(AddExp* node){
    printf("AddExp\n");
    return 0;
}

int EeyoreGenner::printRelExp(RelExp* node){
    printf("RelExp\n");
    return 0;
}

int EeyoreGenner::printEqExp(EqExp* node){
    printf("EqExp\n");
    return 0;
}

int EeyoreGenner::printLAndExp(LAndExp* node){
    printf("LAndExp\n");
    return 0;
}

int EeyoreGenner::printLOrExp(LOrExp* node){
    printf("LOrExp\n");
    return 0;
}

int EeyoreGenner::printConstExp(ConstExp* node){
    printf("ConstExp\n");
    return 0;
}