#ifndef NODO_H
#define NODO_H

#include "MPointer.h"

template <typename T>
class Nodo {
public:
    T data;                      // Valor almacenado en el nodo
    MPointer<Nodo<T>> siguiente;  // Puntero al siguiente nodo
    MPointer<Nodo<T>> anterior;   // Puntero al nodo anterior

    // Constructor por defecto
    Nodo() : data(T()), siguiente(nullptr), anterior(nullptr) {}

    // Constructor que inicializa el valor del nodo
    Nodo(T valor) : data(valor), siguiente(nullptr), anterior(nullptr) {}
};

#endif
