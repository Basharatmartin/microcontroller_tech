DEVICE  = msp430g2553
CC      = msp430-gcc

CFLAGS = -mmcu=$(DEVICE) -O2 -g

SOURCE = exercise3_exp.c
#	$(CC) $(SOURCE)

all:
	$(CC) $(SOURCE) $(CFLAGS) $? -o $(DEVICE).elf


clean:
	rm -r *.o

