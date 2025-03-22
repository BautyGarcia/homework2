#include "time.hpp"
#include <iostream>

using namespace std;

// Script de stack overflow para limpiar la pantalla
void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Aca para abajo son todos wrappers para que el switch sea mas legible
void HandleSetHora(Time& time) {
    ClearScreen();
    int newHours;
    cout << "Ingrese horas (0-11): ";
    cin >> newHours;
    time.SetHours(newHours);
}

void HandleSetMinutos(Time& time) {
    ClearScreen();
    int newMinutes;
    cout << "Ingrese minutos (0-59): ";
    cin >> newMinutes;
    time.SetMinutes(newMinutes);
}

void HandleSetSegundos(Time& time) {
    ClearScreen();
    int newSeconds;
    cout << "Ingrese segundos (0-59): ";
    cin >> newSeconds;
    time.SetSeconds(newSeconds);
}

void HandleToggleMeridiano(Time& time) {
    ClearScreen();
    if (time.GetMeridiano() == Meridiano::AM) {
        time.SetMeridiano(Meridiano::PM);
    } else {
        time.SetMeridiano(Meridiano::AM);
    }
    cout << "Cambio a " << (time.GetMeridiano() == Meridiano::AM ? "AM" : "PM") << endl;
}

int main() {
    Time time;
    int choice;
    
    int hours, minutes, seconds;
    string meridiano;
    bool valid = false;
    
    while (!valid) { 
        cout << "=== Crear Tiempo ===" << endl;
        cout << "Ingrese horas (0-11): ";
        cin >> hours;
        cout << "Ingrese minutos (0-59): ";
        cin >> minutes; 
        cout << "Ingrese segundos (0-59): ";
        cin >> seconds;
        cout << "Ingrese meridiano (AM/PM) (default: AM): ";
        cin >> meridiano;

        try {
            time = Time(hours, minutes, seconds, meridiano == "PM" ? Meridiano::PM : Meridiano::AM);
            valid = true;
        } catch (invalid_argument& e) {
            ClearScreen();
            cout << "Valores de tiempo invalidos. Intente nuevamente." << endl << endl;
        }
    }

    ClearScreen();

    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Imprimir hora (12h)" << endl;
        cout << "2. Imprimir hora (24h)" << endl;
        cout << "3. Cambiar AM/PM" << endl;
        cout << "4. Cambiar hora" << endl;
        cout << "5. Cambiar minutos" << endl;
        cout << "6. Cambiar segundos" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ClearScreen();
                time.PrintTime();
                break;
            case 2:
                ClearScreen();
                time.PrintTime24();
                break;
            case 3: {
                HandleToggleMeridiano(time);
                break;
            }
            case 4: {
                HandleSetHora(time);
                break;
            }
            case 5: {
                HandleSetMinutos(time);
                break;
            }
            case 6: {
                HandleSetSegundos(time);
                break;
            }
        }
    } while (choice != 7);

    return 0;
}