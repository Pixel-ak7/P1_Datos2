#include "MPointerGC.h"

// Instancia única de MPointerGC
MPointerGC MPointerGC::instance;

// Método para obtener la instancia del singleton
MPointerGC& MPointerGC::getInstance() {
    return instance;
}

// Método para registrar un nuevo MPointer
int MPointerGC::registerPointer(void* ptr) {
    pointerList.push_back(ptr);
    std::cout << "MPointer registrado. Total de punteros: " << pointerList.size() << std::endl;
    return pointerList.size();
}

// Método para eliminar un MPointer
void MPointerGC::deregisterPointer(void* ptr) {
    pointerList.remove(ptr);
    std::cout << "MPointer eliminado. Total de punteros: " << pointerList.size() << std::endl;
}

// Método para ejecutar el Garbage Collector
void MPointerGC::runGC() {
    std::cout << "Ejecutando Garbage Collector..." << std::endl;
    if (pointerList.empty()) {
        std::cout << "No hay punteros por liberar." << std::endl;
    } else {
        std::cout << "Liberando los siguientes punteros: " << std::endl;
        for (auto it = pointerList.begin(); it != pointerList.end(); ++it) {
            std::cout << "Liberando memoria de puntero: " << *it << std::endl;
        }
    }
}
