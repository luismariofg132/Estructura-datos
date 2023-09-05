#include <iostream>
using namespace std;

class Stack
{
private:
    // Atributos de la pila
    static const int MAXSIZE = 10; // Tamaño máximo de la pila
    int top;                       // Índice del elemento en la parte superior de la pila
    int items[MAXSIZE];            // Arreglo que almacena los elementos de la pila

public:
    // Métodos de la pila
    Stack()
    {
        top = -1;
    };

    int empty() // Metodo para verificar si la pila esta vacia
    {
        return (top == -1);
    }

    int full() // Metodo para verificar si la pila esta llena
    {
        return (top == MAXSIZE - 1);
    }

    void push(int v) // Metodo para insertar un elemento en la pila
    {
        if (!full())
        {
            items[++top] = v;
        }
        else
        {
            cout << "No es posible crear el elemento" << endl;
        }
    }

    // Metodo para extraer un elemento de la pila
    int pop()
    {
        if (!empty())
        {
            return (items[top--]);
        }
        else
        {
            cout << "No es posible extraer un elemento " << endl;
            return (0);
        }
    }

    // Metodo para buscar un elemento en la pila
    int search(int element)
    {
        for (int i = 0; i <= top; i++)
        {
            if (items[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    // Metodo para buscar y eliminar un elemento de la pila
    int findAndRemove(int element)
    {
        for (int i = top; i >= 0; i--)
        {
            if (items[i] == element)
            {
                // Elemento encontrado, eliminarlo
                for (int j = i; j < top; j++)
                {
                    items[j] = items[j + 1];
                }
                top--;
                return 1; // Salir del bucle una vez que se encuentre y elimine el elemento
            }
        }
        return 1;
    }

    // Metodo para imprimir la pila
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << items[i] << endl;
        }
    }
};

void process(Stack &myStack, int choice);

int main()
{
    Stack myStack;
    int choice, size;
    cout << "Ingrese el numero de elementos que desea ingresar" << endl;
    cin >> size;

    if (size > 10)
    {
        cout << "El tamaño ingresado se sale de los limites de la pila" << endl;
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        int element;
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> element;
        myStack.push(element);
    }

    do
    {
        cout << "¿Qué desea hacer?" << endl;
        cout << "1. Insertar un elemento" << endl;
        cout << "2. Buscar un elemento" << endl;
        cout << "3. Eliminar un elemento" << endl;
        cout << "4. Imprimir la pila" << endl;
        cout << "5. Eliminar el ultimo elemento" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese su elección: ";
        cin >> choice;

        process(myStack, choice);

    } while (choice != 6);

    return 0;
}

void process(Stack &myStack, int choice)
{
    switch (choice)
    {
    case 1:
    {
        int element;
        cout << "Ingrese el elemento a insertar: ";
        cin >> element;
        myStack.push(element);
    }
        return;

    case 2:
    {
        int searchElement;
        cout << "Ingrese el elemento a buscar: ";
        cin >> searchElement;
        int index = myStack.search(searchElement);
        if (index != -1)
        {
            cout << "El elemento " << searchElement << " se encuentra en la posición " << index << " de la pila." << endl;
        }
        else
        {
            cout << "El elemento no se encontró en la pila." << endl;
        }
    }

        return;

    case 3:
    {
        int removeElement;
        cout << "Ingrese el elemento a eliminar: ";
        cin >> removeElement;
        if (myStack.findAndRemove(removeElement))
        {
            cout << "El elemento " << removeElement << " se eliminó de la pila." << endl;
        }
        else
        {
            cout << "El elemento no se encontró en la pila." << endl;
        }
    }
        return;

    case 4:
    {
        cout << "Elementos en la pila:" << endl;
        myStack.display();
    }
        return;
    case 5:
    {
        cout << "Eliminando el ultimo elemento de la pila." << endl;
        myStack.pop();
    }
        return;
    case 6:
    {
        cout << "Saliendo del programa." << endl;
    }
        return;
    default:
        cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        return;
    }
}
