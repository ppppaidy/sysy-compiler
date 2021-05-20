// tiggergen.cpp
// gen tigger code

#include "tiggergen.h"

int TiggerGenner::printFinal(){
    getEeyoreCode();
    genTiggerCode();
    std::ofstream output_file(o_file, std::ios::out);
    output_file<<tiggercode;
    return 0;
}

int TiggerGenner::getEeyoreCode(){
    std::ifstream input_file(i_file, std::ios::in);
    std::string stmt;
    while(std::getline(input_file, stmt, '\n')){
        std::stringstream input_stmt(stmt);
        std::string word;
        eeyorecode.push_back(std::vector<std::string>(0));
        while(input_stmt>>word){
            eeyorecode[eeyorecode.size()-1].push_back(word);
        }
    }
    return 0;
}

int TiggerGenner::genTiggerCode(){
    tiggercode = "";
    int pos = 0;
    global_var_num = 0;
    for(; pos < eeyorecode.size(); pos++){
        if(eeyorecode[pos].size() == 0) continue;
        if(eeyorecode[pos][0][0] == 'f'){
            tiggercode = tiggercode + "\n";
            break;
        }
        if(eeyorecode[pos][1][0] == 't' || eeyorecode[pos][1][0] == 'T'){
            global_var_num++;
            var_addr[eeyorecode[pos][1]] = global_var_num;
            inside_func[eeyorecode[pos][1]] = 0;
            tiggercode = tiggercode + "v" + std::to_string(global_var_num) + " = 0\n";
        }
        else{
            global_var_num++;
            var_addr[eeyorecode[pos][2]] = global_var_num;
            inside_func[eeyorecode[pos][2]] = 0;
            tiggercode = tiggercode + "v" + std::to_string(global_var_num)
                + " = malloc " + eeyorecode[pos][1] + "\n";
        }
    }
    for(; pos < eeyorecode.size(); pos++){
        if(eeyorecode[pos].size() == 0) continue;
        if(eeyorecode[pos][0][0] == 'f'){
            param_id = 0;
            funccode = "";
            stack_size = 0;
            func_name = eeyorecode[pos][0];
            param_num = eeyorecode[pos][1];
            int pnum = atoi(param_num.substr(1, param_num.length()-2).c_str());
            stack_size += pnum;
            for(int i = 0; i < pnum; i++){
                std::string var_name = "p" + std::to_string(i);
                var_addr[var_name] = i+1;
                inside_func[var_name] = 1;
                funccode = funccode + "store a" + std::to_string(i) + " "
                    + std::to_string(i+1) + "\n";
            }
        }
        else if(eeyorecode[pos][0] == "end"){
            funccode = func_name + " " + param_num + " [" 
                + std::to_string(stack_size) + "]\n" + funccode;
            funccode = funccode + "end " + func_name + "\n\n";
            tiggercode = tiggercode + funccode;
        }
        else if(eeyorecode[pos][0][0] == 'l'){
            funccode = funccode + eeyorecode[pos][0] + "\n";
        }
        else if(eeyorecode[pos][0] == "goto"){
            funccode = funccode + eeyorecode[pos][0] + " " + eeyorecode[pos][1] + "\n";
        }
        else if(eeyorecode[pos][0] == "var"){
            if(eeyorecode[pos][1][0] == 't' || eeyorecode[pos][1][0] == 'T'){
                stack_size += 4;
                var_addr[eeyorecode[pos][1]] = stack_size / 4;
                inside_func[eeyorecode[pos][1]] = 1;
            }
            else{
                var_addr[eeyorecode[pos][2]] = stack_size / 4 + 1;
                inside_func[eeyorecode[pos][2]] = 1;
                stack_size += atoi(eeyorecode[pos][1].c_str());
            }
        }
        else if(eeyorecode[pos][0] == "param"){
            if(inside_func[eeyorecode[pos][1]])
                funccode = funccode + "load " + std::to_string(var_addr[eeyorecode[pos][1]])
                    + " a" + std::to_string(param_id) + "\n";
            else
                funccode = funccode + "load v" + std::to_string(var_addr[eeyorecode[pos][1]])
                    + " a" + std::to_string(param_id) + "\n";
            param_id++;
        }
        else if(eeyorecode[pos][0] == "call"){
            param_id = 0;
            funccode = funccode + "call " + eeyorecode[pos][1] + "\n";
        }
        else if(eeyorecode[pos][0] == "if"){
            if(eeyorecode[pos][1][0] == 'p' || eeyorecode[pos][1][0] == 't'
            || eeyorecode[pos][1][0] == 'T'){
                if(inside_func[eeyorecode[pos][1]])
                    funccode = funccode + "load " 
                            + std::to_string(var_addr[eeyorecode[pos][1]]) + " s0" + "\n";
                else
                    funccode = funccode + "load v" 
                            + std::to_string(var_addr[eeyorecode[pos][1]]) + " s0" + "\n";
            }
            else{
                funccode = funccode + "s0 = " + eeyorecode[pos][1] + "\n";
            }
            if(eeyorecode[pos][3][0] == 'p' || eeyorecode[pos][3][0] == 't'
            || eeyorecode[pos][3][0] == 'T'){
                if(inside_func[eeyorecode[pos][3]])
                    funccode = funccode + "load " 
                            + std::to_string(var_addr[eeyorecode[pos][3]]) + " s1" + "\n";
                else
                    funccode = funccode + "load v" 
                            + std::to_string(var_addr[eeyorecode[pos][3]]) + " s1" + "\n";
            }
            else{
                funccode = funccode + "s1 = " + eeyorecode[pos][3] + "\n";
            }
            funccode = funccode + "if s0 " + eeyorecode[pos][2] + " s1 goto "
                 + eeyorecode[pos][5] + "\n";
        }
        else if(eeyorecode[pos][0] == "return"){
            if(eeyorecode[pos].size() == 1)
                funccode = funccode + "return\n";
            else{
                if(eeyorecode[pos][1][0]=='p' || eeyorecode[pos][1][0]=='t' 
                || eeyorecode[pos][1][0] == 'T'){
                    if(inside_func[eeyorecode[pos][1]])
                        funccode = funccode + "load " 
                            + std::to_string(var_addr[eeyorecode[pos][1]]) + " a0" + "\n";
                    else
                        funccode = funccode + "load v" 
                            + std::to_string(var_addr[eeyorecode[pos][1]]) + " a0" + "\n";
                    funccode = funccode + "return\n";
                }
                else{
                    funccode = funccode + "a0 = " + eeyorecode[pos][1] + "\n";
                    funccode = funccode + "return\n";
                }
            }
        }
        else{
            if(eeyorecode[pos][2] == "call"){
                param_id = 0;
                funccode = funccode + "call " + eeyorecode[pos][3] + "\n";
                if(inside_func[eeyorecode[pos][0]])
                    funccode = funccode + "loadaddr " 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s0" + "\n";
                else
                    funccode = funccode + "loadaddr v" 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s0" + "\n";
                funccode = funccode + "s0[0] = a0\n";
            }
            else if(eeyorecode[pos][0][eeyorecode[pos][0].length()-1] == ']'){
                std::string store_var_name = eeyorecode[pos][0].substr(0, 
                    eeyorecode[pos][0].find('['));
                std::string store_var_index = eeyorecode[pos][0].substr(
                    eeyorecode[pos][0].find('[') + 1);
                store_var_index = store_var_index.substr(0, store_var_index.length()-1);
                if(eeyorecode[pos][2][0]=='p' || eeyorecode[pos][2][0]=='t' 
                || eeyorecode[pos][2][0] == 'T'){
                    if(inside_func[eeyorecode[pos][2]])
                        funccode = funccode + "load " 
                            + std::to_string(var_addr[eeyorecode[pos][2]]) + " s0" + "\n";
                    else
                        funccode = funccode + "load v" 
                            + std::to_string(var_addr[eeyorecode[pos][2]]) + " s0" + "\n";
                }
                else{
                    funccode = funccode + "s0 = " + eeyorecode[pos][2] + "\n";
                }
                if(store_var_name[0] == 'p' || store_var_name[0] == 't' 
                || store_var_name[0] == 'T'){
                    if(inside_func[store_var_name])
                        funccode = funccode + "loadaddr " 
                            + std::to_string(var_addr[store_var_name]) + " s1" + "\n";
                    else
                        funccode = funccode + "loadaddr v" 
                            + std::to_string(var_addr[store_var_name]) + " s1" + "\n";
                }
                else{
                    funccode = funccode + "s1 = " + store_var_name + "\n";
                }
                if(store_var_index[0] == 'p' || store_var_index[0] == 't' 
                || store_var_index[0] == 'T'){
                    if(inside_func[store_var_index])
                        funccode = funccode + "load " 
                            + std::to_string(var_addr[store_var_index]) + " s2" + "\n";
                    else
                        funccode = funccode + "load v" 
                            + std::to_string(var_addr[store_var_index]) + " s2" + "\n";
                }
                else{
                    funccode = funccode + "s2 = " + store_var_index + "\n";
                }
                funccode = funccode + "s1 = s1 + s2\n";
                funccode = funccode + "s1[0] = s0\n";
            }
            else if(eeyorecode[pos][2][eeyorecode[pos][2].length()-1] == ']'){
                std::string store_var_name = eeyorecode[pos][2].substr(0, 
                    eeyorecode[pos][2].find('['));
                std::string store_var_index = eeyorecode[pos][2].substr(
                    eeyorecode[pos][2].find('[') + 1);
                store_var_index = store_var_index.substr(0, store_var_index.length()-1);
                if(store_var_name[0] == 'p' || store_var_name[0] == 't' 
                || store_var_name[0] == 'T'){
                    if(inside_func[store_var_name])
                        funccode = funccode + "loadaddr " 
                            + std::to_string(var_addr[store_var_name]) + " s1" + "\n";
                    else
                        funccode = funccode + "loadaddr v" 
                            + std::to_string(var_addr[store_var_name]) + " s1" + "\n";
                }
                else{
                    funccode = funccode + "s1 = " + store_var_name + "\n";
                }
                if(store_var_index[0] == 'p' || store_var_index[0] == 't' 
                || store_var_index[0] == 'T'){
                    if(inside_func[store_var_index])
                        funccode = funccode + "load " 
                            + std::to_string(var_addr[store_var_index]) + " s2" + "\n";
                    else
                        funccode = funccode + "load v" 
                            + std::to_string(var_addr[store_var_index]) + " s2" + "\n";
                }
                else{
                    funccode = funccode + "s2 = " + store_var_index + "\n";
                }
                funccode = funccode + "s1 = s1 + s2\n";
                funccode = funccode + "s0 = s1[0]\n";
                if(inside_func[eeyorecode[pos][0]])
                    funccode = funccode + "loadaddr " 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s3" + "\n";
                else
                    funccode = funccode + "loadaddr v" 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s3" + "\n";
                funccode = funccode + "s3[0] = s0\n";
            }
            else if(eeyorecode[pos].size() == 3){
                if(inside_func[eeyorecode[pos][0]])
                    funccode = funccode + "loadaddr " 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s0" + "\n";
                else
                    funccode = funccode + "loadaddr v" 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s0" + "\n";
                if(eeyorecode[pos][2][0] == 'p' || eeyorecode[pos][2][0] == 't' 
                || eeyorecode[pos][2][0] == 'T'){
                    if(inside_func[eeyorecode[pos][2]])
                        funccode = funccode + "load " 
                            + std::to_string(var_addr[eeyorecode[pos][2]]) + " s1" + "\n";
                    else
                        funccode = funccode + "load v" 
                            + std::to_string(var_addr[eeyorecode[pos][2]]) + " s1" + "\n";
                }
                else{
                    funccode = funccode + "s1 = " + eeyorecode[pos][2] + "\n";
                }
                funccode = funccode + "s0[0] = s1\n";
            }
            else if(eeyorecode[pos].size() == 4){
                if(inside_func[eeyorecode[pos][0]])
                    funccode = funccode + "loadaddr " 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s0" + "\n";
                else
                    funccode = funccode + "loadaddr v" 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s0" + "\n";
                if(eeyorecode[pos][3][0] == 'p' || eeyorecode[pos][3][0] == 't' 
                || eeyorecode[pos][3][0] == 'T'){
                    if(inside_func[eeyorecode[pos][3]])
                        funccode = funccode + "load " 
                            + std::to_string(var_addr[eeyorecode[pos][3]]) + " s1" + "\n";
                    else
                        funccode = funccode + "load v" 
                            + std::to_string(var_addr[eeyorecode[pos][3]]) + " s1" + "\n";
                }
                else{
                    funccode = funccode + "s1 = " + eeyorecode[pos][3] + "\n";
                }
                funccode = funccode + "s0[0] = " + eeyorecode[pos][2] +" s1\n";
            }
            else{
                if(inside_func[eeyorecode[pos][0]])
                    funccode = funccode + "loadaddr " 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s0" + "\n";
                else
                    funccode = funccode + "loadaddr v" 
                        + std::to_string(var_addr[eeyorecode[pos][0]]) + " s0" + "\n";
                if(eeyorecode[pos][2][0] == 'p' || eeyorecode[pos][2][0] == 't' 
                || eeyorecode[pos][2][0] == 'T'){
                    if(inside_func[eeyorecode[pos][2]])
                        funccode = funccode + "load " 
                            + std::to_string(var_addr[eeyorecode[pos][2]]) + " s1" + "\n";
                    else
                        funccode = funccode + "load v" 
                            + std::to_string(var_addr[eeyorecode[pos][2]]) + " s1" + "\n";
                }
                else{
                    funccode = funccode + "s1 = " + eeyorecode[pos][2] + "\n";
                }
                if(eeyorecode[pos][4][0] == 'p' || eeyorecode[pos][4][0] == 't' 
                || eeyorecode[pos][4][0] == 'T'){
                    if(inside_func[eeyorecode[pos][4]])
                        funccode = funccode + "load " 
                            + std::to_string(var_addr[eeyorecode[pos][4]]) + " s2" + "\n";
                    else
                        funccode = funccode + "load v" 
                            + std::to_string(var_addr[eeyorecode[pos][4]]) + " s2" + "\n";
                }
                else{
                    funccode = funccode + "s2 = " + eeyorecode[pos][4] + "\n";
                }
                funccode = funccode + "s0[0] = s1 " + eeyorecode[pos][3] + " s2\n";
            }
        }
    }
    return 0;
}