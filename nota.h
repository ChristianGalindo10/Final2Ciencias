/**
  *@file nota.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase Nota
  *@brief Clase para representar un tipo de evaluación dentro del programa
  */

#ifndef NOTA_H     
#define NOTA_H
#include "contenedor.h"

/**
  *@brief Clase para manejar los datos relacionados a un tipo de evaluación
  */
class Nota{
		string tipo; ///&lt; Tipo de evaluación
		int porcentaje; ///&lt; Porcentaje relacionado al tipo de evaluación
		lista<Contenedor> evaluaciones; ///&lt; Lista de tipo Contenedor para guardar cada evaluación correspondiente
	public:
		//Setters
		/**
	  	  *@brief Establece el porcentaje relacionado al tipo de evaluación
	  	  *@param porcen Procentaje del tipo de evaluación
	  	  */
		void setPorcentaje(int porcen);
		
		/**
	  	  *@brief Establece el tipo de evaluación
	  	  *@param t Tipo de evaluación
	  	  */
		void setTipo(string t);
		
		/**
	  	  *@brief Establece la lista de contenedores
	  	  *@param eval Lista de tipo Contenedor
	  	  */
		void setListaContenedor(lista<Contenedor> eval);
		//Getters
		/**
	  	  *@brief Retorna el porcentaje del tipo de evaluación
	  	  *@return Porcentaje del tipo de evaluación tipo entero
	  	  */
		int& getPorcentaje();
		
		/**
	  	  *@brief Retorna el tipo de evaluación
	  	  *@return Tipo de evaluación tipo string
	  	  */
		string getTipo();
		
		/**
	  	  *@brief Retorna la lista de contenedores relacionada al tipo de evaluación 
	  	  *@return Lista de tipo Contenedor asociada al tipo de evaluación
	  	  */
		lista<Contenedor> getListaContenedor();
};
//Setters
void Nota::setPorcentaje(int porcen){
	porcentaje=porcen;
}
void Nota::setTipo(string t){
	tipo = t;
}
void Nota::setListaContenedor(lista<Contenedor> eval){
	evaluaciones=eval;
}
//Getters
int& Nota::getPorcentaje(){
	return porcentaje;
}
string Nota::getTipo(){
	return tipo;
}
lista<Contenedor> Nota::getListaContenedor(){
	return evaluaciones;
}
#endif
