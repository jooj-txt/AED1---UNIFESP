#include <stdio.h>

int main() {
    int v, t;

    // O loop continua enquanto scanf conseguir ler 2 valores inteiros.
    // Quando o arquivo acaba, scanf retorna EOF (-1) e o loop para.
    while (scanf("%d %d", &v, &t) != EOF) {
        
        // A fórmula derivada: 2 * velocidade * tempo
        int deslocamento = 2 * v * t;
        
        printf("%d\n", deslocamento);
    }

    return 0;
}