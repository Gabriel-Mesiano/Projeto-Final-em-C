#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void matrizMenu();
void matriz1();
void matriz2();
void matriz3();
void matriz4();
void matriz5();
void matriz6();
void matriz7();
void matriz8();
void matriz9();

void matrizMenu()
{
    int opt;
    do {
    system("cls");
    printf("\tMENU UTILIZAÇÃO DE MATRIZES\n\n");
    printf("1 - Preencher uma matriz quadrada com números aleatórios\n");
    printf("2 - Preencher uma simetrica com números aleatórios\n");
    printf("3 - Preencher uma matriz quadrada com números inteiros\n");
    printf("4 - Preencher a diagonal de uma matriz quadrada com o valor zero\n");
    printf("5 - Preencher uma linha de uma matriz quadrada com o valor zero\n");
    printf("6 - Preencher uma coluna de uma matriz quadrada com o valor zero\n");
    printf("7 - Mostrar a média dos valores existentes em cada linha de uma matriz\n");
    printf("8 - Somar duas matrizes\n");
    printf("9 - Multiplicar duas matrizes\n");
    printf("0 - Voltar ao menu anterior\n");
    printf("Qual a sua opção? ");
    scanf("%d", &opt);

    switch (opt) {
    case 1:
        system("cls");
        matriz1();
        break;
    case 2:
        system("cls");
        matriz2();
        break;
    case 3:
        system("cls");
        matriz3();
        break;
    case 4:
        system("cls");
        matriz4();
        break;
    case 5:
        system("cls");
        matriz5();
        break;
    case 6:
        system("cls");
        matriz6();
        break;
    case 7:
        system("cls");
        matriz7();
        break;
    case 8:
        system("cls");
        matriz8();
        break;
    case 9:
        system("cls");
        matriz9();
        break;
    case 0:
        break;
    default:
        printf("Opção inválida.");
        system("pause");
    }
    }
    while (opt != 0);
}

void matriz1()
{
    int n,a,b;



    srand( (unsigned)time(NULL) );
    printf("Insira dimensão da matriz: ");
    scanf("%d", &n);


    int m[n][n];

    for (a=0; a<n; a++)



    {
        for (b=0; b<n; b++)



        {
            m[a][b]= rand()%100+1;
            printf("%4d ",m[a][b]);

        }
 printf("\n");

    }
    printf("\n\n\n");
    system("pause");
}

void matriz2()
{
    {
    srand (time(NULL));
    int ordem=0;
    printf ("\nDigite a ordem da matriz simetrica:");
    while (ordem<=0)
    {
         fflush(stdin);
         scanf ("%i", &ordem);
         if (ordem<=0)
         {
                     printf ("/n\t ERRO!! ORDEM DEVE SER MAIOR QUE ZERO!!");
                     printf ("\nDigite a ordem da matriz simetrica:");
         }
    }
    int mat[ordem][ordem],i,j;
    for (i=0; i<ordem;i++)
    {
        for (j=i;j<ordem;j++)
        {
               if (i!=j)
               {
                  mat[i][j] = rand()%101;
                  mat[j][i] = mat[i][j];
               }
               else
                  mat[i][j] = rand()%101;
        }
    }
    printf ("\n\n MATRIZ SIMETRICA GERADA:\n\n");
    for (i=0;i<ordem;i++)
    {
        for (j=0;j<ordem;j++)
          printf ("\t%i", mat[i][j]);
        printf ("\n\n");
    }
    system("pause");
}
}

void matriz3()
{
    int n,a,b;


    printf("Insira dimensão da matriz: ");
    scanf("%d", &n);


    int m[n][n];

    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)

        {
            printf("m[%d,%d]=",a+1,b+1);
            scanf("%d", &m[a][b]);

        }
    }

    printf("\nMatriz é:\n");

    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)
        {
            printf("%4d ",m[a][b]);

        }
        printf("\n");
    }
    printf("\n\n\n");
    system("pause");
}

void matriz4()
{
    int n,a,b;
    srand( (unsigned)time(NULL) );
    printf("Insira dimensão da matriz: ");
    scanf("%d", &n);
    int m[n][n];

    printf("A matriz inicial é:\n");
    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)

        {
            m[a][b]= rand()%100+1;
            printf("%4d ",m[a][b]);

        }
        printf("\n");
    }

    printf("A matriz final é:\n");
    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)

        {
            if(a==b)
                m[a][b]=0;
            printf("%4d ",m[a][b]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    system("pause");
}

void matriz5()
{
    int n,a,b,linha;
    srand( (unsigned)time(NULL) );
    printf("Insira a dimensão da matriz quadrada: ");
    scanf("%d", &n);
    int m[n][n];

    printf("Matriz Inicial\n");
    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)

        {
            m[a][b]= rand()%100+1;
            printf("%4d ",m[a][b]);

        }
        printf("\n");
    }

    do
    {
         printf("Qual o numero da linha que pretende preencher com zeros? ");
        scanf("%d",&linha);
        if(linha>n)
            printf("Escolha uma linha existente na matriz\n");
    }
    while(linha>n);


     for (a=0; a<n; a++)
     {
         for (b=0; b<n; b++)
         {
             if (a==linha-1)
                m[a][b]=0;
            printf("%4d ",m[a][b]);
         }
         printf("\n");

     }
     printf("\n\n\n");
    system("pause");
}

