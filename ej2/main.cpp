#include "curso.hpp"
#include <iomanip>
#define MAX_ALUMNOS 20

// Script de stack overflow para limpiar la pantalla
void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showStatusBar(Curso& curso) {
    int cantidadAlumnos = curso.GetCantidadAlumnos();
    cout << "Capacidad: [";
    cout << std::string(cantidadAlumnos, '#') << std::string(MAX_ALUMNOS - cantidadAlumnos, '_');
    cout << "] (" << cantidadAlumnos << "/" << MAX_ALUMNOS << ")" << endl;
}

void handleAddAlumno(Curso& curso) {
    if (curso.IsFull()) {
        cout << "Error: El curso está lleno" << endl;
        return;
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
}

void handleRemoveAlumno(Curso& curso) {
    int legajo;
    cout << "Ingrese legajo del alumno a eliminar: ";
    cin >> legajo;
    curso.RemoveAlumno(legajo);
}

void handleCheckAlumno(Curso& curso) {
    int legajo;
    cout << "Ingrese legajo a verificar: ";
    cin >> legajo;
    cout << "El alumno " << (curso.IsAlumno(legajo) ? "existe" : "no existe") << " en el curso" << endl;
}

int main() {
    ClearScreen();
    Curso curso;
    int opcion;

    do {
        showStatusBar(curso);

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
                handleAddAlumno(curso);
                break;
            }
            case 2: {
                handleRemoveAlumno(curso);
                break;
            }
            case 3: {
                handleCheckAlumno(curso);
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
        ClearScreen();
    } while (opcion != 0);

    return 0;
}