#include <algorithm>
#include "curso.hpp"
#define MAX_ALUMNOS 20

Alumno::Alumno(string nombre, int legajo) : nombre(nombre), legajo(legajo), cursos(vector<CursoNota>()) {};

string Alumno::GetNombre() const {
    return this->nombre;
}

int Alumno::GetLegajo() const {
    return this->legajo;
}

float Alumno::GetPromedioGeneral() const {
    float suma = 0;
    for (CursoNota curso : this->cursos) {
        suma += curso.nota;
    }
    return suma / this->cursos.size();
}

void Alumno::AgregarCurso(Curso* curso, int nota) {
    this->cursos.push_back({curso, nota});
}

ostream& operator<<(ostream& os, const Alumno& alumno) {
    os << "Nombre: " << alumno.GetNombre()
       << ", Legajo: " << alumno.GetLegajo() 
       << ", Promedio: " << alumno.GetPromedioGeneral();
    return os;
}

bool Alumno::operator>(const Alumno& other) const {
    return this->GetNombre() > other.GetNombre();
}

Curso::Curso() : alumnos(vector<Alumno>()) {}

Curso::Curso(const Curso& other) : alumnos(other.alumnos) {}

void Curso::AddAlumno(Alumno* alumno) {
    if (this->alumnos.size() >= MAX_ALUMNOS) {
        cout << "No se puede agregar mas alumnos" << endl;
        return;
    }

    alumno->AgregarCurso(this, 10);
    this->alumnos.push_back(*alumno);
}

void Curso::RemoveAlumno(int legajo) {
    for (int i = 0; i < this->alumnos.size(); i++) {
        if (this->alumnos[i].GetLegajo() == legajo) {
            this->alumnos.erase(this->alumnos.begin() + i);
            return;
        }
    }
    cout << "No se encontro el alumno con legajo " << legajo << endl;
}

bool Curso::IsAlumno(int legajo) const {
    for (Alumno alumno : this->alumnos) {
        if (alumno.GetLegajo() == legajo) {
            return true;
        }
    }
    return false;
}

bool Curso::IsFull() const {
    return this->alumnos.size() == MAX_ALUMNOS;
}

void Curso::PrintAlumnosOrdenados() const {
    vector<Alumno> alumnosOrdenados = this->alumnos;
    sort(alumnosOrdenados.begin(), alumnosOrdenados.end(), [](Alumno a, Alumno b) {
        return b > a;
    });

    for (Alumno alumno : alumnosOrdenados) {
        cout << alumno << endl;
    }
}

int Curso::GetCantidadAlumnos() const {
    return this->alumnos.size();
}