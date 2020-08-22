#ifndef TEMA_H     
#define TEMA_H

class Tema{
		int codigo;
		char nombre[50];
	public:
		//Setters
		void setCodigo(int cod);
		void setNombre(int pos, char letra);
		//Getters
		char* getNombre();
		int& getCodigo();
};
//Setters
void Tema::setCodigo(int cod){
	codigo=cod;
}
void Tema::setNombre(int pos, char letra){
	nombre[pos]=letra;
}
//Getters
char* Tema::getNombre(){
	return nombre;
}
int& Tema::getCodigo(){
	return codigo;
}
#endif
