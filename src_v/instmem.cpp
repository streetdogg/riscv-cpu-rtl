#include "Vinstmem.h"
#include "verilated.h"

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vinstmem *instmem = new Vinstmem;

    printf("Module verification code goes here!\n");

    delete instmem;
}