// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA
// MATRICULA: 403958

#include <iostream>
#include <cstdlib>
#include "tree.h"

using namespace std;

void limpaTela() {
    cout << "Tecle para proseguir..." << endl;
    getchar();
    getchar();
    system("clear");
}
//menu principal
int menu() {
    int op = 0;
    cout << "-----------------------------  "           << endl;
    cout << "Implementacao da arvore AVL    "           << endl;
    cout << "-----------------------------  "           << endl;
    cout                                                << endl;
    cout << "1 - Inserir"                               << endl;
    cout << "2 - Remover"                               << endl;
    cout << "3 - Percurso pre-ordem"                    << endl;
    cout << "4 - Percurso em-ordem"                     << endl;
    cout << "5 - Percurso pos-ordem"                    << endl;
    cout << "6 - Altura da arvore"                      << endl;
    cout << "7 - Numero de folhas da arvore"            << endl;
    cout << "8 - Valor maximo e minimo"                 << endl;
    cout << "9 - Apagar todos os nos da arvore"         << endl;
    cout << "10- pesquisar uma chave e retornar o valor"<< endl;
    cout << "0 - Sair"                                  << endl;
    cout << ">> ";
    cin >> op;

    return op;
}
//switch case do menu principal
template <typename Tchave>
void init(int op, tree<typename Tchave> *t, bool *b) {
    system("clear");
    switch(op)
    {
    case 1:
    {
        Tkey novaChave;
        Tvalue novoValor;
        cout << "Entre com a chave a ser inserido: ";
        cin >> novaChave;
        cout << "Entre com o novo valor a ser inserido: ";
        cin >> novoValor;
        t->inserir(novaChave, novoValor);
        limpaTela();
        break;
    }
    case 2:
    {
        Tkey deleteChave;
        cout << "Entre com a chave que deseja deletar: ";
        cin >> deleteChave;
        t->remover(deleteChave);
        limpaTela();
        break;
    }
    case 3:
    {
        t->pre_ordem();
        limpaTela();
        break;
    }
    case 4:
    {
        t->em_ordem();
        limpaTela();
        break;
    }
    case 5:
    {
        t->pos_ordem();
        limpaTela();
        break;
    }
    case 6:
    {
        int altura = t->altura();
        cout << "Altura da arvore: " << altura << endl;
        limpaTela();
        break;
    }
    case 7:
    {
        int numFolhas = t->numeroFolhas();
        cout << "Numero de folhas da arvore: " << numFolhas << endl;
        limpaTela();
        break;
    }
    case 8:
    {
        node *max = t->max();
        node *min = t->min();
        if(max == nullptr || min == nullptr) {
            cout << "Valores maximo e minimo nao existem..." << endl;
        } else {
            cout << "Valor maximo: " << max->getChave() << endl;
            cout << "Valor minimo: " << min->getChave() << endl;
        }
        limpaTela();
        break;
    }
    case 9:
    {
        cout << "Apagando a arvore"<< endl;
        t->remover_tudo();
        limpaTela();
        break;
    }
    case 10:
    {
        Tkey chave;
        cout << "Digite uma Chave..."<< endl;
        cin >> chave;
        t->pesquisar(chave);
        limpaTela();
        break;
    }
    
    case 0:
    {
        *b = false;
        break;
    }
    default:
    {
        cout << "Opcao invalida..." << endl;
        limpaTela();
        break;
    }
    }
}

template <typename Tchave>
int main() {
    tree<typename Tchave> *t = new tree();
    bool continua = true;

    while(continua) {
        init(menu(), t, &continua);
    }

    delete t;

    return 0;
}