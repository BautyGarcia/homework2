#include <string>
#include <vector>
#include <iostream>
#include "alumno.hpp"
#include "curso.hpp"

using namespace std;

Alumno::Alumno(string nombre, int legajo) : nombre(nombre), legajo(legajo), cursos(vector<CursoNota>()) {};

string Alumno::GetNombre() const {
    return this->nombre;
}

int Alumno::GetLegajo() const {
    return this->legajo;
}

float Alumno::GetPromedioGeneral() const {
    float suma = 0;
    for (const CursoNota& curso : this->cursos) {
        suma += curso.nota;
    }
    return suma / this->cursos.size();
}

void Alumno::AgregarCurso(Curso* curso, int nota) {
    this->cursos.push_back({curso, nota});
}

void Alumno::EliminarCurso(Curso* curso) {
    for (int i = 0; i < this->cursos.size(); i++) {
        if (this->cursos[i].curso == curso) {
            this->cursos.erase(this->cursos.begin() + i);
            return;
        }
    }
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