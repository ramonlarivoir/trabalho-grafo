#include "Aresta.h"

Aresta::Aresta(int id_No) {
    this->pesoAresta    = 0;
    this->id_No         = id_No;
    this->proxAresta    = NULL;
}

Aresta::~Aresta() {
    //dtor
}

float Aresta::getPesoAresta() {
    return this->pesoAresta;
}

int Aresta::getIDNo() {
    return this->id_No;
}

Aresta* Aresta::getProxAresta() {
    return this->proxAresta;
}

void  Aresta::setPesoAresta(float peso) {
    this->pesoAresta = peso;
}

void Aresta::setProxAresta(Aresta* prox) {
    this->proxAresta = prox;
}
