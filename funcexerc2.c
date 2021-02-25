//Calcule e exiba o n-ésimo termo de um PA (Progressão Aritmética), fornecidos os valores de n ,do primeiro termo e da razão . Todos esses valores são números inteiros. Use uma função que calculo o n-ésimo termo e retorne o resultado para a função main() exibir.


#include<stdio.h>

int pa(int a1, int n, int r)
{
int an = a1+(n-1)*r;
return an;
}

main()
{
int an, a1, n, r;
printf("Cálculo de PA (Progressão Aritmética) \n");
printf("Informe valores para 'primeiro termo', 'n' e 'razão': \n");
scanf("%d %d %d", &a1, &n, &r);
printf("Resultado da PA: %d\n", pa(a1, n, r));
}
