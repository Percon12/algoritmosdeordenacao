/*
    Método de Ordenação de Dados - Insertion Sort
*/

#include <stdio.h>
#include <stdlib.h>

typedef int item;

#define less(A,B) ((A) < (B))

#define lesseq(A,B) ((A) <= (B))

#define exch(A,B) { item t; t=A; A=B; B=t; }

#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

/*void insertionsort(item *v, int l, int r)
{ // Declara a função insertion sort mais lenta;
	for(int i = l+1; i <= r; i++){
		for(int j = i; j > l; j--){
			if(less(v[j], v[j-1])){
				exch(v[j], v[j-1]);
			}
		}
	}
}*/

void insertionsort(item *v, int l, int r)
{ // Declara a função insertion sort mais rapida;
	for(int i = r; i > l; i--){
		cmpexch(v[i-i], v[i]);
	}

	for(int i = l+2; i <= r; i++){
		int j=i;
		item tmp = v[j];
		while(less(tmp, v[j-1])){
			v[j] = v[j-1];
			j--;
		}
		v[j] = tmp;
	}	
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
    insertionsort(vetor, 0, tam);

    for(int i=0; i<tam; i++)
    {
        printf("%d ",vetor[i]);
    }
    
    printf("\n");
    
    return 0;

}