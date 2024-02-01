#include <stdio.h>

#define INICIOARRANJO 1
#define MAXTAM 1000

// Peso e Vetor são estrutura para trabalha com os segmentos
typedef struct peso
{
    int num;
    int tipo;
} Peso;

typedef struct mat
{
    int tipo;
    int repet;

} Vetor;

typedef int TipoApontador;
typedef int TipoChave;

typedef struct
{
    TipoChave Chave;
    int Tipo;
    int NumElementos;
    int PontoMedio;
} TipoItem;

typedef struct
{
    TipoItem Item[MAXTAM];
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = INICIOARRANJO;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    if (Lista->Ultimo > MAXTAM)
    {
        printf("Lista está cheia\n");
    }
    else
    {
        Lista->Item[Lista->Ultimo - 1] = x;
        Lista->Ultimo++;
    }
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if (Vazia(*Lista) || p >= Lista->Ultimo)
    {
        printf("Erro: Posição não existe\n");
        return;
    }
    *Item = Lista->Item[p - 1];
    Lista->Ultimo--;
    for (Aux = p; Aux < Lista->Ultimo; Aux++)
    {
        Lista->Item[Aux - 1] = Lista->Item[Aux];
    }
}

void Imprime(TipoLista *Lista)
{
    int Aux;
    for (Aux = Lista->Primeiro - 1; Aux <= (Lista->Ultimo - 2); Aux++)
    {
        printf("%d\n", Lista->Item[Aux].Chave);
    }
}

// As operações com segmento serão feitas na função para não poluir a main
 void Segmentos(Peso peso[], int n, Vetor vetor[],int cont){

    for (int i = 0; i < n; i++)
    {
            if(peso[i].num ==0){peso[i].tipo = 1;}
            if(peso[i].num ==128){peso[i].tipo = 2;}
            if(peso[i].num ==255){peso[i].tipo = 3;}   
    }

     for (int i = 0; i < cont; i++)
    {
        vetor[i].repet = 1;
        vetor[i].tipo = peso[i].tipo;
    }

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
}

double PontoMedio(Peso peso[], int *inicio,int fim) {
    int final = *inicio;
    double pontom;

    if(final == fim-1){
        return fim-1;
    }

    if (peso[final].num != peso[final + 1].num && final == 0) {
        *inicio = *inicio+1;
        return 0;
    }

    if (peso[final].num != peso[final + 1].num) {
        *inicio = final + 1;
        pontom = *inicio;
        return pontom;
    }

    while (peso[final].num == peso[final + 1].num) {
        final++;
    }

    pontom = (final + *inicio) / 2;
    *inicio = final;
    return pontom;
}

void PrencheLista(TipoLista *Lista,Vetor vetor[],Peso peso[], int cont){
    TipoItem Item;
    int inicio=0;
    for(int i =0; i < cont ; i++){
        Item.Chave = i+1;
        Item.NumElementos = vetor[i].repet;
        Item.Tipo = vetor[i].tipo;
        Item.PontoMedio = PontoMedio(peso,&inicio,cont);
        Insere(Item, Lista);
    }
}

void ProcuraPadrao(TipoLista Lista, int cont, int *comp2){
    
    int vetorComparacao[5] = {1, 3, 2, 3, 1};

    int comp =0;

    for(int i =0 ; i< cont; i++){
        if(Lista.Item[i].Tipo == vetorComparacao[0]){
            for(int a=0; a<5;a++){
                if(Lista.Item[i+a].Tipo == vetorComparacao[a]){
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
    *comp2=comp;   
}

int main(){

TipoLista Lista;
int N,cont=1,chave =1,comp;

scanf("%i",&N);
Peso peso[N];

for (int i = 0; i < N; i++){
        scanf("%i", &peso[i].num);
}
for (int i = 0; i < N - 1; i++){
    int j = i + 1;
    if (peso[i].num != peso[j].num)
        cont++;
}
   
Vetor vetor[cont];

Segmentos(peso,N,vetor,cont);

FLVazia(&Lista);

PrencheLista(&Lista,vetor,peso,cont);

ProcuraPadrão(Lista, cont,&comp);

 if(comp == 5){
        printf("Resultado: Padrao encontrado.\n");
        }else{
            printf("Resultado: Padrao nao encontrado.\n");
        }
    return 0;

    
}