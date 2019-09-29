#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <bits/stdc++.h>
using namespace std;

class Arquivo{
    private:
    int linha;
    string path;
    int nova_quantidade;
    double novo_preco;
    public:
    Arquivo();
    ~Arquivo();
    string retorna_linha(string path,int linha);
    void modifica_preco(string path, double novo_preco);
    void modifica_quantidade(string path, int nova_quantidade);
};
#endif