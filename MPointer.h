#ifndef MPOINTER_H
#define MPOINTER_H

#include <iostream>
#include "MPointerGC.h"

// Definición de una clase template MPointer que gestiona dinámicamente la memoria de un puntero de tipo T.
template <typename T>
class MPointer {
private:
    T* ptr;  // Puntero interno que almacena el valor de tipo T.
    int id;  // Identificador único para el puntero, gestionado por el Garbage Collector (MPointerGC).
    int* refCount;  // Contador de referencias compartidas, para gestionar cuántos MPointer apuntan al mismo bloque de memoria.

public:
    // Constructor por defecto
    // Inicializa el puntero, asigna memoria para el tipo T y registra el puntero en el Garbage Collector.
    MPointer() {
        ptr = new T();  // Asigna memoria para un nuevo objeto de tipo T.
        refCount = new int(1);  // Inicializa el contador de referencias con 1 (el propio MPointer está referenciando el valor).
        id = MPointerGC::getInstance().registerPointer(this);  // Registra el puntero en el Garbage Collector y obtiene un ID único.
    }

    // Constructor de copia
    // Permite copiar un MPointer, lo que hace que ambos apunten al mismo bloque de memoria y compartan el contador de referencias.
    MPointer(const MPointer<T>& other) {
        ptr = other.ptr;  // Copia el puntero interno.
        refCount = other.refCount;  // Copia el contador de referencias.
        (*refCount)++;  // Incrementa el contador de referencias, ya que ahora hay otro MPointer apuntando al mismo valor.
        id = other.id;  // Copia el ID, ya que ambos punteros gestionan la misma memoria.
    }

    // Destructor
    // Se encarga de liberar la memoria cuando el último MPointer que apunta al valor es destruido.
    ~MPointer() {
        (*refCount)--;  // Decrementa el contador de referencias.
        if (*refCount == 0) {  // Si no hay más referencias al puntero, se libera la memoria.
            delete ptr;  // Libera la memoria apuntada por el puntero.
            delete refCount;  // Libera la memoria asignada al contador de referencias.
            MPointerGC::getInstance().deregisterPointer(this);  // Desregistra el puntero del Garbage Collector.
        }
    }

    // Sobrecarga del operador * (dereference)
    // Permite acceder al valor almacenado en la memoria gestionada por MPointer.
    T& operator*() {
        return *ptr;  // Devuelve el valor apuntado por el puntero.
    }

    // Sobrecarga del operador = (asignación con tipo T)
    // Permite asignar un valor de tipo T al MPointer, sobreescribiendo el valor en la memoria gestionada.
    MPointer<T>& operator=(const T& value) {
        *ptr = value;  // Asigna el valor directamente a la memoria gestionada.
        return *this;  // Devuelve una referencia a sí mismo.
    }

    // Sobrecarga del operador = (asignación entre MPointers)
    // Permite asignar un MPointer a otro. Ambos MPointer compartirán la misma memoria y contador de referencias.
    MPointer<T>& operator=(const MPointer<T>& other) {
        if (this != &other) {  // Verifica que no se está asignando a sí mismo.
            (*refCount)--;  // Decrementa el contador de referencias del puntero actual.
            if (*refCount == 0) {  // Si no hay más referencias, libera la memoria.
                delete ptr;
                delete refCount;
                MPointerGC::getInstance().deregisterPointer(this);  // Desregistra el puntero.
            }

            // Asigna el nuevo puntero y comparte el contador de referencias con el otro MPointer.
            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;  // Incrementa el contador de referencias del nuevo puntero.
            id = other.id;  // Copia el ID.
        }
        return *this;  // Devuelve una referencia a sí mismo.
    }

    // Sobrecarga del operador & (referencia)
    // Permite obtener el puntero a la memoria gestionada. Útil si se necesita acceder directamente al puntero.
    T* operator&() {
        return ptr;  // Devuelve la dirección de memoria gestionada.
    }

    // Sobrecarga del operador == para comparar el valor apuntado por MPointer con otro valor
    // Esto permite comparaciones directas entre un MPointer y un valor de tipo T.
    bool operator==(const T& other) const {
        return *ptr == other;  // Compara el valor apuntado por el puntero con el valor proporcionado.
    }

    // Método estático para crear un nuevo MPointer
    // Inicializa un nuevo objeto MPointer utilizando el constructor por defecto.
    static MPointer<T> New() {
        return MPointer<T>();  // Devuelve una nueva instancia de MPointer.
    }

    // Método para obtener el ID del puntero gestionado
    // El ID es útil para identificar los punteros en el contexto del Garbage Collector.
    int getId() const {
        return id;  // Devuelve el ID asociado con este MPointer.
    }
};

#endif
