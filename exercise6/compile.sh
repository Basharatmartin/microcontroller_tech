#!/bin/bash


if [ -f Makefile ]; then
	/usr/bin/make
fi


mspdebug rf2500 "prog msp430g2553.elf";




