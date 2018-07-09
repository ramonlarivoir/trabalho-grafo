#ifndef GRAFO_H
#define GRAFO_H

# include <iostream>
# include <algorithm>

#include "No.h"
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo {
    private:
        int ordem;
        int grauGrafo;
        int numArestas;
        list<No*> listaNos;
    public:
        Grafo();
        ~Grafo();
        list<No*> getListaNos();
        int getOrdem();
        int getGrau();
        int getNumArestas();
        No* getNo(int);
        void setListaNos(list<No*>);
        void setOrdem(int);
        void insereNo(No*);
        void removeNo(No*);
        void imprimeLista();
        void insereArestaNos(No*, No*, int);
        void informaOrdem();
        void trivial();
        void nulo();
        void vizinhancaAbertaNo(int idNo);
        void vizinhancaFechadaNo(int idNo);
        void grafoSimplesCompleto();
        void sequenciaGrau();
        void sequenciaGrauEntrada();
        void sequenciaGrauSaida();
        int dijkstra(int orig, int dest);
};

#endif // GRAFO_H
