#ifndef NOTA_H     
#define NOTA_H
#include "contenedor.h"

class Nota{
		string tipo;
		int porcentaje;
		lista<Contenedor> evaluaciones;
	public:
		//Setters
		void setPorcentaje(int porcen);
		void setTipo(string t);
		void setListaContenedor(lista<Contenedor> eval);
		//Getters
		int& getPorcentaje();
		string getTipo();
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
