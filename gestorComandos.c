#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "gestor.h"
#include "gestorComandos.h"

void gestorConsola(char cmd[], char out[], int* s, char names[150][512], char nums[150][512], char pres[150][512], int* q, int* p, int mode, int* m)
{
    char aux[1024][1024];
    int i, j, ign, arg, offset, quant, pag, done;
    for (i=0; i<1024; i++) {
        for (j=0; j<1024; j++) {
            aux[i][j] = '\0';
        }
    }
    offset = 0;
    ign = 0;
    arg = 0;
    quant = *q;
    pag = *p;
    for(i=0;i<65536;i++) {
        if (cmd[i] == ' ' && ign == 0) {
            for (j=offset; j<i; j++) {
                aux[arg][j-offset] = cmd[j];
            }
            aux[arg][i] = '\0';
            offset = i+1;
            arg++;
        }
        else if (cmd[i] == ' ' && ign == 2) {
           offset = i+1;
           ign = 0;
        }
        else if (cmd[i] == '"' || cmd[i] == 47) {
            if (ign == 0) ign = 1;
            else {
                for (j=offset+1; j<i; j++) {
                    aux[arg][j-offset-1] = cmd[j];
                }
                aux[arg][i-1] = '\0';
                offset = i+1;
                arg++;
                ign = 2;
            }
        }
        else if (cmd[i] == '\0') {
            for (j=offset; j<i; j++) {
                aux[arg][j-offset] = cmd[j];
            }
            aux[arg][i] = '\0';
            offset = i+1;
            arg++;
            break;
        }
    }

    if (ign == 1) {
        char temp[] = "ERRO: Argumento infinito (apóstrofes ou aspas incompletas)";
        strcpy(out, temp);
        return;
    }
    if (mode != 1) {
    strlwr(aux[0]);
    if (strcmp(aux[0],"sair")==0) {
        if (arg == 1)
            *s = 1;
        else {
            char temp[] = "ERRO: Nº de argumentos inválido";
            strcpy(out, temp);
        }
    }
    else if (strcmp(aux[0],"add")==0) {
        if (arg == 4) {
            char temp[65536];
            strcpy(temp, aux[1]);
            if (gestorSeNumeros(temp)==1) {
                strcpy(temp, aux[3]);
                if (gestorSeNumeros(temp)==1) {
                    if (quant < 150) {
                        strcpy(nums[quant], aux[1]);
                        strcpy(names[quant], aux[2]);
                        strcpy(pres[quant], aux[3]);
                        *q = quant+1;
                        quant = quant+1;
                        char temp[] = "Adicionado um registo";
                        strcpy(out, temp);
                    }
                    else {
                        char temp[] = "ERRO: Nº máximo de registos alcançado";
                        strcpy(out, temp);
                    }
                }
                else {
                    char temp[] = "ERRO: argumento 3 só aceita números";
                    strcpy(out, temp);
                }
            }
            else {
                char temp[] = "ERRO: argumento 1 só aceita números";
                strcpy(out, temp);
            }
        }
        else {
            char temp[] = "ERRO: Nº de argumentos inválido";
            strcpy(out, temp);
        }
    }
    else if (strcmp(aux[0],"pag")==0) {
        if (arg == 2) {
            if (gestorSeNumeros(aux[1])==1) {
                int limpag;
                if (quant <= 0) limpag = 1;
                else limpag = (int)ceil((float)quant/10);
                int pagnovo;
                pagnovo = gestorStrParaInt(aux[1]);
                if (pagnovo > 0 && pagnovo <= limpag) *p = pagnovo-1;
                else {
                   char temp[] = "ERRO: página não existe";
                    strcpy(out, temp);
                }
            }
            else {
                char temp[] = "ERRO: argumento 1 só aceita números";
                strcpy(out, temp);
            }
        }
        else {
            char temp[] = "ERRO: Nº de argumentos inválido";
            strcpy(out, temp);
        }
    }
    else if (strcmp(aux[0],"ajuda")==0) {
        system("cls");
        printf("\tAJUDA\n\n");
        printf("ajuda - Apresenta um menu de comandos\n");
        printf("add <numaluno> <nome> <numpresencas> - Adiciona um registo\n");
        printf("del <linha> - Seleciona uma linha relativa à página atual para apagar\n");
        printf("mod <linha> - Seleciona uma linha relativa à página atual para modificar valores\n");
        printf("ordenar <numero|nome|presenca> - Ordena a lista pelo parametro introduzido\n");
        printf("pag <numero> - Muda a página para a que for introduzida\n");
        printf("pesq <numero|nome> <val> - Muda a página para a que for introduzida\n");
        printf("reset - Faz um reset ao gestor, eliminando todo os registos (irreversível)\n");
        printf("sair - Fecha o gestor de presenças\n");
        printf("simple - Muda o gestor de presenças para o modo básico\n");
        printf("\nPressione [ENTER] para continuar...");
        getchar();
    }
    else if (strcmp(aux[0],"del")==0) {
        if (arg == 2) {
            if (gestorSeNumeros(aux[1])==1) {
                if (gestorStrParaInt(aux[1]) <= quant-pag*10 && gestorStrParaInt(aux[1]) > 0 && gestorStrParaInt(aux[1]) <= 10) {
                    gestorDel(names, nums, pres, q, p, gestorStrParaInt(aux[1]), out);
                }
                else {
                    char temp[] = "ERRO: registo não existe";
                strcpy(out, temp);
                }
            }
            else {
                char temp[] = "ERRO: argumento 1 só aceita números";
                strcpy(out, temp);
            }
        }
        else {
            char temp[] = "ERRO: Nº de argumentos inválido";
            strcpy(out, temp);
        }
    }
    else if (strcmp(aux[0],"ordenar")==0) {
        if (arg==2) {
            if (strcmp(aux[1],"numero")==0) {
                done = 0;
                while (done!=1) {
                    done = 1;
                    for (i=1; i<quant; i++) {
                        if (gestorStrParaInt(nums[i]) < gestorStrParaInt(nums[i-1])) {
                            char trocar[512];
                            strcpy(trocar, nums[i]);
                            strcpy(nums[i], nums[i-1]);
                            strcpy(nums[i-1], trocar);

                            strcpy(trocar, names[i]);
                            strcpy(names[i], names[i-1]);
                            strcpy(names[i-1], trocar);

                            strcpy(trocar, pres[i]);
                            strcpy(pres[i], pres[i-1]);
                            strcpy(pres[i-1], trocar);
                            done = 0;
                        }
                    }
                }
                char temp[] = "Ordenado por números";
                strcpy(out, temp);
            }
            else if (strcmp(aux[1],"nome")==0) {
                done = 0;
                while (done!=1) {
                    done = 1;
                    for (i=1; i<quant; i++) {
                        if (strcasecmp(names[i], names[i-1])<0) {
                            char trocar[512];
                            strcpy(trocar, nums[i]);
                            strcpy(nums[i], nums[i-1]);
                            strcpy(nums[i-1], trocar);

                            strcpy(trocar, names[i]);
                            strcpy(names[i], names[i-1]);
                            strcpy(names[i-1], trocar);

                            strcpy(trocar, pres[i]);
                            strcpy(pres[i], pres[i-1]);
                            strcpy(pres[i-1], trocar);
                            done = 0;
                        }
                    }
                }
                char temp[] = "Ordenado por nomes";
                strcpy(out, temp);
            }
            else if (strcmp(aux[1],"presenca")==0) {
                done = 0;
                while (done!=1) {
                    done = 1;
                    for (i=1; i<quant; i++) {
                        if (gestorStrParaInt(pres[i]) < gestorStrParaInt(pres[i-1])) {
                            char trocar[512];
                            strcpy(trocar, nums[i]);
                            strcpy(nums[i], nums[i-1]);
                            strcpy(nums[i-1], trocar);

                            strcpy(trocar, names[i]);
                            strcpy(names[i], names[i-1]);
                            strcpy(names[i-1], trocar);

                            strcpy(trocar, pres[i]);
                            strcpy(pres[i], pres[i-1]);
                            strcpy(pres[i-1], trocar);
                            done = 0;
                        }
                    }
                }
                char temp[] = "Ordenado por presenças";
                strcpy(out, temp);
            }
            else {
                char temp[] = "ERRO: argumento 1 inválido";
                strcpy(out, temp);
            }
        }
        else {
            char temp[] = "ERRO: Nº de argumentos inválido";
            strcpy(out, temp);
        }
    }
    else if (strcmp(aux[0],"mod")==0) {
        if (arg == 2) {
            if (gestorSeNumeros(aux[1])==1) {
                if (gestorStrParaInt(aux[1]) <= quant-pag*10 && gestorStrParaInt(aux[1]) > 0 && gestorStrParaInt(aux[1]) <= 10) {
                    gestorMod(names, nums, pres, q, p, gestorStrParaInt(aux[1]), out, 1);
                }
                else {
                    char temp[] = "ERRO: registo não existe";
                strcpy(out, temp);
                }
            }
            else {
                char temp[] = "ERRO: argumento 1 só aceita números";
                strcpy(out, temp);
            }
        }
        else {
            char temp[] = "ERRO: Nº de argumentos inválido";
            strcpy(out, temp);
        }
    }
    else if (strcmp(aux[0], "pesq") == 0) {
        if (arg == 3) {
                int found = 0;
            if (strcmp(aux[1], "numero") == 0) {
                if (gestorSeNumeros(aux[2]) == 1) {
                    for (i=0; i<quant; i++) {
                        if (strcmp(nums[i], aux[2]) == 0) {
                            *p = (int) ceil(i/10);
                            found = 1;
                            break;
                        }
                    }
                    if (found == 1) {
                        char temp[] = "Registo encontrado";
                        strcpy(out, temp);
                    }
                    else {
                        char temp[] = "Registo não encontrado";
                        strcpy(out, temp);
                    }
                }
            }
            else if (strcmp(aux[1], "nome") == 0) {
                for (i=0; i<quant; i++) {
                    if (strcmp(names[i], aux[2]) == 0) {
                        *p = (int) ceil(i/10);
                        found = 1;
                        break;
                    }
                }
                if (found == 1) {
                    char temp[] = "Registo encontrado";
                    strcpy(out, temp);
                }
                else {
                    char temp[] = "Registo não encontrado";
                    strcpy(out, temp);
                }
            }
            else {
                char temp[] = "ERRO: argumento 1 inválido";
                strcpy(out, temp);
            }
        }
        else {
            char temp[] = "ERRO: Nº de argumentos inválido";
            strcpy(out, temp);
        }
    }
    else if (strcmp(aux[0], "simple") == 0) {
        if (arg == 1) {
            *m = 1;
            char temp[] = "Modo básico ativado";
            strcpy(out, temp);
        }
        else {
            char temp[] = "ERRO: Nº de argumentos inválido";
            strcpy(out, temp);
        }
    }
    else if (strcmp(aux[0],"reset")==0) {
        if (arg == 1) {
            char doreset[16];
            do {
                system("cls");
                printf("\tRESET\n\nTem a certeza que quer fazer reset? Os dados vão ser perdidos para sempre! <s/n> ");
                gets(doreset);
            }
            while (strcasecmp(doreset, "s") != 0 && strcasecmp(doreset, "n") != 0);
            if (strcasecmp(doreset, "s") == 0) {
                *q = 0;
                *p = 0;
                char temp[] = "Reset ativado";
                strcpy(out, temp);
            }
        }
        else {
            char temp[] = "ERRO: Nº de argumentos inválido";
            strcpy(out, temp);
        }
    }
    else {
        char temp[] = "ERRO: Comando desconhecido. Para uma lista de comandos, escreva 'ajuda'";
        strcpy(out, temp);
    }
    }
    else {
        char ex[65536];
        if (strcmp(cmd, "0") == 0) {
            *s = 1;
        }
        else if (strcmp(cmd, "1") == 0) {
            if (quant < 150) {
            system("cls");
            printf("\tADICIONAR\n\n\nInsira o número de aluno: ");
            gets(ex);
            while (gestorSeNumeros(ex) != 1) {
                system("cls");
                printf("\tADICIONAR\n\nERRO: Foi introduzido letras ou espaços\nInsira o número de aluno: ");
                gets(ex);
            }
            strcpy(nums[quant], ex);
            system("cls");
            printf("\tADICIONAR\n\n\nInsira o nome de aluno: ");
            gets(ex);
            strcpy(names[quant], ex);
            system("cls");
            printf("\tADICIONAR\n\n\nInsira o número de presenças deste aluno: ");
            gets(ex);
            while (gestorSeNumeros(ex) != 1) {
                system("cls");
                printf("\tADICIONAR\n\nERRO: Foi introduzido letras ou espaços\nInsira o número de presenças deste aluno: ");
                gets(ex);
            }
            strcpy(pres[quant], ex);
            *q = quant + 1;
            char temp[] = "Registo adicionado";
            strcpy(out, temp);
            }
            else {
                char temp[] = "ERRO: número máximo de registos alcançado";
                strcpy(out, temp);
            }
        }
        else if (strcmp(cmd, "2") == 0) {
            gestorAtualizarEcra(quant, names, nums, pres, pag, out, 0, 1);
            printf("NOTA: A linha selecionada é relativa à página atual\nSelecione uma linha: ");
            gets(ex);
            if (gestorSeNumeros(ex) == 1) {
                if (gestorStrParaInt(ex) <= quant-pag*10 && gestorStrParaInt(ex) > 0 && gestorStrParaInt(ex) <= 10) {
                    gestorMod(names, nums, pres, q, p, gestorStrParaInt(ex), out, 1);
                }
                else {
                    char temp[] = "ERRO: linha não existe";
                    strcpy(out, temp);
                }
            }
            else {
                char temp[] = "ERRO: letra/espaço adicionado";
                strcpy(out, temp);
            }
        }
        else if (strcmp(cmd, "3") == 0) {
            gestorAtualizarEcra(quant, names, nums, pres, pag, out, 0, 1);
            printf("NOTA: A linha selecionada é relativa à página atual\nSelecione uma linha: ");
            gets(ex);
            if (gestorSeNumeros(ex)==1) {
                if (gestorStrParaInt(ex) <= quant-pag*10 && gestorStrParaInt(ex) > 0 && gestorStrParaInt(ex) <= 10) {
                    gestorDel(names, nums, pres, q, p, gestorStrParaInt(ex), out);
                }
                else {
                    char temp[] = "ERRO: registo não existe";
                strcpy(out, temp);
                }
            }
            else {
                char temp[] = "ERRO: letra/espaço adicionado";
                strcpy(out, temp);
            }
        }
        else if (strcmp(cmd, "4") == 0) {
            gestorAtualizarEcra(quant, names, nums, pres, pag, out, 0, 1);
            printf("Ordenar por:\n 1 - Número\n 2 - Nome\n 3 - Presenças\n");
            gets(ex);
            if (strcmp(ex, "1") == 0) {
                done = 0;
                while (done!=1) {
                    done = 1;
                    for (i=1; i<quant; i++) {
                        if (gestorStrParaInt(nums[i]) < gestorStrParaInt(nums[i-1])) {
                            char trocar[512];
                            strcpy(trocar, nums[i]);
                            strcpy(nums[i], nums[i-1]);
                            strcpy(nums[i-1], trocar);

                            strcpy(trocar, names[i]);
                            strcpy(names[i], names[i-1]);
                            strcpy(names[i-1], trocar);

                            strcpy(trocar, pres[i]);
                            strcpy(pres[i], pres[i-1]);
                            strcpy(pres[i-1], trocar);
                            done = 0;
                        }
                    }
                }
                char temp[] = "Ordenado por números";
                strcpy(out, temp);
            }
            else if (strcmp(ex, "2") == 0) {
                done = 0;
                while (done!=1) {
                    done = 1;
                    for (i=1; i<quant; i++) {
                        if (strcasecmp(names[i], names[i-1])<0) {
                            char trocar[512];
                            strcpy(trocar, nums[i]);
                            strcpy(nums[i], nums[i-1]);
                            strcpy(nums[i-1], trocar);

                            strcpy(trocar, names[i]);
                            strcpy(names[i], names[i-1]);
                            strcpy(names[i-1], trocar);

                            strcpy(trocar, pres[i]);
                            strcpy(pres[i], pres[i-1]);
                            strcpy(pres[i-1], trocar);
                            done = 0;
                        }
                    }
                }
                char temp[] = "Ordenado por nomes";
                strcpy(out, temp);
            }
            else if (strcmp(ex, "3") == 0) {
                done = 0;
                while (done!=1) {
                    done = 1;
                    for (i=1; i<quant; i++) {
                        if (gestorStrParaInt(pres[i]) < gestorStrParaInt(pres[i-1])) {
                            char trocar[512];
                            strcpy(trocar, nums[i]);
                            strcpy(nums[i], nums[i-1]);
                            strcpy(nums[i-1], trocar);

                            strcpy(trocar, names[i]);
                            strcpy(names[i], names[i-1]);
                            strcpy(names[i-1], trocar);

                            strcpy(trocar, pres[i]);
                            strcpy(pres[i], pres[i-1]);
                            strcpy(pres[i-1], trocar);
                            done = 0;
                        }
                    }
                }
                char temp[] = "Ordenado por presenças";
                strcpy(out, temp);
            }
            else {
                char temp[] = "ERRO: opção inválida";
                strcpy(out, temp);
            }
        }
        else if (strcmp(cmd, "5") == 0)
            gestorPesquisa(names, nums, pres, q, p, out);
        else if (strcmp(cmd, "6") == 0) {
            gestorAtualizarEcra(quant, names, nums, pres, pag, out, 0, 1);
            printf("Insira o número de página: ");
            gets(ex);
            if (gestorSeNumeros(ex) == 1) {
                int limpag;
                if (quant <= 0) limpag = 1;
                else limpag = (int)ceil((float)quant/10);
                int pagnovo;
                pagnovo = gestorStrParaInt(ex);
                if (pagnovo > 0 && pagnovo <= limpag) *p = pagnovo-1;
                else {
                    char temp[] = "ERRO: página inválida";
                    strcpy(out, temp);
                }
            }
            else {
                char temp[] = "ERRO: página inválida";
                strcpy(out, temp);
            }
        }
        else if (strcmp(cmd, "7") == 0) {
            *m = 0;
            char temp[] = "Modo avançado ativado (escreva 'ajuda' para abrir um menu com todos os comandos avançados)";
            strcpy(out, temp);
        }
        else if (strcmp(cmd, "8") == 0) {
            char doreset[16];
            do {
                system("cls");
                printf("\tRESET\n\nTem a certeza que quer fazer reset? Os dados vão ser perdidos para sempre! <s/n> ");
                gets(doreset);
            }
            while (strcasecmp(doreset, "s") != 0 && strcasecmp(doreset, "n") != 0);
            if (strcasecmp(doreset, "s") == 0) {
                *q = 0;
                *p = 0;
                char temp[] = "Reset ativado";
                strcpy(out, temp);
            }
        }
        else {
            char temp[] = "ERRO: opção inválida";
            strcpy(out, temp);
        }
    }
}

