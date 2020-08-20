#ifndef ESCRIBIRARCHIVOS_H
#define ESCRIBIRARCHIVOS_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "profesor.h"
class EscribirArchivos{
	public:
		void escribirProfesores(lista<Profesor> ps);
		void escribirCortes(lista<Profesor> ps);
		void escribirNotas(lista<Profesor> ps);
		void escribirContenedores(lista<Profesor> ps);
		void escribirEvaluaciones(lista<Profesor> ps);
};
void EscribirArchivos::escribirProfesores(lista<Profesor> ps){
	ofstream archivo;
	Profesor p;
	archivo.open("archivos//Profesores//profesores.txt",ios::out); //Abrir archivo
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		archivo<<p.getCedula()<<","<<p.getApellidos()<<","<<p.getNombres()<<","<<p.getNumClases()<<endl;
	}
	
	archivo.close();
}
void EscribirArchivos::escribirCortes(lista<Profesor> ps){
	Profesor p;
	Corte cor;
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		ofstream archivo;
		ostringstream ss;
		ss << p.getCedula();
		string ruta;
		ruta="archivos//Cortes//"+ss.str()+"cortes.txt";
		archivo.open(ruta.c_str(),ios::out);
		for(int c=1;c<=p.getListaCorte().get_tam();c++){
			p.getListaCorte().recorrer(c,&cor);
			archivo<<cor.getNombre()<<endl;
		}
		archivo.close();	
	}
	
}
void EscribirArchivos::escribirNotas(lista<Profesor> ps){
	Profesor p;
	Corte cor;
	Nota nt;
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		ostringstream ss;
		ss << p.getCedula();
		string ruta;
		for(int c=1;c<=p.getListaCorte().get_tam();c++){
			p.getListaCorte().recorrer(c,&cor);
			ofstream archivo;
			ruta="archivos//TiposEvaluacion//"+ss.str()+cor.getNombre()+"tiposEval.txt";
			archivo.open(ruta.c_str(),ios::out);
			for(int n=1;n<=cor.getListaNotas().get_tam();n++){
				cor.getListaNotas().recorrer(n,&nt);
				archivo<<nt.getTipo()<<","<<nt.getPorcentaje()<<endl;
			}
			archivo.close();
		}
	}
}
void EscribirArchivos::escribirContenedores(lista<Profesor> ps){
	Profesor p;
	Corte cor;
	Nota nt;
	Contenedor cont;
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		ostringstream ss;
		ss << p.getCedula();
		string ruta;
		for(int c=1;c<=p.getListaCorte().get_tam();c++){
			p.getListaCorte().recorrer(c,&cor);
			for(int n=1;n<=cor.getListaNotas().get_tam();n++){
				cor.getListaNotas().recorrer(n,&nt);
				ofstream archivo;
				ruta="archivos//Contenedores//"+ss.str()+cor.getNombre()+nt.getTipo()+".txt";
				archivo.open(ruta.c_str(),ios::out);
				for(int ct=1;ct<=nt.getListaContenedor().get_tam();ct++){
					nt.getListaContenedor().recorrer(ct,&cont);
					archivo<<cont.getI()<<endl;
				}
				archivo.close();
			}
		}
	}
}
void EscribirArchivos::escribirEvaluaciones(lista<Profesor> ps){
	Profesor p;
	Corte cor;
	Nota nt;
	Contenedor cont;
	Evaluacion eva;
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		ostringstream ss;
		ss << p.getCedula();
		string ruta;
		for(int c=1;c<=p.getListaCorte().get_tam();c++){
			p.getListaCorte().recorrer(c,&cor);
			for(int n=1;n<=cor.getListaNotas().get_tam();n++){
				cor.getListaNotas().recorrer(n,&nt);
				for(int ct=1;ct<=nt.getListaContenedor().get_tam();ct++){
					nt.getListaContenedor().recorrer(ct,&cont);
					ostringstream ss2;
					ss2 << cont.getI();
					ofstream archivo;
					ruta="archivos//Evaluaciones//"+ss.str()+cor.getNombre()+nt.getTipo()+ss2.str()+"preguntas.txt";
					archivo.open(ruta.c_str(),ios::out);
					for(int e=1;e<=cont.getListaEvaluacion().get_tam();e++){
						cont.getListaEvaluacion().recorrer(e,&eva);
						archivo<<eva.getTema()<<","<<eva.getPorcentaje()<<endl;
					}
					archivo.close();
				}
			}
		}
	}
}
#endif

