#include <gtest/gtest.h>
#include "MPointer.h"

// Prueba para verificar la asignación de un valor a MPointer
// Qué sucede: Se crea un MPointer y se asigna el valor 10.
// Por qué sucede: Esta prueba busca verificar que la asignación de valores a MPointer funcione correctamente.
// Qué deberíamos esperar: El valor almacenado en MPointer debe ser 10.
TEST(MPointerTest, AssignValue) {
    MPointer<int> myPtr = MPointer<int>::New();  // Crea un nuevo MPointer que apunta a un entero.
    *myPtr = 10;  // Asigna el valor 10.
    EXPECT_EQ(*myPtr, 10);  // Verifica que el valor sea 10.
}

// Prueba para verificar la asignación entre dos MPointers
// Qué sucede: Se crea un MPointer y se asigna otro a él.
// Por qué sucede: Esta prueba verifica que se puedan asignar dos MPointers y compartan la misma memoria.
// Qué deberíamos esperar: Ambos MPointers deben apuntar al mismo valor.
TEST(MPointerTest, AssignPointer) {
    MPointer<int> myPtr1 = MPointer<int>::New();  // Crea el primer MPointer.
    *myPtr1 = 20;  // Asigna el valor 20.

    MPointer<int> myPtr2 = MPointer<int>::New();  // Crea el segundo MPointer.
    myPtr2 = myPtr1;  // Asigna el primero al segundo.

    EXPECT_EQ(*myPtr2, 20);  // Verifica que ambos apunten al valor 20.
    EXPECT_EQ(myPtr1.getId(), myPtr2.getId());  // Verifica que ambos compartan el mismo ID.
}

// Prueba para verificar la recolección de basura (GC)
// Qué sucede: Se crea un MPointer, se asigna un valor y se ejecuta el Garbage Collector.
// Por qué sucede: Esta prueba busca verificar que el Garbage Collector pueda ejecutarse sin problemas.
// Qué deberíamos esperar: No debe lanzarse ninguna excepción al ejecutar el Garbage Collector.
TEST(MPointerTest, GarbageCollector) {
    MPointer<int> myPtr = MPointer<int>::New();  // Crea un nuevo MPointer.
    *myPtr = 30;  // Asigna el valor 30.

    EXPECT_EQ(*myPtr, 30);  // Verifica que el valor sea 30.
    EXPECT_NO_THROW(MPointerGC::getInstance().runGC());  // Verifica que no se lance una excepción al ejecutar el GC.
}

// Prueba para verificar la eliminación de punteros
// Qué sucede: Se crea un MPointer dinámicamente, se asigna un valor, se elimina y luego se ejecuta el Garbage Collector.
// Por qué sucede: Esta prueba verifica que los punteros se eliminen correctamente.
// Qué deberíamos esperar: No debe lanzarse ninguna excepción durante la eliminación y el Garbage Collector.
TEST(MPointerTest, DestructorTest) {
    MPointer<int>* myPtr = new MPointer<int>();  // Crea un nuevo MPointer dinámicamente.
    *myPtr = 40;  // Asigna el valor 40.
    EXPECT_EQ(*myPtr, 40);  // Verifica que el valor sea 40.
    delete myPtr;  // Elimina el puntero.
    EXPECT_NO_THROW(MPointerGC::getInstance().runGC());  // Verifica que el GC no lance excepciones.
}

// Prueba para verificar punteros nullptr
// Qué sucede: Se crea un MPointer que apunta a nullptr.
// Por qué sucede: Esta prueba verifica la asignación y comparación con nullptr.
// Qué deberíamos esperar: El puntero debería ser igual a nullptr.
TEST(MPointerTest, NullPointerTest) {
    MPointer<int> nullPtr(nullptr);  // Crea un MPointer que apunta a nullptr.
    EXPECT_EQ(nullPtr == nullptr, true);  // Verifica que el puntero es igual a nullptr.
    EXPECT_EQ(nullPtr != nullptr, false);  // Verifica que no es diferente de nullptr.
}

// Prueba para verificar la asignación directa de valores
// Qué sucede: Se crea un MPointer y se asigna un valor directamente (por ejemplo, 50).
// Por qué sucede: Esta prueba verifica que la asignación directa funcione correctamente.
// Qué deberíamos esperar: El valor almacenado debe ser 50.
TEST(MPointerTest, DirectAssignmentTest) {
    MPointer<int> myPtr = MPointer<int>::New();
    myPtr = 50;  // Asignación directa de un valor.
    EXPECT_EQ(*myPtr, 50);  // Verifica que el valor sea 50.
}

// Prueba para verificar igualdad y desigualdad entre MPointers
// Qué sucede: Se crean dos MPointers, ambos apuntando a diferentes valores, y luego se comparan.
// Por qué sucede: Esta prueba verifica que las comparaciones entre dos MPointers funcionen correctamente.
// Qué deberíamos esperar: Los punteros deben ser diferentes antes de la asignación y ser iguales después.
TEST(MPointerTest, EqualityAndInequalityTest) {
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();
    *ptr1 = 100;
    *ptr2 = 100;

    EXPECT_EQ(ptr1 == ptr2, false);  // Los valores son iguales, pero las referencias son diferentes.
    EXPECT_EQ(ptr1 != ptr2, true);  // Las referencias deben ser diferentes.

    ptr2 = ptr1;
    EXPECT_EQ(ptr1 == ptr2, true);  // Ahora ambos punteros apuntan a la misma referencia.
}

// Prueba para verificar la obtención del ID de un MPointer
// Qué sucede: Se crean dos MPointers y se verifica que cada uno tenga un ID único.
// Por qué sucede: Esta prueba asegura que cada MPointer tenga un ID único y que el ID se mantenga tras la asignación.
// Qué deberíamos esperar: Los IDs deben ser diferentes antes de la asignación y ser iguales después.
TEST(MPointerTest, GetIdTest) {
    MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();

    EXPECT_NE(myPtr.getId(), myPtr2.getId());  // Los IDs deben ser diferentes.

    myPtr2 = myPtr;
    EXPECT_EQ(myPtr.getId(), myPtr2.getId());  // Después de la asignación, ambos deben tener el mismo ID.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // Ejecuta todas las pruebas.
}
