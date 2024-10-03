#include <iostream>
#include "ListaDoble.h"

using namespace std;

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
