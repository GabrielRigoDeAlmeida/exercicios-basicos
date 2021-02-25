//Faça um programa que leia um número inteiro que corresponde a uma temperatura em graus Celsius. Seu programa deve converter a temperatura de Celsius (c) para Fahrenheit (f). [C/5 = (F-32)/9]. Use uma função que faça a conversão e retorne o resultado para a função main() exibir.


#include<stdio.h>

int f(int c)
{
 int f = (c*9+160)/5;
 return f;
}
main()
{
	int c;
	printf("Informe temperatura em ºC:");
	scanf("%d", &c);
	printf("Temperatura em ºF: %d\n", f(c));
}
