# Procesamiento OpenMP con Validaciones y Comentarios (GNU/Linux)

## Descripción general

Este programa en C++ utiliza la biblioteca OpenCV y OpenMP para cargar una imagen, aplicar un filtro de escala de grises de manera paralela y guardar la imagen resultante. Además, incorpora validaciones para asegurarse de que las entradas sean correctas. El código está organizado en un archivo principal `procesamiento_openmp.cpp`.

## Uso

1. **Incluir bibliotecas**: Asegúrate de tener OpenCV, OpenMP y la biblioteca regex instaladas. Incluye las bibliotecas necesarias al principio del programa.

```cpp
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <chrono>
#include <omp.h>
#include <regex>
```

2. **Definir y llamar la función `procesar_openmp`**: La función toma el nombre del archivo de entrada, el nombre del archivo de salida y la cantidad de hilos OpenMP como parámetros.

```cpp
procesar_openmp("input.jpg", "output.jpg", 4);
```

3. **Resultados**: La imagen procesada se guardará con el nombre de archivo especificado, y se imprimirá un mensaje indicando el nombre del archivo de salida.

## Detalles de implementación

- La función `procesar_openmp` carga la imagen en color desde el archivo de entrada utilizando OpenCV.
- Utiliza OpenMP para paralelizar el bucle que recorre cada píxel de la imagen y aplica la fórmula estándar para convertir un píxel de color a escala de grises.
- Mide el tiempo de ejecución para evaluar el rendimiento.
- Valida las entradas del programa, asegurándose de que los nombres de archivo tengan extensiones válidas (como .jpg, .jpeg, .png) y que la cantidad de hilos sea un número válido.

## Comentarios y Validaciones

- Se imprime en la consola el proceso de carga de la imagen y se valida si la imagen se ha cargado correctamente.
- Se verifican las entradas del programa, y se muestra un mensaje de error si no cumplen con las validaciones.
- Se imprime el tiempo de ejecución en milisegundos al final del procesamiento.
- Se muestra un mensaje indicando el nombre del archivo de salida.

## Compilación (GNU/Linux)

Asegúrate de tener instalado el compilador de GNU C++ (g++) y las bibliotecas de OpenCV, OpenMP y regex. Puedes instalar OpenCV en Ubuntu con el siguiente comando:

```bash
sudo apt-get install libopencv-dev
```

Compila el programa con el siguiente comando:

```bash
g++ procesamiento_openmp.cpp -o procesamiento_openmp -std=c++11 -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -fopenmp
```

## Ejecución

Ejecuta el programa compilado:

```bash
./procesamiento_openmp input.jpg output.jpg 4
```

Observa la salida que indica el progreso y el tiempo de ejecución. La imagen procesada se guardará con el nombre especificado.

