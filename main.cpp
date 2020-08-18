#include <iostream>
#include <string>
#include <sstream>
#include "lista.h"
#include "Cola.h"
#include <fstream>

using namespace std;
//using std::string;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Estructuras

struct evaluacion{
	int porcentaje;
	int tema;
};
//

struct contenedor{
	int i;
	lista<evaluacion> c;
};

struct nota{
	string tipo;
	int porcentaje;
	lista<contenedor> evaluaciones;
};

struct corte{
	string nombre;
	lista<nota> evaluaciones;
};

struct profesor{
	long long int cedula;
	char apellidos[50];
	char nombres[50];
	int numClases;
	lista<corte> cortes;
};

struct tema{
	int codigo;
	string nombre;
};

//Funciones para manejo de archivos
void escribirProfesores(lista<profesor> ps);
void escribirCortes(lista<profesor> ps);
void escribirNotas(lista<profesor> ps);
void escribirContenedores(lista<profesor> ps);
void escribirEvaluaciones(lista<profesor> ps);
lista<profesor> lectura(lista<profesor> ps);
lista<corte> lecturaCortes(profesor p);
lista<nota> lecturaNotas(profesor p, corte cor);
lista<contenedor> lecturaContenedores(profesor p, corte cor, nota nt);
lista<evaluacion> lecturaEvaluaciones(profesor p, corte cor, nota nt, contenedor cont);


