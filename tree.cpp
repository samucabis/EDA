#include "tree.h"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

//iniciando a arvore como vazia
tree::tree() {
    cout << "Criando..."              << endl;
    cout << "Aperte enter para prosseguir..." << endl;
    getchar();
    system("clear");
    raiz = nullptr;
}
//destruindo a arvore
tree::~tree() {
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
int tree::numeroFolhas() {
    if(raiz == nullptr) {
        return 0;
    }
    return raiz->numeroFolhas();
}
//retorna a altura da arvore
int tree::altura() {
    if(raiz == nullptr) {
        return 0;
    }
    return raiz->getAltura();
}
//função pre ordem
void tree::pre_ordem() {
    if(raiz == nullptr) {
        cout << "Arvore vazia.";
    } else {
        raiz->preorder();
    }
    cout << endl;
}
//função em ordem
void tree::em_ordem() {
    if(raiz == nullptr) {
        cout << "Arvore vazia.";
    } else {
        raiz->inorder();
    }
    cout << endl;
}
//função pos ordem
void tree::pos_ordem() {
    if(raiz == nullptr) {
        cout << "Arvore vazia.";
    } else {
        raiz->postorder();
    }
    cout << endl;
}
//retorna valor minimo da arvore
node* tree::min() {
    if(raiz == nullptr) {
        return nullptr;
    }
    return raiz->min();
}
//retorna valor max da arvore
node* tree::max() {
    if(raiz == nullptr) {
        return nullptr;
    }
    return raiz->max();
}
//função inserir na arvore
void tree::inserir(Tkey chave, Tvalue valor) {
    if(raiz == nullptr) {
        //cria novo nó com os valores recebidos, caso seja a primeira inserção
        raiz = new node(chave, valor);
    } else {
        //chamada da função para inserir novos valores
        raiz = raiz->insert(chave, valor);
    }
}
//chamada da função remove
void tree::remover(Tkey chave) {
    if(raiz != nullptr) {
        raiz = raiz->remove(chave);
    }
}
//chamada da fução remove que limpa a arvore
void tree::remover_tudo(){
    if(raiz != nullptr) {
        raiz = raiz->remove_all(raiz);
    }
}
//a partir de uma chave, essa funçao retorna o valor do nó
void tree::pesquisar(Tkey chave){
    if(raiz == nullptr){
        cout << "Arvore vazia..."<<endl;
    }else{
        node* x = raiz->search(raiz, chave);
        if(x != nullptr){
            cout << x->getValor()<<endl;

        }else{
            cout << "Valor não existe na arvore..."<<endl;
        }
    }
}

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA
// MATRICULA: 403958

