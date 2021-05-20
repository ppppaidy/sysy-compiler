// riscvgen.cpp
// gen riscv code

#include "riscvgen.h"

int RiscvGenner::printFinal(){
    getTiggerCode();
    genRiscvCode();
    std::ofstream output_file(o_file, std::ios::out);
    output_file<<riscvcode;
    return 0;
}

int RiscvGenner::getTiggerCode(){
    std::ifstream input_file(i_file, std::ios::in);
    std::string stmt;
    while(std::getline(input_file, stmt, '\n')){
        std::stringstream input_stmt(stmt);
        std::string word;
        tiggercode.push_back(std::vector<std::string>(0));
        while(input_stmt>>word){
            tiggercode[tiggercode.size()-1].push_back(word);
        }
    }
    return 0;
}

int RiscvGenner::genRiscvCode(){
    riscvcode = "";
    inside_func = 0;
    for(int pos = 0; pos < tiggercode.size(); pos++){
        if(tiggercode[pos].size() == 0) continue;
        if(!inside_func){
            if(tiggercode[pos][0][0] == 'f'){
                std::string funcname = tiggercode[pos][0].substr(2);
                inside_func = 1;
                funccode = "";
                funccode = funccode + "  .text\n";
                funccode = funccode + "  .align\t2\n";
                funccode = funccode + "  .global\t" + funcname + "\n";
                funccode = funccode + "  .type\t\t" + funcname + ", @function\n";
                funccode = funccode + funcname + ":\n";
                STK = atoi(tiggercode[pos][2].substr(1,tiggercode[pos][2].length()-2).c_str());
                STK = (STK/4+1)*16;
                funccode = funccode + "  addi\t\tsp, sp, -" + std::to_string(STK) + "\n";
                funccode = funccode + "  sw\t\tra, " + std::to_string(STK-4) + "(sp)\n";
                funccodetail = "  .size\t\t" + funcname + ", .-" + funcname + "\n\n";
            }
            else if(tiggercode[pos][2] == "malloc"){
                riscvcode = riscvcode + "  .comm\t\t" + tiggercode[pos][0] + ", "
                    + tiggercode[pos][3] + ", 4\n\n";
            }
            else{
                riscvcode = riscvcode + "  .global\t" + tiggercode[pos][0] + "\n";
                riscvcode = riscvcode + "  .section\t.sdata\n";
                riscvcode = riscvcode + "  .align\t2\n";
                riscvcode = riscvcode + "  .type\t\t" + tiggercode[pos][0] + ", @object\n";
                riscvcode = riscvcode + "  .size\t\t" + tiggercode[pos][0] + ", 4\n";
                riscvcode = riscvcode + tiggercode[pos][0] + ":\n";
                riscvcode = riscvcode + "  .word\t\t" + tiggercode[pos][2] + "\n\n";
            }
        }
        else{
            if(tiggercode[pos][0] == "end"){
                riscvcode = riscvcode + funccode + funccodetail;
                inside_func = 0;
            }
            else if(tiggercode[pos][0] == "if"){
                std::string reg1 = tiggercode[pos][1];
                std::string reg2 = tiggercode[pos][3];
                std::string label = tiggercode[pos][5];
                std::string op = tiggercode[pos][2];
                if(op == "<")
                    funccode = funccode + "  blt\t\t" + reg1 + ", " + reg2 + ", ." + label + "\n";
                else if(op == ">")
                    funccode = funccode + "  bgt\t\t" + reg1 + ", " + reg2 + ", ." + label + "\n";
                else if(op == "<=")
                    funccode = funccode + "  ble\t\t" + reg1 + ", " + reg2 + ", ." + label + "\n";
                else if(op == ">=")
                    funccode = funccode + "  bge\t\t" + reg1 + ", " + reg2 + ", ." + label + "\n";
                else if(op == "!=")
                    funccode = funccode + "  bne\t\t" + reg1 + ", " + reg2 + ", ." + label + "\n";
                else
                    funccode = funccode + "  beq\t\t" + reg1 + ", " + reg2 + ", ." + label + "\n";
            }
            else if(tiggercode[pos][0] == "goto"){
                funccode = funccode + "  j\t\t\t." + tiggercode[pos][1] + "\n";
            }
            else if(tiggercode[pos][0] == "load"){
                if(tiggercode[pos][1][0] == 'v'){
                    std::string reg = tiggercode[pos][2];
                    std::string g_var = tiggercode[pos][1];
                    funccode = funccode + "  lui\t\t" + reg + ", %hi(" + g_var + ")\n";
                    funccode = funccode + "  lw\t\t" + reg + ", %lo(" + g_var + ")(" + reg + ")\n";
                }
                else{
                    std::string imm_s = tiggercode[pos][1];
                    int imm = atoi(imm_s.c_str())*4;
                    if(imm < -2048 || imm > 2047){
                        funccode = funccode + "  li\t\tt0, " + std::to_string(imm) + "\n";
                        imm_s = "t0";
                    }
                    else imm_s = std::to_string(imm);
                    funccode = funccode + "  lw\t\t" + tiggercode[pos][2] + ", " + imm_s + "(sp)\n";
                }
            }
            else if(tiggercode[pos][0] == "loadaddr"){
                if(tiggercode[pos][1][0] == 'v'){
                    std::string reg = tiggercode[pos][2];
                    std::string g_var = tiggercode[pos][1];
                    funccode = funccode + "  la\t\t" + reg + ", " + g_var + "\n";
                }
                else{
                    std::string imm_s = tiggercode[pos][1];
                    int imm = atoi(imm_s.c_str())*4;
                    if(imm < -2048 || imm > 2047){
                        funccode = funccode + "  li\t\tt0, " + std::to_string(imm) + "\n";
                        imm_s = "t0";
                    }
                    else imm_s = std::to_string(imm);
                    funccode = funccode + "  addi\t\t" + tiggercode[pos][2] + ", sp, " + imm_s + "\n";
                }
            }
            else if(tiggercode[pos][0][0] == 'l'){
                funccode = funccode + "." + tiggercode[pos][0] + "\n";
            }
            else if(tiggercode[pos][0] == "call"){
                funccode = funccode + "  call\t\t" + tiggercode[pos][1].substr(2) + "\n";
            }
            else if(tiggercode[pos][0] == "return"){
                funccode = funccode + "  lw\t\tra, " + std::to_string(STK-4) + "(sp)\n";
                funccode = funccode + "  addi\t\tsp, sp, " + std::to_string(STK) + "\n";
                funccode = funccode + "  ret\n";
            }
            else if(tiggercode[pos][0] == "store"){
                std::string imm_s = tiggercode[pos][2];
                int imm = atoi(imm_s.c_str())*4;
                if(imm < -2048 || imm > 2047){
                    funccode = funccode + "  li\t\tt0, " + std::to_string(imm) + "\n";
                    imm_s = "t0";
                }
                else imm_s = std::to_string(imm);
                funccode = funccode + "  sw\t\t" + tiggercode[pos][1] + ", " + imm_s + "(sp)\n";
            }
            else if(tiggercode[pos][0][tiggercode[pos][0].size()-1] == ']'){
                std::string reg1 = tiggercode[pos][0].substr(0, tiggercode[pos][0].find('['));
                std::string imm_s = tiggercode[pos][0].substr(tiggercode[pos][0].find('[') + 1);
                imm_s = imm_s.substr(0, imm_s.length()-1);
                int imm = atoi(imm_s.c_str());
                if(imm < -2048 || imm > 2047){
                    funccode = funccode + "  li\t\tt0, " + std::to_string(imm) + "\n";
                    imm_s = "t0";
                }
                std::string reg2 = tiggercode[pos][2];
                funccode = funccode + "  sw\t\t" + reg2 + ", " + imm_s + "(" + reg1 + ")\n";
            }
            else if(tiggercode[pos][2][tiggercode[pos][2].size()-1] == ']'){
                std::string reg1 = tiggercode[pos][0];
                std::string imm_s = tiggercode[pos][2].substr(tiggercode[pos][2].find('[') + 1);
                imm_s = imm_s.substr(0, imm_s.length()-1);
                int imm = atoi(imm_s.c_str());
                if(imm < -2048 || imm > 2047){
                    funccode = funccode + "  li\t\tt0, " + std::to_string(imm) + "\n";
                    imm_s = "t0";
                }
                std::string reg2 = tiggercode[pos][2].substr(0, tiggercode[pos][2].find('['));
                funccode = funccode + "  lw\t\t" + reg1 + ", " + imm_s + "(" + reg2 + ")\n";
            }
            else if(tiggercode[pos].size() == 3){
                std::string reg1 = tiggercode[pos][0];
                std::string reg2 = tiggercode[pos][2];
                if(reg2[0]<'0' || reg2[0]>'9')
                    funccode = funccode + "  mv\t\t" + reg1 + ", " + reg2 + "\n";
                else
                    funccode = funccode + "  li\t\t" + reg1 + ", " + reg2 + "\n";
            }
            else if(tiggercode[pos].size() == 4){
                std::string reg1 = tiggercode[pos][0];
                std::string reg2 = tiggercode[pos][3];
                std::string op = tiggercode[pos][2];
                if(op == "-")
                    funccode = funccode + "  neg\t\t" + reg1 + ", " + reg2 + "\n";
                else
                    funccode = funccode + "  seqz\t\t" + reg1 + ", " + reg2 + "\n";
            }
            else{
                std::string reg1 = tiggercode[pos][0];
                std::string reg2 = tiggercode[pos][2];
                std::string reg3 = tiggercode[pos][4];
                std::string op = tiggercode[pos][3];
                if(reg3[0] >='0' && reg3[0]<='9'){
                    funccode = funccode + "  li\t\tt0, " + reg3 + "\n";
                    reg3 = "t0";
                }
                if(op == "+")
                    funccode = funccode + "  add\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                else if(op == "-")
                    funccode = funccode + "  sub\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                else if(op == "*")
                    funccode = funccode + "  mul\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                else if(op == "/")
                    funccode = funccode + "  div\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                else if(op == "%")
                    funccode = funccode + "  rem\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                else if(op == "<")
                    funccode = funccode + "  slt\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                else if(op == ">")
                    funccode = funccode + "  sgt\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                else if(op == "<="){
                    funccode = funccode + "  sgt\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                    funccode = funccode + "  seqz\t\t" + reg1 + ", " + reg1 + "\n";
                }
                else if(op == ">="){
                    funccode = funccode + "  slt\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                    funccode = funccode + "  seqz\t\t" + reg1 + ", " + reg1 + "\n";
                }
                else if(op == "&&"){
                    funccode = funccode + "  snez\t\t" + reg1 + ", " + reg2 + "\n";
                    funccode = funccode + "  snez\t\tt0, " + reg3 + "\n";
                    funccode = funccode + "  and\t\t" + reg1 + ", " + reg1 + ", t0\n";
                }
                else if(op == "||"){
                    funccode = funccode + "  or\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                    funccode = funccode + "  snez\t\t" + reg1 + ", " + reg1 + "\n";
                }
                else if(op == "!="){
                    funccode = funccode + "  xor\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                    funccode = funccode + "  snez\t\t" + reg1 + ", " + reg1 + "\n";
                }
                else{
                    funccode = funccode + "  xor\t\t" + reg1 + ", " + reg2 + ", " + reg3 + "\n";
                    funccode = funccode + "  seqz\t\t" + reg1 + ", " + reg1 + "\n";
                }
            }
        }
    }
    return 0;
}