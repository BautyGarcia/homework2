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
        /*
            (b -> v) Constructor de copia para el curso

            Se hace una shallow copy del curso, esto se debe a que (segun lo que busque) el vector<Alumno> ya tiene
            implementada su propia copia profunda al ser copiado, ademas los Alumnos dentro del vector son objetos
            y no punteros, por lo que tambien se copian completamente.

            (c) La relacion Curso-Alumno es bidireccional ya que el curso tiene copias completas de los alumnos
            y los alumnos mantienen punteros al Curso original en su vector de CursoNota.
        */
        Curso(const Curso& other);
        void AddAlumno(Alumno* alumno);
        void RemoveAlumno(int legajo);
        bool IsAlumno(int legajo) const;
        bool IsFull() const;
        void PrintAlumnosOrdenados() const;
        int GetCantidadAlumnos() const; // Funcion auxiliar para el status bar
};