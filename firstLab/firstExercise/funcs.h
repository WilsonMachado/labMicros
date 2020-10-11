double sum(double arr[], int lenArr);

void sumWithPointer(double** arr, int* lenArr, int col, double* sumP);

// Nótese que se modificó la función sumWithPointer con el fin de que ahora reciba una matriz de datos
// y pueda sumar sus columnas. Esto se hizo con el fin de que se pudiera implementar esta función 
// en el algoritmo pearsonC. Además, se le quitó que retorne un double; en su lugar, ahora modifica el
// valor de una variable por su dirección de memoria.

void pearsonC(double** arr, double* pearsonR, int* lenArr);

void writeFile(double** arr, double* pearsonR, int* lenArr, FILE* archivo);