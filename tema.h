/**
  *@file tema.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase tema
  *@brief Clase para representar un tema dentro del programa
  */

#ifndef TEMA_H     
#define TEMA_H

/**
  *@brief Clase para manejar los datos relacionados al tema
  */ 
class Tema{
		int codigo; ///&lt; Código del tema
		char nombre[50]; ///&lt; Nombre o descripción del tema
	public:
		//Setters
		/**
	  	  *@brief Establece el código del tema
	  	  *@param cod Código del tema
	  	  */
		void setCodigo(int cod);
		
		/**
	  	  *@brief Establece el nombre o descripción del tema
	  	  *@param pos Posición del arreglo
	  	  *@para letra Letra que debe ir en la posición indicada
	  	  */
		void setNombre(int pos, char letra);
		//Getters
		/**
	  	  *@brief Retorna el nombre o descripción del tema
	  	  *@return Nombre o descripción del tema tipo puntero a char
	  	  */
		char* getNombre();
		
		/**
	  	  *@brief Retorna el código del tema
	  	  *@return Código del tema tipo entero
	  	  */
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
