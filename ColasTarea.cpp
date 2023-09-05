#include <iostream>

using namespace std;

class StaticQueue
{
private:
    static const int maxSize = 10; // Tamaño máximo de la cola
    int data[maxSize];             // Arreglo para almacenar los elementos de la cola
    int frontIndex;                // Índice del elemento en la parte frontal de la cola
    int rearIndex;                 // Índice del elemento en la parte trasera de la cola

public:
    StaticQueue()
    {
        frontIndex = -1;
        rearIndex = -1;
    }

    bool isEmpty()
    {
        return (frontIndex == -1);
    }

    bool isFull()
    {
        return ((rearIndex + 1) % maxSize == frontIndex);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "La cola está llena. No se puede insertar más elementos." << endl;
            return;
        }
        if (isEmpty())
        {
            frontIndex = 0; // Inicializar el índice frontal si la cola estaba vacía
        }
        rearIndex = (rearIndex + 1) % maxSize;
        data[rearIndex] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "La cola está vacía. No se puede eliminar ningún elemento." << endl;
            return -1; // Valor de retorno predeterminado para indicar un error
        }
        int dequeuedValue = data[frontIndex];
        if (frontIndex == rearIndex)
        {
            // Si solo hay un elemento en la cola, reiniciar los índices
            frontIndex = -1;
            rearIndex = -1;
        }
        else
        {
            frontIndex = (frontIndex + 1) % maxSize;
        }
        return dequeuedValue;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "La cola está vacía." << endl;
            return;
        }
        cout << "Elementos en la cola:" << endl;
        int current = frontIndex;
        while (current != rearIndex)
        {
            cout << data[current] << " ";
            current = (current + 1) % maxSize;
        }
        cout << data[current] << endl;
    }
};

int main()
{
    StaticQueue myQueue;

    int choice;
    do
    {
        cout << "¿Qué desea hacer?" << endl;
        cout << "1. Insertar un elemento" << endl;
        cout << "2. Eliminar un elemento" << endl;
        cout << "3. Imprimir la cola" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int element;
            cout << "Ingrese el elemento a insertar: ";
            cin >> element;
            myQueue.enqueue(element);
            break;

        case 2:
            int removedElement;
            removedElement = myQueue.dequeue();
            if (removedElement != -1)
            {
                cout << "Se eliminó el elemento " << removedElement << " de la cola." << endl;
            }
            break;

        case 3:
            myQueue.display();
            break;

        case 4:
            cout << "Saliendo del programa." << endl;
            break;

        default:
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
