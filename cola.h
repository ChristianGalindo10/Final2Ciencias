/**
  *@file cola.h
  *@version 1.0
  *@date 24/08/2020
  *@title Clase plantilla cola
  *@brief Clase para la implementación de la estructura de datos cola
  */
#include <cstdlib>
#include <iostream>
#include "estructura.h"

#ifndef COLA_H     
#define COLA_H 

using namespace std;

/**
  *@brief Clase para implementar la estructura de datos cola
  */ 
    
template <class T>
//Clase plantilla cola
class cola{nodo<T> *cab,*fin; ///&lt; apuntadores a una estructura nodo.
      public: 
	  /**
	  	*@brief Constructor por defecto Cola
	  	*/
	  cola(){cab=fin=NULL;}
      
	  /**
	  	*@brief Inserta en la cola
	  	*@param i Dato a insertar en la cola
	  	*/
	  void InsCola(T i);
	   
	   /**
	  	*@brief Atiende la cola
	  	*@param infoRet Direccion de un tipo de dato asociado al tipo de dato de la cola, para poder retornar la información
	  	*/
      void AtenderCola(T *infoRet);
      
      /**
	  	*@brief Imprime los datos que se encuentran en la cola
	  	*/
      void ImprimirCola();
      
      /**
	  	*@brief Devuelve el estado de la cola
	  	*@return Verdadero si está vacía, falso en caso contrario
	  	*/
      bool ColaVacia();
      
      /**
	  	*@brief Destructor de la cola
	  	*/
      ~cola();
 };

//Implementación de los métodos de clase
template <class T>
void cola<T>::InsCola(T i){
     nodo<T> *nuevo;
     nuevo= new nodo <T>;
     nuevo->Dato=i;
     nuevo->sig= NULL;
     if (cab==NULL)
         {cab=nuevo;}
     else {fin->sig = nuevo;}
     fin=nuevo;
}


template <class T>
void cola<T>::AtenderCola(T *infoRet)
{
    nodo<T> *aux = cab; 
    cab=aux->sig;
    *infoRet=aux->Dato;
    delete aux;
    }

template <class T>
void cola<T>::ImprimirCola(){
     nodo<T> *aux;
     aux=cab;
     while(aux!=NULL){
       cout<<aux->Dato<<" ";
       aux=aux->sig;}    
}

template <class T>
bool cola<T>::ColaVacia(){
     return (cab==NULL);
     }
     
     
template <class T>
cola<T>::~cola(){
     nodo<T> *aux;
     while(cab!=NULL)
       {aux= cab;
        cab=aux->sig;
        delete aux;}
     delete cab;
     }

#endif
 


