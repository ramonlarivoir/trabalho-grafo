#include "Aresta.h"

Aresta::Aresta() {
    this->pesoAresta    = 0;
    this->id_No         = 0;
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
