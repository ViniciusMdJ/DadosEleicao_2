#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "../include/Tokenizer.h"
#include "../include/DateUtils.h"

#include "../include/partidos.h"
#include "../include/candidatos.h"

using namespace cpp_util;
using namespace std;


vector<Candidato*> leArquivoCandidatos(string nomeArq){
    vector<Candidato*> candidatos;
    ifstream arq(nomeArq);


    string aux;
    getline(arq, aux);

    while(!arq.eof()){
        getline(arq, aux);
        Tokenizer separa(aux, ',');
        vector<string> separado = separa.remaining();

        if(!validDate(separado[6], DATE_FORMAT_PT_BR_SHORT)){
            cout << "Data no formato invalido" << endl;
        }

        Candidato *cand = new Candidato(stoi(separado.at(0)), stoi(separado.at(1)), separado.at(2), separado.at(3), separado.at(4), separado.at(5), parseDate(separado.at(6), DATE_FORMAT_PT_BR_SHORT), separado.at(7), stoi(separado.at(8)));

        candidatos.push_back(cand);
    }

    return candidatos;
}

//vector<Partido*> leArquivoPartido(string nomeArq)