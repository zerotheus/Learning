#include <stdio.h>
#include <string.h>
#include "MatheusOliveira20221160030.h"
// datainvalida 0;
// datavalida 1;
DiasMesesAnos DMA;
int q1(char data[])
{
    int barrasPos[2] = {-1, -1}, valid;
    valid = Valida_Data(data, barrasPos);
    // printf("%d\t", valid);
    return valid;
}

int Valida_Data(char data[], int barrasPos[])
{
    int i, valid = 1, k = 0, DigAno = 0, ddmmyyyy;
    int dia, mes, ano, bissexto = 0;
    for (i = 0; data[i] != '\n' && data[i] != '\0' && i < 11; i++)
    {
        if (data[i] < 48 && data[i] > 57 && data[i] != '/')
        {
            valid = 0;
            return valid;
        }
        if (data[i] == '/')
        {
            if (k < 2) // guarda a posicao das barras
            {
                barrasPos[k] = i;
            }
            else
            {
                // printf("muitas barras\n");
                valid = 0;
                return valid;
            }
            k++;
        }
    }
    for (i = barrasPos[1], DigAno; data[i] != '\0' && data[i] != '\n' && i < 11; i++, DigAno++)
    {
    }
    // printf("%d", DigAno);
    if (DigAno != 3 && DigAno != 5) // formatos de data n aceitos
    {
        // printf("Formato de ano invalido\ndig ano%d", DigAno);
        valid = 0;
        return valid;
    }

    if (barrasPos[0] == 0)
    {
        // printf("Barra em posicao indevida\n");
        valid = 0;
        return valid;
    }

    if (barrasPos[1] - barrasPos[0] != 2 && barrasPos[1] - barrasPos[0] != 3)
    {
        // printf("Posiçao das barras invalidas %d e %d\n", (barrasPos[0] - barrasPos[1]), barrasPos[0] - barrasPos[1]);
        valid = 0;
        return valid;
    }

    ddmmyyyy = Quebra_Data(data, barrasPos);
    dia = ddmmyyyy / 1000000;
    ddmmyyyy = ddmmyyyy % 1000000;
    mes = ddmmyyyy / 10000;
    ddmmyyyy = ddmmyyyy % 10000;
    ano = ddmmyyyy;
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) // Verifica se o ano é bissexto
    {
        bissexto = 1;
    }
    if (dia > 31 || mes > 12) // datas impossiveis
    {
        // printf("Data inexistente");
        valid = 0;
        return valid;
    }

    if (mes == 2 && dia >= 29 && bissexto != 1)
    {
        // printf("Ano nao bissexto\n");
        valid = 0;
        return valid;
    }
    if (mes == 2 && dia > 29)
    {
        // printf("Fevereiro so tem no maximo 29 dias\n");
        valid = 0;
        return valid;
    }
    if (dia >= 31 && mes != 1 && mes != 3 && mes != 5 && mes != 7 && mes != 8 && mes != 10 && mes != 12)
    {
        // printf("Mes sem dia 31\n");
        valid = 0;
        return valid;
    }

    return valid;
}

int Quebra_Data(char data[], int barras[])
{
    int ddmmyyyy = 0, i, DigDia = 0, DigMes = 0, DigAno = 0, dia = 0, mes = 0, ano = 0;
    for (i = 0; data[i] != '/'; i++)
    {
        DigDia++;
    }
    for (i = barras[0] + 1; data[i] != '/'; i++)
    {
        DigMes++;
    }
    for (i = barras[1] + 1; data[i] != '\n' && data[i] != '\0'; i++)
    {
        DigAno++;
    }
    // calculos de datas para suas multiplas posibilidades
    if (DigDia == 1)
    {
        dia = data[0] - 48;
    }
    else
    {
        dia = (data[0] - 48) * 10;
        dia += data[1] - 48;
    }
    if (DigMes == 1)
    {
        mes = data[barras[0] + 1] - 48;
    }
    else
    {
        mes = (data[barras[0] + 1] - 48) * 10;
        mes += (data[barras[0] + 2] - 48);
    }
    if (DigAno == 2)
    {
        ano = (data[barras[1] + 1] - 48) * 10;
        ano += (data[barras[1] + 2] - 48);
        if (ano > 22)
        {
            ano += 1900;
        }
        else
        {
            ano += 2000;
        }
    }
    else
    {
        ano = (data[barras[1] + 1] - 48) * 1000;
        ano += (data[barras[1] + 2] - 48) * 100;
        ano += (data[barras[1] + 3] - 48) * 10;
        ano += (data[barras[1] + 4] - 48);
    }
    // fim dos calculos
    dia = dia * 1000000;
    mes = mes * 10000;
    ddmmyyyy = dia + mes + ano;
    return ddmmyyyy; // uso de vetores ou ponteiros seria mais facil, mas como ha muito onde mostrar o uso de vet decidi usar essa tecnica
}

