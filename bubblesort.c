#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *v;
  int len, i, cont, k;

  printf("Defina o tamanho do vetor: ");
  scanf("%d", &len);

  v = (int *)(malloc(len * sizeof(int)));

  for(i = 0; i < len; i++)
  {
    printf("Insira um valor: \n");
    scanf("%d", &v[i]);
  }
  for(cont = 1; cont < len; cont++)
  {
    for(i = 0; i < len - 1; i++)
    {
      if(v[i] > v[i + 1])
      {
      k = v[i];
      v[i] = v[i + 1];
      v[i + 1] = k;
      }
    }
  }
  
  printf("\n Elementos do vetor ordenados de maneira crescente: \n");
  for(i = 0; i < len; i++)
  {
    printf("%d", v[i]);
    printf("\n");
  }

  free(v);

  return 0;
}