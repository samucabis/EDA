#ifndef NODE_H
#define NODE_H
#include "pessoa.h"
#include <iostream>
#include <string>

// ########################################### NODE #####################################################
template <typename Tchave>
class node
{
public:
    node(Tchave, pessoa &p);
    node();
    node *esq = NULL;
    node *dir = NULL;
    Tchave getChave();
    string getPessoa();
    int numeroFolhas();
    int getAltura();
    int getBalanco();
    //void preorder();
    // void inorder();
    //void postorder();
    void desalocarMemoria();
    node *rotacao_dir(node *x);
    node *rotacao_esq(node *x);
    node *insert(Tchave chave, pessoa &p);
    //node* remove(Tchave chave);
    //node* remove_all(node *x);
    //node* minValueNode(node *x);
    node *min();
    node *max();
    node *search(node *x, Tchave chave);
    void searchnome(node *x, Tchave chave);
    pessoa *pssoa;

private:
    Tchave chave;

    int altura;
};

template <typename Tchave>
node<Tchave>::node()
{

    this->altura = 1;
    this->dir = NULL;
    this->esq = NULL;
}

template <typename Tchave>
node<Tchave>::node(Tchave chave, pessoa &p)
{
    this->chave = chave;
    this->pssoa = &p;
    this->altura = 1;
    this->dir = NULL;
    this->esq = NULL;
}

template <typename Tchave>
Tchave operator<(Tchave a, Tchave b)
{
    if (a < b)
        return a;
    return b;
}

template <typename Tchave>
Tchave operator>(Tchave a, Tchave b)
{
    if (a > b)
        return a;
    return b;
}
template <typename Tchave>
bool operator==(Tchave a, Tchave b)
{
    if (a == b)
        return true;

    return false;
}

template <typename Tchave>
void node<Tchave>::desalocarMemoria()
{
    node *currentNode = this;
    if (currentNode != nullptr)
    {
        currentNode->esq->desalocarMemoria();
        currentNode->dir->desalocarMemoria();
        delete currentNode;
    }
}

//maximo valor da chave da arvore
template <typename Tchave>
node<Tchave> *node<Tchave>::max()
{
    node *currentNode = this;

    if (currentNode == nullptr)
    {
        return nullptr;
    }

    while (currentNode->dir != nullptr)
    {
        currentNode = currentNode->dir;
    }
    return currentNode;
}
//menor chave da arvoress
template <typename Tchave>
node<Tchave> *node<Tchave>::min()
{
    node *currentNode = this;

    if (currentNode == nullptr)
    {
        return nullptr;
    }

    while (currentNode->esq != nullptr)
    {
        currentNode = currentNode->esq;
    }
    return currentNode;
}

template <typename Tchave>
Tchave node<Tchave>::getChave()
{
    return this->chave;
}
template <typename Tchave>
string node<Tchave>::getPessoa()
{
    string nome = this->pssoa->nome;
    return nome;
}
template <typename Tchave>
int node<Tchave>::getAltura()
{
    node *currentNode = this;
    if (currentNode == nullptr)
    {
        return 0;
    }
    return currentNode->altura;
}
template <typename Tchave>
int node<Tchave>::getBalanco()
{
    node *currentNode = this;
    if (currentNode == nullptr)
    {
        return 0;
    }
    return (currentNode->esq->getAltura() -
            currentNode->dir->getAltura());
}

template <typename Tchave>
node<Tchave> *node<Tchave>::rotacao_dir(node *y)
{
    if (y->esq == nullptr)
    {
        y->esq = new node();
        y->esq->pssoa = new pessoa();
    }
    if (y->dir == nullptr)
    {
        y->dir = new node();
        y->dir->pssoa = new pessoa();
    }
    node *x = y->esq;
    node *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    x->altura = std::max(x->esq->getAltura(), x->dir->getAltura()) + 1;
    y->altura = std::max(y->esq->getAltura(), y->dir->getAltura()) + 1;

    return x;
}

