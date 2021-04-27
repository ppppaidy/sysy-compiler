// eeyoregen.h
// gen eeyore code

#ifndef _EEYOREGEN_H_
#define _EEYOREGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <unordered_map>
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

        std::string gen_var_code(int id);
        std::string gen_var(int id);
        std::string gen_var_with_arr(int id);
        void add_var_to_now_func(int id);

        //string for code
        std::string code_string;

        int compunit_id;
        int main_id;

        //bool indicate whether return val or nodeid
        int return_val;

        //indicate whether the return result is val
        //0->val
        //1->t0
        //2->T0
        //3->p0
        int return_is_val;

        //whether the return id is a arr
        int return_is_arr;

        //0->val
        //1->t0
        //2->T0
        //3->p0
        std::unordered_map<int, int> vars_type;

        //func -> vector of vars
        //store definition of vars on func
        std::unordered_map<int, std::vector<int> > vars_on_func;

        //var_name -> vector of vars
        std::unordered_map<std::string, std::vector<int> > str2vars;
        //var id -> var_name
        std::unordered_map<int, std::string> vars2str;

        //var arr size
        std::unordered_map<int, int> var_arr_size;
        std::unordered_map<int, std::vector<int> > var_arr_size_vec;

        //block -> vector of vars
        std::unordered_map<int, std::vector<int> > vars_on_block;
        //var -> block
        std::unordered_map<int, int> block_of_vars;

        //func id now in
        int func_now;

        //stack of blockid
        std::vector<int> block_stack;

        //const vars -> int
        std::unordered_map<int, int> const_vars_val;

        //used for arr init
        int now_in_arr_init;
        int now_arr;
        int now_arr_step;
        int now_arr_size;
        int now_arr_layer;
        int now_arr_pos;

        //stack of while stmt id
        std::vector<int> while_stack;

        //var_id -> param_id
        std::unordered_map<int, int> var2param;

        int now_in_assign_l;

        std::string init_on_main;
};

#endif