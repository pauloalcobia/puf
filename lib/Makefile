PIC_TYPE := 18f2455

PROGRAMS = libpuf.lib
OBJECTS = picon.o boot_iface.o usb.o sequencer.o

CC := sdcc
GPLIB := gplib

DEBUG = --denable-peeps --obanksel=9 --opt-code-size --optimize-cmp --optimize-df --use-non-free
CFLAGS += -mpic16 -p$(PIC_TYPE) $(DEBUG) -I../include

all: $(PROGRAMS)

libpuf.lib: $(OBJECTS)
	$(GPLIB) -c $@ $+

clean:
	-rm -f *.o *.lst *.asm $(PROGRAMS)

.PHONY: all clean
