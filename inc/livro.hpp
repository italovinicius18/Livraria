#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <bits/stdc++.h>
using namespace std;

class Livro
{
private:
    string nome_livro;
    int codigo_livro;
    string categoria;
    double valor;
    int quantidade;

public:
    Livro();
    Livro(string nome_livro, int codigo_livro, string categoria, double valor, int quantidade);
    ~Livro();
    string get_nome_livro();
    void set_nome_livro(string nome_livro);
    int get_codigo_livro();
    void set_codigo_livro(int codigo_livro);
    string get_categoria();
    void set_categoria(string categoria);
    double get_valor();
    void set_valor(double valor);
    int get_quantidade();
    void set_quantidade(int quantidade);
    void lista_livro(string categoria);
    void lista_categoria();
    string verifica_categoria ();
    int verifica_livro (string categoria);
    void imprime_dados();
    string salva_dados();
};
#endif