DEVICE  = msp430g2553
CC      = msp430-gcc

CFLAGS = -mmcu=$(DEVICE) -O2 -g

#SOURCE = main1.c
SOURCE = exercise5.c
#SOURCE = hussain4.c
#	$(CC) $(SOURCE)

all:
	$(CC) $(SOURCE) $(CFLAGS) $? -o $(DEVICE).elf


clean:
	rm -r *.o

