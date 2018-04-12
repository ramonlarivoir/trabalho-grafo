#ifndef NO_H
#define NO_H

# include <iostream>
#include "Aresta.h"

class No {
    private:
        int id;
        float pesoNo;
        No *proxNo;
        Aresta* listaAresta;
        int grau;
        int grauEntrada;
        int grauSaida;
        Aresta* cabeca;
    public:
        No(int id);
        ~No();
        int getID();
        float getPeso();
        No* getProxNo();
        Aresta* getListaAresta();
        int getGrau();
        int getGrauEntrada();
        int getGrauSaida();
        void setPeso(float);
        void setProxNo(No*);
        void setListaAresta(Aresta*);
        void setGrau(int);
        void setGrauEntrada(int);
        void setGrauSaida(int);
        void aumentaGrau();
        void aumentaGrauEntrada();
        void aumentaGrauSaida();
        void diminuiGrau();
        void diminuiGrauEntrada();
        void diminuiGrauSaida();
        void insereAresta(No*);
        void removeAresta(No*);
};

#endif // NO_H
