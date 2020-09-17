double sum(double arr[], int lenArr){             // Sumar elementos de un arreglo sin apuntadores

    double result = 0;
    int i;

    for (i = 0; i < lenArr; i++)
    {
        result += arr[i];
    }
     
    return result;

}

double sumWithPointer(double* arr, int* lenArr){  // Sumar elementos de un arreglo con apuntadores  

    double result = 0;
    int i;

    for (i = 0; i < *lenArr; i++)
    {
       result += arr[i]; 
    }
     
    return result;

}