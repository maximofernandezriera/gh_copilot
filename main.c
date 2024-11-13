#include <stdbool.h>
#include <stdio.h>

// Función para imprimir los valores del array multiplicados por 2
void imprimirArray(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i] * 2);
    }
    printf("\n");
}

// Función para buscar el valor 11 en el array
bool buscarValor(int arr[], int tamaño, int valor) {
    if (arr == NULL) {
        printf("El array es nulo\n");
        return false;
    }
    for (int i = 0; i < tamaño; i++) {
        if (arr[i] == valor) {
            printf("Valor %d encontrado en la posición %d\n", valor, i);
            return true;
        }
    }
    printf("Valor %d no encontrado en el array\n", valor);
    return false;
}

int main() {
    // Array estático con veinte enteros
    int array[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    // Llamada a la función para imprimir los valores del array multiplicados por 2
    imprimirArray(array, 20);

    // Llamada a la función para buscar el valor 11 en el array
    buscarValor(array, 20, 11);

    return 0;
}
