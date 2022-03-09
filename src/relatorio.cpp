#include "../include/TSE.h"
#include "../include/relatorio.h"
#include "../include/candidatos.h"
#include "../include/partidos.h"

#include <iostream>
#include <algorithm>

using namespace std;

void numeroVagas(TSE& tse){
	cout << "Número de vagas: " << tse.getQtdVagas() << endl;
}

void candidatosEleitos(TSE& tse) {
	vector<Candidato> listaCandidatosEleitos;
    tse.getCandidatosEleitos(listaCandidatosEleitos);

	sort(listaCandidatosEleitos.begin(), listaCandidatosEleitos.end(), compareCandidatos);

	int j = 1;
	cout << "Vereadores eleitos:" << endl;
	for (Candidato candidato : listaCandidatosEleitos) {
		cout << j << " - ";
        candidato.println();
		j++;
	}
}

void candidatosMaisVotados(TSE& tse) {
	vector<Candidato> listaCandidatos;
	tse.getAllCandidatos(listaCandidatos);

	sort(listaCandidatos.begin(), listaCandidatos.end(), compareCandidatos);

	cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" <<endl;
	for (int i = 1; i <= tse.getQtdVagas(); i++) {
		cout << i << " - ";
		listaCandidatos.at(i - 1).println();
	}
}

/*void distribuicaoEleitosFaixaEtaria(TSE& tse){
	int menor30 = 0, maiorIgual30Menor40 = 0, maiorIgual40Menor50 = 0, maiorIgual50Menor60 = 0, maiorIgual60 = 0;
	int idade = 0;
	vector<Candidato> listaCandidatosEleitos;
	tse.getCandidatosEleitos(listaCandidatosEleitos);
	sort(listaCandidatosEleitos.begin(), listaCandidatosEleitos.end(), compareCandidatos);
	int qtdVagas = tse.getQtdVagas();
	for (Candidato i : listaCandidatosEleitos) {
		idade = OrdenacaoUtils.calculaIdade(i.getDataNasc(), tse.getDataEleicao());
		if (idade < 30) {
			menor30++;
		} else if (idade < 40) {
			maiorIgual30Menor40++;
		} else if (idade < 50) {
			maiorIgual40Menor50++;
		} else if (idade < 60) {
			maiorIgual50Menor60++;
		} else {
			maiorIgual60++;
		}
	}
	cout << "Eleitos, por faixa etária (na data da eleição):" << endl;
	if (tse.getQtdVagas() != 0) {
		cout << "      Idade < 30: " << menor30 << " (";
		printf("%.2f%%)\n", (((double) (menor30 + 0.0) / qtdVagas) * 100.0));
		cout << "30 <= Idade < 40: " << maiorIgual30Menor40 + " (";
		printf("%.2f%%)\n", (((double) (maiorIgual30Menor40 + 0.0) / qtdVagas) * 100.0));
		cout << "40 <= Idade < 50: " << maiorIgual40Menor50 << " (";
		printf("%.2f%%)\n", (((double) (maiorIgual40Menor50 + 0.0) / qtdVagas) * 100.0));
		cout << "50 <= Idade < 60: " << maiorIgual50Menor60 << " (";
		printf("%.2f%%)\n", (((double) (maiorIgual50Menor60 + 0.0) / qtdVagas) * 100.0));
		cout << "60 <= Idade     : " << maiorIgual60 << " (";
		printf("%.2f%%)\n", (((double) (maiorIgual60 + 0.0) / qtdVagas) * 100.0));
	} else {
		cout <<"proporções não calculadas") << endl;
	}
}*/
	
void distribuicaoEleitosSexo(TSE& tse){
    int qtdFem = 0, qtdMas = 0;
    vector<Candidato> listaCandidatosEleitos;
	tse.getCandidatosEleitos(listaCandidatosEleitos);
	sort(listaCandidatosEleitos.begin(), listaCandidatosEleitos.end(), compareCandidatos);
	for(Candidato i : listaCandidatosEleitos){
		if(i.getSexo() == enumCandidato::M) qtdMas++;
		else if(i.getSexo() == enumCandidato::F) qtdFem++;
	}

	cout << "Eleitos, por sexo:" << endl;

	if(tse.getQtdVagas() != 0){
		cout << "Feminino:  " << qtdFem;
		printf(" (%.2f%%)\n", (((double) (qtdFem + 0.0) / tse.getQtdVagas()) * 100.0));
		cout << "Masculino: " << qtdMas;
		printf(" (%.2f%%)\n", (((double) (qtdMas + 0.0) / tse.getQtdVagas()) * 100.0));
	}
	else{
		cout << "proporções não calculadas" << endl;
	}	tse.getCandidatosEleitos(listaCandidatosEleitos);
}

void totalVotos(TSE& tse){
    int qtdLegenda = 0, qtdNominais = 0;

    for(Partido i : tse.getListaPartidos()){
        qtdLegenda += i.getVotosLegenda();
        qtdNominais += i.getNominaisTotais();
    }

    cout << "Total de votos válidos:    " << (qtdLegenda + qtdNominais) << endl;
    cout << "Total de votos nominais:   " << qtdNominais;

    if (qtdLegenda + qtdNominais != 0) {
		printf(" (%.2f%%)\n", (((double) (qtdNominais + 0.0) / (qtdLegenda + qtdNominais)) * 100.0));
	} else {
		cout << " (proporção não calculada)" << endl;
	}
	cout << "Total de votos de legenda: " << qtdLegenda;
	if (qtdLegenda + qtdNominais != 0) {
		printf(" (%.2f%%)\n", (((double) (qtdLegenda + 0.0) / (qtdLegenda + qtdNominais)) * 100.0));
	} else {
		cout << " (proporção não calculada)" << endl;
	}


}