void gestorDel(char names[150][512], char nums[150][512], char pres[150][512], int* q, int* p, int line, char out[])
{
    int quant, pag;
    quant = *q;
    pag = *p;

    int i, l, min;
    char opcao[512];

    do {
        system("cls");
        printf("\tAPAGAR\n\n");
        l = 0;
        if (quant-pag*10>=10) min = (pag+1)*10;
        else min = quant;
        for (i=pag*10; i<min; i++) {
            if (line-1 == l) {
                printf(">> %s - %s; %s presenças\n", nums[i], names[i], pres[i]);
            }
            else {
            printf("%s - %s; %s presenças\n", nums[i], names[i], pres[i]);
            }
            l++;
        }
        while (l<12) {
            printf("\n");
            l++;
        }
        printf("Apagar o registo selecionado? <s/n> ");
        gets(opcao);
    }
    while (strcasecmp(opcao, "s") != 0 && strcasecmp(opcao, "n") != 0);

    if (strcasecmp(opcao, "s") == 0) {
        for (i=line-1+pag*10; i<(quant-1); i++) {
            strcpy(nums[i],nums[i+1]);
            strcpy(names[i],names[i+1]);
            strcpy(pres[i],pres[i+1]);
        }
        *q = *q - 1;
        quant = *q;
        if (quant%10 == 0 && pag > 0) pag--;
        char temp[] = "Registo apagado";
        strcpy(out, temp);
    }
    else {
        char temp[] = "Remoção cancelada";
        strcpy(out, temp);
    }
}

