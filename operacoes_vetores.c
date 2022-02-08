#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes_utilitarias.h"
#include "funcoes_vetores.h"




//***************************************Números gerados aleatoriamente************************************************
int vetorAletorio(void)
{
    system("cls");
    int elem;
    elem=insiraNumeroElementos();
    int vetor [elem];
    numerosAleatorios(vetor,elem);
    apresentarVetor(vetor,elem);

    return 0;
}

//***************************************Inseridos pelo Utilizador************************************************

int vetorUtilizador(void)
{
    system("cls");
    int elem=0;
    int vetor[elem];

    elem=insiraNumeroElementos();
    inserirNumeroVetor(vetor,elem);
    apresentarVetor(vetor,elem);

    return 0;
}

//****************************************Menor Valor******************************************

int vetorMenorValor()
{
    system("cls");
    int elem, aux=100,i;
    elem=insiraNumeroElementos();
    int vetor[elem];

    numerosAleatorios(vetor,elem);
    apresentarVetor(vetor,elem);
    for (i = 0; i<elem ; i++)
    {
        if (vetor[i]<aux)
            aux =vetor[i];
    }

    printf("O menor valor é %d",aux);

    return 0;

}

//************************************Posição do Menor Valor******************************************

int vetorPosicaoMenor()
{

    system("cls");
    int elem, aux=100,aux_2,i;
    elem=insiraNumeroElementos();
    int vetor[elem];

    numerosAleatorios(vetor,elem);
    apresentarVetor(vetor,elem);
    for (i=0; i<elem; i++)
    {
        if (vetor[i]<aux)
        {
            aux =vetor[i];
            aux_2=i+1;
        }
    }
    printf("O menor valor é %d e é o %dº elemento do vetor",aux,aux_2);

    return 0;

}

//************************************Procurar Vetor******************************************

int vetorProcurar()
{
    system("cls");
    int elem,procurar=0;
    elem=insiraNumeroElementos();
    int vetor[elem];

    numerosAleatorios(vetor,elem);
    apresentarVetor(vetor,elem);
    procurarVetor(vetor,elem,procurar);

    return 0;
}

//************************************Ordem Crescente******************************************

int vetorCrescente()
{
    system("cls");
    setlocale (LC_CTYPE,"Portuguese");
    int elem=10;
    int vetor [elem];

    inserirNumeroVetor(vetor,elem);
    ordenar (vetor, elem);

        return 0;
}

//************************************Contar Ocorrencias******************************************

int vetorContagem()
{
    system("cls");

    int elem,contagem=1;
    elem=insiraNumeroElementos();
    int vetor[elem];
    inserirNumeroVetor(vetor,elem);
    apresentarVetor(vetor,elem);
    procurarVetor(vetor,elem,contagem);

    return 0;

}
