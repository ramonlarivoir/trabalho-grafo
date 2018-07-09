#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>
#include <list>

class Aresta {
    private:
        int pesoAresta;
        int id_No;
    public:
        Aresta(int idNo, int peso);
        ~Aresta();
        float getPesoAresta();
        int getIDNo();
        void setPesoAresta(int);
};

#endif // ARESTA_H
