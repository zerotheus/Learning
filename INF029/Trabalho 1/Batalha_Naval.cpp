#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Navios
{
    int NavioTam4 = 1;
    int NavioTam3 = 1;
    int NavioTam2 = 0;
    int NavioTam1 = 3;
};

int BatalhaNaval(struct Navios navios[]);

int SelecionaNavio(int jogador, char matrizdojogador[10][10], struct Navios Nav, int qtdnavios);

int Alocanavio(int TamanhodoNavio, int jogador, char matrizdojogador[10][10]);

int validaSelecao(char selection[]);

int validaorientacao(char orientacao, int linha, int coluna, int tamanhodoNavio, char matrizdoJogador[10][10]);

int validaposfinal(int posfinal);

int Analisatiro(char matrizAdversario[10][10], char jogadasJogador[10][10], char tiro[]);

void ExibeCampo(int jogador, char MatrizdoJogador[10][10], char JogadasdoJogador[10][10], int consulta);

void Setcampo(char M1[10][10], char M2[10][10], char J1[10][10], char J2[10][10]);

void getpos(char pontoinicial[]);

void limpaTela();

void getpos(char pontoinicial[])
{
    fgets(pontoinicial, 3, stdin);
    getchar();
}

void ExibeCampo(int jogador, char MatrizdoJogador[10][10], char JogadasdoJogador[10][10], int consulta)
{
    int const linha = 10, coluna = 10;
    int l, c;
    printf("Jogador %d\n", jogador);
    printf("> 0 1 2 3 4 5 6 7 8 9");
    if (consulta != 3)
    {
        printf("\n");
    }
    else
    {
        printf("\t0 1 2 3 4 5 6 7 8 9\n");
    }

    if (jogador == 1)
    {
        for (l = 0; l < linha; l++)
        {
            printf("%c ", 'A' + l);
            for (c = 0; c < coluna; c++)
            {
                printf("%c ", MatrizdoJogador[l][c]);
            }
            printf("\t");
            if (consulta == 3 || consulta == 1)
            {
                for (c = 0; c < coluna; c++)
                {
                    printf("%c ", JogadasdoJogador[l][c]);
                }
            }
            printf("\n");
        }
    }
    else
    {

        for (l = 0; l < linha; l++)
        {
            printf("%c ", 'A' + l);
            for (c = 0; c < coluna; c++)
            {
                printf("%c ", MatrizdoJogador[l][c]);
            }
            printf("\t");
            if (consulta == 3 || consulta == 1)
            {
                for (c = 0; c < coluna; c++)
                {
                    printf("%c ", JogadasdoJogador[l][c]);
                }
            }
            printf("\n");
        }
    }
}

void Setcampo(char M1[10][10], char M2[10][10], char J1[10][10], char J2[10][10])
{
    int const linha = 10, coluna = 10;
    int l, c;
    for (l = 0; l < linha; l++)
    {
        for (c = 0; c < coluna; c++)
        {
            M1[l][c] = ' ';
            M2[l][c] = ' ';
            J1[l][c] = ' ';
            J2[l][c] = ' ';
        }
    }
}

void limpaTela()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

int validaposfinal(int posfinal)
{
    printf("%d pos", posfinal);
    if (posfinal < 0 || posfinal > 10)
    {
        printf("Orientacao impossivel de ser realizada\n");
        return 0;
    }
    else
    {
        return 1;
    }
    return 1;
}

int validaSelecao(char selection[])
{
    if (selection[0] > 96 && selection[0] < 107)
    {
        selection[0] = selection[0] - 32;
    }
    // 0 invalido
    if (selection[0] < 65 || selection[0] > 74)
    {
        printf("Linha invalida\n");
        return 0;
    }
    if (selection[1] < 48 || selection[1] > 57)
    {
        printf("Coluna invalida");
        return 0;
    }
    return 1;
}

