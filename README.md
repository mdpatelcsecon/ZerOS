# Aster v0.0.1 "Moore"
## A Hobby Operating System

Initial Specifications
-----------------------
- Target Platform: x86-64 PCs
- Executable Type: ELF
- Toolchain: x86_64-elf-gcc
- Bootloader: Limine
- Kernel Name: Catalyst
- Kernel Architecture: Hybrid Kernel (Microkernel wherever possible)

Design Ideas
-------------
- Everything is an agent (lightweight process like entity)
  - Exactly one thread of execution
  - It's own virtual address space
  - No need for thread local storage since each agent only has a single thread
  - Can write corestate to disk and load it at any time via syscalls
- In-kernel interagent bus system for fast IPC 
  - backed by read-only shared memory
- Drivers and kernel subsystems can create virtual agents through which they can communicate with userspace
  - No need for ioctl or DeviceIOControl type syscall
- Userspace Exceptions (USX): an interrupt-like mechanism for agents


Build Instructions
-------------------
1. Build and install the GNU Binutils version 2.40 and GNU GCC Compiler version 12.2.0 both targeting x86_64-elf
2. Add the aforementioned tools to your PATH environment variable
3. Clone this repository
4. Run the `make -jx` command where `x` is the number of threads you wish to use

- `make clean` can sort of be used to delete all build artifacts
- `make test` can be used to test a build in QEMU if it is installed

![Aster logo](admin/@ster.png)
