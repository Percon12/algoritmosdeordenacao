/*
    Método de Ordenação de Dados - Shell Sort
*/

#include <stdio.h>
#include <stdlib.h>

typedef int item;

#define less(A,B) ((A) < (B))

#define lesseq(A,B) ((A) <= (B))

#define exch(A,B) { item t; t=A; A=B; B=t; }

#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

/*void insertionsortH(item *v,int l,int r,int h) // Declarando a função insertion sort com o salto editavel
{
  for(int i=l+h;i<=r;i++)
  {
    int j=i; item tmp=v[j];
    while(j>=l+h && less(tmp,v[j-h]))
    {
      v[j]=v[j-h];
      j-=h;
    }
    v[j]=tmp;
  }
}
*/
void shellsort(item *v,int l,int r) // Declarando a funcao shell sort
{
  int h;
  for(h=1;h<=(r-l)/9;h=3*h+1);
  for(;h>0;h/=3)
  {
  	for(int i=l+h;i<=r;i++)
  	{
    	int j=i; item tmp=v[j];
    	while(j>=l+h && less(tmp,v[j-h]))
    	{
      		v[j]=v[j-h];
      		j-=h;
    	}
    	v[j]=tmp;
  	}
  }
    //insertionsortH(v,0,t-1,h);
}

int main(void) // Declarando a funcao main;
{ 
    item vetor[1000];
    int n = 0;

    while(scanf("%d", &vetor[n]) != EOF)
    {
        n++;
    }

    int tam = n;
    shellsort(vetor, 0, tam);

    for(int i=0; i<tam; i++)
    {
        printf("%d ",vetor[i]);
    }
    
    printf("\n");
    
    return 0;

}