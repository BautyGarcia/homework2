#include "curso.hpp"

int main() {
    Curso curso;

    cout << "\n=== Creo y agrego alumnos ===" << endl;
    Alumno alumno1("Papo", 101);
    Alumno alumno2("Pepe", 102);
    Alumno alumno3("Pipi", 103);
    Alumno alumno4("Popo", 104);
    Alumno alumno5("Pupu", 105);
    
    cout << "\n=== Agrego 5 alumnos ===" << endl;
    curso.AddAlumno(&alumno1);
    curso.AddAlumno(&alumno2);
    curso.AddAlumno(&alumno3);
    curso.AddAlumno(&alumno4);
    curso.AddAlumno(&alumno5);

    cout << "\n=== Alumnos ===" << endl;
    cout << alumno1 << endl;
    cout << alumno2 << endl;
    cout << alumno3 << endl;
    cout << alumno4 << endl;
    cout << alumno5 << endl;
    
    cout << "\n=== Verificación de Alumnos ===" << endl;
    cout << "¿Existe alumno con legajo 101? " << (curso.IsAlumno(101) ? "Sí" : "No") << endl;
    cout << "¿Existe alumno con legajo 999? " << (curso.IsAlumno(999) ? "Sí" : "No") << endl;

    cout << "\n=== Lista Ordenada Alfabéticamente ===" << endl;
    curso.PrintAlumnosOrdenados();

    cout << "\n=== Prueba de Eliminación ===" << endl;
    cout << "Removiendo alumno con legajo 103 (Pipi)..." << endl;
    curso.RemoveAlumno(103);
    cout << "Intentando remover alumno inexistente (legajo 999)..." << endl;
    curso.RemoveAlumno(999);
    
    cout << "\n=== Lista Final Ordenada ===" << endl;
    curso.PrintAlumnosOrdenados();

    cout << "\n=== Prueba de Límite de Alumnos (Trato de agregar 20 alumnos) ===" << endl;
    for (int i = 0; i < 20; i++) {
        Alumno temp("Estudiante" + to_string(i), 200 + i);
        curso.AddAlumno(&temp);
    }
    cout << "¿Está lleno el curso? " << (curso.IsFull() ? "Sí" : "No") << endl;

    return 0;
}