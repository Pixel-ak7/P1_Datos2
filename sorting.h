#ifndef SORTING_H
#define SORTING_H

#include "Nodo.h"

// Implementación de QuickSort para lista doblemente enlazada
// Qué sucede: Divide la lista en dos sublistas en torno a un pivote y las ordena recursivamente.
// Por qué sucede: Utiliza el algoritmo QuickSort para ordenar la lista de manera eficiente.
// Qué deberíamos esperar: La lista se ordena en su totalidad.
template <typename T>
MPointer<Nodo<T>> particion(MPointer<Nodo<T>> low, MPointer<Nodo<T>> high) {
    T pivote = high->data;  // Selecciona el último elemento como pivote.
    MPointer<Nodo<T>> i = low->anterior;  // `i` es el índice de elementos más pequeños que el pivote.

    for (MPointer<Nodo<T>> j = low; j != high; j = j->siguiente) {
        if (j->data <= pivote) {  // Si el elemento es menor o igual al pivote.
            i = (i == nullptr) ? low : i->siguiente;  // Mueve `i` un paso adelante.
            std::swap(i->data, j->data);  // Intercambia los valores de `i` y `j`.
        }
    }
    i = (i == nullptr) ? low : i->siguiente;  // Mueve `i` un paso más.
    std::swap(i->data, high->data);  // Coloca el pivote en su lugar.
    return i;  // Devuelve la posición del pivote.
}

template <typename T>
void quickSort(MPointer<Nodo<T>> low, MPointer<Nodo<T>> high) {
    if (high != nullptr && low != high && low != high->siguiente) {
        MPointer<Nodo<T>> p = particion(low, high);  // Encuentra el pivote.
        quickSort(low, p->anterior);  // Ordena la sublista izquierda.
        quickSort(p->siguiente, high);  // Ordena la sublista derecha.
    }
}

// Implementación de BubbleSort para lista doblemente enlazada
// Qué sucede: Recorre la lista repetidamente y mueve los elementos más grandes hacia el final.
// Por qué sucede: Utiliza el algoritmo BubbleSort para ordenar la lista.
// Qué deberíamos esperar: La lista se ordena completamente.
template <typename T>
void bubbleSort(MPointer<Nodo<T>> head) {
    bool swapped;  // Indica si hubo intercambios.
    MPointer<Nodo<T>> actual;

    do {
        swapped = false;
        actual = head;

        while (actual->siguiente != nullptr) {  // Recorre la lista.
            if (actual->data > actual->siguiente->data) {  // Si los nodos están en desorden.
                std::swap(actual->data, actual->siguiente->data);  // Intercambia los datos.
                swapped = true;  // Marca que hubo un intercambio.
            }
            actual = actual->siguiente;  // Avanza al siguiente nodo.
        }
    } while (swapped);  // Repite mientras haya intercambios.
}

// Implementación de InsertionSort para lista doblemente enlazada
// Qué sucede: Inserta cada elemento en su posición correcta dentro de la lista ya ordenada.
// Por qué sucede: Utiliza el algoritmo InsertionSort para ordenar la lista.
// Qué deberíamos esperar: La lista se ordena completamente.
template <typename T>
void insertionSort(MPointer<Nodo<T>> head) {
    MPointer<Nodo<T>> actual = head->siguiente;  // Comienza desde el segundo nodo.

    while (actual != nullptr) {
        T key = actual->data;  // Almacena el valor del nodo actual.
        MPointer<Nodo<T>> j = actual->anterior;  // Comienza desde el nodo anterior.

        while (j != nullptr && j->data > key) {  // Mueve los elementos mayores hacia adelante.
            j->siguiente->data = j->data;  // Mueve el valor hacia adelante.
            j = j->anterior;  // Retrocede un nodo.
        }

        if (j == nullptr) {  // Si se alcanzó el inicio de la lista.
            head->data = key;  // Coloca el valor en el primer nodo.
        } else {
            j->siguiente->data = key;  // Coloca el valor en su lugar correcto.
        }

        actual = actual->siguiente;  // Avanza al siguiente nodo.
    }
}

#endif
