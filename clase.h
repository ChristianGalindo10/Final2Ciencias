/**
  *@file clase.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase Clase
  */

#ifndef CLASE_H     
#define CLASE_H
#include "lista.h"

/**
  *@brief Estructura auxiliar para guardar las direcciones los archivos de los parciales enviados por los profesores
  */
struct Cur{
	string curso;
	lista<string> archivos;
};


/**
  *@brief Clase para manejar los datos relacionados a los parciales
  */ 
class Clase{
		long long int cedula; ///&lt; Cédula del profesor a cargo
		lista<Cur> cursos; ///&lt; Lista de tipo Cur donde se encuentran los archivos de los parciales
	public:
		//Setters
		/**
	  	  *@brief Establece la cédula del profesor
	  	  *@param c Cédula del profesor
	  	  */
		void setCedula(long long int c);
		
		/**
	  	  *@brief Establece la lista de cursos
	  	  *@param cs Lista de tipo Cur
	  	  */
		void setCursos(lista<Cur> cs);
		//Getters
		
		/**
	  	  *@brief Retorna el número de cédula del profesor
	  	  *@return Número de cédula del profesor de tipo long long int
	  	  */
		long long int& getCedula();
		
		/**
	  	  *@brief Retorna la lista de cursos
	  	  *@return Lista de tipo Cur
	  	  */
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
