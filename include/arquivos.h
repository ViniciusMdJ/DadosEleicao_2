#ifndef ARQUIVOS_H
#define ARQUIVOS_H

using namespace std;

#include <iostream>
#include <string>
#include <list>

#include "../include/partidos.h"
#include "../include/candidatos.h"


list<Candidato> leArquivoCandidatos(string nomeArq);


#endif//ARQUIVOS_H