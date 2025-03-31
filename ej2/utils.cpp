#include <iostream>
#include <limits>
#include <vector>
#include <string>

#include "alumno.hpp"
#include "curso.hpp"

#define MAX_ALUMNOS 20

using namespace std;

// Script de stack overflow para limpiar la pantalla (solo para que la terminal se vea mas piola)
void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funcion auxiliar para validar la entrada de datos
bool isValidInput() {
    if (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

// Getters para la entrada de datos
int getAlumnoLegajoInput() {
    int legajo;
    cout << "Ingrese el legajo del alumno: ";
    cin >> legajo;
    if (!isValidInput()) {
        cout << "Tenes que ingresar un numero" << endl;
        return getAlumnoLegajoInput();
    }
    return legajo;
}

int getAlumnoNotaInput() {
    int nota;
    cout << "Ingrese la nota del alumno: ";
    cin >> nota;
    if (!isValidInput()) {
        cout << "Tenes que ingresar un numero" << endl;
        return getAlumnoNotaInput();
    }

    if (nota < 0 || nota > 10) {
        cout << "La nota tiene que estar entre 0 y 10" << endl;
        return getAlumnoNotaInput();
    }

    return nota;
}

string getAlumnoNombreInput() {
    string nombre;
    cout << "Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin, nombre);
    if (nombre.empty()) {
        cout << "El nombre no puede estar vacio" << endl;
        return getAlumnoNombreInput();
    }
    return nombre;
}

string getCursoNombreInput() {
    string nombre;
    cout << "Ingrese el nombre del curso: ";
    cin.ignore();
    getline(cin, nombre);
    if (nombre.empty()) {
        cout << "El nombre no puede estar vacio" << endl;
        return getCursoNombreInput();
    }
    return nombre;
}

// Auxiliar que busca un alumno en el vector de alumnos
Alumno* findAlumno(vector<Alumno*>& todosAlumnosPtrs, int legajo) {
    for (Alumno* ptr : todosAlumnosPtrs) {
        if (ptr->GetLegajo() == legajo) {
            return ptr;
        }
    }
    return nullptr;
}

// Auxiliar que crea un alumno y lo agrega al vector de alumnos
Alumno* createAlumno(vector<Alumno*>& todosAlumnosPtrs, int legajo, const string& nombre) {
    try {
        Alumno* nuevoAlumnoPtr = new Alumno(nombre, legajo);
        todosAlumnosPtrs.push_back(nuevoAlumnoPtr);
        return nuevoAlumnoPtr;
    } catch (const exception& e) {
        cout << "Error en la linea " << __LINE__ << " de " << __FILE__ << " Hubo un error: " << e.what() << endl;
    }
    return nullptr;
}

void showStatusBar(Curso* curso) {
    int cantidadAlumnos = curso->GetCantidadAlumnos();
    cout << "Capacidad: [";
    cout << string(cantidadAlumnos, '#') << string(MAX_ALUMNOS - cantidadAlumnos, '_');
    cout << "] (" << cantidadAlumnos << "/" << MAX_ALUMNOS << ") \n" << endl;
}

// Handlers para las opciones del menu

void handleAddAlumno(Curso* curso, vector<Alumno*>& alumnos) {
    if (curso->IsFull()) {
        ClearScreen();
        cout << "No se puede agregar mas alumnos \n" << endl;
        return;
    }

    ClearScreen();

    int legajo = getAlumnoLegajoInput();

    // Si el alumno ya esta inscrito en el curso, no se puede agregar
    if (curso->IsAlumno(legajo)) {
        ClearScreen();
        cout << "El alumno con legajo " << legajo << " ya esta inscrito en el curso" << endl;
        return;
    }

    // Buscar si el alumno ya existe en la lista global
    Alumno* alumnoExistente = findAlumno(alumnos, legajo);
    Alumno* alumnoParaAgregar = nullptr; // Puntero al alumno que voy a agregar al curso

    int nota;

    if (alumnoExistente != nullptr) {
        // El alumno ya existe globalmente, usar ese
        ClearScreen();
        cout << "El alumno '" << alumnoExistente->GetNombre() << "' (Legajo: " << legajo << ") ya existe." << endl;
        cout << "Se agregará al curso '" << curso->GetNombre() << "'." << endl;
        nota = getAlumnoNotaInput();
        alumnoParaAgregar = alumnoExistente;
    } else {
        // El alumno no existe globalmente, hay que crearlo
        ClearScreen();
        cout << "Creando nuevo alumno con legajo " << legajo << "." << endl;
        string nombre = getAlumnoNombreInput();
        nota = getAlumnoNotaInput();

        alumnoParaAgregar = createAlumno(alumnos, legajo, nombre);

        if (alumnoParaAgregar == nullptr) {
            ClearScreen();
            cout << "Error: No se pudo crear el alumno." << endl;
            return;
        }
         cout << "Alumno '" << nombre << "' creado exitosamente." << endl;
    }

    if (alumnoParaAgregar == nullptr) {
        return;
    }

    curso->AddAlumno(alumnoParaAgregar, nota);

    ClearScreen();
}

void handleRemoveAlumno(Curso* curso, vector<Alumno*>& alumnos) {
    ClearScreen();

    int legajo;

    legajo = getAlumnoLegajoInput();

    if (!curso->IsAlumno(legajo)) {
        ClearScreen();
        cout << "El alumno con legajo " << legajo << " no esta inscrito en el curso" << endl;
        return;
    }

    curso->RemoveAlumno(legajo);
    
    ClearScreen();
}

void handleCheckAlumno(Curso* curso) {
    ClearScreen();

    int legajo;

    legajo = getAlumnoLegajoInput();

    ClearScreen();

    if (curso->IsAlumno(legajo)) {
        cout << "El alumno con legajo " << legajo << " esta inscrito en el curso" << endl;
    }
    else {
        cout << "El alumno con legajo " << legajo << " no esta inscrito en el curso" << endl;
    }

    cout << endl;
}

void handleCreateCurso(vector<Curso*>& cursos, Curso*& curso) {
    ClearScreen();
    string nombre;
    nombre = getCursoNombreInput();

    try {
        Curso* nuevoCurso = new Curso(nombre);
        cursos.push_back(nuevoCurso);
        curso = nuevoCurso;
    } catch (const exception& e) {
        cout << "Error en la linea " << __LINE__ << " de " << __FILE__ << " Hubo un error: " << e.what() << endl;
    }
}

// Funcion auxiliar para mostrar los cursos del menu de cursos en terminal
void showCursos(vector<Curso*>& cursos) {
    for (int i = 0; i < cursos.size(); i++) {
        cout << i + 1 << ". " << cursos[i]->GetNombre() << endl;
    }
}

// Handler para el menu de cursos
void handleCursoMenu(vector<Curso*>& cursos, Curso*& curso) {
    ClearScreen();

    int opcion = -1;
    bool valid = false;
    curso = nullptr;

    while (!valid) {
        cout << "=== Seleccione un curso ===" << endl;
        cout << "0. Ingresar nuevo curso" << endl;
        showCursos(cursos);
        cout << "Ingrese una opción: ";
        cin >> opcion;

        if (!isValidInput()) {
            ClearScreen();
            cout << "Tenes que ingresar un numero \n" << endl;
            continue;
        }

        if (opcion == 0) {
            handleCreateCurso(cursos, curso);

            // Si el curso no se creo, y por ende, no se asigno a curso, no se puede continuar
            // En el caso en el que haya un curso viejo cargado, se mantiene la sesion en ese
            if (!curso) {
                return;
            }

            valid = true;
        }
        else if (opcion > 0 && opcion <= cursos.size()) {
            curso = cursos[opcion - 1];
            valid = true;
        }
        else {
            ClearScreen();
            cout << "Opción inválida \n" << endl;
        }
    }

    ClearScreen();
}

// Handler para el menu principal
void handleMainMenu(vector<Curso*>& cursos, Curso*& curso, vector<Alumno*>& alumnos) {
    int opcion = -1;

    while (opcion != 0) {
        cout << "Curso: " << curso->GetNombre() << endl;
        showStatusBar(curso);

        cout << "=== Menú Principal ===" << endl;
        cout << "1. Agregar alumno" << endl;
        cout << "2. Eliminar alumno" << endl;
        cout << "3. Verificar alumno por legajo" << endl;
        cout << "4. Mostrar lista ordenada" << endl;
        cout << "5. Cambiar curso" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        if (!isValidInput()) {
            cout << "Tenes que ingresar un numero" << endl;
            continue;
        }

        switch (opcion) {
            case 1: {
                handleAddAlumno(curso, alumnos);
                break;
            }
            case 2: {
                handleRemoveAlumno(curso, alumnos);
                break;
            }
            case 3: {
                handleCheckAlumno(curso);
                break;
            }
            case 4: {
                curso->PrintAlumnosOrdenados();
                break;
            }
            case 5: {
                handleCursoMenu(cursos, curso);
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
    }

    ClearScreen();
}