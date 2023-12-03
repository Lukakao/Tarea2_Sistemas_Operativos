#include <iostream>
#include "procesador_threaded.h"
#include <regex>

using namespace std;

int main(int const argc, char const** argv){
	int numero_hebras = stoi(argv[3]);
	const regex pattern("[^\\s]+(.*?)\\.(jpg|jpeg|png|JPG|JPEG|PNG)$");
	if(!regex_match(argv[1],pattern) ){
		cout << "Imagen de input no es valida" << endl;
		return 0;
	}
        if(!regex_match(argv[2],pattern) ){
		cout << "Imagen de output no es valida" << endl;
		return 0;
	}
	if(numero_hebras < 1 || numero_hebras > 1000){
		cout << "numero de hebras invalido" << endl;
		return 0;
	}
	ProcesadorThreaded procesador(argv[1],argv[2],numero_hebras);
	procesador.procesar_imagen();
}
