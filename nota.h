#ifndef NOTA_H     
#define NOTA_H
#include "contenedor.h"

class Nota{
		string tipo;
		int porcentaje;
		lista<Contenedor> evaluaciones;
	public:
		//Setters
		void setPorcentaje(int porcen);
		void setTipo(string t);
		void setListaContenedor(lista<Contenedor> eval);
		//Getters
		int& getPorcentaje();
		string getTipo();
		lista<Contenedor> getListaContenedor();
		
		/*void escribirNotas(lista<Profesor> ps);
		lista<nota> llenaNotas(lista<nota> ns);*/
};
//Setters
void Nota::setPorcentaje(int porcen){
	porcentaje=porcen;
}
void Nota::setTipo(string t){
	tipo = t;
}
void Nota::setListaContenedor(lista<Contenedor> eval){
	evaluaciones=eval;
}
//Getters
int& Nota::getPorcentaje(){
	return porcentaje;
}
string Nota::getTipo(){
	return tipo;
}
lista<Contenedor> Nota::getListaContenedor(){
	return evaluaciones;
}
/*
void escribirNotas(lista<Profesor> ps){
	Profesor p;
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
lista<nota> nota::llenaNotas(lista<nota> ns){
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
#endif
