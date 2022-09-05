#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int convertehora[2], hora, minuto, segundos;
  char time[11], time24[9];
  fgets(time, 10, stdin);
  if (time[8] == 'P')
  {
    hora = (time[0] - '0') * 10;
    hora += (time[1] - '0');
    minuto = (time[3] - '0') * 10;
    minuto += (time[4] - '0');
    segundos = (time[6] - '0') * 10;
    segundos += (time[7] - '0');
    if (hora < 12)
    {
      if (hora < 10)
      {
        time[0] += 1;
        time[1] += 2;
      }
      else
      {
        time[0] += 1;
        time[1] += 2;
      }
    }
  }
  else
  {
    hora = (time[0] - '0') * 10;
    hora += (time[1] - '0');
    minuto = (time[3] - '0') * 10;
    minuto += (time[4] - '0');
    segundos = (time[6] - '0') * 10;
    segundos += (time[7] - '0');
    if (hora == 12)
    {
      time[0] = time[0] - 1;
      time[1] = time[1] - 2;
    }
  }
  time[8] = '\0';
  puts(time);
}