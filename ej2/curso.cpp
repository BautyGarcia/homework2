#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

#include "curso.hpp"
#include "alumno.hpp"
#include "utils.hpp"

#define MAX_ALUMNOS 20

using namespace std;

Curso::Curso(string nombre) : nombre(nombre), alumnos(vector<Alumno*>()) {}

// Constructor de copia (Nunca se usa, pero permite copiar un curso)
Curso::Curso(const Curso& other) : nombre(other.nombre) {
    try {
        for (Alumno* alumno : other.alumnos) {
            this->alumnos.push_back(new Alumno(*alumno));
        }
    } catch (const exception& e) {
        cout << "Error en la linea " << __LINE__ << " de " << __FILE__ << " Hubo un error: " << e.what() << endl;
    }
}

Curso::~Curso() {
    for (Alumno* alumno : this->alumnos) {
        delete alumno;
        alumno = nullptr;
    }
}

string Curso::GetNombre() const {
    return this->nombre;
}

void Curso::AddAlumno(Alumno* alumno, int nota) {
    alumno->AgregarCurso(this, nota);
    this->alumnos.push_back(alumno);
}

void Curso::RemoveAlumno(int legajo) {
    for (int i = 0; i < this->alumnos.size(); i++) {
        if (this->alumnos[i]->GetLegajo() == legajo) {
            this->alumnos[i]->EliminarCurso(this);
            this->alumnos.erase(this->alumnos.begin() + i);
        }
    }
}

bool Curso::IsAlumno(int legajo) const {
    for (Alumno* alumno : this->alumnos) {
        if (alumno->GetLegajo() == legajo) {
            return true;
        }
    }
    return false;
}

bool Curso::IsFull() const {
    return this->alumnos.size() == MAX_ALUMNOS;
}

void Curso::PrintAlumnosOrdenados() const {
    ClearScreen();

    if (alumnos.empty()) {
        cout << "El curso " << nombre << " no tiene alumnos. \n" << endl;
        return;
    }

    cout << "=== Lista de Alumnos Ordenada ===" << endl;
    vector<Alumno*> alumnosOrdenados = this->alumnos;

    sort(alumnosOrdenados.begin(), alumnosOrdenados.end(), [](Alumno* a, Alumno* b) {
        return *a < *b;
    });

    for (const Alumno* alumno : alumnosOrdenados) {
        cout << *alumno << endl;
    }

    cout << "\nApreta Enter para continuar...";
    cin.ignore();
    cin.get();
    ClearScreen();
}

int Curso::GetCantidadAlumnos() const {
    return this->alumnos.size();
}