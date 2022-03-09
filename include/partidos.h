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

vector<Candidato> getListaCandidatos();

};

#endif//PARTIDOS_H