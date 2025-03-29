#include "time.hpp"

void ClearScreen();

void HandleSetHora(Time& time);
void HandleSetMinutos(Time& time);
void HandleSetSegundos(Time& time);
void HandleToggleMeridiano(Time& time);

int getHours();
int getMinutes();
int getSeconds();
Meridiano getMeridiano();

void HandleDefaultInit(Time& time);
void HandleHHInit(Time& time);
void HandleHHMMInit(Time& time);
void HandleHHMMSSInit(Time& time);
void HandleHHMMSSAMPMInit(Time& time);