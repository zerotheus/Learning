#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;//@Ntheus You need something like while (fgets(string, 256, stdin)) but really instead of doing puzzles on web sites you need to spend some time actually learning C++. This puzzle seems too advanced for your knowledge of coding.//
//@Ntheus The reason the first code repeats is that it has a while loop while (getline(cin, data)). There is no such loop in your code//

int main()
{
  char string[256], SorC[256], P1, P2;
  int size, next, word, endw, CC, x;
 while(fgets(string, 256, stdin)){
  CC=strlen(string);
  P1=string[0];
  P2=string[2];
  if (string[0] == 'S') 
  {
    if (string[2] == 'C')
    {
      for (endw = 4, size = 0, word = 0, next = endw + 1; string[endw - 1] != '\0'; endw++, size++, next++)
      {
        if (endw == 4)
        {
          SorC[size] = string[endw] + 32;
        }
        else
        {
          if (string[next] > 64 && string[next] < 91)
          {
            SorC[size + word] = string[endw];
            word++;
            SorC[size + word] = 32;
          }
          else
          {
            if (string[endw] > 64 && string[endw] < 91)
            {
              SorC[size + word] = string[endw] + 32;
            }
            else
            {
              SorC[size + word] = string[endw];
            }
          }
        }
      }
    }
    if (string[2] == 'V')
    {
      for (endw = 4, size = 0, word = 0, next = endw + 1; string[endw] != '\0'; endw++, size++, next++)
      {
          if (string[endw] > 64 && string[endw] < 91)
        {
          string[endw] = string[endw] + 32;
          
        }
        if (string[next] > 64 && string[next] < 91)
        {
          SorC[size] = string[endw];
          word++;
          SorC[size + word] = 32;
        }
        else
        {
          SorC[size + word] = string[endw];
        }
      }
    }
    if (string[2] == 'M')
    {

      for (endw = 4, size = 0, word = 0, next = endw + 1; string[endw] != '('; endw++, size++, next++)
      {
        if (string[endw] > 64 && string[endw] < 91){
          string[endw]=string[endw]+32;
        }

        if (endw == 4)
        {
          SorC[endw - 4] = string[endw];
        }
        else if (string[next] > 64 && string[next] < 91)
        {
          SorC[endw - 4] = string[endw];
          SorC[endw - 3] = 32;
          word++;
          size++;
        }
        else
        {
          SorC[endw - 4 + word] = string[endw];
        }
      }
    }
  }
  else
  {
    if (string[2] == 'C')
    { string[4]=string[4]-32;
      for (endw = 0, size = -4, word = 0, next = endw + 1; string[endw] != '\0'; endw++, size++, next++)
      {
        if (endw < 4)
        {
          string[endw] = 127;
        }
        else
        {
          if (string[endw] == 32)
          {
            word--;
            string[endw] = 127;
            string[endw + 1] = string[endw + 1] - 32;
          }
          else
          {
            SorC[size + word] = string[endw];
          }
        }
      }
    }
    if (string[2] == 'V')
    {
      for (endw = 0, size = -4, word = 0, next = endw + 1; string[next] != '\0'; endw++, size++, next++)
      {
        if (endw < 4)
        {
          string[endw] = 127;
        }
        else
        {
          if (string[endw] == 32)
          {
            word--;
            string[endw] = 127;
            string[endw + 1] = string[endw + 1] - 32;
          }
          else
          {
            SorC[size + word] = string[endw];
          }
        }
      }
    }
    if (string[2] == 'M')
    { for (x = CC; x < CC+2; x++)
    {
      if (x==CC)
      {
        string[x]=='(';
      }else{
        string[x]==')';
      }
      
    }
    
      for (endw = 0, size = -4, word = 0, next = endw + 1; string[endw] != '\0'; endw++, size++, next++)
      {
        if (endw < 4)
        {
          string[endw] = 127;
        }
        else
        {
          if (string[endw] == 32)
          {
            word--;
            string[endw] = 127;
            string[endw + 1] = string[endw + 1] - 32;
          }
          else
          {
            SorC[size + word] = string[endw];
          }
          if (SorC[size + word]=='\n')
          {
            SorC[size + word]=40;
            SorC[size + word+1]=41;
          }
          
        }
      }
    }
  }

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  for (int i = 0; ((i < size) && ((SorC[i]<122 && SorC[i]>64) || SorC[i]==32)); i++)
  {
    printf("%c", SorC[i]);
  }
  if ((P2=='M') && (P1=='C'))
    {
      printf("()");
    }
  printf("\n");
 }
  return 0;
}
