/**
  *@file evaluacion.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase Evaluacion
  *@brief Clase que representa una pregunta.
  */

#ifndef EVALUACION_H     
#define EVALUACION_H

/**
  *@brief Clase para manejar los datos relacionados a una pregunta
  */ 
class Evaluacion{
		int porcentaje; ///&lt; Porcentaje de la pregunta
		int tema; ///&lt; Tema de la pregunta
	public:
		//Setters
		/**
	  	  *@brief Establece el porcentaje de la pregunta
	  	  *@param porcen Procentaje de la pregunta tipo entero
	  	  */
		void setPorcentaje(int porcen);
		
		/**
	  	  *@brief Establece el tema de la pregunta
	  	  *@param t Tema de la pregunta tipo entero
	  	  */
		void setTema(int t);
		//Getters
		/**
	  	  *@brief Retorna el tema de la pregunta
	  	  *@return Tema de la pregunta de tipo entero
	  	  */
		int& getTema();
		
		/**
	  	  *@brief Retorna el porcentaje de la pregunta
	  	  *@return Porcentaje de la pregunta de tipo entero
	  	  */
		int& getPorcentaje();
};
//Setters
void Evaluacion::setPorcentaje(int porcen){
	porcentaje = porcen;
}
void Evaluacion::setTema(int t){
	tema = t;
}
//Getters
int& Evaluacion::getTema(){
	return tema;
}
int& Evaluacion::getPorcentaje(){
	return porcentaje;
}
#endif
