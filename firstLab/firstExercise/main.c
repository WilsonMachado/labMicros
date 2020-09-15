#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char num_in[8]; 		// Variable para recibir datos de consola
	double num_out[2]; 		// Variable para almacenar los números 
	int i;					// Variable de control ciclo For
	
	for(i = 0; i < 2; i = i+1){
	
		scanf("%s", &num_in); 	  // Escaneo de entrada de teclado
		num_out[i] = atof(num_in); // Conversión string a double
					
	}
	
	
	printf("Potencia: %4.2f\n", pow(num_out[0],2)); // Cálculo de potencia al cuadrado
	printf("Raiz: %4.2f\n", sqrt(num_out[1]));		// Cálculo de raíz cuadrada	

    system("pause");
	
	return 0;
}
 