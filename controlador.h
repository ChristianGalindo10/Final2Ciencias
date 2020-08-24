/**
  *@file controlador.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase Controlador
  *@brief Clase principal que maneja el programa
  */
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>


#include "lista.h"
//Clases

#include "profesor.h"
#include "tema.h"
#include "corte.h"
#include "contenedor.h"
#include "clase.h"
#include "nota.h"
#include "evaluacion.h"
#include "curso.h"
#include "estudiante.h"
#include "llenarlistas.h"
#include "lecturaarchivos.h"
#include "escribirarchivos.h"

/**
  *@brief Clase que controla todas las listas y operaciones sobre estas
  */ 
using namespace std;
class Controlador{
	lista<Profesor> profesores; ///&lt; Lista de profesores
	lista<Tema> temas; ///&lt; Lista de temas
	lista<Curso> cursos; ///&lt; Lista de cursos
	lista<Clase> clases; ///&lt; Lista de clases
	LecturaArchivos lecArchivos; ///&lt; Instancia de LecturaArchivos
	EscribirArchivos escArchivos; ///&lt; Instancia de EscribirArchivos
	LlenarListas insertar; ///&lt; Instancia de LlenarListas
	//Paramétros necesarios para manejo de listas
	Profesor p; ///&lt; Instancia de Profesor
	Corte cor; ///&lt; Instancia de Corte
	Nota nt; ///&lt; Instancia de Nota
	Contenedor ct; ///&lt; Instancia de Contenedor
	Evaluacion eva; ///&lt; Instancia de Evaluacion
	string ap; ///&lt; string auxiliar para apellidos
	string nom; ///&lt; string auxiliar para nombres
	Tema t; ///&lt; Instancia de Tema
	Curso curso; ///&lt; Instancia de Curso
	Cur cur; ///&lt; Instancia de Cur
	lista<Cur> cs; ///&lt; Lista de tipo Cur
	Estudiante est; ///&lt; Instancia de Estudiante
	Clase clase; ///&lt; Instancia de Clase
	public:	
		/**
	  	  *@brief Constructor por defecto Controlador
	  	  */
		Controlador(){
			//Inicializar lista profesores
			p.setCedula(999999);
			ap="Apellido1 Apellido2";
			nom="Nombre1 Nombre 2";
			for(int i = 0; i<ap.length(); i++){
				p.setApellidos(i,ap[i]);
			}
			for(int i = 0; i<nom.length(); i++){
				p.setNombres(i,nom[i]);
			}
			p.setNumClases(1000);
			profesores = lista<Profesor>(p);
			
			//Inicializar lista temas
			t.setCodigo(1000);
			nom="temaEjemplo";
			for(int i = 0; i<nom.length(); i++){
				t.setNombre(i,nom[i]);
			}
			temas = lista<Tema>(t);
			curso.setCodigo("CodigoFinal");
			cursos = lista<Curso>(curso);
			clase.setCedula(10000);
			cur.curso="CodigoFinal";
			cs=lista<Cur>(cur);
			clase.setCursos(cs);
			clases=lista<Clase>(clase);
		};
		
		//Métodos para manejar listas
		
		/**
	  	  *@brief Muestra la lista de profesores
	  	  */
		void mostrarListaProfes();
		
		/**
	  	  *@brief Muestra la lista de profesores dado el número de clases ingresado
	  	  *@param c Número de clases del profesor
	  	  */
		void mostrarListaProfes(int c);
		
		/**
	  	  *@brief Muestra la lista de cortes asociada a un profesor
	  	  *@param p Profesor asociado a la lista de cortes
	  	  */
		void mostrarListaCortes(Profesor p);
		
		/**
	  	  *@brief Muestra la lista de tipos de evaluaciones asociada a un corte
	  	  *@param cor Corte asociado a lista de tipos de evaluación
	  	  */
		void mostrarListaNotas(Corte cor);
		
		/**
	  	  *@brief Muestra las evaluacios relacionadas a un tipo de evaluación
	  	  *@param nt Tipo de evaluación asociada a la lista de evaluaciones
	  	  */
		void mostrarListaContenedores(Nota nt);
		
		/**
	  	  *@brief Muestra la lista  de preguntas asociadas a una evaluación
	  	  *@param cont Evaluación asociada a las preguntas
	  	  */
		void mostrarListaEvaluaciones(Contenedor cont);
		
		/**
	  	  *@brief Muestra la lista de temas
	  	  */
		void mostrarListaTemas();
		
		/**
	  	  *@brief Muestra la lista de cursos
	  	  */
		void mostrarListaCursos();
		
		/**
	  	  *@brief Muestra la lista de estudiantes asociados a un curso
	  	  *@param c Curso que contiene a la lista de estudiantes
	  	  */
		void mostrarListaEstudiantes(Curso c);
		
		//Métodos modificación
		/**
	  	  *@brief Inserta profesores
	  	  */
		void insertarProfes();
		
