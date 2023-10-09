
# Taller OpenMP

A continuanción se presentan las especificaciones en las que se ejecutó el taller.
- Sistema operativo: Linux Ubuntu 22.04.3 LTS
- GCC Compiler: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0

## Descripción de los archivos del taller:
- **pi.c:** Código del cálculo de pi. (Punto 3a de la especificación)
- **pi_loop.c:** Código del cálculo de pi (Punto 3b de la especificación)
- **script.sh:** Script de shell para ejecutar los pasos (3c y 3d de la especificación)
- **plotter.py:** Script de Python para ejecutar el punto 3d de la especificación sin el script de shell.
- **taylor_loop.c:** Código del cálculo de Euler por series de Taylor(Punto 4a de la especificación)
- **daxpy_loop.c:** Código de la operación DAXPY (Punto 4b de la especificación)
- **script_e.sh:** Script de shell para ejecutar el código del cálculo de series de Taylor 100 veces y además de generar la gráfica de este.(Punto 4c referente a Taylor)
- **script_daxpy.sh:** Script de shell para ejecutar el código del DAXPY 100 veces y además de generar la gráfica de este.(Punto 4c referente a DAXPY)
- **plotter_e.py:** Script de Python para ejecutar el punto 4c de la especificación sin el script de shell para Euler.
- **plotter_daxpy.py:** Script de Python para ejecutar el punto 4c de la especificación sin el script de shell para DAXPY.

## Modos de ejecución

### Compilación y ejecución individual de los archivos .c

- `gcc -fopenmp -o NombreDelEjecutable NombreDelArchivo.c`
- `./NombreDelEjecutable`

### Ejecución por medio de los scripts de shell

#### **Para pi_loop.c**
- `chmod +x script.sh`
- `./script.sh`

#### **Para taylor_loop.c**
- `chmod +x script_e.sh`
- `./script_e.sh`

#### **Para daxpy_loop.c**
- `chmod +x script_daxpy.sh`
- `./script_daxpy.sh`
