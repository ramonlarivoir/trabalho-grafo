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
    this->grau = grau;
}

void No::setGrauEntrada(int grauEntrada) {
    this->grauEntrada = grauEntrada;
}

void No::setGrauSaida(int grauSaida) {
    this->grauSaida = grauSaida;
}

/*****************************/
/*   AUMENTO E DIMINUI��O    */
/*    DOS GRAUS DOS N�S      */
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
/** INCLUS�O E REMO��O DE ARESTAS **/
/**                               **/
/***********************************/

void No::insereAresta(No* noAdj) {
    Aresta* percorre = getListaAresta();                //aresta auxiliar para percorrer a lista de arestas
    Aresta* novaAresta = new Aresta(noAdj->getID());    //aresta que ser� inserida na lista
    if(cabeca==NULL) {
        cabeca = novaAresta;                            //verifica se a lista est� vazia e atribui a nova aresta na lista
        setListaAresta(cabeca);
        aumentaGrau();                                  //aumento dos graus das arestas
        aumentaGrauSaida();
        noAdj->aumentaGrauEntrada();
    } else {
        while(percorre->getProxAresta() != NULL) {      //percorre at� a �tlima posi��o e insere
            percorre = percorre->getProxAresta();
        }
        percorre->setProxAresta(novaAresta);
        aumentaGrau();                                  //aumento dos graus das arestas
        aumentaGrauSaida();
        noAdj->aumentaGrauEntrada();
    }
}

void No::removeAresta(No* noAdj) {
    Aresta* percorre = getListaAresta();
    if(cabeca == NULL) {                                    //verifica se a lista est� vazia
        std::cout << "Lista de Arestas vazia" << std::endl;
    } else {
        if(cabeca->getIDNo() == noAdj->getID()) {           //verifica se � a primeira aresta da lista
            if(cabeca->getProxAresta() == NULL) {
                cabeca == NULL;
                diminuiGrau();                              //caso seja a �nica aresta faz a remo��o e diminui os graus
                diminuiGrauSaida();
                noAdj->diminuiGrauEntrada();
            } else {
                percorre = percorre->getProxAresta();      //se n�o for a �nica aresta, aponta para a pr�xima e exclui a primeira
                delete cabeca;
                cabeca = percorre;
                diminuiGrau();
                diminuiGrauSaida();
                noAdj->diminuiGrauEntrada();
            }
        } else {
            while(percorre->getProxAresta()->getIDNo() != noAdj->getID()) {
                percorre = percorre->getProxAresta();       //percorre a lista at� a aresta
            }
            Aresta* aux = percorre->getProxAresta();
            percorre->setProxAresta(aux->getProxAresta());
            delete aux;                                     //remove a aresta e diminui os graus
            diminuiGrau();
            diminuiGrauSaida();
            noAdj->diminuiGrauEntrada();
        }
    }
}

/************************************/
/*                                  */
/* MOSTRA A VIZINHAN�A ABERTA DO N� */
/*                                  */
/************************************/

void No::vizinhancaAberta() {
    Aresta* percorre = getListaAresta();
    std::cout << "Vizinhanca aberta do no " << this->getID() << ":" << std::endl;
    if(percorre->getProxAresta() == NULL) {
        std::cout << percorre->getIDNo() << std::endl;
    } else {
        while(percorre->getProxAresta() != NULL) {
            std::cout << percorre->getIDNo() << std::endl;
            percorre = percorre->getProxAresta();
            std::cout << percorre->getIDNo() << std::endl;
        }
    }
}
/***********************************/
/*                                 */
/*  MOSTRA A FECHADA ABERTA DO N�  */
/*                                 */
/***********************************/

void No::vizinhancaFechada() {
    Aresta* percorre = getListaAresta();
    std::cout << "Vizinhanca fechada do no " << this->getID() << ":" << std::endl;
    std::cout << this->getID() << std::endl;
    if(percorre->getProxAresta() == NULL) {
        std::cout << percorre->getIDNo() << std::endl;
    } else {
        while(percorre->getProxAresta() != NULL) {
            std::cout << percorre->getIDNo() << std::endl;
            percorre = percorre->getProxAresta();
            std::cout << percorre->getIDNo() << std::endl;
        }
    }
}
