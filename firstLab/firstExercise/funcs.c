#include <stdio.h>
#include <math.h>

double sum(double arr[], int lenArr){             // Sumar elementos de un arreglo sin apuntadores

    double result = 0;
    int i;

    for (i = 0; i < lenArr; i++)
    {
        result += arr[i];
    }
     
    return result;

}
// Pablo estuvo aqui. 
void sumWithPointer(double** arr, int* lenArr, int col, double* sumP){  // Sumar elementos de un arreglo con apuntadores  

    int i;

    for (i = 0; i < *lenArr; i++)
    {
       (*sumP) += arr[i][col]; 
    }  

}

void squaredComponent(double** arr, int* lenArr, int col, double* sumPS){

    int i;

    for(i = 0; i < *lenArr; i++){                           
        (*sumPS) += arr[i][col]*arr[i][col]; 
    }

}

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