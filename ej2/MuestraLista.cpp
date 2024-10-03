#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
    Nodo *anterior;
    Nodo(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

class ListaDoble
{
private:
    Nodo *cabeza;

public:
    ListaDoble() : cabeza(nullptr) {}
    void agregar(int valor)
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
    void mostrar()
    {
        Nodo *temp = cabeza;
        while (temp)
        {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
    ~ListaDoble()
    {
        Nodo *temp = cabeza;
        while (temp)
        {
            Nodo *siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
    }
};

int main()
{
    ListaDoble lista;
    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);
    lista.agregar(40);
    lista.agregar(50);
    cout << "Elementos de la lista doblemente enlazada: ";
    lista.mostrar();
    return 0;
}