int validaorientacao(char orientacao, int linha, int coluna, int tamanhodoNavio, char matrizdoJogador[10][10])
{
    int posfinal, l, c;
    if (orientacao != 'd' && orientacao != 'D' && orientacao != 'c' && orientacao != 'C' && orientacao != 'e' && orientacao != 'E' && orientacao != 'b' && orientacao != 'B')
    {
        printf("Atente as instrucoes\n");
        return 0;
    }
    if (orientacao == 'd' || orientacao == 'D')
    {
        posfinal = coluna + tamanhodoNavio;

        if (validaposfinal(posfinal) == 0)
        {
            return 0;
        }

        for (c = coluna; c < posfinal; c++)
        {
            if (matrizdoJogador[linha][c] == 'N')
            {
                printf("Orientcao impossivel devido a obstrucao\n");
                return 0;
            }
        }
        for (c = coluna; c < posfinal; c++)
        {
            matrizdoJogador[linha][c] = 'N';
        }
    }
    if (orientacao == 'c' || orientacao == 'C')
    {
        posfinal = linha - tamanhodoNavio + 1; // como começa em 0 tem que adicionar um valor

        if (validaposfinal(posfinal) == 0)
        {
            return 0;
        }

        for (l = posfinal; l <= linha; l++)
        {
            if (matrizdoJogador[l][coluna] == 'N')
            {
                printf("Orientcao impossivel devido a obstrucao\n");
                return 0;
            }
        }
        for (l = posfinal; l <= linha; l++)
        {
            matrizdoJogador[l][coluna] = 'N';
        }
    }
    if (orientacao == 'e' || orientacao == 'E')
    {
        posfinal = coluna + 1 - tamanhodoNavio; // como começa em 0 adiciona mais um

        if (validaposfinal(posfinal) == 0)
        {
            return 0;
        }

        for (c = posfinal; c <= coluna; c++)
        {
            if (matrizdoJogador[linha][c] == 'N')
            {
                printf("Orientcao impossivel devido a obstrucao\n");
                return 0;
            }
        }
        for (c = posfinal; c <= coluna; c++)
        {
            matrizdoJogador[linha][c] = 'N';
        }
    }
    if (orientacao == 'b' || orientacao == 'B')
    {
        posfinal = linha + tamanhodoNavio;

        if (validaposfinal(posfinal) == 0)
        {
            return 0;
        }

        for (l = linha; l < posfinal; l++)
        {
            if (matrizdoJogador[l][coluna] == 'N')
            {
                printf("Orientcao impossivel devido a obstrucao\n");
                return 0;
            }
        }
        for (l = linha; l < posfinal; l++)
        {
            matrizdoJogador[l][coluna] = 'N';
        }
    }
    return 1;
}

int Analisatiro(char matrizAdversario[10][10], char jogadasJogador[10][10], char tiro[])
{
    int linha, coluna;
    linha = tiro[0] - 'A';
    coluna = tiro[1] - '0';
    if (matrizAdversario[linha][coluna] == 'N')
    {
        matrizAdversario[linha][coluna] = 'O';
        jogadasJogador[linha][coluna] = 'O';
        return 1;
    }
    else
    {
        matrizAdversario[linha][coluna] = 'X';
        jogadasJogador[linha][coluna] = 'X';
        return 0;
    }
    return 0;
}

