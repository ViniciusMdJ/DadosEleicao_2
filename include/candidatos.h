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
//Candidato(const Candidato&);
//void operator=(const Candidato&);
void print() const;
void println() const;

enumCandidato::DestinoVoto getDestinoVoto() const;
enumCandidato::Situacao getSituacao() const;
int getNumeroPartido() const;
int getVotos() const;

void setPartido(const Partido* p);



};

#endif