#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "funcoes_utilitarias.h"

/* ****************************************************************************
* Fun��o parar
* Apresenta a mensagem "Prima ENTER para continuar" e espera at� que o
* utilizador prima a tecla ENTER
******************************************************************************/


void parar(void)
{
    fflush(stdin);
    printf("\nPrima ENTER para continuar\n");
    getchar();
    fflush(stdin);
}

/* ****************************************************************************
* Fun��o inicializarGeradorNumerosAleatorios
* Inicializa a semente do gerador de n�meros aleat�rios tendo por base a hora
* do sistema
******************************************************************************/


void inicializarGeradorNumerosAleatorios(void){
    srand((unsigned) time(NULL));
}


/* ****************************************************************************
* Fun��o inicializarConsola
* Configura a consola para utiliza��o dos caracteres portugueses
* Perimte fazer a entrada e sa�da dos caracteres acentuados
******************************************************************************/

void inicializarConsola(void){
    SetConsoleOutputCP((unsigned int) 1252);
    SetConsoleCP((unsigned int) 1252);
}

/* ****************************************************************************
* Fun��o erStringNCaracteres
* Recebe
*   char s[] - string para colocar os caracteres lidos da entrada standard
*   unsigned int qtdCaracteres - n�mero de caracteres a ler da entrada standard
* Devolve um inteiro
*   -1 se a quantidade de caracteres for superior ao n�mero m�ximo de caracteres
* reservados
*   0 se a quantidade de caracteres lidos for igual a qtdCaracteres
*   1 se a quantidade de caracteres lidos for menor que qtdCaracteres
*   2 se a quantidade de caracteres lidos for maior que qtdCaracteres
*
* L� a qtdCaracteres da entrada standard para a string s. Se forem inseridos mais
* caracteres que qtdCaracteres, coloca na string s apenas qtdCaracteres caracteres
******************************************************************************/



int lerStringNCaracteres(char s[], unsigned int qtdCaracteres)
{
    char s1[MAXSTRING];
    unsigned int numeroDeCaracteres, totalDeCaracteresInseridos;
    if (qtdCaracteres>=MAXSTRING)
        return -1;
    else {
        fflush(stdin);
        fgets(s1,MAXSTRING,stdin);
        fflush(stdin);
        totalDeCaracteresInseridos=strlen(s1);
        // remover o caracter '\n' caso tenha sido lido
        if (s1[totalDeCaracteresInseridos-1]=='\n')
            s1[totalDeCaracteresInseridos-1]='\0';
        numeroDeCaracteres=strlen(s1);
        if (numeroDeCaracteres==qtdCaracteres) {
            strcpy(s,s1);
            return 0;
        }
        else {
            copiarInicioString(s,s1,qtdCaracteres);
            if (numeroDeCaracteres<qtdCaracteres)
                return 1;
            else
                return 2;
        }

    }

}

void copiarInicioString(char strDestino[], char strOrigem[], int numeroDeCaracteres)
{
    int posicao = 0;
    while (posicao < numeroDeCaracteres&&strOrigem[posicao]!='\0') {
        strDestino[posicao]=strOrigem[posicao];
        posicao++;
    }
    strDestino[posicao]='\0';
}