void matriz6()
{
    int n,a,b,coluna;
    srand( (unsigned)time(NULL) );
    printf("Insira dimensão da matriz quadrada: ");
    scanf("%d", &n);
    int m[n][n];

    printf("Matriz Inicial\n");
    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)

        {
            m[a][b]= rand()%100+1;
            printf("%4d ",m[a][b]);

        }
        printf("\n");
    }

    do
    {
         printf("Qual a coluna que pretende preencher com zeros? ");
        scanf("%d",&coluna);
        if(coluna>n)
            printf("Escolha uma coluna existente na matriz\n");
    }
    while(coluna>n);


     for (a=0; a<n; a++)
     {
         for (b=0; b<n; b++)
         {
             if (b==coluna-1)
                m[a][b]=0;
            printf("%4d ",m[a][b]);
         }
         printf("\n");

     }
     printf("\n\n\n");
    system("pause");
}

void matriz7()
{
    int n,a,b;
    float media=0;
    srand( (unsigned)time(NULL) );
    printf("Insira dimensão da matriz quadrada: ");
    scanf("%d", &n);
    int m[n][n];

    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)

        {
            m[a][b]= rand()%100+1;
            printf("%4d ",m[a][b]);
        }
        printf("\n");

    }
     printf("Média dos valores por linha\n");
     for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)

        {
            media=media+m[a][b];
        }

        media=media/n;
        printf("Linha %d: %.4f",a+1,media);
        printf("\n");
    }
    printf("\n\n\n");
    system("pause");
}

void matriz8()
{
    //Definição de variaveis
int i, j, l, c;

//Entrada de dados
printf("\n Informe a quntidade de linhas das matrizes : ");
scanf("%d",&l);
printf("\n\n Informe a quantidade de colunas das matrizes : ");
scanf("%d",&c);;
float matrizA[l][c],matrizB[l][c],matrizC[l][c];

for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                    printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da Matriz A: ", i+1, j+1);
                    scanf("%f", &matrizA[i][j]);
                    }
                    printf("\n");
                    }
for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                    printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da 2%c Matriz B: ", i+1, 167, j+1);
                    scanf("%f", &matrizB[i][j]);
                    }
                    printf("\n");
                    }
printf("---------------------------- 1 - Matriz Gerada ---------------------------------\n\n");
for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                   printf("%6.f", matrizA[i][j]);
                   }
                   printf("\n\n");
                   }
printf("---------------------------- 2 - Matriz Gerada ---------------------------------\n\n");
for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                   printf("%6.f", matrizB[i][j]);
                   }
                   printf("\n\n");
                   }
//Processamento e saida em tela
for(i=0; i<l; i++)
{
         matrizC[i][j]=0;
         for(j=0; j<c; j++)
         {
                  matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
                  }
                  }
                  printf("\n\n");
printf("---------------------------- 3 - Matriz Soma duas Matrizes ---------------------------------\n\n");
for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                   printf("%6.f", matrizC[i][j]);
                   }
                   printf("\n\n");
                   }
                   printf("\n\n");
system("pause");
}

void matriz9()
{
    //Definição de variaveis
int i, j, l, c;

//Entrada de dados
printf("\n Informe a quntidade de linhas das matrizes : ");
scanf("%d",&l);
printf("\n\n Informe a quantidade de colunas das matrizes : ");
scanf("%d",&c);;
float matrizA[l][c],matrizB[l][c],matrizC[l][c];

for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                    printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da Matriz A: ", i+1, 167, j+1, 167);
                    scanf("%f", &matrizA[i][j]);
                    }
                    printf("\n");
                    }
for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                    printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da 2%c Matriz B: ", i+1, 167, j+1, 167, 167);
                    scanf("%f", &matrizB[i][j]);
                    }
                    printf("\n");
                    }
printf("---------------------------- 1 - Matriz Gerada ---------------------------------\n\n");
for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                   printf("%6.f", matrizA[i][j]);
                   }
                   printf("\n\n");
                   }
printf("---------------------------- 2 - Matriz Gerada ---------------------------------\n\n");
for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                   printf("%6.f", matrizB[i][j]);
                   }
                   printf("\n\n");
                   }
//Processamento e saida em tela
for(i=0; i<l; i++)
{
         matrizC[i][j]=0;
         for(j=0; j<c; j++)
         {
                  matrizC[i][j] = matrizA[i][j] * matrizB[i][j];
                  }
                  }
                  printf("\n\n");
printf("---------------------------- 3 - Matriz Gerada ---------------------------------\n\n");
for(i=0; i<l; i++)
{
           for(j=0; j<c; j++)
           {
                   printf("%6.f", matrizC[i][j]);
                   }
                   printf("\n\n");
                   }
                   printf("\n\n");
system("pause");
}
