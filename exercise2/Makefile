OBJECTS=exercise.o

GCC_DIR =  /home/basharat/Desktop/uni_freiburg_lectures/microcontroller_tech/ti/msp430_gcc/bin
SUPPORT_FILE_DIRECTORY = /home/basharat/Desktop/uni_freiburg_lectures/microcontroller_tech/ti/msp430_gcc/include

DEVICE  = msp430g2553
CC      = $(GCC_DIR)/msp430-elf-gcc
#CC      = msp430-gcc
GDB     = $(GCC_DIR)/msp430-elf-gdb

CFLAGS = -I $(SUPPORT_FILE_DIRECTORY) -mmcu=$(DEVICE) -O2 -g
LFLAGS = -L $(SUPPORT_FILE_DIRECTORY)

all: ${OBJECTS}
	$(CC) $(CFLAGS) $(LFLAGS) $? -o $(DEVICE).out
	#$(CC) -o $(DEVICE).out

debug: all
	$(GDB) $(DEVICE).out
