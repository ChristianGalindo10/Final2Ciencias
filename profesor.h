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
			void setCedula(int cc);
			void setApellidos(int pos, char letra);
			void setNombres(int pos, char letra);
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
void Profesor::setCedula(int cc){
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
//
/*
void Profesor::escribirProfesores(lista<x> ps){
	ofstream archivo;
	Profesor p;
	archivo.open("archivos//Profesores//profesores.txt",ios::out); //Abrir archivo
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		archivo<<p.cedula<<","<<p.apellidos<<","<<p.nombres<<","<<p.numClases<<endl;
	}
	
	archivo.close();
}
lista<Profesor> Profesor::llenaProfes(lista<Profesor> ps){
	int d=1,c=0;
	corte cor;
	cor.nombre="CorteFinalFinal";
	while(d!=0){
		lista<corte> cortes = lista<corte>(cor);
		Profesor p;
		cout<<"Digite los nombres del profesor: ";
		//cin.ignore();
		cin.getline(p.nombres, 50);
		cout<<"Digite los apellidos del profesor: ";
		//cin.ignore();
		cin.getline(p.apellidos, 50);
		cout<<"Digite la cedula del profesor: ";
		cin>>p.cedula;
		cout<<"Digite el numero de clases del profesor: ";
		cin>>p.numClases;
		cout<<"Desea ingresar los cortes correspondientes al profesor? Si=1,No=0"<<endl;
		cin>>c;
		if(c==1){
			cortes = llenaCortes(cortes);
		}
		p.cortes=cortes;
		ps.insertarOrd(p,p.cedula);
		cout<<"Desea ingresar otro profesor: Si=1,No=0"<<endl;
		cin>>d;
		cin.ignore();
	}
	return ps;
}*/
#endif
