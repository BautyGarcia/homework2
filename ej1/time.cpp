#include "time.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
Para todos los constructores, manejo los ingresos invalidos con el operador modulo. Si pones horas, minutos o segundos
de mas se los reinicia.

Por ejemplo, si ponen 25 horas, se lo pasa a 1.
Si ponen 13, se lo pasa a 1.
Si ponen 12, se lo pasa a 0, dado que las 12 am son las 00 pm y las 12 pm son las 00 am.

El meridiano no cambia y por defecto es AM.

Si pones 65 minutos, se lo pasa a 5 minutos.
*/

Time::Time(int hours, int minutes, int seconds, Meridiano meridiano) {
    this->hours = hours % 12;
    this->minutes = minutes % 60;
    this->seconds = seconds % 60;
    this->meridiano = meridiano;
}

Time::Time(int hours, int minutes, int seconds) {
    this->hours = hours % 12;
    this->minutes = minutes % 60;
    this->seconds = seconds % 60;
    this->meridiano = Meridiano::AM;
}

Time::Time(int hours, int minutes) {
    this->hours = hours % 12;
    this->minutes = minutes % 60;
    this->seconds = 0;
    this->meridiano = Meridiano::AM;
}

Time::Time(int hours) {
    this->hours = hours % 12;
    this->minutes = 0;
    this->seconds = 0;
    this->meridiano = Meridiano::AM;
}

Time::Time() {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->meridiano = Meridiano::AM;
}

/*
Para los metodos de obtener los datos, dado que en otras consignas usa el termino "escriba por pantalla"
y aca no lo especifica, interpreto que quiere que lo devuelva.
*/

int Time::GetHours() {
    return this->hours;
}

int Time::GetMinutes() {
    return this->minutes;
}

int Time::GetSeconds() {
    return this->seconds;
}

Meridiano Time::GetMeridiano() {
    return this->meridiano;
}

void Time::SetHours(int hours) {
    if (hours >= 12) cout << "Como pusiste una hora mayor o igual a 12, lo converti a " << hours % 12 << endl;
    this->hours = this->meridiano == Meridiano::AM ? hours % 12 : hours % 24;
}

void Time::SetMinutes(int minutes) {
    if (minutes >= 60) cout << "Como pusiste minutos mayor o iguales a 60, lo converti a " << minutes % 60 << endl;
    this->minutes = minutes % 60;
}

void Time::SetSeconds(int seconds) {
    if (seconds >= 60) cout << "Como pusiste segundos mayor o iguales a 60, lo converti a " << seconds % 60 << endl;
    this->seconds = seconds % 60;
}

void Time::SetMeridiano(Meridiano meridiano) {
    this->meridiano = meridiano;
}

void Time::PrintTime() {
    cout 
    << std::setfill('0') << std::setw(2) << this->GetHours() << "h, "
    << std::setfill('0') << std::setw(2) << this->GetMinutes() << "m, "
    << std::setfill('0') << std::setw(2) << this->GetSeconds() << "s "
    << (this->GetMeridiano() == Meridiano::AM ? "a.m." : "p.m.") 
    << endl;
}

void Time::PrintTime24() {
    cout 
    << std::setfill('0') << std::setw(2) << this->GetHours() + (this->GetMeridiano() == Meridiano::PM ? 12 : 0) << "h, "
    << std::setfill('0') << std::setw(2) << this->GetMinutes() << "m, "
    << std::setfill('0') << std::setw(2) << this->GetSeconds() << "s "
    << endl;
}