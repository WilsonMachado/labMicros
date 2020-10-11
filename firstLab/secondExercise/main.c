#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"
#include "funcs.c"

int main(){

    // Variables necesarias             

    int input[4], output[2], sel, i, j; // input[4] almacena los criteios de búsqueda. 
                                        // output[2] almacena el resultado de la búsqueda.
                                        // sel guarda la selección del ususario.
                                        // i y j son para recorre matrices (contadores).    
    
    char option[30];                    // option[30] guarda el color que ingresa el usuario como string.

    // Tabla de datos codificada

    int eyes[8] = {0, 0, 1, 1, 2, 2, 3, 3};         // Primera fila de la matriz
    int pants[8] = {2, 4, 2, 4, 2, 4, 2, 4};        // Segunda fila de la matriz
    int shirts[8] = {4, 5, 6, 0, 2, 3, 7, 8};       // Tercera fila de la matriz
                  

    int** matrix[3][8];                             // matriz de punteros para almacenar la tabla de datos.

    for(i = 0; i < 8; i++)   {                      // Se almacena la información de la tabla en un matriz de punteros
        matrix[0][i] = eyes[i];
        matrix[1][i] = pants[i];
        matrix[2][i] = shirts[i];
    }    

    // Ahora inicia el programa

    printf("Programa asesor de moda\n\n");

    i = 0;
            
    do{

        printf("Indique qué característica desea ingresar:\n");
        printf("1) Color de ojos\n");
        printf("2) Color de pantalón\n");
        printf("3) Color de camisa\n");


        scanf("%d", &sel);

        switch (sel)  {
            case 1:
                printf("Ingrese el color de ojos con las letras en minúsculas:\n");
                scanf("%s", option);                 // Se almacena la cadena de caracteres equivalente al color
                input[i] = sel;                      // Se almacena la opción ingresada por el usuario
                colorToNum(option, input, &i, &sel); // Se convierte el color ingresado (string) a número (int) para ser procesado
                if(sel != 4) i += 2; // Se garantiza que solo se incrementa i si se ingresado un dato correcto (Código de error: 4)
                break;
            
            case 2:
                printf("Ingrese el color del pantalón con las letras en minúsculas:\n");
                scanf("%s", option);
                input[i] = sel;
                colorToNum(option, input, &i, &sel);
                if(sel != 4) i += 2;      
                break;
            
            case 3:
                printf("Ingrese el color de la camisa con las letras en minúsculas:\n");
                scanf("%s", option);
                input[i] = sel;
                colorToNum(option, input, &i, &sel);
                if(sel != 4) i += 2;        
                break;
            
            default:
                printf("La opción ingresada no existe. Por favor, ingrese una opción válida.\n");
                break;
        }
    }while((sel > 3) || (sel == 0) || (i < 4)); // Esto se ejecuta mientras el usuario cometa errores o la información necesaria esté incompleta

    printf("\n");
 
    buscar(matrix, input, output); // Llama a la función que busca las coincidencias

    if((output[0] == 0) && (output[1] == 0))    { // Si no hay coincidencias lo informa, de lo contrario muestra el resultado
        printf("La información ingresada no arrojó coincidencias.\n\n");
    }else{
        printf("Esta combinación es adecuada si el %s es %s.\n\n", numToNoun(output[0]), numToColor(output[1])); 
    }  
    
    system("pause");
    return 0;
}

/* Código usado para debug

// printf("\nLas opciones ingresadas fueron: \n\n");
    // for(i = 0; i < 2; i++)   {             
    //     printf("El %s fue %s\n", numToNoun((input[(i*2)])), numToColor((input[(i*2) + 1])));
    // }


// printf("La opción es %d y el color es %d\n\n", output[0], output[1])


*/