#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define vagas 200

struct carros
{
    char cor[50], modelo[32], Placa[9], letrasdaPlaca[4], Marca[21];
    int numerosdaPlaca;
};
// RIO2A18
// 0123456
int LeitordePlaca(char P[], int pos, struct carros Carro[]);

int BuscaPlaca(char Placa[], int qtd, struct carros C[]);

void MostraCarro(int qtd, struct carros C[]);

void Modifica(int qtd, struct carros C[]);

int Exclui(int qtd, struct carros C[]);

void RetiraCarro(int pos, int qtd, struct carros C[]);

int Guardacarro(int vaga, int qtdCarros, int modifica, struct carros Carro[])
{
    int placaIgual = -1;
    char cor[50], modelo[32], Placa[9], Marca[21];
    printf("informe o modelo do carro\n");
    fgets(modelo, 30, stdin);
    printf("informe a Marca do carro\n");
    fgets(Marca, 20, stdin);
    printf("informe a placa no Padrao do mercosul\n");
    fgets(Placa, 9, stdin);
    LeitordePlaca(Placa, vaga, Carro);
    placaIgual = BuscaPlaca(Placa, qtdCarros, Carro);
    if (placaIgual != -1)
    {
        printf("Carro com placa igual já existente\n");
        return 0;
    }
    BuscaPlaca(Placa, qtdCarros, Carro);
    printf("informe a cor do veiculo\n");
    fgets(cor, 48, stdin);
    if (placaIgual == -1)
    {
        strcpy(Carro[vaga].modelo, modelo);
        strcpy(Carro[vaga].Marca, Marca);
        strcpy(Carro[vaga].Placa, Placa);
        strcpy(Carro[vaga].cor, cor);
    }
    return 1;
}

int LeitordePlaca(char P[], int pos, struct carros Carro[])
{
    Carro[pos].letrasdaPlaca[0] = P[0];
    Carro[pos].letrasdaPlaca[1] = P[1];
    Carro[pos].letrasdaPlaca[2] = P[2];
    Carro[pos].letrasdaPlaca[3] = P[4];
    Carro[pos].numerosdaPlaca = (P[3] - 48) * 100;
    Carro[pos].numerosdaPlaca += (P[5] - 48) * 10;
    Carro[pos].numerosdaPlaca += (P[6] - 48) * 1;
}

void MostraCarro(int qtd, struct carros C[])
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        puts(C[i].Marca);
        puts(C[i].modelo);
        puts(C[i].Placa);
        puts(C[i].cor);
    }
}

void Modifica(int qtd, struct carros C[])
{
    char Placa[9];
    int pos;
    printf("informe a placa no Padrao do mercosul\n");
    fgets(Placa, 9, stdin);
    pos = BuscaPlaca(Placa, qtd, C);
    if (pos == -1)
    {
        printf("Carro nao encontrado ou Placa incorreta\n");
    }
    Guardacarro(pos, qtd, 1, C);
}

int BuscaPlaca(char Placa[], int qtd, struct carros C[])
{
    int i, R;
    for (i = 0; i < qtd; i++)
    {
        R = strcmp(Placa, C[i].Placa);
        if (R == 0)
        {
            return i;
        }
    }
    return -1;
}

void RetiraCarro(int pos, int qtd, struct carros C[])
{
    for (int i = pos; i < qtd - 1; i++)
    {
        C[i] = C[i + 1];
    }
}

int Exclui(int qtd, struct carros C[])
{
    char Placa[9];
    int pos;
    printf("informe a placa no Padrao do mercosul\n");
    fgets(Placa, 9, stdin);
    pos = BuscaPlaca(Placa, qtd, C);
    if (pos != -1)
    {
        RetiraCarro(pos, qtd, C);
        return 1;
    }
    return 0;
}

int main()
{
    int opcoes = 0, qtdCarros = 0;
    struct carros Carro[vagas];
    while (opcoes != 5)
    {
        printf("1. Guardar carro\n2. Modificar carro\n3. Retirar carro\n4. Ver carro\n5. Sair\n");
        scanf("%d", &opcoes);
        getchar();
        switch (opcoes)
        {
        case 1:
            if (qtdCarros < vagas)
            {
                qtdCarros += Guardacarro(qtdCarros, qtdCarros, 0, Carro);
            }
            break;
        case 2:
            Modifica(qtdCarros, Carro);
            break;
        case 3:
            Exclui(qtdCarros, Carro);
            break;
        case 4:
            MostraCarro(qtdCarros, Carro);
            break;
        }
    }
}