		/**
	  	  *@brief Inserta temas
	  	  */
		void insertarTemas();
		
		/**
	  	  *@brief Inserta cursos
	  	  */
		void insertarCursos();
		
		/**
	  	  *@brief Inserta estudiantes
	  	  */
		void insertarEstudiantes();
		
		/**
	  	  *@brief Modifica profesores
	  	  */
		void modificarProfesor();
		
		/**
	  	  *@brief Modifica temas
	  	  */
		void modificarTemas();	
		
		/**
	  	  *@brief Elimina profesores
	  	  */
		void eliminarProfesor();	
		
		/**
	  	  *@brief Elimina estudiantes
	  	  */
		void eliminarEstudiante();
		
		/**
	  	  *@brief Elimina cursos
	  	  */
		void eliminarCurso();
		
		/**
	  	  *@brief Elimina temas
	  	  */
		void eliminarTema();
		
		//Métodos profesores
		/**
	  	  *@brief Retorna la lista de profesores
	  	  *@return Lista de tipo Profesor
	  	  */
		lista<Profesor> getProfes();
		
		/**
	  	  *@brief Lee los profesores desde archivos
	  	  */
		void leerProfes();
		
		/**
	  	  *@brief Establece la lista de profesores
	  	  *@param ps lista de tipo Profesor
	  	  */
		void setProfes(lista<Profesor> ps);
		
		//Métodos temas
		
		/**
	  	  *@brief Retorna la lista de temas
	  	  *@return lista de tipo Tema
	  	  */
		lista<Tema> getTemas();
		
		/**
	  	  *@brief Lee los temas desde archivos
	  	  */
		void leerTemas();
		
		/**
	  	  *@brief Establece la lista de temas
	  	  *@param ts Lista de tipo Tema
	  	  */
		void setTemas(lista<Tema> ts);
		
		//Métodos Cursos
		
		/**
	  	  *@brief Retorna la lista de cursos
	  	  *@return lista de tipo Curso
	  	  */
		lista<Curso> getCursos();
		
		/**
	  	  *@brief Establece la lista de cursos
	  	  *@param cs lista de tipo Curso
	  	  */
		void setCursos(lista<Curso> cs);
		
		/**
	  	  *@brief Lee los cursos desde archivos
	  	  */
		void leerCursos(); 
		
		//Métodos de escritura
		
		/**
	  	  *@brief Escribe todas las listas en archivos en el disco
	  	  */
		void escribirArchivos();
		
		//Métodos de clases
		void llenarClases();
		void mostrarClases();
		
};

void Controlador::mostrarClases(){
	llenarClases();
	for(int i=1;i<=clases.get_tam();i++){
		clases.recorrer(i,&clase);
		cout<<clase.getCedula()<<": "<<endl;
		for(int j=1;j<=clase.getCursos().get_tam();j++){
			clase.getCursos().recorrer(j,&cur);
			cout<<cur.curso<<endl;
		}
	}
}

void Controlador::llenarClases(){
	clases=insertar.llenarClases(profesores,cursos,clases,cs);
}

void Controlador::escribirArchivos(){
	escArchivos.escribir(profesores,temas,cursos);
}

lista<Profesor> Controlador::getProfes(){
	return profesores;
}

void Controlador::leerProfes(){
	profesores=lecArchivos.lecturaProfesores(profesores);
}

void Controlador::setProfes(lista<Profesor> ps){
	profesores=ps;
}

void Controlador::leerCursos(){
	cursos=lecArchivos.lecturaCursos(cursos);
}

void Controlador::setCursos(lista<Curso> cs){
	cursos=cs;
}

lista<Curso> Controlador::getCursos(){
	return cursos;
}


lista<Tema> Controlador::getTemas(){
	return temas;
}

void Controlador::leerTemas(){
	temas=lecArchivos.lecturaTemas(temas);
}

void Controlador::setTemas(lista<Tema> ts){
	temas=ts;
}

void Controlador::mostrarListaCursos(){
	int pos;
	for(int i=1;i<=cursos.get_tam();i++){
		cursos.recorrer(i,&curso);
		cout<<i<<". "<<curso.getCodigo()<<endl;
		//cout<<"Estudiantes: "<<endl;
		//mostrarListaEstudiantes(curso);
	}
	cout<<"Digite la posición del curso del cual desea ver los estudiantes: ";
	cin>>pos;
	cursos.buscar(pos,&curso);
	mostrarListaEstudiantes(curso);
}

void Controlador::mostrarListaEstudiantes(Curso c){
	for(int i=1;i<=c.getListaEstudiantes().get_tam();i++){
		c.getListaEstudiantes().recorrer(i,&est);
		cout<<"Codigo: "<<est.getCodigo()<<" Apellidos: "<<est.getApellidos()<<" Nombres: "<<est.getNombres()<<endl;
	}
}

