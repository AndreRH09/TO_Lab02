#include <iostream>

using namespace std;

struct Nodo
{
    int valor;
    Nodo *siguiente;
    Nodo *anterior;

    ~Nodo()
    {
        cout << "\nNodo eliminado: " << valor;
    }
};

void copiaArreglo(int arreglo[], int size, Nodo **inicio);
void imprimeLista(Nodo *inicio);
void imprimeListaReversa(Nodo *fin);
void destruyeLista(Nodo *inicio);

int main()
{
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int tama = sizeof(arreglo) / sizeof(*arreglo);

    Nodo *inicio = nullptr;               // Puntero al inicio de la lista
    copiaArreglo(arreglo, tama, &inicio); // Copia el arreglo a la lista

    imprimeLista(inicio); // Imprimir lista en orden

    // Encuentra el nodo final para la impresión inversa
    Nodo *fin = inicio;
    while (fin->siguiente != nullptr)
    {
        fin = fin->siguiente;
    }

    imprimeListaReversa(fin); // Imprimir lista en orden inverso
    destruyeLista(inicio);    // Destruir la lista

    return 0;
}

// Función que copia el arreglo en una lista doblemente enlazada
void copiaArreglo(int arreglo[], int size, Nodo **inicio)
{
    Nodo *iNodo;
    int i = 0;

    *inicio = new Nodo;            // Crear el primer nodo
    (*inicio)->valor = arreglo[i]; // Inicializar el primer nodo
    (*inicio)->siguiente = nullptr;
    (*inicio)->anterior = nullptr;
    i++;

    iNodo = *inicio;
    while (i < size)
    {
        // Crear un nuevo nodo y enlazarlo con el anterior
        iNodo->siguiente = new Nodo;
        iNodo->siguiente->anterior = iNodo;
        iNodo = iNodo->siguiente;
        iNodo->valor = arreglo[i];
        iNodo->siguiente = nullptr;
        i++;
    }
}

// Función que imprime la lista en orden
void imprimeLista(Nodo *inicio)
{
    Nodo *iNodo = inicio;
    cout << "\nLista en orden: ";
    while (iNodo != nullptr)
    {
        cout << iNodo->valor << " ";
        iNodo = iNodo->siguiente;
    }
    cout << endl;
}

// Función que imprime la lista en orden inverso
void imprimeListaReversa(Nodo *fin)
{
    Nodo *iNodo = fin;
    cout << "\nLista en orden inverso: ";
    while (iNodo != nullptr)
    {
        cout << iNodo->valor << " ";
        iNodo = iNodo->anterior;
    }
    cout << endl;
}

// Función que destruye la lista liberando memoria
void destruyeLista(Nodo *inicio)
{
    Nodo *iNodo = inicio;
    while (iNodo != nullptr)
    {
        Nodo *auxNodo = iNodo->siguiente; // Guardar referencia del siguiente nodo
        delete iNodo;                     // Liberar memoria del nodo actual
        iNodo = auxNodo;                  // Pasar al siguiente nodo
    }
}
