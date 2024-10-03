#include <iostream>
#include "ListaDoble.h"

using namespace std;

ListaDoble::ListaDoble() : cabeza(nullptr) {}

void ListaDoble::agregar(int valor)
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

void ListaDoble::mostrar()
{
    Nodo *temp = cabeza;
    while (temp)
    {
        cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    cout << endl;
}

ListaDoble::~ListaDoble()
{
    Nodo *temp = cabeza;
    while (temp)
    {
        Nodo *siguiente = temp->siguiente;
        delete temp;
        temp = siguiente;
    }
}
