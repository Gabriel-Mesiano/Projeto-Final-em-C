#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<math.h>

void decimalBinario8bitsSemSinal (){
    int deci, i, bin[8], aux;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("DECIMAL PARA BINÁRIO\n8 bits\nsem sinal\n\nGama de valores admissíveis [0,255]\n\n");
        printf("Valor a converter : ");
        scanf("%d", &deci);
        aux = deci;
        if (deci >= 0 && deci < 256) {
            for (i = 7; i >= 0; i--){
                if (deci %2 == 0) {
                    bin[i] = 0;
                    deci = deci / 2;
                }
                else {
                    bin[i] = 1;
                    deci = deci / 2;
                }
            }
        }
        else {
            printf("O valor que inseriu não pertence ao intervalo de valores admissíveis\n");
            system("pause");
            system("cls");
        }
    }while(deci < 0 || deci > 255);
    printf("Representação decimal = %d", aux);
    printf("\nRepresentação binária = ");
    for (i = 0; i <= 7; i++) {
        printf("%d", bin[i]);
        switch (i) {
            case 3:
                printf(" ");
                break;
        }
    }
    printf("\n\n");
    system("pause");
}
void decimalBinario8bitsComSinal (){
    int deci, aux, i, bin[8];
    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("DECIMAL PARA BINÁRIO\n8 bits\nsinal e módulo\n\nGama de valores admissíveis [-127,127]\n\n");
        printf("Valor a converter : ");
        scanf("%d", &deci);
        aux = deci;
        if (deci >= -127 && deci < 128) {
            for (i = 7; i >= 0; i--){
                if (deci %2 == 0) {
                    bin[i] = 0;
                    deci = deci / 2;
                }
                else {
                    bin[i] = 1;
                    deci = deci / 2;
                }
            }
        }
        else {
            printf("O valor que inseriu não pertence ao intervalo de valores admissíveis\n");
            system("pause");
            system("cls");
        }
    }while(deci < -127 || deci > 128);
    switch(aux) {
        case 0:
           switch (i) {
                    case 3:
                        printf(" ");
                        break;
                } printf("Representação binária = 0000 0000 para 0 ou 1000 0000 para -0");
            break;
        default:
            if (aux > 0)
                bin[0] = 0;
            else
                bin[0] = 1;
            printf("Representação binária = ");
            for (i = 0; i <= 7; i++) {
                printf("%d", bin[i]);
                switch (i) {
                    case 3:
                        printf(" ");
                        break;
                }
            }
    }
    printf("\n\n");
    system("pause");
}
void decimalBinario8bitsComplemento1(){
    int deci, bin[8], i, aux;
    char binC[5],binCT[2] = "-0";
    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("DECIMAL PARA BINÁRIO\n8 bits\nComplemento de um\n\nGama de valores admissíveis [-127,127]\n\n");
        printf("Valor a converter : ");
        fflush(stdin);
        scanf("%d%s", &deci, &binC);
        aux = deci;
        if (deci > -128 && deci < 128) {
            for (i = 7; i >= 0; i--){
                if (deci %2 == 0) {
                    bin[i] = 0;
                    deci = deci / 2;
                }
                else {
                    bin[i] = 1;
                    deci = deci / 2;
                }
            }
        }
        else {
            printf("O valor que inseriu não pertence ao intervalo de valores admissíveis\n");
            system("pause");
            system("cls");
        }
    }while(deci < -128 || deci > 128);
    //switch(aux) {
      //  case 0:
        //    printf("Representação binária = 0000 0000 para 0 ou 1111 1111 para -0");
          //  break;
        //default:
    if(strncmp(binCT,binC,2)== 0)
            printf("1111 1111");
    else {
            if (aux < 0){
                printf("Representação binária = ");
                for (i = 0; i <= 7; i++){
                    switch(bin[i]){
                        case 1:
                            bin[i] = 0;
                            break;
                        default:
                            bin[i] = 1;
                    }
                }
            }
            else
            printf("Representação binária = ");
            for (i = 0; i <= 7; i++) {
                printf("%d", bin[i]);
                switch (i) {
                    case 3:
                        printf(" ");
                        break;
                }
            }
            //break;
    }
    printf("\n\n");
    system("pause");
}
void decimalBinario8bitsComplemento2(){
    int deci, bin[8], bins, i, aux;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("DECIMAL PARA BINÁRIO\n8 bits\nComplemento de dois\n\nGama de valores admissíveis [-128,127]\n\n");
        printf("Valor a converter : ");
        scanf("%d", &deci);
        aux = deci;
        if (deci >= -128 && deci < 128) {
            for (i = 7; i >= 0; i--){
                if (deci %2 == 0) {
                    bin[i] = 0;
                    deci = deci / 2;
                }
                else {
                    bin[i] = 1;
                    deci = deci / 2;
                }
            }
        }
        else {
            printf("O valor que inseriu não pertence ao intervalo de valores admissíveis\n");
            system("pause");
            system("cls");
        }
    }while(deci < -129 || deci > 127);
    if (aux < 0){
        for (i = 7; i >= 0; i--){
            switch(bin[i]){
                case 1:
                    bins = i;
                    i = 0;
                    break;
                default:
                    break;
            }
        }
        for (i = 0; i < bins; i++){
            switch(bin[i]){
                case 1:
                    bin[i] = 0;
                    break;
                default:
                    bin[i] = 1;
            }
        }
        bin[0] = 1;
    }
    else
        bin[0] = 0;
    printf("Representação binária = ");
    for (i = 0; i <= 7; i++) {
        printf("%d", bin[i]);
        switch (i) {
            case 3:
                printf(" ");
                break;
        }
    }
    printf("\n\n");
    system("pause");
}
void decimalBinario16bitsSemSinal (){
    int i, bin[16];
    long deci, aux;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("DECIMAL PARA BINÁRIO\n16 bits\nsem sinal\n\nGama de valores admissíveis [0,65.535]\n\n");
        printf("Valor a converter : ");
        scanf("%li", &deci);
        aux = deci;
        if (deci >= 0 && deci < 65536) {
            for (i = 15; i >= 0; i--){
                if (deci %2 == 0) {
                    bin[i] = 0;
                    deci = deci / 2;
                }
                else {
                    bin[i] = 1;
                    deci = deci / 2;
                }
            }
        }
        else {
            printf("O valor que inseriu não pertence ao intervalo de valores admissíveis\n");
            system("pause");
            system("cls");
        }
    }while(deci < 0 || deci > 65536);
    printf("Representação decimal = %li", aux);
    printf("\nRepresentação binária = ");
    for (i = 0; i <= 15; i++) {
        printf("%d", bin[i]);
        switch (i) {
            case 3:
            case 7:
            case 11:
                printf(" ");
                break;
        }
    }
    printf("\n");
    system("pause");
}
void decimalBinario16bitsComplemento2(){
    int deci, bin[16], bins, i, aux;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("DECIMAL PARA BINÁRIO\n16 bits\nComplemento de dois\n\nGama de valores admissíveis [-32.768,32.767]\n\n");
        printf("Valor a converter : ");
        scanf("%d", &deci);
        aux = deci;
        if (deci >= -32768 && deci < 32768) {
            for (i = 15; i >= 0; i--){
                if (deci %2 == 0) {
                    bin[i] = 0;
                    deci = deci / 2;
                }
                else {
                    bin[i] = 1;
                    deci = deci / 2;
                }
            }
        }
        else {
            printf("O valor que inseriu não pertence ao intervalo de valores admissíveis\n");
            system("pause");
            system("cls");
        }
    }while(deci < -32769 || deci > 32768);
    if (aux < 0){
        for (i = 15; i >= 0; i--){
            switch(bin[i]){
                case 1:
                    bins = i;
                    i = 0;
                    break;
                default:
                    break;
            }
        }
        for (i = 0; i < bins; i++){
            switch(bin[i]){
                case 1:
                    bin[i] = 0;
                    break;
                default:
                    bin[i] = 1;
            }
        }
        bin[0] = 1;
    }
    else
        bin[0] = 0;
    printf("Representação binária = ");
    for (i = 0; i <= 15; i++) {
        printf("%d", bin[i]);
        switch (i) {
            case 3:
            case 7:
            case 11:
                printf(" ");
                break;
        }
    }
    printf("\n");
    system("pause");
}
void decimalHexadecimal2Algarismos(){
    int deci;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("DECIMAL PARA HEXADECIMAL\n2 ALGARISMOS HEXADECIMAIS\n\nGama de valores admissíveis [0,255]\n\n");
        printf("Valor a converter : ");
        scanf("%d", &deci);
        if (deci < 0 || deci > 255) {
            printf("O valor que inseriu não pertence ao intervalo de valores admissíveis\n");
            system("pause");
            system("cls");
        }
    }while (deci < 0 || deci > 255);
    printf("Representação hexadecimal = %2X\n", deci);
    system("pause");
}
void decimalHexadecimal4Algarismos(){
    int deci;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("DECIMAL PARA HEXADECIMAL\n4 ALGARISMOS HEXADECIMAIS\n\nGama de valores admissíveis [0,65.535]\n\n");
        printf("Valor a converter : ");
        scanf("%d", &deci);
        if (deci < 0 || deci > 65535) {
            printf("O valor que inseriu não pertence ao intervalo de valores admissíveis\n");
            system("pause");
            system("cls");
        }
    }while (deci < 0 || deci > 65535);
    printf("Representação hexadecimal = %4X\n", deci);
    system("pause");
}
void decimalHexadecimal6Algarismos(){
    double deci;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("DECIMAL PARA HEXADECIMAL\n6 ALGARISMOS HEXADECIMAIS\n\nGama de valores admissíveis [0,16.777.215]\n\n");
        printf("Valor a converter : ");
        scanf("%d", &deci);
        if (deci < 0 || deci > 16777215) {
            printf("O valor que inseriu não pertence ao intervalo de valores admissíveis\n");
            system("pause");
            system("cls");
        }
    }while (deci < 0 || deci > 16777215);
    printf("Representação hexadecimal = %6X\n", deci);
    system("pause");
}
void binarioDecimal8bitsSemSinal(){

    char bin[100];
    int dec = 0;
    int i = 0, s;
    do {
        printf("BINÁRIO PARA DECIMAL\n8 bits sem sinal\n\n");
        printf("Insira um número binário com 8 bits : ");
        fflush(stdin);
        fgets( bin, sizeof(bin), stdin);
        printf("OBS: Os números diferentes de 1 e 0 serão ignorados.\n");
        s = strlen( bin );
        while( s-- ) {
            if( bin[s] == '0' || bin[s] == '1' ) {
                dec = dec + pow(2, i++) * (bin[s] - '0');
            }
        };
        if (dec < 0 || dec > 255) {
                printf("Foram digitados mais de 8 bits\n");
                system("pause");
                system("cls");
        }
    }while (dec < 0 || dec > 256);
    printf("Representação decimal = %d\n", dec);
    system("pause");
}
void binarioDecimal16bitsSemSinal(){

    char bin[100];
    int dec = 0;
    int i = 0, s;
    do {
        printf("BINÁRIO PARA DECIMAL\n16 bits sem sinal\n\n");
        printf("Insira um número binário com 16 bits : ");
        fflush(stdin);
        fgets( bin, sizeof(bin), stdin);
        printf("OBS: Os números diferentes de 1 e 0 serão ignorados.\n");
        s = strlen( bin );
        while( s-- ) {
            if( bin[s] == '0' || bin[s] == '1' ) {
                dec = dec + pow(2, i++) * (bin[s] - '0');
            }
        };
        if (dec < 0 || dec > 65536) {
            printf("Foram digitados mais de 8 bits\n");
            system("pause");
            system("cls");
        }
    }while (dec < 0 || dec > 65536);
    printf("\nNúmero decimal = %d\n", dec);
    system("pause");
}
void binarioDecimalComplemento2(){
    char bin[100];
    int dec = 0;
    int i = 0, s, bins, aux = 0;
    do {
        printf("BINÁRIO PARA DECIMAL\n8 bits complemento de dois\n\n");
        printf("Insira um número binário com 8 bits : ");
        fflush(stdin);
        fgets( bin, sizeof(bin), stdin);
        printf("OBS: Os números diferentes de 1 e 0 serão ignorados.\n");
        s = strlen( bin ) - 1;
        if (s > 8) {
            printf("Foram digitados mais de 8 bits\n");
            system("pause");
            system("cls");
        }
        else {
            switch (bin[0]){
                case '0':
                    break;
                case '1':
                    aux = 1;
                    for (i = s; i >= 0; i--){
                        if(bin[i] == '1') {
                            bins = i;
                            i = 0;
                        }
                    }
                    for (i = 0; i < bins; i++){
                        switch(bin[i]){
                            case '1':
                                bin[i] = '0';
                                break;
                            default:
                                bin[i] = '1';
                        }
                    }
                    break;
            }
            i = 0;
            while( s != 0 ) {
                if( bin[s] == '0' || bin[s] == '1' ) {
                    dec = dec + pow(2, i++) * (bin[s] - '0');
                }
                s--;
            };
        }
    }while (dec <= -128 || dec > 127);
    if (aux == 1)
        dec = -dec;
    printf("Representação decimal = %d\n", dec);
    system("pause");
}
void binarioHexadecimal8bits(){

    char bin[100];
    int dec = 0;
    int i = 0, s;
    do {
        printf("BINÁRIO PARA HEXADECIMAL\n8 bits sem sinal\n\n");
        printf("Insira um número binário com 8 bits : ");
        fflush(stdin);
        fgets( bin, sizeof(bin), stdin);
        printf("OBS: Os números diferentes de 1 e 0 serão ignorados.\n");
        s = strlen( bin );
        while( s-- ) {
            if( bin[s] == '0' || bin[s] == '1' ) {
                dec = dec + pow(2, i++) * (bin[s] - '0');
            }
        };
        if (dec < 0 || dec > 255) {
                printf("Foram digitados mais de 8 bits\n");
                system("pause");
                system("cls");
        }
    }while (dec < 0 || dec > 256);
    printf("Representação decimal = %2X\n", dec);
    system("pause");
}
void binarioHexadecimal16bits(){

    char bin[100];
    int dec = 0;
    int i = 0, s;
    do {
        printf("BINÁRIO PARA HEXADECIMAL\n16 bits sem sinal\n\n");
        printf("Insira um número binário com 16 bits : ");
        fflush(stdin);
        fgets( bin, sizeof(bin), stdin);
        printf("OBS: Os números diferentes de 1 e 0 serão ignorados.\n");
        s = strlen( bin );
        while( s-- ) {
            if( bin[s] == '0' || bin[s] == '1' ) {
                dec = dec + pow(2, i++) * (bin[s] - '0');
            }
        };
        if (dec < 0 || dec > 65536) {
            printf("Foram digitados mais de 16 bits\n");
            system("pause");
            system("cls");
        }
    }while (dec < 0 || dec > 65536);
    printf("\nNúmero decimal = %4X\n", dec);
    system("pause");
}
void binarioHexadecimal24bits(){

    char bin[100];
    int dec = 0;
    int i = 0, s;
    do {
        printf("BINÁRIO PARA HEXADECIMAL\n24 bits sem sinal\n\n");
        printf("Insira um número binário com 24 bits : ");
        fflush(stdin);
        fgets( bin, sizeof(bin), stdin);
        printf("OBS: Os números diferentes de 1 e 0 serão ignorados.\n");
        s = strlen( bin );
        while( s-- ) {
            if( bin[s] == '0' || bin[s] == '1' ) {
                dec = dec + pow(2, i++) * (bin[s] - '0');
            }
        };
        if (dec < 0 || dec > 16777216) {
            printf("Foram digitados mais de 24 bits\n");
            system("pause");
            system("cls");
        }
    }while (dec < 0 || dec > 16777216);
    printf("\nNúmero decimal = %6X\n", dec);
    system("pause");
}
void hexadecimalDecimal2Algarismos(){
    int deci;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("HEXADECIMAL PARA DECIMAL\n2 ALGARISMOS HEXADECIMAIS\n\n");
        printf("Insira um número hexadecimal com 2 algarismos : ");
        scanf("%X", &deci);
        if (deci < 0 || deci > 255) {
            printf("Foram digitados mais de 2 algarismos\n");
            system("pause");
            system("cls");
        }
    }while (deci < 0 || deci > 255);
    printf("Representação hexadecimal = %d\n", deci);
    system("pause");
}
void hexadecimalDecimal4Algarismos(){
    int deci;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("HEXADECIMAL PARA DECIMAL\n4 ALGARISMOS HEXADECIMAIS\n\n");
        printf("Insira um número hexadecimal com 4 algarismos : ");
        scanf("%X", &deci);
        if (deci < 0 || deci > 65535) {
            printf("Foram digitados mais de 4 algarismos\n");
            system("pause");
            system("cls");
        }
    }while (deci < 0 || deci > 65535);
    printf("Representação hexadecimal = %d\n", deci);
    system("pause");
}
void hexadecimalDecimal6Algarismos(){
    int deci;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("HEXADECIMAL PARA DECIMAL\n6 ALGARISMOS HEXADECIMAIS\n\n");
        printf("Insira um número hexadecimal com 6 algarismos : ");
        scanf("%X", &deci);
        if (deci < 0 || deci > 16777216) {
            printf("Foram digitados mais de 6 algarismos\n");
            system("pause");
            system("cls");
        }
    }while (deci < 0 || deci > 16777216);
    printf("Representação hexadecimal = %d\n", deci);
    system("pause");
}
void hexadecimalBinario2Algarismos(){
    int deci, bin[8], i;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("HEXADECIMAL PARA BINÁRIO\n2 ALGARISMOS HEXADECIMAIS\n\n");
        printf("Insira um número hexadecimal com 2 algarismos : ");
        scanf("%X", &deci);
        if (deci < 0 || deci > 255) {
            printf("Foram digitados mais de 2 algarismos\n");
            system("pause");
            system("cls");
        }
        else {
            for (i = 7; i >= 0; i--){
                if (deci %2 == 0) {
                    bin[i] = 0;
                    deci = deci / 2;
                }
                else {
                    bin[i] = 1;
                    deci = deci / 2;
                }
            }
        }
    }while (deci < 0 || deci > 255);
    printf("Representação Binária = ", deci);
    for (i = 0; i <= 7; i++) {
        printf("%d", bin[i]);
        switch (i) {
            case 3:
                printf(" ");
                break;
        }
    }
    printf("\n");
    system("pause");
}
void hexadecimalBinario4Algarismos(){
    int deci, bin[16], i;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("HEXADECIMAL PARA BINÁRIO\n4 ALGARISMOS HEXADECIMAIS\n\n");
        printf("Insira um número hexadecimal com 4 algarismos : ");
        scanf("%X", &deci);
        if (deci < 0 || deci > 65535) {
            printf("Foram digitados mais de 4 algarismos\n");
            system("pause");
            system("cls");
        }
        else {
            for (i = 15; i >= 0; i--){
                if (deci %2 == 0) {
                    bin[i] = 0;
                    deci = deci / 2;
                }
                else {
                    bin[i] = 1;
                    deci = deci / 2;
                }
            }
        }
    }while (deci < 0 || deci > 65535);
    printf("Representação Binária = ", deci);
    for (i = 0; i <= 15; i++) {
        printf("%d", bin[i]);
        switch (i) {
            case 3:
            case 7:
            case 11:
                printf(" ");
                break;
        }
    }
    printf("\n");
    system("pause");
}
void hexadecimalBinario6Algarismos(){
    int deci, bin[24], i;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("HEXADECIMAL PARA BINÁRIO\n6 ALGARISMOS HEXADECIMAIS\n\n");
        printf("Insira um número hexadecimal com 6 algarismos : ");
        scanf("%X", &deci);
        if (deci < 0 || deci > 16777216) {
            printf("Foram digitados mais de 6 algarismos\n");
            system("pause");
            system("cls");
        }
        else {
            for (i = 23; i >= 0; i--){
                if (deci %2 == 0) {
                    bin[i] = 0;
                    deci = deci / 2;
                }
                else {
                    bin[i] = 1;
                    deci = deci / 2;
                }
            }
        }
    }while (deci < 0 || deci > 16777216);
    printf("Representação Binária = ", deci);
    for (i = 0; i <= 23; i++) {
        printf("%d", bin[i]);
        switch (i) {
            case 3:
            case 7:
            case 11:
            case 15:
            case 19:
                printf(" ");
                break;
        }
    }
    printf("\n");
    system("pause");
}
