/*A clínica médica “Bem Estar” precisa urgentemente de um sistema de informação para gerenciar os pacientes que frequentam a clínica e as consultas que são agendadas. O sistema deve permitir que o próprio paciente faça o agendamento, alteração  e exclusão da sua consulta e que a secretária visualize todas as consultas agendadas.*/


#include<stdio.h>
#include<string.h>

                        /*criamos as estruturas paciente e consulta.*/

typedef struct Paciente
{
    char cpf[12];
    char nome[31];
    char tel[10];	
    int tcons;
}pac;
typedef struct Consulta
{
    char cst[12];

}con;
     //(Criamos a função zerar, que preenche todos os horários da agenda com '-' caso o conteúdo não seja 'O' ou 'x'. 
   void zerar (con consul[], char horario[])
   {
      int i;
    
      for(i=0;i<40;i++)
      { 
         if(horario[i] != 'O' && horario[i] != 'x') 
         {
            horario[i] = '-';
            strcpy(consul[i].cst,"0");
         }
      }
   
      
   }
   //Essa função é responsável por guardar o CPF do paciente atual que está logado e por separar os pacientes já cadastrados ou não.
   int login (pac paciente[],char cpfpac[])
   {
      int user,i;
             
      printf("                    BEM VINDO A CLINICA MÉDICA 'BEM ESTAR'\n");
      printf("\n\n  Informe sua opção de login:\n");
      printf(" 1-PACIENTE\n 2-ADMINISTRADOR\n 3-SAIR\n");
      scanf("%d",&user);
      if(user==1)
      {
         printf("Informe seu CPF:");
         scanf("%s",cpfpac); 
                           //Devolve ao main() o retorno 1 se o CPF for cadastrado.
         for(i=0;i<30;i++)
         {
            if(strcmp(paciente[i].cpf,cpfpac)==0)  
            {   
                return (1);
                break;
            } 
         }
                          //Devolve ao main() o retorno 2 se o CPF ainda não foi cadastrado.
            if(strcmp(paciente[i].cpf,cpfpac)!=0)
            {  
               printf("\nPACIENTE NÃO CADASTRADO, FAVOR SE CADASTRAR NO SISTEMA\n");
               return (2); 	
            }
              
      }
      //Se o usuario informar a opção 2 de administrador, aqui retornamos 3 ao main().                    
      else if(user==2)
         return 3;
       
   }
   //Se o CPF não foi cadastrado o main() quando recebe o retorno 2 de login chama essa função para cadastrar o paciente.
   int cadpac (pac paciente[],int *contador)
   {
      int i;  
      int n;
    
      while(*contador<30)
      {       
         printf("MENU DO PACIENTE - Cadastro do paciente\n");
         printf("CPF: ");
         scanf("%s",paciente[*contador].cpf); 
         printf("Nome: ");
         scanf("\n%[^\n]",paciente[*contador].nome);
         printf("Telefone ");
         scanf("%s",paciente[*contador].tel);
         printf("Tipo de consulta (1- Particular / 2- Convênio):"); 
         scanf("%d",&paciente[*contador].tcons);
         *contador=*contador+1;         
         break; 
      }
   }
   //Essa função permite ao usuário alterar do seu cadastro seu telefone e tipo de consulta.
   int alterarcadastro(pac paciente[],char cpfpac[])
   {
      int i;
      
      for(i=0;i<30;i++)
      {
         if(strcmp(paciente[i].cpf,cpfpac)==0)
            break; 
      }

      printf("MENU DO PACIENTE - ALTERAR DADOS CADASTRAIS\n");
      printf("CPF: %s\n ",paciente[i].cpf);
      printf("Nome: %s\n ",paciente[i].nome);
      printf("Telefone ");
      scanf("%s",paciente[i].tel);
      printf("Tipo de consulta (1- Particular / 2- Convênio):"); 
      scanf("%d",&paciente[i].tcons);

   }
 

   //Aqui é impresso a agenda.
   char agenda (con consul[],char cpfpac[], char horario[])
   {
      int i;
      //Realizamos condicionais que permitem diferenciar se a consulta é do paciente atual logado, 'O' ou de outro paciente 'x'.
      for(i=0;i<40;i++)
      {
         if(horario[i]=='O'&&(strcmp(consul[i].cst,cpfpac)!=0))   
            horario[i]='x';
      } 
      for(i=0;i<40;i++)
      {
         if(strcmp(consul[i].cst,cpfpac)==0)   
            horario[i]='O';
      }   
   

      printf("      SEG  :  TER  :  QUA  :  QUI  :  SEX  :\n");
      printf("8h    %c    :  %c    :  %c    :  %c    :  %c    :\n",horario[0],horario[8],horario[16],horario[24],horario[32]);
      printf("9h    %c    :  %c    :  %c    :  %c    :  %c    :\n",horario[1],horario[9],horario[17],horario[25],horario[33]);
      printf("10h   %c    :  %c    :  %c    :  %c    :  %c    :\n",horario[2],horario[10],horario[18],horario[26],horario[34]);
      printf("11h   %c    :  %c    :  %c    :  %c    :  %c    :\n",horario[3],horario[11],horario[19],horario[27],horario[35]); 
      printf("13h   %c    :  %c    :  %c    :  %c    :  %c    :\n",horario[4],horario[12],horario[20],horario[28],horario[36]);
      printf("14h   %c    :  %c    :  %c    :  %c    :  %c    :\n",horario[5],horario[13],horario[21],horario[29],horario[37]);
      printf("15h   %c    :  %c    :  %c    :  %c    :  %c    :\n",horario[6],horario[14],horario[22],horario[30],horario[38]);
      printf("16h   %c    :  %c    :  %c    :  %c    :  %c    :\n",horario[7],horario[15],horario[23],horario[31],horario[39]);
     
   }    

   int menupac (pac paciente[],char cpfpac[], char horario[],con consul[])
   {
      int opcao=0;
      int i;

       while(opcao != 5)  
      {
            /*MENU DO PACIENTE, DAQUI ELE CHAMA TODAS AS FUNÇÕES DE SEU MENU DE OPÇÕES ABAIXO.*/

         printf("\n      MENU PACIENTE\n");
         printf("  (1). AGENDAR UMA CONSULTA\n");
         printf("  (2). EXIBIR MINHAS CONSULTAS AGENDADAS\n");
         printf("  (3). ALTERAR DADOS CADASTRAIS\n");
         printf("  (4). VOLTAR AO MENU PRINCIPAL\n");
         printf("  (5). SAIR\n");
         printf("\n\n  Digite sua opção:"); 
         scanf("%d",&opcao);
      
       
         switch(opcao)
         {
       
            case 1:
               agenda(consul,cpfpac,horario);
               agendar(consul,cpfpac,horario);
            break;
            case 2:
               agenda(consul,cpfpac,horario); 
               exibirconsultas(consul,cpfpac,horario,paciente);
            break;
            case 3:
               alterarcadastro(paciente,cpfpac);
            break;
            case 4:
               main();
               opcao=5;
            break;  
         }
         
   
      }
   }  
   /*Aqui o paciente pode agendar o DIA e horário de sua consulta, caso o DIA e horário esteja vago com '-', além de marcar na agenda,
    também guarda o cpf que possibilita saber quem agendou a consulta.*/
   int agendar (con consul[],char cpfpac[], char horario[])
   {
      char diacon[4];
      int horcon;
     
      printf("\nNovo Dia:"); 
      scanf("%s", diacon);
      printf("Novo Horário:");
      scanf("%d",&horcon);
     
      if(strcmp(diacon,"SEG")==0)
      {
         switch(horcon)
         {
        
            case 8:
               if(horario[0]=='-'){
                  strcpy(consul[0].cst,cpfpac);
                  horario[0]='O';
               } 
               else if(horario[0]=='x')   
                  printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            break;
            case 9:
               if(horario[1]=='-'){
                  strcpy(consul[1].cst,cpfpac);
                  horario[1]='O';
               }  
               else if(horario[1]=='x')   
                  printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            break;
            case 10:
               if(horario[2]=='-'){
                  strcpy(consul[2].cst,cpfpac);
                  horario[2]='O';
               } 
               else if(horario[2]=='x')   
                  printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            break;
            case 11:
               if(horario[3]=='-'){
                  strcpy(consul[3].cst,cpfpac);
                  horario[3]='O';
               } 
               else if(horario[3]=='x')   
               printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            break;
            case 13:
               if(horario[4]=='-'){
                  strcpy(consul[4].cst,cpfpac);
                  horario[4]='O';
               } 
               else if(horario[4]=='x')   
                  printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            break;
            case 14:
               if(horario[5]=='-'){
                  strcpy(consul[5].cst,cpfpac);
                  horario[5]='O';
               } 
               else if(horario[5]=='x')   
                  printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            break;
            case 15:
               if(horario[6]=='-'){
                  strcpy(consul[6].cst,cpfpac);
                  horario[6]='O';
               } 
               else if(horario[6]=='x')   
                  printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            break;
            case 16:
               if(horario[7]=='-'){
                  strcpy(consul[7].cst,cpfpac);
                  horario[7]='O';
               } 
               else if(horario[7]=='x')   
                  printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            break;        
         }                          
      }   
         if(strcmp(diacon,"TER")==0)
         {
            switch(horcon)
            {        
               case 8:
                  if(horario[8]=='-'){
                     strcpy(consul[8].cst,cpfpac);
                     horario[8]='O';
                  } 
                  else if(horario[8]=='x')   
                     printf("Horário de agendado a outro paciente favor escolher um horário disponível");
               break;
               case 9:
                  if(horario[9]=='-'){
                     strcpy(consul[9].cst,cpfpac);
                     horario[9]='O';
                  }  
                  else if(horario[9]=='x')   
                     printf("Horário de agendado a outro paciente favor escolher um horário disponível");
               break;
               case 10:
                  if(horario[10]=='-'){
                     strcpy(consul[10].cst,cpfpac);
                     horario[10]='O';
                  } 
                  else if(horario[10]=='x')   
                     printf("Horário de agendado a outro paciente favor escolher um horário disponível");
               break;
               case 11:
                  if(horario[11]=='-'){
                     strcpy(consul[11].cst,cpfpac);
                     horario[11]='O';
                  } 
                  else if(horario[11]=='x')   
                     printf("Horário de agendado a outro paciente favor escolher um horário disponível");
               break;
               case 13:
                  if(horario[12]=='-'){
                     strcpy(consul[12].cst,cpfpac);
                     horario[12]='O';
                  } 
                  else if(horario[12]=='x')   
                     printf("Horário de agendado a outro paciente favor escolher um horário disponível");
               break;
               case 14:
                  if(horario[13]=='-'){
                     strcpy(consul[13].cst,cpfpac);
                     horario[13]='O';
                  } 
                  else if(horario[13]=='x')   
                     printf("Horário de agendado a outro paciente favor escolher um horário disponível");
               break;
               case 15:
                  if(horario[14]=='-'){
                     strcpy(consul[14].cst,cpfpac);
                     horario[14]='O';
                  } 
                  else if(horario[14]=='x')   
                     printf("Horário de agendado a outro paciente favor escolher um horário disponível");
               break;
               case 16:
                  if(horario[15]=='-'){
                     strcpy(consul[15].cst,cpfpac);
                     horario[15]='O';
                  } 
                  else if(horario[15]=='x')   
                     printf("Horário de agendado a outro paciente favor escolher um horário disponível");
               break;        
            }                               
         }  
 
            if(strcmp(diacon,"QUA")==0)
            {
               switch(horcon)
               {        
                  case 8:
                     if(horario[16]=='-'){
                        strcpy(consul[16].cst,cpfpac);
                        horario[16]='O';
                     } 
                     else if(horario[16]=='x')   
                        printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                  break;
                  case 9:
                     if(horario[17]=='-'){
                        strcpy(consul[17].cst,cpfpac);
                        horario[17]='O';
                     }  
                     else if(horario[17]=='x')   
                        printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                  break;
                  case 10:
                     if(horario[18]=='-'){
                        strcpy(consul[18].cst,cpfpac);
                        horario[18]='O';
                     } 
                     else if(horario[18]=='x')   
                        printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                  break;
                  case 11:
                     if(horario[19]=='-'){
                        strcpy(consul[19].cst,cpfpac);
                        horario[19]='O';
                     } 
                     else if(horario[19]=='x')   
                        printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                  break;
                  case 13:
                     if(horario[20]=='-'){
                        strcpy(consul[20].cst,cpfpac);
                        horario[20]='O';
                     }   
                     else if(horario[20]=='x')   
                        printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                  break;
                  case 14:
                     if(horario[21]=='-'){
                        strcpy(consul[21].cst,cpfpac);
                        horario[21]='O';
                     } 
                     else if(horario[21]=='x')   
                        printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                  break;
                  case 15:
                     if(horario[22]=='-'){
                        strcpy(consul[22].cst,cpfpac);
                        horario[22]='O';
                     } 
                     else if(horario[22]=='x')   
                        printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                  break;
                  case 16:
                     if(horario[23]=='-'){
                        strcpy(consul[23].cst,cpfpac);
                        horario[23]='O';
                     } 
                     else if(horario[23]=='x')   
                        printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                  break;        
               }                               
            }   
               if(strcmp(diacon,"QUI")==0)
               {
                  switch(horcon)
                  {        
                     case 8:
                        if(horario[24]=='-'){
                           strcpy(consul[24].cst,cpfpac);
                           horario[24]='O';
                        } 
                        else if(horario[24]=='x')   
                           printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                     break;
                     case 9:
                        if(horario[25]=='-'){
                           strcpy(consul[25].cst,cpfpac);
                           horario[25]='O';
                        }  
                        else if(horario[25]=='x')   
                           printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                     break;
                     case 10:
                        if(horario[26]=='-'){
                           strcpy(consul[26].cst,cpfpac);
                           horario[26]='O';
                        } 
                        else if(horario[26]=='x')   
                           printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                     break;
                     case 11:
                        if(horario[27]=='-'){
                           strcpy(consul[27].cst,cpfpac);
                           horario[27]='O';
                        } 
                        else if(horario[27]=='x')   
                           printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                     break;
                     case 13:
                        if(horario[28]=='-'){
                           strcpy(consul[28].cst,cpfpac);
                           horario[28]='O';
                        }  
                        else if(horario[28]=='x')   
                           printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                     break;
                     case 14:
                        if(horario[29]=='-'){
                           strcpy(consul[29].cst,cpfpac);
                           horario[29]='O';
                        } 
                        else if(horario[29]=='x')   
                           printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                     break;
                     case 15:
                        if(horario[30]=='-'){
                           strcpy(consul[30].cst,cpfpac);
                           horario[30]='O';
                        } 
                        else if(horario[30]=='x')   
                           printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                     break;
                     case 16:
                        if(horario[31]=='-'){
                           strcpy(consul[31].cst,cpfpac);
                           horario[31]='O';
                        } 
                        else if(horario[31]=='x')   
                           printf("Horário de agendado a outro paciente favor escolher um horário disponível");
                     break;        
                  }                          
               }   
                  if(strcmp(diacon,"SEX")==0)
                  {
                     switch(horcon)
                     {        
                        case 8:
                           if(horario[32]=='-'){
                              strcpy(consul[32].cst,cpfpac);
                              horario[32]='O';
                           } 
               		   else if(horario[32]=='x')   
                  	      printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            		break;
            		case 9:
               		   if(horario[33]=='-'){
                  	      strcpy(consul[33].cst,cpfpac);
                  	      horario[33]='O';
               		   }  
               		   else if(horario[33]=='x')   
                              printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            		break;
            		case 10:
               		   if(horario[34]=='-'){
                  	      strcpy(consul[34].cst,cpfpac);
                  	      horario[34]='O';
               		   } 
               		   else if(horario[34]=='x')   
                  	      printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            		break;
            		case 11:
               		   if(horario[35]=='-'){
                  	      strcpy(consul[35].cst,cpfpac);
                  	      horario[35]='O';
               		   } 
               		   else if(horario[35]=='x')   
               		      printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            		break;
            		case 13:
               		   if(horario[36]=='-'){
                  	      strcpy(consul[36].cst,cpfpac);
                  	      horario[36]='O';
               		   } 
               		   else if(horario[36]=='x')   
                  	      printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            		break;
            		case 14:
               		   if(horario[37]=='-'){
                  	      strcpy(consul[37].cst,cpfpac);
                  	      horario[37]='O';
               		   } 
               		   else if(horario[37]=='x')   
                   	      printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            		break;
            		case 15:
               		   if(horario[38]=='-'){
                  	      strcpy(consul[38].cst,cpfpac);
                  	      horario[38]='O';
               		   } 
               		   else if(horario[38]=='x')   
                              printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            		break;
            		case 16:
               		   if(horario[39]=='-'){
                  	      strcpy(consul[39].cst,cpfpac);
                  	      horario[39]='O';
               		   } 
               		   else if(horario[39]=='x')   
                  	      printf("Horário de agendado a outro paciente favor escolher um horário disponível");
            		break;        
                     }                                
                  }   
   }
 //Essa função funciona como um segundo menu onde chama as funções de exclusão e alteração de agendamento, além de mostrar à agenda.
   int exibirconsultas (con consul[],char cpfpac[], char horario[],pac paciente[])
   { 
      int i,opcao;  

      printf("\n 1 - Alterar um agendamento\n");
      printf(" 2 - Excluir um agendamento\n");
      printf(" 3 - Voltar ao menu paciente\n");
      printf(" Escolha a opção:");
      scanf("%d",&opcao);
 
      if(opcao==1){
         excluir(consul,cpfpac,horario);
         agendar(consul,cpfpac,horario);
      }  
         else if(opcao==2){
            excluir(consul,cpfpac,horario);
         }
            else if(opcao==3){
            } 
      
      return 0;
   }
   //Permite ao usuário excluir uma consulta que esteja marcada por ele com 'O', exclui também o cpf reservado a essa consulta.
   int excluir (con consul[],char cpfpac[], char horario[]) 
   {
      char diacon[4];
      int horcon;

      printf("\nDia:"); 
      scanf("%s", diacon);
      printf("Horário:");
      scanf("%d",&horcon);
     
      if(strcmp(diacon,"SEG")==0)
      {
         switch(horcon)
         {
        
            case 8:
               if(horario[0]=='O'){
                  strcpy(consul[0].cst,"0");
                  horario[0]='-';
               } 
               else if(horario[0]=='x')   
                  printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            break;
            case 9:
               if(horario[1]=='O'){
                  printf("Hey entrei aqui ;)");
                  strcpy(consul[1].cst,"0");
                  horario[1]='-';
               }  
               else if(horario[1]=='x')   
                  printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            break;
            case 10:
               if(horario[2]=='O'){
                  strcpy(consul[2].cst,"0");
                  horario[2]='-';
               } 
               else if(horario[2]=='x')   
                  printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            break;
            case 11:
               if(horario[3]=='O'){
                  strcpy(consul[3].cst,"0");
                  horario[3]='-';
               } 
               else if(horario[3]=='x')   
               printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            break;
            case 13:
               if(horario[4]=='O'){
                  strcpy(consul[4].cst,"0");
                  horario[4]='-';
               } 
               else if(horario[4]=='x')   
                  printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            break;
            case 14:
               if(horario[5]=='O'){
                  strcpy(consul[5].cst,"0");
                  horario[5]='-';
               } 
               else if(horario[5]=='x')   
                  printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            break;
            case 15:
               if(horario[6]=='O'){
                  strcpy(consul[6].cst,"0");
                  horario[6]='-';
               } 
               else if(horario[6]=='x')   
                  printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            break;
            case 16:
               if(horario[7]=='O'){
                  strcpy(consul[7].cst,"0");
                  horario[7]='-';
               } 
               else if(horario[7]=='x')   
                  printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            break;        
         }                          
      }   
         if(strcmp(diacon,"TER")==0)
         {
            switch(horcon)
            {        
               case 8:
                  if(horario[8]=='O'){
                     strcpy(consul[8].cst,"0");
                     horario[8]='-';
                  } 
                  else if(horario[8]=='x')   
                     printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
               break;
               case 9:
                  if(horario[9]=='O'){
                     strcpy(consul[9].cst,"0");
                     horario[9]='-';
                  }  
                  else if(horario[9]=='x')   
                     printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
               break;
               case 10:
                  if(horario[10]=='O'){
                     strcpy(consul[10].cst,"0");
                     horario[10]='-';
                  } 
                  else if(horario[10]=='x')   
                     printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
               break;
               case 11:
                  if(horario[11]=='O'){
                     strcpy(consul[11].cst,"0");
                     horario[11]='-';
                  } 
                  else if(horario[11]=='x')   
                     printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
               break;
               case 13:
                  if(horario[12]=='O'){
                     strcpy(consul[12].cst,"0");
                     horario[12]='-';
                  } 
                  else if(horario[12]=='x')   
                     printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
               break;
               case 14:
                  if(horario[13]=='O'){
                     strcpy(consul[13].cst,"0");
                     horario[13]='-';
                  } 
                  else if(horario[13]=='x')   
                     printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
               break;
               case 15:
                  if(horario[14]=='O'){
                     strcpy(consul[14].cst,"0");
                     horario[14]='-';
                  }
                  else if(horario[14]=='x')   
                     printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
               break;
               case 16:
                  if(horario[15]=='O'){
                     strcpy(consul[15].cst,"0");
                     horario[15]='-';
                  } 
                  else if(horario[15]=='x')   
                     printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
               break;        
            }                               
         }  
 
            if(strcmp(diacon,"QUA")==0)
            {
               switch(horcon)
               {        
                  case 8:
                     if(horario[16]=='O'){
                        strcpy(consul[16].cst,"0");
                        horario[16]='-';
                     } 
                     else if(horario[16]=='x')   
                        printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                  break;
                  case 9:
                     if(horario[17]=='O'){
                        strcpy(consul[17].cst,"0");
                        horario[17]='-';
                     }  
                     else if(horario[17]=='x')   
                        printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                  break;
                  case 10:
                     if(horario[18]=='O'){
                        strcpy(consul[18].cst,"0");
                        horario[18]='-';
                     } 
                     else if(horario[18]=='x')   
                        printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                  break;
                  case 11:
                     if(horario[19]=='O'){
                        strcpy(consul[19].cst,"0");
                        horario[19]='-';
                     } 
                     else if(horario[19]=='x')   
                        printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                  break;
                  case 13:
                     if(horario[20]=='O'){
                        strcpy(consul[20].cst,"0");
                        horario[20]='-';
                     }   
                     else if(horario[20]=='x')   
                        printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                  break;
                  case 14:
                     if(horario[21]=='O'){
                        strcpy(consul[21].cst,"0");
                        horario[21]='-';
                     } 
                     else if(horario[21]=='x')   
                        printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                  break;
                  case 15:
                     if(horario[22]=='O'){
                        strcpy(consul[22].cst,"0");
                        horario[22]='-';
                     } 
                     else if(horario[22]=='x')   
                        printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                  break;
                  case 16:
                     if(horario[23]=='O'){
                        strcpy(consul[23].cst,"0");
                        horario[23]='-';
                     }
                     else if(horario[23]=='x')   
                        printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                  break;        
               }                               
            }   
               if(strcmp(diacon,"QUI")==0)
               {
                  switch(horcon)
                  {        
                     case 8:
                        if(horario[24]=='O'){
                           strcpy(consul[24].cst,"0");
                           horario[24]='-';
                        } 
                        else if(horario[24]=='x')   
                           printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                     break;
                     case 9:
                        if(horario[25]=='O'){
                           strcpy(consul[25].cst,"0");
                           horario[25]='-';
                        } 
                        else if(horario[25]=='x')   
                           printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                     break;
                     case 10:
                        if(horario[26]=='O'){
                           strcpy(consul[26].cst,"0");
                           horario[26]='-';
                        } 
                        else if(horario[26]=='x')   
                           printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                     break;
                     case 11:
                        if(horario[27]=='O'){
                           strcpy(consul[27].cst,"0");
                           horario[27]='-';
                        } 
                        else if(horario[27]=='x')   
                           printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                     break;
                     case 13:
                        if(horario[28]=='O'){
                           strcpy(consul[28].cst,"0");
                           horario[28]='-';
                        }  
                        else if(horario[28]=='x')   
                           printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                     break;
                     case 14:
                        if(horario[29]=='O'){
                           strcpy(consul[29].cst,"0");
                           horario[29]='-';
                        } 
                        else if(horario[29]=='x')   
                           printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                     break;
                     case 15:
                        if(horario[30]=='O'){
                           strcpy(consul[30].cst,"0");
                           horario[30]='-';
                        } 
                        else if(horario[30]=='x')   
                           printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                     break;
                     case 16:
                        if(horario[31]=='O'){
                           strcpy(consul[31].cst,"0");
                           horario[31]='-';
                        }
                        else if(horario[31]=='x')   
                           printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
                     break;        
                  }                          
               }   
                  if(strcmp(diacon,"SEX")==0)
                  {
                     switch(horcon)
                     {        
                        case 8:
                           if(horario[32]=='O'){
                              strcpy(consul[32].cst,"0");
                              horario[32]='-';
                           } 
               		   else if(horario[32]=='x')   
                  	      printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            		break;
            		case 9:
               		   if(horario[33]=='O'){
                              strcpy(consul[33].cst,"0");
                              horario[33]='-';
                           }  
               		   else if(horario[33]=='x')   
                              printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            		break;
            		case 10:
               		   if(horario[34]=='O'){
                              strcpy(consul[34].cst,"0");
                              horario[34]='-';
                           }       
               		   else if(horario[34]=='x')   
                  	      printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            		break;
            		case 11:
               		   if(horario[35]=='O'){
                              strcpy(consul[35].cst,"0");
                              horario[35]='-';
                           } 
               		   else if(horario[35]=='x')   
               		      printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            		break;
            		case 13:
               		   if(horario[36]=='O'){
                              strcpy(consul[36].cst,"0");
                              horario[36]='-';
                           } 
               		   else if(horario[36]=='x')   
                  	      printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            		break;
            		case 14:
               		   if(horario[37]=='O'){
                              strcpy(consul[37].cst,"0");
                              horario[37]='-';
                           } 
               		   else if(horario[37]=='x')   
                   	      printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            		break;
            		case 15:
               		   if(horario[38]=='O'){
                              strcpy(consul[38].cst,"0");
                              horario[38]='-';
                           } 
               		   else if(horario[38]=='x')   
                              printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            		break;
            		case 16:
               		   if(horario[39]=='O'){
                              strcpy(consul[39].cst,"0");
                              horario[39]='-';
                           }
               		   else if(horario[39]=='x')   
                  	      printf("HORÁRIO MARCADO POR OUTRO PACIENTE, CONFIRME SUA OPÇÃO E RETORNE A ESSA OPERAÇÃO.");
            		break;        
                     }                                
                  }  
   }              

