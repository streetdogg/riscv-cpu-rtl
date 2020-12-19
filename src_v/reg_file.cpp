/**
 * MIT License
 * 
 * Copyright (c) 2020 Piyush Itankar <pitankar@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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