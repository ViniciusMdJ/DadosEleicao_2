#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "../include/Tokenizer.h"
#include "../include/DateUtils.h"
#include "../include/Excecoes/arquivoNotFound.h"
#include "../include/Excecoes/invalidDate.h"

#include "../include/partidos.h"
#include "../include/candidatos.h"

using namespace cpp_util;
using namespace std;

void leArquivoCandidatos(string nomeArq, vector<Candidato> &candidatos)
{
    ifstream arq(nomeArq);
    if (!arq.is_open())
    {
        throw arqNotFound();
    }

    string aux;
    getline(arq, aux);

    while (!arq.eof())
    {
        getline(arq, aux);
        Tokenizer separa(aux, ',');
        vector<string> separado = separa.remaining();

        if (separado.size() != 9)
        {
            break;
        }

        if (!validDate(separado[6], DATE_FORMAT_PT_BR_SHORT))
        {
            throw invalidDate();
        }
        Candidato cand(stoi(separado.at(0)), stoi(separado.at(1)), separado.at(2), separado.at(3), separado.at(4), separado.at(5), parseDate(separado.at(6), DATE_FORMAT_PT_BR_SHORT), separado.at(7), stoi(separado.at(8)));

        candidatos.push_back(cand);
    }
}

void leArquivoPartidos(string nomeArq, vector<Partido> &partidos)
{
    ifstream arq(nomeArq);
    if (!arq.is_open())
    {
        throw arqNotFound();
    }

    string aux;
    getline(arq, aux);

    while (!arq.eof())
    {
        getline(arq, aux);
        Tokenizer separa(aux, ',');
        vector<string> separado = separa.remaining();
        if (separado.size() != 4)
        {
            break;
        }

        Partido part(stoi(separado.at(0)), stoi(separado.at(1)), separado.at(2), separado.at(3));

        partidos.push_back(part);
    }
}