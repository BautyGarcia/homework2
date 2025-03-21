#include "curso.hpp"

int main() {
    Curso curso;
    Alumno alumno("Juan", 128);
    Alumno alumno2("Pedro", 124);
    Alumno alumno3("Luis", 125);
    curso.AddAlumno(&alumno);
    curso.AddAlumno(&alumno2);
    curso.AddAlumno(&alumno3);
    cout << "El alumno " << alumno.GetNombre() << " tiene " << alumno.GetPromedioGeneral() << " de promedio" << endl;
    cout << "El alumno " << alumno2.GetNombre() << " tiene " << alumno2.GetPromedioGeneral() << " de promedio" << endl;
    cout << "El alumno " << alumno3.GetNombre() << " tiene " << alumno3.GetPromedioGeneral() << " de promedio" << endl;
    cout << "Alumnos ordenados:" << endl;
    curso.PrintAlumnosOrdenados();
    return 0;
}