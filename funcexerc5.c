/*Implemente um programa que permita ao usuário calcular a área dos seguintes polígonos:triângulo, quadrado, retângulo, trapézio e   círculo.Crie um menu para que o usuário possaescolher qual área do polígono ele deseja calcular. Uma vez escolhido o polígono o usuário deve informar os dados deste polígono (base, altura, lado, raio, etc...) e o programa exibirá a área. Para cada polígono, crie uma função que calcule a sua área e retorne o resultado para a função main() exibir.*/

#include<stdio.h>
#include<math.h>

float triangulo(float a, float b)

{
	float result_t=(a*b)/2; 
	return result_t;
}

float circulo(float c)

{
	float result_c=3.14*pow(c,2);
	return result_c;
}

float trapezio(float a, float b, float c)
{
	float result_tr=((a+b)*c)/2;
	return result_tr;
}

float quadrado(float a)
{
	float result_q=a*a;
	return result_q;
}

float retangulo(float a, float b)
{
	float result_r=a*b;
	return result_r;
}

main()
{
	float a,b,c;
	int opc;

printf("Informe o numero do poligono para calcular a area do mesmo.\n"); 
printf("Para saber a area do triangulo digite: (1)\n");
printf("Para saber a area do circulo digite:   (2)\n"); 
printf("Para saber a area do trapezio digite:  (3)\n"); 
printf("Para saber a area do quadrado digite:  (4)\n");
printf("Para saber a area do retangulo digite: (5)\n");   

scanf("%d" ,&opc);

	switch(opc)
		{
		case 1:
			printf("A area do triangulo é ((a*b)/2):\n");	
			scanf("%f %f" ,&a,&b);
			printf("A area do triangulo é:%.2f\n",triangulo(a,b));
			break;
		case 2:
			printf("A area do circulo é (3.14*pow(c,2)):\n");
			scanf("%f" ,&c);			
			printf("A area do circulo é:%.2f\n",circulo(c));			
			break;
		case 3:
			printf("A area do trapezio é (((a+b)*c)/2):\n");
			scanf("%f %f %f" ,&a,&b,&c);			
			printf("A area do trapezio:%.2f\n",trapezio(a,b,c));			
			break;
		case 4:
			printf("A area do quadrado é (a*a):\n");
			scanf("%f" ,&a);			
			printf("A area do quadrado%.2f\n",quadrado(a));			
			break;
		case 5:
			printf("A area do retangulo é (a*b):\n");
			scanf("%f %f" ,&a,&b);			
			printf("A area do retangulo:%.2f\n",retangulo(a,b));			
			break; 
		}
}
