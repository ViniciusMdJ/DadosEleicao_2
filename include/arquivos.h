#ifndef ARQUIVOS_H
#define ARQUIVOS_H

using namespace std;

#include <iostream>
#include <string>
#include <vector>

#include "../include/partidos.h"
#include "../include/candidatos.h"


vector<Candidato*> leArquivoCandidatos(string nomeArq);


#endif//ARQUIVOS_H