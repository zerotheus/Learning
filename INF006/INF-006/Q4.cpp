#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define lim 1000

struct Pessoas
{
    char nome[52], datadeNascimento[12];
    int renda, dia, mes, ano, codigo;
};

int BuscaBinaria(int inicio, int fim, int busca, struct Pessoas C[])
{
    int meio, encontrado = -1;
    if (inicio > fim)
    {
        return encontrado;
    }
    else
    {
        meio = (inicio + fim) / 2;
        if (C[meio].codigo == busca)
        {
            return meio;
        }
        if (C[meio].codigo < busca)
        {
            meio = BuscaBinaria(meio + 1, fim, busca, C);
        }
        if (C[meio].codigo > busca)
        {
            meio = BuscaBinaria(inicio, meio - 1, busca, C);
        }
    }
    return meio;
}

int CadastraCliente(int pos, int qtdClientes, int edit, struct Pessoas Cliente[]);

int ValidaData(char data[]);

int ExibirClientes(int qtd, struct Pessoas C[]);

void Edita(int qtdClientes, struct Pessoas Clientes[]);

int Excluir(int qtdClientes, struct Pessoas Clientes[]);

void Logicadeexclusao(int pos, int qtd, struct Pessoas C[]);

void Nascidosentre1980e2000(int qtd, struct Pessoas C[]);

void Acimadamedia(int qtd, struct Pessoas C[]);

int ValidaData(char data[])
{
    int i, dia, mes, ano, valid = 1, bissexto = 0;
    for (i = 0; data[i] != '\n' && data[i] != '\0'; i++)
    {
        if ((data[i] > 47 && data[i] < 58) || data[i] == '/')
        {
        }
        else
        {
            valid = 0;
            return valid;
        }
    }

    dia = (data[0] - 48) * 10;
    dia += (data[1] - 48);
    mes = (data[3] - 48) * 10;
    mes += (data[4] - 48);
    ano = (data[6] - 48) * 1000;
    ano += (data[7] - 48) * 100;
    ano += (data[8] - 48) * 10;
    ano += (data[9] - 48);
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0)
    {
        valid = 0;
        return valid;
    }
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    {
        bissexto = 1;
    }
    if (dia >= 31 && mes != 1 && mes != 3 && mes != 5 && mes != 7 && mes != 8 && mes != 10 && mes != 12)
    {
        valid = 0;
        return valid;
    }
    if (dia > 29 && mes == 2)
    {
        valid = 0;
        return valid;
    }
    if (dia > 28 && mes == 2 && bissexto == 0)
    {
        valid = 0;
        return valid;
    }
    return valid;
}

int CadastraCliente(int pos, int qtdClientes, int edit, struct Pessoas Cliente[])
{
    static unsigned int codigo = 10;
    char nome[52], datadeNascimento[12];
    int renda, valid = 1, ano;
    printf("Informe o nome do cliente\n");
    fgets(nome, 50, stdin);
    printf("Informe a Data de nascimento do cliente\nFormato dd/mm/ano\n");
    fgets(datadeNascimento, 11, stdin);
    valid = ValidaData(datadeNascimento);
    if (valid != 1)
    {
        printf("Data invalida\n");
        return 0;
    }
    printf("Informe a renda do cliente\n");
    scanf("%d", &renda);
    getchar();
    strcpy(Cliente[pos].nome, nome);
    strcpy(Cliente[pos].datadeNascimento, datadeNascimento);
    Cliente[pos].renda = renda;
    if (edit == 0)
    {
        Cliente[pos].codigo = codigo;
        codigo++;
    }
    ano = (datadeNascimento[6] - 48) * 1000;
    ano += (datadeNascimento[7] - 48) * 100;
    ano += (datadeNascimento[8] - 48) * 10;
    ano += (datadeNascimento[9] - 48);
    Cliente[pos].ano = ano;
    printf("Cliente: %scodigo: %d\n", Cliente[pos].nome, Cliente[pos].codigo);
    return 1;
}

