#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pii
{
    int tempo;
    int pizzas;
    float razao;
    float razaor;
} Pizzas;

float razao(int a, int b)
{
    a = pow(a, 2);
    b = pow(b, 2);
    float raz = (float)a / b;
    return (raz);
}
float razaor(int a, int b)
{
    a = pow(a, 2);
    b = sqrt(b);
    float raz = (float)a / b;
    return (raz);
}

int melhorTempo(int np, Pizzas pizza[], int pizzamax)
{
    int qtdpizzas = 0, tempo = 0;
    for (int i = 0; i < np; i++)
    {
        qtdpizzas += pizza[i].pizzas;
        tempo += pizza[i].tempo;

        if (qtdpizzas > pizzamax)
        {
            qtdpizzas -= pizza[i].pizzas;
            tempo -= pizza[i].tempo;
        }
    }
    return tempo;
}

int main()
{
    int np = 0, pizzamax = 0;

    // for para escanear as entradas

    while (1)
    {

        scanf("%i", &np);

        if (np == 0)
            break;

        scanf("%i", &pizzamax);

        Pizzas pizza[np];

        int k = 0;
        for (int j = 0; j < np; j++)
        {
            scanf("%i %i", &pizza[k].tempo, &pizza[k].pizzas);
            pizza[k].razao = razao(pizza[k].tempo, pizza[k].pizzas);
            pizza[k].razaor = razaor(pizza[k].tempo, pizza[k].pizzas);
            k++;
        }

        // for para ordenar em relação à razao entre o tempo e quantidade de pizzas
        for (int i = 0; i < np - 1; i++)
        {
            for (int j = i + 1; j < np; j++)
            {
                if (pizza[i].razao < pizza[j].razao)
                {
                    Pizzas aux = pizza[i];
                    pizza[i] = pizza[j];
                    pizza[j] = aux;
                }
            }
        }

        int tempoRazao = melhorTempo(np, pizza, pizzamax);

        // for para ordenar em relação à subtracao do limite e qtd de pizzas
        for (int i = 0; i < np - 1; i++)
        {
            for (int j = i + 1; j < np; j++)
            {
                if ((pizza[i].pizzas - np) < (pizza[j].pizzas - np))
                {
                    Pizzas aux = pizza[i];
                    pizza[i] = pizza[j];
                    pizza[j] = aux;
                }
            }
        }
        int tempoSubtracao = melhorTempo(np, pizza, pizzamax);

        // for para ordenar em relação à razao do quadrado pela raiz
        for (int i = 0; i < np - 1; i++)
        {
            for (int j = i + 1; j < np; j++)
            {
                if (pizza[i].razaor < pizza[j].razaor)
                {
                    Pizzas aux = pizza[i];
                    pizza[i] = pizza[j];
                    pizza[j] = aux;
                }
            }
        }
        int tempoRazaor = melhorTempo(np, pizza, pizzamax);



        int v[4] = {tempoRazao, tempoRazaor, tempoSubtracao};
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                if(v[i] < v[j]){
                    int aux = v[i];
                    v[i]= v[j];
                    v[j] = aux;
                }
            }
        }

        int tempo = 0;

         printf("%i min.\n", tempo);   
        
        tempo=0;
        tempoRazao=0,tempoRazaor=0,tempoSubtracao=0;
    }
    return 0;
}
