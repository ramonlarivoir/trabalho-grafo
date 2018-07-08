#include <iostream>
#include <algorithm>

#include "No.h"
#include "Aresta.h"
#include "Grafo.h"
#include "LeitorArquivoGrafo.h"

using namespace std;

int main() {

    No* no1 = new No(1);
    No* no2 = new No(2);
    No* no3 = new No(3);

    Grafo* g = new Grafo();
    LeitorArquivoGrafo l;
    l.leituraArquivo("DGRP_LAP_0_3000_1.txt", *g);
    g->nulo();
    g->informaOrdem();
    g->trivial();
    g->grafoSimplesCompleto();
    g->imprimeLista();
    int i;
    for(i = 1; i <= g->getOrdem(); i++) {
        cout<< endl << endl << "id: " << g->getNo(i)->getID() << endl;
        g->getNo(i)->vizinhancaAberta();
    }
    cout << endl << endl << "no 10: id -> " << g->getNo(10)->getID() << endl;
    cout << "no 1: id -> " << g->getNo(1)->getID() << endl;
    cout << "no 2: id -> " << g->getNo(2)->getID() << endl;
    cout << endl;
    g->sequenciaGrau();
    //g->insereNo(no1);
    //g->nulo();
    /*g->insereNo(no2);
    g->informaOrdem();
    g->trivial();
    g->grafoSimplesCompleto();
    g->insereNo(no3);
    g->informaOrdem();

    cout<<"Confere grafo completo"<< endl;
    g->insereArestaNos(no1, no2);
    g->grafoSimplesCompleto();
    g->sequenciaGrau();
    g->insereArestaNos(no1, no3);
    g->grafoSimplesCompleto();
    g->sequenciaGrau();
    g->insereArestaNos(no2, no3);
    g->grafoSimplesCompleto(); */


  /*  g->imprimeLista();

    cout << "grau 1: " <<no1->getGrau() << endl;

    no1->insereAresta(no2);
    cout << "grau 1: " <<no1->getGrau() << endl;
    no1->vizinhancaAberta();
    g->vizinhancaAbertaNo(1);
    no1->insereAresta(no3);
    cout << "grau 1: " <<no1->getGrau() << endl;
    no1->vizinhancaAberta();
    no1->vizinhancaFechada();
    g->vizinhancaAbertaNo(1);
    g->vizinhancaFechadaNo(1);
    no3->insereAresta(no2);
    no3->vizinhancaAberta();
    g->vizinhancaAbertaNo(3);
    cout << "grau saida 1: " <<no1->getGrauSaida() << endl;
    cout << "grau saida 2: " <<no2->getGrauEntrada() << endl;
    cout << "grau saida 3: " <<no3->getGrauEntrada() << endl;

    no1->removeAresta(no2);
    cout << "grau saida 1: " <<no1->getGrauSaida() << endl;
    cout << "grau saida 3: " <<no2->getGrauEntrada() << endl;

    cout << "Nó 1: " <<no1->getListaAresta()->getIDNo() << endl;
    cout << "Nó 1: " <<no1->getListaAresta()->getProxAresta()->getIDNo() << endl; */

    return 0;
}
