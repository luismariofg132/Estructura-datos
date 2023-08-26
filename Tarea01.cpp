#include <iostream>

using namespace std;

void encontrarMayorMenor(int arreglo[], int n, int &mayor, int &menor);
void cambiarNumero(int arreglo[], int posicion, int nuevoNumero);
void imprimirArreglo(int arreglo[], int n);

int main()
{
    /*
    crear un programa mediante el uso de arreglos, que solicite por pantalla el tamaño del arreglo,
    los elementos del arreglo, hacer que encuentre el número más grande, luego que permita al usuario
    cambiar un número específico y que finalmente encuentre el nuevo número más pequeño en el arreglo modificado.
    */

    int n;
    int mayor, menor;

    cout << "Ingrese el tamano del arrego" << endl;
    cin >> n;

    int arreglo[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << " :" << endl;
        cin >> arreglo[i];
    }

    encontrarMayorMenor(arreglo, n, mayor, menor);

    cout << "El numero mayor es: " << mayor << endl;
    cout << "El numero menor es: " << menor << endl;

    int posicion, nuevoNumero;

    imprimirArreglo(arreglo, n);
    cout << "Ingrese la posicion del numero que desea cambiar" << endl;
    cin >> posicion;

    cout << "Ingrese el nuevo numero" << endl;
    cin >> nuevoNumero;

    cambiarNumero(arreglo, posicion, nuevoNumero);

    imprimirArreglo(arreglo, n);

    encontrarMayorMenor(arreglo, n, mayor, menor);

    cout << "El numero mayor es: " << mayor << endl;
    cout << "El numero menor es: " << menor << endl;

    return 0;
}

void imprimirArreglo(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Posicion " << i << " :" << arreglo[i] << endl;
    }
}

void cambiarNumero(int arreglo[], int posicion, int nuevoNumero)
{
    arreglo[posicion] = nuevoNumero;
}

void encontrarMayorMenor(int arreglo[], int n, int &mayor, int &menor)
{
    mayor = arreglo[0];
    menor = arreglo[0];

    for (int i = 0; i < n; i++)
    {
        if (arreglo[i] > mayor)
        {
            mayor = arreglo[i];
        }
        if (arreglo[i] < menor)
        {
            menor = arreglo[i];
        }
    }
}