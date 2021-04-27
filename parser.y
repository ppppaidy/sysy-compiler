/* parser.y */
/* parse the syntax */

%{
#define YYPARSER

#include <iostream>
#include "globals.h"
#include "scan.h"
#include "nodedef.h"
#include "parse.h"

#define YYSTYPE NodeBase*
static NodeBase* savedTree;
static int yylex();
int char2int(char*);
int yyerror(std::string);
%}

%expect 1

%token ENDFILE ERROR
%token IF ELSE WHILE BREAK CONTINUE RETURN
%token CONST INT VOID
%token ASSIGN EQ NEQ LT GT LEQ GEQ
%token ADD SUB MUL DIV MOD NOT AND OR
%token LPAREN RPAREN LBRACK RBRACK LBPAREN RBPAREN
%token ID NUM
%token COMMA SEMI

%%

program         :   compunit
                    {savedTree = $1;}
                ;

compunit        :   compunit decl
                    {
                        $$ = $1;
                        ((CompUnit*)$$)->nb.push_back((NodeBase*)$2);
                    }

                |   compunit funcdef
                    {
                        $$ = $1;
                        ((CompUnit*)$$)->nb.push_back((NodeBase*)$2);
                    }
                
                |   decl
                    {
                        $$ = new CompUnit;
                        ((CompUnit*)$$)->nb.push_back((NodeBase*)$1);
                    }
                
                |   funcdef
                    {
                        $$ = new CompUnit;
                        ((CompUnit*)$$)->nb.push_back((NodeBase*)$1);
                    }
                ;




decl            :   constdecl
                    {$$ = $1;}
                
                |   vardecl
                    {$$ = $1;}
                ;

constdecl       :   CONST INT constdefs SEMI
                    {$$ = $3;}
                ;

constdefs       :   constdefs COMMA constdef
                    {
                        $$ = $1;
                        ((ConstDecl*)$$)->cd.push_back((ConstDef*)$3);
                    }
                |   constdef
                    {
                        $$ = new ConstDecl;
                        ((ConstDecl*)$$)->cd.push_back((ConstDef*)$1);
                    }
                ;

constdef        :   identifier ASSIGN constinitval
                    {
                        $$ = new ConstDef;
                        ((ConstDef*)$$)->ident = (Identifier*)$1;
                        ((ConstDef*)$$)->civ = (ConstInitVal*)$3;
                    }
                |   identifier arr_constdef ASSIGN constinitval
                    {
                        $$ = $2;
                        ((ConstDef*)$$)->ident = (Identifier*)$1;
                        ((ConstDef*)$$)->civ = (ConstInitVal*)$4;
                    }
                ;

arr_constdef    :   arr_constdef LBRACK constexp RBRACK
                    {
                        $$ = $1;
                        ((ConstDef*)$$)->arr.push_back((ConstExp*)$3);
                    }
                |   LBRACK constexp RBRACK
                    {
                        $$ = new ConstDef;
                        ((ConstDef*)$$)->arr.push_back((ConstExp*)$2);
                    }
                ;

constinitval    :   constexp
                    {
                        $$ = new ConstInitVal;
                        ((ConstInitVal*)$$)->ce.push_back((NodeBase*)$1);
                        ((ConstInitVal*)$$)->has_bparen = 0;
                    }
                |   LBPAREN constinitvals RBPAREN
                    {$$ = $2;}
                |   LBPAREN RBPAREN
                    {
                        $$ = new ConstInitVal;
                        ((ConstInitVal*)$$)->has_bparen = 1;
                    }
                ;

constinitvals   :   constinitvals COMMA constinitval
                    {
                        $$ = $1;
                        ((ConstInitVal*)$$)->ce.push_back((NodeBase*)$3);
                    }
                |   constinitval
                    {
                        $$ = new ConstInitVal;
                        ((ConstInitVal*)$$)->has_bparen = 1;
                        ((ConstInitVal*)$$)->ce.push_back((NodeBase*)$1);
                    }
                ;




