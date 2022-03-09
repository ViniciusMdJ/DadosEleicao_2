#include "../include/TSE.h"
#include "../include/DateUtils.h"
#include "../include/arquivos.h"

#include <iostream>
#include <string>


using namespace std;
using namespace cpp_util;

TSE::TSE(string& arqCandidatos, string& arqPartidos, string& dataEleicao){

    if(!validDate(dataEleicao, DATE_FORMAT_PT_BR_SHORT)){
        cout << "Data da eleição não é valida: " << dataEleicao << endl;
        exit(1);
    }

    this->dataEleicao = parseDate(dataEleicao, DATE_FORMAT_PT_BR_SHORT);

    //cout << this->dataEleicao << endl;

    this->qtdVagas = 0;
    leArquivoPartidos(arqPartidos, this->partidos);

    vector<Candidato> candidatos;
    leArquivoCandidatos(arqCandidatos, candidatos);
    //cout << "Data nascimento 1 candidato: " << candidatos.at(0).getDataNasc() << endl;

    for(Candidato i : candidatos){
        if(i.getDestinoVoto() == enumCandidato::VALIDO){
            for(Partido& j : this->partidos){
                if(j.verificaCandidato(i)){
                    j.cadastraCandidato(i);
                    break;
                }
            }
        }
    }

    for(Partido i : partidos){
        qtdVagas += i.getQtdEleitos();
    }

}

void TSE::getCandidatosEleitos(vector<Candidato>& listaCandidatosEleitos) {
	for(Partido i : this->partidos) {
		i.getCandidatosEleitos(listaCandidatosEleitos);
	}
}

void TSE::getAllCandidatos(vector<Candidato>& listaCandidatos) {

	for (Partido i : this->partidos) {
		for (Candidato j : i.getListaCandidatos()) {
			listaCandidatos.push_back(j);
		}
	}
}

vector<Partido>& TSE::getListaPartidos() {
		return this->partidos;
	}

int TSE::getQtdVagas() {
	return this->qtdVagas;
}

time_t TSE::getDataEleicao() {
	return this->dataEleicao;
}