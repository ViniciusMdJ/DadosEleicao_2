#include "../include/candidatos.h"
#include "../include/partidos.h"
#include "../include/DateUtils.h"
#include "../include/StringUtils.h"
#include <iostream>
#include <time.h>
#include <ctime>


using namespace cpp_util;

Candidato::Candidato(int num, int votosNominais, string& situacao, string& nome, string& nomeUrna, string& sexo, time_t dataNasc, string& destinoVoto, int numeroPartido){
    this->numero = num;
    this->votosNominais = votosNominais;
    this->situacao = verificaSituacao(ltrim(situacao));
    this->nome = ltrim(nome);
    this->nomeUrna = ltrim(nomeUrna);
    this->sexo = verificaSexo(ltrim(sexo));
    this->dataNasc = dataNasc;
    this->destinoVoto = verificaDestinoVoto(ltrim(destinoVoto));
    this->numeroPartido = numeroPartido;
}

/*
Candidato::Candidato(const Candidato& c){
    *this = c;
}

void Candidato::operator=(const Candidato& c){
    this->numero = c.numero;
    this->votosNominais = c.votosNominais;
    this->situacao = c.situacao;
    this->nome = c.nome;
    this->nomeUrna = c.nomeUrna;
    this->sexo = c.sexo;
    this->dataNasc = c.dataNasc;
    this->destinoVoto = c.destinoVoto;
    this->numeroPartido = c.numeroPartido;
}*/

enumCandidato::Situacao Candidato::verificaSituacao(string& situacao){
    if(situacao.compare("Eleito") == 0){
        return enumCandidato::ELEITO;
    }
    else if(situacao.compare("Não Eleito") == 0){
        return enumCandidato::NAOELEITO;
    }
    else if(situacao.compare("Suplente") == 0){
        return enumCandidato::SUPLENTE;
    }
    //Eleito, Não Eleito, Suplente
}

enumCandidato::Sexo Candidato::verificaSexo(string& sexo){
    if(sexo.compare("M") == 0) return enumCandidato::M;
    else if(sexo.compare("F") == 0) return enumCandidato::F;
}

enumCandidato::DestinoVoto Candidato::verificaDestinoVoto(string& destinoVoto){
    if(destinoVoto.compare("Válido") == 0) return enumCandidato::VALIDO;
    else return enumCandidato::INVALIDO;
}

void Candidato::print() const{
    cout << nome << " / " << nomeUrna << " (" << partido->getSigla() << ", " << votosNominais << ((votosNominais < 2) ? " voto)" : " votos)");

        /*1 > 2 ? true : false
		if (votosNominais < 2) {
			return saida + " voto)";
		} else {
			return saida + " votos)";
		}*/
}

void Candidato::println() const{
    this->print();
    cout << endl;
}

void Candidato::imprimeFormatoPartido() const{
    cout << nomeUrna << " (" << numero << ", " << votosNominais;
	if (votosNominais <= 1) {
		cout << " voto)";
	} else {
		cout << " votos)";
	}
}

enumCandidato::DestinoVoto Candidato::getDestinoVoto() const{
    return this->destinoVoto;
}

enumCandidato::Situacao Candidato::getSituacao() const{
    return this->situacao;
}

enumCandidato::Sexo Candidato::getSexo() const{
    return sexo;
}

int Candidato::getNumeroPartido() const{
    return this->numeroPartido;
}

int Candidato::getVotosNominais() const{
    return this->votosNominais;
}

time_t Candidato::getDataNasc() const{
    return this->dataNasc;
}

void Candidato::setPartido(const Partido *p){
    this->partido = p;
}

int Candidato::calculaIdade(time_t atual) const{
    return difftime(atual, dataNasc) / 31536000;
}

bool compareCandidatos(Candidato& candidato1, Candidato& candidato2){
	int aux = candidato2.getVotosNominais() - candidato1.getVotosNominais();
    if(aux > 0) return false;
	if (aux == 0) {
        if(candidato1.getDataNasc() - candidato2.getDataNasc() > 0) return false;
	}
	return true;
}