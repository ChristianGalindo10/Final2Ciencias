#ifndef MENUELIMINACION_H     
#define MENUELIMINACION_H
class MenuEliminacion{
	public:
		void mostrarMenuElim();
};
void MenuEliminacion::mostrarMenuElim(){
	system("cls");
	int op1;
	cout << "\t-----------MENU ELIMINACIONES-----------" << endl << endl;
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
			cout << "Ingresar la cedula del profesor a eliminar: " << endl;
			cout << "El profesor identificado con la cedula (n\xa3mero de la cedula) ha sido eliminado exitosamente" << endl << endl;
			system("pause");
			mostrarMenuElim();
			break;
		case 2:
			cout << "Ingresar el codigo o algo semejante que permita identificar el estudiante: " << endl;
			cout << "El estudiante con el codigo (codigo del estudiante) eliminado exitosamente" << endl;
			system("pause");
			mostrarMenuElim();
			break;
		case 3:
			cout << "Ingresar el codigo del tema que desea eliminar: " << endl;
			cout << "El tema con el codigo (codigo del tema) ha sido eliminado exitosamente" << endl;
			system("pause");
			mostrarMenuElim();
			break;
		case 4:
			cout << "Ingrese la cedula del profresor: " << endl;
			cout << "Ingrese el nombre de la evaluaci\xa2n que desea editar, o algo as\xa1, la vdd no estoy seguro :c x2" << endl;
			cout << "Evaluaci\xa2n eliminada exitosamente" << endl;
			system("pause");
			mostrarMenuElim();
			break;
		case 5:
			break;
		default:
			cout << "\tOpci\xa2n invalida" << endl;
			system("pause");
			mostrarMenuElim();
			break;
	}
}
#endif