DiasMesesAnos q2(char dataIncial[], char dataFinal[]) // eu nao sabia que poderiamos retornar funcoes com structs
{
    DiasMesesAnos dma;
    dma.retorno = 1;
    int valid = 1, Barraspos[2], ddmmyyyy[2], dia[2], mes[2], ano[2], diasrestantes, bissexto[] = {0, 0};
    valid = Valida_Data(dataIncial, Barraspos);
    if (valid != 1)
    {
        dma.retorno = 2; // data inicial invalida
        return dma;
    }
    ddmmyyyy[0] = Quebra_Data(dataIncial, Barraspos);
    dia[0] = ddmmyyyy[0] / 1000000;
    ddmmyyyy[0] = ddmmyyyy[0] % 1000000;
    mes[0] = ddmmyyyy[0] / 10000;
    ano[0] = ddmmyyyy[0] % 10000;
    // printf("\nData incial dia %d, mes %d, ano %d\n", dia[0], mes[0], ano[0]);
    if ((ano[0] % 4 == 0 && ano[0] % 100 != 0) || ano[0] % 400 == 0)
    {
        bissexto[0] = 1;
    }
    if (mes[0] == 4 || mes[0] == 6 || mes[0] == 9 || mes[0] == 11)
    {
        diasrestantes = 30;
    }
    if (mes[0] != 4 && mes[0] != 6 && mes[0] != 9 && mes[0] != 11 && mes[0] != 2)
    {
        diasrestantes = 31;
    }
    if (mes[0] == 2 && bissexto[0] == 1)
    {
        diasrestantes = 29;
    }
    if (mes[0] == 2 && bissexto[0] == 0)
    {
        diasrestantes = 28;
    }
    valid = Valida_Data(dataFinal, Barraspos);
    if (valid != 1)
    {
        dma.retorno = 3;
        return dma;
    }
    ddmmyyyy[1] = Quebra_Data(dataFinal, Barraspos);
    dia[1] = ddmmyyyy[1] / 1000000;
    ddmmyyyy[1] = ddmmyyyy[1] % 1000000;
    mes[1] = ddmmyyyy[1] / 10000;
    ano[1] = ddmmyyyy[1] % 10000;
    // printf("Data Final dia %d, mes %d, ano %d\n", dia[1], mes[1], ano[1]);
    if ((ano[1] % 4 == 0 && ano[1] % 100 != 0) || ano[1] % 400 == 0)
    {
        bissexto[1] = 1;
    }
    if (ano[0] > ano[1] || (ano[0] >= ano[1] && mes[0] > mes[1]) || (ano[0] >= ano[1] && mes[0] >= mes[1] && dia[0] > dia[1]))
    {
        dma.retorno = 4;
        return dma;
    }
    int difdias = 0, difmes, difanos;
    if (ano[0] <= ano[1])
    {
        difanos = ano[1] - ano[0];
        if (mes[0] >= mes[1] && dia[0] < dia[1])
        {
            difanos--;
        }
        if (mes[0] > mes[1])
        {

            difmes = 12 - (mes[1] - mes[0]);
            if (dia[0] > dia[1])
            {
                difmes--;
            }
        }
        else
        {
            difmes = mes[1] - mes[0];
            if (dia[0] > dia[1])
            {
                difmes--;
            }
        }
    }
    if (dia[1] >= dia[0])
    {
        difdias = dia[1] - dia[0];
    }
    if (dia[0] > dia[1])
    {
        difdias = (diasrestantes - dia[0]) + dia[1];
    }
    if (bissexto[0] == 1 && bissexto[1] != 1 && mes[1] > 2 && mes[0] <= 2)
    {
        difdias--;
    }
    if (bissexto[1] == 1 && bissexto[0] != 1 && mes[1] > 2 && mes[0] <= 2)
    {
        difdias++;
    }
    dma.qtdDias = difdias;
    dma.qtdMeses = difmes;
    dma.qtdAnos = difanos;
    // printf("difdias: %d, difmes %d, difanos: %d\n", difdias, difmes, difanos);
    return dma;
}

