#ifndef PESSOA_H
#define PESSOA_H
#include "stdio.h"
#include <string>

using namespace std;


class pessoa
{
    public:
        pessoa(string cpf, string nome, string snome, string nasc, string cidade);
        pessoa();
        //~pessoa();1
        void printPessoa();
        string cpf;
        string nasc;
        string nome;
        string snome;
        string cidade; 
        bool igualdade;
};

#endif


