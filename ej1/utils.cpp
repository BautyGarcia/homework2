#include "time.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

using namespace std;

// Script de stack overflow para limpiar la pantalla
void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Handlers para el menu principal

void HandleSetHora(Time& time) {
    ClearScreen();
    time.SetHours(getHours());
}

void HandleSetMinutos(Time& time) {
    ClearScreen();
    time.SetMinutes(getMinutes());
}

void HandleSetSegundos(Time& time) {
    ClearScreen();
    time.SetSeconds(getSeconds());
}

// Considere que dado que son 2 opciones, un toggle es mas practico que un set
void HandleToggleMeridiano(Time& time) {
    ClearScreen();
    if (time.GetMeridiano() == Meridiano::AM) {
        time.SetMeridiano(Meridiano::PM);
    } else {
        time.SetMeridiano(Meridiano::AM);
    }
    cout << "Meridiano cambiado a " << (time.GetMeridiano() == Meridiano::AM ? "AM" : "PM") << endl;
}

// getters/handlers para el menu de inicializacion

int getHours() {
    int newHours;
    cout << "Ingrese horas (0-11): ";
    cin >> newHours;

    if (newHours < 0 || newHours > 11) {
        cout << "Hora inválida. Por favor, ingrese una hora válida." << endl;
        return getHours();
    }

    return newHours;
}

int getMinutes() {
    int newMinutes;
    cout << "Ingrese minutos (0-59): ";
    cin >> newMinutes;

    if (newMinutes < 0 || newMinutes > 59) {
        cout << "Minuto inválido. Por favor, ingrese un minuto válido." << endl;
        return getMinutes();
    }

    return newMinutes;
}

int getSeconds() {
    int newSeconds;
    cout << "Ingrese segundos (0-59): ";
    cin >> newSeconds;

    if (newSeconds < 0 || newSeconds > 59) {
        cout << "Segundo inválido. Por favor, ingrese un segundo válido." << endl;
        return getSeconds();
    }

    return newSeconds;
}

Meridiano getMeridiano() {
    string meridiano;
    cout << "Ingrese meridiano (AM/PM) o (am/pm) (por defecto AM): ";
    cin >> meridiano;
    return meridiano == "PM" || meridiano == "pm" ? Meridiano::PM : Meridiano::AM;
}

void HandleDefaultInit(Time& time) {
    time = Time();
}

void HandleHHInit(Time& time) {
    time = Time(getHours());
}

void HandleHHMMInit(Time& time) {
    time = Time(getHours(), getMinutes());
}

void HandleHHMMSSInit(Time& time) {
    time = Time(getHours(), getMinutes(), getSeconds());
}

void HandleHHMMSSAMPMInit(Time& time) {
    time = Time(getHours(), getMinutes(), getSeconds(), getMeridiano());
}

// Helper para validar que el input sea un numero
bool isValidInput() {
    if (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}