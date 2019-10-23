#include "inicio.hpp"
#include "livro.hpp"
#include "socio.hpp"
#include "carrinho.hpp"
#include "arquivo.hpp"
#include "recomenda.hpp"

#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

string getString()
{
    string valor;
    getline(cin, valor);
    return valor;
}

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

Inicio::Inicio() {}
Inicio::~Inicio() {}

void Inicio::modo_inicio()
{
    cout << "****************Livraria do Vinícius**************" << endl;
    cout << " Digite o número do comando para entrar na opção: " << endl;
    cout << " 1 - __________________Modo venda_________________" << endl;
    cout << " 2 - _________________Modo estoque________________" << endl;
    cout << " 3 - ________________Modo recomenda_______________" << endl;
    cout << " 0 - _____________________Sair____________________" << endl;
    cout << "***************************************************" << endl;
}

void Inicio::modo_venda()
{
    string nome;
    string cpf;
    string socio;
    string telefone;
    string email;
    string categoria;
    int codigo_livro;
    int quantidade;
    vector<Cliente *> clientes;
    vector<Socio *> socios;
    vector<string> situacao;
    Cliente c;
    Socio s;
    Livro l;
    ofstream outfile;
    ifstream infile;

    cout << "_____________________Modo venda____________________" << endl;

    cout << "Digite o seu nome:" << endl;
    nome = getString();
    cout << "Digite o seu CPF: (Apenas números)" << endl;
    cpf = c.verifica_cpf();
    cin.clear();

    if (c.verifica_cliente(cpf))
    {
        cout << "---------------------------------------------------" << endl;
        cout << "      Seja bem-vindo novamente, " + nome + " !!" << endl;
        cout << "---------------------------------------------------" << endl;
    }

    else
    {
        cout << "Digite o seu email: " << endl;
        email = getString();
        cout << "Digite o seu telefone: " << endl;
        telefone = getString();
        cout << "Gostaria de ser socio ? (S/N)" << endl;
        socio = getString();

        if (socio == "S")
        {
            socios.push_back(new Socio(nome, cpf, email, telefone));

            outfile.open("file/socios/" + cpf + ".txt", ios::app);

            for (Socio *s : socios)
            {
                s->salva_dados();
                outfile << s->salva_dados();
            }

            outfile.close();
        }
        else
        {
            clientes.push_back(new Cliente(nome, cpf, email, telefone));

            outfile.open("file/clientes/" + cpf + ".txt", ios::app);

            for (Cliente *c : clientes)
            {
                c->salva_dados();
                outfile << c->salva_dados();
            }

            outfile.close();
        }

        cout << "---------------------------------------------------" << endl;
        cout << "Muito obrigado por escolher a nossa loja, " + nome + " !!" << endl;
        cout << "---------------------------------------------------" << endl;
    }

    int opcao = -1;

    while (opcao != 0)
    {
        cout << "*********************CARRINHO**********************" << endl;
        cout << "  Digite o número do comando para entrar na opção: " << endl;
        cout << "  1 - __________________Comprar____________________" << endl;
        cout << "  0 - _______________Concluir compra_______________" << endl;
        cout << "\n*************************************************" << endl;

        opcao = getInput<int>();

        switch (opcao)
        {
        case 1:
        {

            Carrinho carrinho;

            l.lista_categoria();

            categoria = l.verifica_categoria();

            l.lista_livro(categoria);

            codigo_livro = l.verifica_livro(categoria);

            cout << "Digite a quantidade que deseja comprar: " << endl;
            quantidade = getInput<int>();

            situacao.push_back(categoria);
            situacao.push_back(to_string(codigo_livro));
            situacao.push_back(to_string(quantidade));
            carrinho.situacao_carrinho(situacao);
            carrinho.total_carrinho(situacao, cpf);
        }

        break;

        case 0:
        {

            Carrinho carrinho;
            if (situacao.size() != 0)
            {

                carrinho.situacao_carrinho(situacao);
                carrinho.total_carrinho(situacao, cpf);
                if (carrinho.verifica_quantidade(situacao))
                {
                    carrinho.remove_quantidade(situacao);
                    carrinho.salva_produtos(situacao, cpf);
                }
                else
                {
                    cout << "Compra cancelada, não temos a quantidade de produtos no estoque" << endl;
                }
            }
            if (situacao.size() == 0)
            {
                cout << "-------------Nenhum produto comprado---------------" << endl;
            }
        }
        break;
        default:
            cout << "Opção inválida" << endl;
            break;
        }
    }
}

