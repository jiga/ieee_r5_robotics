SHELL = cmd.exe

#
# ZDS II Make File - line sensor, Release
#

CC = @C:\PROGRA~1\ZiLOG\ZDSII_~1.6\bin\eZ8cc
ASM = @C:\PROGRA~1\ZiLOG\ZDSII_~1.6\bin\eZ8asm
LINK = @C:\PROGRA~1\ZiLOG\ZDSII_~1.6\bin\eZ8link
LIB = @C:\PROGRA~1\ZiLOG\ZDSII_~1.6\bin\eZ8lib

CFLAGS =  \
 -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -NOdebug  \
 -define:_Z8F6423 -define:_Z8ENCORE_64K_SERIES  \
 -define:_MODEL_LARGE -define:_Z8ENCORE_F642X -doublesize:32  \
 -NOexpmac -floatsize:32 -NOfplib -genprintf -globalcopy  \
 -globalcse -globalfold -intrinsic -intsize:16 -intsrc -jmpopt  \
 -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy -localcse  \
 -localfold -longsize:32 -loopopt -maxerrs:50 -model:L -NOoptlink  \
 -optsize -peephole -NOpromote -quiet -regvar -NOrevaa -sdiopt  \
 -shortsize:16  \
 -stdinc:"C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\Z8Encore_F642X"  \
 -strict -NOwatch -cpu:Z8F6423  \
 -asmsw:" -cpu:Z8F6423 -define:_Z8F6423=1 -define:_Z8ENCORE_64K_SERIES=1 -define:_MODEL_LARGE=1 -define:_Z8ENCORE_F642X=1 -include:C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\Z8Encore_F642X -NOrevaa"

AFLAGS =  \
 -NOdebug -define:_Z8F6423=1 -define:_Z8ENCORE_64K_SERIES=1  \
 -define:_MODEL_LARGE=1 -define:_Z8ENCORE_F642X=1 -genobj  \
 -NOigcase  \
 -include:"C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std;C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog;C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\Z8Encore_F642X"  \
 -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt  \
 -warn -NOzmasm -NOrevaa -cpu:Z8F6423

OUTDIR = E:\ROBOTI~1\APRIL7~1\LINESE~1\

Release: line_sensor

deltarget: 
	@if exist E:\ROBOTI~1\APRIL7~1\LINESE~1\line sensor.lod  \
            del E:\ROBOTI~1\APRIL7~1\LINESE~1\line sensor.lod
	@if exist E:\ROBOTI~1\APRIL7~1\LINESE~1\line sensor.hex  \
            del E:\ROBOTI~1\APRIL7~1\LINESE~1\line sensor.hex

clean: 
	@if exist E:\ROBOTI~1\APRIL7~1\LINESE~1\line sensor.lod  \
            del E:\ROBOTI~1\APRIL7~1\LINESE~1\line sensor.lod
	@if exist E:\ROBOTI~1\APRIL7~1\LINESE~1\line sensor.hex  \
            del E:\ROBOTI~1\APRIL7~1\LINESE~1\line sensor.hex
	@if exist E:\ROBOTI~1\APRIL7~1\LINESE~1\zsldevinit.obj  \
            del E:\ROBOTI~1\APRIL7~1\LINESE~1\zsldevinit.obj
	@if exist E:\ROBOTI~1\APRIL7~1\LINESE~1\main.obj  \
            del E:\ROBOTI~1\APRIL7~1\LINESE~1\main.obj

rebuildall: clean Release

relink: deltarget Release

LIBS = 

OBJS =  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\zsldevinit.obj  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\main.obj

line_sensor: $(OBJS)
	 $(LINK)  @E:\ROBOTI~1\APRIL7~1\LINESE~1\line_sensor_Release.linkcmd

E:\ROBOTI~1\APRIL7~1\LINESE~1\zsldevinit.obj :  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\zsldevinit.asm  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\ez8dev.inc  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) E:\ROBOTI~1\APRIL7~1\LINESE~1\zsldevinit.asm

E:\ROBOTI~1\APRIL7~1\LINESE~1\main.obj :  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\main.c  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std\FORMAT.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std\STDARG.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std\STDIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\std\STRING.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\defines.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\dmadefs.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\ez8.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\gpio.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\SIO.H  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\uart.h  \
            C:\PROGRA~1\ZiLOG\ZDSII_~1.6\include\zilog\uartdefs.h  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\ROOMFU~1.H  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\armpit.h  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\camera.h  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\DISTAN~1.H  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\encoder.h  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\INTERR~1.H  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\LINESE~1.H  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\motor.h  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\NAVIGA~1.H  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\PATHFI~1.H  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\ROOMMO~1.H  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\timer.h  \
            E:\ROBOTI~1\APRIL7~1\LINESE~1\util.h
	 $(CC)  $(CFLAGS) E:\ROBOTI~1\APRIL7~1\LINESE~1\main.c

