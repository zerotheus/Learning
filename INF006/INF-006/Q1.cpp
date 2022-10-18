#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct data
{
    int dia, mes, ano;
    char data[12]; // DD/MM/YYYY
};

int Anobissexto(int ano);

int CalculaDias(int dia, int mes, int ano);

int EscreveDataPorExtenso(int dia, int mes, int ano);

int validaDataInteira(int dia, int mes, int ano, struct data Datainteira[]);

int validaDataString(char Data[], struct data Datainteira[]);

int DataDaPascoa(int ano);
// 0 Falso //1 verdade
int Anobissexto(int ano)
{
    int bissexto = 0;
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    {
        bissexto = 1;
    }
    return bissexto;
}

int validaDataString(char Data[], struct data Datainteira[])
{
    int valid = 1, i, dia, mes, ano, bissexto = 0;
    for (i = 0; i < Data[i] != '\n' && Data[i] != '\0'; i++)
    {
        if (Data[i] < 48 && Data[i] > 57 && Data[i] != '/')
        {
            valid = 0;
            return valid;
        }
    }
    dia = (Data[0] - 48) * 10;
    dia += (Data[1] - 48);
    mes = (Data[3] - 48) * 10;
    mes += (Data[4] - 48);
    ano = (Data[6] - 48) * 1000;
    ano += (Data[7] - 48) * 100;
    ano += (Data[8] - 48) * 10;
    ano += (Data[9] - 48);
    valid = validaDataInteira(dia, mes, ano, Datainteira);
    return valid;
}

int validaDataInteira(int dia, int mes, int ano, struct data Datainteira[])
{
    int valid = 1, bissexto = 0;
    bissexto = Anobissexto(ano);
    if (dia > 31 || mes > 12 || dia < 1 || mes < 1 || ano < 0)
    {
        valid = 0;
        return valid;
    }
    if (dia >= 29 && mes == 2 && bissexto == 0)
    {
        valid = 0;
        return valid;
    }
    if (dia > 29 && mes == 2 && bissexto == 1)
    {
        valid = 0;
        return valid;
    }
    if (dia >= 31 && mes != 1 && mes != 3 && mes != 5 && mes != 7 && mes != 8 && mes != 10 && mes != 12)
    {
        valid = 0;
        return valid;
    }
    Datainteira[0].dia = dia;
    Datainteira[0].mes = mes;
    Datainteira[0].ano = ano;
    return valid;
}

int CalculaDias(int dia, int mes, int ano)
{
    int inteiro, bissexto = 0, i, totalDias = 0, soma, sub;
    printf("Digite seu inteiro\n");
    scanf("%d", &inteiro);
    getchar();
    bissexto = Anobissexto(ano);
    for (i = 1; i < mes; i++)
    {
        if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            totalDias += 30;
        }
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
        {
            totalDias += 31;
        }
        if (i == 2 && bissexto == 0)
        {
            totalDias += 28;
        }
        if (i == 2 && bissexto == 1)
        {
            totalDias += 29;
        }
    }
    totalDias += dia;
    soma = totalDias + inteiro;
    sub = totalDias - inteiro;
    printf("total de dias: %d, seu inteiro: %d\nSoma: %d\nSub: %d\n", totalDias, inteiro, soma, sub);
    return 0;
}

int EscreveDataPorExtenso(int dia, int mes, int ano)
{
    char mesExtenso[12][20];
    strcpy(mesExtenso[0], "Janeiro");
    strcpy(mesExtenso[1], "Fevereiro");
    strcpy(mesExtenso[2], "Março");
    strcpy(mesExtenso[3], "Abril");
    strcpy(mesExtenso[4], "Maio");
    strcpy(mesExtenso[5], "Junho");
    strcpy(mesExtenso[6], "Julho");
    strcpy(mesExtenso[7], "Agosto");
    strcpy(mesExtenso[8], "Setembro");
    strcpy(mesExtenso[9], "Outubro");
    strcpy(mesExtenso[10], "Novembro");
    strcpy(mesExtenso[11], "Dezembro");
    mes = mes - 1;
    printf("%d de %s de %d\n", dia, mesExtenso[mes], ano);
    return 0;
}

int DataDaPascoa(int ano)
{ // R = L
    // n = mes da pascoa
    int a, b, c, d, e, g, h, j, k, m, r, n, p;
    a = ano % 19;
    b = ano / 100, c = ano % 100;
    d = b / 4, e = b % 4;
    g = (8 * b + 13) / 25;
    h = (19 * a + b - d - g + 15) % 30;
    j = c / 4, k = c % 4;
    m = (a + 11 * h) / 319;
    r = (2 * e + 2 * j - k - h + m + 32) % 7;
    n = (h - m + r + 90) / 25;
    p = (h - m + r + n + 19) % 32;
    printf("a: %d, b: %d, c: %d, d: %d, e: %d, g: %d, h: %d, j: %d, k: %d, m: %d, r: %d, n: %d, p: %d\n", a, b, c, d, e, g, h, j, k, m, r, n, p);
    if (n == 3)
    {
        printf("O dia: %d Março\n", p);
    }
    if (n == 4)
    {
        printf("O dia: %d Abril\n", p);
    }

    return p;
}

int main()
{
    struct data Data[1]; // aloquei 1 pra modificao em qlqr lugar do parametro ser repassada para a variavel sem usar ponteiros
    int valid, pascoa;
    while (valid != 2)
    {
        printf("Digite o a Data no formato: DD/MM/AAAA\n");
        fgets(Data[0].data, 12, stdin);
        valid = validaDataString(Data[0].data, Data);
        if (valid == 0) // Nao vi ponto em repetir as validacoes ou refazer as validacoes em cada uma
        {
            printf("Data invalida\n");
            printf("Nao e possivel continuar as operações\n");
            continue;
        }
        printf("dia: %d mes: %d ano: %d\n", Data[0].dia, Data[0].mes, Data[0].ano);
        CalculaDias(Data[0].dia, Data[0].mes, Data[0].ano);
        EscreveDataPorExtenso(Data[0].dia, Data[0].mes, Data[0].ano);
        DataDaPascoa(Data[0].ano);
    }
}
