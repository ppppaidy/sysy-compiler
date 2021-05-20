// riscvgen.h
// gen riscv code

#ifndef _RISCVGEN_H_
#define _RISCVGEN_H_

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

class RiscvGenner{
    public:
        char* i_file;
        char* o_file;
        RiscvGenner(char* i_file_, char* o_file_):i_file(i_file_),o_file(o_file_){}
        int printFinal();
        int getTiggerCode();
        int genRiscvCode();

        std::string riscvcode;
        std::string funccode;
        std::string funccodetail;

        int inside_func;

        int STK;

        //tigger code
        //line is dimension 1
        //word is dimension 2
        std::vector<std::vector<std::string> > tiggercode;
};

#endif