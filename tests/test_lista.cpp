#include <gtest/gtest.h>
#include "ListaDoble.h"
#include "sorting.h"

// Prueba para verificar QuickSort en una lista doblemente enlazada
// Qué sucede: Se crea una lista doblemente enlazada y se agregan los elementos 3, 1 y 2.
// Por qué sucede: Esta prueba busca verificar que el algoritmo QuickSort ordena correctamente los elementos.
// Qué deberíamos esperar: La lista debe ordenarse en el siguiente orden: 1, 2, 3.
TEST(ListaDobleTest, QuickSortTest) {
    ListaDoble<int> lista;  // Crea una lista doblemente enlazada de enteros.
    lista.agregar(3);  // Agrega el número 3 a la lista.
    lista.agregar(1);  // Agrega el número 1 a la lista.
    lista.agregar(2);  // Agrega el número 2 a la lista.

    quickSort(lista.obtenerHead(), lista.obtenerTail());  // Ordena la lista utilizando QuickSort.
    lista.imprimir();  // Imprime la lista para verificar visualmente el resultado.

    // Verifica que la lista esté ordenada correctamente.
    EXPECT_EQ(lista.obtenerHead()->data, 1);  // El primer elemento debe ser 1.
    EXPECT_EQ(lista.obtenerHead()->siguiente->data, 2);  // El segundo elemento debe ser 2.
    EXPECT_EQ(lista.obtenerTail()->data, 3);  // El último elemento debe ser 3.
}

// Prueba para verificar BubbleSort en una lista doblemente enlazada
// Qué sucede: Se crea una lista doblemente enlazada y se agregan los elementos 5, 2, 4 y 1.
// Por qué sucede: Esta prueba busca verificar que el algoritmo BubbleSort ordena correctamente los elementos.
// Qué deberíamos esperar: La lista debe ordenarse en el siguiente orden: 1, 2, 4, 5.
TEST(ListaDobleTest, BubbleSortTest) {
    ListaDoble<int> lista;  // Crea una lista doblemente enlazada de enteros.
    lista.agregar(5);  // Agrega el número 5 a la lista.
    lista.agregar(2);  // Agrega el número 2 a la lista.
    lista.agregar(4);  // Agrega el número 4 a la lista.
    lista.agregar(1);  // Agrega el número 1 a la lista.

    bubbleSort(lista.obtenerHead());  // Ordena la lista utilizando BubbleSort.
    lista.imprimir();  // Imprime la lista para verificar visualmente el resultado.

    // Verifica que la lista esté ordenada correctamente.
    EXPECT_EQ(lista.obtenerHead()->data, 1);  // El primer elemento debe ser 1.
    EXPECT_EQ(lista.obtenerHead()->siguiente->data, 2);  // El segundo elemento debe ser 2.
    EXPECT_EQ(lista.obtenerTail()->data, 5);  // El último elemento debe ser 5.
}

// Prueba para verificar InsertionSort en una lista doblemente enlazada
// Qué sucede: Se crea una lista doblemente enlazada y se agregan los elementos 3, 1 y 4.
// Por qué sucede: Esta prueba busca verificar que el algoritmo InsertionSort ordena correctamente los elementos.
// Qué deberíamos esperar: La lista debe ordenarse en el siguiente orden: 1, 3, 4.
TEST(ListaDobleTest, InsertionSortTest) {
    ListaDoble<int> lista;  // Crea una lista doblemente enlazada de enteros.
    lista.agregar(3);  // Agrega el número 3 a la lista.
    lista.agregar(1);  // Agrega el número 1 a la lista.
    lista.agregar(4);  // Agrega el número 4 a la lista.

    insertionSort(lista.obtenerHead());  // Ordena la lista utilizando InsertionSort.
    lista.imprimir();  // Imprime la lista para verificar visualmente el resultado.

    // Verifica que la lista esté ordenada correctamente.
    EXPECT_EQ(lista.obtenerHead()->data, 1);  // El primer elemento debe ser 1.
    EXPECT_EQ(lista.obtenerHead()->siguiente->data, 3);  // El segundo elemento debe ser 3.
    EXPECT_EQ(lista.obtenerTail()->data, 4);  // El último elemento debe ser 4.
}
