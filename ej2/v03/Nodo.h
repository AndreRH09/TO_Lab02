#ifndef NODO_H
#define NODO_H

class Nodo
{
public:
    int dato;
    Nodo *siguiente;
    Nodo *anterior;

    Nodo(int valor);
};

#endif // NODO_H
