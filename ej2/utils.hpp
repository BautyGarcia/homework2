#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

class Curso;
class Alumno;

using namespace std;

void ClearScreen();
bool isValidInput();
int getAlumnoLegajoInput();
int getAlumnoNotaInput(); 
string getAlumnoNombreInput();
string getCursoNombreInput();
Alumno* findAlumno(vector<Alumno*>& todosAlumnosPtrs, int legajo);
Alumno* createAlumno(vector<Alumno*>& todosAlumnosPtrs, int legajo, const string& nombre);
void showStatusBar(Curso* curso);
void handleAddAlumno(Curso* curso, vector<Alumno*>& alumnos);
void handleRemoveAlumno(Curso* curso, vector<Alumno*>& alumnos);
void handleCheckAlumno(Curso* curso);
void handleCreateCurso(vector<Curso*>& cursos, Curso*& curso);
void showCursos(vector<Curso*>& cursos);
void handleCursoMenu(vector<Curso*>& cursos, Curso*& curso);
void handleMainMenu(vector<Curso*>& cursos, Curso*& curso, vector<Alumno*>& alumnos);

#endif
