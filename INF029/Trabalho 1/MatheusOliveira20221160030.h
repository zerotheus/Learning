// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Matheus de Lima Oliveira
//  email: matheusoliveira.7313@gmail.com
//  Matrícula: 20221160030
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################
#ifndef TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H
#define TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H

typedef struct DQ
{
    int Dia;
    int Mes;
    int Ano;
    int valido; // 0 se inválido, e 1 se válido

} DataQuebrada;

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

// int somar(int x, int y); //função utilizada para testes
// int fatorial(int x); //função utilizada para testes
int q1(char data[]);
DiasMesesAnos q2(char dataIncial[], char dataFinal[]);
// DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char texto[], char c, int isCaseSensitive);
int diferenciaMaiusculas(char texto[], char letas);
char seLivradeAcento(char letras[]);
// int q3(char *texto, char c, int isCaseSensitive);
int q4(char texto[], char buscando[], int pos[]);
// int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
// int q6(int numerobase, int numerobusca);
int q6(int numOriginal, int numBuscado);
// DataQuebrada quebraData(char data[]);
int Valida_Data(char data[], int barrasPos[]);
int Quebra_Data(char data[], int barras[]);

#endif // TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H