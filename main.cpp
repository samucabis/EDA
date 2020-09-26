// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA
// MATRICULA: 403958

#include <iostream>
#include <cstdlib>
#include "tree.h"
#include <vector>
#include "ReadCsv.h"

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
    cout << "1 - Gerar arvores"                         << endl;
    cout << "2 - Remover"                               << endl;
    cout << "3 - Percurso pre-ordem"                    << endl;
    cout << "4 - Percurso em-ordem"                     << endl;
    cout << "5 - Percurso pos-ordem"                    << endl;
    cout << "6 - Altura da arvore"                      << endl;
    cout << "7 - Numero de folhas da arvore"            << endl;
    cout << "8 - Valor maximo e minimo"                 << endl;
    cout << "9 - Apagar todos os nos da arvore"         << endl;
    cout << "10- Consultar por CPF"                     << endl;
    cout << "0 - Sair"                                  << endl;
    cout << ">> ";
    cin >> op;

    return op;
}
//switch case do menu principal
template <typename Tchave>
void init(int op, tree<Tchave> *t, bool *b, vector<pessoa> &pessoas) {
    system("clear");
    switch(op)
    {
    case 1:
    {
        //cout << pessoas.size() << endl;1
        int i=1;
        for(pessoa &p : pessoas){
            //p.printPessoa();
            //pessoa *pe = &pessoas.at(i);
            cout << "LINHA :" << i  << " NOME :" << p.nome << endl;
            //cout << pessoas.at(i).cpf.substr(0,2) << endl;
            //t->inserir(p.cpf, p);
            t->inserir(p.nome, p);
            //t2->inserir(pessoas.at(i).nasc, pe);
            i++;
        }
    
        
        limpaTela();
        break;
    }
    case 2:
    {
        Tchave deleteChave;
        cout << "Entre com a chave que deseja deletar: ";
        cin >> deleteChave;
        //t->remover(deleteChave);
        limpaTela();
        break;
    }
    case 3:
    {
       // t->pre_ordem();
        limpaTela();
        break;
    }
    case 4:
    {
        //t->em_ordem();
        limpaTela();
        break;
    }
    case 5:
    {
        //t->pos_ordem();
        limpaTela();
        break;
    }
    case 6:
    {
        int altura = t->altura();
        //int altura1 = t1->altura();
        //int altura2 = t2->altura();
        cout << "Altura da arvore cpf: " << altura << endl;
       // cout << "Altura da arvore nome: " << altura1 << endl;
        //cout << "Altura da arvore nascimento : " << altura2 << endl;
        limpaTela();
        break;
    }
    case 7:
    {
        //int numFolhas = t->numeroFolhas();
        //cout << "Numero de folhas da arvore: " << numFolhas << endl;
        limpaTela();
        break;
    }
    case 8:
    {
        node<Tchave> *max = t->max();
        node<Tchave> *min = t->min();
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
        //t->remover_tudo();
        limpaTela();
        break;
    }
    case 10:
    {
        Tchave chave;
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

int main() {
    tree<string> *t = new tree<string>();
    //tree<string> *t1 = new tree<string>();
   // tree<string> *t2 = new tree<string>();
    ReadCsv readcsv;
    vector<pessoa> pessoas = read_csv("data.csv");

    bool continua = true;

    while(continua) {
        init(menu(),  t, &continua, pessoas);
    } 


    delete t;
    //delete t1;
    //delete t2;

    return 0;
}
