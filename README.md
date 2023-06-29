# ZerOS
## A Hobby Operating System

Initial Specifications
-----------------------
- Target Platform: x86-64 PCs
- Executable Type: TBD
- Toolchain: x86_64-elf-gcc
- Assembler: NASM
- Bootloader: Limine

Components (Planned)
-----------
- Kernel: Catalyst
  - Monolithic kernel
  - Uses novel target-action-arguments based extensible interface

Design Concepts
----------------
- Kernel APIs offer fine grained control while being agnostic to specific hardware devices
- Lightweight and configurable processes
- A separate and well designed syscall for each type of device and kernel subsystem that is supported
including virtual ones like the terminal
- A stub library for interacting with the kernel so the syscall interface can change over time without breaking
userspace

Build Instructions
-------------------
- NOTE: As of right now this project can only be built on GNU/Linux and the only OS it has been tested to build on is Fedora 38

1. Build and install the GNU Binutils version 2.40 and GNU GCC Compiler version 12.2.0 both targeting x86_64-elf
2. Add the aforementioned tools to your PATH environment variable
3. Clone this repository
4. Run the `make -jx` command where `x` is the number of threads you wish to use

- `make clean` can be used to delete all build artifacts
- `make test` can be used to test a build in QEMU if it is installed
