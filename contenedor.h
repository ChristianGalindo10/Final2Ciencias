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
		
		/*void escribirContenedores(lista<Profesor> ps);
		lista<contenedor> llenaContenedores(lista<contenedor> cs);*/
		
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
/*
void contenedor::escribirContenedores(lista<Profesor> ps){
	Profesor p;
	corte cor;
	nota nt;
	contenedor cont;
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		ostringstream ss;
		ss << p.cedula;
		string ruta;
		for(int c=1;c<=p.cortes.get_tam();c++){
			p.cortes.recorrer(c,&cor);
			for(int n=1;n<=cor.evaluaciones.get_tam();n++){
				cor.evaluaciones.recorrer(n,&nt);
				ofstream archivo;
				ruta="archivos//Contenedores//"+ss.str()+cor.nombre+nt.tipo+".txt";
				archivo.open(ruta.c_str(),ios::out);
				for(int ct=1;ct<=nt.evaluaciones.get_tam();ct++){
					nt.evaluaciones.recorrer(ct,&cont);
					archivo<<cont.i<<endl;
				}
				archivo.close();
			}
		}
	}
}
lista<contenedor> contenedor::llenaContenedores(lista<contenedor> cs){
	int c=1;
	evaluacion eva;
	eva.porcentaje=99999;
	eva.tema=1000;
	while(c!=0){
		lista<evaluacion> evaluaciones = lista<evaluacion>(eva);
		contenedor cont;
		cont.i=cs.get_tam()+1;
		cout<<"Insertando evaluacion #"<<cont.i<<endl;
		evaluaciones=llenaEvaluaciones(evaluaciones);
		cont.c=evaluaciones;
		cs.insertarOrd(cont,cont.i);
		cout<<"Desea insertar otra evaluacion de este tipo? Si=1,No=0"<<endl;
		cin>>c;
	}
	return cs;
}*/
#endif
