/**
  *@file corte.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase Corte
  *@brief Clase para representar un corte dentro del programa
  */
#ifndef CORTE_H     
#define CORTE_H
#include "lista.h"
#include "nota.h"

/**
  *@brief Clase para manejar los datos relacionados a un corte asociado a un profesor
  */ 
class Corte{
		string nombre; ///&lt; Nombre del corte
		lista<Nota> evaluaciones; ///&lt; Lista de tipos de evaluación asociada
	public:
		//Setters
		
		/**
	  	  *@brief Establece el nombre del corte
	  	  *@param nom Nombre del corte
	  	  */
		void setNombre(string nom);
		
		/**
	  	  *@brief Establece la lista de tipos de evaluación
	  	  *@param eval Lista de tipo Nota
	  	  */
		void setEvaluaciones(lista<Nota> eval);
		//Getters
		
		/**
	  	  *@brief Retorna el nombre del corte
	  	  *@return Nombre del corte de tipo string
	  	  */
		string getNombre();
		
		/**
	  	  *@brief Retorna la lista de tipos de evaluación
	  	  *@return Lista de tipo Nota asociada al corte 
	  	  */
		lista<Nota> getListaNotas();
};
//Setters
void Corte::setNombre(string nom){
	nombre=nom;
}
void Corte::setEvaluaciones(lista<Nota> eval){
	evaluaciones=eval;
}
//Getters
string Corte::getNombre(){
	return nombre;
}
lista<Nota> Corte::getListaNotas(){
	return evaluaciones;
}
#endif