//Implementacion funciones manejo de archivos
lista<profesor> lectura(lista<profesor> ps){
	ifstream archivo;
	int numLines = 0;
	ifstream in("archivos//Profesores//profesores.txt");
	string unused;
	//Contar lineas de archivo
	while (getline(in, unused) )
   		++numLines; 
	cola<string> Cola;
	archivo.open("archivos//Profesores//profesores.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	string aux;
	//while(!archivo.eof()){
	for(int i=0;i<numLines;i++){
		profesor p;
		string puntero="";
		getline(archivo,aux);
		stringstream ss(aux);
		while(ss.good()){
			string substr;
			getline(ss,substr,',');
			Cola.InsCola(substr);
		}
		Cola.AtenderCola(&puntero);
		istringstream cedula(puntero);
		if ( !(cedula >> p.cedula) ) //give the value to 'Result' using the characters in the stream
    		p.cedula = 0;
    	Cola.AtenderCola(&puntero);
		for(int i = 0; i<puntero.length(); i++){
			p.apellidos[i] = puntero[i];
		}
		for(int i = puntero.length(); i<50; i++){
			p.apellidos[i] = 0;
		}
		Cola.AtenderCola(&puntero);
		for(int i = 0; i<puntero.length(); i++){
			p.nombres[i] = puntero[i];
		}
		for(int i = puntero.length(); i<50; i++){
			p.nombres[i] = 0;
		}
		Cola.AtenderCola(&puntero);
		istringstream numClases(puntero);
		if ( !(numClases >> p.numClases) ) //give the value to 'Result' using the characters in the stream
    		p.numClases = 0;
		p.cortes=lecturaCortes(p);		
    	ps.insertarOrd(p,p.cedula);
	}
	archivo.close();
	return ps;
}

lista<corte> lecturaCortes(profesor p){	
	ifstream archivo;
	ostringstream ss;
	ss << p.cedula;
	string ruta;
	ruta="archivos//Cortes//"+ss.str()+"cortes.txt";
	//Contar lineas de archivo
	int numLines = 0;
	ifstream in(ruta.c_str());
	string unused;
	while (getline(in, unused))
   		++numLines; 
	archivo.open(ruta.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		//exit(1);
	}
	corte c;
	c.nombre="CorteEjemplo";
	lista<corte> cs= lista<corte>(c);
	for(int i=0;i<numLines;i++){
		string nombre;
		getline(archivo,nombre);
		c.nombre=nombre;
		c.evaluaciones=lecturaNotas(p,c);
		cs.insertarOrd(c,cs.get_tam()+1);
	}
	archivo.close();
	return cs;
}

lista<nota> lecturaNotas(profesor p, corte cor){
	ifstream archivo;
	ostringstream ss;
	ss << p.cedula;
	string ruta;
	ruta="archivos//TiposEvaluacion//"+ss.str()+cor.nombre+"tiposEval.txt";
	//cout<<ruta;
	//Contar lineas de archivo
	int numLines = 0;
	ifstream in(ruta.c_str());
	string unused;
	while (getline(in, unused))
   		++numLines; 
	archivo.open(ruta.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		//exit(1);
	}
	nota nt;
	nt.porcentaje=1000;
	nt.tipo="TipoCualquiera";
	lista<nota> ns= lista<nota>(nt);
	string aux;
	cola<string> Cola2;
	for(int i=0;i<numLines;i++){
		string puntero="";
		getline(archivo,aux);
		stringstream ss(aux);
		while(ss.good()){
			string substr;
			getline(ss,substr,',');
			Cola2.InsCola(substr);
		}
		Cola2.AtenderCola(&puntero);
		nt.tipo=puntero;
		Cola2.AtenderCola(&puntero);
		istringstream porcentaje(puntero);
		if ( !(porcentaje >> nt.porcentaje) ) //give the value to 'Result' using the characters in the stream
    		nt.porcentaje = 0;
    		nt.evaluaciones=lecturaContenedores(p,cor,nt);
    	ns.insertarOrd(nt,ns.get_tam()+1);	
	}
	archivo.close();
	return ns;
}

lista<contenedor> lecturaContenedores(profesor p, corte cor, nota nt){
	ifstream archivo;
	ostringstream ss;
	ss << p.cedula;
	string ruta;
	ruta="archivos//Contenedores//"+ss.str()+cor.nombre+nt.tipo+".txt";
	//Contar lineas de archivo
	int numLines = 0;
	ifstream in(ruta.c_str());
	string unused;
	while (getline(in, unused))
   		++numLines; 
	archivo.open(ruta.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		//exit(1);
	}
	contenedor cont;
	cont.i=1000;
	lista<contenedor> cs= lista<contenedor>(cont);
	string aux;
	for(int i=0;i<numLines;i++){
		getline(archivo,aux);
		istringstream contador(aux);
		if ( !(contador >> cont.i) ) //give the value to 'Result' using the characters in the stream
    		cont.i = 0;
    	cont.c=lecturaEvaluaciones(p,cor,nt,cont);	
    	cs.insertarOrd(cont,cs.get_tam()+1);
	}
    return cs;	
}

lista<evaluacion> lecturaEvaluaciones(profesor p, corte cor, nota nt, contenedor cont){
	ifstream archivo;
	ostringstream ss;
	ss << p.cedula;
	ostringstream ss2;
	ss2 << cont.i;
	string ruta;
	ruta="archivos//Evaluaciones//"+ss.str()+cor.nombre+nt.tipo+ss2.str()+"preguntas.txt";
	//Contar lineas de archivo
	int numLines = 0;
	ifstream in(ruta.c_str());
	string unused;
	while (getline(in, unused))
   		++numLines; 
	archivo.open(ruta.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		//exit(1);
	}
	evaluacion eva;
	eva.porcentaje=1000;
	eva.tema=1000;
	lista<evaluacion> vs= lista<evaluacion>(eva);
	string aux;
	cola<string> Cola3;
	for(int i=0;i<numLines;i++){
		string puntero="";
		getline(archivo,aux);
		stringstream ss(aux);
		while(ss.good()){
			string substr;
			getline(ss,substr,',');
			Cola3.InsCola(substr);
		}
		Cola3.AtenderCola(&puntero);
		istringstream tema(puntero);
		if ( !(tema >> eva.tema) ) //give the value to 'Result' using the characters in the stream
    		eva.tema = 0;
		Cola3.AtenderCola(&puntero);
		istringstream porcentaje(puntero);
		if ( !(porcentaje >> eva.porcentaje) ) //give the value to 'Result' using the characters in the stream
    		eva.porcentaje = 0;
    	vs.insertarOrd(eva,vs.get_tam()+1);
	}
    return vs;	
}


void escribirProfesores(lista<profesor> ps){
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
}

void escribirCortes(lista<profesor> ps){
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
}

void escribirNotas(lista<profesor> ps){
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
}

void escribirContenedores(lista<profesor> ps){
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
}

void escribirEvaluaciones(lista<profesor> ps){
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
}

//Prototipos funciones de llenado
lista<tema> llenaTemas(lista<tema> ts,tema t);
lista<profesor> llenaProfes(lista<profesor> ps);
lista<corte> llenaCortes(lista<corte> cs);
lista<nota> llenaNotas(lista<nota> ns);
lista<contenedor> llenaContenedores(lista<contenedor> cs);
lista<evaluacion> llenaEvaluaciones(lista<evaluacion> es);




//Implementación funciones de llenado
lista<tema> llenaTemas(lista<tema> ts,tema t){
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
}

lista<corte> llenaCortes(lista<corte> cs){
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
}

lista<nota> llenaNotas(lista<nota> ns){
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
}

lista<contenedor> llenaContenedores(lista<contenedor> cs){
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
}

lista<evaluacion> llenaEvaluaciones(lista<evaluacion> es){
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
}

lista<profesor> llenaProfes(lista<profesor> ps){
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
	return ps;
}

int main(int argc, char** argv) {
	int pos=1,c=1,n=1,cont=1,e=1;
	string ap,nom;
	profesor p;
	corte cor;
	nota nt;
	contenedor ct;
	evaluacion eva;
	cor.nombre="zzzzz";
	p.cedula=999999;
	ap="Apellido1 Apellido2";
	nom="Nombre1 Nombre 2";
	for(int i = 0; i<ap.length(); i++){
		p.apellidos[i] = ap[i];
	}
	for(int i = 0; i<nom.length(); i++){
		p.nombres[i] = nom[i];
	}
	p.numClases=1000;
	tema t;
	t.codigo=1000;
	t.nombre="temaEjemplo";
	
	//Lista profesores
	lista<profesor> profesores = lista<profesor>(p);
	
	
	//Lista de temas
	lista<tema> temas = lista<tema>(t);
	
	//Llenar temas
	temas=llenaTemas(temas,t);
	
	profesores=lectura(profesores);
	//Llenar profesores
	//profesores=llenaProfes(profesores);
	
	//system("cls");

	
	//Muestra la lista
	cout<<"Profesores"<<endl;
	for(pos=1;pos<=profesores.get_tam();pos++){
		profesores.recorrer(pos,&p);
		cout<<"Profesor:"<<endl;	
		cout<<"Cedula: "<<p.cedula<<endl;
		cout<<"Apellidos: "<<p.apellidos<<endl;
		cout<<"Nombres: "<<p.nombres<<endl;
		cout<<"Numero de clases: "<<p.numClases<<endl;
		
		cout<<"Cortes:"<<endl;
		for(c=1;c<=(p.cortes.get_tam());c++){
			p.cortes.recorrer(c,&cor);
			cout<<cor.nombre<<": "<<endl;
			cout<<"Tipos de evaluaciones:"<<endl;
			for(n=1;n<=(cor.evaluaciones.get_tam());n++){
				cor.evaluaciones.recorrer(n,&nt);
				cout<<"Tipo: "<<nt.tipo<<". Porcentaje: "<<nt.porcentaje<<"%"<<endl;
				cout<<"Evaluaciones: "<<endl;
				for(cont=1;cont<=(nt.evaluaciones.get_tam());cont++){
					nt.evaluaciones.recorrer(cont,&ct);
					cout<<"evaluacion #"<<ct.i<<endl;
					for(e=1;e<=(ct.c.get_tam());e++){
						ct.c.recorrer(e,&eva);
						cout<<"Porcentaje: "<<eva.porcentaje<<". Tema: "<<eva.tema<<endl;
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
