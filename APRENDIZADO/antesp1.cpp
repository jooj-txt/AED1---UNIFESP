#include <iostream>
using namespace std;

void imprimirVetor(int *v, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        cout << *(v + i) << endl;
    }

    cout << "\n"
         << endl;
}

void imprimirVetorLetras(char *v, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        cout << *(v + i) << endl;
    }

    cout << "\n"
         << endl;
}

void preencherVetorInt(int *v, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        cout << "Digite um valor qualquer:" << endl;
        cin >> *(v + i);
    }

    cout << "\n"
         << endl;
}

typedef struct no
{
    int valor;
    struct no *proximo;
} no;

typedef struct
{
    no *inicio;
    int tam;
} Lista;

void inserirInicio(Lista *lista, int valor)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
}

void inserirFim(Lista *lista, int valor){
    no *mo, *novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
    else{
        mo = lista->inicio;
        while (mo->proximo != NULL)
        {
            mo = mo->proximo;
        } 
            mo->proximo = novo;

    }
    lista->tam++;

}

void imprimir(Lista *lista)
{
    no *inicio = lista->inicio;
    cout<< "Tamanho lista:" << lista->tam << endl;


    while (inicio != NULL)
    {
        cout << inicio->valor << endl;
        inicio = inicio->proximo;
    }

    cout << "\n\n"
         << endl;
}

int main()
{

    // lista encadeada

    Lista lista;
    int opcao, valor;
    lista.inicio = NULL;
    lista.tam = 0;

    do
    {
        cout << "1 - inserir no inicio\n2 - imprimir\n3 - inerir no fim\n5 - sair\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        cout<< "Digite um valor a ser inserido:"<< endl;
            cin >> valor;
            inserirInicio(&lista, valor);
            break;

        case 2:
            imprimir(&lista);
            break;

        case 3:
             cout<< "Digite um valor a ser inserido:"<< endl;
             cin >> valor;
             inserirFim(&lista, valor);
            break;

        case 5:
            cout << "Finalizando...\n"
                 << endl;
        default:
            cout << "opção invalida" << endl;
        }
    } while (opcao != 5);



    // ponteiros basicos
    /* int *valor1, valor2 = 50;
     char *letra1, letra2 = 'q';

     valor1 = &valor2;
     letra1 = &letra2;

     cout << "valor valor2:"  << "\n" << valor2 << endl;
     cout << "end valor2:"  << "\n" << &valor2 << endl;
     cout << "conteudo valor1:"  << "\n" << valor1 << endl;
     cout << "conteudo apontado valor1:"  << "\n" << *valor1 << endl;

 */

    // vetor e ponteiros

    /* int i, vet[10] = {0,1,2,3,4,5,6,7,8,9};
    char letras[10] = {'a','b','c','d','e','f','g','h','i','j'}; */

    /* cout << vet << endl;
     cout << &vet[0] << endl;*/
    // Aprimeira posicap de um vetor é um end,
    //  ele contem o end de memória onde ele começa

    /* for(i = 0; i < 10; i++){
        cout << *(vet + i) << endl;
    } */

    /* preencherVetorInt(vet,10);

      imprimirVetor(vet,10);

      imprimirVetorLetras(letras,10);  */

    return 0;
}
