#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "gestor.h"
#include "gestorComandos.h"

void gestorInit(void)
{
    system("cls");
    printf("\nIniciando Gestor de Presenças...");
    char nomes[150][512], command[65536], output[65536], numeros[150][512], present[150][512], temp[65536], filedata[65536];
    output[0] = '\0';
    int quant, pagina, sair, modo;
    quant = 0;
    sair = 0;
    pagina = 0;
    modo = 1;
    FILE * gestorficheiro;
    gestorficheiro = fopen("dadosGestor", "r+");
    if (gestorficheiro == NULL) {
        gestorficheiro = fopen("dadosGestor", "w+");
        if (gestorficheiro == NULL) {
            printf("\nERRO: Não foi possivel criar o ficheiro de dados\nO gestor vai fechar.\n\nPrima [ENTER] para continuar");
            getchar();
            return;
        }
    }
    int i,j,ler,ord,linha;
    i = 0;
    j = 0;
    ler = -1;
    ord = 0;
    linha = 0;
    while (1) {
        if (feof(gestorficheiro)) break;
        filedata[i] = fgetc(gestorficheiro);
        if (filedata[i] == '"') {
            if (ler < 0) ler = i;
            else {
                for (j=ler+1; j<i; j++) {
                    if (ord == 0) {
                        numeros[linha][j-ler-1] = filedata[j];
                    }
                    else if (ord == 1) {
                        nomes[linha][j-ler-1] = filedata[j];
                    }
                    else {
                        present[linha][j-ler-1] = filedata[j];
                    }
                }
                ord++;
                if (ord>2) {
                    ord = 0;
                    linha++;
                    quant++;
                }
                ler = -1;
            }
        }
        i++;
    }
    rewind(gestorficheiro);
    fclose(gestorficheiro);
    printf("\nIniciado com sucesso.");
    while (sair != 1) {
        gestorAtualizarEcra(quant, nomes, numeros, present, pagina, output, 1, modo);
        fflush(stdin);
        gets(command);
        gestorConsola(command, output, &sair, nomes, numeros, present, &quant, &pagina, modo, &modo);
        //fclose(gestorficheiro);
        //remove("dadosGestor");
        gestorficheiro = fopen("dadosGestor", "w+");
        rewind(gestorficheiro);
        /*i = 0;
        while (1) {
            if (feof(gestorficheiro)) break;
            fgetc(gestorficheiro);
            i++;
        }
        j = i;
        i = 0;
        rewind(gestorficheiro);
        while (j > 0) {
            fgetc(gestorficheiro);
            i++;
            if (i >= j) {
                j--;
                putc(EOF, gestorficheiro);
                i = 0;
                rewind(gestorficheiro);
            }
        }
        */
        for (i=0;i<quant;i++) {
            fputc('"', gestorficheiro);
            fprintf(gestorficheiro, numeros[i]);
            fputc('"', gestorficheiro);
            fputc(' ', gestorficheiro);
            fputc('"', gestorficheiro);
            fprintf(gestorficheiro, nomes[i]);
            fputc('"', gestorficheiro);
            fputc(' ', gestorficheiro);
            fputc('"', gestorficheiro);
            fprintf(gestorficheiro, present[i]);
            fputc('"', gestorficheiro);
            fputc('\n', gestorficheiro);
        }
        fclose(gestorficheiro);
    }
}

void gestorAtualizarEcra(int q, char names[150][512], char nums[150][512], char pres[150][512], int pag, char out[], int mostrarcoms, int simples)
{
    int i, l, min;
    system("cls");
    printf("\tGESTOR DE PRESENÇAS\n\n");
    l = 0;
    if (q-pag*10>=10) min = (pag+1)*10;
    else min = q;
    if (q==0) {
        printf("[SEM REGISTOS]");
        l = 1;
    }
    else for (i=pag*10; i<min; i++) {
        printf("%s - %s; %s presenças\n", nums[i], names[i], pres[i]);
        l++;
    }
    while (l<12) {
        printf("\n");
        l++;
    }
    int totpag;
    if (q <= 0) totpag = 1;
    else totpag = (int)ceil((float)q/10);
    printf("Página %d de %d\n\n", pag+1, totpag);
    if (mostrarcoms == 1) {
        if (simples == 1)
            gestorMostrarComandos();
        printf("\n%s\n>> ", out);
    }
    out[0] = '\0';
}

void gestorMostrarComandos()
{
    printf("1 - Adicionar registo\n");
    printf("2 - Modificar registo\n");
    printf("3 - Apagar registo\n");
    printf("4 - Ordenar registos\n");
    printf("5 - Pesquisa\n");
    printf("6 - Mudar de página\n");
    printf("7 - Mudar para modo avançado\n");
    printf("8 - Reset do gestor (apaga todos os registos, irreversivel)\n");
    printf("0 - Sair\n");
}

int gestorSeNumeros(char str[])
{
    int i;
    i = 0;
    while (strlen(str) > i) {
        if (str[i] < 48 || str[i] > 57)
            return 0;
        i++;
    }
    return 1;
}

int gestorStrParaInt(char str[])
{
    int i, result;
    i = 0;
    result = 0;
    while (strlen(str) > i) {
        result = result + (str[i]-48)*((int)pow(10, strlen(str)-i-1));
        i++;
    }
    return result;
}
