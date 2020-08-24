/**
  *@file curso.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase Curos
  *@brief Clase para representar un curso dentro del programa
  */
  
#ifndef CURSO_H     
#define CURSO_H
#include "lista.h"
#include "estudiante.h"

/**
  *@brief Clase para manejar los datos relacionados a un curso
  */ 
class Curso{
		long long int profesor; ///&lt; Cédula del profesor a cargo del curso
		string codigo; ///&lt; Código del curso
		lista<Estudiante> estudiantes; ///&lt; Lista de estudiantes asociada al curso
	public:
		//Setters
		
		/**
	  	  *@brief Establece el código del curso
	  	  *@param cod Código del curso
	  	  */
		void setCodigo(string cod);
		
		/**
	  	  *@brief Establece la lista de estudiantes asociada al curso
	  	  *@param es Lista de tipo Estudiante
	  	  */
		void setListaEstudiantes(lista<Estudiante> es);
		
		/**
	  	  *@brief Establece la cédula del profesor
	  	  *@param cedula Cédula del profesor
	  	  */
		void setProfesor(long long int cedula);
		//Getters
		
		/**
	  	  *@brief Retorna el código del curso
	  	  *@return Código del curso tipo string
	  	  */
		string getCodigo();
		
		/**
	  	  *@brief Retorna la lista de estudiantes del curso
	  	  *@return Lista de tipo Estudiante
	  	  */
		lista<Estudiante> getListaEstudiantes();
		
		/**
	  	  *@brief Retorna la cédula del profesor a cargo
	  	  *@return Número de cédula del profesor tipo long long int
	  	  */
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