int Alocanavio(int TamanhodoNavio, int jogador, char matrizdojogador[10][10])
{
    int linha, coluna, Posvalida;
    char pontoinicial[4];
    char orientacao;
    ExibeCampo(jogador, matrizdojogador, matrizdojogador, 0);
    printf("informe onde deseja colocar o inicio seu navio Exemplo: D3\n");
    getpos(pontoinicial);
    Posvalida = validaSelecao(pontoinicial);
    if (Posvalida != 1)
    {
        return 0;
    }
    linha = pontoinicial[0] - 65;
    coluna = pontoinicial[1] - 48;
    if (TamanhodoNavio == 1 && matrizdojogador[linha][coluna] != 'N')
    {
        matrizdojogador[linha][coluna] = 'N';
        return 1;
    }
    else
    {
        if (matrizdojogador[linha][coluna] == 'N')
        {
            printf("Local ja ocupado\n");
            return 0;
        }
    }
    matrizdojogador[linha][coluna] = 'P';
    ExibeCampo(jogador, matrizdojogador, matrizdojogador, 0);
    printf("Informe para qual direcao deseja orientar o Navio\nE - esquerda, D- direita\nC - cima -B baixo\n");
    scanf("%c", &orientacao);
    getchar();
    Posvalida = validaorientacao(orientacao, linha, coluna, TamanhodoNavio, matrizdojogador);
    if (matrizdojogador[linha][coluna] != 'N' && Posvalida != 0)
    {
        matrizdojogador[linha][coluna] = 'P';
    }
    else
    {
        if (Posvalida != 1)
        {
            if (matrizdojogador[linha][coluna] == 'N')
            {
                printf("Local ja ocupado\n");
            }
            matrizdojogador[linha][coluna] = ' ';
            return 0;
        }
    }
}

int SelecionaNavio(int jogador, char matrizdojogador[10][10], struct Navios Nav, int qtdnavios)
{
    int tamanho = 0, jogadavalida = 0;
    while (Nav.NavioTam4 > 0 || Nav.NavioTam3 > 0 || Nav.NavioTam2 > 0 || Nav.NavioTam1 > 0)
    {
        printf("Navios tamanho 4: %d\nNavios tamanho 3: %d\nNavios tamanho 2: %d\nNavios tamanho 1: %d\n", Nav.NavioTam4, Nav.NavioTam3, Nav.NavioTam2, Nav.NavioTam1);
        printf("Digite o tamanho do navio que deseja inserir\n");
        tamanho = 0;
        jogadavalida = 0;
        while (tamanho < 1 || tamanho > 4)
        {
            scanf("%d", &tamanho);
            getchar();
            if (tamanho == 4)
            {
                if (Nav.NavioTam4 == 0)
                {
                    break;
                }
                jogadavalida = Alocanavio(tamanho, jogador, matrizdojogador);
                if (jogadavalida == 0)
                {
                    printf("Jogada invalida\nDigite novamente o tamanho desejado");
                    tamanho = 0;
                    continue;
                }
                if (Nav.NavioTam4 > 0)
                {
                    Nav.NavioTam4--;
                }
                else
                {
                    tamanho = 0;
                    if (Nav.NavioTam4 == 0)
                    {
                        printf("Tamanho digitado indisponivel\nSelecione outro\n");
                        break;
                    }
                }
                break;
            }
            if (tamanho == 3)
            {
                if (Nav.NavioTam3 == 0)
                {
                    break;
                }
                jogadavalida = Alocanavio(tamanho, jogador, matrizdojogador);
                if (jogadavalida == 0)
                {
                    printf("Jogada invalida\n");
                    tamanho = 0;
                    continue;
                }
                if (Nav.NavioTam3 > 0)
                {
                    Nav.NavioTam3--;
                }
                else
                {
                    tamanho = 0;
                    printf("Tamanho digitado indisponivel\n");
                }
                break;
            }
            if (tamanho == 2)
            {
                if (Nav.NavioTam2 == 0)
                {
                    break;
                }
                jogadavalida = Alocanavio(tamanho, jogador, matrizdojogador);
                if (jogadavalida == 0)
                {
                    printf("Jogada invalida\n");
                    tamanho = 0;
                    continue;
                }
                if (Nav.NavioTam2 > 0)
                {
                    Nav.NavioTam2--;
                }
                else
                {
                    tamanho = 0;
                    printf("Tamanho digitado indisponivel\n");
                }
                break;
            }
            if (tamanho == 1)
            {
                if (Nav.NavioTam1 == 0)
                {
                    break;
                }
                jogadavalida = Alocanavio(tamanho, jogador, matrizdojogador);
                if (jogadavalida != 1)
                {
                    printf("Jogada invalida\n");
                    tamanho = 0;
                    continue;
                }
                if (Nav.NavioTam1 > 0)
                {
                    Nav.NavioTam1--;
                }
                else
                {
                    tamanho = 0;
                    printf("Tamanho digitado indisponivel\n");
                }
                break;
            }
            printf("Tamanho digitado invalido\n");
        }
        ExibeCampo(jogador, matrizdojogador, matrizdojogador, 0);
    }
}

