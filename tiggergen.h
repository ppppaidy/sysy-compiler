// tiggergen.h
// gen tigger code

#ifndef _TIGGERGEN_H_
#define _TIGGERGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class TiggerGenner{
    public:
        char* i_file;
        char* o_file;
        TiggerGenner(char* i_file_, char* o_file_):i_file(i_file_),o_file(o_file_){}
        int printFinal();
        int getEeyoreCode();
        int genTiggerCode();

        std::string tiggercode;
        std::string funccode;

        //eeyore code
        //line is dimension 1
        //word is dimension 2
        std::vector<std::vector<std::string> > eeyorecode;

        //whether a var is global or local
        std::unordered_map<std::string, int> inside_func;

        //global var : name
        //local var : addr in stack
        std::unordered_map<std::string, int> var_addr;

        //size of stack of the func now
        int stack_size;

        //name of the func now
        std::string func_name;

        //number of param of the func now
        std::string param_num;

        //compute register id when before call
        int param_id;

        //number of global vars
        int global_var_num;
};

#endif