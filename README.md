# Aster v0.0.0 "Moore"
## A Hobby Operating System

Initial Specifications
-----------------------
- Target Platform: x86-64 PCs
- Executable Type: ELF
- Toolchain: x86_64-elf-gcc
- Assembler: NASM
- Bootloader: Limine
- Kernel Name: Catalyst
- Kernel Architecture: Hybrid Monolithic-Exokernel

Design Concepts
----------------
- Kernel with low level but specific device agnostic APIs
- Lightweight and configurable processes
- Processes can manipulate their virtual address space via syscalls
- Simple filesystem (open, close, read, write) with no special files
- Userspace Exceptions (USX): an interrupt-like mechanism for processes


Build Instructions
-------------------
1. Build and install the GNU Binutils version 2.40 and GNU GCC Compiler version 12.2.0 both targeting x86_64-elf
2. Add the aforementioned tools to your PATH environment variable
3. Clone this repository
4. Run the `make -jx` command where `x` is the number of threads you wish to use

- `make clean` can sort of be used to delete all build artifacts
- `make test` can be used to test a build in QEMU if it is installed

![Aster logo](admin/@ster.png)
