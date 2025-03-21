#include <iostream>

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
        friend ostream& operator<<(ostream& os, const Alumno& alumno);
        bool operator>(const Alumno& other) const;
};

class Curso {
    private:
        vector<Alumno> alumnos;
    public:
        Curso();
        void AddAlumno(Alumno* alumno);
        void RemoveAlumno(int legajo);
        bool IsAlumno(int legajo) const;
        bool IsFull() const;
        void PrintAlumnosOrdenados() const;
};