#ifndef MENUINSERCION_H     
#define MENUINSERCION_H
class MenuInsercion{
	public:
		void mostrarMenuIns();
};
void MenuInsercion::mostrarMenuIns(){
	int op1;
	system("cls");
	cout << "\t-----------MENU INSERCIONES-----------" << endl << endl;
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
			cout << "Lo necesario para agregar un profesor, por ahora lo que ya se tenia" << endl << endl;
			//profesores = llenaProfes(profesores);
			system("pause");
			mostrarMenuIns();
			break;
		case 2:
			cout << "Lo necesario para agregar un estudiante" << endl;
			system("pause");
			mostrarMenuIns();
			break;
		case 3:
			cout << "Lo necesario para agregar un tema" << endl;
			system("pause");
			mostrarMenuIns();
			break;
		case 4:
			cout << "Lo necesario para agregar una evaluaci\xa2n" << endl;
			system("pause");
			mostrarMenuIns();
			break;
		case 5:
			break;
		default:
			cout << "\tOpci\xa2n invalida" << endl;
			system("pause");
			mostrarMenuIns();
			break;	
	}
}
#endif
