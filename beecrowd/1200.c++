#include <iostream>
#include <string>
using namespace std;

struct Node {
    char valor;
    Node *esq, *dir;
};

// Cria novo nó
Node* novoNo(char valor) {
    Node* no = new Node;
    no->valor = valor;
    no->esq = no->dir = nullptr;
    return no;
}

// Insere um valor na ABP
Node* inserir(Node* raiz, char valor) {
    if (raiz == nullptr)
        return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Busca um valor na ABP
bool buscar(Node* raiz, char valor) {
    if (raiz == nullptr) return false;
    if (raiz->valor == valor) return true;
    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    else
        return buscar(raiz->dir, valor);
}

// Percursos
void imprimirInfixa(Node* raiz, bool &primeiro) {
    if (raiz == nullptr) return;
    imprimirInfixa(raiz->esq, primeiro);
    if (!primeiro) cout << " ";
    cout << raiz->valor;
    primeiro = false;
    imprimirInfixa(raiz->dir, primeiro);
}

void imprimirPrefixa(Node* raiz, bool &primeiro) {
    if (raiz == nullptr) return;
    if (!primeiro) cout << " ";
    cout << raiz->valor;
    primeiro = false;
    imprimirPrefixa(raiz->esq, primeiro);
    imprimirPrefixa(raiz->dir, primeiro);
}

void imprimirPosfixa(Node* raiz, bool &primeiro) {
    if (raiz == nullptr) return;
    imprimirPosfixa(raiz->esq, primeiro);
    imprimirPosfixa(raiz->dir, primeiro);
    if (!primeiro) cout << " ";
    cout << raiz->valor;
    primeiro = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* raiz = nullptr;
    string comando;

    while (cin >> comando) {
        if (comando == "I") {
            char c;
            cin >> c;
            raiz = inserir(raiz, c);
        }
        else if (comando == "P") {
            char c;
            cin >> c;
            if (buscar(raiz, c))
                cout << c << " existe\n";
            else
                cout << c << " nao existe\n";
        }
        else if (comando == "INFIXA") {
            bool primeiro = true;
            imprimirInfixa(raiz, primeiro);
            cout << "\n";
        }
        else if (comando == "PREFIXA") {
            bool primeiro = true;
            imprimirPrefixa(raiz, primeiro);
            cout << "\n";
        }
        else if (comando == "POSFIXA") {
            bool primeiro = true;
            imprimirPosfixa(raiz, primeiro);
            cout << "\n";
        }
    }

    return 0;
}
