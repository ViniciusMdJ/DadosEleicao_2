#ifndef ARQUIVOS_H
#define ARQUIVOS_H

using namespace std;

#include <iostream>
#include <string>
#include <vector>

#include "../include/partidos.h"
#include "../include/candidatos.h"

/**
 * @brief Realiza a leitura do arquivo de candidatos, criando um vector para eles.
 * 
 * @param nomeArq Referencia para o arquivo de candidatos.
 * @return vector dos candidatos lidos no arquivo.
 */
void leArquivoCandidatos(string nomeArq, vector<Candidato>& candidatos);

/**
 * @brief Realiza a leitura do arquivo de partidos, criando um vector para eles.
 * 
 * @param nomeArq Referencia para o arquivo de partidos.
 * @param partidos vector dos partidos lidos no arquivo.
 */
void leArquivoPartidos(string nomeArq, vector<Partido>& partidos);

#endif//ARQUIVOS_H