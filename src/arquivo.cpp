#include "arquivo.hpp"
#include <bits/stdc++.h>

using namespace std;

Arquivo::Arquivo()
{
}
Arquivo::~Arquivo()
{
}

string Arquivo::retorna_linha(string path, int linha)
{
	string aux;
	string conteudo;
	int i = 1;
	ifstream infile;
	infile.open(path);
	while (!infile.eof())
	{
		cout << "";
		getline(infile, aux);
		if (i == linha)
		{
			conteudo = aux;
		}
		i++;
	}
	infile.close();
	return conteudo;
}

void Arquivo::modifica_preco(string path, double novo_preco)
{
	ifstream outfile;
	ofstream infile;
	int i = 1;
	infile.open(path, ios::in);
	outfile.open(path, ios::app);
	string line;
	while (getline(outfile, line))
	{
		if (i > 4)
		{
			break;
		}
		if (i != 3)
		{
			infile << line << '\n';
		}
		if (i == 3)
		{
			infile << novo_preco << '\n';
		}

		i++;
	}

	outfile.close();
	outfile.close();
}

void Arquivo::modifica_quantidade(string path, int nova_quantidade)
{
	ifstream outfile;
	ofstream infile;
	int i = 1;
	infile.open(path, ios::in);
	outfile.open(path, ios::app);
	string line;
	while (getline(outfile, line))
	{
		if (i > 5)
		{
			break;
		}
		if (i != 4)
		{
			infile << line << '\n';
		}
		if (i == 4)
		{
			infile << nova_quantidade << '\n';
		}
		i++;
	}

	outfile.close();
	outfile.close();
}