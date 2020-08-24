/**
  *@file estudiante.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase Estudiante
  *@brief Clase para representar un estudiante dentro del programa
  */

#ifndef ESTUDIANTE_H     
#define ESTUDIANTE_H

/**
  *@brief Clase para manejar los datos relacionados al estudiante
  */ 
class Estudiante{
		long long int codigo; ///&lt; Código del estudiante
		char apellidos[50]; ///&lt; Apellidos del estudiante
		char nombres[50]; ///&lt; Nombres del estudiante
	public:
		//Setters
		/**
	  	  *@brief Establece el código del estudiante
	  	  *@param cod Código del estudiante
	  	  */
		void setCodigo(long long int cod);
		
		/**
	  	  *@brief Establece los nombres del estudiante
	  	  *@param pos posición del arreglo
	  	  *@param letra Letra que debe ir en la posición indicada
	  	  */
		void setNombres(int pos, char letra);
		
		/**
	  	  *@brief Establece los apellidos del estudiante
	  	  *@param pos posición del arreglo
	  	  *@param letra Letra que debe ir en la posición indicada
	  	  */
		void setApellidos(int pos, char letra);
		//Getters
		/**
	  	  *@brief Retorna el código del estudiante
	  	  *@return Código del estudiante tipo long long int
	  	  */
		long long int& getCodigo();
		
		/**
	  	  *@brief Retorna los apellidos del estudiante
	  	  *@return Apellidos del estudiante tipo puntero a char
	  	  */
		char* getApellidos();
		
		/**
	  	  *@brief Retorna los nombres del estudiante
	  	  *@return Nombres del estudiante tipo puntero a char
	  	  */
		char* getNombres();
};
//Setters

void Estudiante::setCodigo(long long int cod){
	codigo=cod;
}

void Estudiante::setNombres(int pos, char letra){
	nombres[pos]=letra;
}

void Estudiante::setApellidos(int pos, char letra){
	apellidos[pos]=letra;
}

//Getters
long long int& Estudiante::getCodigo(){
	return codigo;
}

char* Estudiante::getNombres(){
	return nombres;
}

char* Estudiante::getApellidos(){
	return apellidos;
}

#endif
