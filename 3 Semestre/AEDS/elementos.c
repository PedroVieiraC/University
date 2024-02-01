#include <stdio.h>
#include <stdlib.h>

typedef struct peso
{
    int num;
    int tipo;
} Peso;

typedef struct mat
{
    int tipo;
    int repet;

} Matriz;

int main()
{

    int n;
    scanf("%i", &n);

    int v[n];

    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }

    Peso peso[n];

    // recebe entradas e declara peso -1
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &v[i]);
        peso[i].num = v[i];
    }

    // codifica o número e conta a quantidade de tipos
    for (int i = 0; i < n; i++)
    {

            if(peso[i].num ==0) peso[i].tipo = 1;
            if(peso[i].num ==128) peso[i].tipo = 2;
            if(peso[i].num ==256) peso[i].tipo = 3;
            
    }
    

    for(int i=0;i<n;i++){
        printf("n %i t %i\n", peso[i].num,peso[i].tipo);
    }

    printf("\n");

    int cont = 1;

    // conta o tamanho de v2
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        if (peso[i].num != peso[j].num)
            cont++;
    }

    Matriz matriz[cont];

    // inicializa a struct da matriz como 1
    for (int i = 0; i < cont; i++)
    {
        matriz[i].repet = 1;
        matriz[i].tipo = peso[i].tipo;
    }



    // coloca em matriz.repet o tamanho de cada repeticao de estrutura
    int aux = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        if (peso[i].num == peso[j].num)
        {
            matriz[aux].repet++;
        }
        
        else
        {
            aux++;
        }
    }

    printf("tipo: ");
    for (int i = 0; i < cont; i++)
    {
        printf("%i ", matriz[i].tipo);
    }

    printf("\nrepeticoes: ");
    for (int i = 0; i < cont; i++)
    {
        printf("%i ", matriz[i].repet);
    }

    printf("\n");

    int vetorComparacao[5] = {1, 3, 2, 3, 1};

    int cr = 0, conf = 0;

    /*for (int i = 0; i < cont; i++)
    {

        if (matriz[i].tipo == vetorComparacao[0])
        {
            printf("%i = %i \n", matriz[i].tipo, vetorComparacao[0]);

            cr++;
            int k = 1, ar= i+3;
            for (int j=i+1;j<ar;j++){
                if(matriz[j].tipo == vetorComparacao[k]){
                    cr++;
                    k++;
                }
            }
            if(cr == 6) conf = 1;
        }
            cr=0;

    }
    for (int i = 0; i < cont; i++)
     {
         for (int j = 1; j < 5; j++)
         {
             if (matriz[i].tipo == vetorComparacao[0])
             {
                 printf("%i = %i \n",matriz[i].tipo, vetorComparacao[0]);

                 cr++;

                 int k = i + 1;
                 if (matriz[k].tipo == vetorComparacao[j])
                 {
                     printf("%i = %i \n",matriz[k].tipo, vetorComparacao[j]);
                     cr++;
                     k++;

                 }
             }
             if (cr == 5)
                 conf = 1;
             cr = 0;
         }
     }*/

    if (conf == 1)
        printf("padrao encontrado\n");
    else
        printf("nao encontrado\n");

    /*
        // Alocar memória para array de ponteiros
        int **matrix = (int **)malloc(2 * sizeof(int *));

        // Alocar memória para cada linha da matriz
        for (int i = 0; i < 2; i++)
        {
            matrix[i] = (int *)malloc(cont * sizeof(int));
        }

        for (int i = 0; i < cont; i++)
        {
            matrix[0][i] = matriz[i].tipo;
            matrix[1][i] = matriz[i].repet;
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < cont; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        // Liberar memória alocada
        for (int i = 0; i < 2; i++)
        {
            free(matrix[i]);
        }
        free(matrix);

    */
    return 0;
}
