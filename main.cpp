#include <iostream>
#include <algorithm>

#include "No.h"
#include "Aresta.h"
#include "Grafo.h"
#include "LeitorArquivoGrafo.h"

using namespace std;

int main() {

    Grafo* g = new Grafo();
    LeitorArquivoGrafo l;
    l.leituraArquivo("DGRP_LAP_0_3000_1.txt", *g);
   // g->nulo();
   // g->informaOrdem();
   // g->trivial();
   // g->grafoSimplesCompleto();
  /*  g->imprimeLista();
    int i;
    for(i = 1; i <= g->getOrdem(); i++) {
        cout<< endl << endl << "id: " << g->getNo(i)->getID() << endl;
        g->getNo(i)->vizinhancaAberta();
    } */
   //g->sequenciaGrau();
    cout << endl;
   //g->sequenciaGrauEntrada();
    cout << endl;
    //g->sequenciaGrauSaida();

    cout << g->dijkstra(2, 4764) << endl;

    return 0;
}
