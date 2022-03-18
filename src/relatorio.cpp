#include "../include/TSE.h"
#include "../include/relatorio.h"
#include "../include/candidatos.h"
#include "../include/partidos.h"
#include "../include/NumberUtils.h"
#include "../include/DateUtils.h"

#include <iostream>
#include <algorithm>

using namespace std;
using namespace cpp_util;

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

void candidatosPrejudicados(TSE& tse) {
	vector<Candidato> listaCandidatos;
	tse.getAllCandidatos(listaCandidatos);

	sort(listaCandidatos.begin(), listaCandidatos.end(), compareCandidatos);

	cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl << "(com sua posição no ranking de mais votados)" << endl;
	for (int i = 1; i <= tse.getQtdVagas(); i++) {
		if (listaCandidatos.at(i - 1).getSituacao() != enumCandidato::ELEITO) {
			cout << i << " - ";
			listaCandidatos.at(i - 1).println();
		}
	}
}

void candidatosBeneficiados(TSE& tse) {
	vector<Candidato> listaCandidatos;
	tse.getAllCandidatos(listaCandidatos);

	sort(listaCandidatos.begin(), listaCandidatos.end(), compareCandidatos);

	cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
	cout << "(com sua posição no ranking de mais votados)" << endl;
	// verifica quantos candidatos dentro da quantidade de eleitos foram
	// prejudicados por se eleição proporcional
	int qtdBeneficiados = 0;
	for (int i = 0; i < tse.getQtdVagas(); i++) {
		if (listaCandidatos.at(i).getSituacao() != enumCandidato::ELEITO) {
			qtdBeneficiados++;
		}
	}
	// imprime os candidatos eleitos a partir do indice qtdEleitos da lista.
	for (int i = tse.getQtdVagas(); i < listaCandidatos.size() && qtdBeneficiados > 0; i++) {
		if (listaCandidatos.at(i).getSituacao() == enumCandidato::ELEITO) {
			cout << (i + 1) << " - ";
			listaCandidatos.at(i).println();
			qtdBeneficiados--;
		}
	}
}

void votosTotalizadosPartidoQtdCandidatosEleitos(TSE& tse) {
	vector<Partido> listaPartidos = tse.getListaPartidos();
	cout << "Votação dos partidos e número de candidatos eleitos:" << endl;
	sort(listaPartidos.begin(), listaPartidos.end(), ComparaVotosTotalizados);
	
	int i = 1;
	for (Partido j : listaPartidos) {
		cout << i << " - ";
		j.print();
		cout << ", " << (j.getVotosLegenda() + j.getNominaisTotais());
		if (j.getVotosLegenda() + j.getNominaisTotais() <= 1) {
			cout << " voto";
		} else {
			cout << " votos";
		}
		cout << " (" << j.getNominaisTotais();
		if (j.getNominaisTotais() <= 1) {
		cout <<" nominal e " << j.getVotosLegenda() << " de legenda), ";
		} else {
			cout << " nominais e " << j.getVotosLegenda() << " de legenda), ";
		}

		if (j.getQtdEleitos() <= 1)
			cout << j.getQtdEleitos() << " candidato eleito" << endl;
		else
			cout << j.getQtdEleitos() << " candidatos eleitos" << endl;

		i++;
	}
}

void votosLegenda(TSE& tse) {
	cout << "Votação dos partidos (apenas votos de legenda):" << endl;
	vector<Partido> listaPartidos = tse.getListaPartidos();
	sort(listaPartidos.begin(), listaPartidos.end(), ComparaVotosLegenda);
	int i = 1;
	for (Partido j : listaPartidos) {
		cout << i <<  " - ";
		j.print();
		cout << ", " << j.getVotosLegenda();
		if (j.getVotosLegenda() <= 1) {
			cout << " voto de legenda (";
		} else {
			cout << " votos de legenda (";
		}
		if (j.getVotosLegenda() + j.getNominaisTotais() != 0) {
			double por100 = (100.0 * (j.getVotosLegenda() / (double)(j.getVotosLegenda() + j.getNominaisTotais())));
			cout << formatDoubleCurrency(por100, LOCALE_PT_BR) << "% do total do partido)" << endl;
		} else {
			cout << "proporção não calculada, 0 voto no partido)" << endl;
		}

		i++;
	}
}

