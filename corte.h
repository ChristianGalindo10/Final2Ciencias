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
		
		/*
		void escribirCortes(lista<Profesor> ps);
		lista<corte> llenaCortes(lista<corte> cs);*/
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
/*
void corte::escribirCortes(lista<profesor> ps){
	Profesor p;
	corte cor;
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		ofstream archivo;
		ostringstream ss;
		ss << p.cedula;
		string ruta;
		ruta="archivos//Cortes//"+ss.str()+"cortes.txt";
		archivo.open(ruta.c_str(),ios::out);
		for(int c=1;c<=p.cortes.get_tam();c++){
			p.cortes.recorrer(c,&cor);
			archivo<<cor.nombre<<endl;
		}
		archivo.close();	
	}
}
lista<corte> corte::llenaCortes(lista<corte> cs){
	int c=1,e=0;
	nota n;
	n.porcentaje=1000;
	n.tipo="TipoEjemplo";
	while(c!=0){
		lista<nota> notas = lista<nota>(n);
		corte cor;
		cout<<"Digite el nombre del corte: ";
		cin>>cor.nombre;
		cout<<"Desea insertar los tipos de evaluación con su repectivo porcentaje? Si=1, No=0"<<endl;
		cin>>e;
		if(e==1){
			notas=llenaNotas(notas);
		} 
		cor.evaluaciones=notas;
		cs.insertarOrd(cor,cs.get_tam()+1);
		cout<<"Desea ingresar otro corte? Si=1, No=0"<<endl;
		cin>>c;
	}
	return cs;
}*/
#endif
