/*Jogo com minimo 2 e máximo 8 jogadores cada jogador receberá 03 números que a máquina gerará aleatoriamente entre 1 e 100 e
mostrará a soma alcançada. A máquina NÃO mostrará os números. Esse jogador terá a chance de
avaliar sua soma e, se desejar, pedir um, dois ou três novos números. Ao pedir novos os números,
o jogador deverá indicar quantos e no lugar de qual número ele deseja substituir. Havendo
substituição, a máquina mostra a nova soma. É o valor definitivo, e o jogador NÃO poderá voltar
atrás. Ganha o jogador que, ao final, apresentar o maior valor de soma.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()

{

	float semente;
	int seg,a,b,c,nao,i,qtdjogador,nome,soma,acm,jgd,novonumero,venc,maior,altnum,cont;
	soma=jgd=venc=0;
	maior=-1;	
		printf("Informe a quantidade de jogadores:\n");
		scanf("%d",&qtdjogador);
	
	//Este bloco verifica se o jogo possui a quantidade necessaria de jogadores para o inicio do jogo.		
		if((qtdjogador<2)||(qtdjogador>8))
		      
		    printf("Informe a quantidade de jogador minimo 2 maximo 8.\n");		
		
		else
		
	//Este bloco incrementa os jogadores.
		for(i=1;i<=qtdjogador;i++){
		    jgd++;

	//Este bloco inicia o jogo, gera 3 numeros aleatorios para o usuário e os soma. Permite também que o usuário informe a quantidade de 		numeros gerados que ele deseja alterar.
			for(acm=0;acm<=qtdjogador;acm++){
		    	   
			   printf("\nJogador = %d\n",jgd);
			   srand(time(NULL));
		           a = rand() %100;
		           b = rand() %100;
		           c = rand() %100;			   
		    
		           soma = (a+b+c);	
		         	
			   printf("\nResultado do jogo = %d\n",soma);
			   printf("Deseja Alterar algum numero, Quantos? Caso não queira digite (0)."); 
			   scanf("%d",&altnum);
			   if(altnum!=0){

	//Este bloco permite o usuario trocar algum numero gerado no inicio do jogo, caso queira.
			  	for(cont=1;cont<=altnum;cont++){

			           printf("Digite (1 = primeiro, 2 = segundo, 3 = terceiro)\n");
			           scanf("%d",&novonumero);
						
			           if(novonumero==1){
			              srand(time(NULL));
		                      a = rand() %100;
			              }
			              else if(novonumero==2){
			                 srand(time(NULL));
		                         b = rand() %100; 
			                 }
			                 else if(novonumero==3){
			                    srand(time(NULL));
		                            c = rand() %100;
			                    }
			
		   	    	     
		   		}
			   }
	
	//Este bloco realiza a soma destes possiveis novos numeros gerados pelo usuario, e imprime o novo resultado.			   
			   soma=(a+b+c);
		   	   if(altnum!=0)
			      printf("Novo resultado do jogo = %d\n\n\n",soma);
	
	//Este bloco verifica a maior soma dos numeros de cada jogador, gerando assim o jogador vencedor.
			   if(soma>maior){
			      maior=soma;
			      venc=i;  
			      }

	//Este bloco define uma condição de parada para os numeros gerados para cada jogador.	
			   if(i<=qtdjogador)
			         break;
			}	
		}
		   if(qtdjogador<=8 && qtdjogador>1)   
		      printf("Jogador vencedor: %d, pontuação: %d\n\n",venc,maior);

 			if(qtdjogador<=8 && qtdjogador>1)
			printf("\nNeste jogo tivemos %d jogadores\n",qtdjogador);
}
