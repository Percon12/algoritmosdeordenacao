/*
    Método de Ordenação de Dados - Quick Sort
*/

#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

// separaCORMEM
int separa(item *V,int l,int r) 
{
  item c=V[r];
  int j=l;
  for(int k=l; k<r; k++)
    if(less(V[k], c))
    {
      exch(V[k], V[j]);
      j++;
    }
  exch(V[j], V[r]);
  return j;
}

// separaSEDGEWICK
/*int separa(item *V,int l,int r) 
{
  int i=l-1, j=r; item v=V[r];
  for(;;)
  {
    while(less(V[++i],v));
    while(less(v,V[--j])) if(j==l) break;
    if(i>=j) break;
    exch(V[i],V[j]);
  }
  exch(V[i],V[r])
  return i;
}*/

// Quicksort
/*void quicksort(item *V,int l, int r)
{
  if (r<=l) return;
  int j=separa(V,l,r);
  quicksort(V,l,j-1);
  quicksort(V,j+1,r);
}*/

// Quicksort mediana de 3
void quicksort(item *V,int l, int r)
{
  if (r<=l) return;

  cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
      cmpexch(V[r],V[(l+r)/2]);

  int j=separa(V,l,r);
  quicksort(V,l,j-1);
  quicksort(V,j+1,r);
}

// Main
int main(void)
{
  int t;
  int r;
  r=scanf("%d",&t);

  item *v=malloc(t*sizeof(item));
  
  for(int i=0;i<t;i++)
    r=scanf("%d",&v[i]);

  quicksort(v,0,t-1);

  printf("\n");

  for(int i=0;i<t;i++)
    r=printf("%d ",v[i]);

  printf("\n");
  
  return 0;
}
