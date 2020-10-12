//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega2560__
    #define __AVR_ATmega2560__
#endif

//*****************************//


#ifndef MAT_KBRD_H
#define MAT_KBRD_H


//delay when reading each column
#define KBRD_DELAY 50

//Port definition if all pins belong to a single port.

#define KBRD_PORT PORTC
#define KBRD_DDR DDRC
#define KBRD_PINPORT PINC

#define KBRD_C0_PORT KBRD_PORT
#define KBRD_C1_PORT KBRD_PORT
#define KBRD_C2_PORT KBRD_PORT
#define KBRD_C3_PORT KBRD_PORT
#define KBRD_F0_PORT KBRD_PORT
#define KBRD_F1_PORT KBRD_PORT
#define KBRD_F2_PORT KBRD_PORT
#define KBRD_F3_PORT KBRD_PORT

#define KBRD_C0_DDR KBRD_DDR
#define KBRD_C1_DDR KBRD_DDR
#define KBRD_C2_DDR KBRD_DDR
#define KBRD_C3_DDR KBRD_DDR
#define KBRD_F0_DDR KBRD_DDR
#define KBRD_F1_DDR KBRD_DDR
#define KBRD_F2_DDR KBRD_DDR
#define KBRD_F3_DDR KBRD_DDR

#define KBRD_F0_PINPORT KBRD_PINPORT
#define KBRD_F1_PINPORT KBRD_PINPORT
#define KBRD_F2_PINPORT KBRD_PINPORT
#define KBRD_F3_PINPORT KBRD_PINPORT


//Pin definitions
/*
MATRIX KEYPAD PIN DESCRIPTION
1 --> C1
2 --> F0
3 --> C0
4 --> F3
5 --> C2
6 --> F2
7 --> F1
8 --> C3
*/

//#define KBRD_C0_PIN 2
//#define KBRD_C1_PIN 0
//#define KBRD_C2_PIN 4
//#define KBRD_C3_PIN 7
//#define KBRD_F0_PIN 1
//#define KBRD_F1_PIN 6
//#define KBRD_F2_PIN 5
//#define KBRD_F3_PIN 3

//MATRIX KEYPAD PIN DESCRIPTION

//1 --> C0
//2 --> C1
//3 --> C2
//4 --> C3
//5 --> F0
//6 --> F1
//7 --> F2
//8 --> F3

//MATRIX KEYPAD PIN DESCRIPTION (adaptación a Proteus)

// C0 --> 1
// C1 --> 2
// C2 --> 3
// C3 --> 4
// C4 --> A
// C5 --> B
// C6 --> C
// C7 --> D

#define KBRD_C0_PIN 0
#define KBRD_C1_PIN 1
#define KBRD_C2_PIN 2
#define KBRD_C3_PIN 3
#define KBRD_F0_PIN 4
#define KBRD_F1_PIN 5
#define KBRD_F2_PIN 6
#define KBRD_F3_PIN 7





void kbrd_init(void);


char kbrd_read(void);


#endif
