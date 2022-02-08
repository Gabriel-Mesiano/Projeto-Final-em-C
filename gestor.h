#ifndef GESTOR_H_INCLUDED
#define GESTOR_H_INCLUDED

void gestorInit(void);

void gestorAtualizarEcra(int , char[150][512], char[150][512], char[150][512], int, char[], int, int);

void gestorMostrarComandos();

int gestorSeNumeros(char[]);

int gestorStrParaInt(char[]);

#endif // GESTOR_H_INCLUDED
