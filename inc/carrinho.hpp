#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include<bits/stdc++.h>
using namespace std;

class Carrinho{
    private:
        double total;
        vector<string> codigos;
        string cpf;
    public:
        Carrinho();
        ~Carrinho();
        bool verifica_quantidade(vector<string> livro);
        void total_carrinho(vector<string> livro,string cpf);
        void situacao_carrinho(vector<string> livro);
        void remove_quantidade(vector<string> livro);
        void salva_produtos(vector<string> livro,string cpf);
};

#endif
