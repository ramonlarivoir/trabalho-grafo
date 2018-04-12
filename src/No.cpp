#include "No.h"

No::No(int id) {
    this->id            = id;
    this->pesoNo        = 0;
    this->proxNo        = NULL;
    this->listaAresta   = NULL;
    this->grau          = 0;
    this->grauEntrada   = 0;
    this->grauSaida     = 0;
    this->cabeca        = NULL;
}

No::~No() {
    //dtor
}

int No::getID() {
    return this->id;
}

float No::getPeso() {
    return this->pesoNo;
}

No* No::getProxNo() {
    return this->proxNo;
}

Aresta* No::getListaAresta() {
    return this->listaAresta;
}

int No::getGrau() {
    return this->grau;
}

int No::getGrauEntrada() {
    return this->grauEntrada;
}

int No::getGrauSaida() {
    return this->grauSaida;
}

void No::setPeso(float peso) {
    this->pesoNo = peso;
}

void No::setProxNo(No* prox) {
    this->proxNo = prox;
}

void No::setListaAresta(Aresta* listaAresta) {
    this->listaAresta = listaAresta;
}

void No::setGrau(int grau) {
    this->grau = this->grau + grau;
}

void No::setGrauEntrada(int grauEntrada) {
    this->grauEntrada = grauEntrada;
}

void No::setGrauSaida(int grauSaida) {
    this->grauSaida = grauSaida;
}

void No::insereAresta(No* noAdj) {
    Aresta* percorre = getListaAresta();
    Aresta* novaAresta = new Aresta(noAdj->getID());
    if(cabeca==NULL) {
        cabeca = novaAresta;
        setListaAresta(cabeca);
        setGrau(1);
    } else {
        while(percorre->getProxAresta() != NULL) {
            percorre = percorre->getProxAresta();
        }
        percorre->setProxAresta(novaAresta);
        setGrau(1);
    }
}
