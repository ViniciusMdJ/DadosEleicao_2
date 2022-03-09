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
    cout << sigla << " - " << numero;
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
    this->votosNominaisTotais += cand.getVotosNominais();


    if(cand.getSituacao() == enumCandidato::ELEITO){
        this->qtdEleitos++;
    }

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

vector<Candidato> Partido::getListaCandidatos() const{
    return listaCandidatos;
}

int Partido::getVotosLegenda() const{
    return votosLegenda;
}

int Partido::getNominaisTotais() const{
    return votosNominaisTotais;
}

int Partido::getNumero() const{
    return numero;
}

string Partido::getSigla() const{
    return this->sigla;
}

Candidato& Partido::getMaisVotado(){
    sort(listaCandidatos.begin(), listaCandidatos.end(), compareCandidatos);

    return listaCandidatos.front();
}

Candidato& Partido::getMenosVotado(){
	sort(listaCandidatos.begin(), listaCandidatos.end(), compareCandidatos);

    return listaCandidatos.back();
}

bool ComparaVotosTotalizados(Partido& o1, Partido& o2) {
	int aux = (o2.getVotosLegenda() + o2.getNominaisTotais()) - (o1.getVotosLegenda() + o1.getNominaisTotais());
    if(aux > 0) return false;
	if (aux == 0) {
		if(o2.getNumero() - o1.getNumero() > 0){
            return false;
        }

	}
	return true;
}

bool ComparaVotosLegenda(Partido& o1, Partido& o2){
    int aux = o2.getVotosLegenda() - o1.getVotosLegenda();
	if(aux > 0) return false;
	if (aux == 0) {
		int aux2 = o2.getNominaisTotais() - o1.getNominaisTotais();
		if(aux2 > 0) return false;
		if (aux2 == 0) {
            if(o2.getNumero() - o1.getNumero() > 0) return false;
		}
	}
    return true;
}

bool ComparaMaisVotado(Partido& o1, Partido& o2){
    Candidato& candidato1 = o1.getMaisVotado();
	Candidato& candidato2 = o2.getMaisVotado();
	// Verifica se os partidos possuem algum candidato mais votado
	// ordenando de acordo.
	if (o1.getNominaisTotais() == 0 && o2.getNominaisTotais() > 0) {
		return true;
	} else if (o2.getNominaisTotais() == 0) {
		return false;
	}
    int aux = 0;
	aux = candidato2.getVotosNominais() - candidato1.getVotosNominais();
	if (aux == 0) {
		if(o1.getNumero() - o2.getNumero() > 0){
            return false;
        }
	}
	if(aux > 0) return false;
    else return true;
}