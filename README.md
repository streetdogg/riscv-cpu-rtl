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

# Resources and References
1. [RISC-V Specification](https://riscv.org/technical/specifications/)
2. Youtube Channel: [RISC-V International](https://www.youtube.com/channel/UC5gLmcFuvdGbajs4VL-WU3g) 
3. Youtube Channel: [Robert Baruch](https://www.youtube.com/channel/UCBcljXmuXPok9kT_VGA3adg)
4. [E85: Digital Electronics & Computer Architecture (David Harris, Joshua Brake)](http://pages.hmc.edu/harris/class/e85/)
5. [CSCI 463 Computer Architecture and Systems Organization Fall 2020 (John Winans)](http://faculty.cs.niu.edu/~winans/CS463/Fall2020/)
    - Youtube Playlist: [Fall 2020 NIU CSCI 463](https://www.youtube.com/playlist?list=PL3by7evD3F500w-kleB4MITsxeq5J5PaT)