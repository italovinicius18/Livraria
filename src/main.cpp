#include <bits/stdc++.h>
#include "inicio.hpp"

using namespace std;

template <typename T1>

T1 getInput()
{
    while (true)
    {
        T1 valor;
        cin >> valor;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Entrada inválida! Insira novamente: " << endl;
        }
        else
        {
            cin.ignore(32767, '\n');
            return valor;
        }
    }
}

int main()
{
    system("clear");
    int comando = -1;
    Inicio inicio;
    while (comando != 0)
    {
        inicio.modo_inicio();

        comando = getInput<int>();

        switch (comando)

        {
        case 1:
            inicio.modo_venda();
            break;
        case 2:
            inicio.modo_estoque();
            break;
        case 3:
            inicio.modo_recomenda();
            break;
        case 0:
            cout << "Muito obrigado pela visita, volte sempre !!" << endl;
            break;
        default:
            cout << "Por favor, digite uma opção válida:" << endl;
            break;
        }
    }

    return 0;
}