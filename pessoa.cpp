#include "pessoa.h"
#include <iostream>

using namespace std;
//1
pessoa::pessoa(string cpf, string nome, string snome, string nasc, string cidade) {
    this->cpf   = cpf;
	this->nome   = nome;
    this->snome     = snome;
    this->nasc     = nasc;
    this->cidade  = cidade;
}
pessoa::pessoa() {
}
void pessoa::printPessoa(){
    cout << this->cpf << " - " << this->nome << endl;
}