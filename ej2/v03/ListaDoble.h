#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"

class ListaDoble
{
private:
    Nodo *cabeza;

public:
    ListaDoble();
    void agregar(int valor);
    void mostrar();
    ~ListaDoble();
};

#endif // LISTADOBLE_H
