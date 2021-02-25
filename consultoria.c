/*Ao final do período de 30 dias corridos, representados com valores inteiros de 1 a 30, a empresa Bits & Bytes precisa efetuar a análise da carga horária e o retorno financeiro do trabalho das equipes. Para isso, o seu sistema deve ser capaz de emitir um relatório para a alta gerência. Para cada dia do mês (valores inteiros de 1 a 30), o usuário informa primeiramente quantos pedidos foram feitos neste dia. Em seguida, ele fornece a lista de pedidos indicando a especialidade (MAN, NET, PRG ou GER) e o número de horas necessário para a realização daquele pedido, informar: O dia de maior número de pedidos; o dia com maior número de horas de trabalho e o dia de maior faturamento. Em caso de empate, considere o menor dia. O faturamento e o número total de horas trabalhadas no período. A porcentagem de horas de trabalho por equipe no período. A equipe que menos faturou no período.*/

#include<stdio.h>
#include<string.h>


//Função criada devido a necessidade de inicializar os vetores abaixo criados na main().
int iniciarvetor(int vma[], int vne[], int vpr[], int vge[])
{
	int i;

	for(i=0;i<30;i++)
	{
	   vma[i]=0;
	   vne[i]=0;
	   vpr[i]=0;
	   vge[i]=0;
	}
	   listaped(vma,vne,vpr,vge);
	   return 0;
}

