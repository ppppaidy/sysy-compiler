# sysy-compiler
A sysy compiler to riscv

------

This is a compiler from SysY to RiscV, a lab of Principal of Compiler in Peking University.

Please use `make` and `make clean` to generate the compiler and clear cache files.

When you want to compile a `.c/.eeyore/.tigger` file, please use `./compiler -S [-e/-t] <file>.c/.eeyore/.tigger -o <file>` to compiler it.

Using `-e` will generate an Eeyore code. Using `-t` will generate a Tigger code. Ignoring this option will generate a RiscV code.

I do not ensure there is no bug except from SysY to RiscV.
