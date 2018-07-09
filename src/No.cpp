#include "No.h"

No::No(int id) {
    this->id            = id;
    this->pesoNo        = 0;
    this->listaAresta;
    this->grau          = 0;
    this->grauEntrada   = 0;
    this->grauSaida     = 0;
}

No::~No() {
    //dtor
}

/*****************************/
/*                           */
/*       GETS E SETS         */
/*                           */
/*****************************/

int No::getID() {
    return this->id;
}

float No::getPeso() {
    return this->pesoNo;
}

list<Aresta*> No::getListaAresta() {
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

void No::setListaAresta(list<Aresta*> listaAresta) {
    this->listaAresta = listaAresta;
}

void No::setGrau(int grau) {
    this->grau = grau;
}

void No::setGrauEntrada(int grauEntrada) {
    this->grauEntrada = grauEntrada;
}

void No::setGrauSaida(int grauSaida) {
    this->grauSaida = grauSaida;
}

Aresta* No::getAresta(int idNo) {
    if(listaAresta.size() == 0) {                              //verifica se a lista está vazia
        cout << "Lista de Arestas vazia" << endl;
        exit(0);
    } else {
        for(auto it = listaAresta.begin(); it != listaAresta.end(); it ++) {
            Aresta *aresta = *it;
            if(aresta->getIDNo() == idNo) {
                return aresta;
                exit(0);
            }
        }
        cout << "Aresta nao existe" << endl;
        exit(0);
    }
}

/*****************************/
/*   AUMENTO E DIMINUIÇÃO    */
/*    DOS GRAUS DOS NÓS      */
/*      EM UMA UNIDADE       */
/*****************************/

void No::aumentaGrau() {
    this->grau = this->grau + 1;
}

void No::aumentaGrauEntrada() {
    this->grauEntrada = this->grauEntrada + 1;
}

void No::aumentaGrauSaida() {
    this->grauSaida = this->grauSaida + 1;
}

void No::diminuiGrau() {
    this->grau = this->grau - 1;
}
void No::diminuiGrauEntrada() {
    this->grauEntrada = this->grauEntrada - 1;
}
void No::diminuiGrauSaida() {
    this->grauSaida = this->grauSaida - 1;
}

/***********************************/
/**                               **/
/** INCLUSÃO E REMOÇÃO DE ARESTAS **/
/**                               **/
/***********************************/

void No::insereAresta(No* noAdj, int peso) {
    Aresta *aresta = new Aresta(noAdj->getID(), peso);
    listaAresta.push_back(aresta);
    aumentaGrau();
    aumentaGrauSaida();
    noAdj->aumentaGrau();
    noAdj->aumentaGrauEntrada();
}

void No::removeAresta(No* noAdj) {
    Aresta *aresta = new Aresta(noAdj->getID(), noAdj->getPeso());
    listaAresta.remove(aresta);
    diminuiGrau();
    diminuiGrauSaida();
    noAdj->diminuiGrau();
    noAdj->diminuiGrauSaida();
}

/************************************/
/*                                  */
/* MOSTRA A VIZINHANÇA ABERTA DO NÓ */
/*                                  */
/************************************/

void No::vizinhancaAberta() {
    cout << "Vizinhanca aberta do no " << this->getID() << ":" << endl;
    int aux = 0;
    if(listaAresta.size() == 0) {
        cout << "Este no nao tem vizinhanca." << endl;
    } else {
        for(auto i = listaAresta.begin(); i != listaAresta.end(); i++) {
            Aresta *aresta = *i;
            aux++;
            cout << aresta->getIDNo();
            if(aux != listaAresta.size()) {
                cout << " -> ";
            }
        }
    }
}
/***********************************/
/*                                 */
/*  MOSTRA A FECHADA ABERTA DO NÓ  */
/*                                 */
/***********************************/

void No::vizinhancaFechada() {
    cout << "Vizinhanca fechada do no " << this->getID() << ":" << endl;
    cout << this->getID();
    int aux = 0;
    if(listaAresta.size() == 0) {
        cout << "Este no nao tem vizinhanca." << endl;
    } else {
        cout << " -> ";
        for(auto i = listaAresta.begin(); i != listaAresta.end(); i++) {
            Aresta *aresta = *i;
            aux++;
            cout << aresta->getIDNo();
            if(aux != listaAresta.size()) {
                cout << " -> ";
            }
        }
    }
}
