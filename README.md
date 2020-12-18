# RISC-V RV32I Implementation

Implements the base integer instruction for the RISC-V 32 bit CPU.

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