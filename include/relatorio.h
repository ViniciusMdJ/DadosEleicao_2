#ifndef RELATORIO_H
#define RELATORIO_H

#include "TSE.h"

/**
 * @brief Imprime o número de vagas da eleição.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void numeroVagas(TSE& tse);

/**
 * @brief Imprime os candidatos eleitos.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void candidatosEleitos(TSE& tse);

/**
 * @brief Imprime os candidatos que seriam eleitos se fosse votação majoritatria.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void candidatosMaisVotados(TSE& tse);


/**
 * @brief Imprime os candidatos que não foram eleitos pela votação ser proporcional.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void candidatosPrejudicados(TSE& tse);

/**
 * @brief Imprime os candidatos que se beneficiaram pela eleição proporcional.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void candidatosBeneficiados(TSE& tse);

/**
 * @brief Imprime os votos de cada partido e com a quantidade de candidatos eleitos.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void votosTotalizadosPartidoQtdCandidatosEleitos(TSE& tse);

/**
 * @brief Imprime cada partido onrdenado por votos de legenda.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void votosLegenda(TSE& tse);

/**
 * @brief Imprime o candidatos mais votado e menos votado de cada partido.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void primeiroUltimoCandidato(TSE& tse);

/**
 * @brief Imprime a distribuição dos candidatos eleitos por faixa etária.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void distribuicaoEleitosFaixaEtaria(TSE& tse);

/**
 * @brief Imprime a quantidade de candadatos eleitos por sexo.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void distribuicaoEleitosSexo(TSE& tse);

/**
 * @brief Imprime o total de votos, total de votos nominais e total de votos de legenda, com porcentagem da legenda e nominais.
 * 
 * @param tse Objeto que contem todos os partidos e candidatos cadastrados.
 */
void totalVotos(TSE& tse);

#endif//RELATORIO_H