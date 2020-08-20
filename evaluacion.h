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
#endif
