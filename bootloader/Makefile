PIC_TYPE := 18f2455

CC := sdcc
LNK := $(CC)

PROGRAMS = bootloader.hex
OBJECTS = application_iface.o boot_main.o boot_iface.o usb.o \
	usb_descriptors.o ep0.o ep1.o ep2.o flash.o config.o interrupt_iface.o


DEBUG = --denable-peeps --obanksel=9 --opt-code-size --optimize-cmp --optimize-df --use-non-free
CFLAGS += -mpic16 -p$(PIC_TYPE) $(DEBUG) -I../include

COMPILE = $(CC) -mpic16 $(DEBUG) -p$(PIC_TYPE) -Iinclude -c
LINK = $(LNK) -o $@ $(DEBUG) $(LDFLAGS) --use-crt=crt0.o -Wl-s$(PIC_TYPE).lkr,-m \
	-mpic16 -p$(PIC_TYPE) -llibio$(PIC_TYPE).lib -llibc18f.lib


all: $(PROGRAMS)

bootloader.hex: $(OBJECTS)
	@rm -f bootloader.hex
	$(LINK) $(OBJECTS)

clean:
	-rm -f *.o *.lst *.asm *.cod *.map $(PROGRAMS)

.PHONY: all clean
