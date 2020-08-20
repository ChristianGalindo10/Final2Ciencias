#ifndef PROFESOR_H     
#define PROFESOR_H
#include "lista.h"
#include "corte.h"

class Profesor{
			long long int cedula;
			char apellidos[50];
			char nombres[50];
			int numClases;
			lista<Corte> cortes;
	public:
			Profesor(){
			};
			//Setters
			void setCedula(long long int cc);
			void setApellidos(int pos, char letra);
			void setApellidos(char &apell);
			void setNombres(int pos, char letra);
			void setNombres(char &nom);
			void setNumClases(int num);
			void setListaCorte(lista<Corte> cor);
			//Getters
			lista<Corte> getListaCorte();
			long long int& getCedula();
			char* getApellidos();
			char* getNombres();
			int& getNumClases();
};

//Setters
void Profesor::setCedula(long long int cc){
	cedula=cc;
}
void Profesor::setApellidos(char &apell){
	*apellidos = apell;
}
void Profesor::setApellidos(int pos, char letra){
	apellidos[pos]=letra;
}
void Profesor::setNombres(char &nom){
	*nombres=nom;
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
