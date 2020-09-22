#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <string>

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
    int numeroFolhas();
    void pre_ordem();
    void em_ordem();
    void pos_ordem();
    void inserir(Tchave chave, string p);
    void remover(Tchave chave);
    void remover_tudo();
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
//retorna a quantidade de folhas
template <typename Tchave>
int tree<Tchave>::numeroFolhas() {
    if(raiz == nullptr) {
        return 0;
    }
    return raiz->numeroFolhas();
}
//retorna a altura da arvore
template <typename Tchave>
int tree<Tchave>::altura() {
    if(raiz == nullptr) {
        return 0;
    }
    return raiz->getAltura();
}
//função pre ordem
template <typename Tchave>
void tree<Tchave>::pre_ordem() {
    if(raiz == nullptr) {
        cout << "Arvore vazia.";
    } else {
        raiz->preorder();
    }
    cout << endl;
}
//função em ordem
template <typename Tchave>
void tree<Tchave>::em_ordem() {
    if(raiz == nullptr) {
        cout << "Arvore vazia.";
    } else {
        raiz->inorder();
    }
    cout << endl;
}
//função pos ordem
template <typename Tchave>
void tree<Tchave>::pos_ordem() {
    if(raiz == nullptr) {
        cout << "Arvore vazia.";
    } else {
        raiz->postorder();
    }
    cout << endl;
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
void tree<Tchave>::inserir(Tchave chave, string p) {
    if(raiz == nullptr) {
        //cria novo nó com os valores recebidos, caso seja a primeira inserção
        raiz = new node<Tchave>(chave, p);
    } else {
        //chamada da função para inserir novos valores
        raiz = raiz->insert(chave, p);
    }
}
//chamada da função remove
template <typename Tchave>
void tree<Tchave>::remover(Tchave chave) {
    if(raiz != nullptr) {
        raiz = raiz->remove(chave);
    }
}
//chamada da fução remove que limpa a arvore
template <typename Tchave>
void tree<Tchave>::remover_tudo(){
    if(raiz != nullptr) {
        raiz = raiz->remove_all(raiz);
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