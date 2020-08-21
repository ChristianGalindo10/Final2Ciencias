#ifndef MENUCONSULTA_H     
#define MENUCONSULTA_H
class MenuConsulta{
	public:
		void mostrarMenuConsul();
};
void MenuConsulta::mostrarMenuConsul(){
	system("cls");
	int op1;
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
		mostrarMenuConsul();
		break;
	case 2:
		cout << "Ingresar el curso del cual se desea saber el promedio" << endl;
		cout << "Mostrar el comportamiento promedio de de los estudiantes en los diversos temas" << endl << endl;
		system("pause");
		mostrarMenuConsul();
		break;
	case 3:
		cout << "Ingresar el profesor del cual se desea saber el comportamiento promedio de los estudiantes que tienen clase con \x82l" << endl;
		cout << "Mostrar el comportamiento promedio de de los estudiantes clasificado por temas" << endl << endl;
		system("pause");
		mostrarMenuConsul();
		break;
	case 4:
		cout << "Ingresar el n\xa3mero de clases" << endl;
		cout << "Mostrar la lista de profesores ordenados por cedula, por ahora se muestra la lista como ya estaba c:" << endl << endl;
		//Muestra la lista
		cout<<"Profesores"<<endl;
		/*for(pos=1;pos<=profesores.get_tam();pos++){
			profesores.recorrer(pos,&p);
			cout<<"Profesor:"<<endl;	
			cout<<"Cedula: "<<p.cedula<<endl;
			cout<<"Apellidos: "<<p.apellidos<<endl;
			cout<<"Nombres: "<<p.nombres<<endl;
			cout<<"Numero de clases: "<<p.numClases<<endl;
			cout<<"Cortes:"<<endl;
			for(c=1;c<=(p.cortes.get_tam());c++){
				p.cortes.recorrer(c,&cor);
				cout<<cor.nombre<<": "<<endl;
				cout<<"Tipos de evaluaciones:"<<endl;
					for(n=1;n<=(cor.evaluaciones.get_tam());n++){
						cor.evaluaciones.recorrer(n,&nt);
						cout<<"Tipo: "<<nt.tipo<<". Porcentaje: "<<nt.porcentaje<<"%"<<endl;
						cout<<"Evaluaciones: "<<endl;
							for(cont=1;cont<=(nt.evaluaciones.get_tam());cont++){
								nt.evaluaciones.recorrer(cont,&ct);
								cout<<"evaluacion #"<<ct.i<<endl;
									for(e=1;e<=(ct.c.get_tam());e++){
										ct.c.recorrer(e,&eva);
										cout<<"Porcentaje: "<<eva.porcentaje<<". Tema: "<<eva.tema<<endl;
									}
							}
					}
			}
		}*/
		system("pause");
		mostrarMenuConsul();
		break;
	case 5:
		cout << "Ingresar la nota: " << endl;
		cout << "Ingresar el tema: " << endl;
		cout << "Mostrar la lista de los estudiantes que superan dicha nota en el tema ingresado" << endl << endl;
		system("pause");
		mostrarMenuConsul();
		break;
	case 6:
		break;
	default:
		cout << "\tOpci\xa2n invalida" << endl;
		system("pause");
		mostrarMenuConsul();
		break;	
	}
}
#endif
