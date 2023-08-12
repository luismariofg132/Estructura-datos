#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    int numero, randomNumber, numeroIntentos = 3;
    bool esCorrecto = false;
    
    srand(time(NULL));
    randomNumber = rand()%100;
    
    for(int i = 1; i <= numeroIntentos; i++){ 
        
        cout << "Intento numero: " << i << endl;
        cout << "Ingrese un numero: " << endl;
        cin >> numero;
        
        if(numero == randomNumber){
            cout << "Ese era el numero" << endl;
            esCorrecto = true;
            break;
        }
        
        cout << "No es el numero" << endl;
        
        if (i != numeroIntentos){
            if(numero < randomNumber){
                cout << "El numero es mayor, al que ingresaste" << endl;
            } else {
                cout << "El numero es menor, al que ingresaste" << endl;
            }
        }
    }
    
    if (!esCorrecto){
        cout << "El numero correcto era el: " << randomNumber << endl;
    }
    
    return 0;
}
