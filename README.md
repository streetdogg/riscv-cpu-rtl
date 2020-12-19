# RISC-V RV32I Implementation

Implements the base integer instruction set for the RISC-V 32 bit CPU.

## Linting
Run the following to run `verilator` and check that the language rules are followed correctly.
```
make
```

## Verify modules
Run the following to have `verilator` create the module `cpp` files, build and run the executable generated.
```
make verify
```
----

# Implementation Details

## Instruction memory [instmem.sv]
For the ease of implementation this CPU will have a separate code and data memory, i.e to say it is based on the `Harvard Architecture`. The size of `instruction memory` is `128 Bytes`.

The instruction memory takes in a `7 Bit` wide address and outputs `32 Bit` instruction which is then consumed by rest of the system.

**Note:** The instruction memory module has a configurable parameter - `code_file` which is a text file that can be provided during instantiation. This file would contain the instructions in Hex format and be used to init the instruction memory content during synthesis.

----
# Resources and References
1. [RISC-V Specification](https://riscv.org/technical/specifications/)
2. Youtube Channel: [RISC-V International](https://www.youtube.com/channel/UC5gLmcFuvdGbajs4VL-WU3g) 
3. Youtube Channel: [Robert Baruch](https://www.youtube.com/channel/UCBcljXmuXPok9kT_VGA3adg)
4. [E85: Digital Electronics & Computer Architecture (David Harris, Joshua Brake)](http://pages.hmc.edu/harris/class/e85/)
5. [CSCI 463 Computer Architecture and Systems Organization Fall 2020 (John Winans)](http://faculty.cs.niu.edu/~winans/CS463/Fall2020/)
    - Youtube Playlist: [Fall 2020 NIU CSCI 463](https://www.youtube.com/playlist?list=PL3by7evD3F500w-kleB4MITsxeq5J5PaT)
6. [Verilator Documentation](https://www.veripool.org/projects/verilator/wiki/Documentation)
    - [Verilator Manual](https://www.veripool.org/ftp/verilator_doc.pdf)