
/**
  *@file profesor.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase Profesor
  *@brief Clase para representar un profesor dentro del programa
  */
#ifndef PROFESOR_H     
#define PROFESOR_H
#include "lista.h"
#include "corte.h"

/**
  *@brief Clase para manejar los datos relacionados al profesor
  */ 
class Profesor{
			long long int cedula; ///&lt; Cédula del profesor
			char apellidos[50]; ///&lt; Apellidos del profesor
			char nombres[50]; ///&lt; Nombres del profesor
			int numClases; ///&lt; Número de clases del profesor
			lista<Corte> cortes; ///&lt; Lista de cortes asociada al profesor
	public:
			/**
	  		  *@brief Constructor por defecto Profesor
	  		  */
			Profesor(){
			};
			//Setters
			
			/**
	  		  *@brief Establece la cédula del profesor
	  		  *@param cc Cédula del profesor
	  		  */
			void setCedula(long long int cc);
			
			/**
	  		  *@brief Establece los apellidos del profesor
	  		  *@param pos posición del arreglo
	  		  *@param letra Letra que debe ir en la posición indicada
	  		  */
			void setApellidos(int pos, char letra);
			
			/**
	  		  *@brief Establece los nombres del profesor
	  		  *@param pos posición del arreglo
	  		  *@param letra Letra que debe ir en la posición indicada
	  		  */
			void setNombres(int pos, char letra);

			/**
	  		  *@brief Establece el número de clases del profesor
	  		  *@param num número de clases del profesor
	  		  */
			void setNumClases(int num);
			
			/**
	  		  *@brief Establece la lista de cortes del profesor
	  		  *@param cor lista de cortes del profesor
	  		  */
			void setListaCorte(lista<Corte> cor);
			//Getters
			
			/**
	  		  *@brief Retorna la lista de cortes del profesor
	  		  *@return Lista de tipo Corte asociada al profesor 
	  		  */
			lista<Corte> getListaCorte();
			
			/**
	  		  *@brief Retorna la cédula del profesor
	  		  *@return Número de cédula del profesor tipo long long int
	  		  */
			long long int& getCedula();
			
			/**
	  		  *@brief Retorna los apellidos del profesor
	  		  *@return Apellidos del profesor tipo puntero a char
	  		  */
			char* getApellidos();
			
			/**
	  		  *@brief Retorna los nombres del profesor
	  		  *@return Nombres del profesor tipo puntero a char
	  		  */
			char* getNombres();
			
			/**
	  		  *@brief Retorna el número de clases del profesor
	  		  *@return Número de clases del profesor tipo entero
	  		  */
			int& getNumClases();
};

//Setters
void Profesor::setCedula(long long int cc){
	cedula=cc;
}

void Profesor::setApellidos(int pos, char letra){
	apellidos[pos]=letra;
}

void Profesor::setNombres(int pos, char letra){
	nombres[pos]=letra;
}
void Profesor::setNumClases(int num){
	numClases=num;
}
void Profesor::setListaCorte(lista<Corte> cor){
	cortes=cor;
}
//Getters
long long int& Profesor::getCedula(){
	return cedula;
}
char* Profesor::getApellidos(){
	return apellidos;
}
char* Profesor::getNombres(){
	return nombres;
}
int& Profesor::getNumClases(){
	return numClases;
}
lista<Corte> Profesor::getListaCorte(){
	return cortes;
}
#endif
