#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <chrono>
#include <omp.h>
#include <regex>
using namespace cv;
using namespace std;
using namespace std::chrono;

void procesar_openmp(const string& input_nombre, const  string& output_nombre, int cant_threads){ // la funcoin es similar a la funcion secuencial, pero hace uso de OpenMP para el multithreading
	cout << "Cargando imagen... " << endl;
	Mat img = imread(input_nombre, IMREAD_COLOR);
	if(img.empty()){  // se valida que la imagen cargo correctamente
		cout << "No se encontró imagen " << endl;
		return;
	}
	auto t1 = steady_clock::now(); // se usa para medir el tiempo de ejecucion
	cout << "Ejecutando... " << endl;
	// se hace uso de la libreria openmp
	#pragma omp parallel num_threads(cant_threads) 
	{
		#pragma omp for
        	for(int c=0; c<img.size().height;c++){
                	for(int r=0; r<img.size().width;r++){
                        	// pasar por cada pixel en imagen
				Vec3b pixel = img.at<Vec3b>(c,r);
                        	int gris = pixel[0]*0.114 + pixel[1]*0.587 + pixel[2]*0.299; // se calcula el valor de la luminosidad con los tres canales de color del pixel
				img.at<Vec3b>(c,r) = Vec3b(gris,gris,gris); // se reeemplaza el pixel por el nuevo color gris
			}
        	}
	}

	auto t2 = steady_clock::now();
	cout << "Tiempo de ejecucion: " << duration_cast<milliseconds>(t2-t1).count() << "ms" << endl;
	imwrite(output_nombre, img); // se guarda la imagen
	cout << "Imagen guardada como: " << output_nombre << endl;

}

int main(int const argc, char const** argv){
	// se usa un regex para validar los strings de entrada, de forma que solo se permiten archivos que terminan en .jpg, png, etc.
	// los strings no pueden tener 0 caracteres antes de la extension .jpg, etc.
	const regex pattern("[^\\s]+(.*?)\\.(jpg|jpeg|png|JPG|JPEG|PNG)$");
        if(!regex_match(argv[1],pattern) ){ // valida el nombre del input
                cout << "Imagen de input no es valida" << endl;
                return 0;
        }
        if(!regex_match(argv[2],pattern) ){ // valida el nombre del output
                cout << "Imagen de output no es valida" << endl;
                return 0;
        }

	int cant_threads = stoi(argv[3]); // se valida que como minimo se use una hebra y no mas de 1000.
	if(cant_threads < 1 || cant_threads > 1000){
                cout << "numero de hebras invalido" << endl;
                return 0;
        }
	procesar_openmp(argv[1],argv[2], cant_threads);
}
