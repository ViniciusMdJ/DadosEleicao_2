using namespace std;
#include <iostream> 
#include <stdio.h>
#include <string>
#include <list>

#include "../include/arquivos.h"
//#include "../include/partidos.h"
#include "../include/candidatos.h"


int main(int argc, char const *argv[]){
    list<Candidato> teste = leArquivoCandidatos("../testes/serra/in/candidatos.csv");
    return 0;
}
