#ifndef ESTUDIANTE_H     
#define ESTUDIANTE_H

class Estudiante{
		long long int codigo;
		char apellidos[50];
		char nombres[50];
	public:
		//Setters
		void setCodigo(long long int cod);
		void setNombres(int pos, char letra);
		void setApellidos(int pos, char letra);
		//Getters
		long long int& getCodigo();
		char* getApellidos();
		char* getNombres();
};
//Setters

void Estudiante::setCodigo(long long int cod){
	codigo=cod;
}

void Estudiante::setNombres(int pos, char letra){
	nombres[pos]=letra;
}

void Estudiante::setApellidos(int pos, char letra){
	apellidos[pos]=letra;
}

//Getters
long long int& Estudiante::getCodigo(){
	return codigo;
}

char* Estudiante::getNombres(){
	return nombres;
}

char* Estudiante::getApellidos(){
	return apellidos;
}

#endif
