// eeyoregen.cpp
// gen eeyore code

#include "eeyoregen.h"

int EeyoreGenner::printFinal(NodeBase* root){
    print(root);
    fprintf(o_file, "%s\n\n", code_string.c_str());
    return 0;
}

int EeyoreGenner::print(NodeBase* node){
    if(node == NULL) return 0;
    printf("%d : ", node->NodeID);
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

void EeyoreGenner::add_var_to_now_func(int id){
    vars_on_func[func_now].push_back(id);
    vars_type[id] = 1;
}

int EeyoreGenner::printIdentifier(Identifier* node){
    printf("Identifier : %s\n", node->id_name.c_str());
    if(return_val){
        return const_vars_val[str2vars[node->id_name][str2vars[node->id_name].size()-1]];
    }
    return str2vars[node->id_name][str2vars[node->id_name].size()-1];
}

int EeyoreGenner::printNumber(Number* node){
    printf("Number : %d\n", node->num_val);
    if(return_val){
        return node->num_val;
    }
    add_var_to_now_func(node->NodeID);
    code_string = gen_var(node->NodeID) + " = " + std::to_string(node->num_val) + "\n";
    return node->NodeID;
}

std::string EeyoreGenner::gen_var(int id){
    std::string name = std::to_string(id);
    if(vars_type[id] == 1) return "t"+name;
    if(vars_type[id] == 2) return "T"+name;
    if(vars_type[id] == 3) return "p"+name;
    return name;
}

std::string EeyoreGenner::gen_var_code(int id){
    std::string name = gen_var(id);
    if(var_arr_size[id] == 0) return "var "+name+"\n";
    else return "var "+std::to_string(var_arr_size[id])+" "+name+"\n";
}

int EeyoreGenner::printCompUnit(CompUnit* node){
    printf("CompUnit\n");
    std::string code_now = "";
    func_now = node->NodeID;
    compunit_id = node->NodeID;
    now_in_arr_init = 0;
    block_stack.push_back(compunit_id);
    for(size_t i = 0; i < node->nb.size(); i++){
        if(node->nb[i]->type_name != "FuncDef") continue;
        if(((FuncDef*)(node->nb[i]))->ident->id_name != "main") continue;
        main_id = ((FuncDef*)(node->nb[i]))->ident->NodeID;
    }
    printf("func : %d compunit : %d main : %d\n", func_now, compunit_id, main_id);
    for(size_t i = 0; i < node->nb.size(); i++){
        code_string = "";
        print(node->nb[i]);
        code_now = code_now + code_string;
    }
    code_string = code_now;
    for(size_t i = 0; i < vars_on_func[compunit_id].size(); i++){
        code_string = gen_var_code(vars_on_func[compunit_id][i]) + code_string;
    }
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
    std::string code_now = "";
    for(size_t i = 0; i < node->vd.size(); i++){
        code_string = "";
        print(node->vd[i]);
        code_now = code_now + code_string;
    }
    code_string = code_now;
    return 0;
}

int EeyoreGenner::printVarDef(VarDef* node){
    printf("VarDef\n");
    printf("%s %d %d\n", 
        node->ident->id_name.c_str(), func_now, block_stack[block_stack.size()-1]);
    str2vars[node->ident->id_name].push_back(node->NodeID);
    vars2str[node->NodeID] = node->ident->id_name;
    vars_on_func[func_now].push_back(node->NodeID);
    vars_type[node->NodeID] = 2;
    vars_on_block[block_stack[block_stack.size()-1]].push_back(node->NodeID);
    block_of_vars[node->NodeID] = block_stack[block_stack.size()-1];
    //print(node->ident);
    if(node->arr.size() == 0){
        if(node->iv == NULL){
            code_string = "";
        }
        else{
            code_string = "";
            int t = print(node->iv);
            code_string = code_string + gen_var(node->NodeID) + " = " + gen_var(t) + "\n";
        }
    }
    else{
        for(size_t i = 0; i < node->arr.size(); i++)
            print(node->arr[i]);
        now_in_arr_init = 1;
        print(node->iv);
        now_in_arr_init = 0;
    }
    return 0;
}

int EeyoreGenner::printInitVal(InitVal* node){
    printf("InitVal\n");
    if(!now_in_arr_init){
        return print(node->e[0]);
    }
    return 0;
}

int EeyoreGenner::printFuncDef(FuncDef* node){
    printf("FuncDef\n");
    int func_pre = func_now;
    func_now = node->NodeID;
    //print(node->ident);
    block_stack.push_back(node->body->NodeID);
    for(size_t i = 0; i < node->fp.size(); i++)
        print(node->fp[i]);
    block_stack.pop_back();
    print(node->body);

    for(size_t i = 0; i < vars_on_func[func_now].size(); i++){
        code_string = gen_var_code(vars_on_func[func_now][i]) + code_string;
    }

    code_string = "\nf_" + node->ident->id_name + " ["
        +std::to_string(node->fp.size()) + "]\n" + code_string;
    code_string = code_string + "return 0\n";
    code_string = code_string + "end f_" + node->ident->id_name+"\n\n";

    func_now = func_pre;

    return 0;
}

int EeyoreGenner::printFuncFParam(FuncFParam* node){
    printf("FuncFParam\n");
    return 0;
}

int EeyoreGenner::printBlock(Block* node){
    printf("Block\n");
    std::string code_now = "";
    block_stack.push_back(node->NodeID);
    for(size_t i = 0; i < node->bi.size(); i++){
        code_string = "";
        print(node->bi[i]);
        code_now = code_now + code_string;
    }
    code_string = code_now;
    block_stack.pop_back();
    int block_id = node->NodeID;
    for(size_t i = 0; i < vars_on_block[block_id].size(); i++){
        str2vars[vars2str[vars_on_block[block_id][i]]].pop_back();
    }
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
    std::string code_now = "";
    code_string = "";
    int l = print(node->lv);
    code_now = code_now + code_string;
    int lv_return_is_arr = return_is_arr;
    code_string = "";
    int r = print(node->e);
    code_now = code_now + code_string;
    if(lv_return_is_arr){
        code_now = code_now + gen_var(l) + "[0] = " + gen_var(r) + "\n";
    }
    else{
        code_now = code_now + gen_var(l) + " = " + gen_var(r) + "\n";
    }
    code_string = code_now;
    return 0;
}

int EeyoreGenner::printExpStmt(ExpStmt* node){
    printf("ExpStmt\n");
    if(node->e == NULL) return 0;
    print(node->e);
    return 0;
}

int EeyoreGenner::printBlockStmt(BlockStmt* node){
    printf("BlockStmt\n");
    print(node->b);
    return 0;
}

int EeyoreGenner::printIfStmt(IfStmt* node){
    printf("IfStmt\n");
    std::string code_now = "";
    code_string = "";
    int cc = print(node->c);
    code_now = code_now + code_string;
    code_string = "";
    int t = print(node->then_body);
    code_now = code_now + code_string;
    code_string = code_now;
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
    if(node->e == NULL){
        code_string = "return 0\n";
        return 0;
    }
    int t = print(node->e);
    code_string = code_string + "return " + gen_var(t) + "\n";
    return 0;
}

int EeyoreGenner::printExp(Exp* node){
    printf("Exp\n");
    return print(node->ae);
}

int EeyoreGenner::printCond(Cond* node){
    printf("Cond\n");
    return print(node->loe);
}

int EeyoreGenner::printLVal(LVal* node){
    printf("LVal\n");
    int id = str2vars[node->ident->id_name][str2vars[node->ident->id_name].size()-1];
    if(var_arr_size[id] == 0){
        if(return_val) return printIdentifier(node->ident);
        return id;
    }
    //arr
    return 0;
}

int EeyoreGenner::printPrimaryExp(PrimaryExp* node){
    printf("PrimaryExp\n");
    return print(node->body);
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
    if(node->ue.size() == 1) return print(node->ue[0]);
    add_var_to_now_func(node->NodeID);
    std::string code_now = "";
    code_string = "";
    int l = print(node->ue[0]);
    code_now = code_now + code_string;
    code_string = "";
    int r = print(node->ue[1]);
    code_now = code_now + code_string;
    code_now = code_now 
        + gen_var(node->NodeID) + " = " + gen_var(l) 
        + " " + node->ops[0] + " " + gen_var(r) + "\n";
    for(size_t i = 2; i < node->ue.size(); i++){
        code_string = "";
        r = print(node->ue[i]);
        code_now = code_now + code_string;
        code_now = code_now 
            + gen_var(node->NodeID) + " = " + gen_var(node->NodeID)
            + " " + node->ops[i-1] + " " + gen_var(r) + "\n";
    }
    code_string = code_now;
    return node->NodeID;
}

int EeyoreGenner::printAddExp(AddExp* node){
    printf("AddExp\n");
    if(node->me.size() == 1) return print(node->me[0]);
    add_var_to_now_func(node->NodeID);
    std::string code_now = "";
    code_string = "";
    int l = print(node->me[0]);
    code_now = code_now + code_string;
    code_string = "";
    int r = print(node->me[1]);
    code_now = code_now + code_string;
    code_now = code_now 
        + gen_var(node->NodeID) + " = " + gen_var(l) 
        + " " + node->ops[0] + " " + gen_var(r) + "\n";
    for(size_t i = 2; i < node->me.size(); i++){
        code_string = "";
        r = print(node->me[i]);
        code_now = code_now + code_string;
        code_now = code_now 
            + gen_var(node->NodeID) + " = " + gen_var(node->NodeID)
            + " " + node->ops[i-1] + " " + gen_var(r) + "\n";
    }
    code_string = code_now;
    return node->NodeID;
}

int EeyoreGenner::printRelExp(RelExp* node){
    printf("RelExp\n");
    if(node->ae.size() == 1) return print(node->ae[0]);
    add_var_to_now_func(node->NodeID);
    std::string code_now = "";
    code_string = "";
    int l = print(node->ae[0]);
    code_now = code_now + code_string;
    code_string = "";
    int r = print(node->ae[1]);
    code_now = code_now + code_string;
    code_now = code_now 
        + gen_var(node->NodeID) + " = " + gen_var(l) 
        + " " + node->ops[0] + " " + gen_var(r) + "\n";
    for(size_t i = 2; i < node->ae.size(); i++){
        code_string = "";
        r = print(node->ae[i]);
        code_now = code_now + code_string;
        code_now = code_now 
            + gen_var(node->NodeID) + " = " + gen_var(node->NodeID)
            + " " + node->ops[i-1] + " " + gen_var(r) + "\n";
    }
    code_string = code_now;
    return node->NodeID;
}

int EeyoreGenner::printEqExp(EqExp* node){
    printf("EqExp\n");
    if(node->re.size() == 1) return print(node->re[0]);
    add_var_to_now_func(node->NodeID);
    std::string code_now = "";
    code_string = "";
    int l = print(node->re[0]);
    code_now = code_now + code_string;
    code_string = "";
    int r = print(node->re[1]);
    code_now = code_now + code_string;
    code_now = code_now 
        + gen_var(node->NodeID) + " = " + gen_var(l) 
        + " " + node->ops[0] + " " + gen_var(r) + "\n";
    for(size_t i = 2; i < node->re.size(); i++){
        code_string = "";
        r = print(node->re[i]);
        code_now = code_now + code_string;
        code_now = code_now 
            + gen_var(node->NodeID) + " = " + gen_var(node->NodeID)
            + " " + node->ops[i-1] + " " + gen_var(r) + "\n";
    }
    code_string = code_now;
    return node->NodeID;
}

int EeyoreGenner::printLAndExp(LAndExp* node){
    printf("LAndExp\n");
    if(node->ee.size() == 1) return print(node->ee[0]);
    add_var_to_now_func(node->NodeID);
    std::string code_now = "";
    code_now = gen_var(node->NodeID) + " = 1\n";
    for(size_t i = 0; i < node->ee.size(); i++){
        code_string = "";
        int r = print(node->ee[i]);
        code_now = code_now + code_string;
        code_now = code_now 
            + gen_var(node->NodeID) + " = " + gen_var(node->NodeID)
            + " && " + gen_var(r) + "\n";
        code_now = code_now
            + "if " + gen_var(node->NodeID) + " == 0 goto l" 
            + std::to_string(node->NodeID) + "0\n";
    }
    code_now = code_now + "l" + std::to_string(node->NodeID) + "0:\n";
    code_string = code_now;
    return node->NodeID;
}

int EeyoreGenner::printLOrExp(LOrExp* node){
    printf("LOrExp\n");
    if(node->lae.size() == 1) return print(node->lae[0]);
    add_var_to_now_func(node->NodeID);
    std::string code_now = "";
    code_now = gen_var(node->NodeID) + " = 0\n";
    for(size_t i = 0; i < node->lae.size(); i++){
        code_string = "";
        int r = print(node->lae[i]);
        code_now = code_now + code_string;
        code_now = code_now 
            + gen_var(node->NodeID) + " = " + gen_var(node->NodeID)
            + " || " + gen_var(r) + "\n";
        code_now = code_now
            + "if " + gen_var(node->NodeID) + " != 0 goto l" 
            + std::to_string(node->NodeID) + "0\n";
    }
    code_now = code_now + "l" + std::to_string(node->NodeID) + "0:\n";
    code_string = code_now;
    return node->NodeID;
}

int EeyoreGenner::printConstExp(ConstExp* node){
    printf("ConstExp\n");
    return 0;
}