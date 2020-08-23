#ifndef CURSO_H     
#define CURSO_H
#include "lista.h"
#include "estudiante.h"
class Curso{
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
void Curso::setCodigo(string cod){
	codigo=cod;
}

void Curso::setListaEstudiantes(lista<Estudiante> es){
	estudiantes=es;
}
//Getters
string Curso::getCodigo(){
	return codigo;
}

lista<Estudiante> Curso::getListaEstudiantes(){
	return estudiantes;
}
#endif
