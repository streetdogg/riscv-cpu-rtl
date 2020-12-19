#include <fstream>
#include <iostream>

#include "test_infra.h"
#include "Vinstmem.h"
#include "verilated.h"

using namespace std;

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vinstmem *instmem = new Vinstmem;
    
    int status = 0, address = 0, instruction;
    string line;
    ifstream progFile("program.txt");

    while (!progFile.eof()) {
        instmem->addr = address;
        instmem->eval();

        // Read a line from the program file
        getline(progFile, line);
        if (line.length() == 0)
            break;

        // Convert to hex if the line was no empty
        instruction = stoi(line, 0, 16);

        // Check if the memory has the same content as the file
        ASSERT((instmem->instr == instruction),
               status,
               terminate,
               "[%03d]: 0x%04x != 0x%04x \n", address, instmem->instr, instruction);

        address++;
    }

terminate:
    progFile.close();
    instmem->final();
    delete instmem;

    return status;
}