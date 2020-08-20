#ifndef LLENARLISTAS_H
#define LLENARLISTAS_H
#include "tema.h"
using namespace std;
class LlenarListas{
	public:
		lista<Tema> llenaTemas(lista<Tema> ts,Tema t);
		
};
lista<Tema> LlenarListas::llenaTemas(lista<Tema> ts,Tema t){
	t.setCodigo(1);
	t.setNombre("tipos de algoritmos");
	ts.insertarOrd(t,t.getCodigo());
	
	t.setCodigo(2);
	t.setNombre("complejidad en memoria");
	ts.insertarOrd(t,t.getCodigo());
	
	t.setCodigo(3);
	t.setNombre("complejidad en tiempo");
	ts.insertarOrd(t,t.getCodigo());
	
	t.setCodigo(6);
	t.setNombre("Definicion de orden");
	ts.insertarOrd(t,t.getCodigo());
	
	t.setCodigo(8);
	t.setNombre("Demostraciones");
	ts.insertarOrd(t,t.getCodigo());
	return ts;
}
#endif
