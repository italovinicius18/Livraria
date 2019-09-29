#include "cliente.hpp"
#include <bits/stdc++.h>

using namespace std;

Cliente::Cliente()
{
}

Cliente::Cliente(string nome, string cpf, string email, string telefone)
{
    set_nome(nome);
    set_cpf(cpf);
    set_email(email);
    set_telefone(telefone);
}

Cliente::~Cliente()
{
}

string Cliente::get_nome()
{
    return nome;
}
void Cliente::set_nome(string nome)
{
    this->nome = nome;
}
string Cliente::get_cpf()
{
    return cpf;
}
void Cliente::set_cpf(string cpf)
{
    this->cpf = cpf;
}
string Cliente::get_telefone()
{
    return telefone;
}
void Cliente::set_telefone(string telefone)
{
    this->telefone = telefone;
}

string Cliente::get_email()
{
    return email;
}
void Cliente::set_email(string email)
{
    this->email = email;
}

bool Cliente::verifica_cliente(string cpf)
{
    ifstream cliente("file/clientes/" + cpf + ".txt");
    ifstream socio("file/socios/" + cpf + ".txt");

    if (cliente.is_open() or socio.is_open())
    {
        socio.close();
        cliente.close();
        return true;
    }
    else
    {
        return false;
    }
}

string Cliente::verifica_cpf()
{
    {
        bool p = true;
        do
        {
            cin >> cpf;
            int tam;
            tam = cpf.size();
            if (tam > 11 || tam < 11)
            {
                p = false;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Digite novamente o cpf: (Apenas numeros)" << endl;
            }
            else
            {
                int aux = 0;
                for (int i = 0; i < tam; i++)
                {
                    if (((int)cpf[i] > 47) & ((int)cpf[i] < 58))
                    {
                        aux++;
                    }
                }

                if (aux == 11)
                {
                    p = true;
                }
                else
                {
                    p = false;
                    cout << "Digite novamente o cpf: (Apenas numeros)" << endl;
                }
            }

        } while (p == false);
        cin.clear();
        cin.ignore(32767, '\n');
        return cpf;
    }
}

void Cliente::imprime_dados()
{
    cout << "Nome: " << get_nome() << endl;
    cout << "CPF: " << get_cpf() << endl;
    cout << "Telefone: " << get_telefone() << endl;
    cout << "Email: " << get_email() << endl;
}

string Cliente::salva_dados()
{
    return get_nome() + "\n" + get_cpf() + "\n" + get_telefone() + "\n" + get_email() + "\n";
}