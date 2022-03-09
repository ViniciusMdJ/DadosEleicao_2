using namespace std;
#include <iostream> 
#include <stdio.h>
#include <string>
#include <vector>

#include "../include/arquivos.h"
#include "../include/partidos.h"
#include "../include/candidatos.h"
#include "../include/TSE.h"

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

    vector<Candidato> eleitos;
    tse.getCandidatosEleitos(eleitos);

    cout << endl << "candidatos eleitos:" << endl;
    for(Candidato i : eleitos){
        i.println();
    }

    cout << "enum ELEITO: " << enumCandidato::ELEITO << endl;

    return 0;
}