main()
{
   FILE *f;
   FILE *fp;
   char cpfpac[12];
   char resposta[4];
   char horario[40];
   int escolha,contador,i,b,e,cadastro;
   pac paciente[30];
   con consul[40];
   escolha=contador=b=e=0;
    
                      //Tenta abrir o arquivo clinica.txt. Se não conseguir, ou se o arquivo não existe fp fica com o valor NULL.
    if((fp = fopen("clinica.txt", "r+")) != NULL)
    {
                    //Enquanto não atingiu o final do arquivo. 
       while(!feof(fp))
       {
                     //Leia do arquivo o conteudo da estrutura Paciente.  
          fscanf(fp, "%s", paciente[b].cpf);
          fscanf(fp, "\n%[^\n]\n",paciente[b].nome);
          fscanf(fp, "%s", paciente[b].tel);
          fscanf(fp, "%d", &paciente[b].tcons);
          fscanf(fp, "%d", &contador);
          b++;
       }
    }
                  //Tenta abrir o arquivo consultas.txt. Se não conseguir, ou se o arquivo não existe fp fica com o valor NULL.
    if((f = fopen("consultas.txt", "r+")) != NULL)
    {
                      //Enquanto não atingiu o final do arquivo. 
       while(!feof(f))
       {
                     //Leia do arquivo o conteudo da estrutura Paciente.                   
          fscanf(f, "%s", consul[e].cst);
          fscanf(f, "%s", &horario[e]);
          e++;
       }
    }

   zerar(consul,horario);
   
   escolha=login(paciente,cpfpac);
   //Tratamos os retornos fornecidos pela função login.
   if(escolha==1){
      menupac(paciente,cpfpac,horario,consul);
   }
   else if(escolha==2){
      cadpac(paciente,&contador);
      menupac(paciente,cpfpac,horario,consul); 
   }
   else if(escolha==3){
      printf("                      ~ADMINISTRADOR~                      \n");
      printf("               CONFIRA A AGENDA DE CONSULTAS               \n");
      agenda(consul,cpfpac,horario);
   }
                                    //Na saída do programa criamos 2 arquivos .txt.
   fp = fopen("clinica.txt", "w");
                                   // Este escreve todo os dados do paciente no arquivo.
   for(i=0; i<contador; i++)
   {
      fprintf(fp, "%s\n", paciente[i].cpf);
      fprintf(fp, "%s\n", paciente[i].nome);
      fprintf(fp, "%s\n", paciente[i].tel);
      fprintf(fp, "%d\n", paciente[i].tcons);
      fprintf(fp, "%d\n",contador);
   }

   fclose(fp);

   f = fopen("consultas.txt", "w");
                                   // E este escreve todos os dados da agenda de consultas dos pacientes no arquivo.
    for(i=0;i<40;i++)
      { 
           fprintf(f, "%s\n",consul[i].cst);
           fprintf(f, "%c\n",horario[i]);        
      }


    fclose(f);
        
}
