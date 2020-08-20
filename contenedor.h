#ifndef CONTENEDOR_H     
#define CONTENEDOR_H
#include "lista.h"
#include "evaluacion.h"

class Contenedor{
		int i;
		lista<Evaluacion> c;
	public:
		//Setters
		void setI(int a);
		void setListaEvaluacion(lista<Evaluacion> b);
		//Getters
		int& getI();
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
