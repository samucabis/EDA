#ifndef NODE_H
#define NODE_H
#include "pessoa.h"

template <typename Tchave> 
class node {
public:
    explicit node(Tchave, pessoa p);
    node *esq;
    node *dir;
    Tchave getChave();
	pessoa getPessoa();
    int numeroFolhas();
    int getAltura();
    int getBalanco();
    void preorder();
    void inorder();
    void postorder();
    void desalocarMemoria();
    node* rotacao_dir(node *x);
    node* rotacao_esq(node *x);
    node* insert(Tchave chave, pessoa p);
    //node* remove(Tkey chave);
    node* remove_all(node *x);
    //node* minValueNode(node *x);
    node* min();
    node* max();
    node* search(node *x, Tchave chave);
private:
    Tchave chave;
    pessoa pssoa;
    int altura;

};

template <typename Tchave>
node< typename Tchave >::node(Tchave chave, pessoa p) 
{
    this->Tchave = chave;
    this->pssoa = p;
    this->altura = 1;
    
}
template <typename Tchave>
void node<typename Tchave>::desalocarMemoria(){
    node *currentNode = this;
    if(currentNode != nullptr) {
        currentNode->esq->desalocarMemoria();
        currentNode->dir->desalocarMemoria();
        delete currentNode;
    }
}

//maximo valor da chave da arvore
template <typename Tchave>
node<typename Tchave>* node<typename Tchave>::max() {
    node *currentNode = this;

    if(currentNode == nullptr) {
        return nullptr;
    }

    while(currentNode->dir != nullptr) {
        currentNode = currentNode->dir;
    }
    return currentNode;
}
//menor chave da arvore
template <typename Tchave>
node<typename Tchave>* node<typename Tchave>::min() {
    node *currentNode = this;

    if(currentNode == nullptr) {
        return nullptr;
    }

    while(currentNode->esq != nullptr) {
        currentNode = currentNode->esq;
    }
    return currentNode;
}



template <typename Tchave>
Tchave node< typename Tchave >::getChave() {
    return this->chave;
}
template <typename Tchave>
pessoa node< typename Tchave >::getPessoa() {
    return this->valor;
}
template <typename Tchave>
int node<typename Tchave>::getAltura() {
    node *currentNode = this;
    if(currentNode == nullptr) {
        return 0;
    }
    return currentNode->altura;
}
template <typename Tchave>
int node<typename Tchave>::getBalanco() {
    node *currentNode = this;
    if(currentNode == nullptr) {
        return 0;
    }
    return (currentNode->esq->getAltura() -
            currentNode->dir->getAltura());
}

template<typename Tchave>
node<typename Tchave>* node<typename Tchave>::rotacao_dir(node *y) {
    node *x = y->esq;
    node *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    x->altura = std::max(x->esq->getAltura(), x->dir->getAltura()) + 1;
    y->altura = std::max(y->esq->getAltura(), y->dir->getAltura()) + 1;

    return x;
}

template<typename Tchave>
node<typename Tchave>* node<typename Tchave>::rotacao_esq(node *x) {
    node *y = x->dir;
    node *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = std::max(x->esq->getAltura(), x->dir->getAltura()) + 1;
    y->altura = std::max(y->esq->getAltura(), y->dir->getAltura()) + 1;

    return y;
}



template <typename Tchave>
node<typename Tchave>* node<typename Tchave>::insert(Tchave chave, pessoa p)  {
    //verifica se o no atual é vazio
    node *currentNode = this;
    if(currentNode == nullptr) {
        //retorna novo no
        return new node(chave, p);
    }
    // se a chave for igual, retorna null
    if(currentNode->chave == chave) {
        return nullptr;
    }
    //verifica se a chave e menor pra inserir no lado esquerdo
    else if(stoi(chave) < stoi(currentNode->chave)) {
        currentNode->esq = currentNode->esq->insert(chave, p);
    }
    //caso contrario chama a função pro lado direito
    else {
        currentNode->dir = currentNode->dir->insert(chave, p);
    }

    currentNode->altura = std::max(currentNode->esq->getAltura(),
                                   currentNode->dir->getAltura()) + 1;
    //calcula o balanço
    int balanco_diferenca = currentNode->getBalanco();
    //verifica se precisa de rotaçao
    if(balanco_diferenca > 1 &&
            chave < currentNode->esq->chave) {
        return rotacao_dir(currentNode);
    }

    if(balanco_diferenca < -1 &&
            chave > currentNode->dir->chave) {
        return rotacao_esq(currentNode);
    }

    if(balanco_diferenca > 1 &&
            chave > currentNode->esq->chave) {
        currentNode->esq = rotacao_esq(currentNode->esq);
    }

    if(balanco_diferenca < -1 &&
            chave < currentNode->dir->chave) {
        currentNode->dir = rotacao_dir(currentNode->dir);
    }

    return currentNode;
}

template <typename Tchave>
node<typename Tchave>* node<typename Tchave>::search(node *x, Tchave chave)
{
    if (x == nullptr)
        return nullptr;
    if (stoi(chave) < stoi(x->chave))
        return search(x->esq, chave);
    else if (stoi(chave) > stoi(x->chave))
        return search(x->dir, chave);
    else
        return x;
}
#endif