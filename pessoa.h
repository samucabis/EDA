#ifndef PESSOA_H
#define PESSOA_H

using namespace std;

class Pessoa{
    public:
        Pessoa(string nome, string cpf);
        ~Pessoa();
        void printPessoa();
    private:    
        std::string nome;
        std::string cpf;

    
};

#endif


