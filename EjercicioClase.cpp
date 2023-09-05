/* Asignacion Dinamica de arreglos

new: reserva el numero de bytes solicitado por la declarcion.
delete: libera un bloque de bytes reservado con anterioridad.

ejemplo: pedir al usuario n calificaciones y almacenarlos en un arreglo dinamico
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void pedirnotas();//prototipo de 
void mostrarnotas();

int numCalificacion,*calificacion;

int main(){
	
	pedirnotas();
	mostrarnotas();
	
	delete[] calificacion;//liberando espacio utilizado en el arreglo dinamico
	
	getch();
	return 0;
}

void pedirnotas(){
	cout<<"Digite la cantidad de calificaciones: ";
	cin>>numCalificacion;
	
	calificacion= new int[numCalificacion];//crea arreglo reservando memeoria
	
	for(int i=0; i<numCalificacion;i++){
		cout<<"Ingrese una nota: ";
		cin>>calificacion[i];
	}
}

void mostrarnotas(){
    // Mostrar ubicacion de memoria sin el ampersand
	cout<<"\n\nMostrar notas del usuario: \n";

	for(int i=0; i<numCalificacion;i++){
		cout<<calificacion[i]<<endl;
        

		}
}