vardecl         :   INT vardefs SEMI
                    {$$ = $2;}
                ;

vardefs         :   vardefs COMMA vardef
                    {
                        $$ = $1;
                        ((VarDecl*)$$)->vd.push_back((VarDef*)$3);
                    }
                |   vardef
                    {
                        $$ = new VarDecl;
                        ((VarDecl*)$$)->vd.push_back((VarDef*)$1);
                    }
                ;

vardef          :   identifier
                    {
                        $$ = new VarDef;
                        ((VarDef*)$$)->ident = (Identifier*)$1;
                        ((VarDef*)$$)->iv = NULL;
                    }
                |   identifier arr_vardef
                    {
                        $$ = $2;
                        ((VarDef*)$$)->ident = (Identifier*)$1;
                        ((VarDef*)$$)->iv = (InitVal*)NULL;
                    }
                |   identifier ASSIGN initval
                    {
                        $$ = new VarDef;
                        ((VarDef*)$$)->ident = (Identifier*)$1;
                        ((VarDef*)$$)->iv = (InitVal*)$3;
                    }
                |   identifier arr_vardef ASSIGN initval
                    {
                        $$ = $2;
                        ((VarDef*)$$)->ident = (Identifier*)$1;
                        ((VarDef*)$$)->iv = (InitVal*)$4;
                    }
                ;

arr_vardef      :   arr_vardef LBRACK constexp RBRACK
                    {
                        $$ = $1;
                        ((VarDef*)$$)->arr.push_back((ConstExp*)$3);
                    }
                |   LBRACK constexp RBRACK
                    {
                        $$ = new VarDef;
                        ((VarDef*)$$)->arr.push_back((ConstExp*)$2);
                    }
                ;

initval         :   exp
                    {
                        $$ = new InitVal;
                        ((InitVal*)$$)->e.push_back((NodeBase*)$1);
                        ((InitVal*)$$)->has_bparen = 0;
                    }
                |   LBPAREN initvals RBPAREN
                    {$$ = $2;}
                |   LBPAREN RBPAREN
                    {
                        $$ = new InitVal;
                        ((InitVal*)$$)->has_bparen = 1;
                    }
                ;

initvals        :   initvals COMMA initval
                    {
                        $$ = $1;
                        ((InitVal*)$$)->e.push_back((NodeBase*)$3);
                    }
                |   initval
                    {
                        $$ = new InitVal;
                        ((InitVal*)$$)->has_bparen = 1;
                        ((InitVal*)$$)->e.push_back((NodeBase*)$1);
                    }
                ;




funcdef         :   VOID identifier LPAREN RPAREN block
                    {
                        $$ = new FuncDef;
                        ((FuncDef*)$$)->ident = (Identifier*)$2;
                        ((FuncDef*)$$)->body = (Block*)$5;
                    }
                |   INT identifier LPAREN RPAREN block
                    {
                        $$ = new FuncDef;
                        ((FuncDef*)$$)->ident = (Identifier*)$2;
                        ((FuncDef*)$$)->body = (Block*)$5;
                    }
                |   VOID identifier LPAREN funcfparams RPAREN block
                    {
                        $$ = $4;
                        ((FuncDef*)$$)->ident = (Identifier*)$2;
                        ((FuncDef*)$$)->body = (Block*)$6;
                    }
                |   INT identifier LPAREN funcfparams RPAREN block
                    {
                        $$ = $4;
                        ((FuncDef*)$$)->ident = (Identifier*)$2;
                        ((FuncDef*)$$)->body = (Block*)$6;
                    }
                ;

funcfparams     :   funcfparams COMMA funcfparam
                    {
                        $$ = $1;
                        ((FuncDef*)$$)->fp.push_back((FuncFParam*)$3);
                    }
                |   funcfparam
                    {
                        $$ = new FuncDef;
                        ((FuncDef*)$$)->fp.push_back((FuncFParam*)$1);
                    }
                ;

