#include <gtest/gtest.h>
#include "MPointer.h"

// Prueba para verificar la asignación de un valor a MPointer
// En esta prueba, se crea un objeto MPointer y se le asigna el valor 10. Luego, se
// verifica que el valor almacenado en la memoria gestionada por el puntero sea el correcto.
TEST(MPointerTest, AssignValue) {
    MPointer<int> myPtr = MPointer<int>::New();  // Se crea un nuevo MPointer que apunta a un entero.
    *myPtr = 10;  // Se asigna el valor 10 a la memoria gestionada por myPtr.
    EXPECT_EQ(*myPtr, 10);  // Se verifica que el valor almacenado sea 10.
}

// Prueba para verificar la asignación entre dos MPointers
// Esta prueba verifica que dos objetos MPointer puedan apuntar al mismo bloque de memoria.
// Después de asignar un MPointer a otro, ambos deben compartir el mismo valor y el mismo ID.
TEST(MPointerTest, AssignPointer) {
    MPointer<int> myPtr1 = MPointer<int>::New();  // Se crea el primer MPointer.
    *myPtr1 = 20;  // Se le asigna el valor 20.

    MPointer<int> myPtr2 = MPointer<int>::New();  // Se crea el segundo MPointer.
    myPtr2 = myPtr1;  // myPtr2 ahora apunta a la misma dirección que myPtr1.
    
    // Se verifica que ambos punteros compartan el mismo valor y el mismo ID.
    EXPECT_EQ(*myPtr2, 20);  // Ambos deben apuntar al valor 20.
    EXPECT_EQ(myPtr1.getId(), myPtr2.getId());  // Los IDs deben ser los mismos.
}

// Prueba para verificar la recolección de basura (registro y eliminación de punteros)
// En esta prueba, se verifica que el Garbage Collector registre correctamente un puntero y
// no arroje ninguna excepción al ejecutarse. No se espera que el recolector de basura elimine
// punteros todavía, ya que el puntero sigue activo.
TEST(MPointerTest, GarbageCollector) {
    MPointer<int> myPtr = MPointer<int>::New();  // Se crea un nuevo MPointer.
    *myPtr = 30;  // Se le asigna el valor 30.

    // Se verifica que el valor asignado sea correcto.
    EXPECT_EQ(*myPtr, 30);
    
    // Se ejecuta el Garbage Collector y se verifica que no arroje ninguna excepción.
    EXPECT_NO_THROW(MPointerGC::getInstance().runGC());
}

// Prueba para verificar la eliminación de punteros
// Esta prueba verifica que un puntero sea correctamente destruido cuando ya no es necesario.
// Se crea un puntero dinámicamente, se asigna un valor, y luego se libera con `delete`.
// Después de liberar el puntero, el Garbage Collector se ejecuta y no debe arrojar excepciones.
TEST(MPointerTest, DestructorTest) {
    MPointer<int>* myPtr = new MPointer<int>();  // Se crea un nuevo MPointer dinámicamente.
    *myPtr = 40;  // Se le asigna el valor 40.
    EXPECT_EQ(*myPtr, 40);  // Se verifica que el valor sea 40.
    
    delete myPtr;  // Se elimina el puntero dinámicamente.
    
    // Se ejecuta el Garbage Collector para asegurarse de que no haya errores.
    EXPECT_NO_THROW(MPointerGC::getInstance().runGC());
}

// Función main de GoogleTest
// Esta función se encarga de ejecutar todas las pruebas definidas anteriormente.
// GoogleTest automáticamente ejecutará cada prueba y reportará si pasa o falla.
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);  // Inicializa GoogleTest con los argumentos.
    return RUN_ALL_TESTS();  // Ejecuta todas las pruebas definidas en este archivo.
}
