/**
  *@file lista.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase plantilla Lista
  *@brief Clase para la implementación de la estructura de datos lista
  */

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "estructura.h"
using namespace std;

/**
  *@brief Clase para implementar una lista ordenada de datos
  */ 
template <class T>
class lista{nodo <T> *cab, *z;///&lt; apuntadores a una estructura nodo.
			int tam;
			
	public: 
			/**
			  *@brief Constructor por defecto lista
			  *@param InfoMax Informacion máxima que puede contener un dato almacenado en la lista
			  */
			lista(T Infomax){
					cab=new nodo<T>; z=new nodo <T>;
					cab->sig=z;
					z->clave=99999999999;
					z->Dato=Infomax;
					z->sig=z;
					tam=0;}
			lista(){cab=NULL; tam=0;}		
			/**
			  *@brief Devuelve el estado de la cola
			  *@return Verdadero si está vacía, falso en caso contrario
			  */
			bool lista_vacia();
			
			/**
			  *@brief Inserta de manera ordenada por clave en la lista
			  *@param info Dato a ingresar en la lista
			  *@param clave Clave del dato a ingresar
			  */
			void insertarOrd(T info, long long int clave);
			
			/**
			  *@brief Elimina un dato de la lista
			  *@param clave Clave del dato a eliminar
			  *@return Verdadero si se pudo eliminar el dato, falso en caso contrario
			  */
			bool borrar(long long int clave);
			
			/**
			  *@brief Busca un dato en la lista
			  *@param clave Clave del dato a buscar
			  *@param infoRet Direccion de un tipo de dato asociado al tipo de dato de la lista, para poder retornar la información del dato encontrado
			  *@return Verdadero si se encuentra el dato, falso en caso contrario
			  */
			bool buscar (long long int clave, T *infoRet);
			
			/**
			  *@brief Cambia la información relacionada a un dato de la lista
			  *@param clave Clave del dato al cual se desea cambiar la información
			  *@param infoNueva Tipo de dato que contiene la nueva información
			  *@return Verdadero si se logra cambiar la información, falso en caso contrario
			  */
			bool cambiar(long long int clave, T infoNueva);	
			
			/**
			  *@brief Indica si un dato pertenece a la lista
			  *@param clave Clave del dato a buscar
			  *@return Verdadero si el dato pertenece a la lista, falso en caso contrario
			  */
			bool pertenece(long long int clave);
			
			/**
			  *@brief Recorre la lista
			  *@param pos Posición que se desea mostrar
			  *@param infoRet Direccion de un tipo de dato asociado al tipo de dato de la lista, para poder retornar la información del dato en la posición dada
			  */
			void recorrer(long long int pos,T *infoRet);
			
			/**
			  *@brief Devuelve el tamaño de la lista
			  *@return El tamaño de la lista de tipo entero
			  */
			int get_tam(){
				return tam;
			}
			
			
			
};

template <class T>
bool lista<T>::lista_vacia()
{if(cab->sig==z)
    return true;
 else
	return false;
}

template <class T>
void lista <T>::insertarOrd(T info,long long int clave){	
	nodo<T> *ant,*pos,*nuevo;
	nuevo=new nodo<T>;
	nuevo->clave=clave;
	nuevo->Dato=info;
	ant=cab;
	pos=cab->sig;
	while(nuevo->clave>pos->clave){
		ant=pos;
		pos=ant->sig;
	}
	ant->sig=nuevo;
	nuevo->sig=pos;
	tam++;
}

template <class T>
bool lista<T>::borrar(long long int clave){ 
	nodo<T> *ant,*pos;
	ant=cab;
	pos=cab->sig;
	while(clave>pos->clave){
		ant=pos;
		pos=ant->sig;
	}
	ant->sig=pos->sig;
	if(pos->clave==clave){
		delete pos;
		tam--;
		return true;
	}else{
		return false;
	}
}

template <class T>
bool lista<T>::buscar(long long int clave, T *infoRet)
{   
	nodo <T> *temp;
	temp=cab->sig;
	while(temp->clave<clave){
		temp=temp->sig;
	}
	if(temp->clave==clave){
		*infoRet = temp->Dato;
		return true;
	}else{
		return false;
	}
}

template <class T>
bool lista<T>::cambiar(long long int clave, T infoNueva){
 	nodo <T> *aux=cab->sig;
	while(aux->clave<clave){
		aux=aux->sig;
	}
	if(aux->clave==clave){
		aux->Dato= infoNueva;
		return true;
	}else{
		return false;
	}
}	

template <class T>
void lista<T>::recorrer(long long int pos,T *infoRet){
	nodo <T> *aux=cab;
	aux=aux->sig;
	int p=1;
	while(p<pos){
		aux=aux->sig;
		p++;
	}
	*infoRet = aux->Dato;
}

template <class T>
bool lista<T>::pertenece(long long int clave){
	nodo <T> *temp;
	temp=cab->sig;
	while(temp->clave<clave){
		temp=temp->sig;
	}
	if(temp->clave==clave){
		return true;
	}else{
		return false;
	}
}

#endif


