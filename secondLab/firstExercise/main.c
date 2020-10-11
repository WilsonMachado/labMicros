/* 

# Archivo:      Primer problema: 'Hola mundo, ATmega2560'
# Autores:      Katerine Lotero, Pablo Uribe, Wilson Machado
# Copyright:    Laboratorio de Microprocesadores y Ensamblador
# Licencia:     Universidad del Valle - Ingeniería Electrónica

*/

//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega2560__
    #define __AVR_ATmega2560__
#endif

//*****************************//

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>


int main(void){

    DDRA |= (0xF3);  // Es decir, 1111 | 0011

    PORTA |= (0x0C); // Es decir, 0000 | 1100 ---> Salidas apagadas y resistencias de Pull-Up activadas

    while(1)    {        

        if((PINA & (1 << PORTA2)) == 0){ // Operación AND entre PINA y el PIN A2 para saber si se ha puesto en 0
            PORTA |= (1 << PORTA0);            
        }else   {
            PORTA &= ~(1 << PORTA0);
        }

        if((PINA & (1 << PORTA3)) == 0){ // Operación AND entre PINA y el PIN A3 para saber si se ha puesto en 0
            PORTA |= (1 << PORTA1);            
        }else   {
            PORTA &= ~(1 << PORTA1);
        }

    }

    return 0;
}

     /*  

       Porción de código inicial (para el problema solicitado no es necesario)
       
       PORTA |= (0x01);
       PORTA &= ~(0x02);
       _delay_ms(500);

       PORTA &= ~(0x01);
       PORTA |= (0x02);
       _delay_ms(500); 
        
    */