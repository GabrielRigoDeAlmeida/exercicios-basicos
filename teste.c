#include<stdio.h>
#include<string.h>

/*criamos a estrutura das perguntas*/

typedef struct Questao
{
    int id;
    char titulo[100];

}questao;

/*Esta função permite apagar qualquer pergunta digitada pelo usuário
Criamos um condicional que faz a filtragem de qual o numero da pergunta que o usuario digitou de maneira que no laço
de repeticao os elementos dentro dos indices são decrementados, para liberar espaço nas ultimas posiçoes do vetor.*/
void excluir (questao pergunta[]) 
{
	int i, pos, encontrou, elem,qtdperg;
	char escolha[4];
	encontrou = pos = 0;
   	qtdperg=11;

        printf("Digite o \"numero da pergunta\" que deseja excluir\n");
        scanf("%d",&elem);
	elem=elem-1;	
           
	while ((pos < qtdperg) && (!encontrou))
	{	
	   
	   if (elem==pos)
	   {
	      encontrou = 1;

	      for (i = pos; i <= qtdperg; i++ )
	      {	
	         strcpy(pergunta[i].titulo, pergunta[i + 1].titulo);
		 pergunta[i].id = pergunta[i + 1].id;
              }
		     
	   }

	   pos = pos + 1;
        }  
}

/*Esta função exibe ao usuario as perguntas com seus respectivos indices cadastrados*/
void lista (questao pergunta[], int qtdperg)
{
   int i;

   for(i=0;i<qtdperg;i++)
   {
      printf(" %d- %s\n",i+1,pergunta[i].titulo);
      printf(" ID: %d\n", pergunta[i].id); 
   }	  
}

/*Esta função recebe as respostas das perguntas feitas pelo usuário e com base nelas indica um curso cadastrado*/
int testevocacional (questao pergunta[], int qtdperg)  
{
	int i,tema1,tema2;
	char resposta[4];

	tema1=tema2=0;
        printf("     \n\"ESTE É O NOSSO PROTÓTIPO DO TESTE VOCACIONAL DA FACULDADE CATÓLICA SALESIANA.\"\n");
        printf("          Iremos lhe fazer algumas pergutas responda (sim e nao)\n");
        printf("          Ao final indicaremos entre os cursos de Sist.informação e Enfermagem o que mais combina com seu perfil.\n");
 
	for(i=0;i<qtdperg;i++)
	{
           if(strcmp(pergunta[i].titulo,"0")!=0)      
           {     
		printf("\n%s  ",pergunta[i].titulo);
		scanf("%s",resposta);
		
		if(strcmp(resposta,"sim")==0)
		{		
		   if(pergunta[i].id==1)
		   {
                      tema1++;
                   }   
		   
                   else if(pergunta[i].id==2)
		   {
		      tema2++;
		   }
	        }
           }
	}

	if(tema1>tema2 || tema1==tema2)
	{
   	   printf("          \nA FACULDADE CATÓLICA SALESIANA TE INDICA O CURSO DE: \"SISTEMAS DE INFORMAÇÃO\"\n");
	   printf("     A mensalidade do curso é: R$ 573,00\n     Duração: 4 anos\n"); 
	   printf("     Área de atuação: Gerência de tecnologia da informação, Analista de sistemas,\n");
	   printf("     Projetista de sistemas, Programador de sistemas, Consultor independênte e outras.\n");
	   printf("     Salário inicial: R$ 2,6 mil.\n     Salário no auge: Pode superar os R$ 20 mil\n");	
	   printf("     Vagas disponíveis por ano: 64.380 em todo o país.\n\n");		
	}
	   else if(tema2>tema1)
	   {	
	      printf("          \nA FACULDADE CATÓLICA SALESIANA TE INDICA O CURSO DE: \"ENFERMAGEM\"\n");
	      printf("     A mensalidade do curso é R$ 865,00\n     Duração 4 anos\n");
	      printf("     Área de atuação: Hospitais, unidades basicas de saude,\n");
	      printf("     creches, clinicas, Consultórios de atendimentos particular e outras.\n");
	      printf("     Salário inicial: R$ 2,5 mil.\n     Salário no auge: Pode superar os R$ 12 mil\n");	
	      printf("     Vagas disponíveis por ano: 116.343 em todo o país.\n\n");	
	   }	
return 0;	
}

