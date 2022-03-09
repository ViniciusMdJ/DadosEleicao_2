#include "../include/partidos.h"
#include "../include/StringUtils.h"
#include <iostream>


using namespace cpp_util;

Partido::Partido(int numero, int votosLegenda, string& nome, string& sigla){
    this->numero = numero;
    this->votosLegenda = votosLegenda;
    this->nome = ltrim(nome);
    this->sigla = ltrim(sigla);
    
    this->votosNominaisTotais = 0;
    this->qtdEleitos = 0;
    this->listaCandidatos;
}


void Partido::print() const{
    cout << numero << " " << votosLegenda << " " << nome << " " << sigla << " qtdEleitos = " << qtdEleitos << " Votos nominais = " << votosNominaisTotais;
}

void Partido::println() const{
    this->print();
    cout << endl;
}

bool Partido::verificaCandidato(const Candidato& cand) const{
    if(cand.getNumeroPartido() == this->numero) return true;
    else return false;
}

void Partido::cadastraCandidato(Candidato& cand){
    this->votosNominaisTotais += cand.getVotos();

    if(cand.getSituacao() == enumCandidato::ELEITO){
        this->qtdEleitos++;
    }
    //cout << "cadastrou no partido: ";
    //this->println();

    cand.setPartido(this);
    this->listaCandidatos.push_back(cand);
}

int Partido::getQtdEleitos() const{
    return this->qtdEleitos;
    
}

void Partido::getCandidatosEleitos(vector<Candidato>& lista) const{
    int qtdEleitosRestante = this->qtdEleitos;
    for(Candidato i : listaCandidatos){
        if(qtdEleitosRestante == 0) break;

        if(i.getSituacao() == enumCandidato::ELEITO){
            lista.push_back(i);
            qtdEleitosRestante--;
        }
    }
}

vector<Candidato> Partido::getListaCandidatos(){
    return listaCandidatos;
}