void gestorMod(char names[150][512], char nums[150][512], char pres[150][512], int* q, int* p, int line, char out[], int mode)
{
    int quant, pag;
    quant = *q;
    pag = *p;

    int i, l, min;
    char opcao[512], opcao2[512];

    do {
        system("cls");
        printf("\tMODIFICAR\n\n");
        l = 0;
        if (quant-pag*10>=10) min = (pag+1)*10;
        else min = quant;
        for (i=pag*10; i<min; i++) {
            if (line-1 == l) {
                printf(">> %s - %s; %s presenças\n", nums[i], names[i], pres[i]);
            }
            else {
            printf("%s - %s; %s presenças\n", nums[i], names[i], pres[i]);
            }
            l++;
        }
        while (l<12) {
            printf("\n");
            l++;
        }
        printf("Modificar o registo selecionado? <s/n> ");
        gets(opcao);
    }
    while (strcasecmp(opcao, "s") != 0 && strcasecmp(opcao, "n") != 0);

    if (strcasecmp(opcao, "s") == 0) {
        if (mode != 1) {
        do {
            system("cls");
            printf("\tMODIFICAR\n\n");
            l = 0;
            if (quant-pag*10>=10) min = (pag+1)*10;
            else min = quant;
            for (i=pag*10; i<min; i++) {
                if (line-1 == l) {
                    printf(">> %s - %s; %s presenças\n", nums[i], names[i], pres[i]);
                }
                else {
                printf("%s - %s; %s presenças\n", nums[i], names[i], pres[i]);
                }
                l++;
            }
            while (l<12) {
                printf("\n");
                l++;
            }
            printf("Modificar que parametro? <numero|nome|presenca> ");
            gets(opcao);
        }
        while (strcasecmp(opcao, "numero") != 0 && strcasecmp(opcao, "nome") != 0 && strcasecmp(opcao, "presenca") != 0);
        }
        else {
            do {
            system("cls");
            printf("\tMODIFICAR\n\n");
            l = 0;
            if (quant-pag*10>=10) min = (pag+1)*10;
            else min = quant;
            for (i=pag*10; i<min; i++) {
                if (line-1 == l) {
                    printf(">> %s - %s; %s presenças\n", nums[i], names[i], pres[i]);
                }
                else {
                printf("%s - %s; %s presenças\n", nums[i], names[i], pres[i]);
                }
                l++;
            }
            while (l<12) {
                printf("\n");
                l++;
            }
            printf("Modificar que parametro?\n 1 - Número\n 2 - Nome\n 3 - Presenças\n");
            gets(opcao);
        }
        while (strcasecmp(opcao, "1") != 0 && strcasecmp(opcao, "2") != 0 && strcasecmp(opcao, "3") != 0);
        }
        if (strcasecmp(opcao, "1") == 0) {
            char temp[] = "numero";
            strcpy(opcao, temp);
        }
        else if (strcasecmp(opcao, "2") == 0) {
            char temp[] = "nome";
            strcpy(opcao, temp);
        }
        else {
            char temp[] = "presenca";
            strcpy(opcao, temp);
        }
        system("cls");
        printf("\tMODIFICAR\n\n");
        l = 0;
        if (quant-pag*10>=10) min = (pag+1)*10;
        else min = quant;
        for (i=pag*10; i<min; i++) {
            if (line-1 == l) {
                printf(">> %s - %s; %s presenças\n", nums[i], names[i], pres[i]);
            }
            else {
            printf("%s - %s; %s presenças\n", nums[i], names[i], pres[i]);
            }
            l++;
        }
        while (l<12) {
            printf("\n");
            l++;
        }
        printf("\nInsira o novo valor: ");
        gets(opcao2);
        if ((strcasecmp(opcao, "numero") == 0 || strcasecmp(opcao, "presenca") == 0) && gestorSeNumeros(opcao2) == 0) {
            do {
                system("cls");
                printf("\tMODIFICAR\n\n");
                l = 0;
                if (quant-pag*10>=10) min = (pag+1)*10;
                else min = quant;
                for (i=pag*10; i<min; i++) {
                    if (line-1 == l) {
                        printf(">> %s - %s; %s presenças\n", nums[i], names[i], pres[i]);
                    }
                    else {
                    printf("%s - %s; %s presenças\n", nums[i], names[i], pres[i]);
                    }
                    l++;
                }
                while (l<12) {
                    printf("\n");
                    l++;
                }
                printf("Valor tem de ser um número!\nInsira o novo valor: ");
                gets(opcao2);
            }
            while ((strcasecmp(opcao, "numero") == 0 || strcasecmp(opcao, "presenca") == 0) && gestorSeNumeros(opcao2) == 0);
        }
        if (strcasecmp(opcao, "numero") == 0) {
            for (i=0; i<512; i++) {
                nums[line-1+pag][i] = '\0';
            }
            strcpy(nums[line-1+pag], opcao2);
        }
        else if (strcasecmp(opcao, "nome") == 0) {
            for (i=0; i<512; i++) {
                names[line-1+pag][i] = '\0';
            }
            strcpy(names[line-1+pag], opcao2);
        }
        else {
            for (i=0; i<512; i++) {
                pres[line-1+pag][i] = '\0';
            }
            strcpy(pres[line-1+pag], opcao2);
        }
        char temp[] = "Modificação concluida";
        strcpy(out, temp);
    }
    else {
        char temp[] = "Modificação cancelada";
        strcpy(out, temp);
    }
}

