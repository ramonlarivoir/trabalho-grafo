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

    g->imprimeLista();

    g->removeNo(no1);
    g->removeNo(no2);

    cout << "Remove:" << endl;
    g->imprimeLista();

    return 0;
}
