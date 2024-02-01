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

            if(peso[i].num ==0){peso[i].tipo = 1;}

            if(peso[i].num ==128){peso[i].tipo = 2;}
            if(peso[i].num ==255){peso[i].tipo = 3;}
            
    }
    
/*
    for(int i=0;i<n;i++){
        printf("n %i t %i\n", peso[i].num,peso[i].tipo);
    }
*/

    int cont = 1;

    // conta o tamanho de v2
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        if (peso[i].num != peso[j].num)
            cont++;
    }

    Matriz vetor[cont];

    // inicializa a struct da vetor como 1
    for (int i = 0; i < cont; i++)
    {
        vetor[i].repet = 1;
        vetor[i].tipo = peso[i].tipo;
    }



    // coloca em vetor.repet o tamanho de cada repeticao de estrutura
    int aux = 0;
    for (int i = 0; i < n ; i++)
    {
        int j = i + 1;
        if (peso[i].num == peso[j].num)
        {
            vetor[aux].repet++;
        }
        
        else
        {
        
            vetor[aux].tipo = peso[i].tipo;
            aux++;

        }
    }

    //printf("tipo: ");
    for (int i = 0; i < cont; i++)
    {
        //printf("%i ", vetor[i].tipo);
    }

    //printf("\nrepeticoes: ");
    for (int i = 0; i < cont; i++)
    {
        //printf("%i ", vetor[i].repet);
    }

    //printf("\n");

    int vetorComparacao[5] = {1, 3, 2, 3, 1};

    int comp =0;

    for(int i =0 ; i< cont; i++){
        if(vetor[i].tipo == vetorComparacao[0]){
        
            for(int a=0; a<5;a++){
                if(vetor[i+a].tipo == vetorComparacao[a]){
                    comp ++;
                }else{
                    comp =0;
                    a=5;
                }
                if(comp ==5 ){
                    i = cont;
                }
            }
        
        }
    }

    
    
     if(comp == 5){
        printf("Resultado: Padrao encontrado.\n");
        }else{
            printf("Resultado: Padrao nao encontrado.\n");
        }


    return 0;
}