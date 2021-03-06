# MPLAB IDE generated this makefile for use with GNU make.
# Project: contalitri.mcp
# Date: Sun Mar 25 16:11:45 2012

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

contalitri.hex : contalitri.cof
	$(HX) "contalitri.cof"

contalitri.cof : main.o DEE\ Emulation\ 16-bit.o Flash\ Operations.o display.o peripherals.o
	$(CC) -mcpu=24FJ128GA306 "main.o" "DEE Emulation 16-bit.o" "Flash Operations.o" "display.o" "peripherals.o" -o"contalitri.cof" -Wl,-L"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64\common",-L"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64",-L"C:\Microchip Solutions v2011-10-18\Microchip",--script="..\..\..\..\..\..\Program Files (x86)\Microchip\MPLAB C30\support\PIC24F\gld\p24FJ128GA306.gld",--defsym=__MPLAB_BUILD=1,-Map="contalitri.map",--report-mem

main.o : peripherals.h display.h DEE\ Emulation\ 16-bit/DEE\ Emulation\ 16-bit.h ../../../../../../program\ files\ (x86)/microchip/mplab\ c30/support/PIC24F/h/p24fj128ga306.h main.c
	$(CC) -mcpu=24FJ128GA306 -x c -c "main.c" -o"main.o" -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64\inc" -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64" -I"C:\Microchip Solutions v2011-10-18\Microchip\DEE Emulation 16-bit" -I"C:\Microchip Solutions v2011-10-18\Microchip\Include" -g -Wall

DEE\ Emulation\ 16-bit.o : ../../../../../../Microchip\ Solutions\ v2011-10-18/Microchip/Include/DEE\ Emulation\ 16-bit/DEE\ Emulation\ 16-bit.h ../../../../../../program\ files\ (x86)/microchip/mplab\ c30/support/PIC24F/h/p24FJ128GA306.h ../../../../../../program\ files\ (x86)/microchip/mplab\ c30/support/PIC24F/h/p24Fxxxx.h ../../../../../../Microchip\ Solutions\ v2011-10-18/Microchip/DEE\ Emulation\ 16-bit/DEE\ Emulation\ 16-bit.c
	$(CC) -mcpu=24FJ128GA306 -x c -c "C:\Microchip Solutions v2011-10-18\Microchip\DEE Emulation 16-bit\DEE Emulation 16-bit.c" -o"DEE Emulation 16-bit.o" -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64\inc" -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64" -I"C:\Microchip Solutions v2011-10-18\Microchip\DEE Emulation 16-bit" -I"C:\Microchip Solutions v2011-10-18\Microchip\Include" -g -Wall

Flash\ Operations.o : ../../../../../../Microchip\ Solutions\ v2011-10-18/Microchip/DEE\ Emulation\ 16-bit/Flash\ Operations.s
	$(CC) -mcpu=24FJ128GA306 -c -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64\inc" -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64" -I"C:\Microchip Solutions v2011-10-18\Microchip\DEE Emulation 16-bit" -I"C:\Microchip Solutions v2011-10-18\Microchip\Include" "C:\Microchip Solutions v2011-10-18\Microchip\DEE Emulation 16-bit\Flash Operations.s" -o"Flash Operations.o" -Wa,-g

display.o : peripherals.h font.h Display.h ../../../../../../program\ files\ (x86)/microchip/mplab\ c30/include/stdarg.h ../../../../../../program\ files\ (x86)/microchip/mplab\ c30/include/stdio.h ../../../../../../program\ files\ (x86)/microchip/mplab\ c30/include/stddef.h ../../../../../../program\ files\ (x86)/microchip/mplab\ c30/include/string.h ../../../../../../program\ files\ (x86)/microchip/mplab\ c30/support/PIC24F/h/p24fj128ga306.h display.c
	$(CC) -mcpu=24FJ128GA306 -x c -c "display.c" -o"display.o" -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64\inc" -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64" -I"C:\Microchip Solutions v2011-10-18\Microchip\DEE Emulation 16-bit" -I"C:\Microchip Solutions v2011-10-18\Microchip\Include" -g -Wall

peripherals.o : display.h peripherals.h ../../../../../../program\ files\ (x86)/microchip/mplab\ c30/support/PIC24F/h/p24fj128ga306.h peripherals.c
	$(CC) -mcpu=24FJ128GA306 -x c -c "peripherals.c" -o"peripherals.o" -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64\inc" -I"C:\Users\fabiobaraldi\Desktop\PIC\progettoPIC32\contalitri\Grlib128x64" -I"C:\Microchip Solutions v2011-10-18\Microchip\DEE Emulation 16-bit" -I"C:\Microchip Solutions v2011-10-18\Microchip\Include" -g -Wall

clean : 
	$(RM) "main.o" "DEE Emulation 16-bit.o" "Flash Operations.o" "display.o" "peripherals.o" "contalitri.cof" "contalitri.hex"

