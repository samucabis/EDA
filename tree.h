#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <string>
#include <iostream>

using namespace std;

template <typename Tchave>
class tree
{
private:
    
    node<Tchave> *raiz;

public:

    tree();
    ~tree();
    int altura();
    //int numeroFolhas();
    //void pre_ordem();
   // void em_ordem();
    //void pos_ordem();
    void inserir(Tchave chave, pessoa *p);
    //void remover(Tchave chave);
    //void remover_tudo();
    node<Tchave>* min();
    node<Tchave>* max();
    void pesquisar(Tchave chave);

};

//iniciando a arvore como vazia
template <typename Tchave>
tree<Tchave>::tree() {
    cout << "Criando..."              << endl;
    cout << "Aperte enter para prosseguir..." << endl;
    getchar();
    system("clear");
    raiz = nullptr;
}
//destruindo a arvore
template <typename Tchave>
tree<Tchave>::~tree() {
    cout << "Deletando..." << endl;
    if(raiz != nullptr) {
        raiz->desalocarMemoria();
    }
    cout <<"Aperte tecla para prosseguir..." << endl;
    getchar();
    getchar();
    system("clear");
}
//retorna a altura da arvore
template <typename Tchave>
int tree<Tchave>::altura() {
    if(raiz == nullptr) {
        return 0;
    }
    return raiz->getAltura();
}
//retorna valor minimo da arvore
template <typename Tchave>
node<Tchave>* tree<Tchave>::min() {
    if(raiz == nullptr) {
        return nullptr;
    }
    return raiz->min();
}
//retorna valor max da arvore
template <typename Tchave>
node<Tchave>* tree<Tchave>::max() {
    if(raiz == nullptr) {
        return nullptr;
    }
    return raiz->max();
}
//função inserir na arvore
template <typename Tchave>
void tree<Tchave>::inserir(Tchave chave, pessoa *p) {
    //cout << raiz->getChave() << endl;
    if(raiz == nullptr) {
        //cria novo nó com os valores recebidos, caso seja a primeira inserção
        cout << "raiz " << endl;
        raiz = new node<Tchave>(chave, p);
        cout << raiz->pssoa->cpf << " -  - - " << raiz->pssoa->nome << endl;
    } else {
        //chamada da função para inserir novos valores
        cout << "não raiz " << endl;
        raiz = raiz->insert(chave, p);
    }
}
//a partir de uma chave, essa funçao retorna o valor do nó
template <typename Tchave>
void tree<Tchave>::pesquisar(Tchave chave){
    if(raiz == nullptr){
        cout << "Arvore vazia..."<<endl;
    }else{
        node<Tchave>* x = raiz->search(raiz, chave);
        if(x != nullptr){
            cout << x->getPessoa()<<endl;

        }else{
            cout << "Valor não existe na arvore..."<<endl;
        }
    }
}

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA
// MATRICULA: 403958

#endif 