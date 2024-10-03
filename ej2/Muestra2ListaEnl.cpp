#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
    Nodo *anterior;
    Nodo(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

void agregar(Nodo *&cabeza, int valor)
{
    Nodo *nuevoNodo = new Nodo(valor);
    if (!cabeza)
    {
        cabeza = nuevoNodo;
    }
    else
    {
        Nodo *temp = cabeza;
        while (temp->siguiente)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->anterior = temp;
    }
}

void mostrar(Nodo *cabeza)
{
    Nodo *temp = cabeza;
    while (temp)
    {
        cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    cout << endl;
}

void eliminar(Nodo *&cabeza)
{
    Nodo *temp = cabeza;
    while (temp)
    {
        Nodo *siguiente = temp->siguiente;
        delete temp;
        temp = siguiente;
    }
}

int main()
{
    Nodo *cabeza = nullptr;
    agregar(cabeza, 10);
    agregar(cabeza, 20);
    agregar(cabeza, 30);
    agregar(cabeza, 40);
    agregar(cabeza, 50);

    cout << "Elementos de la lista doblemente enlazada: ";
    mostrar(cabeza);

    eliminar(cabeza); // Liberar memoria
    return 0;
}
