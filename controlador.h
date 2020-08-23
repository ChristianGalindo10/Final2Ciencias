#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>


#include "lista.h"
//Clases

#include "profesor.h"
#include "tema.h"
#include "corte.h"
#include "contenedor.h"
#include "nota.h"
#include "evaluacion.h"
#include "curso.h"
#include "estudiante.h"
#include "llenarlistas.h"
#include "lecturaarchivos.h"
#include "escribirarchivos.h"


using namespace std;
class Controlador{
	lista<Profesor> profesores;
	lista<Tema> temas;
	lista<Curso> cursos;
	LecturaArchivos lecArchivos;
	EscribirArchivos escArchivos;
	LlenarListas insertar;
	//Paramétros necesarios para manejo de listas
	Profesor p;
	Corte cor;
	Nota nt;
	Contenedor ct;
	Evaluacion eva;
	string ap;
	string nom;
	Tema t;
	Curso curso;
	Estudiante est;
	public:	
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
			
		};
		//Métodos para manejar listas
		void mostrarListaProfes();
		void mostrarListaProfes(int c);
		void mostrarListaCortes(Profesor p);
		void mostrarListaNotas(Corte cor);
		void mostrarListaContenedores(Nota nt);
		void mostrarListaEvaluaciones(Contenedor cont);
		void mostrarListaTemas();
		void mostrarListaCursos();
		void mostrarListaEstudiantes(Curso c);
		
		//Métodos modificación
		void insertarProfes();
		void insertarTemas();
		void insertarCursos();
		void insertarEstudiantes();
		void modificarProfesor();
		void modificarTemas();	
		void eliminarProfesor();	
		void eliminarEstudiante();
		void eliminarCurso();
		void eliminarTema();
		
		//Métodos profesores
		lista<Profesor> getProfes();
		void leerProfes();
		void setProfes(lista<Profesor> ps);
		
		//Métodos temas
		lista<Tema> getTemas();
		void leerTemas();
		void setTemas(lista<Tema> ts);
		
		//Métodos Cursos
		lista<Curso> getCursos();
		void setCursos(lista<Curso> cs);
		void leerCursos(); 
		
		//Métodos de escritura
		void escribirArchivos();
		
		//Métodos de clases
		void llenarClases();
		
};

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
