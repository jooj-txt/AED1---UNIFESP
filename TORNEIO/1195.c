#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node *createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left,data);
    } else if(data > root->data){
        root->right = insert(root->right,data);
    }
    return root;
}

void printPreOrder(Node* root){
    if(root != NULL){
        printf(" %d", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printInOrder(Node* root){
    if(root != NULL){
        printInOrder(root->left);
        printf(" %d",root->data);
        printInOrder(root->right);
    }
}

void printPostOrder(Node* root){
    if(root != NULL){
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf(" %d",root->data);
    }
}

void freeTree(Node* root){
    if(root == NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    int C,N;
    int caso = 1;

    scanf("%d", &C);

    while (C > 0){
        scanf("%d", &N);

        Node* root = NULL;
        int valor;

        for(int i = 0; i < N; i++){
            scanf("%d", &valor);
            root = insert(root, valor);
        }

        printf("Case %d:\n", caso++);

        printf("Pre.:");
        printPreOrder(root);
        printf("\n");

        printf("In..:");
        printInOrder(root);
        printf("\n");

        printf("Post:");
        printPostOrder(root);
        printf("\n\n");

        freeTree(root);
        C--;
    }

    return 0;
}