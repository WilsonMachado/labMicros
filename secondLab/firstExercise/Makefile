# Ruta a incluir en el C/C++ de VS Code: C:\WinAVR-20100110\avr\include

# Archivo: Makefile
# Autores: Kate, Pablo, JuanJo y Wilson
# Copyright: C de C y C de Control
# Licencia: C de C y C de Control

# TARGET ....... Nombre del archivo principal (main.c) sin el '.c'.
# DEVICE ....... Aquí se debe poner el micro con el que se esté trabajando.
# CLOCK ........ Aquí se debe poner el reloj con el que se esté trabajando (en Hertz).
# OBJECTS ...... Archivo que se relaciona los .c para crear los demás archivos (extensión .o).           
# PROGRAMMER ... Define el hardware con el que se va a programar el micro en caso de que se quiera
#				 hacer desde aquí (caracterísitica por agregar).
# FUSES ........ Parámetros para el programador del micro. Esto define características específicas.

TARGET = main

DEVICE     = atmega2560
CLOCK      = 16000000
OBJECTS    = $(TARGET).o
#PROGRAMMER = -c arduino -P $(PORT) -b 19200 
#FUSES      = -U lfuse:w:0x64:m -U hfuse:w:0xdd:m -U efuse:w:0xff:m


######################################################################
######################################################################

# Líneas para el programador y compilador respectivamente:

#AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE)
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)


# Inicio de creación de los archivos objetivos:
all:	$(TARGET).hex

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@
# NOTA: "-x assembler-with-cpp" no debería ser necesario porque esta opción está por defecto
# sin embargo, se ha puesto porque podría dar problemas de compatibilidad en caso de que no lo esté.

.c.s:
	$(COMPILE) -S $< -o $@

clean:
	rm -f $(TARGET).hex $(TARGET).elf $(OBJECTS)

# Archivos objetivos:

$(TARGET).elf: $(OBJECTS)
	$(COMPILE) -o $(TARGET).elf $(OBJECTS)

$(TARGET).hex: $(TARGET).elf
	rm -f $(TARGET).hex
	avr-objcopy -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex

# Para hacer debug y análisis del código:
disasm:	$(TARGET).elf
	avr-objdump -d $(TARGET).elf

cpp:
	$(COMPILE) -E $(TARGET).c
