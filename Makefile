INCLUDE = -I/usr/include/opencv4 -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui
CXX = g++

all: secuencial threaded openmp

secuencial:
	$(CXX) -m64 -o main_secuencial main_secuencial.cpp $(INCLUDE)
	chmod +x main_secuencial

threaded:
	$(CXX) -o main_threaded procesador_threaded.cpp main_threaded.cpp $(INCLUDE)
	chmod +x main_threaded

openmp:
	$(CXX) -fopenmp -o main_openmp main_openmp.cpp $(INCLUDE)
	chmod +x main_openmp


clean:
	rm main_secuencial.cpp main_threaded.cpp main_openmp


