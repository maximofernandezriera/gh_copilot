#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

// Declare the functions to be tested
void imprimirArray(int arr[], int tamaño);
bool buscarValor(int arr[], int tamaño, int valor);

void test_imprimirArray() {
    int array[5] = {1, 2, 3, 4, 5};
    printf("Expected output: 2 4 6 8 10\n");
    printf("Actual output: ");
    imprimirArray(array, 5);
}

void test_buscarValor() {
    int array[5] = {1, 2, 3, 4, 5};
    assert(buscarValor(array, 5, 3) == true);
    assert(buscarValor(array, 5, 6) == false);
    printf("All buscarValor tests passed.\n");
}

int main() {
    test_imprimirArray();
    test_buscarValor();
    return 0;
}