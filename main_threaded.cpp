#include <iostream>
#include "procesador_threaded.h"
#include <regex>

using namespace std;

int main(int const argc, char const** argv){
	int numero_hebras = stoi(argv[3]);

	// se usa un regex para validar los strings de entrada, de forma que solo se permiten archivos que terminan en .jpg, png, etc.
	// los strings no pueden tener 0 caracteres antes de la extension .jpg, etc.
	const regex pattern("[^\\s]+(.*?)\\.(jpg|jpeg|png|JPG|JPEG|PNG)$");
	if(!regex_match(argv[1],pattern) ){ // valida nombre de input
		cout << "Imagen de input no es valida" << endl;
		return 0;
	}
        if(!regex_match(argv[2],pattern) ){ // valida nombre de input
		cout << "Imagen de output no es valida" << endl;
		return 0;
	}
	if(numero_hebras < 1 || numero_hebras > 1000){ // valida que la cantidad de hebras ingresadas no sea 0 ni mayor a 1000
		cout << "numero de hebras invalido" << endl;
		return 0;
	}
	ProcesadorThreaded procesador(argv[1],argv[2],numero_hebras); // se crea una instancia de la clase con los argumentos
	procesador.procesar_imagen();
}
