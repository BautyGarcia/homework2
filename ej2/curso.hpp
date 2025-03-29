#ifndef CURSO_HPP
#define CURSO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Alumno;

class Curso {
    private:
        string nombre;
        vector<Alumno*> alumnos;
    public:
        Curso(string nombre);
        /*
            (b -> v) Constructor de copia para el curso

            Dado que tengo un vector de punteros a Alumno, se hace una deep copy de los punteros, de otra forma
            se estarian creando copias que apuntan a los mismos alumnos, lo que terminaria en que si borro, por ejemplo, la copia
            de un curso, tambien estaria borrando el alumno del curso original.

            (c) La relacion Curso-Alumno corresponde con la de Agregacion. Los alumnos pueden 
            ser anotados, desanotados, buscados, ser evaluados, etc. 
            En cuanto a su lifetime, en el caso de que el curso se cierre, los alumnos pueden cambiar 
            de curso sin dejar de ser alumnos. O bien, si se mueren todos los alumnos, el 
            curso deberá de anotar más alumnos, pero no dejar de existir.
        */
        Curso(const Curso& other);
        string GetNombre() const;
        void AddAlumno(Alumno* alumno, int nota);
        void RemoveAlumno(int legajo);
        bool IsAlumno(int legajo) const;
        bool IsFull() const;
        void PrintAlumnosOrdenados() const;
        int GetCantidadAlumnos() const; // Funcion auxiliar para el status bar
        ~Curso();
};

#endif