funcfparam      :   INT identifier
                    {
                        $$ = new FuncFParam;
                        ((FuncFParam*)$$)->ident = (Identifier*)$2;
                    }
                |   INT identifier arr_funcfparam
                    {
                        $$ = $3;
                        ((FuncFParam*)$$)->ident = (Identifier*)$2;
                    }
                ;

arr_funcfparam  :   LBRACK RBRACK
                    {
                        $$ = new FuncFParam;
                        ((FuncFParam*)$$)->ce.push_back(NULL);
                    }
                |   arr_funcfparam LBRACK constexp RBRACK
                    {
                        $$ = $1;
                        ((FuncFParam*)$$)->ce.push_back((ConstExp*)$3);
                    }
                ;
            



block           :   LBPAREN blockitems RBPAREN
                    {
                        $$ = $2;
                    }
                |   LBPAREN RBPAREN
                    {
                        $$ = new Block;
                    }
                ;

blockitems      :   blockitems blockitem
                    {
                        $$ = $1;
                        ((Block*)$$)->bi.push_back((BlockItem*)$2);
                    }
                |   blockitem
                    {
                        $$ = new Block;
                        ((Block*)$$)->bi.push_back((BlockItem*)$1);
                    }
                ;

blockitem       :   decl
                    {$$ = $1;}
                |   stmt
                    {$$ = $1;}
                ;

stmt            :   lval ASSIGN exp SEMI
                    {
                        $$ = new AssignStmt;
                        ((AssignStmt*)$$)->lv = (LVal*)$1;
                        ((AssignStmt*)$$)->e = (Exp*)$3;
                    }
                |   SEMI
                    {
                        $$ = new ExpStmt;
                        ((ExpStmt*)$$)->e = NULL;
                    }
                |   exp SEMI
                    {
                        $$ = new ExpStmt;
                        ((ExpStmt*)$$)->e = (Exp*)$1;
                    }
                |   block
                    {
                        $$ = new BlockStmt;
                        ((BlockStmt*)$$)->b = (Block*)$1;
                    }
                |   IF LPAREN cond RPAREN stmt
                    {
                        $$ = new IfStmt;
                        ((IfStmt*)$$)->c = (Cond*)$3;
                        ((IfStmt*)$$)->then_body = (Stmt*)$5;
                        ((IfStmt*)$$)->else_body = NULL;
                    }
                |   IF LPAREN cond RPAREN stmt ELSE stmt
                    {
                        $$ = new IfStmt;
                        ((IfStmt*)$$)->c = (Cond*)$3;
                        ((IfStmt*)$$)->then_body = (Stmt*)$5;
                        ((IfStmt*)$$)->else_body = (Stmt*)$7;
                    }
                |   WHILE LPAREN cond RPAREN stmt
                    {
                        $$ = new WhileStmt;
                        ((WhileStmt*)$$)->c = (Cond*)$3;
                        ((WhileStmt*)$$)->body = (Stmt*)$5;
                    }
                |   BREAK SEMI
                    {
                        $$ = new BreakStmt;
                    }
                |   CONTINUE SEMI
                    {
                        $$ = new ContinueStmt;
                    }
                |   RETURN SEMI
                    {
                        $$ = new ReturnStmt;
                        ((ReturnStmt*)$$)->e = NULL;
                    }
                |   RETURN exp SEMI
                    {
                        $$ = new ReturnStmt;
                        ((ReturnStmt*)$$)->e = (Exp*)$2;
                    }
                ;




exp             :   addexp
                    {
                        $$ = new Exp;
                        ((Exp*)$$)->ae = (AddExp*)$1;
                    }
                ;

cond            :   lorexp
                    {
                        $$ = new Cond;
                        ((Cond*)$$)->loe = (LOrExp*)$1;
                    }
                ;