void primeiroUltimoCandidato(TSE& tse){
	cout << "Primeiro e último colocados de cada partido:" << endl;
	vector<Partido> listaPartidos = tse.getListaPartidos();
	sort(listaPartidos.begin(), listaPartidos.end(), ComparaMaisVotado);

	int j = 1;
	for (Partido i : listaPartidos) {
		if (i.getNominaisTotais() > 0) {
			cout << j << " - ";
			i.print();
			cout << ", ";
			i.getMaisVotado().imprimeFormatoPartido();
			cout << " / ";
			i.getMenosVotado().imprimeFormatoPartido();

			cout << endl;
			j++;
		}
	}
}

void distribuicaoEleitosFaixaEtaria(TSE& tse){
	int menor30 = 0, maiorIgual30Menor40 = 0, maiorIgual40Menor50 = 0, maiorIgual50Menor60 = 0, maiorIgual60 = 0;
	int idade = 0;
	vector<Candidato> listaCandidatosEleitos;
	tse.getCandidatosEleitos(listaCandidatosEleitos);
	sort(listaCandidatosEleitos.begin(), listaCandidatosEleitos.end(), compareCandidatos);
	int qtdVagas = tse.getQtdVagas();
	for (Candidato i : listaCandidatosEleitos) {
		idade = i.calculaIdade(tse.getDataEleicao());
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
		cout << "      Idade < 30: " << menor30 << " (" << formatDoubleCurrency((((double) (menor30 + 0.0) / qtdVagas) * 100.0), LOCALE_PT_BR) << "%)" << endl;
		cout << "30 <= Idade < 40: " << maiorIgual30Menor40 << " (" << formatDoubleCurrency((((double) (maiorIgual30Menor40 + 0.0) / qtdVagas) * 100.0), LOCALE_PT_BR) << "%)" << endl;
		cout << "40 <= Idade < 50: " << maiorIgual40Menor50 << " (" << formatDoubleCurrency((((double) (maiorIgual40Menor50 + 0.0) / qtdVagas) * 100.0), LOCALE_PT_BR) << "%)" << endl;
		cout << "50 <= Idade < 60: " << maiorIgual50Menor60 << " (" << formatDoubleCurrency((((double) (maiorIgual50Menor60 + 0.0) / qtdVagas) * 100.0), LOCALE_PT_BR) << "%)" << endl;
		cout << "60 <= Idade     : " << maiorIgual60 << " (" << formatDoubleCurrency((((double) (maiorIgual60 + 0.0) / qtdVagas) * 100.0), LOCALE_PT_BR) << "%)" << endl;
	} else {
		cout << "proporções não calculadas" << endl;
	}
}
	
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
		cout << "Feminino:  " << qtdFem << " (" << formatDoubleCurrency((((double) (qtdFem + 0.0) / tse.getQtdVagas()) * 100.0), LOCALE_PT_BR) << "%)" << endl;
		cout << "Masculino: " << qtdMas << " (" << formatDoubleCurrency((((double) (qtdMas + 0.0) / tse.getQtdVagas()) * 100.0), LOCALE_PT_BR) << "%)" << endl;
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
		cout << " (" << formatDoubleCurrency((((double) (qtdNominais + 0.0) / (qtdLegenda + qtdNominais)) * 100.0), LOCALE_PT_BR) << "%)" << endl;
	} else {
		cout << " (proporção não calculada)" << endl;
	}
	cout << "Total de votos de legenda: " << qtdLegenda;
	if (qtdLegenda + qtdNominais != 0) {
		cout  << " (" << formatDoubleCurrency((((double) (qtdLegenda + 0.0) / (qtdLegenda + qtdNominais)) * 100.0), LOCALE_PT_BR) << "%)" << endl;
	} else {
		cout << " (proporção não calculada)" << endl;
	}


}