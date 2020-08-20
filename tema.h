#ifndef TEMA_H     
#define TEMA_H

class Tema{
		int codigo;
		string nombre;
	public:
		//Setters
		void setCodigo(int cod);
		void setNombre(string nom);
		//Getters
		string getNombre();
		int getCodigo();
};
//Setters
void Tema::setCodigo(int cod){
	codigo=cod;
}
void Tema::setNombre(string nom){
	nombre=nom;
}
//Getters
string Tema::getNombre(){
	return nombre;
}
int Tema::getCodigo(){
	return codigo;
}
#endif
