#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include "EstruturaVetores.h"

// int vetorPrincipal[TAM];

struct dados
{
    int num;
    int qtd;
    int tamanhoAuxiliar;
    int *ptr;
};

typedef struct dados Dados;

Dados *matriz[10];

// int** arr = (int**)malloc(r * sizeof(int*));

int Buscalinear(int posicao, int num)
{
    int i;
    for (i = 0; i < (*matriz[posicao]).qtd; i++)
    {
        if (num == matriz[posicao][i].num)
        {
            return i;
        }
    }
    return NUMERO_INEXISTENTE;
}

void Lista(int posicao)
{
    int i;
    if ((*matriz[posicao]).qtd < 1)
    {
        return;
    }
    printf("Lista :");
    for (i = 0; i < (*matriz[posicao]).qtd; i++)
    {
        printf("%d, ", matriz[posicao][i].num);
    }
    printf("\n");
}

int particao(int esquerda, int direita, int arr[])
{
    int pivot = arr[direita];
    int i = esquerda - 1, j, aux;
    for (j = esquerda; j < direita; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
        }
    }
    arr[direita] = arr[i + 1];
    arr[i + 1] = pivot;
    return i + 1;
}

int quicksort(int esquerda, int direita, int arr[])
{
    int pivot;
    if (esquerda < direita)
    {
        pivot = particao(esquerda, direita, arr);
        quicksort(esquerda, pivot - 1, arr);
        quicksort(pivot + 1, direita, arr);
    }
}

int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    retorno = ehPosicaoValida(posicao);
    if (retorno == POSICAO_INVALIDA)
    {
        return retorno;
    }

    if (tamanho < 1)
    {
        retorno = TAMANHO_INVALIDO;
        return retorno;
    }
    posicao = posicao - 1;
    if (retorno == SEM_ESTRUTURA_AUXILIAR)
    {
        matriz[posicao] = realloc(matriz[posicao], sizeof(Dados) * tamanho);
        (*matriz[posicao]).tamanhoAuxiliar = tamanho;
        (*matriz[posicao]).ptr = &(*matriz[posicao]).tamanhoAuxiliar;
        // printf("size %d\n", sizeof(matriz[posicao]));
        retorno = SUCESSO;
        return retorno;
    }
    if (retorno != SEM_ESTRUTURA_AUXILIAR)
    {
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    return retorno;
}

int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    posicao_invalida = ehPosicaoValida(posicao);
    if (SEM_ESTRUTURA_AUXILIAR == posicao_invalida)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    if (posicao_invalida == POSICAO_INVALIDA)
    {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    posicao = posicao - 1;

    if (((*matriz[posicao]).qtd < (*matriz[posicao]).tamanhoAuxiliar))
    {
        (matriz[posicao][(*matriz[posicao]).qtd]).num = valor;
        (*matriz[posicao]).qtd++;
        // Lista(posicao);
        retorno = SUCESSO;
    }
    else
    {
        retorno = SEM_ESPACO;
    }

    return retorno;
}

int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno;

    retorno = ehPosicaoValida(posicao);
    posicao = posicao - 1;
    if (retorno != SUCESSO)
    {
        return retorno;
    }
    if ((*matriz[posicao]).qtd < 1)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    (*matriz[posicao]).qtd--;
    // Lista(posicao);
    return retorno;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno, contador, i;

    retorno = ehPosicaoValida(posicao);

    if (retorno != SUCESSO)
    {
        return retorno;
    }
    posicao--;
    contador = Buscalinear(posicao, valor);
    if (contador == NUMERO_INEXISTENTE)
    {
        return contador;
    }
    i = matriz[posicao]->qtd - 1;
    for (; contador < i; i--)
    {
        matriz[posicao][i - 1].num = matriz[posicao][i].num;
    }
    matriz[posicao]->qtd--;
    // Lista(posicao);

    return retorno;
}

