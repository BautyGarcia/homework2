#include "time.h"
#include <iostream>

using namespace std;

int main() {
    cout << "\n=== Prueba de Constructores ===" << endl;
    cout << "Constructor completo (11:30:45 PM):" << endl;
    Time t1(11, 30, 45, Meridiano::PM);
    t1.PrintTime();
    t1.PrintTime24();

    cout << "\nConstructor sin meridiano (13:65:75 -> 1:05:15 AM):" << endl;
    Time t2(13, 65, 75);
    t2.PrintTime();
    t2.PrintTime24();

    cout << "\nConstructor sin segundos (14:30 -> 2:30:00 AM):" << endl;
    Time t3(14, 30);
    t3.PrintTime();
    t3.PrintTime24();

    cout << "\nConstructor solo horas (15 -> 3:00:00 AM):" << endl;
    Time t4(15);
    t4.PrintTime();
    t4.PrintTime24();

    cout << "\nConstructor vacío (0:00:00 AM):" << endl;
    Time t5;
    t5.PrintTime();
    t5.PrintTime24();

    cout << "\n=== Prueba de Getters ===" << endl;
    cout << "Hora: " << t1.GetHours() << endl;
    cout << "Minutos: " << t1.GetMinutes() << endl;
    cout << "Segundos: " << t1.GetSeconds() << endl;
    cout << "Meridiano: " << (t1.GetMeridiano() == Meridiano::AM ? "AM" : "PM") << endl;

    cout << "\n=== Prueba de Setters ===" << endl;
    cout << "Tiempo original:" << endl;
    Time t6(1, 30, 45, Meridiano::AM);
    t6.PrintTime();

    cout << "\nCambiando hora a 14 (debería convertir a 2):" << endl;
    t6.SetHours(14);
    t6.PrintTime();

    cout << "\nCambiando minutos a 75 (debería convertir a 15):" << endl;
    t6.SetMinutes(75);
    t6.PrintTime();

    cout << "\nCambiando segundos a 90 (debería convertir a 30):" << endl;
    t6.SetSeconds(90);
    t6.PrintTime();

    cout << "\nCambiando meridiano a PM:" << endl;
    t6.SetMeridiano(Meridiano::PM);
    t6.PrintTime();

    cout << "\n=== Prueba de casos límite ===" << endl;
    cout << "Hora 12 (debería convertir a 0):" << endl;
    Time t7(12, 0, 0, Meridiano::AM);
    t7.PrintTime();
    t7.PrintTime24();

    cout << "\nHora 24 (debería convertir a 0):" << endl;
    Time t8(24, 0, 0, Meridiano::AM);
    t8.PrintTime();
    t8.PrintTime24();

    cout << "\nValores grandes (99:99:99):" << endl;
    Time t9(99, 99, 99, Meridiano::PM);
    t9.PrintTime();
    t9.PrintTime24();

    return 0;
}