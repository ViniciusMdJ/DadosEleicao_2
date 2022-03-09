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
void cadastraCandidato(Candidato& cand);

int getQtdEleitos() const;

void print() const;
void println() const;

void getCandidatosEleitos(vector<Candidato>& lista) const;

vector<Candidato> getListaCandidatos() const;

int getVotosLegenda() const;

int getNominaisTotais() const;

int getNumero() const;

string getSigla() const;

Candidato& getMaisVotado();

Candidato& getMenosVotado();

};

bool ComparaVotosTotalizados(Partido& o1, Partido& o2);

bool ComparaVotosLegenda(Partido& o1, Partido& o2);

bool ComparaMaisVotado(Partido& o1, Partido& o2);

#endif//PARTIDOS_H