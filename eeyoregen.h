// eeyoregen.h
// gen eeyore code

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include "nodedef.h"

class EeyoreGenner{
    public:
        FILE* o_file;
        EeyoreGenner(FILE* o_file_):o_file(o_file_){}
        int printFinal(NodeBase* root);
        int print(NodeBase* node);
        int printIdentifier(Identifier* node);
        int printNumber(Number* node);
        int printCompUnit(CompUnit* node);
        int printDecl(Decl* node);
        int printConstDecl(ConstDecl* node);
        int printConstDef(ConstDef* node);
        int printConstInitVal(ConstInitVal* node);
        int printVarDecl(VarDecl* node);
        int printVarDef(VarDef* node);
        int printInitVal(InitVal* node);
        int printFuncDef(FuncDef* node);
        int printFuncFParam(FuncFParam* node);
        int printBlock(Block* node);
        int printBlockItem(BlockItem* node);
        int printStmt(Stmt* node);
        int printAssignStmt(AssignStmt* node);
        int printExpStmt(ExpStmt* node);
        int printBlockStmt(BlockStmt* node);
        int printIfStmt(IfStmt* node);
        int printWhileStmt(WhileStmt* node);
        int printBreakStmt(BreakStmt* node);
        int printContinueStmt(ContinueStmt* node);
        int printReturnStmt(ReturnStmt* node);
        int printExp(Exp* node);
        int printCond(Cond* node);
        int printLVal(LVal* node);
        int printPrimaryExp(PrimaryExp* node);
        int printFuncExp(FuncExp* node);
        int printUnaryExp(UnaryExp* node);
        int printUnaryOp(UnaryOp* node);
        int printMulExp(MulExp* node);
        int printAddExp(AddExp* node);
        int printRelExp(RelExp* node);
        int printEqExp(EqExp* node);
        int printLAndExp(LAndExp* node);
        int printLOrExp(LOrExp* node);
        int printConstExp(ConstExp* node);
};