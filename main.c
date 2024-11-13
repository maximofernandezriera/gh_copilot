#include <stdio.h>

// Función para imprimir los valores del array multiplicados por 2
void imprimirArray(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i] * 2);
    }
    printf("\n");
}

int main() {
    // Array estático con veinte enteros
    int array[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    // Llamada a la función para imprimir los valores del array multiplicados por 2
    imprimirArray(array, 20);

    return 0;
}
