# NewOS v0.0.0 "Moore"
## A Hobby Operating System

Initial Specifications
-----------------------
- Target Platform: x86-64 PCs
- Executable Type: ELF
- Toolchain: x86_64-elf-gcc
- Assembler: NASM
- Bootloader: Limine

Components (Planned)
-----------
- Kernel: Catalyst
  - Hybrid kernel 
  - Exokernel inspired low level syscall interface though still agnostic to exact devices
- System Library: Valence
  - Thin wrapper library used so that kernel syscalls can change without breaking userspace
  - C and all other higher level language implementations must develop their own standard libraries
- Init System: Entanglement
  - Single high performance program initially in assembly with raw syscalls but eventually in C using Valence
- Shell: Eigen
  - Extremely easy to use using full length words such that anyone who can read English can easily use it

Design Concepts
----------------
- Kernel APIs offer fine grained control while being agnostic to specific hardware devices
- Lightweight and configurable processes
- Simple filesystem (open, close, read, write) with no special files and each partition is treated as a separate device
- Userspace Exceptions (USX): an interrupt-like mechanism for processes
- A separate and well designed syscall for each type of device and kernel subsystem that is supported 
including virtual ones like the terminal
- A small system library for making syscalls from C so that the kernel syscall interface can change over time without breaking
userspace


Build Instructions
-------------------
1. Build and install the GNU Binutils version 2.40 and GNU GCC Compiler version 12.2.0 both targeting x86_64-elf
2. Add the aforementioned tools to your PATH environment variable
3. Clone this repository
4. Run the `make -jx` command where `x` is the number of threads you wish to use

- `make clean` can sort of be used to delete all build artifacts
- `make test` can be used to test a build in QEMU if it is installed