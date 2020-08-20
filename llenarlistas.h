#ifndef LLENARLISTAS_H
#define LLENARLISTAS_H
#include "tema.h"
using namespace std;
class LlenarListas{
	public:
		lista<Tema> llenaTemas(lista<Tema> ts,Tema t);
		lista<Profesor> llenaProfes(lista<Profesor> ps);
		lista<Corte> llenaCortes(lista<Corte> cs);
		lista<Nota> llenaNotas(lista<Nota> ns);
		lista<Contenedor> llenaContenedores(lista<Contenedor> cs);
		lista<Evaluacion> llenaEvaluaciones(lista<Evaluacion> es);
};
lista<Tema> LlenarListas::llenaTemas(lista<Tema> ts,Tema t){
	t.setCodigo(1);
	t.setNombre("tipos de algoritmos");
	ts.insertarOrd(t,t.getCodigo());
	
	t.setCodigo(2);
	t.setNombre("complejidad en memoria");
	ts.insertarOrd(t,t.getCodigo());
	
	t.setCodigo(3);
	t.setNombre("complejidad en tiempo");
	ts.insertarOrd(t,t.getCodigo());
	
	t.setCodigo(6);
	t.setNombre("Definicion de orden");
	ts.insertarOrd(t,t.getCodigo());
	
	t.setCodigo(8);
	t.setNombre("Demostraciones");
	ts.insertarOrd(t,t.getCodigo());
	return ts;
}
lista<Profesor> LlenarListas::llenaProfes(lista<Profesor> ps){
	int d=1,c=0;
	Corte cor;
	long long int cedula;
	char apellidos[50];
	char nombres[50];
	int numClases;
	cor.setNombre("CorteFinalFinal");
	while(d!=0){
		lista<Corte> cortes = lista<Corte>(cor);
		Profesor p;
		cout<<"Digite los nombres del profesor: ";
		//cin.ignore();
		cin.getline(nombres, 50);
		p.setNombres(*nombres);
		cout<<"Digite los apellidos del profesor: ";
		//cin.ignore();
		cin.getline(apellidos, 50);
		p.setApellidos(*apellidos);
		cout<<"Digite la cedula del profesor: ";
		cin>>cedula;
		p.setCedula(cedula);
		cout<<"Digite el numero de clases del profesor: ";
		cin>>numClases;
		p.setNumClases(numClases);
		cout<<"Desea ingresar los cortes correspondientes al profesor? Si=1,No=0"<<endl;
		cin>>c;
		if(c==1){
			cortes = llenaCortes(cortes);
		}
		p.setListaCorte(cortes);
		ps.insertarOrd(p,p.getCedula());
		cout<<"Desea ingresar otro profesor: Si=1,No=0"<<endl;
		cin>>d;
		cin.ignore();
	}
	return ps;
}
lista<Corte> LlenarListas::llenaCortes(lista<Corte> cs){
	int c=1,e=0;
	Nota n;
	string nombre;
	n.setPorcentaje(1000);
	n.setTipo("TipoEjemplo");
	while(c!=0){
		lista<Nota> notas = lista<Nota>(n);
		Corte cor;
		cout<<"Digite el nombre del corte: ";
		cin>>nombre;
		cor.setNombre(nombre);
		cout<<"Desea insertar los tipos de evaluación con su repectivo porcentaje? Si=1, No=0"<<endl;
		cin>>e;
		if(e==1){
			notas=llenaNotas(notas);
		} 
		cor.setEvaluaciones(notas);
		cs.insertarOrd(cor,cs.get_tam()+1);
		cout<<"Desea ingresar otro corte? Si=1, No=0"<<endl;
		cin>>c;
	}
	return cs;
}
lista<Nota> LlenarListas::llenaNotas(lista<Nota> ns){
	int nc=1,e=1;
	Contenedor cont;
	cont.setI(9999999);
	string tipo;
	int porcentaje;
	while(nc!=0){
		lista<Contenedor> contenedores = lista<Contenedor>(cont);
		Nota n;
		cout<<"Digite el tipo de evaluacion: ";
		cin>>tipo;
		n.setTipo(tipo);
		cout<<endl;
		cout<<"Digite el porcentaje de evaluacion: ";
		cin>>porcentaje;
		n.setPorcentaje(porcentaje);
		cout<<endl;
		cout<<"Desea insertar evaluaciones? Si=1, No=0"<<endl;
		cin>>e;
		if(e==1){
			contenedores = llenaContenedores(contenedores);
		}
		n.setListaContenedor(contenedores);
		ns.insertarOrd(n,ns.get_tam()+1);
		cout<<"Desea ingresar otro tipo de evaluacion? Si=1, No=0"<<endl;
		cin>>nc;
	}
	return ns;
}
lista<Contenedor> LlenarListas::llenaContenedores(lista<Contenedor> cs){
	int c=1;
	Evaluacion eva;
	eva.setPorcentaje(99999);
	eva.setTema(1000);
	while(c!=0){
		lista<Evaluacion> evaluaciones = lista<Evaluacion>(eva);
		Contenedor cont;
		cont.setI(cs.get_tam()+1);
		cout<<"Insertando evaluacion #"<<cont.getI()<<endl;
		evaluaciones=llenaEvaluaciones(evaluaciones);
		cont.setListaEvaluacion(evaluaciones);
		cs.insertarOrd(cont,cont.getI());
		cout<<"Desea insertar otra evaluacion de este tipo? Si=1,No=0"<<endl;
		cin>>c;
	}
	return cs;
}
lista<Evaluacion> LlenarListas::llenaEvaluaciones(lista<Evaluacion> es){
	int e=1;
	int porcentaje;
	int tema;
	while(e!=0){
		Evaluacion eva;
		cout<<"Insertando pregunta "<<es.get_tam()+1<<endl;
		cout<<"Inserte porcentaje: ";
		cin>>porcentaje;
		eva.setPorcentaje(porcentaje);
		cout<<endl;
		cout<<"Inserte tema: ";
		cin>>tema;
		eva.setTema(tema);
		es.insertarOrd(eva,es.get_tam()+1);
		cout<<"Desea insertar otra pregunta? Si=1,No=0"<<endl;
		cin>>e;
	}
	return es;
}
#endif