int ehPosicaoValida(int posicao)
{
    int retorno = 0, i = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    posicao = posicao - 1; // verificar a posicao real
    if (((*matriz[posicao]).ptr == NULL))
    {
        // printf("Ptr%d Nulo\n", posicao);
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    retorno = SUCESSO;
    return retorno;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0, i;
    retorno = ehPosicaoValida(posicao);
    if (retorno != SUCESSO)
    {
        return retorno;
    }
    posicao = posicao - 1;

    int fim = matriz[posicao]->qtd;
    for (i = 0; i < fim; i++)
    {
        vetorAux[i] = matriz[posicao][i].num;
    }

    return retorno;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0, i;
    retorno = ehPosicaoValida(posicao);
    if (retorno != SUCESSO)
    {
        return retorno;
    }
    posicao = posicao - 1;
    int fim = matriz[posicao]->qtd;
    for (i = 0; i < fim; i++)
    {
        vetorAux[i] = matriz[posicao][i].num;
    }
    quicksort(0, fim - 1, vetorAux);
    return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0, contazero = 0, i, naoNulas = 0, aux = 0, *matrizesNaoNulas, k = 0;
    int j, fim;
    for (i = 0; i < 10; i++)
    {
        if ((*matriz[i]).qtd == 0)
        {
            contazero++;
            continue;
        }
        naoNulas++;
    }
    if (naoNulas > 0)
    {
        matrizesNaoNulas = (int *)malloc(sizeof(int) * naoNulas);
    }
    // printf("contazero: %d\n", contazero);
    if (contazero == 10)
    {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        return retorno;
    }

    for (i = 0; i < 10; i++)
    {
        if ((*matriz[i]).qtd == 0)
        {
            continue;
        }
        matrizesNaoNulas[aux] = i;
        aux++;
    }
    /*for (i = 0; i < aux; i++)
    {
        printf("%d\t", matrizesNaoNulas[i]);
    }*/
    for (i = 0; i < aux; i++)
    {
        fim = (*matriz[matrizesNaoNulas[i]]).qtd;
        for (j = 0; j < fim; j++)
        {
            vetorAux[k] = matriz[matrizesNaoNulas[i]][j].num;
            k++;
        }
    }
    // printf("NN %d\n", naoNulas);
    free(matrizesNaoNulas);
    retorno = SUCESSO;
    return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0, contazero = 0, i, naoNulas = 0, aux = 0, *matrizesNaoNulas, k = 0, tamanhoTotal = 0;
    int j, fim;
    for (i = 0; i < 10; i++)
    {
        if ((*matriz[i]).qtd == 0)
        {
            contazero++;
            continue;
        }
        naoNulas++;
    }
    if (naoNulas > 0)
    {
        matrizesNaoNulas = (int *)malloc(sizeof(int) * naoNulas);
    }
    // printf("contazero: %d\n", contazero);
    if (contazero == 10)
    {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        return retorno;
    }

    for (i = 0; i < 10; i++)
    {
        if ((*matriz[i]).qtd == 0)
        {
            continue;
        }
        matrizesNaoNulas[aux] = i;
        aux++;
    }
    /*for (i = 0; i < aux; i++)
    {
        printf("%d\t", matrizesNaoNulas[i]);
    }*/
    for (i = 0; i < aux; i++)
    {
        fim = (*matriz[matrizesNaoNulas[i]]).qtd;
        tamanhoTotal += (*matriz[matrizesNaoNulas[i]]).qtd;
        for (j = 0; j < fim; j++)
        {
            vetorAux[k] = matriz[matrizesNaoNulas[i]][j].num;
            k++;
        }
    }
    // printf("%d", tamanhoTotal);
    quicksort(0, tamanhoTotal - 1, vetorAux);
    // printf("NN %d\n", naoNulas);
    free(matrizesNaoNulas);
    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1 Rertono (int) SUCESSO - foi modificado corretamente o tamanho da
estrutura auxiliar SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    retorno = ehPosicaoValida(posicao);
    if (retorno != SUCESSO)
    {
        return retorno;
    }
    posicao = posicao - 1;
    int tamanho = (*matriz[posicao]).tamanhoAuxiliar;
    tamanho = tamanho + novoTamanho;
    if (tamanho < 1)
    {
        return NOVO_TAMANHO_INVALIDO;
    }
    matriz[posicao] = realloc(matriz[posicao], sizeof(Dados) * tamanho);
    (*matriz[posicao]).tamanhoAuxiliar = tamanho;
    if ((*matriz[posicao]).qtd > tamanho)
    {
        (*matriz[posicao]).qtd = tamanho;
    }
    (*matriz[posicao]).ptr = &(*matriz[posicao]).tamanhoAuxiliar;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'. Retorno (int) POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno;
    retorno = ehPosicaoValida(posicao);
    if (retorno != SUCESSO)
    {
        return retorno;
    }
    posicao = posicao - 1;
    return (*matriz[posicao]).qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas. Retorno (No*) NULL, caso não tenha nenhum número nas
listas No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() { return NULL; }

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {}

void inicializar()
{
    static int inicializado = 0;
    int i;
    if (inicializado == 0)
    {

        for (i = 0; i < 10; i++)
        {
            matriz[i] = malloc(sizeof(Dados));
            matriz[i]->ptr = NULL;
            matriz[i]->qtd = 0;
        }
    }
}

void finalizar()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        free(matriz[i]);
    }
}