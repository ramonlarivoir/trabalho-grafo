#ifndef GRAFO_H
#define GRAFO_H

# include <iostream>
# include <algorithm>

#include "No.h"
#include <list>

using namespace std;

class Grafo {
    private:
        int ordem;
        int grauGrafo;
        int numArestas;
        std::list<No*> listaNos;
    public:
        Grafo();
        ~Grafo();
        std::list<No*> getListaNos();
        int getOrdem();
        int getGrau();
        int getNumArestas();
        No* getNo(int);
        void setListaNos(list<No*>);
        void setOrdem(int);
        void insereNo(No*);
        void removeNo(No*);
        void imprimeLista();
        void insereArestaNos(No*, No*);
        void informaOrdem();
        void trivial();
        void nulo();
        void vizinhancaAbertaNo(int idNo);
        void vizinhancaFechadaNo(int idNo);
        void grafoSimplesCompleto();
        void sequenciaGrau();
};

#endif // GRAFO_H
