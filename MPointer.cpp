#include "MPointer.h"
#include "MPointerGC.h"
#include <iostream>

// Constructor por defecto
// Este constructor inicializa el puntero interno `ptr` con una nueva instancia de tipo T.
// Además, registra este puntero en el Garbage Collector (MPointerGC) y almacena un ID
// único que se asigna al puntero gestionado.
template <typename T>
MPointer<T>::MPointer() {
    ptr = new T();  // Asigna memoria para un nuevo objeto de tipo T.
    id = MPointerGC::getInstance().registerPointer(this);  // Registra el puntero en el GC y obtiene un ID.
}

// Destructor
// Este destructor se llama cuando un objeto `MPointer` sale del ámbito o se destruye explícitamente.
// Se encarga de liberar la memoria del puntero `ptr` y desregistrar el puntero del Garbage Collector.
template <typename T>
MPointer<T>::~MPointer() {
    delete ptr;  // Libera la memoria apuntada por `ptr`.
    MPointerGC::getInstance().deregisterPointer(this);  // Elimina el puntero del Garbage Collector.
}

// Sobrecarga del operador * (dereference)
// Permite acceder al valor almacenado en la memoria gestionada por el puntero `ptr`.
// Devuelve una referencia al valor almacenado, lo que permite tanto leer como escribir en ese valor.
template <typename T>
T& MPointer<T>::operator*() {
    return *ptr;  // Devuelve el valor apuntado por `ptr`.
}

// Sobrecarga del operador = (asignación con tipo T)
// Permite asignar directamente un valor de tipo T al puntero gestionado por `MPointer`.
// El valor proporcionado sobreescribe el valor almacenado en la memoria gestionada.
template <typename T>
MPointer<T>& MPointer<T>::operator=(const T& value) {
    *ptr = value;  // Asigna el valor al puntero.
    return *this;  // Devuelve la referencia a sí mismo para encadenar llamadas.
}

// Sobrecarga del operador = (asignación entre MPointers)
// Este operador permite asignar un `MPointer` a otro. Ambos punteros compartirán la misma
// dirección de memoria después de la asignación, y el puntero original se desregistrará del Garbage Collector.

template <typename T>
MPointer<T>& MPointer<T>::operator=(const MPointer<T>& other) {
    if (this != &other) {  // Verifica que no se está asignando a sí mismo.
        // Desregistrar el puntero actual del Garbage Collector.
        MPointerGC::getInstance().deregisterPointer(this);

        // Asignar el puntero y el ID del otro MPointer.
        ptr = other.ptr;
        id = other.id;

        // Registrar el nuevo puntero en el Garbage Collector.
        MPointerGC::getInstance().registerPointer(this);
    }
    return *this;  // Devuelve la referencia a sí mismo.
}

// Sobrecarga del operador & (referencia)
// Devuelve el puntero interno `ptr` para que se pueda acceder directamente a la memoria gestionada.

template <typename T>
T* MPointer<T>::operator&() {
    return ptr;  // Devuelve la dirección de memoria gestionada por el puntero.
}

// Método estático para crear un nuevo MPointer
// Este método estático devuelve un nuevo `MPointer` utilizando el constructor por defecto.
template <typename T>
MPointer<T> MPointer<T>::New() {
    return MPointer<T>();  // Crea un nuevo objeto `MPointer`.
}

// Método para obtener el ID del puntero gestionado
// Este método devuelve el ID único asignado a cada puntero por el Garbage Collector.
// El ID es útil para identificar y gestionar punteros en el sistema de Garbage Collection.
template <typename T>
int MPointer<T>::getId() const {
    return id;  // Devuelve el ID del puntero gestionado.
}
