#include "Pessoa.h"

#include <iostream>
#include <cstdlib>

Pessoa::Pessoa(string nome, string cpf){
    this->nome = nome;
    this->cpf = cpf;
}
void Pessoa::printPessoa(){
    cout << this->nome << " - " << this->cpf << endl;
}
