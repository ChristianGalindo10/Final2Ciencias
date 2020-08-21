#ifndef MENUPRINCIPAL_H     
#define MENUPRINCIPAL_H
#include "menuinsercion.h"
#include "menumodificacion.h"
#include "menueliminacion.h"
#include "menuconsulta.h"
class MenuPrincipal{
	public:
		void mostrarMenu();
};
void MenuPrincipal::mostrarMenu(){
	int op;
	system("cls");
	cout << "\t-----------MENU PRINCIPAL-----------" << endl << endl;
	cout << "\t1. Inserciones." << endl;
	cout << "\t2. Modificaciones." << endl;
	cout << "\t3. Eliminaciones." << endl;
	cout << "\t4. Consultas." << endl;
	cout << "\t5. Generar archivo \"refuerzo.txt\"" << endl;
	cout << "\t6. Salir." << endl << endl;
	cout << "\tSeleccione una opci\xa2n: ";
	cin >> op;
	system("cls");
	switch(op){
		case 1:
			MenuInsercion menuInser;
			menuInser.mostrarMenuIns();
			mostrarMenu();
			break;
		case 2:
			MenuModificacion menuModi;
			menuModi.mostrarMenuMod();
			mostrarMenu();
			break;
		case 3:
			MenuEliminacion menuEli;
			menuEli.mostrarMenuElim();
			mostrarMenu();
			break;
		case 4:
			mostrarMenu();
			break;
		case 5:
			cout << "Arcihvo generado exitosamente" << endl;
			system("pause");
			mostrarMenu();
			break;
		case 6:
			cout << "Se han generado los archivos automaticamente, vuelva pronto";
			break;
		default:
			cout << "\tOpci\xa2n invalida" << endl;
			system("pause");
			mostrarMenu();
			break;
	}
}
#endif
