#include <iostream>
#include <cstdio>
#include "lista.h"
//Clases
#include "controlador.h"
#include "menuprincipal.h"

using namespace std;
int main(int argc, char** argv) {
	Controlador controlador = Controlador();
	controlador.leerProfes();
	controlador.leerTemas();
	controlador.leerCursos();
	MenuPrincipal menu;
	menu.mostrarMenu(controlador);
	return 0;
}
