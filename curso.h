#ifndef CURSO_H     
#define CURSO_H
#include "lista.h"
#include "estudiante.h"
class Curso{
		long long int profesor;
		string codigo;
		lista<Estudiante> estudiantes;
	public:
		//Setters
		void setCodigo(string cod);
		void setListaEstudiantes(lista<Estudiante> es);
		void setProfesor(long long int cedula);
		//Getters
		string getCodigo();
		lista<Estudiante> getListaEstudiantes();
		long long int& getProfesor();
};
//Setters
void Curso::setCodigo(string cod){
	codigo=cod;
}

void Curso::setListaEstudiantes(lista<Estudiante> es){
	estudiantes=es;
}

void Curso::setProfesor(long long int cedula){
	profesor=cedula;
}
//Getters
string Curso::getCodigo(){
	return codigo;
}

lista<Estudiante> Curso::getListaEstudiantes(){
	return estudiantes;
}

long long int& Curso::getProfesor(){
	return profesor;
}
#endif
