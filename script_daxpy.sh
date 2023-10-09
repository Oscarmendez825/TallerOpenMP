#!/bin/bash

# Número de veces que deseas ejecutar el programa
num_runs=100

# Directorio donde se almacenarán los resultados
results_dir="results_daxpy"

# Compilar el programa si no está compilado
if [ ! -f "daxpi" ]; then
    gcc -o daxpy daxpy_loop.c -fopenmp -lm
fi

# Crear el directorio de resultados si no existe
if [ ! -d "$results_dir" ]; then
    mkdir "$results_dir"
fi

# Ejecutar el programa múltiples veces y almacenar los resultados
for ((i=1; i<=$num_runs; i++)); do
    ./daxpy > "$results_dir/daxpy_$(printf "%02d" $i).txt"
done

echo "Ejecución de $num_runs veces completada."

#Ejecutar script de python para graficar

python3 plotter_daxpy.py

clear

echo "Gráfica desplegada en el explorador"