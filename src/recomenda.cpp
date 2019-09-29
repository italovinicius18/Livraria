#include "recomenda.hpp"
#include "socio.hpp"
#include "arquivo.hpp"

#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

bool sortbysec(const pair<string, int> &a, const pair<string, int> &b)
{
    return (a.second > b.second);
}

void Recomenda::recomendados(string cpf)
{
    Arquivo arquivo;
    Socio socio;
    ifstream infile;
    vector<string> compras;
    vector<string> categorias;
    int aux = 0;
    string line;
    if (socio.verifica_socio(cpf))
    {
        infile.open("file/socios/" + cpf + ".txt");
    }
    else
    {
        infile.open("file/clientes/" + cpf + ".txt");
    }
    while (!infile.eof())
    {
        aux++;
        if (aux > 5)
        {
            getline(infile, line);
            compras.push_back(line);
        }
    }

    struct dirent *entry;
    string path = "file/estoque";
    DIR *dir = opendir(path.c_str());

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != 46)
        {
            categorias.push_back(entry->d_name);
        }
    }
    closedir(dir);

    int freq;
    int temp=0;
    vector<pair<string, int>> TQ; //Tema e Quantidade comprada
    string favorito;
    vector<string> indicados;
    for (string aux : categorias)
    {
        freq = count(compras.begin(), compras.end(), aux);
        if(freq>0){
        TQ.push_back(make_pair(aux, freq));
        temp++;
        }
    }

    sort(TQ.begin(), TQ.end(), sortbysec);

    vector<string> recomendados; 
    vector<string> mais_comprados;
    for (int i=0;i<temp;i++){
        cout<<TQ[i].first<<endl;
        mais_comprados.push_back(TQ[i].first);
    }
    
    int contador = 1;
    temp = 1;
    for (string i : mais_comprados)
    {
        if(contador == (10+temp)){
            break;
        }
        recomendados.push_back(i);
        temp++;
        string path = "file/estoque/"+i;
        DIR *dir = opendir(path.c_str());
        while ((entry = readdir(dir)) != NULL)
        {
            if (entry->d_name[0] != 46 and find (compras.begin(), compras.end(), entry->d_name) == compras.end())
            {
                recomendados.push_back(arquivo.retorna_linha("file/estoque/"+i+"/"+entry->d_name,1));
                contador++;
            }
        }
        closedir(dir);
    }
    
    cout<< "Estes são os mais indicados pra você por ordem de recomendação:" <<endl;
    for (string aux: recomendados){
        cout<<aux<<endl;
    }
    recomendados.clear();
}