#ifndef MPOINTER_H
#define MPOINTER_H

#include <iostream>
#include "MPointerGC.h"

template <typename T>
class MPointer {
private:
    T* ptr;  // Puntero interno que almacena el valor de tipo T
    int id;  // Identificador único para el puntero
    int* refCount;  // Contador de referencias compartidas para gestionar memoria

public:
    // Constructor por defecto
    // Qué sucede: Se inicializa el puntero interno `ptr` con una nueva instancia del tipo T.
    // Por qué sucede: Se asigna memoria dinámica al puntero y se registra en el Garbage Collector.
    // Qué deberíamos esperar: El puntero `ptr` apunta a un nuevo objeto de tipo T, y `refCount` se inicializa en 1.
    MPointer() {
        ptr = new T();  // Asigna memoria dinámica para un nuevo objeto de tipo T.
        refCount = new int(1);  // Inicializa el contador de referencias a 1.
        id = MPointerGC::getInstance().registerPointer(this);  // Registra el puntero en el Garbage Collector.
    }

    // Constructor para nullptr
    // Qué sucede: Inicializa el puntero interno a `nullptr` y el contador de referencias a 0.
    // Por qué sucede: Permite crear un `MPointer` que no apunta a ninguna memoria válida.
    // Qué deberíamos esperar: `ptr` es nullptr, y el `refCount` se establece en 0.
    MPointer(std::nullptr_t) : ptr(nullptr), refCount(new int(0)), id(-1) {}

    // Constructor de copia
    // Qué sucede: Copia el puntero interno y el contador de referencias de otro `MPointer`.
    // Por qué sucede: Permite compartir la misma memoria entre múltiples `MPointer`, incrementando el contador de referencias.
    // Qué deberíamos esperar: Tanto el nuevo `MPointer` como el original apuntan al mismo objeto, y `refCount` se incrementa.
    MPointer(const MPointer<T>& other) {
        ptr = other.ptr;  // Copia el puntero interno.
        refCount = other.refCount;  // Copia el contador de referencias.
        (*refCount)++;  // Incrementa el contador de referencias.
        id = other.id;  // Copia el ID.
    }

    // Destructor
    // Qué sucede: Decrementa el contador de referencias y libera la memoria cuando ya no es necesaria.
    // Por qué sucede: Asegura que la memoria solo se libere cuando no hay más referencias al objeto.
    // Qué deberíamos esperar: Si este es el último `MPointer` que apunta al objeto, se libera la memoria y se elimina del Garbage Collector.
    ~MPointer() {
        (*refCount)--;  // Decrementa el contador de referencias.
        if (*refCount == 0) {  // Si no hay más referencias, libera la memoria.
            delete ptr;
            delete refCount;  // Libera el contador de referencias.
            MPointerGC::getInstance().deregisterPointer(this);  // Desregistra el puntero del Garbage Collector.
        }
    }

    // Sobrecarga del operador * (dereference)
    // Qué sucede: Permite acceder al valor al que apunta el puntero `ptr`.
    // Por qué sucede: Facilita el acceso al valor gestionado por el `MPointer` como si fuera un puntero regular.
    // Qué deberíamos esperar: El valor almacenado en `ptr` se devuelve.
    T& operator*() {
        return *ptr;  // Devuelve el valor apuntado por `ptr`.
    }

    // Sobrecarga del operador -> (acceso a miembros)
    // Qué sucede: Permite acceder a los miembros del objeto apuntado por `ptr`.
    // Por qué sucede: Facilita el acceso a los miembros del objeto gestionado por el `MPointer`.
    // Qué deberíamos esperar: Devuelve un puntero a `ptr` para acceder a sus miembros.
    T* operator->() {
        return ptr;  // Devuelve el puntero `ptr`.
    }

    // Sobrecarga del operador = (asignación con tipo T)
    // Qué sucede: Asigna un valor directo al objeto gestionado por `MPointer`.
    // Por qué sucede: Permite asignar un valor al objeto apuntado por `MPointer` como si fuera un puntero regular.
    // Qué deberíamos esperar: El valor proporcionado sobrescribe el valor almacenado en `ptr`.
    MPointer<T>& operator=(const T& value) {
        *ptr = value;  // Asigna el valor directamente a la memoria gestionada.
        return *this;  // Devuelve una referencia a sí mismo.
    }

