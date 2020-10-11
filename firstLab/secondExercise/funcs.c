#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* numToColor(int input){ // Decodificar los números a colores

    char* color;

    switch (input)    {

        case 0:
            color = "verde";
            break;
        case 1:
            color = "cafe";
            break;
        case 2:
            color = "azul";
            break;
        case 3:
            color = "gris";
            break;
        case 4:
            color = "negro";
            break;
        case 5:
            color = "blanco";
            break;
        case 6:
            color = "rosado";
            break;
        case 7:
            color = "amarillo";
            break;
        case 8:
            color = "rojo";
            break;
        default:
            color = "indefinido";
            break;
    }
    return color;
}

void colorToNum(char option[], int* input, int* i, int* sel){ // Codifica los colores en números 
    
    if(!(strcmp(option, "verde")))    { // La función strcmp arroja un 0 si una cadena de caracteres es igual a otra. Dicha función está en la librería string.h
        input[(*i) + 1] = 0;    
    }else if (!(strcmp(option, "cafe")))    {
        input[(*i) + 1] = 1;
    }else if (!(strcmp(option, "azul")))    {
        input[(*i) + 1] = 2;
    }else if (!(strcmp(option, "gris")))    {
        input[(*i) + 1] = 3;
    }else if (!(strcmp(option, "negro")))    {
        input[(*i) + 1] = 4;
    }else if (!(strcmp(option, "blanco")))    {
        input[(*i) + 1] = 5;
    }else if (!(strcmp(option, "rosado")))    {
        input[(*i) + 1] = 6;
    }else if (!(strcmp(option, "amarillo")))    {
        input[(*i) + 1] = 7;
    }else if (!(strcmp(option, "rojo")))    {
        input[(*i) + 1] = 8;
    }else{
        printf("El color ingresado no es correcto o no se encuentra en la base de datos.\n\n");
        (*sel) = 4;
        return;
    }    
}

char* numToNoun(int input){ // Decodifica los números a sustantivos
    
    char* noun;

    switch (input)    {
        case 1:
            noun = "color de ojos";
            break;
        case 2:
            noun = "color de los pantalones";
            break;
        case 3:
            noun = "color de la camisa";
            break;
        
        default:
            noun = "no encontrado";
            break;
    }
    return noun;
}

void buscar(int matrix[3][8], int* input, int* output){ // Busca coincidencias en la matriz y, si las hay, los muestra; de lo contrario, arroja una advertencia de no coincidencia.

    int i; // Variable para los ciclos for 

    if(((input[0] == 1) && (input[2] == 2)) || ((input[0] == 2) && (input[2] == 1)))    { // Si se ingresa un color de ojos y un color de pantalón o viceversa
        
        for(i = 0; i < 8; i++)   {
            if( ((input[0] == 1) && (input[2] == 2))  && (input[1] == matrix[0][i]) && (input[3] == matrix[1][i]) || ((input[0] == 2) && (input[2] == 1))  && (input[1] == matrix[1][i]) && (input[3] == matrix[0][i]) ){ // Y es una combinación que tiene coincidencias.
                output[0] = 3;
                output[1] = matrix[2][i]; // Se almace el valor recomendado para ser mostrado.  
                break;              
            }else   {
                output[0] = 0;
                output[1] = 0;            // De lo contrario, se muestra que no hay conincidencias.
            }
        }
        
    }else if (((input[0] == 1) && (input[2] == 3)) || ((input[0] == 3) && (input[2] == 1)))    { // De lo contrario, si se ingresa un color de ojos y un color de camisa o viceversa.
        
        for(i = 0; i < 8; i++)   {
            if( ((input[0] == 1) && (input[2] == 3))  && (input[1] == matrix[0][i]) && (input[3] == matrix[2][i]) || ((input[0] == 3) && (input[2] == 1))  && (input[1] == matrix[2][i]) && (input[3] == matrix[0][i]) ){// Y es una combinación que tiene coincidencias.
                output[0] = 2;
                output[1] = matrix[1][i]; // Se almace el valor recomendado para ser mostrado.
                break;
            }else   {
                output[0] = 0;
                output[1] = 0;            // De lo contrario, se muestra que no hay conincidencias.
            }
        }
        
    }else if (((input[0] == 2) && (input[2] == 3)) || ((input[0] == 3) && (input[2] == 2)))    { // De lo contrario, si se ingresa un color de pantalón y un color de camisa o viceversa.
        for(i = 0; i < 8; i++)   {
            if( ((input[0] == 3) && (input[2] == 2))  && (input[1] == matrix[2][i]) && (input[3] == matrix[1][i]) || ((input[0] == 2) && (input[2] == 3))  && (input[1] == matrix[1][i]) && (input[3] == matrix[2][i]) ){ // Y es una combinación que tiene coincidencias.
               
                output[0] = 1;
                output[1] = matrix[0][i]; // Se almace el valor recomendado para ser mostrado.
                break;
            }else   {
                output[0] = 0;
                output[1] = 0;            // De lo contrario, se muestra que no hay conincidencias.
            } 
        }
        
    }else   {                             // De lo contrario, se muestra que no hay conincidencias
        output[0] = 0;
        output[1] = 0;                    
    }   
   
}