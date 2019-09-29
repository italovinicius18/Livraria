#ifndef SOCIO_HPP
#define SOCIO_HPP

#include <bits/stdc++.h>
#include "cliente.hpp"

using namespace std;

class Socio : public Cliente{
    public:
        Socio();
        ~Socio();
        Socio(string nome,string cpf, string email,string telefone);
        bool verifica_socio(string socio);
        double desconto_socio(double valor);
};


#endif