template <typename Tchave>
node<Tchave> *node<Tchave>::rotacao_esq(node *x)
{
    if (x->esq == nullptr)
    {
        x->esq = new node();
        x->esq->pssoa = new pessoa();
    }
    if (x->dir == nullptr)
    {
        x->dir = new node();
        x->dir->pssoa = new pessoa();
    }

    node *y = x->dir;
    node *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = std::max(x->esq->getAltura(), x->dir->getAltura()) + 1;
    y->altura = std::max(y->esq->getAltura(), y->dir->getAltura()) + 1;

    return y;
}
//retorna numeor de folhas da arvore
template<typename Tchave>
int node<Tchave>::numeroFolhas() {
    node *currentNode = this;
    if(currentNode == nullptr) {
        return 0;
    }
    else if(currentNode->esq == nullptr &&
            currentNode->dir == nullptr) {
        return 1;
    }
    //soma do retono das folhas
    return currentNode->esq->numeroFolhas() +
            currentNode->dir->numeroFolhas();
}
// template <typename Tchave>
// void node<Tchave>::concerta(node *current)
// {
//     current->dir = new node();
//     current->dir->pssoa = new pessoa();
//     current->esq = new node();
//     current->esq->pssoa = new pessoa();
// }

template <typename Tchave>
node<Tchave> *node<Tchave>::insert(Tchave chave, pessoa &p)
{
    //verifica se o no atual é vazio
    node *currentNode = this;
    if (currentNode == nullptr)
    {
        //retorna novo no
        cout << "inserir vazio " << endl;
        return new node(chave, p);
    }

    // se a chave for igual, retorna null
    if (!p.igualdade)
    {
        //verifica se a chave e menor pra inserir no lado esquerdo
        if (chave < currentNode->chave)
        {
            cout << "indo para esquerda do no" << endl;
            currentNode->esq = currentNode->esq->insert(chave, p);
            //concerta(currentNode->esq->);
        }
        //caso contrario chama a função pro lado direito
        else
        {
            cout << "indo para direita do no " << endl;
            currentNode->dir = currentNode->dir->insert(chave, p);
            //concerta(currentNode->dir);
        }
    }
    else
    {
        cout << "igual " << endl;

        if (currentNode->pssoa->cpf < p.cpf)
        {
            cout << "cahve igual 1 " << endl;

            currentNode->dir = currentNode->dir->insert(chave, p);
        }
        else
        {
            cout << "cahve igual 2 " << endl;

            currentNode->esq = currentNode->esq->insert(chave, p);
        }
    }
    cout << chave << " - " << currentNode->chave << endl;


    currentNode->altura = std::max(currentNode->esq->getAltura(),
                                   currentNode->dir->getAltura()) +
                          1;
    //calcula o balanço
    int balanco_diferenca = currentNode->getBalanco();
    cout << "Balanço : " << currentNode->getBalanco() << endl;

    //verifica se precisa de rotaçao

    //cout << "chaves diferentes" << endl;
    if (balanco_diferenca > 1 &&
        chave < currentNode->esq->chave)
    {
        //rot_dir(currentNode);
        return rotacao_dir(currentNode);
    }

    if (balanco_diferenca < -1 &&
        chave > currentNode->dir->chave)
    {
        //rot_esq(currentNode);
        return rotacao_esq(currentNode);
    }

    if (balanco_diferenca > 1 &&
        chave > currentNode->esq->chave)
    {
        //rot_esq_dir(currentNode);
        //cout << currentNode->esq->chave << endl;
        currentNode->esq = rotacao_esq(currentNode->esq);
        return rotacao_dir(currentNode);
    }
    if (balanco_diferenca < -1 &&
        chave < currentNode->dir->chave)
    {
        //rot_dir_esq(currentNode);
        currentNode->dir = rotacao_dir(currentNode->dir);
        return rotacao_esq(currentNode);
    }

    return currentNode;
}

template <typename Tchave>
node<Tchave> *node<Tchave>::search(node *x, Tchave chave)
{
    if (x == nullptr)
        return nullptr;
    if (chave < x->chave)
        return search(x->esq, chave);
    else if (chave > x->chave)
        return search(x->dir, chave);
    else
        return x;
}
template <typename Tchave>
void node<Tchave>::searchnome(node *x, Tchave chave)
{   
    if(x != nullptr) {
        if(x->chave.find(chave) != std::string::npos)
            x->pssoa->printPessoa();
        x->esq->searchnome(x->esq,chave);
        x->dir->searchnome(x->dir,chave);
    }
}

// ########################################################################### END NODE #########################################

#endif