#include <fstream>
#include <iostream>

#include "test_infra.h"
#include "Vreg_file.h"
#include "verilated.h"

using namespace std;

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vreg_file *reg_file = new Vreg_file;
    int status = 0;
   
    printf("TODO: Implement reg_file module tests\n");

    delete reg_file;
    return status;
}