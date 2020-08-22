#ifndef MENUPRINCIPAL_H     
#define MENUPRINCIPAL_H

class MenuPrincipal{
	public:
		void mostrarMenu(Controlador c);
};
void MenuPrincipal::mostrarMenu(Controlador c){
	int op;
	while(op!=6){
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
				{
				int op1;
				while(op1!=5){
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
							c.insertarProfes();
							c.mostrarListaProfes();
							system("pause");
							break;
						case 2:
							cout << "Lo necesario para agregar un estudiante" << endl;
							system("pause");
							break;
						case 3:
							cout << "Lo necesario para agregar un tema" << endl;
							c.insertarTemas();
							c.mostrarListaTemas();						
							system("pause");
							break;
						case 4:
							cout << "Lo necesario para agregar una evaluaci\xa2n" << endl;
							system("pause");
							break;
						case 5:
							break;
						default:
							cout << "\tOpci\xa2n invalida" << endl;
							system("pause");
							break;	
					}
				}
				}
				break;
			case 2:
				{
				int op1;
				while(op1!=5){
					system("cls");
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
							c.modificarProfesor();
							system("pause");
							break;
						case 2:
							cout << "Ingresar el codigo o algo semejante que permita identificar el estudiante: " << endl;
							cout << "Modificar estudiante el estudiante elegido" << endl;
							cout << "El estudiante con el codigo (codigo del estudiante) modificado exitosamente" << endl;
							system("pause");
							break;
						case 3:
							c.modificarTemas();
							system("pause");
							break;
						case 4:
							system("pause");
							break;
						case 5:
							break;
						default:
							cout << "\tOpci\xa2n invalida" << endl;
							system("pause");
							break;
					}
				}
				}
				break;
			case 3:
				{
				int op1;
				while(op1!=5){
					system("cls");
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
							c.eliminarProfesor();
							system("pause");
							break;
						case 2:
							cout << "Ingresar el codigo o algo semejante que permita identificar el estudiante: " << endl;
							cout << "El estudiante con el codigo (codigo del estudiante) eliminado exitosamente" << endl;
							system("pause");
							break;
						case 3:
							cout << "Ingresar el codigo del tema que desea eliminar: " << endl;
							cout << "El tema con el codigo (codigo del tema) ha sido eliminado exitosamente" << endl;
							system("pause");
							break;
						case 4:
							cout << "Ingrese la cedula del profresor: " << endl;
							cout << "Ingrese el nombre de la evaluaci\xa2n que desea editar, o algo as\xa1, la vdd no estoy seguro :c x2" << endl;
							cout << "Evaluaci\xa2n eliminada exitosamente" << endl;
							system("pause");
							break;
						case 5:
							break;
						default:
							cout << "\tOpci\xa2n invalida" << endl;
							system("pause");
							break;
					}
				}
			    }
				break;
			case 4:
				{
				int op1;
				while(op1!=6){
					system("cls");
					cout << "\t-----------MENU CONSULTAS-----------" << endl << endl;
					cout << "\t1. Promedio de un estudiante" << endl;
					cout << "\t2. Comportamiento promedio de los estudiantes." << endl;
					cout << "\t3. Comportamiento promedio de los estudiantes asignados a un profesor." << endl;
					cout << "\t4. Profesores con determinado n\xa3mero de clases." << endl;
					cout << "\t5. Estudiantes con nota superior a cierta nota." << endl;
					cout << "\t6. Volver." << endl << endl;
					cout << "\tSeleccione una opci\xa2n: ";
					cin >> op1;
					system("cls");
					switch(op1){
					case 1:
						cout << "Ingresar algo que permmita saber de que estudiante se desea saber su promedio, puede ser el codigo o algo as\xa1" << endl;
						cout << "Ingresar el curso del cual se desea saber el promedio" << endl;
						cout << "Mostrar el promedio del estudiante :v" << endl << endl;
						system("pause");
						break;
					case 2:
						cout << "Ingresar el curso del cual se desea saber el promedio" << endl;
						cout << "Mostrar el comportamiento promedio de de los estudiantes en los diversos temas" << endl << endl;
						system("pause");
						break;
					case 3:
						cout << "Ingresar el profesor del cual se desea saber el comportamiento promedio de los estudiantes que tienen clase con \x82l" << endl;
						cout << "Mostrar el comportamiento promedio de de los estudiantes clasificado por temas" << endl << endl;
						system("pause");
						break;
					case 4:
						cout << "Ingresar el n\xa3mero de clases" << endl;
						cout << "Mostrar la lista de profesores ordenados por cedula, por ahora se muestra la lista como ya estaba c:" << endl << endl;
						//Muestra la lista
						c.mostrarListaProfes();
						system("pause");
						break;
					case 5:
						cout << "Ingresar la nota: " << endl;
						cout << "Ingresar el tema: " << endl;
						cout << "Mostrar la lista de los estudiantes que superan dicha nota en el tema ingresado" << endl << endl;
						system("pause");
						break;
					case 6:
						break;
					default:
						cout << "\tOpci\xa2n invalida" << endl;
						system("pause");
						break;	
					}
				}
				}
				break;
			case 5:
				cout << "Arcihvo generado exitosamente" << endl;
				system("pause");
				break;
			case 6:
				c.escribirArchivos();
				cout << "Se han generado los archivos automaticamente, vuelva pronto";
				break;
			default:
				cout << "\tOpci\xa2n invalida" << endl;
				system("pause");
				break;
		}
	}
}
#endif
