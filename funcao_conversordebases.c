#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


void conversorBases(){
    char op;
    char opcao[10];
    int codigo;
    setlocale(LC_ALL, "Portuguese");
    do{
        printf("      Conversor de bases de numeração");
        printf("\n1 - Decimal     -> Binário");
        printf("\n2 - Decimal     -> Hexadecimal");
        printf("\n3 - Binário     -> Decimal");
        printf("\n4 - Binário     -> Hexadecimal");
        printf("\n5 - Hexadecimal -> Decimal");
        printf("\n6 - Hexadecimal -> Binário");
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
                decimalBinarioMenu();
                break;
            case '2':
                system("cls");
                decimalHexadecimalMenu();
                break;
            case '3':
                system("cls");
                binarioDecimalMenu();
                break;
            case '4':
                system("cls");
                binarioHexadecimalMenu();
                break;
            case '5':
                system("cls");
                hexadecimalDecimalMenu();
                break;
            case '6':
                system("cls");
                hexadecimalBinarioMenu();
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
void decimalBinarioMenu(){
    char op;
    char opcao[10];
    int codigo;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    do{
        printf("      Conversão de decimal para binário");
        printf("\n1 - 8 bits sem sinal");
        printf("\n2 - 8 bits sinal e módulo");
        printf("\n3 - 8 bits complemento de 1");
        printf("\n4 - 8 bits complemento de 2");
        printf("\n5 - 16 bits sem sinal");
        printf("\n6 - 16 bits complemento de 2");
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
                decimalBinario8bitsSemSinal();
                break;
            case '2':
                system("cls");
                decimalBinario8bitsComSinal();
                break;
            case '3':
                system("cls");
                decimalBinario8bitsComplemento1();
                break;
            case '4':
                system("cls");
                decimalBinario8bitsComplemento2();
                break;
            case '5':
                system("cls");
                decimalBinario16bitsSemSinal();
                break;
            case '6':
                system("cls");
                decimalBinario16bitsComplemento2();
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
void decimalHexadecimalMenu(){
    char op;
    char opcao[10];
    int codigo;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    do{
        printf("      Conversão de decimal para hexadecimal");
        printf("\n1 - 2 Algarismos hexadecimais");
        printf("\n2 - 4 Algarismos hexadecimais");
        printf("\n3 - 6 Algarismos hexadecimais");
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
                decimalHexadecimal2Algarismos();
                break;
            case '2':
                system("cls");
                decimalHexadecimal4Algarismos();
                break;
            case '3':
                system("cls");
                decimalHexadecimal6Algarismos();
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
void binarioDecimalMenu(){
    char op;
    char opcao[10];
    int codigo;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    do{
        printf("      Conversão de binário para decimal");
        printf("\n1 - 8 bits sem sinal");
        printf("\n2 - 16 bits sem sinal");
        printf("\n3 - 8 bits complemento de 2");
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
                binarioDecimal8bitsSemSinal();
                break;
            case '2':
                system("cls");
                binarioDecimal16bitsSemSinal();
                break;
            case '3':
                system("cls");
                binarioDecimalComplemento2();
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
void binarioHexadecimalMenu(){
    char op;
    char opcao[10];
    int codigo;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    do{
        printf("      Conversão de binário sem sinal para hexadecimal");
        printf("\n1 - 8 bits");
        printf("\n2 - 16 bits");
        printf("\n3 - 24 bits");
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
                binarioHexadecimal8bits();
                break;
            case '2':
                system("cls");
                binarioHexadecimal16bits();
                break;
            case '3':
                system("cls");
                binarioHexadecimal24bits();
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
void hexadecimalDecimalMenu(){
    char op;
    char opcao[10];
    int codigo;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    do{
        printf("      Conversão de hexadecimal para decimal");
        printf("\n1 - 2 Algarismos hexadecimais");
        printf("\n2 - 4 Algarismos hexadecimais");
        printf("\n3 - 6 Algarismos hexadecimais");
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
                hexadecimalDecimal2Algarismos();
                break;
            case '2':
                system("cls");
                hexadecimalDecimal4Algarismos();
                break;
            case '3':
                system("cls");
                hexadecimalDecimal6Algarismos();
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
void hexadecimalBinarioMenu(){
    char op;
    char opcao[10];
    int codigo;
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    do{
        printf("      Conversão de hexadecimal para binário");
        printf("\n1 - 2 Algarismos hexadecimais");
        printf("\n2 - 4 Algarismos hexadecimais");
        printf("\n3 - 6 Algarismos hexadecimais");
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
                hexadecimalBinario2Algarismos();
                break;
            case '2':
                system("cls");
                hexadecimalBinario4Algarismos();
                break;
            case '3':
                system("cls");
                hexadecimalBinario6Algarismos();
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