int diferenciaMaiusculas(char texto[], char letra)
{
    int ocorrencias = 0, i;
    for (i = 0; texto[i] != '\n' && texto[i] != '\0'; i++)
    {
        if (texto[i] == letra)
        {
            ocorrencias++;
        }
    }
    return ocorrencias;
}

char seLivradeAcento(char letras[])
{
    int i, j, k;
    for (i = 0, j = i; letras[i] != '\0'; i++)
    {
        k = letras[i];
        if (k != -61)
        {
            letras[j] = letras[i];
            j++;
        }
        else
        {
        }
    }
    // printf("%s", letras);
}
// Bem tava no docs q era pra eu desconsiderar acentos ent fiz uma funcao pra isso
int q3(char texto[], char c, int isCaseSensitive)
{
    int ocorrencias = 0, i;
    /*if (c < 65 || (c > 90 && c < 97) || c > 122)
    {
        c = seLivradeAcento(c);
    }*/

    if (isCaseSensitive == 1)
    {
        ocorrencias = diferenciaMaiusculas(texto, c);
        return ocorrencias;
    }
    if (c > 96 && c < 123)
    {
        c = c - 32;
    }
    for (i = 0; texto[i] != '\n' && texto[i] != '\0'; i++)
    {
        if (texto[i] == c || texto[i] == (c + 32))
        {
            ocorrencias++;
        }
    }
    return ocorrencias;
}
// bem isso tentei manter a complexidade o mais baixa possivel
int q4(char texto[], char buscando[], int pos[])
{
    seLivradeAcento(texto);
    // printf("\n%s", texto);
    int caracteres, i, j, k = 0, n, caracteresiguais = 0, tamanhodotexto, encontros = 0;
    caracteres = strlen(buscando);
    tamanhodotexto = strlen(texto);
    for (i = 0; i < tamanhodotexto; i++)
    {
        if (buscando[0] == texto[i])
        {
            for (j = 0; j < caracteres; j++, i++)
            {
                if (buscando[j] == texto[i])
                {
                    caracteresiguais++;
                }
                else
                {
                    break;
                }
            }
            // printf("qtd iguais %d\n", caracteresiguais);
            if (caracteresiguais == caracteres)
            {
                /// printf("\n");
                /*for (n = i - j; n < i + caracteres - j; n++)
                {
                    //printf("%d, ", n);
                }
                for (n = i - j; n < i + caracteres - j; n++)
                {
                    printf("%c, ", texto[n]);
                }*/
                // printf("\n");
                encontros++;
                pos[k] = i - caracteres + 1;
                pos[k + 1] = i;
                k = k + 2;
            }
            caracteresiguais = 0;
            i = i - j + 1;
        }
    }
    // printf("\nValores retornados\n");
    for (i = 0; i < 2 * encontros; i++)
    {
        // printf("%d ,", pos[i]);
    }
    // printf("\n");
    return encontros;
}

int q5(int num)
{
    // printf("\noriginal %d", num);
    int unidade = 0;
    while (num > 0)
    {
        unidade = unidade * 10;
        unidade += num % 10;
        num = num / 10;
    }
    // printf(" mun: %d\n", unidade);
    return unidade;
}

int q6(int numOriginal, int numBuscado)
{
    int divisor = 1, qtd = 0, copia = numBuscado, segmento;
    while (copia > 0)
    {
        copia = copia / 10;
        divisor = divisor * 10;
    }
    divisor = divisor / 1;
    copia = numOriginal;
    while (copia > 0)
    {
        segmento = copia % divisor;
        if (segmento == numBuscado)
        {
            qtd++;
            copia = copia / divisor;
        }
        else
        {
            copia = copia / 10;
        }
    }
    // printf("qtd: %d\n", qtd);
    return qtd;
}