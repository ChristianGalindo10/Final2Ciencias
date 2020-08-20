#ifndef CORTE_H     
#define CORTE_H
#include "lista.h"
#include "nota.h"

class Corte{
		string nombre;
		lista<Nota> evaluaciones;
	public:
		//Setters
		void setNombre(string nom);
		void setEvaluaciones(lista<Nota> eval);
		//Getters
		string getNombre();
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
