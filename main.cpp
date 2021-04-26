// main.c
// handle commond line imput

#include "globals.h"
#include "scan.h"
#include "nodedef.h"
#include "parse.h"
#include "eeyoregen.h"

char err_usage[] = "usage : %s -S [-e|-t] <filename>.[c|eeyore|tigger] -o <filename>.S\n";

char filename[256], filename_o[256];
char input_filename[256];
char output_filename[256];

int sysy2eeyore = 0;
int eeyore2tigger = 0;
int tigger2riscv = 0;

FILE* source;
FILE* listing;

NodeBase* ast_root;

int main(int argc, char* argv[]){
    if(argc < 5){
        fprintf(stderr, err_usage, argv[0]);
        return 1;
    }
    if(strcmp(argv[1], "-S") != 0){
        fprintf(stderr, err_usage, argv[0]);
        return 1;
    }

    if(strcmp(argv[2], "-e") != 0 && strcmp(argv[2], "-t") != 0){
        strcpy(filename, argv[2]);
    }
    else{
        strcpy(filename, argv[3]);
    }

    if(strcmp(strchr(filename, '.')+1, "c") == 0){
        sysy2eeyore = eeyore2tigger = tigger2riscv = 1;
    }
    else if(strcmp(strchr(filename, '.')+1, "eeyore") == 0){
        eeyore2tigger = tigger2riscv = 1;
    }
    else if(strcmp(strchr(filename, '.')+1, "tigger") == 0){
        tigger2riscv = 1;
    }
    else{
        fprintf(stderr, err_usage, argv[0]);
        return 1;
    }
    *strchr(filename, '.') = '\0';

    if(strcmp(argv[2], "-e") == 0){
        eeyore2tigger = tigger2riscv = 0;
    }
    if(strcmp(argv[2], "-t") == 0){
        tigger2riscv = 0;
    }

    if(strcmp(argv[3], "-o") == 0){
        strcpy(filename_o, argv[4]);
    }
    else{
        strcpy(filename_o, argv[5]);
    }

    //sysy to eeyore
    if(sysy2eeyore == 1){
        strcpy(input_filename, filename);
        strcat(input_filename, ".c");
        source = fopen(input_filename, "r");
        ast_root = parse();
        fclose(source);
        strcpy(output_filename, filename);
        strcat(output_filename, ".eeyore");
        listing = fopen(output_filename, "w");
        EeyoreGenner(listing).printFinal(ast_root);
        fclose(listing);
    }

    //eeyore to tigger
    if(eeyore2tigger == 1){

    }

    //tigger to riscv
    if(tigger2riscv == 1){

    }
    
    return 0;
}