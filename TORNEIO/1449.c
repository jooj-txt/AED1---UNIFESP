
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Estrutura para armazenar uma palavra em japonês e sua tradução em português
struct palavra {
	char japones[500];
	char portugues[500];
};

// Declaração de funções
bool busca(struct palavra *, char *, int);
int compara(const void *a, const void *b);
int posicao;

int main () { // Correção: int main()
	int i;
	int numPalavras;
	int numLinhas, casos;
	char frase[500] = { 0 }, *palavraTmp;

	// Lê o número de casos de teste
	scanf("%d", &casos);

	while (casos--) {
		// Lê o número de palavras no dicionário e o número de linhas de entrada
		scanf("%d %d", &numPalavras, &numLinhas);

		// Cria um array para armazenar as palavras do dicionário
		struct palavra dicionario[numPalavras];

		// Lê as palavras em japonês e suas traduções em português para o dicionário
		for (i = 0; i < numPalavras; i++) {
			scanf(" %[^\n]", dicionario[i].japones);
			scanf(" %[^\n]", dicionario[i].portugues);
		}

		// Ordena o dicionário por palavras em japonês usando qsort
		qsort(dicionario, numPalavras, sizeof(struct palavra), compara);

		// Processa cada linha de entrada
		while (numLinhas--) {
			scanf(" %[^\n]", frase);

			// Se a linha estiver vazia, imprime uma quebra de linha
			if (!strlen(frase))
				printf("\n");
			else {
				// Separa a frase em palavras
				palavraTmp = strtok(frase, " ");

				// Busca a palavra no dicionário e imprime a tradução ou a própria palavra
				if (busca(dicionario, palavraTmp, numPalavras))
					printf("%s", dicionario[posicao].portugues);
				else
					printf("%s", palavraTmp);

				// Processa as palavras restantes na linha
				do {
					palavraTmp = strtok(NULL, " ");

					if (palavraTmp)
						printf(" ");

					if (palavraTmp)
						if (busca(dicionario, palavraTmp, numPalavras))
							printf("%s", dicionario[posicao].portugues);
						else
							printf("%s", palavraTmp);

				} while (palavraTmp);
			}

			// Imprime uma quebra de linha após processar a linha de entrada
			printf("\n");
			// Limpa o buffer da frase
			memset(frase, 0, sizeof(frase));
		}

		// Imprime uma quebra de linha após processar todos os casos
		printf("\n");
	}

	return 0; // Correção: retorno do status de término
}

// Função que implementa busca binária para procurar uma palavra no dicionário
bool busca(struct palavra *dicionario, char *palavra, int tam) {
	int inicio, fim, meio;
	inicio = 0;
	fim = tam - 1;

	while (inicio <= fim) {
		meio = (inicio + fim) / 2;
		if (strcmp(dicionario[meio].japones, palavra) < 0)
			inicio = meio + 1;
		else if (strcmp(dicionario[meio].japones, palavra) > 0)
			fim = meio - 1;
		else {
			posicao = meio;
			return true;
		}
	}

	return false;
}

// Função de comparação para o qsort do C
int compara(const void *a, const void *b) {
	if (strcmp((*(struct palavra*)a).japones, (*(struct palavra*)b).japones) == 0)
		return 0;
	else if ((strcmp((*(struct palavra*)a).japones, (*(struct palavra*)b).japones) > 0))
		return 1;
	else
		return -1;
}