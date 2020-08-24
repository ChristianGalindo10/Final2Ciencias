/**
  *@file escribirarchivos.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase EscribirArchivos
  *@brief Clase para escribir los archivos en disco
  */

#ifndef ESCRIBIRARCHIVOS_H
#define ESCRIBIRARCHIVOS_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "profesor.h"

/**
  *@brief Clase para escribir los archivos en disco luego de terminada la ejecucución del programa
  */ 
class EscribirArchivos{
	public:
		/**
	  	  *@brief Escribe todos los archivos necesarios
	  	  */
		void escribir(lista<Profesor> ps, lista<Tema> ts, lista<Curso> cs);
		
		/**
	  	  *@brief Escribe los profesores
	  	  *@param ps Lista de tipo Profesor a escribir en los archivos
	  	  */
		void escribirProfesores(lista<Profesor> ps);
		
		/**
	  	  *@brief Escribe los cortes relacionados a cada profesor
	  	  *@param ps Lista de tipo Profesor a escribir en los archivos
	  	  */
		void escribirCortes(lista<Profesor> ps);
		
		/**
	  	  *@brief Escribe los tipos de evaluación asociados a cada corte
	  	  *@param ps Lista de tipo Profesor a escribir en los archivos
	  	  */
		void escribirNotas(lista<Profesor> ps);
		
		/**
	  	  *@brief Escribe las evaluaciones asociadas a cada tipo de evaluación
	  	  *@param ps Lista de tipo Profesor a escribir en los archivos
	  	  */
		void escribirContenedores(lista<Profesor> ps);
		
		/**
	  	  *@brief Escribe las preguntas asociadas a una evaluación
	  	  *@param ps Lista de tipo Profesor a escribir en los archivos
	  	  */
		void escribirEvaluaciones(lista<Profesor> ps);
		
		/**
	  	  *@brief Escribe los temas
	  	  *@param ts Lista de tipo Tema a escribir en los archivos
	  	  */
		void escribirTemas(lista<Tema> ts);
		
		/**
	  	  *@brief Escribe los cursos
	  	  *@param cs Lista de tipo Curso a escribir en los archivos
	  	  */
		void escribirCursos(lista<Curso> cs);
		
		/**
	  	  *@brief Escribe los estudiantes asociados a un curso
	  	  *@param cs Lista de tipo Curso a escribir en los archivos
	  	  */
		void escribirEstudiantes(lista<Curso> cs);
};

void EscribirArchivos::escribir(lista<Profesor> ps, lista<Tema> ts, lista<Curso> cs){
	escribirProfesores(ps);
	escribirCortes(ps);
	escribirNotas(ps);
	escribirContenedores(ps);
	escribirEvaluaciones(ps);
	escribirTemas(ts);
	escribirCursos(cs);
	escribirEstudiantes(cs);
}

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


void EscribirArchivos::escribirTemas(lista<Tema> ts){
	ofstream archivo;
	Tema t;
	archivo.open("archivos//Temas//temas.txt",ios::out); //Abrir archivo
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	for(int pos=1;pos<=ts.get_tam();pos++){
		ts.recorrer(pos,&t);
		archivo<<t.getCodigo()<<","<<t.getNombre()<<endl;
	}
	
	archivo.close();
}

void EscribirArchivos::escribirCursos(lista<Curso> cs){
	ofstream archivo;
	Curso c;
	archivo.open("archivos//Clases//clases.txt",ios::out); //Abrir archivo
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	for(int pos=1;pos<=cs.get_tam();pos++){
		cs.recorrer(pos,&c);
		archivo<<c.getProfesor()<<c.getCodigo()<<endl;
	}
	archivo.close();
}

void EscribirArchivos::escribirEstudiantes(lista<Curso> cs){
	Curso cl;
	Estudiante e;
	for(int pos=1;pos<=cs.get_tam();pos++){
		cs.recorrer(pos,&cl);
		ofstream archivo;
		ostringstream ss;
		ss << cl.getCodigo();
		string ruta;
		ruta="archivos//Estudiantes//"+ss.str()+"estudiantes.txt";
		archivo.open(ruta.c_str(),ios::out);
		for(int c=1;c<=cl.getListaEstudiantes().get_tam();c++){
			cl.getListaEstudiantes().recorrer(c,&e);
			archivo<<e.getCodigo()<<","<<e.getApellidos()<<","<<e.getNombres()<<endl;
		}
		archivo.close();	
	}
}


#endif

