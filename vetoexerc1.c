#include<stdio.h>



void num_1(int vetor[])
{
	int i;
	printf("informe 5 numeros:\n");	
	for(i=0; i<5; i++){
			scanf("%d",&vetor[i]);
	}
}

int num_2(int vetor[])
{
	int i;
	for(i=0; i<5; i++)
		printf("%d\n",vetor[i]);
}

main()
{
	int tam=5;
	int vetor[tam];
	num_1(vetor);
	num_2(vetor);
}



