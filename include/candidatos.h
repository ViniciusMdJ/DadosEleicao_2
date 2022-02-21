#ifndef CANDIDATOS_H
#define CANDIDATOS_H

using namespace std;

#include <stdio.h>

class Candidato{

int numero;
int votosNominais;
//Situacao situacao;
string nome;
string nomeUrna;
//sexo sexo;
//Date dataNasc;
//DestinoVoto DestinoVoto;
int numeroPartido;
//Partido partido;

public:
Candidato();
Candidato(const Candidato&);
~Candidato();
void operator=(const Candidato&);


};

#endif