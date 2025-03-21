#include "time.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

/*
Si ponen horas, minutos o segundos de mas, tiro un error, este despues lo manejo en runtime.
*/

Time::Time(int hours, int minutes, int seconds, Meridiano meridiano) {
    if (hours >= 12) throw invalid_argument("Las horas deben ser menores a 12");
    if (minutes >= 60) throw invalid_argument("Los minutos deben ser menores a 60");
    if (seconds >= 60) throw invalid_argument("Los segundos deben ser menores a 60");
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->meridiano = meridiano;
}

Time::Time(int hours, int minutes, int seconds) {
    if (hours >= 12) throw invalid_argument("Las horas deben ser menores a 12");
    if (minutes >= 60) throw invalid_argument("Los minutos deben ser menores a 60"); 
    if (seconds >= 60) throw invalid_argument("Los segundos deben ser menores a 60");
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->meridiano = Meridiano::AM;
}

Time::Time(int hours, int minutes) {
    if (hours >= 12) throw invalid_argument("Las horas deben ser menores a 12");
    if (minutes >= 60) throw invalid_argument("Los minutos deben ser menores a 60");
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = 0;
    this->meridiano = Meridiano::AM;
}

Time::Time(int hours) {
    if (hours >= 12) throw invalid_argument("Las horas deben ser menores a 12");
    this->hours = hours;
    this->minutes = 0;
    this->seconds = 0;
    this->meridiano = Meridiano::AM;
}

Time::Time() :
    hours(0),
    minutes(0), 
    seconds(0),
    meridiano(Meridiano::AM)
{}

/*
Para los metodos de obtener los datos, dado que en otras consignas usa el termino "escriba por pantalla"
y aca no lo especifica, interpreto que quiere que lo devuelva.
*/

int Time::GetHours() const {
    return this->hours;
}

int Time::GetMinutes() const {
    return this->minutes;
}

int Time::GetSeconds() const {
    return this->seconds;
}

Meridiano Time::GetMeridiano() const {
    return this->meridiano;
}

void Time::SetHours(int hours) {
    if (hours >= 12) {
        cout << "Las horas deben ser menores a 12" << endl;
        return;
    }
    this->hours = this->meridiano == Meridiano::AM ? hours % 12 : hours % 24;
}

void Time::SetMinutes(int minutes) {
    if (minutes >= 60) {
        cout << "Los minutos deben ser menores a 60" << endl;
        return;
    }
    this->minutes = minutes % 60;
}

void Time::SetSeconds(int seconds) {
    if (seconds >= 60) {
        cout << "Los segundos deben ser menores a 60" << endl;
        return;
    }
    this->seconds = seconds % 60;
}

void Time::SetMeridiano(Meridiano meridiano) {
    this->meridiano = meridiano;
}

void Time::PrintTime() const {
    cout 
    << std::setfill('0') << std::setw(2) << this->GetHours() << "h, "
    << std::setfill('0') << std::setw(2) << this->GetMinutes() << "m, "
    << std::setfill('0') << std::setw(2) << this->GetSeconds() << "s "
    << (this->GetMeridiano() == Meridiano::AM ? "a.m." : "p.m.") 
    << endl;
}

void Time::PrintTime24() const {
    cout 
    << std::setfill('0') << std::setw(2) << this->GetHours() + (this->GetMeridiano() == Meridiano::PM ? 12 : 0) << "h, "
    << std::setfill('0') << std::setw(2) << this->GetMinutes() << "m, "
    << std::setfill('0') << std::setw(2) << this->GetSeconds() << "s "
    << endl;
}