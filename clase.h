#ifndef CLASE_H     
#define CLASE_H
#include "lista.h"
#include "estudiante.h"
class Clase{
		string codigo;
		lista<Estudiante> estudiantes;
	public:
		//Setters
		void setCodigo(string cod);
		void setListaEstudiantes(lista<Estudiante> es);
		//Getters
		string getCodigo();
		lista<Estudiante> getListaEstudiantes();
};
//Setters
void Clase::setCodigo(string cod){
	codigo=cod;
}

void Clase::setListaEstudiantes(lista<Estudiante> es){
	estudiantes=es;
}
//Getters
string Clase::getCodigo(){
	return codigo;
}

lista<Estudiante> Clase::getListaEstudiantes(){
	return estudiantes;
}
#endif