int BatalhaNaval(struct Navios navios[])
{
    int const linha = 10, coluna = 10;
    int repeticoes = 0;
    char tiroPos[4];
    int jogadorUmNavios = navios[0].NavioTam1 + navios[0].NavioTam2 + navios[0].NavioTam3 + navios[0].NavioTam4;
    int jogadorDoisNavios = navios[1].NavioTam1 + navios[1].NavioTam2 + navios[1].NavioTam3 + navios[1].NavioTam4;
    int posicoesVivasJogador1 = navios[0].NavioTam1 + navios[0].NavioTam2 * 2 + navios[0].NavioTam3 * 3 + navios[0].NavioTam4 * 4;
    int posicoesVivasJogador2 = navios[1].NavioTam1 + navios[1].NavioTam2 * 2 + navios[1].NavioTam3 * 3 + navios[1].NavioTam4 * 4;
    int acertosJ1 = 0, acertosJ2 = 0, tiroValido = 0;
    char MatrizP1[linha][coluna];
    char MatrizP2[linha][coluna];
    char JogadasP1[linha][coluna];
    char JogadasP2[linha][coluna];
    Setcampo(MatrizP1, MatrizP2, JogadasP1, JogadasP2);
    ExibeCampo(1, MatrizP1, JogadasP1, 1);
    ExibeCampo(2, MatrizP2, JogadasP2, 1);
    SelecionaNavio(1, MatrizP1, navios[0], jogadorUmNavios);
    // SelecionaNavio(2, MatrizP2, navios[1], jogadorDoisNavios);
    while (posicoesVivasJogador1 > 0 && posicoesVivasJogador2 > 0)
    {
        repeticoes++;
        printf("Jogador 1 seu campo e navios\n");
        ExibeCampo(1, MatrizP1, JogadasP1, 3);
        printf("Faca sua jogada Ex: B2\t\tJogada num: \n");
        while (tiroValido == 0)
        {
            getpos(tiroPos);
            tiroValido = validaSelecao(tiroPos);
            if (tiroValido == 0)
            {
                printf("Erro de digitacao ou fora de alcance\nCorrija\n");
                continue;
            }
        }
        posicoesVivasJogador1 -= Analisatiro(MatrizP2, JogadasP1, tiroPos);
        tiroValido = 0;
        limpaTela();
        printf("Jogador 2 seu campo e navios\n");
        ExibeCampo(2, MatrizP2, JogadasP2, 3);
        printf("Faca sua jogada Ex: B2\t\tJogada num: \n");
        while (tiroValido == 0)
        {
            getpos(tiroPos);
            tiroValido = validaSelecao(tiroPos);
            if (tiroValido == 0)
            {
                printf("Erro de digitacao ou fora de alcance\nCorrija\n");
                continue;
            }
        }
        posicoesVivasJogador2 -= Analisatiro(MatrizP1, JogadasP2, tiroPos);
        tiroValido = 0;
        limpaTela();
    }

    return 1;
}

int main()
{
    int const jogadores = 2;
    Navios navios[jogadores];
    char tecla;
    printf("Aperte qualquer tecla para iniciar\n");
    scanf("%c", &tecla);
    getchar();
    BatalhaNaval(navios);
}