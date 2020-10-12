/* 

# Archivo:      Segundo problema: 'Calculadora básica'
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

#include "libs/lcd.h"       // Librería para la pantalla LCD 2x16
#include "libs/lcd.c"

#include "libs/mat_kbrd.h"  // Librería para el teclado matricial 4x4
#include "libs/mat_kbrd.c"

#include "funcs.h"
#include "funcs.c"

int main(void){

    lcd_init(LCD_DISP_ON);          // Inicializa la pantalla LCD. Está conectada al puerto B

    kbrd_init();                    // Inicializa el teclado matricial. Está conectado al puerto C 
    
    lcd_clrscr();                   // Limpia la pantalla LCD
    
    lcd_home();                     // Ubica el puntero en la posición inicial (0,0)
    
    lcd_puts("Wil Kate y Pablo");   // Una frase en la primera línea al iniciar >:3 
    lcd_gotoxy(0, 1);               // Cambio el cursor a la segunda línea de la pantalla, y primer elemento (0,1)
    lcd_puts(" LAB II: MICROS ");   // Una frase en la segunda línea al iniciar >:3 

    _delay_ms(3000);                // Espera 3 segundos para ver el mensaje

    lcd_clrscr();                   // Limpia la pantalla LCD
    lcd_home();                     // Ubica el puntero en la posición inicial (0,0)

    lcd_puts("  Calculadora   ");   // Primera línea de presentación del programa 
    lcd_gotoxy(0, 1);               // Cambio el cursor a la segunda línea de la pantalla, y primer elemento (0,1)
    lcd_puts("   basica UwU   ");   // Segunda línea de presentación del programa 
    
    _delay_ms(3000);                // Espera 3 segundos para ver el mensaje

    lcd_clrscr();                   // Limpia la pantalla LCD
    lcd_home();                     // Ubica el puntero en la posición inicial (0,0)

    while(1)    { 

    float fNumber = 0;         // Primer número de la operación
    float sNumber = 0;         // Segundo número de la operación
    float result = 0;          // Resultado de la operación

    char operator = 0;         // Almacena el operador de la expresión a realizar
    
    accNumber(&fNumber, &operator);

    _delay_ms(10);

    if(operator == 0){                // Si se ingresó el primer operando, pero no se seleccionó operador
        while(operator != '+' || operator != '-' || operator != '*' || operator != '/'){
            operator = kbrd_read();
            _delay_ms(10);
            if(operator == '+' || operator == '-' || operator == '*' || operator == '/'){
                break;                
            }
        }
        lcd_putc(operator);
        _delay_ms(10);
    }                    
    accNumber(&sNumber, &operator);   // De lo controario, si se seleccionó operador
            
     lcd_putc('=');              // Imprime '='   

    switch (operator) { // Para determinar qué operación realizar con los dos datos ingresados
        case '+':
            result = fNumber + sNumber; 
        break;
        case '-':
            result = fNumber - sNumber; 
        break;
        case '*':
            result = (fNumber) * (sNumber); 
        break;
        case '/':
            result = fNumber / sNumber; 
        break;
    
    default:
        break;
    }      

    int entero = result;                    // Truca la parte entera
    int decimal = (result - entero) * 100;  // Y la parte decimal (2 decimales)
    
    lcd_gotoxy(0, 1);                       // Se posiciona en la segunda fila, primera columna
    
    numToLcd(entero);                       // Imprime la parte entera
    lcd_putc('.');                          // Imprime el punto decimal
    numToLcd(decimal);                      // Imprime la parte decimal
  
    _delay_ms(3000);                        // Mantiene los datos 3 segundos en pantalla 
    
    lcd_clrscr();                           // Limpia la pantalla LCD
    lcd_home();                             // Ubica el puntero en la posición inicial (0,0)    
            
    }                  

    return 0;
}








