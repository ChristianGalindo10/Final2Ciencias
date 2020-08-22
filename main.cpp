#include <iostream>
#include "lista.h"
//Clases
#include "controlador.h"
#include "menuprincipal.h"

using namespace std;
int main(int argc, char** argv) {
	Controlador controlador = Controlador();
	controlador.leerProfes();
	controlador.leerTemas();
	MenuPrincipal menu;
	menu.mostrarMenu(controlador);
	return 0;
}
