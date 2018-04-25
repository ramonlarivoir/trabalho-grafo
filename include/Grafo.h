#ifndef GRAFO_H
#define GRAFO_H

# include <iostream>

# include "No.h"

class Grafo {
    private:
        int ordem;
        int grauGrafo;
        int numArestas;
        No *listaNos;
        No *cabeca;
    public:
        Grafo();
        ~Grafo();
        No* getListaNos();
        int getOrdem();
        int getGrau();
        int getNumArestas();
        void setListaNos(No*);
        void insereNo(No*);
        void removeNo(No*);
        void imprimeLista();
        void insereArestaNos(No*, No*);
        void informaOrdem();
        void trivial();
        void nulo();
        void vizinhancaAbertaNo(int idNo);
};

#endif // GRAFO_H
