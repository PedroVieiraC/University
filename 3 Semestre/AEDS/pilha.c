#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct aniversario
{
    int dia, mes, ano;
} Aniversario;

typedef struct pessoa
{
    char nome[10];
    Aniversario aniversario;
} Pessoa;

typedef struct no
{
    Pessoa pe;
    struct no *proximo;
} No;

Pessoa ler()
{
    Pessoa pe;
    printf("Digite nome: ");
    scanf("%s", pe.nome);
    printf("digite data de nascimento dd mm aaaa");
    scanf("%d%d%d", &pe.aniversario.dia, &pe.aniversario.mes, &pe.aniversario.ano);
    return pe;
}

void imprimir(Pessoa pe)
{
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", pe.nome, pe.aniversario.dia, pe.aniversario.mes, pe.aniversario.ano);
}

// funcao push
No *push(No *topo)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->pe = ler();
        novo->proximo = topo;
        return novo;
    }

    else
    {
        printf("\nErro ao alocar\n");
        return NULL;
    }
}

No *pull(No **topo)
{
    if (*topo != NULL)
    {
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
        printf("\npilha vazia!\n");

    return NULL;
}

void imprimirall(No *topo){

    printf("\npilha\n");
    
    while(topo){
    
        imprimir(topo->pe);
    
        topo = topo->proximo;
    
    }

    printf("\nfim pilha\n");

}

int main()
{
    No *topo = NULL;
    No *remover;
    int opcao;

    do
    {
        printf("\n0 - sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {    
        case 1: //empilhar
            topo = push(topo);
            break;

        case 2: //desempilhar
            remover = pull(&topo);
            if(remover != NULL)
            {

             printf("remocao de\n");
             imprimir(remover->pe);

            }

            else printf("Sem nó a remover\n");
            break;

        case 3:
            imprimirall(topo);
            break;

        default:
            if (opcao != 0)
                printf("\nopcao invalida!!\n");
        }

    } while (opcao != 0);

    return 0;
}