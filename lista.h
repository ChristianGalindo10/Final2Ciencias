#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "estructura.h"
using namespace std;
/*
template <class T>
struct nodo {
			int clave;
			T Dato;
             nodo<T> * sig;};*/


template <class T>
class lista{nodo <T> *cab, *z;
			int tam;
			
	public: lista(T Infomax){cab=new nodo<T>; z=new nodo <T>;
					cab->sig=z;
					z->clave=99999999999;
					z->Dato=Infomax;
					z->sig=z;
					tam=0;}
					
			lista(){
				cab=NULL; tam=0;
			}
			bool lista_vacia();
			//void insertar_final(T infoNueva);
			void insertarOrd(T info, long long int clave);
			bool borrar(long long int clave);
			bool buscar (long long int clave, T *infoRet);
			bool cambiar(long long int clave, T infoNueva);	
			bool pertenece(long long int clave);
			void recorrer(long long int pos,T *infoRet);
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

/*
template <class T>
void lista<T>::insertar_final(T infoNueva)
{ nodo <T> *nuevo;
  nuevo = new nodo <T>;
  nuevo->Dato = infoNueva;
  nuevo->sig = NULL;
  if(tam == 0)
    {cab = nuevo;}
  else
    {nodo <T> *aux;
     aux = cab;
     while(aux->sig != NULL)
        {aux = aux->sig;}
     aux->sig = nuevo;
    }
  tam++;
}*/

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


