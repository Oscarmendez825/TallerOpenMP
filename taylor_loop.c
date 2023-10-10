#include <stdio.h>
#include <omp.h>

static long num_terms = 1200; // Número de términos en la serie de Taylor
double e_reference = 2.7182818284590452353602874713527; // Valor de referencia para e

int main() {
    double e_approx, sum;
    double start_time, run_time;

    int max_threads = omp_get_max_threads();

    for (int i = 1; i <= max_threads; i++) 
    {
        sum = 0;
        omp_set_num_threads(i);
        start_time = omp_get_wtime();
        
        #pragma omp parallel for reduction(+:sum)
        for (long long int j = 0; j < num_terms; j++) {
            double term = 1.0;
            for (int k = 1; k <= j; k++) {
                term /= k;
            }
            sum += term;
        }
        
        e_approx = sum;
        run_time = omp_get_wtime() - start_time;

        printf("num_threads = %d computed e = %3.15f in %3.15f seconds threads =  %d %% error = %3.15f\n", i, e_approx, run_time, i, (e_approx - e_reference)*100.0/e_reference);
        
    }
    
}
