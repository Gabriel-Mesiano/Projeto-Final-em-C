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
    //Este do � para fazer a repeti��o do programa at� que o usu�rio selecione a op��o "0" e encerre o programa.
    do {
        printf("      MENU PRINCIPAL");
        printf("\n1 - Realiza��o de opera��es num�ricas");
        printf("\n2 - Ultiliza��o de vetores");
        printf("\n3 - Ultiliza��o de matrizes");
        printf("\n4 - Ultiliza��o de strings");
        printf("\n5 - Conversor de bases de numera��o");
        printf("\n6 - Gestor de presen�as de alunos");
        printf("\n0 - Terminar o programa");
        printf("\nQual a sua opc�o? ");
        codigo = lerStringNCaracteres(opcao,1);
        if (codigo == 0)
            op = opcao[0];
        else
            op ='a';
        //Switch est� sendo ultilizado para fazer a sele��o do menu, direcionando cada case para a fun��o espec�fica, e tratamento entradas invalidas.
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
                printf("\nOp��o inv�lida\n");
                system("Pause");
            }
    system("cls");
    }while(op != '0');
    printf("Obrigado por utilizar o programa!!\n");
}
