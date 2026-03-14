CC = gcc
LD = ld
CFLAGS = -g -pedantic -Wall -Wextra -fPIC -std=gnu2x
ASFLAGS = -g

# Targets
all: kernel.elf

kernel.elf: kernel.o process.o queue.o process_asm.o boot.o box.o libos.a
	$(LD) -g -N -Ttext=0x10000 -o kernel.elf kernel.o process.o queue.o process_asm.o boot.o box.o libos.a

kernel.o: kernel.c
	$(CC) $(CFLAGS) -MMD -c kernel.c -o kernel.o

process.o: process.c process.h
	$(CC) $(CFLAGS) -MMD -c process.c -o process.o

queue.o: queue.c process.h
	$(CC) $(CFLAGS) -MMD -c queue.c -o queue.o

process_asm.o: process_asm.S
	$(CC) $(ASFLAGS) -MMD -c process_asm.S -o process_asm.o

boot.o: boot.S
	$(CC) $(ASFLAGS) -MMD -c boot.S -o boot.o

box.o: box.S
	$(CC) $(ASFLAGS) -MMD -c box.S -o box.o

run: kernel.elf
	qemu-system-aarch64 -machine raspi3b -kernel kernel.elf

debug: kernel.elf
	qemu-system-aarch64 -machine raspi3b -S -s -kernel kernel.elf &
	ddd --debugger 'gdb-multiarch -ex "target remote localhost:1234" -ex "break main" -ex "continue"' kernel.elf

clean:
	rm -f *.o *.d kernel.elf