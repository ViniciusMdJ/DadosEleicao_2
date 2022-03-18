#ifndef CANDIDATOS_H
#define CANDIDATOS_H

using namespace std;


#include <stdio.h>
#include <ctime>
#include <string>

class Partido;

namespace enumCandidato{
    enum Situacao {ELEITO, NAOELEITO, SUPLENTE};
    enum Sexo {M, F};
    enum DestinoVoto {VALIDO, INVALIDO};
}


class Candidato{


    int numero;
    int votosNominais;
    enumCandidato::Situacao situacao;
    string nome;
    string nomeUrna;
    enumCandidato::Sexo sexo;
    time_t dataNasc;
    enumCandidato::DestinoVoto destinoVoto;
    int numeroPartido;
    const Partido *partido;

    enumCandidato::Situacao verificaSituacao(string& situacao);

    enumCandidato::Sexo verificaSexo(string& sexo);

    enumCandidato::DestinoVoto verificaDestinoVoto(string& destinoVoto);

    public:
    Candidato(int num, int votosNominais, string& situacao, string& nome, string& nomeUrna, string& sexo, time_t dataNasc, string& destinoVoto, int numeroPartido);
    void print() const;
    void println() const;

    /**
     * @brief Imprime no terminal a string de impressao do candidato no formato para impressão dos partidos.
     */
    void imprimeFormatoPartido() const;

    enumCandidato::DestinoVoto getDestinoVoto() const;
    enumCandidato::Situacao getSituacao() const;
    enumCandidato::Sexo getSexo() const;
    int getNumeroPartido() const;
    int getVotosNominais() const;
    time_t getDataNasc() const;

    void setPartido(const Partido* p);

    /**
     * @brief Função utilitária que calcula os anos decorridos entre duas datas.
     * 
     * @param atual    Data final.
     * @return Inteiro da quantidade de anos decorridos.
     */
    int calculaIdade(time_t atual) const;



};

/**
 * @brief Estabelece o critério de comparação dos candidatos.
 * 
 * @param candidato Candidato a ser comparado.
 * @return false se candidato 2 deve ser trocado com candidato 1, true senão
 */
bool compareCandidatos(Candidato& candidato1, Candidato& candidato2);

#endif