#include <iostream>
#include "lista.h"
//Clases
#include "profesor.h"
#include "tema.h"
#include "llenarlistas.h"
#include "lecturaarchivos.h"
/*#include "evaluacion.h"
#include "contenedor.h"
#include "nota.h"
#include "corte.h"

using namespace std;
//using std::string;*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Estructuras

//Funciones para manejo de archivos
//void escribirProfesores(lista<profesor> ps);
//void escribirCortes(lista<profesor> ps);
//void escribirNotas(lista<profesor> ps);
//void escribirContenedores(lista<profesor> ps);
//void escribirEvaluaciones(lista<profesor> ps);

/*void escribirProfesores(lista<profesor> ps){
	ofstream archivo;
	profesor p;
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
}*/

/*void escribirCortes(lista<profesor> ps){
	profesor p;
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
}*/

/*void escribirNotas(lista<profesor> ps){
	profesor p;
	corte cor;
	nota nt;
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		ostringstream ss;
		ss << p.cedula;
		string ruta;
		for(int c=1;c<=p.cortes.get_tam();c++){
			p.cortes.recorrer(c,&cor);
			ofstream archivo;
			ruta="archivos//TiposEvaluacion//"+ss.str()+cor.nombre+"tiposEval.txt";
			archivo.open(ruta.c_str(),ios::out);
			for(int n=1;n<=cor.evaluaciones.get_tam();n++){
				cor.evaluaciones.recorrer(n,&nt);
				archivo<<nt.tipo<<","<<nt.porcentaje<<endl;
			}
			archivo.close();
		}
	}
}*/

/*void escribirContenedores(lista<profesor> ps){
	profesor p;
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
}*/

/*void escribirEvaluaciones(lista<profesor> ps){
	profesor p;
	corte cor;
	nota nt;
	contenedor cont;
	evaluacion eva;
	for(int pos=1;pos<=ps.get_tam();pos++){
		ps.recorrer(pos,&p);
		ostringstream ss;
		ss << p.cedula;
		string ruta;
		for(int c=1;c<=p.cortes.get_tam();c++){
			p.cortes.recorrer(c,&cor);
			for(int n=1;n<=cor.evaluaciones.get_tam();n++){
				cor.evaluaciones.recorrer(n,&nt);
				for(int ct=1;ct<=nt.evaluaciones.get_tam();ct++){
					nt.evaluaciones.recorrer(ct,&cont);
					ostringstream ss2;
					ss2 << cont.i;
					ofstream archivo;
					ruta="archivos//Evaluaciones//"+ss.str()+cor.nombre+nt.tipo+ss2.str()+"preguntas.txt";
					archivo.open(ruta.c_str(),ios::out);
					for(int e=1;e<=cont.c.get_tam();e++){
						cont.c.recorrer(e,&eva);
						archivo<<eva.tema<<","<<eva.porcentaje<<endl;
					}
					archivo.close();
				}
			}
		}
	}
}*/

//Prototipos funciones de llenado
//lista<tema> llenaTemas(lista<tema> ts,tema t);
//lista<profesor> llenaProfes(lista<profesor> ps);
//lista<corte> llenaCortes(lista<corte> cs);
//lista<nota> llenaNotas(lista<nota> ns);
//lista<contenedor> llenaContenedores(lista<contenedor> cs);
//lista<evaluacion> llenaEvaluaciones(lista<evaluacion> es);




//Implementación funciones de llenado
/*lista<tema> llenaTemas(lista<tema> ts,tema t){
	t.codigo=1;
	t.nombre="tipos de algoritmos";
	ts.insertarOrd(t,t.codigo);
	
	t.codigo=2;
	t.nombre="complejidad en memoria";
	ts.insertarOrd(t,t.codigo);
	
	t.codigo=3;
	t.nombre="complejidad en tiempo";
	ts.insertarOrd(t,t.codigo);
	
	t.codigo=6;
	t.nombre="Definicion de orden";
	ts.insertarOrd(t,t.codigo);
	
	t.codigo=8;
	t.nombre="Demostraciones";
	ts.insertarOrd(t,t.codigo);
	return ts;
}*/

/*lista<corte> llenaCortes(lista<corte> cs){
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

/*lista<nota> llenaNotas(lista<nota> ns){
	int nc=1,e=1;
	contenedor cont;
	cont.i=9999999;
	while(nc!=0){
		lista<contenedor> contenedores = lista<contenedor>(cont);
		nota n;
		cout<<"Digite el tipo de evaluacion: ";
		cin>>n.tipo;
		cout<<endl;
		cout<<"Digite el porcentaje de evaluacion: ";
		cin>>n.porcentaje;
		cout<<endl;
		cout<<"Desea insertar evaluaciones? Si=1, No=0"<<endl;
		cin>>e;
		if(e==1){
			contenedores = llenaContenedores(contenedores);
		}
		n.evaluaciones=contenedores;
		ns.insertarOrd(n,ns.get_tam()+1);
		cout<<"Desea ingresar otro tipo de evaluacion? Si=1, No=0"<<endl;
		cin>>nc;
	}
	return ns;
}*/

/*lista<contenedor> llenaContenedores(lista<contenedor> cs){
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

/*lista<evaluacion> llenaEvaluaciones(lista<evaluacion> es){
	int e=1;
	while(e!=0){
		evaluacion eva;
		cout<<"Insertando pregunta "<<es.get_tam()+1<<endl;
		cout<<"Inserte porcentaje: ";
		cin>>eva.porcentaje;
		cout<<endl;
		cout<<"Inserte tema: ";
		cin>>eva.tema;
		es.insertarOrd(eva,es.get_tam()+1);
		cout<<"Desea insertar otra pregunta? Si=1,No=0"<<endl;
		cin>>e;
	}
	return es;
}*/

/*lista<profesor> llenaProfes(lista<profesor> ps){
	int d=1,c=0;
	corte cor;
	cor.nombre="CorteFinalFinal";
	while(d!=0){
		lista<corte> cortes = lista<corte>(cor);
		profesor p;
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
	return ps;*/
//}

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
