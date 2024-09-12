#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"

template <typename T>
class ListaDoble {
private:
    MPointer<Nodo<T>> head;  // Puntero al primer nodo de la lista
    MPointer<Nodo<T>> tail;  // Puntero al último nodo de la lista

public:
    // Constructor por defecto
    // Qué sucede: Inicializa los punteros `head` y `tail` a nullptr.
    // Por qué sucede: La lista se crea vacía, por lo que no hay nodos.
    // Qué deberíamos esperar: Tanto `head` como `tail` estarán en nullptr.
    ListaDoble() : head(nullptr), tail(nullptr) {}

    // Método para agregar un nuevo nodo al final de la lista
    // Qué sucede: Crea un nuevo nodo con el valor proporcionado y lo añade al final de la lista.
    // Por qué sucede: Permite añadir elementos a una lista doblemente enlazada.
    // Qué deberíamos esperar: El nuevo nodo se convierte en el nuevo `tail` de la lista.
    void agregar(T valor) {
        MPointer<Nodo<T>> nuevoNodo = MPointer<Nodo<T>>::New();  // Crea un nuevo nodo.
        nuevoNodo->data = valor;  // Asigna el valor al nuevo nodo.

        if (head == nullptr) {  // Si la lista está vacía.
            head = nuevoNodo;  // El nuevo nodo es el primero.
            tail = nuevoNodo;  // El nuevo nodo también es el último.
        } else {
            tail->siguiente = nuevoNodo;  // El último nodo apunta al nuevo nodo.
            nuevoNodo->anterior = tail;  // El nuevo nodo apunta hacia atrás al antiguo último nodo.
            tail = nuevoNodo;  // El nuevo nodo se convierte en el último de la lista.
        }
    }

    // Método para imprimir la lista
    // Qué sucede: Recorre la lista desde `head` hasta `tail`, imprimiendo los valores de cada nodo.
    // Por qué sucede: Permite ver los valores almacenados en la lista.
    // Qué deberíamos esperar: Se imprimen los valores de todos los nodos en orden.
    void imprimir() {
        MPointer<Nodo<T>> actual = head;  // Comienza desde el primer nodo.
        while (actual != nullptr) {  // Mientras no se llegue al final de la lista.
            std::cout << actual->data << " ";  // Imprime el valor del nodo actual.
            actual = actual->siguiente;  // Pasa al siguiente nodo.
        }
        std::cout << std::endl;
    }

    // Método para obtener el primer nodo (head)
    // Qué sucede: Devuelve el puntero al primer nodo de la lista.
    // Por qué sucede: Permite acceder al inicio de la lista.
    // Qué deberíamos esperar: Devuelve `head`.
    MPointer<Nodo<T>> obtenerHead() {
        return head;
    }

    // Método para obtener el último nodo (tail)
    // Qué sucede: Devuelve el puntero al último nodo de la lista.
    // Por qué sucede: Permite acceder al final de la lista.
    // Qué deberíamos esperar: Devuelve `tail`.
    MPointer<Nodo<T>> obtenerTail() {
        return tail;
    }
};

#endif
