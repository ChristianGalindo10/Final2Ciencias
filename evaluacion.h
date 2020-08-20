#ifndef EVALUACION_H     
#define EVALUACION_H

class Evaluacion{
		int porcentaje;
		int tema;
	public:
		//Setters
		void setPorcentaje(int porcen);
		void setTema(int t);
		//Getters
		int& getTema();
		int& getPorcentaje();
		
		/*void escribirEvaluaciones(lista<Profesor> ps);
		lista<Evaluacion> llenaEvaluaciones(lista<Evaluacion> es);*/
};
//Setters
void Evaluacion::setPorcentaje(int porcen){
	porcentaje = porcen;
}
void Evaluacion::setTema(int t){
	tema = t;
}
//Getters
int& Evaluacion::getTema(){
	return tema;
}
int& Evaluacion::getPorcentaje(){
	return porcentaje;
}
/*
void Evaluacion::escribirEvaluaciones(lista<Profesor> ps){
	Profesor p;
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
lista<Evaluacion> Evaluacion::llenaEvaluaciones(lista<Evaluacion> es){
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
#endif
