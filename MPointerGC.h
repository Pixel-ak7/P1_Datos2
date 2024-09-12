#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <list>
#include <iostream>  // Asegura que se incluye para usar std::cout y std::endl

class MPointerGC {
private:
    static MPointerGC instance;  // Singleton para gestionar los MPointers
    std::list<void*> pointerList;  // Lista de punteros registrados

    // Constructor privado para implementar el patrón singleton
    MPointerGC() {}

public:
    // Método estático para obtener la instancia única
    static MPointerGC& getInstance();

    // Registrar un nuevo MPointer
    int registerPointer(void* ptr);

    // Eliminar un MPointer cuando ya no es necesario
    void deregisterPointer(void* ptr);

    // Método para ejecutar el Garbage Collector (GC) si es necesario
    void runGC();
};

#endif
