# RISC-V RV32I Implementation

Implements the base integer instruction set for the RISC-V 32 bit CPU.

## Linting
Run the following to run `verilator` and check that the language rules are followed correctly.
```
make lint instmem
make lint reg_file
```
This can also be executed as a single command
```
make lint instmem reg_file
```
## Verify modules
Run the following to have `verilator` create the module `cpp` files, build and run the executable generated.
```
make verify instmem
make verify reg_file
```
This can also be executed as a single command like the `lint` command above
```
make verify instmem reg_file
```
----

# Implementation Details

## Instruction memory [instmem.sv]
For the ease of implementation this CPU will have a separate code and data memory, i.e to say it is based on the `Harvard Architecture`. The size of `instruction memory` is `128 Bytes`.

The instruction memory takes in a `7 Bit` wide address and outputs `32 Bit` instruction which is then consumed by rest of the system.

**Note:** The instruction memory module has a configurable parameter - `code_file` which is a text file that can be provided during instantiation. This file would contain the instructions in Hex format and be used to init the instruction memory content during synthesis.

## Register File [reg_file.sv]
RISC-V specification dictates that the base implmentation would need to have `32` general purpose registers, each `32 Bits` wide. These are denoted by `x0` to `x1`. `x0` is hardwired to `0`. The module takes input as the source 1 (`rs1`), source 2 (`rs2`) and destination register (`rd`) addresses which are `5 Bits` wide each. The destination register is written to only if the write enable line is asserted. Further, not all instructions use the source 2 register, hence there is an extra input line that tracks if source 2 register is to be considered for the reads.

**Note:** It is assumed that `x0` won't be written to. This needs to be corrected in future improvements in the module.

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