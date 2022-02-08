//#include <stdio.h>
//#include <stdlib.h>
#include "funcoes_utilitarias.h"
#include "menu_operacoes_numericas.h"
#include "operacoesNumericas.h"

void operacoesNumericas(void) {
    int opcaoMenuOperacoesNumericas;
    do {
        opcaoMenuOperacoesNumericas=apresentarMenuOperacoesNumericas();
        switch (opcaoMenuOperacoesNumericas) {
        case 1:
            calcularMDC();
            break;
        case 2:
            calcularMMC();
            break;
        case 3:
           imprimirMultiplos();
            break;
        case 4:
            calcularMedia();
            break;
        case 5:
            somapares();
            break;
        case 6:
            verificarPrimos();
            break;
        case 7:
            imprimirPrimos();
            break;
        case 0:
            break;
        default:
            printf("\nOp��o inv�lida\n");
            parar();
        }
    } while (opcaoMenuOperacoesNumericas!=0);
    return;
}
int apresentarMenuOperacoesNumericas(void) {
    int opcao_op;
    system("cls");
    printf("\t\t\tMENU OPERA��ES NUM�RICAS\n\n");
    printf(" 1 - Calcular o m�ximo divisor comum de dois n�meros naturais\n");
    printf(" 2 - Calcular o m�nimo m�ltiplo comum de dois n�meros naturais\n");
    printf(" 3 - Imprimir m�ltiplos de um n�mero existentes num determinado intervalo\n");
    printf(" 4 - Calcular soma e m�dia de 10 n�meros naturais\n");
    printf(" 5 - Soma de todos os n�meros pares existentes num determinado intervalo\n");
    printf(" 6 - Verificar se um n�mero natural � primo\n");
    printf(" 7 - Mostrar todos os n�meros primos existentes num determinado intervalo\n");
    printf(" 0 - Voltar ao menu anterior\n");
    printf(" Qual a sua op��o? ");
    scanf("%d",&opcao_op);
    return opcao_op;
}

// Menu da funcionalidade  M�ximo Divisor Comum
void calcularMDC (void) {
    int a, b;

    system ("cls");
    printf ("\tC�LCULO DO M�XIMO DIVISOR COMUM!!!\n\n");
    printf ("Insira o primeiro n�mero natural: ");
    scanf("%d", &a);
    printf ("Insira o segundo n�mero natural: ");
    scanf("%d", &b);
    printf ("mdc(%d,%d) = %d\n\n", a, b, mdc (a,b));
     parar();
}

void calcularMMC(void){
 int num1,num2, mmc;

    system ("cls");
    printf ("\tC�LCULO DO MINIMO MULTIPLO COMUM!!!\n\n");
    printf("Insira o primeiro numero natural: ");
    scanf("%d", &num1);
    printf("Insira o segundo numero natural:");
    scanf("%d",&num2);

    mmc = (num1*num2)/mdc(num1,num2);

    printf("mmc(%d,%d)=%d \n",num1, num2, mmc);
   parar();


}
void  imprimirMultiplos(){
int liminf, limsup, num;
    system ("cls");

    printf ("\tIMPRIMIR MULTIPLO DE UM NUMERO EXISTENTE NUM DETERMINADO INTERVALO!!!\n\n");
    printf("Insira o numero: ");
    scanf("%d", &num);
    printf("Insira o Limite inferior do intervalo: ");
    scanf("%d", &liminf);
    printf("Insira o Limite superior do intervalo: ");
    scanf("%d", &limsup);
    printf("Os m�ltiplos de %d existentes no intervalo [%d, %d] sao:", num, liminf, limsup);

    int i;

    for( i = liminf; i<=limsup; i++)
    {
        if(i%num==0)
            printf("\t%d", i);
    }
    parar();
    }




void calcularMedia (){
    int num;
    int soma=0;
    int i=1;
    float media;
    system("cls");
   printf("\tCALCULAR SOMA E M�DIA DE 10 N�MEROS NATURAIS!!!\n\n");
            do{
                printf("Insira o %d numero natural:", i);
                scanf("%d", &num);
                soma=soma+num;
                i++;

                media=soma/10;
                }
                while (i<=10);
            printf("\nSoma = %d",soma);
            printf("\nM�dia = %f\n",media);
           parar();
}

void somapares(){
     int liminf,limsup,i,soma=0;
     system("cls");

            printf("\tSOMA DE TODOS OS NUMEROS PARES EXISTENTES NUM DETERMINADO INTERVALO!\n");
            printf("\nInsira o limite inferior do intervalo: ");
            scanf("%d", &liminf);
            printf("Insira o limite superior do intervalo: ");
            scanf("%d", &limsup);
            for (int i=liminf; i<=limsup; i++)
            {
                if (i%2==0)
                {
                    soma=soma+i;
                }
            }
            printf("A soma de todos os n�meros pares no intervalo existentes no intervalo[%d,%d] e %d\n",liminf,limsup,soma);
           parar();
}

void verificarPrimos(){
    int num, i, resultado = 0;
      system("cls");

 printf("\tVERIFICAR SE O NUMERO E PRIMO OU NAO!\n");
 printf("Digite um n�mero: ");
 scanf("%d", &num);

 for (i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
       resultado++;

    }
 }

 if (resultado == 0)
    printf("O numero %d e um numero primo\n", num);
 else
    printf(" O numero %d nao e um n�mero primo\n", num);
     parar();
}
void imprimirPrimos(){
 int liminf,limsup,n, primoS = 0;
   system("cls");
            printf("\tMOSTRAR TODOS OS N�MEROS PRIMOS EXISTENTES NUM DETERMINADO INTERVALO!!!\n");
            printf("Introduza o intervalo � esquerda:");
            scanf("%d", &liminf);
            printf("Introduza o intervalo � direta:");
            scanf("%d", &limsup);
            printf("Os n�meros primos existentes no intervalo [%d,%d] s�o: ", liminf,limsup);

            for (int i=liminf; i<=limsup; i++)
            {
                n=resprimo(i);
                if (n==2)
                {
                    primoS = 1;
                    printf("%d ",i);
                }
            }
            if (primoS == 0)
                printf("Nao existe primos!!!");
            printf("\n");
            parar();
}

