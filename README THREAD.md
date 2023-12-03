# Procesamiento Multithreading de Imágenes con Validaciones

## Descripción general

Este programa en C++ utiliza la biblioteca OpenCV para cargar una imagen, aplicar un filtro de escala de grises utilizando multithreading y guardar la imagen resultante. Además, incorpora validaciones para asegurarse de que las entradas sean correctas. El código está organizado en tres archivos: `main.cpp`, `procesador_threaded.cpp` y `procesador_threaded.h`.

## Uso

1. **Compilación**: Asegúrate de tener OpenCV instalado. Puedes instalar OpenCV en Ubuntu con el siguiente comando:

```bash
sudo apt-get install libopencv-dev
```

Compila el programa con el siguiente comando:

```bash
g++ main.cpp procesador_threaded.cpp -o procesamiento_threaded -std=c++11 -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -pthread
```

2. **Ejecución**: Ejecuta el programa compilado:

```bash
./procesamiento_threaded input.jpg output.jpg 4
```

Reemplaza `input.jpg` y `output.jpg` con los nombres de archivo de entrada y salida respectivamente, y `4` con el número deseado de hebras (puedes ajustar este valor según tu preferencia).

## Detalles de implementación

### Clase `ProcesadorThreaded`

- La clase toma el nombre del archivo de entrada, el nombre del archivo de salida y el número de hebras como parámetros en su constructor.
- La función `procesar_imagen` inicializa y ejecuta un número definido de threads que procesan partes de la imagen en paralelo.
- La función `computar_thread` realiza el procesamiento de la imagen para el rango de columnas asignado a cada thread.

### Main (`main.cpp`)

- Se validan las entradas del programa, asegurándose de que los nombres de archivo tengan extensiones válidas (como .jpg, .jpeg, .png) y de que el número de hebras sea válido.
- Se crea una instancia de la clase `ProcesadorThreaded` y se llama a la función `procesar_imagen`.

## Comentarios y Validaciones

- Se imprime en la consola el proceso de carga de la imagen y se valida si la imagen se ha cargado correctamente.
- Se verifican las entradas del programa, y se muestra un mensaje de error si no cumplen con las validaciones.
- Se imprime el tiempo de ejecución en milisegundos al final del procesamiento.
- Se muestra un mensaje indicando el nombre del archivo de salida.

## Compilación

Asegúrate de tener instalado el compilador de C++ (g++) y las bibliotecas de OpenCV. Compila el programa con el siguiente comando:

```bash
g++ main.cpp procesador_threaded.cpp -o procesamiento_threaded -std=c++11 -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -pthread
```

## Ejecución

Ejecuta el programa compilado con el comando mencionado anteriormente, proporcionando los nombres de archivo de entrada y salida, así como el número de hebras deseado.

