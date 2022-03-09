#ifndef TSE_H
#define TSE_H

#include "partidos.h"
#include <vector>
#include <ctime>

class TSE{

    vector<Partido> partidos;
    int qtdVagas;
    time_t dataEleicao;

    public:
    TSE(string& arqCandidatos, string& arqPartidos, string& dataEleicao);

    void getCandidatosEleitos(vector<Candidato>& listaCandidatosEleitos);
    void getAllCandidatos(vector<Candidato>& listaCandidatos);

    vector<Partido> getListaPartidos();

    int getQtdVagas();

    time_t getDataEleicao();

};


#endif//TSE_H