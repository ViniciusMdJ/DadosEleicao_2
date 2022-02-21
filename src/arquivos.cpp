using namespace std;

#include <fstream>
#include <iostream>
#include <string>
#include <list>

//#include "../include/partidos.h"
#include "../include/candidatos.h"


list<Candidato> leArquivoCandidatos(string nomeArq){
    list<Candidato> candidatos;
    ifstream arq(nomeArq);

    string aux;
    getline(arq, aux);
    cout << aux << endl;

    return candidatos;
}