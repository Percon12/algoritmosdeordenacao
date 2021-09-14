/*
    Método de Ordenação de Dados - Selection Sort
*/

#include <stdio.h>
#include <stdlib.h>

typedef int item;

#define less(A,B) ((A) < (B))

#define lesseq(A,B) ((A) <= (B))

#define exch(A,B) { item t; t=A; A=B; B=t; }

#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void selectionsort(item *v, int l, int r){ // Declara a função select sort;

    if(l == r) return;

    int min = l;

    for(int j = l + 1; j < r; j++){
        if (less(v[j], v[min])){
            min = j;
        }
    }
    exch(v[min], v[l]);
    selectionsort(v, l+1, r);
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
    selectionsort(vetor, 0, tam);

    for(int i=0; i<tam; i++)
    {
        printf("%d ",vetor[i]);
    }
    
    printf("\n");
    
    return 0;

}
