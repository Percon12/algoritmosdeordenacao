/*
    Método de Ordenação de Dados - Merge Sort
*/

#include<stdio.h>
#include<stdlib.h>
 
#define exch(a,b) {int c; c=a; a=b; b=c;}
 
void intercala(int *v, int esq, int dir1, int dir2)
{
   int *v2 = malloc((dir2-esq)*sizeof(int));
   int k=0;
   int i=esq;
   int j=dir1;
 
   while(i<dir1 && j<dir2)
   {
      if(v[i] <= v[j])
      {
         v2[k++] = v[i++];
      }
      else
      {
         v2[k++] = v[j++];
      }
   }
 
   while(i < dir1)
   {
      v2[k++] = v[i++];
   }
      while(j < dir2)
      {
         v2[k++] = v[j++];
      }
 
   k=0;
   
   for(i=esq; i<dir2; i++)
   {
      v[i] = v2[k++];
   }
   
   free(v2);
}
 
void mergesort(int *v, int esq, int dir)
{
   if(esq < dir-1)
   {
      int meio = (dir+esq)/2;
 
      mergesort(v,esq,meio);
      mergesort(v,meio,dir);
      intercala(v,esq,meio,dir);
   }
}
 
int main()
{
   int tam, *vetor;
 
   scanf("%d", &tam);
   
   vetor = malloc(tam*sizeof(int));
 
   for(int i=0; i<tam; i++)
   {
      scanf("%d", &vetor[i]);
   }
 
   mergesort(vetor,0,tam);
 
   int i;
   
   for(i=0; i<tam-1; i++)
   {
      printf("%d ", vetor[i]);
   }
   
   printf("%d\n", vetor[i]);
 
   return 0;
}