int ExibirClientes(int qtd, struct Pessoas C[])
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        printf("Codigo: %d Nome: %s Data de nascimento %s, Renda: %d\n", C[i].codigo, C[i].nome, C[i].datadeNascimento, C[i].renda);
    }
}

void Edita(int qtdClientes, struct Pessoas Clientes[])
{
    int codigo, pos;
    printf("Digite o codigo do cliente\nCaso nao saiba digite 0\n");
    scanf("%d", &codigo);
    getchar();
    if (codigo == 0)
    {
        ExibirClientes(qtdClientes, Clientes);
        return;
    }
    if (codigo > 9)
    {
        pos = BuscaBinaria(0, qtdClientes, codigo, Clientes);
    }
    if (pos == -1)
    {
        return;
    }
    CadastraCliente(pos, qtdClientes, 1, Clientes);
}

void Acimadamedia(int qtd, struct Pessoas C[])
{
    int i;
    float Media, Soma = 0;
    for (i = 0; i < qtd; i++)
    {
        Soma += C[i].renda;
    }
    Media = Soma / qtd;
    for (i = 0; i < qtd; i++)
    {
        if (C[i].renda > Media)
        {
            printf("Nome: %sCodigo: %d Renda %d\n", C[i].nome, C[i].codigo, C[i].renda);
        }
    }
}

void Nascidosentre1980e2000(int qtd, struct Pessoas C[])
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        if (C[i].ano >= 1980 && C[i].ano <= 2000)
        {
            printf("Nome: %sData de Nascimento %s", C[i].nome, C[i].datadeNascimento);
        }
    }
}

void Menuclientes(int qtd, struct Pessoas C[])
{
    int opcoes;
    printf("1. Ver clientes\n2. Rendas acima da media\n3. Nascidos entre 1980 e 2000\n");
    scanf("%d", &opcoes);
    getchar();
    if (opcoes == 1)
    {
        ExibirClientes(qtd, C);
        return;
    }
    if (opcoes == 2)
    {
        Acimadamedia(qtd, C);
        return;
    }
    if (opcoes == 3)
    {
        Nascidosentre1980e2000(qtd, C);
        return;
    }
}

void Logicadeexclusao(int pos, int qtd, struct Pessoas C[])
{
    int i;
    for (i = pos; i < qtd; i++)
    {
        C[i] = C[i + 1];
    }
}

int Excluir(int qtdClientes, struct Pessoas Clientes[])
{
    int codigo, pos;
    printf("Digite o codigo do cliente que deseja excluir\nCaso nao saiba digite 0\n");
    scanf("%d", &codigo);
    getchar();
    if (codigo == 0)
    {
        ExibirClientes(qtdClientes, Clientes);
        return 0;
    }
    if (codigo > 9)
    {
        pos = BuscaBinaria(0, qtdClientes, codigo, Clientes);
    }
    if (pos == -1)
    {
        return 0;
    }
    Logicadeexclusao(pos, qtdClientes, Clientes);
    return 1;
}

int main()
{
    int opcoes = 0, qtdClientes = 0, retorno;
    struct Pessoas Cliente[lim];
    while (opcoes != 5)
    {
        printf("1. Cadastrar cliente\n2. Editar cliente\n3. Excluir cliente\n4. Ver cliente\n5. Encerrar\n");
        scanf("%d", &opcoes);
        getchar();
        switch (opcoes)
        {
        case 1:
            retorno = CadastraCliente(qtdClientes, qtdClientes, 0, Cliente);
            qtdClientes += retorno;
            break;
        case 2:
            Edita(qtdClientes, Cliente);
            break;
        case 3:
            retorno = Excluir(qtdClientes, Cliente);
            qtdClientes -= retorno;
            break;
        case 4:
            Menuclientes(qtdClientes, Cliente);
            break;
        }
    }
}
