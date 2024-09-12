#include "MPointer.h"
#include <iostream>

int main() {
    {
        // Se crea un nuevo puntero MPointer que gestionará un puntero a un entero.
        // La función MPointer::New() inicializa un nuevo objeto MPointer y lo registra
        // en el Garbage Collector.
        MPointer<int> myPtr = MPointer<int>::New();

        // El operador * ha sido sobrecargado en la clase MPointer para permitir 
        // acceder al valor que apunta el puntero interno (ptr).
        // Aquí se asigna el valor 10 a la memoria gestionada por myPtr.
        *myPtr = 10;

        // Se utiliza el operador * para obtener el valor almacenado en myPtr,
        // el cual es 10, y se imprime en la consola.
        std::cout << "Valor de myPtr: " << *myPtr << std::endl;

        // Se crea otro MPointer que también gestiona un puntero a entero.
        // Se inicializa usando la función MPointer::New().
        MPointer<int> myPtr2 = MPointer<int>::New();

        // El operador = ha sido sobrecargado para permitir la asignación entre dos
        // objetos MPointer. Cuando myPtr2 = myPtr, ambos punteros apuntan a la 
        // misma dirección de memoria (comparten el mismo valor).
        // El contador de referencias se incrementa.
        myPtr2 = myPtr;

        // Se imprime el valor almacenado en myPtr2, que debería ser el mismo que
        // el valor almacenado en myPtr, es decir, 10.
        std::cout << "Valor de myPtr2: " << *myPtr2 << std::endl;

        // Verificación de IDs de los punteros. Ambos punteros (myPtr y myPtr2) deberían
        // tener el mismo ID, ya que están apuntando a la misma memoria.
        // La función getId() devuelve el ID asociado a cada MPointer.
        std::cout << "ID de myPtr: " << myPtr.getId() << std::endl;
        std::cout << "ID de myPtr2: " << myPtr2.getId() << std::endl;

    } // Fin del bloque, aquí ambos MPointer (myPtr y myPtr2) salen de alcance.
      // El destructor de MPointer se llama automáticamente al salir del bloque.
      // Dado que myPtr y myPtr2 compartían la misma memoria, el contador de referencias 
      // se decrementa en cada uno, y cuando el último MPointer es destruido, 
      // la memoria es liberada.

    // El Garbage Collector se ejecuta manualmente aquí, aunque no hay más punteros
    // activos en este momento, debería confirmar que no hay punteros por liberar.
    MPointerGC::getInstance().runGC();

    return 0;
}
