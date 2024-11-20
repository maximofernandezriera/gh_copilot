#include <stdio.h>
#include "mpi.h"

#define SIZE 10
#define USERID 28

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int v1[SIZE];

    // Inicialización de v1
    for (int i = 0; i < SIZE; i++) {
        if (rank == 0)
            v1[i] = USERID + i; // Valores iniciales para rank 0
        else if (rank == 1)
            v1[i] = (USERID - i) * (-1); // Valores iniciales para rank 1
    }

    // Impresión inicial del vector en ambos procesos
    for (int i = 0; i < SIZE; i++) 
        printf("[%d/%d] index %d value %d\n", rank, size, i, v1[i]);

    // Crear una ventana de memoria para RMA
    MPI_Win win;
    MPI_Win_create(v1, SIZE * sizeof(int), sizeof(int), MPI_INFO_NULL, MPI_COMM_WORLD, &win);

    // Intercambio de datos usando RMA
    if (rank == 0) {
        MPI_Win_fence(0, win); // Sincronización para leer los datos del rank 1

        // Obtener valores de índices impares desde rank 1
        for (int i = 1; i < SIZE; i += 2) {
            int temp;
            MPI_Get(&temp, 1, MPI_INT, 1, i, 1, MPI_INT, win);
            v1[i] = temp; // Actualizar los valores impares en rank 0
        }

        MPI_Win_fence(0, win); // Sincronización final
    } else if (rank == 1) {
        MPI_Win_fence(0, win); // Sincronización para que rank 0 lea los datos
        MPI_Win_fence(0, win); // Sincronización final
    }

    // Impresión final en rank 0
    if (rank == 0) {
        printf("\nFinal vector in rank 0:\n{");
        for (int i = 0; i < SIZE; i++) {
            printf("%d", v1[i]);
            if (i < SIZE - 1) printf(", ");
        }
        printf("}\n");
    }

    // Liberar recursos
    MPI_Win_free(&win);
    MPI_Finalize();
    return 0;
}

