#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Necessário para usar o sort

using namespace std;

int main() {
    // Otimização de Entrada/Saída para grandes volumes de dados
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    // Loop que roda enquanto houver entrada (EOF)
    while (cin >> N) {
        // Criamos um vetor de strings para guardar os telefones
        vector<string> telefones(N);

        // 1. Leitura
        for (int i = 0; i < N; i++) {
            cin >> telefones[i];
        }

        // 2. Ordenação
        // Isso coloca números parecidos um ao lado do outro
        sort(telefones.begin(), telefones.end());

        int economia = 0;

        // 3. Contagem da economia
        // Começamos do segundo número (i=1) e comparamos com o anterior (i-1)
        for (int i = 1; i < N; i++) {
            // Pegamos o tamanho do número (o problema diz que todos têm o mesmo tamanho)
            int tamanho = telefones[i].length();
            
            // Verificamos caractere por caractere
            for (int j = 0; j < tamanho; j++) {
                // Se o caractere atual for igual ao do número anterior na mesma posição
                if (telefones[i][j] == telefones[i-1][j]) {
                    economia++;
                } else {
                    // Se encontrou um diferente, o prefixo igual acabou. Para o loop interno.
                    break;
                }
            }
        }

        // Imprime o resultado total para este caso de teste
        cout << economia << "\n";
    }

    return 0;
}