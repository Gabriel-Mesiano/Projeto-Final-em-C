#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void ultilizacaoStrings() {
    char op;
    char opcao[10];
    int codigo;
    setlocale(LC_ALL, "Portuguese");
    do{
        printf("      UTILIZAÇÃO DE STRINGS  ");
        printf("\n1 - Ler uma frase com 8 caracteres");
        printf("\n2 - Ler uma frase com 16 caracteres");
        printf("\n3 - Ler uma frase com N caracteres");
        printf("\n4 - Ler um número binário");
        printf("\n5 - Ler um número decimal");
        printf("\n6 - Ler um número hexadecimal");
        printf("\n7 - Ler hexadecimal e mostrar com letras maiúsculas");
        printf("\n0 - Voltar ao menu anterior");
        printf("\nQual a sua opção?  ");
        codigo = lerStringNCaracteres(opcao,1);
        if (codigo == 0)
            op = opcao[0];
        else
            op ='a';
        switch (op) {
            case '1':
                system("cls");
                frase8();
                break;
            case '2':
                system("cls");
                frase16();
                break;
            case '3':
                system("cls");
                fraseN();
                break;
            case '4':
                system("cls");
                lerbinario();
                break;
            case '5':
                system("cls");
                lerdecimal();
                break;
            case '6':
                system("cls");
                lerhexadecimal();
                break;
            case '7':
                system("cls");
                mostrarhexadecimal();
                break;
            case '0':
                system("pause");
                break;
            default:
                printf("\nOpção inválida\n");
                system("pause");
                break;
        }
    system("cls");
    }while (op != '0');
}
void frase8(){
    int tam;
    char c[50];
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("      Ler frase com 8 caracteres");
    //O do está sendo ultilizado para fazer a repetição da frase caso ela tenha menos ou mais de 8 caracteres.
    do {
        printf("\nInsira uma frase com 8 caracteres : ");
        fflush(stdin);
        gets(c);
        tam = strlen(c);
        //Confere o tamanho da frase e garante a saída correta.
        if (tam < 8)
            printf("Inseriu menos de 8 caracteres.");
        else if (tam > 8)
            printf("Inseriu mais de 8 caracteres.");
        else if (tam = 8){
            printf("Frase inserida : \"%s\"\n",c);
            system("pause");
        }
    }while (tam != 8);
}
void frase16(){
    int tam;
    char c[50];
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("      Ler frase com 16 caracteres");
    //O do está sendo ultilizado para fazer a repetição da frase caso ela tenha menos ou mais de 16 caracteres.
    do {
        printf("\nInsira uma frase com 16 caracteres : ");
        fflush(stdin);
        gets(c);
        tam = strlen(c);
        //Confere o tamanho da frase e garante a saída correta.
        if (tam < 16)
            printf("Inseriu menos de 16 caracteres.");
        else if (tam > 16)
            printf("Inseriu mais de 16 caracteres.");
        else if (tam = 16){
            printf("Frase inserida : \"%s\"\n",c);
            system("pause");
        }
    }while (tam != 16);
}
void fraseN(){
    char c[50];
    int i,nc, tam;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("   Ler frase com N caracteres\n");
    printf("Qual o número de caracteres? ");
    //Define o número de caracteres.
    scanf("%d",&nc);
    //O do está sendo ultilizado para fazer a repetição da frase caso ela tenha menos ou mais de N caracteres que foi definido anteriormente.
    do {
        printf("Insira uma frase com %d caracteres : ", nc);
        fflush(stdin);
        gets(c);
        tam = strlen(c);
        //Confere o tamanho da frase e garante a saída correta.
        if (tam < nc)
            printf("Inseriu menos de %d caracteres.\n", nc);
        else if (tam > nc)
            printf("Inseriu mais de %d caracteres.\n", nc);
        else if (tam = nc) {
            printf("Frase inserida : \"%s\"\n",c);
            system("pause");
        }
    }while (tam != nc);
}
void lerbinario(){
    int i,di;
    char b[50];
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("      Ler um número binário");
    //O do faz a repetição caso a frase inserida não seja um número binário.
    do {
        printf("\nInsira um número binário : ");
        fflush(stdin);
        gets(b);
        di = 0;
        //O for testa se a frase inserida é um número binário.
        for (i = 0; i < strlen(b);i++) {
            switch (b[i]) {
                case '0':
                case '1':
                case ' ':
                    break;
                default:
                    di++;
                    break;
            }
       }
        if (di > 0)
            printf("O texto que inseriu não corresponde a um número binário : \"%s\"",b);
        else {
            printf("Número binário inserido : %s\n",b);
            system("pause");
        }
    }while(di != 0);
}
void lerdecimal(){
    int i,di;
    char d[50];
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("      Ler um número decimal");
    do {
        printf("\nInsira um número decimal : ");
        fflush(stdin);
        gets(d);
        di = 0;
        for (i = 0; i < strlen(d);i++) {
            switch (d[i]) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case ' ':
                    break;
                default:
                    di++;
                    break;
            }
        }
        if (di > 0)
            printf("O texto que inseriu não corresponde a um número decimal : \"%s\"",d);
       else {
            printf("Número decimal inserido : %s\n",d);
            system("pause");
        }
    }while(di != 0);
}
void lerhexadecimal(){
    int i,di;
    char h[50];
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("      Ler um número hexadecimal");
    do {
        printf("\nInsira um número hexadecimal : ");
        fflush(stdin);
        gets(h);
        di = 0;
        for (i = 0; i < strlen(h);i++) {
            switch (h[i]) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                case ' ':
                    break;
                default:
                    di++;
                    break;
            }
        }
        if (di > 0)
            printf("O texto que inseriu não corresponde a um número hexadecimal : \"%s\"",h);
       else {
            printf("Número hexadecimal inserido : %s\n",h);
            system("pause");
        }
    }while(di != 0);
}
void mostrarhexadecimal(){
    int i,di;
    char h[50];
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("      Ler hexadecimal e mostrar com letras maiúsculas");
    do {
        printf("\nInsira um número hexadecimal : ");
        fflush(stdin);
        gets(h);
        di = 0;
        for (i = 0; i < strlen(h);i++) {
            switch (h[i]) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                case ' ':
                    break;
                default:
                    di++;
                    break;
            }
        }
        if (di > 0)
            printf("O texto que inseriu não corresponde a um número hexadecimal : \"%s\"",h);
       else {
            printf("Número hexadecimal inserido : %s\n",strupr(h));
            system("pause");
        }
    }while(di != 0);
}
