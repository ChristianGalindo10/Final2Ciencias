#ifndef MENUMODIFICACION_H     
#define MENUMODIFICACION_H
class MenuModificacion{
	public:
		void mostrarMenuMod();
};
void MenuModificacion::mostrarMenuMod(){
	system("cls");
	int op1;
	cout << "\t-----------MENU MODIFICACIONES-----------" << endl << endl;
	cout << "\t1. Profesores." << endl;
	cout << "\t2. Estudiantes." << endl;
	cout << "\t3. Temas." << endl;
	cout << "\t4. Evaluaciones." << endl;
	cout << "\t5. Volver." << endl << endl;
	cout << "\tSeleccione una opci\xa2n: ";
	cin >> op1;
	system("cls");
	switch(op1){
		case 1:
			cout << "Ingresar la cedula del profesor a modificar: " << endl;
			cout << "Modificar al profesor elegido" << endl;
			cout << "El profesor identificado con la cedula (n\xa3mero de la cedula) ha sido modificado exitosamente" << endl << endl;
			system("pause");
			mostrarMenuMod();
			break;
		case 2:
			cout << "Ingresar el codigo o algo semejante que permita identificar el estudiante: " << endl;
			cout << "Modificar estudiante el estudiante elegido" << endl;
			cout << "El estudiante con el codigo (codigo del estudiante) modificado exitosamente" << endl;
			system("pause");
			mostrarMenuMod();
			break;
		case 3:
			cout << "Ingresar el codigo del tema que desea modificar: " << endl;
			cout << "Modificar el tema elegido" << endl;
			cout << "El tema con el codigo (codigo del tema) ha sido modificado exitosamente" << endl;
			system("pause");
			mostrarMenuMod();
			break;
		case 4:
			cout << "Ingrese la cedula del profresor: " << endl;
			cout << "Ingrese el nombre de la evaluaci\xa2n que desea modificar, o algo as\xa1, la vdd no estoy seguro :c" << endl;
			cout << "Evaluaci\xa2n modificada exitosamente" << endl;
			system("pause");
			mostrarMenuMod();
			break;
		case 5:
			break;
		default:
			cout << "\tOpci\xa2n invalida" << endl;
			system("pause");
			mostrarMenuMod();
			break;
	}
}
#endif
