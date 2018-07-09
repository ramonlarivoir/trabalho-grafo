#ifndef NO_H
#define NO_H

#include <iostream>
#include <list>
#include "Aresta.h"

using namespace std;

class No {
    private:
        int id;
        float pesoNo;
        list<Aresta*> listaAresta;
        int grau;
        int grauEntrada;
        int grauSaida;
    public:
        No(int id);
        ~No();
        int getID();
        float getPeso();
        list<Aresta*> getListaAresta();
        int getGrau();
        int getGrauEntrada();
        int getGrauSaida();
        Aresta* getAresta(int idNo);
        void setPeso(float);
        void setListaAresta(list<Aresta*>);
        void setGrau(int);
        void setGrauEntrada(int);
        void setGrauSaida(int);
        void aumentaGrau();
        void aumentaGrauEntrada();
        void aumentaGrauSaida();
        void diminuiGrau();
        void diminuiGrauEntrada();
        void diminuiGrauSaida();
        void insereAresta(No*, int);
        void removeAresta(No*);
        void vizinhancaAberta();
        void vizinhancaFechada();
};

#endif // NO_H
