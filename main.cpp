#include <iostream>

#include "No.h"
#include "Aresta.h"
#include "Grafo.h"

using namespace std;

int main() {

    No* no1 = new No(1);
    No* no2 = new No(2);
    No* no3 = new No(3);

    Grafo* g = new Grafo();

    g->insereNo(no1);
    g->insereNo(no2);
    g->insereNo(no3);

    g->imprimeLista();

    cout << "grau 1: " <<no1->getGrau() << endl;

    no1->insereAresta(no2);
    cout << "grau 1: " <<no1->getGrau() << endl;
    no1->insereAresta(no3);
    cout << "grau 1: " <<no1->getGrau() << endl;

    cout << "N� 1: " <<no1->getListaAresta()->getProxAresta()->getIDNo() << endl;

    return 0;
}
