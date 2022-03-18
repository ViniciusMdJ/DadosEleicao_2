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

    /**
	 * @brief Inicializa os partidos e candidatos, além do próprio TSE.
	 * 
	 * @param arqCandidatos Nome do arquivo de candidatos.
	 * @param arqPartidos   Nome do arquivo de partidos.
	 * @param dataEleicao   Data da eleição.
	 */
    TSE(string& arqCandidatos, string& arqPartidos, string& dataEleicao);

    /**
	 * @brief Adiciona os candidatos eleitos ao vector passado como parâmetro.
     * @param listaCandidatosEleitos Referência para a lista a serem adicionados os candidatos.
	 */
    void getCandidatosEleitos(vector<Candidato>& listaCandidatosEleitos);

    /**
	 * @brief Adiciona todos os candidatos ao vector passado como parâmetro.
     * @param listaCandidatos Referência para a lista a serem adicionados os candidatos.
	 */
    void getAllCandidatos(vector<Candidato>& listaCandidatos);

    /**
     * @brief Retorna o vector com todos os partidos cadastrados.
     * 
     * @return vector<Partido>& Vector com todos os partidos.
     */
    vector<Partido>& getListaPartidos();

    int getQtdVagas();

    time_t getDataEleicao();

};


#endif//TSE_H