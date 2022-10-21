#include <stdio.h>

using namespace std;

void Exibe(char jogo[3][3])
{
    int l, c;
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("%c", jogo[l][c]);
            if (c < 2)
            {
                printf("|");
            }
        }
        printf("\n");
    }
}

int AnalisaJogo(int jogador, char Jogo[3][3])
{
    char XouBola[2] = {'X', 'O'};
    int l = 0, c = 0, velha = 0;
    // Analisa as linhas
    for (l = 0; l < 3; l++)
    {
        if (Jogo[l][c] == XouBola[jogador] && Jogo[l][c + 1] == XouBola[jogador] && Jogo[l][c + 2] == XouBola[jogador])
        {
            velha = jogador + 1;
            return velha;
        }
    }
    // analisa colunas
    l = 0;
    for (c = 0; c < 3; c++)
    {
        if (Jogo[l][c] == XouBola[jogador] && Jogo[l + 1][c] == XouBola[jogador] && Jogo[l + 2][c] == XouBola[jogador])
        {
            velha = jogador + 1;
            return velha;
        }
    }
    l = 0;
    c = 0;
    // diagonais
    if (Jogo[l][c] == XouBola[jogador] && Jogo[l + 1][c + 1] == XouBola[jogador] && Jogo[l + 2][c + 2] == XouBola[jogador])
    {
        velha = jogador + 1;
        return velha;
    }

    if (Jogo[l + 2][c] == XouBola[jogador] && Jogo[l + 1][c + 1] == XouBola[jogador] && Jogo[l][c + 2] == XouBola[jogador])
    {
        velha = jogador + 1;
        return velha;
    }
    return 0;
}

void posdejogo(int jogador, char jogo[3][3])
{
    char XouBola[2] = {'X', 'O'};
    int pos = 0, l, c;
    while (pos < 1 || pos > 9)
    {
        printf("%d digite o numero de onde quer jgr: ", jogador + 1);
        scanf("%d", &pos);
        getchar();
        if (pos <= 3)
        {
            l = 0;
            c = 0 + pos - 1;
        }
        if (pos > 3 && pos <= 6)
        {
            l = 1;
            c = pos - 4;
        }
        if (pos > 6 && pos <= 9)
        {
            l = 2;
            c = pos - 7;
        }
        if (jogo[l][c] != 'X' && jogo[l][c] != 'O')
        {
            jogo[l][c] = XouBola[jogador];
        }
        else
        {
            printf("Nao é possivel jogar nessa posicao\n");
            pos = 10;
        }
    }
}

int main()
{
    char iniciar;
    int velha = 0, l, c = 0, xy = 0, qtdjogadas = 1;
    char jogo[3][3], jogadas;
    for (l = 0; l < 3; l++, xy = xy + 3)
    {
        jogo[l][c] = '1' + xy;
        jogo[l][c + 1] = '2' + xy;
        jogo[l][c + 2] = '3' + xy;
    }

    printf("Digite qualquer tecla para iniciar\n");
    scanf("%c", &iniciar);
    getchar();
    while (velha == 0 && qtdjogadas < 10)
    {
        Exibe(jogo);
        posdejogo(0, jogo);
        velha = AnalisaJogo(0, jogo);
        if (velha != 0)
        {
            printf("O x venceu\n");
            break;
        }
        qtdjogadas++;
        if (qtdjogadas > 9)
        {
            break;
        }
        Exibe(jogo);
        posdejogo(1, jogo);
        velha = AnalisaJogo(1, jogo);
        if (velha != 0)
        {
            printf("A Bola venceu\n");
            break;
        }
        qtdjogadas++;
        printf("\n%d\n", qtdjogadas);
    }
    if (qtdjogadas >= 9)
    {
        printf("O jogo venceu\n");
    }
}