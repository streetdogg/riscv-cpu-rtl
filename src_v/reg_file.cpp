#include <fstream>
#include <iostream>

#include "test_infra.h"
#include "Vreg_file.h"
#include "verilated.h"

using namespace std;

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vreg_file *reg_file = new Vreg_file;
    int status = 0, reg = 1;

    printf("Writing to the Registers\n");
    reg_file->w_en = true;
    for (reg = 1; reg < 32; reg++) {
        reg_file->rda = reg;
        reg_file->rd = reg * 2;

        reg_file->eval();
    }
    reg_file->w_en = false;

    printf("Checking Written values by probing rs1: ");
    for (reg = 1; reg < 32; reg++) {
        reg_file->rs1a = reg;
        reg_file->eval();

        ASSERT((reg_file->rs1 == reg*2), status, terminate, "FAILED! [reg %02d]\n", reg);
    }
    printf("PASSED!\n");

    printf("Checking Written values by probing rs2 with read disabled: ");
    reg_file->rs2val = false;
    for (reg = 1; reg < 32; reg++) {
        reg_file->rs2a = reg;
        reg_file->eval();

        ASSERT((reg_file->rs2 == 0), status, terminate, "FAILED! [reg %02d]\n", reg);
    }
    printf("PASSED!\n");

    printf("Checking Written values by probing rs2 with read enabled: ");
    reg_file->rs2val = true;
    for (reg = 1; reg < 32; reg++) {
        reg_file->rs2a = reg;
        reg_file->eval();

        ASSERT((reg_file->rs2 == reg*2), status, terminate, "FAILED! [reg %02d]\n", reg);
    }
    reg_file->rs2val = false;
    printf("PASSED!\n");

terminate:
    reg_file->final();
    delete reg_file;
    return status;
}