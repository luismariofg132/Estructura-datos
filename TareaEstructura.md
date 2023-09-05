#include <iostream>

using namespace std;

void ejercicio1();
void ejercicio2();

int main(){
    ejercicio2();
    
    return 0;
}

void ejercicio1(){
     // Comprobar si un numero es par o impar e indicar su posicion de memoria con punteros
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;

    int *dir_num = &num;

    if(*dir_num % 2 == 0){
        cout << "El numero " << *dir_num << " es par" << endl;
        cout << "La posicion de memoria es: " << dir_num << endl;
    }else{
        cout << "El numero " << *dir_num << " es impar" << endl;
        cout << "La posicion de memoria es: " << dir_num << endl;
    }
}

void ejercicio2(){
    // Determinar si un numero es primo o no con punteros e indicar su posicicon de memoria

    int num;
    cout << "Ingrese un numero: ";
    cin >> num;
    int *dir_num = &num;

    int cont = 0;
    for(int i = 1; i <= *dir_num; i++){
        if(*dir_num % i == 0){
            cont++;
        }
    }

    if(cont == 2){
        cout << "El numero " << *dir_num << " es primo" << endl;
        cout << "La posicion de memoria es: " << dir_num << endl;
    }else{
        cout << "El numero " << *dir_num << " no es primo" << endl;
        cout << "La posicion de memoria es: " << dir_num << endl;
    }

}