lval            :   identifier
                    {
                        $$ = new LVal;
                        ((LVal*)$$)->ident = (Identifier*)$1;
                    }
                |   identifier arr_lval
                    {
                        $$ = $2;
                        ((LVal*)$$)->ident = (Identifier*)$1;
                    }
                ;

arr_lval        :   arr_lval LBRACK exp RBRACK
                    {
                        $$ = $1;
                        ((LVal*)$$)->e.push_back((Exp*)$3);
                    }
                |   LBRACK exp RBRACK
                    {
                        $$ = new LVal;
                        ((LVal*)$$)->e.push_back((Exp*)$2);
                    }
                ;

primaryexp      :   LPAREN exp RPAREN
                    {
                        $$ = new PrimaryExp;
                        ((PrimaryExp*)$$)->body = $2;
                    }
                |   lval
                    {
                        $$ = new PrimaryExp;
                        ((PrimaryExp*)$$)->body = $1;
                    }
                |   number
                    {
                        $$ = new PrimaryExp;
                        ((PrimaryExp*)$$)->body = $1;
                    }
                ;

unaryexp        :   primaryexp
                    {
                        $$ = $1;
                    }
                |   identifier LPAREN RPAREN
                    {
                        $$ = new FuncExp;
                        ((FuncExp*)$$)->ident = (Identifier*)$1;
                    }
                |   identifier LPAREN funcrparams RPAREN
                    {
                        $$ = $3;
                        ((FuncExp*)$$)->ident = (Identifier*)$1;
                    }
                |   ADD unaryexp
                    {
                        $$ = new UnaryExp;
                        ((UnaryExp*)$$)->uo = "+";
                        ((UnaryExp*)$$)->ue = (UnaryExp*)$2;
                    }
                |   SUB unaryexp
                    {
                        $$ = new UnaryExp;
                        ((UnaryExp*)$$)->uo = "-";
                        ((UnaryExp*)$$)->ue = (UnaryExp*)$2;
                    }
                |   NOT unaryexp
                    {
                        $$ = new UnaryExp;
                        ((UnaryExp*)$$)->uo = "!";
                        ((UnaryExp*)$$)->ue = (UnaryExp*)$2;
                    }
                ;

funcrparams     :   funcrparams COMMA exp
                    {
                        $$ = $1;
                        ((FuncExp*)$$)->params.push_back((Exp*)$3);
                    }
                |   exp
                    {
                        $$ = new FuncExp;
                        ((FuncExp*)$$)->params.push_back((Exp*)$1);
                    }
                ;




mulexp          :   mulexp MUL unaryexp
                    {
                        $$ = $1;
                        ((MulExp*)$$)->ue.push_back((UnaryExp*)$3);
                        ((MulExp*)$$)->ops.push_back("*");
                    }
                |   mulexp DIV unaryexp
                    {
                        $$ = $1;
                        ((MulExp*)$$)->ue.push_back((UnaryExp*)$3);
                        ((MulExp*)$$)->ops.push_back("/");
                    }
                |   mulexp MOD unaryexp
                    {
                        $$ = $1;
                        ((MulExp*)$$)->ue.push_back((UnaryExp*)$3);
                        ((MulExp*)$$)->ops.push_back("%");
                    }
                |   unaryexp
                    {
                        $$ = new MulExp;
                        ((MulExp*)$$)->ue.push_back((UnaryExp*)$1);
                    }
                ;

addexp          :   addexp ADD mulexp
                    {
                        $$ = $1;
                        ((AddExp*)$$)->me.push_back((MulExp*)$3);
                        ((AddExp*)$$)->ops.push_back("+");
                    }
                |   addexp SUB mulexp
                    {
                        $$ = $1;
                        ((AddExp*)$$)->me.push_back((MulExp*)$3);
                        ((AddExp*)$$)->ops.push_back("-");
                    }
                |   mulexp
                    {
                        $$ = new AddExp;
                        ((AddExp*)$$)->me.push_back((MulExp*)$1);
                    }
                ;
            
