/* Laboratorio de Microprocesadores y Ensamblador

///////////////////////		Primer problema		/////////////////////// 

Autores:

- Katerine Lotero. 

- Pablo A. Uribe.

- Wilson D. Machado.

Profesor: Fabio Rivadeneira.

Ingeniería Electrónica.

Universidad del Valle. */

#include <stdio.h>
#include <stdlib.h>


#include "funcs.h"
#include "funcs.c"


int main(int argc, char* argv[]) {
	
	int i,n;
	int cols = 2; // Como son parejas, la matriz donde se almacenarán tendrán 2 columnas y n filas (n parejas). TUve que volver a cols una variable para poder trabajar con punteros.

	double** pairs; // Matrix de n x 2 para almacenar las parejas
	
	double pearsonR = 0; // Almacena el resultado del coeficiente de correlación de Pearson

	FILE* archivo;		// Archivo donde se guardarán las parejas ingresadas y el coeficiente de Pearson 

	printf("Introduzca el número de parejas que desea ingresar: ");
	scanf("%d", &n);

	pairs = (double**)malloc(n*sizeof(double*)); // Le añado la cantidad de filas a la matriz.

	// En la línea anterior me faltó un asterisco 'sizeof(double *)', ya que lo que se busca crear es un puntero de punteros.
		
	for(i = 0; i < n; i ++){ // Le añado la cantidad de columnas la matriz

		pairs[i] = 	(double*)malloc(cols*sizeof(double)); 					
	}

	printf("Introduzca las parejas, con cada valor separado por espacio (e.j: x y): \n");

	for(i = 0; i < n; i ++){				// Introduzco los valores de la matriz

		scanf("%lf", &pairs[i][0]);		
		scanf("%lf", &pairs[i][1]); 

		printf("\n");		
	}	

	printf("La matriz introducida es: \n"); 
	
	for(i = 0; i < n; i ++){				// Imprimo la matriz de las parejas para saber cómo quedaron
		
		printf("%.2f ", pairs[i][0]);
		printf("%.2f \n", pairs[i][1]); 					
	}

	printf("\n");

	// Aquí, se llama a la función perasonC la cual calcula el coeficiente de correlación de Pearson
	// de la matriz de datos ingresada anteriormente pasando los parámetros como apuntadores de 
	// memoria.

	pearsonC(pairs, &pearsonR, &n);

	printf("El coeficiente de correlación de Pearson es: %.4f", pearsonR);

	
	printf("\n");

	writeFile(pairs, &pearsonR, &n, archivo);


	system("pause"); 	

	return 0;
}
 