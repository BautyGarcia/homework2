#include "time.hpp"
#include "helpers.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Time time;
    int choice;
    
    int hours, minutes, seconds;
    string meridiano;
    bool valid = false;
    
    // Primer menu para explicitamente decir en que formato se inicializa el reloj
    while (!valid) {
        cout << "=== Seleccione el formato de inicialización ===" << endl;
        cout << "1. Hora por defecto (00:00:00 AM)" << endl;
        cout << "2. Solo Hora (HH AM)" << endl;
        cout << "3. Hora y Minutos (HH:MM AM)" << endl;
        cout << "4. Hora, Minutos y Segundos (HH:MM:SS AM)" << endl;
        cout << "5. Hora, Minutos, Segundos y Meridiano (HH:MM:SS AM/PM)" << endl;
        cout << "Ingrese opcion: ";
        cin >> choice;

        if (!isValidInput()) {
            ClearScreen();
            cout << "Error: Debe ingresar un número" << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                HandleDefaultInit(time);
                valid = true;
                break;
            case 2:
                HandleHHInit(time);
                valid = true;
                break;
            case 3:
                HandleHHMMInit(time);
                valid = true;
                break;
            case 4:
                HandleHHMMSSInit(time);
                valid = true;
                break;
            case 5:
                HandleHHMMSSAMPMInit(time);
                valid = true;
                break;
            default:
                ClearScreen();
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
                break;
        }
    }

    ClearScreen();

    // Menu principal para cambiar el reloj
    while (choice != 11) {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Imprimir hora (12h)" << endl;
        cout << "2. Imprimir hora (24h)" << endl;
        cout << "3. Cambiar AM/PM" << endl;
        cout << "4. Cambiar hora" << endl;
        cout << "5. Cambiar minutos" << endl;
        cout << "6. Cambiar segundos" << endl;
        cout << "7. Ver AM/PM" << endl;
        cout << "8. Ver horas" << endl;
        cout << "9. Ver minutos" << endl;
        cout << "10. Ver segundos" << endl;
        cout << "11. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> choice;

        if (!isValidInput()) {
            ClearScreen();
            cout << "Error: Debe ingresar un número" << endl;
            continue;
        }

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
            case 7: {
                ClearScreen();
                cout << (time.GetMeridiano() == Meridiano::AM ? "a.m." : "p.m.") << endl;
                break;
            }
            case 8: {
                ClearScreen();
                cout << time.GetHours() << "h" << endl;
                break;
            }
            case 9: {
                ClearScreen();
                cout << time.GetMinutes() << "m" << endl;
                break;
            }
            case 10: {
                ClearScreen();
                cout << time.GetSeconds() << "s" << endl;
                break;
            }
            default: {
                ClearScreen();
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
                break;
            }
        }
    }

    ClearScreen();
    return 0;
}