void Inicio::modo_estoque()
{
    int comando1 = -1;
    while (comando1 != 0)
    {
        string nome_livro;
        int codigo_livro;
        int quantidade;
        double valor;
        string categoria;
        Arquivo arquivo;
        Livro l;
        vector<Livro *> livro;
        ofstream outfile;

        cout << "***************************************************" << endl;
        cout << "____________________Modo estoque__________________" << endl;
        cout << " Digite o número do comando para entrar na opção: " << endl;
        cout << " 1 - ______________Adicionar livro________________" << endl;
        cout << " 2 - _________Mudar valor de algum livro__________" << endl;
        cout << " 0 - ___________________Sair______________________" << endl;
        cout << "***************************************************" << endl;

        comando1 = getInput<int>();

        switch (comando1)
        {
        case 1:
        {
            cout << "Digite o nome do livro:" << endl;
            nome_livro = getString();
            cout << "Código do Livro :" << endl;
            codigo_livro = getInput<int>();
            cout << "Digite a categoria do livro:" << endl;
            categoria = getString();
            string route = "file/estoque/" + categoria;

            mkdir(route.c_str(), 0700);
            cout << "Quantidade a ser adicionada:" << endl;
            quantidade = getInput<int>();
            cout << "Valor do produto (R$):" << endl;
            valor = getInput<double>();

            livro.push_back(new Livro(nome_livro, codigo_livro, categoria, valor, quantidade));

            outfile.open("file/estoque/" + categoria + "/" + to_string(codigo_livro) + "");

            for (Livro *l : livro)
            {
                l->salva_dados();
                outfile << l->salva_dados();
            }
            outfile.close();
            livro.clear();

            break;
        }
        case 2:

            cout << "Digite a categoria do livro:" << endl;
            l.lista_categoria();
            categoria = l.verifica_categoria();
            cout << "Digite o código do livro:" << endl;
            l.lista_livro(categoria);
            codigo_livro = l.verifica_livro(categoria);
            cout << "Novo valor do produto (R$):" << endl;
            valor = getInput<double>();
            arquivo.modifica_preco("file/estoque/" + categoria + "/" + to_string(codigo_livro) + "", valor);
            break;
        case 0:
            break;

        default:
            cout << "Opção inválida" << endl;
            break;
        }
    }
}

void Inicio::modo_recomenda()
{
    Cliente cliente;
    string nome;
    string cpf;
    cout << "___________________Modo recomenda__________________" << endl;
    cout << "Digite o seu nome:" << endl;
    nome = getString();
    cout << "Digite o seu CPF: (Apenas números)" << endl;
    cpf = cliente.verifica_cpf();
    cin.clear();

    if (cliente.verifica_cliente(cpf))
    {
        cout << "---------------------------------------------------" << endl;
        cout << "      Seja bem-vindo novamente, " + nome + " !!" << endl;
        cout << "---------------------------------------------------" << endl;

        Recomenda recomenda;
        recomenda.recomendados(cpf);

        int aux = -1;
        while (aux != 0)
        {
            cout << "***************************************************" << endl;
            cout << " 0 - _____________________Sair____________________" << endl;
            cout << "***************************************************" << endl;

            aux = getInput<int>();
            switch (aux)
            {
            case 0:

                break;

            default:
                cout << "Opção inválida" << endl;
                break;
            }
        }
    }

    else
    {
        cout << "Esta opção não é válida para clientes não cadastrados" << endl;
    }
}
