#ifndef GRAFO_H
#define GRAFO_H

# include <iostream>
# include <algorithm>

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
        No* getNo(int);
        void setListaNos(No*);
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
