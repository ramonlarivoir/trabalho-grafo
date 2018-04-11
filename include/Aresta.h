#ifndef ARESTA_H
#define ARESTA_H

# include <iostream>


class Aresta {
    private:
        float pesoAresta;
        int id_No;
        Aresta *proxAresta;
    public:
        Aresta();
        ~Aresta();
        float getPesoAresta();
        int getIDNo();
        Aresta* getProxAresta();
        void setPesoAresta(float);
        void setProxAresta(Aresta*);
};

#endif // ARESTA_H
