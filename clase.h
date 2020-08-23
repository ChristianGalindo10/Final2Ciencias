#ifndef CLASE_H     
#define CLASE_H
#include "lista.h"

struct Cur{
	string curso;
	lista<string> archivos;
};

class Clase{
		long long int cedula;
		lista<Cur> cursos;
	public:
		//Setters
		void setCedula(long long int c);
		void setCursos(lista<Cur> cs);
		//Getters
		long long int& getCedula();
		lista<Cur> getCursos();
};
//Setters
void Clase::setCedula(long long int c){
	cedula=c;
}

void Clase::setCursos(lista<Cur> cs){
	cursos=cs;
}
//Getters
long long int& Clase::getCedula(){
	return cedula;
}

lista<Cur> Clase::getCursos(){
	return cursos;
}
#endif
