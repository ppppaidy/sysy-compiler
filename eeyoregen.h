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

};