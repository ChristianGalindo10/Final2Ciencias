/**
  *@file contenedor.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase Contenedor
  *@brief Clase para representar una evaluación dentro del programa
  */

#ifndef CONTENEDOR_H     
#define CONTENEDOR_H
#include "lista.h"
#include "evaluacion.h"

/**
  *@brief Clase para manejar los datos de una evaluación relacionada a un tipo de evaluación
  */ 
class Contenedor{
		int i; ///&lt; Número de la evaluación
		lista<Evaluacion> c; ///&lt; Preguntas asociadas a la evaluación
	public:
		//Setters
		
		/**
	  	  *@brief Establece el número de la evaluación
	  	  *@param a Número de la evaluación
	  	  */
		void setI(int a);
		
		/**
	  	  *@brief Establece la lista de preguntas
	  	  *@param b Lista de tipo Evaluación
	  	  */
		void setListaEvaluacion(lista<Evaluacion> b);
		//Getters
		
		/**
	  	  *@brief Retorna el número de la evaluación
	  	  *@return Número de la evaluación de tipo entero 
	  	  */
		int& getI();
		
		/**
	  	  *@brief Retorna la lista de preguntas
	  	  *@return Lista de tipo Evaluación asociada a la evaluación 
	  	  */
		lista<Evaluacion> getListaEvaluacion();
};
//Setters
void Contenedor::setI(int a){
	i = a;
}
void Contenedor::setListaEvaluacion(lista<Evaluacion> b){
	c = b;
}
//Getters
int& Contenedor::getI(){
	return i;
}
lista<Evaluacion> Contenedor::getListaEvaluacion(){
	return c;
}
#endif
