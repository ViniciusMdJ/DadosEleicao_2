#include "../include/candidatos.h"
#include "../include/partidos.h"
#include "../include/DateUtils.h"
#include "../include/StringUtils.h"
#include "../include/Tokenizer.h"
#include <iostream>
#include <time.h>
#include <ctime>


using namespace cpp_util;

Candidato::Candidato(int num, int votosNominais, string& situacao, string& nome, string& nomeUrna, string& sexo, time_t dataNasc, string& destinoVoto, int numeroPartido){
    this->numero = num;
    this->votosNominais = votosNominais;
    this->situacao = verificaSituacao(trim(situacao));
    this->nome = trim(nome);
    this->nomeUrna = trim(nomeUrna);
    this->sexo = verificaSexo(trim(sexo));
    this->dataNasc = dataNasc;
    this->destinoVoto = verificaDestinoVoto(trim(destinoVoto));
    this->numeroPartido = numeroPartido;
}

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
	int diaAtual, mesAtual, diaNasc, mesNasc;

	// Transformando as datas nos strings do formato "DD/MM/YYYY" e separando pela
	// "/"
    Tokenizer separaNasc(formatDate(dataNasc, DATE_FORMAT_PT_BR_SHORT), '/');
    Tokenizer separaAtual(formatDate(atual, DATE_FORMAT_PT_BR_SHORT), '/');
    vector<string> separadoAtual = separaAtual.remaining();
	vector<string> separadoNasc = separaNasc.remaining();

	diaAtual = stoi(separadoAtual[0]);
	mesAtual = stoi(separadoAtual[1]);

	diaNasc = stoi(separadoNasc[0]);
	mesNasc = stoi(separadoNasc[1]);

	int diffAnos = stoi(separadoAtual[2]) - stoi(separadoNasc[2]);
	if (mesAtual < mesNasc) {
		diffAnos--;
	} else if (mesAtual == mesNasc) {
		if (diaAtual < diaNasc) {
			diffAnos--;
		}
	}
	return diffAnos;
}

bool compareCandidatos(Candidato& candidato1, Candidato& candidato2){
	int aux = candidato2.getVotosNominais() - candidato1.getVotosNominais();
    if(aux > 0) return false;
	if (aux == 0) {
        if(candidato1.getDataNasc() - candidato2.getDataNasc() > 0) return false;
	}
	return true;
}