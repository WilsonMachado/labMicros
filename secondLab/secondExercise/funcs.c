void numToLcd(int number){  // Función para imprimir un número en la pantalla LCD

    char result[10];
    int cont = 0;
    int i;    
    
    if  (number == 0){
        
        lcd_putc('0');
        
        } else{

            while(number != 0){
                result[cont] = (number % 10) + 48;
                number = (number - (number % 10)) / 10;
                if (number != 0) cont++;                
            }

            // Impresión

            for(i = 0; i <= cont; i++){
                lcd_putc(result[cont - i]);        
            }

    } 

}

void accNumber(float* number, char* operator){      // Función para ingresar los números de la operación

    
    int cont = 0;   

    while (cont < 3){                   // Máximo se pueden ingresar 3 dígitos

        char caracter = 0;              // Variable que almacenará el caracter presionado
        caracter = kbrd_read();         // Lectura del teclado matricial
            
        if(caracter != 0){              // Siempre y cuando se oprima un caracter

            if(caracter == '.'){        // Si se ingresa un punto, quiere decir que se va a ingresar la parte
                                        // decimal y debe terminar de ingresar la parte entera.
            
                lcd_putc(caracter);     // Imprime el punto decimal en pantalla
                _delay_ms(10);          // Tiempo de espera para evitar rebotes.
                
                accDecimal(number, operator);     // Llama a la fución que permite ingresar la parte decimal del
                                                  // número de la operación

               return;                  // Termina el ingreso de la parte entera

                }else if(caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/'){
                    
                    if((*operator) == 0){
                        lcd_putc(caracter);      // Imprime el operador en pantalla
                        (*operator) = caracter;  // Almacena el operador para determinar qué debe hacer
                        _delay_ms(10);           // Espera antirebote
                        return;
                    }else{
                        _delay_ms(10);
                    }
  
                    
               
                } else if(caracter == '='){
                    
                    if((*operator != 0)){
                        _delay_ms(10);
                        return;
                    }else{
                        _delay_ms(10);
                    }
                    
                }else{                                          // Si se ingresa un número, se acumula

                    (*number) = ((*number)*10) + caracter - 48; // El número nuevo ingresado tendrá una 
                                                                // década menos que el anterior y como el dato 
                                                                // es ingresado en ASCII se le resta 48 (ver tabla)
                                                                // para convertirlo a entero. 
                                                                // El resultado es almacenado en el valor de la
                                                                // dirección de memoria del número ingresado. 
                    
                    lcd_putc(caracter);                         // Se imprime el caracter en pantalla (echo).
                    _delay_ms(10);                              // Tiempo de espera para evitar rebotes.
                    cont++;                                     // Incrementa el contador para saber que se ha
                                                                // ingresado un nuevo digito
                    }          

        }
                 
    }
    
}

void accDecimal(float* number, char* operator){         // Función para ingresar los decimales de los números de la operación

    int i;
    int cont = 0;
    float aux = 0;                      // Variable auxiliar para ordenar los decimales 

    while (cont < 2){                   // Máximo se pueden ingresar 2 decimales

        char caracter = 0;              // Variable que almacenará el caracter presionado
        caracter = kbrd_read();         // Lectura del teclado matricial
            
        if(caracter != 0){              // Siempre y cuando se oprima un caracter

            if(caracter == '.'){
                
                _delay_ms(10);          // Un número no lleva doble punto decimal !!

            }else if(caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/'){
                    
                    if((*operator) == 0){        // Si aún no hay operador
                        
                        lcd_putc(caracter);      // Imprime el operador en pantalla
                        
                        (*operator) = caracter;  // Almacena el operador para determinar qué debe hacer
                        
                        _delay_ms(10);           // Espera antirebote
                        
                        if(cont != 0){
        
                             for(i = 0; i < cont; i++){
                                 aux = aux / 10; // Se posiciona el punto decimal según los datos
                                                 // ingresados
                            }
                        }
                        (*number) += aux;                        
                        return;                  // Regresa para obtener el siguiente número
                    
                    }else{                      // Si ya hay operador, no hace nada
                        _delay_ms(10);                    
                    }                   
               
            }else if(caracter == '='){
                    
                if((*operator != 0)){           // Si ya se ha seleccionado un operador
                   
                    _delay_ms(10);              // Espera antirebote                    
                    
                    if(cont != 0){
        
                        for(i = 0; i < cont; i++){
                            aux = aux / 10;     // Se posiciona el punto decimal según los datos
                                                // ingresados
                        }
                    }
                    (*number) += aux;                     
                    return;                     // Regresa para realizar la operación
                                                
                }else{                          // De lo contrario, no hace nada
                    _delay_ms(10);
                    }
                    
            }else{                                          // Si se ingresa un número, se acumula

                    aux = (aux*10) + caracter - 48;
                    lcd_putc(caracter);                         // Se imprime el caracter en pantalla (echo).
                    _delay_ms(10);                              // Tiempo de espera para evitar rebotes.
                    cont++;                                     // Incrementa el contador para saber que se ha
                                                                // ingresado un nuevo decimal
                }
        }
    }

    if(cont != 0){
        
        for(i = 0; i < cont; i++){
        aux = aux / 10;                                 // Se posiciona el punto decimal según los datos
                                                        // ingresados
        }
    }else{
        aux = aux / 10;
    }

    (*number) += aux;

}