void Controlador::mostrarListaProfes(){
	cout<<"Profes:"<<endl;
	if(profesores.get_tam()==0){
		cout<<"Lista vacia";
	}
	for(int pos=1;pos<=profesores.get_tam();pos++){
		profesores.recorrer(pos,&p);
		cout<<"Profesor:"<<endl;	
		cout<<"Cedula: "<<p.getCedula()<<endl;
		cout<<"Apellidos: "<<p.getApellidos()<<endl;
		cout<<"Nombres: "<<p.getNombres()<<endl;
		cout<<"Numero de Clases: "<<p.getNumClases()<<endl;
		mostrarListaCortes(p);
	}
}

void Controlador::mostrarListaProfes(int c){
	cout<<"Profes:"<<endl;
	if(profesores.get_tam()==0){
		cout<<"Lista vacia";
	}
	for(int pos=1;pos<=profesores.get_tam();pos++){
		profesores.recorrer(pos,&p);
		if(p.getNumClases()==c){
			cout<<"Profesor:"<<endl;	
			cout<<"Cedula: "<<p.getCedula()<<endl;
			cout<<"Apellidos: "<<p.getApellidos()<<endl;
			cout<<"Nombres: "<<p.getNombres()<<endl;
			cout<<"Numero de Clases: "<<p.getNumClases()<<endl;
			mostrarListaCortes(p);
		}
	}
}

void Controlador::mostrarListaCortes(Profesor p){
	cout<<"Cortes:"<<endl;
	for(int c=1;c<=(p.getListaCorte().get_tam());c++){
		p.getListaCorte().recorrer(c,&cor);
		cout<<cor.getNombre()<<": "<<endl;
		mostrarListaNotas(cor);
	}
}

void Controlador::mostrarListaNotas(Corte cor){
	cout<<"Tipos de evaluaciones:"<<endl;
	for(int n=1;n<=(cor.getListaNotas().get_tam());n++){
		cor.getListaNotas().recorrer(n,&nt);
		cout<<"Tipo: "<<nt.getTipo()<<". Porcentaje: "<<nt.getPorcentaje()<<"%"<<endl;
		mostrarListaContenedores(nt);
	}
}
		
void Controlador::mostrarListaContenedores(Nota nt){
	cout<<"Evaluaciones: "<<endl;
	for(int cont=1;cont<=(nt.getListaContenedor().get_tam());cont++){
		nt.getListaContenedor().recorrer(cont,&ct);
		cout<<"evaluacion #"<<ct.getI()<<endl;
		mostrarListaEvaluaciones(ct);
	}	
}

void Controlador::mostrarListaEvaluaciones(Contenedor ct){
	for(int e=1;e<=(ct.getListaEvaluacion().get_tam());e++){
		ct.getListaEvaluacion().recorrer(e,&eva);
		cout<<"Porcentaje: "<<eva.getPorcentaje()<<". Tema: "<<eva.getTema()<<endl;
	}
}

void Controlador::mostrarListaTemas(){
	for(int i=1;i<=temas.get_tam();i++){
		temas.recorrer(i,&t);
		cout<<t.getCodigo()<<". "<<t.getNombre()<<endl;
	}
}

void Controlador::insertarProfes(){
	profesores=insertar.llenaProfes(profesores);
}

void Controlador::insertarTemas(){
	temas=insertar.llenaTemas(temas);
}

void Controlador::modificarProfesor(){
	profesores=insertar.modificarProfe(profesores);
}

void Controlador::modificarTemas(){
	temas=insertar.modificarTema(temas);
}

void Controlador::eliminarProfesor(){
	profesores=insertar.eliminarProfesor(profesores);
}


void Controlador::insertarCursos(){
	cursos=insertar.llenaCursos(cursos);
}

void Controlador::insertarEstudiantes(){
	int cod;
	for(int i=1;i<=cursos.get_tam();i++){
		cursos.recorrer(i,&curso);
		cout<<i<<". "<<curso.getCodigo()<<endl;
	}
	cout<<"Digite la posicion de la Curso en la cual desea insertar el estudiante: ";
	cin>>cod;	
	cursos.buscar(cod,&curso);
	curso.setListaEstudiantes(insertar.llenaEstudiantes(curso.getListaEstudiantes()));
	cursos.cambiar(cod,curso);
	mostrarListaEstudiantes(curso);
}

void Controlador::eliminarCurso(){
	cursos=insertar.eliminarCurso(cursos);
}

void Controlador::eliminarEstudiante(){
	int cod;
	for(int i=1;i<=cursos.get_tam();i++){
		cursos.recorrer(i,&curso);
		cout<<i<<". "<<curso.getCodigo()<<endl;
	}
	cout<<"Digite la posicion de la Curso en la cual desea insertar el estudiante: ";
	cin>>cod;	
	cursos.buscar(cod,&curso);
	curso.setListaEstudiantes(insertar.eliminarEstudiante(curso.getListaEstudiantes()));
	cursos.cambiar(cod,curso);
}

void Controlador::eliminarTema(){
	temas=insertar.eliminarTema(temas);
}

#endif
