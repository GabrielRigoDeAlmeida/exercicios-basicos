#include<stdio.h>
#include<string.h>

// Definindo a estrutura aluno e renomeando também
typedef struct aluno
{
	char nome[20];
	float media;
	int faltas;
} Aluno;


// Função que preenche um vetor de alunos
void preencheVetorReg(Aluno vetAlunos[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("Nome: ");
		scanf("%s", vetAlunos[i].nome);
		printf("Media: ");
		scanf("%f", &vetAlunos[i].media);
		printf("Faltas: ");
		scanf("%d", &vetAlunos[i].faltas);
	}
}

// Funcao que encontra o aluno com maior média e retorna o
// indice do aluno no vetor
int maiorMedia(Aluno vetAlunos[], int n)
{
	int i;
	int idxMaiorMedia = 0;
	float maiormedia = vetAlunos[0].media;
	
	// para cada aluno do vetor
	for(i = 1; i < n; i++)
	{
		// verifica se a média do aluno atual é maior do que a
		// maior media
		if(vetAlunos[i].media > maiormedia)
		{
			// atualiza o índice a maior média
			idxMaiorMedia = i;
			maiormedia = vetAlunos[i].media;
		}
	}

	// retorna o índice do aluno da maior media
	return idxMaiorMedia;
}

// Função que mostra os alunos reprovados por média
void reprovadosPorMedia(Aluno vetAlunos[], int n)
{
	int i;
	// para cada aluno do vetor
	for(i = 0; i < n; i++)
	{
		// se a media for menor do que 7
		if(vetAlunos[i].media < 7)
			printf("%s - REPROVADO por media\n", vetAlunos[i].nome);
	}
}

main()
{
	int n = 5;
	int idx;
	// Declarando um vetor de alunos de tamanho 'n'
	Aluno vetAlunos[n];

	// Preenchendo o vetor de alunos
	preencheVetorReg(vetAlunos, n);

	// Encontrando a maior média
	idx = maiorMedia(vetAlunos, n);
	// Imprime o aluno com a maior media e a média
	printf("Aluno: %s\tMedia: %.1f\n", vetAlunos[idx].nome, vetAlunos[idx].media);

	// chama a função que imprime os alunos reprovados por media	
	reprovadosPorMedia(vetAlunos, n);
}
