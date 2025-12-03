#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node *esq, *dir;
};

Node* novoNo(int valor) {
    Node* no = new Node;
    no->valor = valor;
    no->esq = no->dir = nullptr;
    return no;
}

// Inserção na árvore binária de busca
Node* inserir(Node* raiz, int valor) {
    if (raiz == nullptr)
        return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Percurso em ordem (in-order) para imprimir ordenado
void imprimirInOrdem(Node* raiz, bool &primeiro) {
    if (raiz == nullptr) return;
    imprimirInOrdem(raiz->esq, primeiro);
    if (!primeiro) cout << " ";
    cout << raiz->valor;
    primeiro = false;
    imprimirInOrdem(raiz->dir, primeiro);
}

// Libera memória
void liberarArvore(Node* raiz) {
    if (raiz == nullptr) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    delete raiz;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int NC; 
    cin >> NC;

    while (NC--) {
        int N;
        cin >> N;
        Node* raiz = nullptr;

        for (int i = 0; i < N; i++) {
            int h;
            cin >> h;
            raiz = inserir(raiz, h);
        }

        bool primeiro = true;
        imprimirInOrdem(raiz, primeiro);
        cout << "\n";

        liberarArvore(raiz);
    }

    return 0;
}
