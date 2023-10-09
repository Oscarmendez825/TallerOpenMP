#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

// Implementación de DAXPY en single thread
void daxpy_single_thread(double a, double* x, double* y, int N) {
    for (int i = 0; i < N; i++) {
        y[i] += a * x[i] + y[i];
    }
}

// Implementación de DAXPY en multithread con OpenMP
void daxpy_multi_thread(double a, double* x, double* y, int N) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        y[i] += a * x[i] + y[i];
    }
}

int main() {
    // Definir un array de tamaños de vectores
    int sizes[] = {240000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int j = 0; j < num_sizes; j++) {
        int N = sizes[j];

        double* x = (double*)malloc(N * sizeof(double));
        double* y = (double*)malloc(N * sizeof(double));

        // Llenar los vectores con valores aleatorios
        for (int i = 0; i < N; i++) {
            x[i] = rand() / (double)RAND_MAX;
            y[i] = rand() / (double)RAND_MAX;
        }

        double a = 5.0; 

        printf("Computed DAXPY for vector size N = %d\n", N);

        int max_threads = omp_get_max_threads(); // Obtener el número máximo de hilos disponibles

        for (int num_threads = 1; num_threads <= max_threads; num_threads++) {
            omp_set_num_threads(num_threads);
            double start_time = omp_get_wtime();

            if (num_threads == 1) {
                daxpy_single_thread(a, x, y, N);
            } else {
                daxpy_multi_thread(a, x, y, N);
            }

            double run_time = omp_get_wtime() - start_time;
            printf("num_threads = %d computed daxpy in %3.15f seconds threads =  %d\n", num_threads, run_time, num_threads);
        }

        free(x);
        free(y);
    }

}
