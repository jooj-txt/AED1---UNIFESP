#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000010  // Máximo de nós na trie (soma dos caracteres)

typedef struct TrieNode {
    struct TrieNode* children[2];  // 0 para '(', 1 para ')'
    int is_end;                     // Marca o fim de uma string
} TrieNode;

TrieNode* create_node() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->children[0] = NULL;
    node->children[1] = NULL;
    node->is_end = 0;
    return node;
}

int insert_string(TrieNode* root, char* str) {
    TrieNode* current = root;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        int index = (str[i] == '(') ? 0 : 1;
        
        if (current->children[index] == NULL) {
            current->children[index] = create_node();
        }
        
        current = current->children[index];
    }
    
    // Se já existe uma string terminando aqui, retorna 0 (não é nova)
    if (current->is_end) {
        return 0;
    } else {
        current->is_end = 1;
        return 1;  // Nova string
    }
}

void free_trie(TrieNode* node) {
    if (node == NULL) return;
    free_trie(node->children[0]);
    free_trie(node->children[1]);
    free(node);
}

int main() {
    TrieNode* root = create_node();
    char buffer[MAX_NODES];
    int distinct_count = 0;
    
    // Lê strings até o final da entrada (EOF)
    while (scanf("%s", buffer) != EOF) {
        if (insert_string(root, buffer)) {
            distinct_count++;
        }
    }
    
    printf("%d\n", distinct_count);
    
    // Libera memória
    free_trie(root);
    
    return 0;
}