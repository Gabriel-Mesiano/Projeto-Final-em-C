#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "operacoes_vetores.h"
#include "funcoes_utilitarias.h"
#include "menu_utilizacao_vetores.h"
#include "operacoes_vetores.h"


void utilizarVetores(void)
{
    setlocale(LC_ALL, "Portuguese");
    int opcaoMenuUtilizarVetores;
    do
    {
        opcaoMenuUtilizarVetores = apresentarMenuUtilizacaoVetores();
        switch (opcaoMenuUtilizarVetores)
        {

        case 1:
            vetorAletorio();
            parar();
            break;
        case 2:
            vetorUtilizador();
            parar();
            break;

        case 3:
             vetorMenorValor();
            parar();
            break;

        case 4:
            vetorPosicaoMenor();
            parar();
            break;

        case 5:
            vetorProcurar();
            parar();
            break;

        case 6:
            vetorCrescente();
            parar();
            break;

        case 7:
            vetorContagem();
            parar();
            break;
        case 0:
            break;
        default:
            printf("Opção inválida\n");
            parar();
        }
    }
    while (opcaoMenuUtilizarVetores!=0);

    return;
}

int apresentarMenuUtilizacaoVetores(void)
{

    int opcao;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("\tMENU UTILIZAÇÃO DE VETORES\n\n");
    printf(" 1 - Preencher e mostrar um vetor com números aleatórios\n");
    printf(" 2 - Preencher e mostrar um vetor com números inseridos pelo utilizador\n");
    printf(" 3 - Mostrar o menor valor existente num vetor de inteiros\n");
    printf(" 4 - Mostrar a posição do vetor onde se encontra o menor valor\n");
    printf(" 5 - Procurar um valor num vetor\n");
    printf(" 6 - Ordenar por ordem crescente um conjunto de dez valores inteiros\n");
    printf(" 7 - Contar ocorrências de um valor num vetor\n");
    printf(" 0 - Voltar ao menu anterior\n");
    printf(" Qual a sua opção? ");
    scanf("%d",&opcao);

    return opcao;
}
