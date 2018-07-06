#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>
#include <list>

class Aresta {
    private:
        float pesoAresta;
        int id_No;
    public:
        Aresta(int);
        ~Aresta();
        float getPesoAresta();
        int getIDNo();
        void setPesoAresta(float);
};

#endif // ARESTA_H
