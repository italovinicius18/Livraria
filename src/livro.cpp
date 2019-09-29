#include "livro.hpp"
#include "arquivo.hpp"
#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;
Livro::Livro()
{
}
Livro::Livro(string nome_livro, int codigo_livro, string categoria, double valor, int quantidade)
{
    set_nome_livro(nome_livro);
    set_codigo_livro(codigo_livro);
    set_categoria(categoria);
    set_valor(valor);
    set_quantidade(quantidade);
}
Livro::~Livro()
{
}

string Livro::get_nome_livro()
{
    return nome_livro;
}
void Livro::set_nome_livro(string nome_livro)
{
    this->nome_livro = nome_livro;
}
int Livro::get_codigo_livro()
{
    return codigo_livro;
}
void Livro::set_codigo_livro(int codigo_livro)
{
    this->codigo_livro = codigo_livro;
}
string Livro::get_categoria()
{
    return categoria;
}
void Livro::set_categoria(string categoria)
{
    this->categoria = categoria;
}
double Livro::get_valor()
{
    return valor;
}
void Livro::set_valor(double valor)
{
    this->valor = valor;
}
int Livro::get_quantidade()
{
    return quantidade;
}
void Livro::set_quantidade(int quantidade)
{
    this->quantidade = quantidade;
}
void Livro::imprime_dados()
{
    cout << "Nome do livro: " << get_nome_livro() << endl;
    cout << "Categoria: " << get_categoria() << endl;
    cout << "Valor: " << get_valor() << endl;
    cout << "Quantidade: " << get_quantidade() << endl;
}
string Livro::salva_dados()
{
    return get_nome_livro() + "\n" + get_categoria() + "\n" + to_string(get_valor()) + "\n" + to_string(get_quantidade());
}

string Livro::verifica_categoria()
{
    cout << "Digite qual a categoria do livro que deseja comprar: " << endl;
    string aux;
    vector<string> categoria;
    struct dirent *entrada;
    DIR *dir = opendir("file/estoque");
    while ((entrada = readdir(dir)) != NULL)
    {
        if (entrada->d_name[0] != 46)
            categoria.push_back(entrada->d_name);
    }
    closedir(dir);

    while (true)
    {
        cin >> aux;
        if (find(categoria.begin(), categoria.end(), aux) != categoria.end())
        {
            return aux;
        }
        else
        {
            cout << "Digite novamente a categoria de acorda com as listadas: " << endl;
        }
    }
}

int Livro::verifica_livro(string categoria)
{
    cout << "Digite qual livro deseja comprar: (código)" << endl;
    int aux;
    vector<int> livros;
    struct dirent *entrada;
    string path = "file/estoque/" + categoria;
    DIR *dir = opendir(path.c_str());
    while ((entrada = readdir(dir)) != NULL)
    {
        if (entrada->d_name[0] != 46)
            livros.push_back(stoi(entrada->d_name));
    }
    closedir(dir);

    while (true)
    {
        cin >> aux;
        if (find(livros.begin(), livros.end(), aux) != livros.end())
        {
            return aux;
        }
        else
        {
            cout << "Digite novamente o código de acordo com os listados: " << endl;
        }
    }
}

void Livro::lista_categoria()
{

    cout << "--------------Categorias dos livros----------------" << endl;
    struct dirent *entry;
    DIR *dir = opendir("file/estoque");

    if (dir == NULL)
    {
        return;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != 46)
            cout << entry->d_name << endl;
    }
    closedir(dir);
    cout << "---------------------------------------------------" << endl;
}

void Livro::lista_livro(string categoria)
{   
    cout << "---------------------Livros------------------------" << endl;
    Arquivo arquivo;
    string nome;
    double preco;
    struct dirent *entry;
    string path = "file/estoque/" + categoria;
    DIR *dir = opendir(path.c_str());
    if (dir == NULL)
    {
        return;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != 46)
        {
            nome = arquivo.retorna_linha(path + "/" + entry->d_name, 1);
            preco = stod(arquivo.retorna_linha(path + "/" + entry->d_name, 3));
            cout << entry->d_name << "-----" << nome << "----"
                 << "R$ " << preco << "\n";
        }
    }
    closedir(dir);
    cout << "---------------------------------------------------" << endl;
}