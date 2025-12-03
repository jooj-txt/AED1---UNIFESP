#include <stdio.h>
#include <string.h>

int pilhaMinimos[1000000]; // Array para armazenar os mínimos

int main() {
    char comando[5];
    int numOperacoes, valor, minimoAtual, indice;

    indice = 0; // Índice da pilha
    scanf("%d", &numOperacoes);

    for (int i = 0; i < numOperacoes; ++i) {
        scanf("%s", comando);

        if (strcmp(comando, "PUSH") == 0) {
            scanf("%d", &valor);

            if (indice == 0) {
                minimoAtual = valor;
            } else {
                minimoAtual = (pilhaMinimos[indice - 1] < valor) ? pilhaMinimos[indice - 1] : valor;
            }

            pilhaMinimos[indice++] = minimoAtual;

        } else if (strcmp(comando, "POP") == 0) {
            if (indice == 0) {
                printf("EMPTY\n");
            } else {
                --indice;
            }

        } else if (strcmp(comando, "MIN") == 0) {
            if (indice == 0) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", pilhaMinimos[indice - 1]);
            }
        }
    }

    return 0;
}