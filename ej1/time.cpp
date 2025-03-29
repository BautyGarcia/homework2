#include "time.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

/*
Si ponen horas, minutos o segundos de mas, tiro un error, este despues lo manejo en runtime.
*/

Time::Time(int hours, int minutes, int seconds, Meridiano meridiano) :
    hours(hours),
    minutes(minutes),
    seconds(seconds),
    meridiano(meridiano)
{}

Time::Time(int hours, int minutes, int seconds) :
    hours(hours),
    minutes(minutes),
    seconds(seconds),
    meridiano(Meridiano::AM)
{}

Time::Time(int hours, int minutes) :
    hours(hours),
    minutes(minutes),
    seconds(0),
    meridiano(Meridiano::AM)
{}

Time::Time(int hours) :
    hours(hours),
    minutes(0),
    seconds(0),
    meridiano(Meridiano::AM)
{}

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
    this->hours = hours;
}

void Time::SetMinutes(int minutes) {
    this->minutes = minutes;
}

void Time::SetSeconds(int seconds) {
    this->seconds = seconds;
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