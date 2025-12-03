#include <stdio.h>
#include <stdlib.h> // Necessário para malloc
#include <string.h>

void combinar(char *str1, char *str2, char *resultado) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0, j = 0, k = 0;
 
    // Intercala as letras das duas strings
    while (i < len1 && j < len2) {
        resultado[k++] = str1[i++];
        resultado[k++] = str2[j++];
    }

    // Adiciona os caracteres restantes da string mais longa
    while (i < len1) {
        resultado[k++] = str1[i++];
    }
    while (j < len2) {
        resultado[k++] = str2[j++];
    }

    resultado[k] = '\0'; // Finaliza a string com o caractere nulo
}

int main() {
    char str1[50];
    char str2[50];
    int n;
    
    scanf("%d", &n);
    getchar(); // Limpa o caractere de nova linha após o número de casos
    
    for (int i = 0; i < n; i++) {
        // Lê as duas strings
        scanf("%s %s", str1, str2);

        // Aloca memória para o buffer de resultado
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int tam = len1 + len2 + 1; // +1 para o caractere nulo
        char *cocantenado = (char *)malloc(tam * sizeof(char));

        if (cocantenado == NULL) {
            printf("Erro na alocação de memória\n");
            return 1; // Retorna com erro
        }

        // Combina as duas strings
        combinar(str1, str2, cocantenado);

        // Imprime o resultado
        printf("%s\n", cocantenado);

        // Libera a memória alocada
        free(cocantenado);
    }

    return 0;
}