using namespace std;
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "../include/arquivos.h"
#include "../include/partidos.h"
#include "../include/candidatos.h"
#include "../include/TSE.h"
#include "../include/relatorio.h"
#include "../include/Excecoes/arquivoNotFound.h"
#include "../include/Excecoes/invalidDate.h"
#include "../include/Excecoes/invalidArguments.h"

using namespace std;

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 4)
        {
            throw invalidArgs();
        }
        string arcCandidato(argv[1]);
        string arcPartidos(argv[2]);
        string dataEleicao(argv[3]);
        TSE tse(arcCandidato, arcPartidos, dataEleicao);

        numeroVagas(tse);
        cout << endl;
        candidatosEleitos(tse);
        cout << endl;
        candidatosMaisVotados(tse);
        cout << endl;
        candidatosPrejudicados(tse);
        cout << endl;
        candidatosBeneficiados(tse);
        cout << endl;
        votosTotalizadosPartidoQtdCandidatosEleitos(tse);
        cout << endl;
        votosLegenda(tse);
        cout << endl;
        primeiroUltimoCandidato(tse);
        cout << endl;
        distribuicaoEleitosFaixaEtaria(tse);
        cout << endl;
        distribuicaoEleitosSexo(tse);
        cout << endl;
        totalVotos(tse);
        cout << endl;
    }
    catch (arqNotFound e)
    {
        cout << e;
    }
    catch (invalidDate e)
    {
        cout << e;
    }
    catch (invalidArgs e)
    {
        cout << e;
    }
    return 0;
}
