# Procesamiento Secuencial de Imágenes con Validaciones

## Descripción general

Este programa en C++ utiliza la biblioteca OpenCV para cargar una imagen, aplicar un filtro de escala de grises de manera secuencial y guardar la imagen resultante. Además, incorpora validaciones para asegurarse de que las entradas sean correctas. El código está organizado en un archivo principal `procesamiento_secuencial.cpp`.

## Uso

1. **Incluir bibliotecas**: Asegúrate de tener OpenCV instalado. Incluye las bibliotecas necesarias al principio del programa.

```cpp
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <chrono>
#include <regex>
```

2. **Definir y llamar la función `procesar_secuencial`**: La función toma el nombre del archivo de entrada y el nombre del archivo de salida como parámetros.

```cpp
procesar_secuencial("input.jpg", "output.jpg");
```

3. **Resultados**: La imagen procesada se guardará con el nombre de archivo especificado, y se imprimirá un mensaje indicando el nombre del archivo de salida.

## Detalles de implementación

- La función `procesar_secuencial` carga la imagen en color desde el archivo de entrada utilizando OpenCV.
- Utiliza dos bucles anidados para recorrer cada píxel de la imagen y aplica la fórmula estándar para convertir un píxel de color a escala de grises.
- Mide el tiempo de ejecución para evaluar el rendimiento.
- Valida las entradas del programa, asegurándose de que los nombres de archivo tengan extensiones válidas (como .jpg, .jpeg, .png).

## Comentarios y Validaciones

- Se imprime en la consola el proceso de carga de la imagen y se valida si la imagen se ha cargado correctamente.
- Se verifican las entradas del programa, y se muestra un mensaje de error si no cumplen con las validaciones.
- Se imprime el tiempo de ejecución en milisegundos al final del procesamiento.
- Se muestra un mensaje indicando el nombre del archivo de salida.

## Compilación

Asegúrate de tener instalado el compilador de C++ (g++) y las bibliotecas de OpenCV. Puedes instalar OpenCV en Ubuntu con el siguiente comando:

```bash
sudo apt-get install libopencv-dev
```

Compila el programa con el siguiente comando:

```bash
g++ procesamiento_secuencial.cpp -o procesamiento_secuencial -std=c++11 -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui
```

## Ejecución

Ejecuta el programa compilado:

```bash
./procesamiento_secuencial input.jpg output.jpg
```

Observa la salida que indica el progreso y el tiempo de ejecución. La imagen procesada se guardará con el nombre especificado.

