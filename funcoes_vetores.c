#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "funcoes_vetores.h"
#include "menu_utilizacao_vetores.h"
#include "funcoes_utilitarias.h"

int funcaoVetores(){

    inicializarConsola();

    utilizarVetores();

    return 0;
}

//*******************************************************************************************************************
int insiraNumeroElementos(void)
{
    int i;
    setlocale(LC_ALL, "Portuguese");
    printf("Insira o número de elementos do vetor: ");
    scanf("%d", &i);
    return i;
}
//*******************************************************************************************************************
void inserirNumeroVetor(int vetor[],int elem)
{
    int i,a=1;
    setlocale(LC_ALL, "Portuguese");
    for (i=0; i<elem; i++,a++)
    {
        if (i==0)
            printf ("Insira os %d valores inteiros\n",elem);
        printf("%dº elemento = ", a);
        scanf("%d",&vetor[i]);
    }

    return;
}
//*******************************************************************************************************************
//*********************************Numeros Aleatorios**********************************************************************************
void numerosAleatorios(int vetor[],int elem)
{
    inicializarGeradorNumerosAleatorios();
    setlocale(LC_ALL, "Portuguese");
    printf("Gerar elementos do vetor\n");
    int i;
    for (i=0; i<elem ; i++)
        vetor[i]= rand()%100+1;

    return;
}
//*******************************************************************************************************************
void apresentarVetor(int vetor[],int elem)
{
    int i,a=1;
    setlocale(LC_ALL, "Portuguese");
    for (i=0; i<elem; i++,a++)
    {
        if (i==0)
            printf("Vetor = { %d",vetor[i]);
        if (i!=0)
            printf(", %d", vetor[i]);
        if (i==elem-1)
            printf(" }\n");
    }

    return;
}
//*******************************************************************************************************************
void procurarVetor(int vetor[],int elem,int vezes)
{
    int i, a=1, valor, n=0;
    setlocale(LC_ALL, "Portuguese");
    printf("\nInsira o valor que deseja procurar: ");
    scanf("%d", &valor);
    for (i=0; i<elem; i++,a++)
    {
        //posição
        if (vetor[i] == valor && vezes == 0)
        {
            printf("O valor %d está presente na %dº posição.\n", valor,i+1);
            return;
        }
        //numero de vezes encontrado
        if (vetor[i] == valor && vezes == 1)
            n=n+vezes;
    }

    if (vezes == 1)
        printf(" O valor %d aparece %d vezes no vetor.", valor,n);
        return;

    printf("%d não foi encontrado no vetor.\n", valor);

    return;
}
//*******************************************************************************************************************

void ordenar (int v[], int n)
{

    int i, troca;
    setlocale(LC_ALL, "Portuguese");
    int aux;
    do
    {
        troca = 0;
        for (i=0; i<n-1; i++)
            if (v[i]>v[i+1])
            {
                aux = v[i];
                v[i]=v[i+1];
                v[i+1] = aux;
                troca = 1;
            }

    }
    while (troca != 0);

    for (i = 0; i<n; i++)
        printf("%d ",v[i]);
    return;
}
