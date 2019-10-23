#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
using namespace std;

class Cliente
{
private:
    string nome;
    string cpf;
    string socio;
    string telefone;
    string email;
public:
    Cliente();
    Cliente(string nome,string cpf, string email,string telefone);
    ~Cliente();
    string get_nome();
    void set_nome(string nome);
    string get_cpf();
    void set_cpf(string cpf);
    string get_email();
    void set_email(string email);
    string get_telefone();
    void set_telefone(string telefone);
    virtual bool verifica_cliente(string cpf);
    string verifica_cpf();
    virtual void imprime_dados();
    virtual string salva_dados();
};

#endif