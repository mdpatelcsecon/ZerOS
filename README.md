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

Building
---------
- As of right now this project can only be built on GNU/Linux
- The following tools are required to build and test this project:
  - GCC built from source to target x86_64-elf
  - The GNU Binutils built from source to target x86_64-elf
  - The Netwide Assembler (NASM)
  - CURL
  - qemu-system-x86_64
- Once these tools are installed and added to the PATH environment variable you can clone this repository and run `make`
  - `make` will build all targets other than test targets
  - `make test` will build the UEFI target and boot it in QEMU
  - `make clean` can be used to delete all build artifacts
  - `make distclean` can be used to remove all supporting libraries and artifacts and force them to be reacquired and rebuilt
  the next time you run `make`
