//Faça um programa para calcular a média ponderada do aluno. Imprimir a média com 01 casa decimal.
//Crie uma função que calcule esta média e retorne o resultado para a função main() exibir.

#include<stdio.h>

float media_p(float n1, float n2, float n3)
{
int p1=2, p2=3, p3=1;
float media = (p1*n1+p2*n2+p3*n3)/(p1+p2+p3);
return media;
}

main()
{
float n1, n2,n3;
printf("Informe os valores da Prova1, Prova2 e Prova3: \n");
scanf("%f %f %f", &n1, &n2, &n3);
printf("Média Ponderada: %.1f\n", media_p(n1, n2, n3));
}
