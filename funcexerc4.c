//Faça um programa que lê dois números reais e imprima a soma, multiplicação e divisão desses dois números.
//Implemente uma função que realize a soma, outra para a multiplicação e uma terceira para a divisão.
//Todas as funções devem retornar o resultado para a função main() exibir.

#include<stdio.h>

float soma(float a, float b)
{

float result_s=(a+b);
return result_s;
}

float multip(float a, float b)
{
float result_m=(a*b);
return result_m;
}

float divis(float a, float b)
{
float result_d=(a/b);
return result_d;
}

main()
{ 
float a,b;

printf("Informe dois numeros:");
scanf("%f %f",&a,&b);
printf("A soma dos numeros é:%.2f\n",soma(a,b));
printf("A multiplicação dos numeros é:%.2f\n",multip(a,b));
printf("A divisão dos numeros é:%.2f\n",divis(a,b));
}
