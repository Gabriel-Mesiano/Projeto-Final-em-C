
#include <stdio.h>
#include <stdlib.h>

//#include "funcoes_utilitarias.h"
#include "menu_operacoes_numericas.h"
#include "operacoesNumericas.h"

//Maximo divisor comum
// Este função calcula o máximo divisor comum entre 2 números
   int mdc (int num1, int num2) {
    int numerador, denominador, resto;

    numerador = num1;
    denominador = num2;
    do {
        resto = numerador % denominador;
        numerador = denominador;
        denominador = resto;
    } while (resto != 0);

    return numerador;
}


//imprimirPrimos

int resprimo(int n)
{
    int resto=0;
    for (int i=1; i<=n; i++)
    {
        if (n%i==0)
        {
            resto++;
        }
    }
    return resto;
}
