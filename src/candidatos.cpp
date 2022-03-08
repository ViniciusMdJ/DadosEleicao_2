#include "../include/candidatos.h"
#include "../include/DateUtils.h"
#include <iostream>


Candidato::Candidato(){

}

Candidato::Candidato(const Candidato& c){

}

Candidato::Candidato(int num, int votosNominais, string& situacao, string& nome, string& nomeUrna, string& sexo, time_t dataNasc, string& destinoVoto, int numeroPartido){
    this->numero = num;
    this->votosNominais = votosNominais;
    this->situacao = verificaSituacao(situacao);
    this->nome = nome;
    this->nomeUrna = nomeUrna;
    this->sexo = verificaSexo(sexo);
    this->dataNasc = dataNasc;
    this->destinoVoto = verificaDestinoVoto(destinoVoto);
    this->numeroPartido = numeroPartido;
}

Candidato::~Candidato(){

}

void Candidato::operator=(const Candidato& c){

}

enumCandidato::Situacao Candidato::verificaSituacao(string situacao){
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

enumCandidato::Sexo Candidato::verificaSexo(string sexo){
    if(sexo.compare("M") == 0) return enumCandidato::M;
    else if(sexo.compare("F") == 0) return enumCandidato::F;
}

enumCandidato::DestinoVoto Candidato::verificaDestinoVoto(string destinoVoto){
    if(destinoVoto.compare("Válido") == 0) return enumCandidato::VALIDO;
    else return enumCandidato::INVALIDO;
}

void Candidato::print() const{
    cout << this->numero << " " << this->votosNominais << " " << this->nome << " " << this->situacao << " " << this->nomeUrna << " " << cpp_util::formatDate(this->dataNasc, cpp_util::DATE_FORMAT_PT_BR_SHORT) << " " << this->destinoVoto << " " << this->numeroPartido;
}

void Candidato::println() const{
    this->print();
    cout << endl;
}