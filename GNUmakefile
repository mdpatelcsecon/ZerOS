# Nuke built-in rules and variables.
override MAKEFLAGS += -rR

override IMAGE_NAME := ZerOS

.PHONY: all
all: $(IMAGE_NAME).iso

.PHONY: all-hdd
all-hdd: $(IMAGE_NAME).hdd

.PHONY: run
run: $(IMAGE_NAME).iso
	qemu-system-x86_64 -M q35 -m 2G -cdrom $(IMAGE_NAME).iso -boot d

.PHONY: run-uefi
run-uefi: ovmf $(IMAGE_NAME).iso
	make ovmf
	qemu-system-x86_64 -M q35 -m 2G -bios ovmf/OVMF.fd -cdrom $(IMAGE_NAME).iso -boot d

.PHONY: run-hdd
run-hdd: $(IMAGE_NAME).hdd
	qemu-system-x86_64 -M q35 -m 2G -hda $(IMAGE_NAME).hdd

.PHONY: run-hdd-uefi
run-hdd-uefi: ovmf $(IMAGE_NAME).hdd
	make ovmf
	qemu-system-x86_64 -M q35 -m 2G -bios ovmf/OVMF.fd -hda $(IMAGE_NAME).hdd

ovmf:
	mkdir -p ovmf
	cd ovmf && curl -Lo OVMF.fd https://retrage.github.io/edk2-nightly/bin/RELEASEX64_OVMF.fd

limine:
	git clone https://github.com/limine-bootloader/limine.git --branch=v4.x-branch-binary --depth=1
	$(MAKE) -C limine

.PHONY: catalyst
catalyst:
	$(MAKE) -C catalyst

$(IMAGE_NAME).iso: limine catalyst
	rm -rf iso_root
	mkdir -p iso_root
	cp catalyst/catalyst.elf \
		limine.cfg limine/limine.sys limine/limine-cd.bin limine/limine-cd-efi.bin iso_root/
	xorriso -as mkisofs -b limine-cd.bin \
		-no-emul-boot -boot-load-size 4 -boot-info-table \
		--efi-boot limine-cd-efi.bin \
		-efi-boot-part --efi-boot-image --protective-msdos-label \
		iso_root -o $(IMAGE_NAME).iso
	limine/limine-deploy $(IMAGE_NAME).iso
	rm -rf iso_root

$(IMAGE_NAME).hdd: limine catalyst
	rm -f $(IMAGE_NAME).hdd
	dd if=/dev/zero bs=1M count=0 seek=64 of=$(IMAGE_NAME).hdd
	parted -s $(IMAGE_NAME).hdd mklabel gpt
	parted -s $(IMAGE_NAME).hdd mkpart ESP fat32 2048s 100%
	parted -s $(IMAGE_NAME).hdd set 1 esp on
	limine/limine-deploy $(IMAGE_NAME).hdd
	sudo losetup -Pf --show $(IMAGE_NAME).hdd >loopback_dev
	sudo mkfs.fat -F 32 `cat loopback_dev`p1
	mkdir -p img_mount
	sudo mount `cat loopback_dev`p1 img_mount
	sudo mkdir -p img_mount/EFI/BOOT
	sudo cp -v catalyst/catalyst.elf limine.cfg limine/limine.sys img_mount/
	sudo cp -v limine/BOOTX64.EFI img_mount/EFI/BOOT/
	sync
	sudo umount img_mount
	sudo losetup -d `cat loopback_dev`
	rm -rf loopback_dev img_mount

.PHONY: clean
clean:
	rm -rf iso_root $(IMAGE_NAME).iso $(IMAGE_NAME).hdd logs/catalyst_db.log logs/catalyst_com.log
	$(MAKE) -C catalyst clean

.PHONY: distclean
distclean: clean
	rm -rf limine ovmf
	$(MAKE) -C catalyst distclean

.PHONY: test
test:
	make all
	qemu-system-x86_64 -M q35 -m 8G -smp 8 -bios ovmf/OVMF.fd -cdrom $(IMAGE_NAME).iso -no-reboot -debugcon stdio

.PHONY: test_log
test_log:
	make all
	qemu-system-x86_64 -M q35 -m 8G -smp 8 -bios ovmf/OVMF.fd -cdrom $(IMAGE_NAME).iso -no-reboot -debugcon file:logs/catalyst_db.log -serial file:logs/catalyst_com.log
