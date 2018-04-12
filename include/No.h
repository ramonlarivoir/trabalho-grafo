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
    public:
        No(int id);
        ~No();
        int getID();
        float getPeso();
        No* getProxNo();
        Aresta* getListaAresta();
        void setPeso(float);
        void setProxNo(No*);
        void setListaAresta(Aresta*);
};

#endif // NO_H
