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
void imprimeFormatoPartido() const;

enumCandidato::DestinoVoto getDestinoVoto() const;
enumCandidato::Situacao getSituacao() const;
enumCandidato::Sexo getSexo() const;
int getNumeroPartido() const;
int getVotosNominais() const;
time_t getDataNasc() const;

void setPartido(const Partido* p);

int calculaIdade(time_t atual) const;



};

bool compareCandidatos(Candidato& candidato1, Candidato& candidato2);

#endif