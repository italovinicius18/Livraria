#include "socio.hpp"

#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

Socio::Socio()
{
}
Socio::~Socio()
{
}
Socio::Socio(string nome, string cpf, string email, string telefone)
{
    set_nome(nome);
    set_cpf(cpf);
    set_telefone(telefone);
    set_email(email);
}

bool Socio::verifica_socio(string cpf)
{
    vector<string> socio;
    struct dirent *entrada;
    DIR *dir = opendir("file/socios");
    while ((entrada = readdir(dir)) != NULL)
    {
        if (entrada->d_name[0] != 46)
            socio.push_back(entrada->d_name);
    }
    closedir(dir);

    cpf = cpf+".txt";

    while (true)
    {
        if (find(socio.begin(), socio.end(), cpf) != socio.end())
        {
            return true;
        }
        else{
            return false;
        }
    }
}

double Socio::desconto_socio(double valor){
    double novo_valor;
    double porcento = 20;
    novo_valor = valor - (valor*(porcento/100));
    return novo_valor;
}