    // Sobrecarga del operador = (asignación entre MPointers)
    // Qué sucede: Permite asignar un `MPointer` a otro, compartiendo la misma memoria.
    // Por qué sucede: Facilita la transferencia de la memoria gestionada entre `MPointer`, gestionando correctamente las referencias.
    // Qué deberíamos esperar: Ambos `MPointer` apuntan a la misma memoria y el contador de referencias se ajusta.
    MPointer<T>& operator=(const MPointer<T>& other) {
        if (this != &other) {  // Evita la autoasignación.
            (*refCount)--;  // Decrementa el contador de referencias del puntero actual.
            if (*refCount == 0) {  // Si no hay más referencias, libera la memoria.
                delete ptr;
                delete refCount;
                MPointerGC::getInstance().deregisterPointer(this);  // Desregistra el puntero.
            }
            ptr = other.ptr;  // Asigna el nuevo puntero.
            refCount = other.refCount;  // Copia el contador de referencias.
            (*refCount)++;  // Incrementa el contador de referencias del nuevo puntero.
            id = other.id;  // Copia el ID.
        }
        return *this;  // Devuelve una referencia a sí mismo.
    }

    // Sobrecarga del operador & (referencia)
    // Qué sucede: Permite obtener el puntero interno `ptr`.
    // Por qué sucede: Facilita el acceso directo a la memoria gestionada por el `MPointer`.
    // Qué deberíamos esperar: Devuelve el puntero `ptr`.
    T* operator&() {
        return ptr;  // Devuelve el puntero interno `ptr`.
    }

    // Sobrecarga del operador == para nullptr
    // Qué sucede: Compara si el puntero interno es igual a `nullptr`.
    // Por qué sucede: Facilita la comparación entre `MPointer` y `nullptr` para verificar si el puntero es nulo.
    // Qué deberíamos esperar: Devuelve `true` si `ptr` es `nullptr`, de lo contrario `false`.
    bool operator==(std::nullptr_t) const {
        return ptr == nullptr;
    }

    // Sobrecarga del operador != para nullptr
    // Qué sucede: Compara si el puntero interno no es igual a `nullptr`.
    // Por qué sucede: Facilita la comparación entre `MPointer` y `nullptr` para verificar si el puntero no es nulo.
    // Qué deberíamos esperar: Devuelve `true` si `ptr` no es `nullptr`, de lo contrario `false`.
    bool operator!=(std::nullptr_t) const {
        return ptr != nullptr;
    }

    // Sobrecarga del operador == para comparar el valor apuntado con un tipo primitivo
    // Qué sucede: Compara el valor apuntado por `ptr` con un valor primitivo.
    // Por qué sucede: Facilita la comparación directa entre el valor almacenado en `ptr` y un valor de tipo `T`.
    // Qué deberíamos esperar: Devuelve `true` si los valores son iguales.
    bool operator==(const T& value) const {
        return *ptr == value;
    }

    // Sobrecarga del operador != para comparar el valor apuntado con un tipo primitivo
    // Qué sucede: Compara el valor apuntado por `ptr` con un valor primitivo.
    // Por qué sucede: Facilita la comparación directa entre el valor almacenado en `ptr` y un valor de tipo `T`.
    // Qué deberíamos esperar: Devuelve `true` si los valores son diferentes.
    bool operator!=(const T& value) const {
        return *ptr != value;
    }

    // Sobrecarga del operador == para comparar dos MPointers
    // Qué sucede: Compara si dos `MPointer` apuntan al mismo objeto.
    // Por qué sucede: Facilita la comparación entre dos `MPointer` para verificar si apuntan a la misma dirección de memoria.
    // Qué deberíamos esperar: Devuelve `true` si ambos `MPointer` apuntan al mismo objeto.
    bool operator==(const MPointer<T>& other) const {
        return ptr == other.ptr;
    }

    // Sobrecarga del operador != para comparar dos MPointers
    // Qué sucede: Compara si dos `MPointer` no apuntan al mismo objeto.
    // Por qué sucede: Facilita la comparación entre dos `MPointer` para verificar si apuntan a direcciones de memoria diferentes.
    // Qué deberíamos esperar: Devuelve `true` si ambos `MPointer` apuntan a objetos diferentes.
    bool operator!=(const MPointer<T>& other) const {
        return ptr != other.ptr;
    }

    // Método estático para crear un nuevo MPointer
    // Qué sucede: Crea un nuevo objeto `MPointer` utilizando el constructor por defecto.
    // Por qué sucede: Facilita la creación de `MPointer` mediante un método estático.
    // Qué deberíamos esperar: Devuelve un nuevo `MPointer`.
    static MPointer<T> New() {
        return MPointer<T>();  // Crea un nuevo objeto `MPointer`.
    }

    // Método para obtener el ID del puntero gestionado
    // Qué sucede: Devuelve el identificador único asignado al puntero.
    // Por qué sucede: Facilita la obtención del ID del puntero para identificaciones únicas en el Garbage Collector.
    // Qué deberíamos esperar: Devuelve el ID asociado al puntero gestionado.
    int getId() const {
        return id;
    }
};

#endif
