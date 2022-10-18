#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define lim 200

struct agendaEnderacos
{
    char nome[52], endereco[255];
    int numero, numerotelefone, cep, reg;
};

struct agendaEnderacos Agenda[lim];

int BuscaBinaria(int inicio, int fim, int busca)
{
    int meio, encontrado = -1;
    if (inicio > fim)
    {
        return encontrado;
    }
    else
    {
        meio = (inicio + fim) / 2;
        if (Agenda[meio].reg == busca)
        {
            return meio;
        }
        if (Agenda[meio].reg < busca)
        {
            meio = BuscaBinaria(meio + 1, fim, busca);
        }
        if (Agenda[meio].reg > busca)
        {
            meio = BuscaBinaria(inicio, meio - 1, busca);
        }
    }
    return meio;
}

int Cadastro(int qtd, int edit);

void Lista(int qtd);

void Edita(int qtd);

int Excluir(int qtd);

int Cadastro(int qtd, int edit)
{
    static unsigned int reg = 10;
    printf("informe o nome\n");
    fgets(Agenda[qtd].nome, 50, stdin);
    printf("Digite o endereco\n");
    fgets(Agenda[qtd].endereco, 253, stdin);
    printf("Digite o cep\n");
    scanf("%d", &Agenda[qtd].cep);
    getchar();

    printf("Digite o numero do endereco\n");
    scanf("%d", &Agenda[qtd].numero);
    getchar();
    printf("Digite o numero de contato\n");
    scanf("%d", &Agenda[qtd].numerotelefone);
    getchar();
    if (edit == 0)
    {
        Agenda[qtd].reg = reg;
        reg++;
    }
    return 1;
}

void Edita(int qtd)
{
    int opcoes, pag, pos;
    char sn;
    printf("Digite a pagina de quem deseja excluir\nCaso nao saiba digite 0\n1 para sair\n");
    scanf("%d", &pag);
    getchar();
    if (pag == 0)
    {
        Lista(qtd);
    }
    if (pag == 1)
    {
        return;
    }
    if (pag > 9)
    {
        pos = BuscaBinaria(0, qtd, pag);
    }
    if (pos == -1)
    {
        printf("Pessoa nao encontrada\n");
        return;
    }
    printf("Editando: ");
    puts(Agenda[pos].nome);
    printf("Cep: %d\nDeseja prosseguir?\nSim: S/s Nao: N/n", Agenda[pos].cep);
    scanf("%c", &sn);
    getchar();
    if (sn == 's' || sn == 'n')
    {
        Cadastro(pos, 1);
    }
    return;
}

void Lista(int qtd)
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        puts(Agenda[i].nome);
        puts(Agenda[i].endereco);
        printf("Cep: %d\nContato: %d\nNumero: %d\n", Agenda[i].cep, Agenda[i].numero, Agenda[i].numerotelefone);
    }
}

int Excluir(int qtd)
{
    int opcoes, pag, pos, i;
    char sn;
    printf("Digite a pagina de quem deseja excluir\nCaso nao saiba digite 0\n1 para sair\n");
    scanf("%d", &pag);
    getchar();
    if (pag == 0)
    {
        Lista(qtd);
    }
    if (pag == 1)
    {
        return 0;
    }
    if (pag > 9)
    {
        pos = BuscaBinaria(0, qtd, pag);
    }
    if (pos == -1)
    {
        printf("Pessoa nao encontrada\n");
        return 0;
    }
    printf("Excluindo: ");
    puts(Agenda[pos].nome);
    printf("Cep: %d\nDeseja prosseguir?\nSim: S/s Nao: N/n", Agenda[pos].cep);
    scanf("%c", &sn);
    getchar();
    if (sn == 's' || sn == 'S')
    {
        for (i = pos; i < qtd - 1; i++)
        {
            Agenda[i] = Agenda[i + 1];
        }
        printf("Endereco excluindo com sucesso\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int opcoes = 0, qtdCadastros = 0;
    while (opcoes != 5)
    {
        printf("1. inserir novo endereco\n2. Editar endereco\n3. Excluir enderecos\n4. Listar enderecos\n5. Encerrar\n");
        scanf("%d", &opcoes);
        getchar();
        switch (opcoes)
        {
        case 1:
            if (qtdCadastros < lim)
            {
                qtdCadastros += Cadastro(qtdCadastros, 0);
            }
            break;
        case 2:
            Edita(qtdCadastros);
            break;
        case 4:
            if (qtdCadastros > 0)
            {
                Lista(qtdCadastros);
            }
            break;
        case 3:
            if (qtdCadastros > 0)
            {
                qtdCadastros -= Excluir(qtdCadastros);
            }
            break;
        }
    }
}