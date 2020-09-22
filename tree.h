#ifndef TREE_H
#define TREE_H

#include "node.h"

class tree
{
private:
    node *raiz;

public:

    tree();
    ~tree();
    int altura();
    int numeroFolhas();
    void pre_ordem();
    void em_ordem();
    void pos_ordem();
    void inserir(Tchave chave, pessoa p);
    void remover(Tchave chave);
    void remover_tudo();
    node* min();
    node* max();
    void pesquisar(Tchave chave);

};

#endif // TREE_H
//teste do git222
// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA
// MATRICULA: 403958










/*
#include "node.h"

class tree
{
private:
    node *raiz;

public:

    tree();
    ~tree();
    int altura();
    int numeroFolhas();
    void pre_ordem();
    void em_ordem();
    void pos_ordem();
    void inserir(Tkey chave, Tvalue valor);
    void remover(Tkey chave);
    void remover_tudo();
    node* min();
    node* max();
    void pesquisar(Tkey chave);

};

#endif // TREE_H

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA

// MATRICULA: 403958
*/