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

using namespace std;

int main(int argc, char const *argv[]){

    if(argc != 4){
        cout << "Quantidade de argumentos inválida" << endl;
        exit(1);
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
    
    cout << endl;
    distribuicaoEleitosSexo(tse);
    cout << endl;
    totalVotos(tse);


    return 0;
}
