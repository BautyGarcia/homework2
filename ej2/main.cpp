#include "curso.hpp"

int main() {
    Curso curso;
    int opcion;
    
    do {
        // Show status bar
        cout << "\n=== Estado del Curso ===" << endl;
        cout << "Capacidad: [";
        for (int i = 0; i < 20; i++) {
            cout << (curso.IsFull() ? "█" : "░");
        }
        cout << "]" << endl;

        // Menu options
        cout << "\n=== Menú Principal ===" << endl;
        cout << "1. Agregar alumno" << endl;
        cout << "2. Eliminar alumno" << endl;
        cout << "3. Verificar alumno por legajo" << endl;
        cout << "4. Mostrar lista ordenada" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                if (curso.IsFull()) {
                    cout << "Error: El curso está lleno" << endl;
                    break;
                }
                string nombre;
                int legajo;
                cout << "Ingrese nombre del alumno: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese legajo: ";
                cin >> legajo;
                
                Alumno* alumno = new Alumno(nombre, legajo);
                curso.AddAlumno(alumno);
                break;
            }
            case 2: {
                int legajo;
                cout << "Ingrese legajo del alumno a eliminar: ";
                cin >> legajo;
                curso.RemoveAlumno(legajo);
                break;
            }
            case 3: {
                int legajo;
                cout << "Ingrese legajo a verificar: ";
                cin >> legajo;
                cout << "El alumno " << (curso.IsAlumno(legajo) ? "existe" : "no existe") 
                     << " en el curso" << endl;
                break;
            }
            case 4: {
                cout << "\n=== Lista de Alumnos Ordenada ===" << endl;
                curso.PrintAlumnosOrdenados();
                break;
            }
            case 0: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opción inválida" << endl;
                break;
            }
        }
        
        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
        system("clear"); // Use "cls" instead of "clear" on Windows
        
    } while (opcion != 0);

    return 0;
}