#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>
#include <list>

class Aresta {
    private:
        double pesoAresta;
        int id_No;
    public:
        Aresta(int idNo, double peso);
        ~Aresta();
        float getPesoAresta();
        int getIDNo();
        void setPesoAresta(double);
};

#endif // ARESTA_H
