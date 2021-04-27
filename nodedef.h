// nodedef.h
// define ast nodes

#ifndef _NODEDEF_H_
#define _NODEDEF_H_

#include <string>
#include <vector>

class NodeBase;
class Identifier;
class Number;
class CompUnit;
class Decl;
class ConstDecl;
class ConstDef;
class ConstInitVal;
class VarDecl;
class VarDef;
class InitVal;
class FuncDef;
class FuncFParam;
class Block;
class BlockItem;
class Stmt;
class AssignStmt;
class ExpStmt;
class BlockStmt;
class IfStmt;
class WhileStmt;
class BreakStmt;
class ContinueStmt;
class ReturnStmt;
class Exp;
class Cond;
class LVal;
class PrimaryExp;
class FuncExp;
class UnaryExp;
class UnaryOp;
class MulExp;
class AddExp;
class RelExp;
class EqExp;
class LAndExp;
class LOrExp;
class ConstExp;

class NodeBase{
    public:
        static int NodeNum;
        NodeBase() {NodeID = NodeNum++;}
        std::string type_name;
        int NodeID;
};

class CompUnit : public NodeBase{
    public:
        CompUnit() {type_name = "CompUnit";}
        std::vector<NodeBase*> nb;
};

class BlockItem : public NodeBase{
    public:
        BlockItem() {type_name = "BlockItem";}
};

class Decl : public BlockItem{
    public:
        Decl() {type_name = "Decl";}
};

class ConstDecl : public Decl{
    public:
        ConstDecl() {type_name = "ConstDecl";}
        std::vector<ConstDef*> cd;
};

class ConstDef : public NodeBase{
    public:
        ConstDef() {type_name = "ConstDef";}
        Identifier* ident;
        std::vector<ConstExp*> arr;
        ConstInitVal* civ;
};

class ConstInitVal : public NodeBase{
    public:
        ConstInitVal(){type_name = "ConstInitVal";}
        std::vector<NodeBase*> ce;
        int has_bparen;
};

class VarDecl : public NodeBase{
    public:
        VarDecl() {type_name = "VarDecl";}
        std::vector<VarDef*> vd;
};

class VarDef : public NodeBase{
    public:
        VarDef() {type_name = "VarDef";}
        Identifier* ident;
        std::vector<ConstExp*> arr;
        InitVal* iv;
};

class InitVal : public NodeBase{
    public:
        InitVal() {type_name = "InitVal";}
        std::vector<NodeBase*> e;
        int has_bparen;
};

class FuncDef : public NodeBase{
    public:
        FuncDef() {type_name = "FuncDef";}
        Identifier* ident;
        std::vector<FuncFParam*> fp;
        Block* body;
};

class FuncFParam : public NodeBase{
    public:
        FuncFParam() {type_name = "FuncFParam";}
        Identifier* ident;
        std::vector<ConstExp*> ce;
};

class Block : public NodeBase{
    public:
        Block() {type_name = "Block";}
        std::vector<BlockItem*> bi;
};

class Stmt : public BlockItem{
    public:
        Stmt() {type_name = "Stmt";}
};

class AssignStmt : public Stmt{
    public:
        AssignStmt() {type_name = "AssignStmt";}
        LVal* lv;
        Exp* e;
};

class ExpStmt : public Stmt{
    public:
        ExpStmt() {type_name = "ExpStmt";}
        Exp* e;
};

class BlockStmt : public Stmt{
    public:
        BlockStmt() {type_name = "BlockStmt";}
        Block* b;
};

class IfStmt : public Stmt{
    public:
        IfStmt() {type_name = "IfStmt";}
        Cond* c;
        Stmt* then_body;
        Stmt* else_body;
};

class WhileStmt : public Stmt{
    public:
        WhileStmt() {type_name = "WhileStmt";}
        Cond* c;
        Stmt* body;
};

class BreakStmt : public Stmt{
    public:
        BreakStmt() {type_name = "BreakStmt";}
};

class ContinueStmt : public Stmt{
    public:
        ContinueStmt() {type_name = "ContinueStmt";}
};

class ReturnStmt : public Stmt{
    public:
        ReturnStmt() {type_name = "ReturnStmt";}
        Exp* e;
};

class Exp : public NodeBase{
    public:
        Exp() {type_name = "Exp";}
        LOrExp* ae;
};

class Cond : public NodeBase{
    public:
        Cond() {type_name = "Cond";}
        LOrExp* loe;
};

class LVal : public NodeBase{
    public:
        LVal() {type_name = "LVal";}
        Identifier* ident;
        std::vector<Exp*> e;
};

class UnaryExp : public NodeBase{
    public:
        UnaryExp() {type_name = "UnaryExp";}
        std::string uo;
        UnaryExp* ue;
};

class PrimaryExp : public UnaryExp{
    public:
        PrimaryExp() {type_name = "PrimaryExp";}
        NodeBase* body;
};

class FuncExp : public UnaryExp{
    public:
        FuncExp() {type_name = "FuncExp";}
        Identifier* ident;
        std::vector<Exp*> params;
};

class MulExp : public NodeBase{
    public:
        MulExp() {type_name = "MulExp";}
        std::vector<UnaryExp*> ue;
        std::vector<std::string> ops;
};

class AddExp : public NodeBase{
    public:
        AddExp() {type_name = "AddExp";}
        std::vector<MulExp*> me;
        std::vector<std::string> ops;
};

class RelExp : public NodeBase{
    public:
        RelExp() {type_name = "RelExp";}
        std::vector<AddExp*> ae;
        std::vector<std::string> ops;
};

class EqExp : public NodeBase{
    public:
        EqExp() {type_name = "EqExp";}
        std::vector<RelExp*> re;
        std::vector<std::string> ops;
};

class LAndExp : public NodeBase{
    public:
        LAndExp() {type_name = "LAndExp";}
        std::vector<EqExp*> ee;
};

class LOrExp : public NodeBase{
    public:
        LOrExp() {type_name = "LOrExp";}
        std::vector<LAndExp*> lae;
};

class ConstExp : public NodeBase{
    public:
        ConstExp() {type_name = "ConstExp";}
        LOrExp* ae;
};

class Identifier : public NodeBase{
    public:
        Identifier() {type_name = "Identifier";}
        std::string id_name;
};

class Number : public NodeBase{
    public:
        Number() {type_name = "Number";};
        int num_val;
};

#endif