void gestorPesquisa(char names[150][512], char nums[150][512], char pres[150][512], int* q, int* p, char out[])
{
    int quant, pag, i, found;
    char opt[65536];
    quant = *q;
    pag = *p;
    found = 0;
    system("cls");
    printf("\tPESQUISA\n\n\nPesquisar por:\n 1 - Número\n 2 - Nome\n>>");
    gets(opt);
    if (strcmp(opt, "1") == 0) {
        do {
            system("cls");
            printf("\tPESQUISA\n\n\nInsira o número: ");
            gets(opt);
        }
        while (gestorSeNumeros(opt) != 1);
        for (i=0; i<quant; i++) {
            if (strcmp(nums[i], opt) == 0) {
                *p = (int) ceil(i/10);
                found = 1;
                break;
            }
        }
        if (found == 1) {
            char temp[] = "Registo encontrado";
            strcpy(out, temp);
        }
        else {
            char temp[] = "Registo não encontrado";
            strcpy(out, temp);
        }
    }
    else if (strcmp(opt, "2") == 0) {
        system("cls");
        printf("\tPESQUISA\n\n\nInsira o nome: ");
        gets(opt);
        for (i=0; i<quant; i++) {
            if (strcasecmp(names[i], opt) == 0) {
                *p = (int) ceil(i/10);
                found = 1;
                break;
            }
        }
        if (found == 1) {
            char temp[] = "Registo encontrado";
            strcpy(out, temp);
        }
        else {
            char temp[] = "Registo não encontrado";
            strcpy(out, temp);
        }
    }
}
