#include "carrinho.hpp"
#include "arquivo.hpp"
#include "socio.hpp"

#include <bits/stdc++.h>
using namespace std;

Carrinho::Carrinho() {}
Carrinho::~Carrinho() {}

bool Carrinho::verifica_quantidade(vector<string> livro)
{
    Arquivo arquivo;
    int quantidade;
    int verifica = 0;
    int tam = livro.size();
    for (int aux = 0; aux < tam; aux += 3)
    {
        string categoria = livro[aux];
        string codigo_livro = livro[aux + 1];
        quantidade = stoi(arquivo.retorna_linha("file/estoque/" + categoria + "/" + codigo_livro, 4));
        if (stoi(livro[aux + 2]) <= quantidade)
        {
            verifica++;
        }
    }
    if (verifica == tam / 3)
    {
        return true;
    }
    return false;
}
void Carrinho::total_carrinho(vector<string> livro, string cpf)
{

    Socio socio;
    Arquivo arquivo;
    double total = 0;
    int quantidade;
    int tam = livro.size();
    for (int aux = 0; aux < tam; aux += 3)
    {
        string categoria = livro[aux];
        string codigo_livro = livro[aux + 1];
        quantidade = stoi(livro[aux + 2]);
        total += quantidade * stod(arquivo.retorna_linha("file/estoque/" + categoria + "/" + codigo_livro, 3));
    }

    if (socio.verifica_socio(cpf))
    {
        total = socio.desconto_socio(total);
    }

    cout << "Total do carrinho ======== R$ " << total << "\n";
}
void Carrinho::situacao_carrinho(vector<string> livro)
{
    cout << "---------Situação do carrinho---------" << endl;
    Arquivo arquivo;
    string nome;
    double preco;
    int tam = livro.size();
    for (int aux = 0; aux < tam; aux += 3)
    {
        string categoria = livro[aux];
        string codigo_livro = livro[aux + 1];
        nome = arquivo.retorna_linha("file/estoque/" + categoria + "/" + codigo_livro, 1);
        preco = stod(arquivo.retorna_linha("file/estoque/" + categoria + "/" + codigo_livro, 3));
        cout << codigo_livro << "-----" << nome << "---- R$ " << round(preco) << "\n";
    }
}

void Carrinho::salva_produtos(vector<string> livro, string cpf)
{
    ofstream outfile;
    Socio socio;
    if (socio.verifica_socio(cpf))
    {
        outfile.open("file/socios/" + cpf + ".txt", ios::app);
        int tam = livro.size();
        for (int aux = 0; aux < tam; aux += 3)
        {
            outfile << "\n";
            outfile << livro[aux] << endl;
            outfile << livro[aux + 1] << endl;
            outfile << livro[aux + 2] << endl;
        }
        outfile.close();
    }
    else
    {
        outfile.open("file/clientes/" + cpf + ".txt", ios::app);
        int tam = livro.size();
        for (int aux = 0; aux < tam; aux += 3)
        {
            outfile << livro[aux] << endl;
            outfile << livro[aux + 1] << endl;
            outfile << livro[aux + 2] << endl;
        }
        outfile.close();
    }
}

void Carrinho::remove_quantidade(vector<string> livro)
{
    cout << "*************Compra efetuada***********" << endl;
    Arquivo arquivo;
    string categoria;
    string codigo_livro;
    int nova_quantidade;
    int tam = livro.size();
    for (int aux = 0; aux < tam; aux += 3)
    {
        string categoria = livro[aux];
        string codigo_livro = livro[aux + 1];
        nova_quantidade = stoi(arquivo.retorna_linha("file/estoque/" + categoria + "/" + codigo_livro, 4)) - stoi(livro[aux + 2]);
        arquivo.modifica_quantidade("file/estoque/" + categoria + "/" + codigo_livro, nova_quantidade);
    }
}