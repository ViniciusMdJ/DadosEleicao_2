#include "../include/candidatos.h"
#include "../include/DateUtils.h"
#include "../include/StringUtils.h"
#include <iostream>


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
    cout << this->numero << " " << this->votosNominais << " " << this->nome << " situação: " << this->situacao << " " << this->nomeUrna << " " << cpp_util::formatDate(this->dataNasc, cpp_util::DATE_FORMAT_PT_BR_SHORT) << " " << this->destinoVoto << " " << this->numeroPartido;
}

void Candidato::println() const{
    this->print();
    cout << endl;
}

enumCandidato::DestinoVoto Candidato::getDestinoVoto() const{
    return this->destinoVoto;
}

int Candidato::getNumeroPartido() const{
    return this->numeroPartido;
}

int Candidato::getVotos() const{
    return this->votosNominais;
}

enumCandidato::Situacao Candidato::getSituacao() const{
    return this->situacao;
}

void Candidato::setPartido(const Partido *p){
    this->partido = p;
}