main()
{
   
   FILE *fp;
   char user[8];
   char resposta[4];
   int escolha,qtdperg,i;
   questao pergunta[50]; 
   
   escolha=qtdperg=0;

/*Tenta abrir o arquivo questionario.txt. Se não conseguir, ou se o arquivo não existe fp fica com o valor NULL*/
    if((fp = fopen("questionario.txt", "r+")) != NULL)
    {
//Enquanto não atingiu o final do arquivo 
       while(!feof(fp))
       {
/*Leia do arquivo o ID da pergunta e o título da questão*/  
          fscanf(fp, "%d", &pergunta[qtdperg].id);
          fscanf(fp, "\n%[^\n]\n", pergunta[qtdperg].titulo);
          qtdperg++;
       }
    }

   printf("                    SEJA MUITO BEM VINDO AO\n");
   printf("      TESTE VOCACIONAL DA FACULDADE CATÓLICA SALESIANA\n");
   printf("  Para gerenciar o programa utilize o login (admin)\n  Para responder o teste utilize o login (usuario)\n");
   printf("\n\n  Informe seu login:"); 
   scanf("%s",user);
   
   if(strcmp(user,"admin")==0)
   {
      while(escolha != 5)  
      {
/*Aqui funciona o gerenciador de comandos do adminstrador, daqui chamamos todas as funções do menu administrador*/
         printf("\n      MENU ADMINISTRADOR\n");
         printf("  (1). Cadastro de perguntas\n");
         printf("  (2). Ir para o teste vocacional\n");
         printf("  (3). Apagar pergunta\n");
         printf("  (4). Listar perguntas\n");
         printf("  (5). Sair\n");
         printf("\n\n  Digite sua opção:"); 
         scanf("%d",&escolha);
     
   	 if(escolha==1)
	 {
/*Criamos um condicional para informar ao usuario que excedeu o limite de perguntas para cadastro*/
            if(qtdperg==11) 
            {
               printf("Favor apagar alguma pergunta\n");
               continue;
            }
/*Aqui e feita a leitura do id e pergunta feitas pelo administrador e definimos que seriam no maximo 11*/
	       while(qtdperg<11)
	       {				
            	  printf("Digite o ID da pergunta (1 para S.I e 2 Enfermagem): ");
                  scanf("%d", &pergunta[qtdperg].id);
                  printf("Digite a %d pergunta: ", qtdperg+1);
                  scanf("\n%[^\n]", pergunta[qtdperg].titulo);
            	  qtdperg=qtdperg+1;

		  if(qtdperg<11)
                  {
	             printf("\nDeseja cadastrar outra pergunta? (sim ou nao): ");
	             scanf("%s",resposta);
		  

	    	     if (strcmp(resposta,"sim")==0)
	    	     {
	                continue;
	    	     }
	    	        else if (strcmp(resposta,"sim")!=0)
		        {
	   	           break;
		        }
                  }      
	       }	
	 }  
            else if(escolha==2)
	    {
	       testevocacional (pergunta,qtdperg); 
            }
	       else if(escolha==3)
               {
                  excluir(pergunta);
                  qtdperg=qtdperg-1;
	       }
                  else if(escolha==4)
                  {
                     lista(pergunta, qtdperg);
                  }  		   
      }   
   }


      else if (strcmp(user,"usuario")==0)
      {   
	testevocacional (pergunta,qtdperg);
      }

// Procedimento de saida do programa!

// Cria um novo arquivo chamado
    fp = fopen("questionario.txt", "w");
// Escreve todo o vetor de perguntas no arquivo
    for(i = 0; i < qtdperg; i++)
    {
        fprintf(fp, "%d\n", pergunta[i].id);
        fprintf(fp, "%s\n", pergunta[i].titulo);
    }

    fclose(fp);
}



