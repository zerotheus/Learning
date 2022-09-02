#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

struct cliente
{
  char cpf[13];
  char sex;
  int data, cpfinteiro[11]; // dd/mm/yyyy
  char nome[31];
} cliente;

int validanome()
{
  int nomevalido = 0;
  for (int i = 0; cliente.nome[i] != '\0'; i++)
  {
    if (i > 22)
    {
      nomevalido = 1;
      return nomevalido;
    }
  }
  return nomevalido;
}

int validasexo()
{
  int valid = 0;
  if (cliente.sex != 'o' && cliente.sex != 'O' && cliente.sex != 'm' && cliente.sex != 'M' && cliente.sex != 'f' && cliente.sex != 'F')
  {
    valid = 1;
    return valid;
  }
  return valid;
}

int validadata()
{
  int dia, mes, ano, resto, valid = 0;
  dia = cliente.data / (1000000);
  resto = cliente.data % (1000000);
  mes = resto / (10000);
  ano = resto % (10000);
  if (dia > 31 || dia < 1)
  {
    valid = 1;
    return valid;
  }
  if (mes > 12 || mes < 1)
  {
    valid = 1;
    return valid;
  }
  if (ano < 1 || ano > 2022)
  {
    valid = 1;
    return valid;
  }
  if (dia >= 29 && mes == 2 && (ano % 4 != 0))
  {
    valid = 1;
    return valid;
  }
  if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11))
  {
    valid = 1;
    return valid;
  }
  return valid;
}

int validacpf() // seguir regra da receita
{
  int i, dgtverificador1, dgtverificador2, resto, calc=0, valid = 0;
  dgtverificador1 = static_cast<int>(cliente.cpf[9] - 48);
  dgtverificador2 = static_cast<int>(cliente.cpf[10] - 48);
  for (i = 0; i < 11; i++)
  {
    cliente.cpfinteiro[i] = static_cast<int>(cliente.cpf[i] - 48); // converte o valor absoluto do char em inteiro//
  }
  for (i = 0; i < 9; i++)
  {
    calc = calc + (cliente.cpfinteiro[i] * (10 - i));
  }
  resto = ((calc * 10) % 11);
  calc=0;
  if (resto != dgtverificador1)
  {
    valid = 1;
    return valid;
  }
  for (i = 0; i < 10; i++)
  {
    calc = calc + (cliente.cpfinteiro[i] * (11 - i));
  }
  resto = ((calc * 10) % 11);
  if (resto != dgtverificador2)
  {
    valid = 1;
    return valid;
  }
  return valid;
}

int cadastro()
{
  int valid = 0;
  printf("informe seu nome\n");
  fgets(cliente.nome, 30, stdin);
  valid = validanome();
  if (valid != 0)
  {
    printf(" error de validação no nome");
    return valid;
  }
  printf("informe seu sexo\n");
  scanf("%c", &cliente.sex);
  valid = validasexo();
  if (valid != 0)
  {
    printf("erro, sexo invalido");
    return valid;
  }
  getchar();
  printf("digite seu cpf. Somente numeros");
  fgets(cliente.cpf, 13, stdin);
  valid = validacpf();
  if (valid != 0){
    printf("Cpf invalido");
    return valid;
  }
  printf("informe sua data de nascimento\n no formato ddmmyyyy, somente em numeros");
  scanf("%d", &cliente.data);
  valid=validadata();
  if (valid != 0){
    printf("data de nascimento invalida");
    return valid;
  }
  return valid;
}

int main()
{
  int sucess = 0;
  sucess=cadastro();
  if (sucess==1)
  {
    printf("\nfalha ao cadastrar o cliente");
  }else{
    printf("\ncliente cadastrado com sucesso");
  }
  
}