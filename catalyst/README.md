# Catalyst
## The kernel of ZerOS

### Design
* Architecture: Monolithic
* Components
    * high-level kernel
        * Hardware agnostic
    * low-level kernel
       * Hardware platform specific code
       * Device Drivers

### Supported Hardware
- ISA: AMD64/Intel64 i.e. x64
- Firmware: UEFI and ACPI required