#include <stdio.h>
#include <math.h>

double sum(double arr[], int lenArr){             // Sumar elementos de un arreglo sin apuntadores

    double result = 0;
    int i;

    for (i = 0; i < lenArr; i++){
        result += arr[i];
    }
     
    return result;

}
// Pablo estuvo aqui. 
void sumWithPointer(double** arr, int* lenArr, int col, double* sumP){  // Sumar elementos de un arreglo con apuntadores  

    int i;

    for (i = 0; i < *lenArr; i++){
       (*sumP) += arr[i][col]; 
    }  

}
<<<<<<< HEAD

void squaredComponent(double** arr, int* lenArr, int col, double* sumPS){ // Calcula la suma de los elementos de un arreglo al cuadrado
=======
// Otra prueba
void squaredComponent(double** arr, int* lenArr, int col, double* sumPS){
>>>>>>> 21a53c35a0ff5c99f87132a0c59e4a20fe5ea393

    int i;

    for(i = 0; i < *lenArr; i++){                           
        (*sumPS) += arr[i][col]*arr[i][col]; 
    }

}
// Pruebasssss
void pearsonC(double** arr, double* pearsonR, int* lenArr){ // Calcula el coeficiente de Pearson




    int i, j;
    double xy = 0, sumX = 0, sumY = 0, sumXS = 0, sumYS = 0;
    
    for(i = 0; i < *lenArr; i++){                           // sum(xy)
        xy += arr[i][0]*arr[i][1]; 
    }

    sumWithPointer(arr, lenArr, 0, &sumX);
    sumWithPointer(arr, lenArr, 1, &sumY);

    squaredComponent(arr, lenArr, 0, &sumXS);
    squaredComponent(arr, lenArr, 1, &sumYS);



    (*pearsonR) = (((*lenArr)*xy) - (sumX*sumY)) / (sqrt(((*lenArr)*sumXS - (sumX*sumX)) * ((*lenArr)*sumYS - (sumY*sumY))));

}

void writeFile(double** arr, double* pearsonR, int* lenArr, FILE* archivo){ // Guarda las parejas ingresadas y el coeficiente de Pearson en un archivo 

    int i, j;
    char buf[100];

    archivo =  fopen("file.txt", "w");

    fputs("X Y\n", archivo);// X Y

    fclose(archivo);

    archivo =  fopen("file.txt", "a");

    for(i = 0; i < (*lenArr); i++){
        for(j = 0; j < 2; j++){
            
            gcvt(arr[i][j], 4, buf);

            fputs(buf, archivo);
            fputs(" ", archivo);
        }

        fputs("\n", archivo);
        
    }

    fputs("\n", archivo);

    fputs("El coeficiente de correlación de Pearson es: ", archivo);
    gcvt((*pearsonR), 4, buf);
    fputs(buf, archivo);

    fputs("\n\n", archivo);

    fputs("Por Kate, Pablo y Wilson.", archivo); // Firma del autor :v

    fclose(archivo);

}