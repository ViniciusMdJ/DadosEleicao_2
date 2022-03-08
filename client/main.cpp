using namespace std;
#include <iostream> 
#include <stdio.h>
#include <string>
#include <vector>

#include "../include/arquivos.h"
#include "../include/partidos.h"
#include "../include/candidatos.h"


int main(int argc, char const *argv[]){
    vector<Candidato*> teste = leArquivoCandidatos("../teste20cand.txt");

    for(Candidato* i : teste){
        i->println();
    }
    return 0;
}
