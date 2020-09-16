#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define cols 2 // Como son parejas, la matriz donde se almacenarán tendrán 2 columnas y n filas (n parejas).

int main(int argc, char *argv[]) {
	
	int i,n;	
	double **pairs; // Matrix de n x 2 para almacenar las parejas

	printf("Introduzca el número de parejas que desea ingresar: ");
	scanf("%d", &n);

	pairs = (double **)malloc(n*sizeof(double)); // Le añado la cantidad de filas a la matriz
		
	for(i = 0; i < n; i = i+1){ // Le añado la cantidad de columnas la matriz

		pairs[i] = 	(double *)malloc(cols*sizeof(double)); 					
	}

	printf("Introduzca las parejas, con cada valor separado por espacio (e.j: x y): \n");

	for(i = 0; i < n; i = i+1){				// Introduzco los valores de la matriz

		scanf("%lf", &pairs[i][0]);		
		scanf("%lf", &pairs[i][1]); 

		printf("\n");		
	}	

	printf("La matriz introducida es: \n"); 
	
	for(i = 0; i < n; i = i+1){				// Imprimo la matriz de las parejas para saber cómo quedaron
		
		printf("%.2f ", pairs[i][0]);
		printf("%.2f \n", pairs[i][1]); 					
	}

	printf("\n");

	system("pause");    
	
	return 0;
}
 