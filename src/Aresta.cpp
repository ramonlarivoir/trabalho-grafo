#include "Aresta.h"

Aresta::Aresta(int id_No, double peso) {
    this->pesoAresta    = peso;
    this->id_No         = id_No;
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

void  Aresta::setPesoAresta(double peso) {
    this->pesoAresta = peso;
}
