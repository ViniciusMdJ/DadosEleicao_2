#include "../include/TSE.h"
#include "../include/DateUtils.h"
#include "../include/arquivos.h"
#include "../include/Excecoes/arquivoNotFound.h"
#include "../include/Excecoes/invalidDate.h"

#include <iostream>
#include <string>

using namespace std;
using namespace cpp_util;

TSE::TSE(string &arqCandidatos, string &arqPartidos, string &dataEleicao)
{
    try
    {
        if (!validDate(dataEleicao, DATE_FORMAT_PT_BR_SHORT))
        {
            throw invalidDate();
        }

        this->dataEleicao = parseDate(dataEleicao, DATE_FORMAT_PT_BR_SHORT);
    ;

            this->qtdVagas = 0;
            leArquivoPartidos(arqPartidos, this->partidos);

        vector<Candidato> candidatos;
        leArquivoCandidatos(arqCandidatos, candidatos);
        
        for(Candidato i : candidatos){
            if(i.getDestinoVoto() == enumCandidato::VALIDO){
                for(Partido& j : this->partidos){
                    if(j.verificaCandidato(i)){
                        j.cadastraCandidato(i);
                        break;
                    }
                }
            }

            for (Partido i : partidos)
            {
                qtdVagas += i.getQtdEleitos();
            }
        }
    }
    catch (invalidDate)
    {
        throw invalidDate();
    }
    catch (arqNotFound)
    {
        throw arqNotFound();
    }
}

void TSE::getCandidatosEleitos(vector<Candidato> &listaCandidatosEleitos)
{
    for (Partido i : this->partidos)
    {
        i.getCandidatosEleitos(listaCandidatosEleitos);
    }
}

void TSE::getAllCandidatos(vector<Candidato> &listaCandidatos)
{

    for (Partido i : this->partidos)
    {
        for (Candidato j : i.getListaCandidatos())
        {
            listaCandidatos.push_back(j);
        }
    }
}

vector<Partido> &TSE::getListaPartidos()
{
    return this->partidos;
}

int TSE::getQtdVagas()
{
    return this->qtdVagas;
}

time_t TSE::getDataEleicao()
{
    return this->dataEleicao;
}