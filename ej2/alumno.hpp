#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <string>
#include <vector>

using namespace std;

class Curso;

struct CursoNota {
    Curso* curso;
    int nota;
};

class Alumno {
    private:
        string nombre;
        int legajo;
        vector<CursoNota> cursos;
    public:
        Alumno(string nombre, int legajo);
        float GetPromedioGeneral() const;
        int GetLegajo() const;
        string GetNombre() const;
        void AgregarCurso(Curso* curso, int nota);
        void EliminarCurso(Curso* curso);
        friend ostream& operator<<(ostream& os, const Alumno& alumno);
        bool operator>(const Alumno& other) const;
};

#endif