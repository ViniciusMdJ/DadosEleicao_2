#ifndef PARTIDOS_H
#define PARTIDOS_H

#include <vector>
#include <string>

#include "../include/candidatos.h"

using namespace std;


class Partido{

    int numero;
    int votosLegenda;
    string nome;
    string sigla;

    int votosNominaisTotais;
    int qtdEleitos;
    vector<Candidato> listaCandidatos;

    public:

    Partido(int numero, int votosLegenda, string& nome, string& sigla);

    bool verificaCandidato(const Candidato& cand) const;

    /**
     * @brief Cadastra um candidato no partido, contabilizando os votosNominaisTotais e a qtdEleitos.
     * 
     * @param candidato Candidato a ser cadastrado.
     */
    void cadastraCandidato(Candidato& cand);

    int getQtdEleitos() const;

    void print() const;
    void println() const;

    /**
     * @brief Retorna a lista de candidatos eleitos do partido.
     * 
     * @param vector<Candidato> Vector de candidatos eleitos.
     */
    void getCandidatosEleitos(vector<Candidato>& lista) const;

    vector<Candidato> getListaCandidatos() const;

    int getVotosLegenda() const;

    int getNominaisTotais() const;

    int getNumero() const;

    string getSigla() const;

    Candidato& getMaisVotado();

    Candidato& getMenosVotado();

};

/**
 * @brief Implementa um critério de comparação considerando votos de legenda e votos
 * nominais em cada partido.
 * 
 * @param o1 Primeiro partido.
 * @param o2 Segundo partido.
 * @return false se o segundo for maior que o primeiro, true senão.
 */
bool ComparaVotosTotalizados(Partido& o1, Partido& o2);

/**
 * @brief Implementa um critério de comparação a partir dos votos de legenda de cada
 * partido.
 * 
 * @param o1 Primeiro partido.
 * @param o2 Segundo partido.
 * @return false se o segundo for maior que o primeiro, true senão.
 */
bool ComparaVotosLegenda(Partido& o1, Partido& o2);

/**
 * @brief Implementa um critério de comparação a partir do candidato mais votado para
 * os partidos.
 * 
 * @param o1 Primeiro partido.
 * @param o2 Segundo partido.
 * @return false se o segundo for maior que o primeiro, true senão.
 */
bool ComparaMaisVotado(Partido& o1, Partido& o2);

#endif//PARTIDOS_H