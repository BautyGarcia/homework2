#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <iostream>

#include "curso.hpp"
#include "alumno.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    ClearScreen();
    vector<Curso*> cursos;
    vector<Alumno*> alumnos;
    Curso* cursoSeleccionado = nullptr;
    int opcion = -1;
    bool valid = false;

    handleCursoMenu(cursos, cursoSeleccionado);

    ClearScreen();

    handleMainMenu(cursos, cursoSeleccionado, alumnos);

    // Libero memoria de alumnos al terminar el programa

    for (Alumno* alumno : alumnos) {
        delete alumno;
        alumno = nullptr;
    }

    alumnos.clear();
    
    // La memoria de los cursos ya esta liberada en el destructor de Curso (No estoy seguro -> preguntar)
    cursos.clear();

    return 0;
}