#include <iostream>
#include "lista.h"
//Clases
#include "profesor.h"
#include "tema.h"
#include "llenarlistas.h"
#include "lecturaarchivos.h"
#include "escribirarchivos.h"
/*#include "evaluacion.h"
#include "contenedor.h"
#include "nota.h"
#include "corte.h"

using namespace std;
//using std::string;*/
int main(int argc, char** argv) {
	int pos=1,c=1,n=1,cont=1,e=1;
	string ap,nom;
	Profesor p;
	Corte cor;
	Nota nt;
	Contenedor ct;
	Evaluacion eva;
	LlenarListas llenarLista;
	LecturaArchivos lecArchivos;
	cor.setNombre("zzzzz");
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
	
	Tema t;
	t.setCodigo(1000);
	
	t.setNombre("temaEjemplo");
	
	//Lista profesores
	
	lista<Profesor> profesores = lista<Profesor>(p);
	
	//Lista de temas
	lista<Tema> temas = lista<Tema>(t);
	
	//Llenar temas
	temas=llenarLista.llenaTemas(temas,t);
	
	profesores=lecArchivos.lecturaProfesores(profesores);
	//Llenar profesores
	//profesores=llenaProfes(profesores);
	
	//system("cls");
	
	
	//Muestra la lista
	cout<<"Profesores"<<endl;
	for(pos=1;pos<=profesores.get_tam();pos++){
		profesores.recorrer(pos,&p);
		cout<<"Profesor:"<<endl;	
		cout<<"Cedula: "<<p.getCedula()<<endl;
		cout<<"Apellidos: "<<p.getApellidos()<<endl;
		cout<<"Nombres: "<<p.getNombres()<<endl;
		cout<<"Numero de clases: "<<p.getNumClases()<<endl;
		
		cout<<"Cortes:"<<endl;
		for(c=1;c<=(p.getListaCorte().get_tam());c++){
			p.getListaCorte().recorrer(c,&cor);
			cout<<cor.getNombre()<<": "<<endl;
			cout<<"Tipos de evaluaciones:"<<endl;
			for(n=1;n<=(cor.getListaNotas().get_tam());n++){
				cor.getListaNotas().recorrer(n,&nt);
				cout<<"Tipo: "<<nt.getTipo()<<". Porcentaje: "<<nt.getPorcentaje()<<"%"<<endl;
				cout<<"Evaluaciones: "<<endl;
				for(cont=1;cont<=(nt.getListaContenedor().get_tam());cont++){
					nt.getListaContenedor().recorrer(cont,&ct);
					cout<<"evaluacion #"<<ct.getI()<<endl;
					for(e=1;e<=(ct.getListaEvaluacion().get_tam());e++){
						ct.getListaEvaluacion().recorrer(e,&eva);
						cout<<"Porcentaje: "<<eva.getPorcentaje()<<". Tema: "<<eva.getTema()<<endl;
					}
				}
			}
		}
	}
	/*
	escribirProfesores(profesores);
	escribirCortes(profesores);
	escribirNotas(profesores);
	escribirContenedores(profesores);
	escribirEvaluaciones(profesores);*/
	
	//Muestra la lista
	/*
	while(pos<=temas.get_tam()){
		temas.recorrer(pos,&t);
		cout<< t.codigo<<" "<<t.nombre<<endl;
		pos++;
	}*/
	
	return 0;
}