//Função responsável por calcular e mostrar a porcentagem de horas de trabalho, e a equipe que menos faturou. 
void trabalhoequipe ( int totalhoras, int valorman, int valornet, int valorprg, int valorger)
{
	float pman,pnet,pprg,pger,man,net,prg,ger,thoras;
//Tivemos de criar novas variaveis em float mudando o tipo de dado das antigas, afim de achar a porcentagem.	
	man=valorman;
	net=valornet;
	prg=valorprg;
	ger=valorger;
	
	thoras=totalhoras;
	valorman=man*100;
	valornet=net*120;
	valorprg=prg*150;
	valorger=ger*200;
//Calculo das porcentagens horas de trabalho das equipes.
	pman=(man/thoras)*100;
	pnet=(net/thoras)*100;
	pprg=(prg/thoras)*100;
	pger=(ger/thoras)*100;
	
	printf("Porcentagem de horas de trabalho:\n");
	printf("MAN: %.0f%c\n",pman,37);
	printf("NET: %.0f%c\n",pnet,37);
	printf("PRG: %.0f%c\n",pprg,37);
	printf("GER: %.0f%c\n",pger,37);

//Criamos a condição para achar a equipe que menos faturou!	
	if((valorman<valornet)&&(valorman<valorprg)&&(valorman<valorger))
	{
	   printf("Equipe que menos faturou: MAN\n");
	}
	   else if((valornet<valorman)&&(valornet<valorprg)&&(valornet<valorger))
	   {
	      printf("Equipe que menos faturou: NET\n");
	   }
	      else if((valorprg<valorman)&&(valorprg<valornet)&&(valorprg<valorger))
	      {
	         printf("Equipe que menos faturou: PRG\n");
	      }
	         else if((valorger<valorman)&&(valorger<valornet)&&(valorger<valorprg))
		 {
	   	    printf("Equipe que menos faturou: GER\n");
		 }			
}
/*Função responsável por encontrar grande parte do relatório gerencial exceto as porcentagens e a equipe que menos faturou,
mas ela é quem fornece os parametros para encontra-los.*/
int listaped (int vma[], int vne[], int vpr[], int vge[])
{
   int a,i,qserv,nped,maiorped,hora,diamaiorh,faturamento,totalhoras,horas,maiorhora;
   int valorman,valornet,valorprg,valorger,mfatur,valorm,valor,diamaior;	
   char espec[4];
   
   hora=horas=totalhoras=maiorhora=diamaiorh=mfatur=valorm=0;		
   valor=faturamento=valorman=valornet=valorprg=valorger=0;

//Primeira estrutura de repetição criar os 30 dias do mês. 	 
  	for(i=0; i<30;i++)
  	{	   
	   printf("\nDia %d\n",i+1);
	   printf("Quantidade de serviços solicitados:");	
	   scanf("%d",&qserv);	

/*Segunda estrutura de repetição para separar por dia, quais especialidades estão sendo contratadas e por quantas horas,
para isso utilizamos vetores criados na função main(), que armazenam as horas de cada serviço para cada dia. Além de 
armazenar a hora total de trabalho de cada especialidade.*/

           for(a=1;a<=qserv;a++)	
	   {
	      printf("\nEspecialidade:");
	      scanf("%s",espec);
	      if(strcmp(espec,"MAN")==0)
	      {	
	         printf("Horas gastas MAN:");
		 scanf("%d",&hora);
		 vma[i]=vma[i]+hora;
		 valorman=(valorman+hora);
              }	
	      	else if (strcmp(espec,"NET")==0)
		{
		   printf("Horas gastas NET:");
		   scanf("%d",&hora);
                   vne[i]=vne[i]+hora;
		   valornet=(valornet+hora);
               	}
	   		else if (strcmp(espec,"PRG")==0)
			{
			   printf("Horas gastas PRG:");
		           scanf("%d",&hora);
                           vpr[i]=vpr[i]+hora;
 			   valorprg=(valorprg+hora);
	                }

	   			else if (strcmp(espec,"GER")==0)
				{
				   printf("Horas gastas GER:");
				   scanf("%d",&hora);
				   vge[i]=vge[i]+hora;
				   valorger=(valorger+hora);
				}
//Condiçaõ para encontrar o dia de maior numero de pedidos.

	   	if(qserv>nped)
           	{
                   nped=qserv;
	           maiorped=i+1;  
	        }

//Condição para encontrar o dia de maior numero de horas de trabalho.
                   horas=(vma[i]+vne[i]+vpr[i]+vge[i]);
		   if(horas>maiorhora)
	           {
	              maiorhora=horas;
		      diamaiorh=i+1;
	           }	
//Condição para encontrar o dia de maior faturamento.
		   	valor=(vma[i]*100+vne[i]*120+vpr[i]*150+vge[i]*200);
			if(valor>valorm)
	                {
	                   valorm=valor;
		           mfatur=i+1;
	                }
	
	   }	
	   	faturamento=(valor+faturamento); //Acumulando o faturamento total do mês.
		totalhoras=(horas+totalhoras);   //Acumulando o total de horas trabalhadas no mês.
		
  	}
relgerencial(maiorped,diamaiorh,mfatur,faturamento,totalhoras);
trabalhoequipe(totalhoras,valorman,valornet,valorprg,valorger);
return 0;
}
//Função responsável por imprimir parte do relatório gerencial.
int relgerencial (int maiorped, int diamaiorh, int mfatur, int faturamento, int totalhoras) 
{
   	
   printf("\n\nRELATÓRIO GERENCIAL:\n");
   printf("Dia de maior:\n");
   printf("  Numero de pedidos:%d\n",maiorped);
   printf("  Numero de horas trabalhadas:%d\n",diamaiorh);
   printf("  Faturamento:%d\n",mfatur);
   printf("\nFaturamento total(R$):%d.00\n",faturamento);
   printf("Total horas trabalhadas(h):%d\n",totalhoras);		

return 0;
}

main()
{
   int i,qserv;
   int vma [30];	
   int vne [30];
   int vpr [30];	
   int vge [30];	

	printf("      SISTEMA DE GERÊNCIA BITS & BYTE\n");
	printf("Menu especialidades\n  Manutenção de hardware(MAN R$100)  \n  Rede de Computadores(NET R$120)\n");
	printf("  Programação de computadores(PRG R$150)\n  Ger.Sistemas e Software(GER R$200)\n");

	iniciarvetor(vma,vne,vpr,vge);
}
