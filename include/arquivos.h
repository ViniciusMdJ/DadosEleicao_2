#ifndef ARQUIVOS_H
#define ARQUIVOS_H

using namespace std;

#include <iostream>
#include <string>
#include <vector>

#include "../include/partidos.h"
#include "../include/candidatos.h"


void leArquivoCandidatos(string nomeArq, vector<Candidato>& candidatos);

void leArquivoPartidos(string nomeArq, vector<Partido>& partidos);

#endif//ARQUIVOS_H