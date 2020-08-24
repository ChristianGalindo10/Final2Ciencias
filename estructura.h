/**
  *@file estructura.h
  *@version 1.0
  *@date 24/08/2020
  *@title Estructura nodo
  *@brief Estructura para el funcionamiento de listas y colas
  */

#ifndef ESTRUCTURA_H     
#define ESTRUCTURA_H 

/**
  *@brief Estructura general que garantiza el funcionamiento de listas y colas
  */
template <class T>
struct nodo {
			long long int clave;
			T Dato;
             nodo<T> * sig;};
       
#endif


