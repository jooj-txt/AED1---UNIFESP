#include <stdio.h>
#include <ctype.h>

#define ALFABETO 26  // Número de letras no alfabeto inglês

// Função para contar a frequência de cada letra
void contar_frequencias(const char *texto, int frequencias[ALFABETO]) {
    // Percorre cada caractere do texto
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);  // Converte para minúscula
        // Verifica se o caractere é uma letra
        if (c >= 'a' && c <= 'z') {
            frequencias[c - 'a']++;  // Atualiza a contagem da letra
        }
    }
}

// Função para imprimir as letras com a maior frequência
void imprimir_maiores_frequencias(const int frequencias[ALFABETO]) {
    int max_frequencia = 0;
    
    // Encontra a maior frequência
    for (int i = 0; i < ALFABETO; i++) {
        if (frequencias[i] > max_frequencia) {
            max_frequencia = frequencias[i];
        }
    }

    // Imprime as letras com a maior frequência
    for (int i = 0; i < ALFABETO; i++) {
        if (frequencias[i] == max_frequencia) {
            printf("%c", 'a' + i);
        }
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d\n", &N);  // Ler o número de casos de teste

    for (int i = 0; i < N; i++) {
        char texto[201];  // Buffer para armazenar a linha de texto
        int frequencias[ALFABETO] = {0};  // Inicializa o array de frequências

        // Ler a linha de texto
        fgets(texto, sizeof(texto), stdin);

        // Contar a frequência das letras
        contar_frequencias(texto, frequencias);

        // Imprimir as letras com a maior frequência
        imprimir_maiores_frequencias(frequencias);
    }

    return 0;
}