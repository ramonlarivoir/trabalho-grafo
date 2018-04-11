#ifndef GRAFO_H
#define GRAFO_H

# include <iostream>
#include "No.h"

class Grafo {
    private:
        int ordem;
        int grauGrafo;
        int numArestas;
        No *listaNos;
    public:
        Grafo();
        ~Grafo();
        No* getListaNos();
        int getOrdem();
        int getGrau();
        int getNumArestas();
        void setListaNos(No*);
};

#endif // GRAFO_H
