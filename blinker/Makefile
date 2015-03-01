PIC_TYPE := 18f2455

CC := sdcc
LNK := $(CC)
LIBPUF := ../lib/libpuf.lib

PROGRAMS = blinker.hex
OBJECTS = application_iface.o main.o usb_descriptors.o


DEBUG = --denable-peeps --obanksel=9 --opt-code-size --optimize-cmp --optimize-df --use-non-free
CFLAGS += -mpic16 -p$(PIC_TYPE) $(DEBUG) -I../include

LIBIO = $(TOOLSDIR)/share/sdcc/lib/pic16/libio18f2455.lib
LIBC18F = $(TOOLSDIR)/share/sdcc/lib/pic16/libc18f.lib

COMPILE = $(CC) -mpic16 $(DEBUG) -p$(PIC_TYPE) -Iinclude -c
LINK = $(LNK) -o $@ $(DEBUG) $(LDFLAGS) --no-crt -Wl-s$(PIC_TYPE).lkr,-m \
	-mpic16 -p$(PIC_TYPE) -l$(LIBPUF) -llibio$(PIC_TYPE).lib -llibc18f.lib



all: $(PROGRAMS)

blinker.hex: $(OBJECTS)
	@rm -f blinker.hex
	$(LINK) $(OBJECTS)

clean:
	-rm -f *.o *.lst *.asm *.cod *.map $(PROGRAMS)

.PHONY: all clean
