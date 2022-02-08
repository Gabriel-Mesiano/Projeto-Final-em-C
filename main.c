#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "funcoes_strings.h"
#include "funcoes_utilitarias.h"

int main()
{
    char op;
    char opcao[10];
    int codigo;

    setlocale(LC_ALL, "Portuguese");
    //Este do é para fazer a repetição do programa até que o usuário selecione a opção "0" e encerre o programa.
    do {
        printf("      MENU PRINCIPAL");
        printf("\n1 - Realização de operações numéricas");
        printf("\n2 - Ultilização de vetores");
        printf("\n3 - Ultilização de matrizes");
        printf("\n4 - Ultilização de strings");
        printf("\n5 - Conversor de bases de numeração");
        printf("\n6 - Gestor de presenças de alunos");
        printf("\n0 - Terminar o programa");
        printf("\nQual a sua opcão? ");
        codigo = lerStringNCaracteres(opcao,1);
        if (codigo == 0)
            op = opcao[0];
        else
            op ='a';
        //Switch está sendo ultilizado para fazer a seleção do menu, direcionando cada case para a função específica, e tratamento entradas invalidas.
        switch(op){
            case '1':
                system("cls");
                operacoesNumericas();
                break;
            case '2':
                system("cls");
                funcaoVetores();
                break;
            case '3':
                system("cls");
                matrizMenu();
                break;
            case '4':
                system("cls");
                ultilizacaoStrings();
                break;
            case '5':
                system("cls");
                conversorBases();
                break;
            case '6':
                system("cls");
                gestorInit();
                break;
            case '0':
                break;
            default :
                printf("\nOpção inválida\n");
                system("Pause");
            }
    system("cls");
    }while(op != '0');
    printf("Obrigado por utilizar o programa!!\n");
}
