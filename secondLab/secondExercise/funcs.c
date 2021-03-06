void numToLcd(float* number){  // Función para imprimir un número en la pantalla LCD

    char result[10];         // Arreglo que almacena el número descompuesto en unidades, decenas, centenas...
    
    dtostrf(*number, 3, 2, result); 
    lcd_puts(result);  
}

void accNumber(float* number, char* operator){      // Función para ingresar los números de la operación

    
    int cont = 0;                       // Contador de cantidad de dígitos ingresados
    char caracter = 0;                  // Variable que almacenará el caracter presionado   

    while (cont < 3){                   // Máximo se pueden ingresar 3 dígitos

        caracter = 0;                   // Resetea la variable caracter
        caracter = kbrd_read();         // Lectura del teclado matricial
            
        if(caracter != 0){              // Siempre y cuando se oprima un caracter

            if(caracter == '.'){        // Si se ingresa un punto, quiere decir que se va a ingresar la parte
                                        // decimal y debe terminar de ingresar la parte entera.
            
                lcd_putc(caracter);     // Imprime el punto decimal en pantalla
                _delay_ms(10);          // Tiempo de espera para evitar rebotes.
                
                accDecimal(number, operator);     // Llama a la fución que permite ingresar la parte decimal del
                                                  // número de la operación

               return;                  // Termina el ingreso de la parte entera

                }else if(caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/'){ // Si se interrumpe el ingreso del número con un operador
                    
                    if((*operator) == 0){
                        
                        lcd_putc(caracter);      // Imprime el operador en pantalla
                        (*operator) = caracter;  // Almacena el operador para determinar qué debe hacer
                        _delay_ms(10);           // Espera antirebote
                        return;
                    
                    }else{
                        _delay_ms(10);          // De lo contrario, no hace nada
                    }
  
                    
               
                } else if(caracter == '='){     // Si se ingresa el operador de resultado 
                    
                    if((*operator != 0)){       // Si ya había un operador válido previamente definido
                        _delay_ms(10);          // Espera antirebote
                        return;                 // Regresa para hacer la operación solicitada
                    }else{                      // Sino, no hace nada. Se necesita que haya un operador válido previamente definido para dar como resultado una operación
                        _delay_ms(10);          // Espera antirebote
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

    //caracter = 0;
    
    while(caracter != '+' || caracter != '-' || caracter != '*' || caracter != '/' || caracter != '.' || caracter != '='){ // Hasta que no se ingrese un operador válido o un punto decimal
        
        
        caracter = kbrd_read();     // Lee el teclado en espera de un operador válido o el punto decimal
        _delay_ms(10);              // 
        
        if( (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') ){ // Si se ingresa un operador válido y no se había seleccionado antes
            
            if ((*operator) == 0){
                (*operator) = caracter; // Se almacena el operador
                lcd_putc(caracter);
                _delay_ms(10);          // Tiempo antirebote
            
                return;                 // Termina el ingreso del número
            }else{
                _delay_ms(10);          // De lo contrario, solo espera
            }
        }else if(caracter == '.'){      // Si se ingresa el punto decimal
                
                lcd_putc(caracter);     // Imprime el punto decimal en pantalla
                _delay_ms(10);          // Tiempo de espera para evitar rebotes.                
                accDecimal(number, operator);     // Llama a la función que permite ingresar la parte decimal del
                                                  // número de la operación
                return;                  // Termina el ingreso del número

        }else if((caracter == '=') && ((*operator) != 0)){ // Si solo se desean ingresar dos operandos de 3 cifras sin decimales

            return;

        }
    }
    
}

void accDecimal(float* number, char* operator){         // Función para ingresar los decimales de los números de la operación

    int i;
    int cont = 0;                       // Variable para llevar la cuenta de los decimales ingresador
    float aux = 0;                      // Variable auxiliar para ordenar los decimales 
    char caracter = 0;              // Variable que almacenará el caracter presionado

    while (cont < 2){                   // Máximo se pueden ingresar 2 decimales

        caracter = 0;                   // Resetea la variable que almacena el caracter presionado
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