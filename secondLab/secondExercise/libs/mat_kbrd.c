
#include "mat_kbrd.h"
#include <avr/io.h>
#include <util/delay.h>
//unsigned static char* kbrd_port;

//TODO: agregar la mascara para el otro pin si se esta utilizando un teclado 4x4
#define KBRD_ROW_MASK()  (KBRD_F0_PINPORT & (1<<KBRD_F0_PIN)) >> KBRD_F0_PIN | ((KBRD_F1_PINPORT & (1<<KBRD_F1_PIN)) >> KBRD_F1_PIN) << 1 | ((KBRD_F2_PINPORT & (1<<KBRD_F2_PIN)) >> KBRD_F2_PIN) << 2 | ((KBRD_F3_PINPORT & (1<<KBRD_F3_PIN)) >> KBRD_F3_PIN) << 3

#define KBRD_ROW_MASK_AL()  (~(KBRD_F0_PINPORT | ~(1<<KBRD_F0_PIN)) >> KBRD_F0_PIN) | (~(KBRD_F1_PINPORT | ~(1<<KBRD_F1_PIN)) >> KBRD_F1_PIN) << 1 | (~(KBRD_F2_PINPORT | ~(1<<KBRD_F2_PIN)) >> KBRD_F2_PIN) << 2 | (~(KBRD_F3_PINPORT | ~(1<<KBRD_F3_PIN)) >> KBRD_F3_PIN) << 3

//function prototypes
 void activate_column(unsigned char column);
 void reset_columns(void);

void kbrd_init()
{
	//Column pins are Outputs
	KBRD_C0_DDR |= (1<<KBRD_C0_PIN);
	KBRD_C1_DDR |= (1<<KBRD_C1_PIN);
	KBRD_C2_DDR |= (1<<KBRD_C2_PIN);
	KBRD_C3_DDR |= (1<<KBRD_C3_PIN);
	
	//Row pins are Inputs
	KBRD_F0_DDR &= ~(1<<KBRD_F0_PIN);
	KBRD_F1_DDR &= ~(1<<KBRD_F1_PIN);
	KBRD_F2_DDR &= ~(1<<KBRD_F2_PIN);
	KBRD_F3_DDR &= ~(1<<KBRD_F3_PIN);
	
	
	//enable pull ups on row pins
	KBRD_F0_PORT |= (1<<KBRD_F0_PIN);
	KBRD_F1_PORT |= (1<<KBRD_F1_PIN);
	KBRD_F2_PORT |= (1<<KBRD_F2_PIN);
	KBRD_F3_PORT |= (1<<KBRD_F3_PIN);
	// Put Ones in Columns
	KBRD_C0_PORT |= (1<<KBRD_C0_PIN);
	KBRD_C1_PORT |= (1<<KBRD_C1_PIN);
	KBRD_C2_PORT |= (1<<KBRD_C2_PIN);
	KBRD_C3_PORT |= (1<<KBRD_C3_PIN);
	

}

char kbrd_read(void)
{
	//reset_columns();
	char tecla=0;
	//verify first column
	activate_column(0);

	_delay_ms(KBRD_DELAY);

	switch(KBRD_ROW_MASK_AL())
		{
		case 1:
			 tecla='7';
		break;
		case 2:
			tecla= '4';
		break;
		case 4:
			tecla= '1';
		break;
		case 8:
			tecla= '.';
		break;
	}	



	//verify second column
	activate_column(1);

	_delay_ms(KBRD_DELAY);

	switch(KBRD_ROW_MASK_AL())
	
	{
		case 1:
			tecla= '8';
		break;
		case 2:
			tecla= '5';
		break;
		case 4:
			tecla= '2';
		break;
		case 8:
			tecla= '0';
		break;
		
	}	
	
	
	
	//verify thirth column
	activate_column(2);
	
	_delay_ms(KBRD_DELAY);

	switch(KBRD_ROW_MASK_AL())
	
	{
		case 1:
			tecla= '9';
		break;
		case 2:
			tecla= '6';
		break;
		case 4:
			tecla= '3';
		break;
		case 8:
			tecla= '=';
		break;
		
	}
	
	
	//verify first column
	activate_column(3);

	_delay_ms(KBRD_DELAY);

	switch(KBRD_ROW_MASK_AL())
	{
		case 1:
			tecla= '/';
		break;
		case 2:
			tecla= '*';
		break;
		case 4:
			tecla= '-';
		break;
		case 8:
			tecla= '+';
		break;
	}	
	
	reset_columns();
	
	if (tecla!=-1)
	{
		return tecla;
	}
	else{return 0;}
	
}

//FIXME: 
void activate_column(unsigned char column)
{
	if(column == 0)
	{
		KBRD_C0_PORT &= ~(1<< KBRD_C0_PIN);
		KBRD_C1_PORT |= (1<< KBRD_C1_PIN);
		KBRD_C2_PORT |= (1<< KBRD_C2_PIN);
		KBRD_C3_PORT |= (1<< KBRD_C3_PIN);	
		
	}
	 if(column == 1)
	{
		KBRD_C0_PORT |= (1<< KBRD_C0_PIN);
		KBRD_C1_PORT &= ~(1<< KBRD_C1_PIN);
		KBRD_C2_PORT |= (1<< KBRD_C2_PIN);
		KBRD_C3_PORT |= (1<< KBRD_C3_PIN);
			
	}
	if(column == 2)
	{
		KBRD_C0_PORT |= (1<< KBRD_C0_PIN);
		KBRD_C1_PORT |= (1<< KBRD_C1_PIN);
		KBRD_C2_PORT &= ~(1<< KBRD_C2_PIN);
		KBRD_C3_PORT |= (1<< KBRD_C3_PIN);
			
	}
	//FIXME: completar para un teclado 4x4
	if(column == 3)
	{
		KBRD_C0_PORT |= (1<< KBRD_C0_PIN);
		KBRD_C1_PORT |= (1<< KBRD_C1_PIN);
		KBRD_C2_PORT |= (1<< KBRD_C2_PIN);
		KBRD_C3_PORT &= ~(1<< KBRD_C3_PIN);
		
	}
	
}


void reset_columns()
{
	
	KBRD_C0_PORT |= (1<< KBRD_C0_PIN);
	KBRD_C1_PORT |= (1<< KBRD_C1_PIN);	
	KBRD_C2_PORT |= (1<< KBRD_C2_PIN);
	KBRD_C3_PORT |= (1<< KBRD_C3_PIN);	
		
}