relexp          :   relexp LT addexp
                    {
                        $$ = $1;
                        ((RelExp*)$$)->ae.push_back((AddExp*)$3);
                        ((RelExp*)$$)->ops.push_back("<");
                    }
                |   relexp GT addexp
                    {
                        $$ = $1;
                        ((RelExp*)$$)->ae.push_back((AddExp*)$3);
                        ((RelExp*)$$)->ops.push_back(">");
                    }
                |   relexp LEQ addexp
                    {
                        $$ = $1;
                        ((RelExp*)$$)->ae.push_back((AddExp*)$3);
                        ((RelExp*)$$)->ops.push_back("<=");
                    }
                |   relexp GEQ addexp
                    {
                        $$ = $1;
                        ((RelExp*)$$)->ae.push_back((AddExp*)$3);
                        ((RelExp*)$$)->ops.push_back(">=");
                    }
                |   addexp
                    {
                        $$ = new RelExp;
                        ((RelExp*)$$)->ae.push_back((AddExp*)$1);
                    }
                ;

eqexp           :   eqexp EQ relexp
                    {
                        $$ = $1;
                        ((EqExp*)$$)->re.push_back((RelExp*)$3);
                        ((EqExp*)$$)->ops.push_back("==");
                    }
                |   eqexp NEQ relexp
                    {
                        $$ = $1;
                        ((EqExp*)$$)->re.push_back((RelExp*)$3);
                        ((EqExp*)$$)->ops.push_back("!=");
                    }
                |   relexp
                    {
                        $$ = new EqExp;
                        ((EqExp*)$$)->re.push_back((RelExp*)$1);
                    }
                ;

landexp         :   landexp AND eqexp
                    {
                        $$ = $1;
                        ((LAndExp*)$$)->ee.push_back((EqExp*)$3);
                    }
                |   eqexp
                    {
                        $$ = new LAndExp;
                        ((LAndExp*)$$)->ee.push_back((EqExp*)$1);
                    }
                ;

lorexp          :   lorexp OR landexp
                    {
                        $$ = $1;
                        ((LOrExp*)$$)->lae.push_back((LAndExp*)$3);
                    }
                |   landexp
                    {
                        $$ = new LOrExp;
                        ((LOrExp*)$$)->lae.push_back((LAndExp*)$1);
                    }
                ;

constexp        :   addexp
                    {
                        $$ = new ConstExp;
                        ((ConstExp*)$$)->ae = (AddExp*)$1;
                    }
                ;




identifier      :   ID
                    {
                        $$ = new Identifier;
                        ((Identifier*)$$)->id_name = std::string(tokenString);
                        //std::cerr<<"ident: "<<tokenString<<std::endl;
                    }
                ;

number          :   NUM
                    {
                        $$ = new Number;
                        ((Number*)$$)->num_val = char2int(tokenString);
                        //std::cerr<<"number: "<<tokenString<<std::endl;
                    }
                ;

%%

int yyerror(std::string message){
    std::cerr<<message<<std::endl;
    return 0;
}

static int yylex(){
    return getToken();
}

NodeBase* parse(){
    yyparse();
    return savedTree;
}

int char2int(char* a){
    if(a[0] == '0' && (a[1] == 'x' || a[1] == 'X')){
        int tmp = 0;
        for(char* p = a+2; *p != '\0'; p++)
            tmp = tmp*16 + 
                ((*p>='0' && *p<='9')? *p-'0' : ((*p>='a' && *p<='f')? *p-'a'+10 : *p-'A'+10));
        return tmp;
    }
    if(a[0] == '0'){
        int tmp = 0;
        for(char* p = a; *p != '\0'; p++)
            tmp = tmp*8 + *p - '0';
        return tmp;
    }
    int tmp = 0;
    for(char* p = a; *p != '\0'; p++)
        tmp = tmp*10 + *p - '0';
    return tmp;
}