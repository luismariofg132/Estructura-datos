#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n;

    cout << "Ingrese el tamano de la matriz" << endl;
    cin >> n;

    int matrizA[n][n];
    int matrizB[n][n];

    // Llenar las matrices con numeros aleatorios
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            matrizA[i][j] = rand() % 10;
            matrizB[i][j] = rand() % 10;
        }
    }

    // Imprimir las matrices
    cout << "Matriz A" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "| ";
        for (int j = 0; j < n; ++j)
        {
            cout << matrizA[i][j] << " ";
        }
        cout << "|" << endl;
    }

    cout << "Matriz B" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "| ";
        for (int j = 0; j < n; ++j)
        {
            cout << matrizB[i][j] << " ";
        }
        cout << "|" << endl;
    }

    // Sumar las matrices
    int matrizC[n][n];
    cout << "Suma de matrices: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "| ";
        for (int j = 0; j < n; ++j)
        {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
            cout << matrizC[i][j] << " ";
        }
        cout << "|" << endl;
    }

    // Multiplicar las matrices
    int matrizD[n][n];
    cout << "Multiplicacion de matrices: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "| ";
        for (int j = 0; j < n; ++j)
        {
            matrizD[i][j] = 0;
            for (int k = 0; k < n; ++k)
            {
                matrizD[i][j] += matrizA[i][k] * matrizB[k][j];
            }
            cout << matrizD[i][j] << " ";
        }
        cout << "|" << endl;
    }

    return 0;
}