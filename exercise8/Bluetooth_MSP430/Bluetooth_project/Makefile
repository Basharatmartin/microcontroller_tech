DEVICE  = msp430g2553
CC      = msp430-gcc

CFLAGS = -mmcu=$(DEVICE) -O2 -g

SOURCE = main.c
#SOURCE = exercise8.c
#SOURCE = sample.c
#SOURCE = uart.c
#	$(CC) $(SOURCE)

all:
	$(CC) $(SOURCE) $(CFLAGS) $? -o $(DEVICE).elf


clean:
	rm -r *.o

