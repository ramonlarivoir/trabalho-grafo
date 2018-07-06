#include "Grafo.h"

Grafo::Grafo() {
    this->ordem          = 0;
    this->grauGrafo      = 0;
    this->numArestas     = 0;
    this->listaNos;
}

Grafo::~Grafo() {
    //dtor
}

/*****************************/
/*                           */
/*       GETS E SETS         */
/*                           */
/*****************************/

list<No*> Grafo::getListaNos() {
    return this->listaNos;
}

int Grafo::getOrdem() {
    return this->ordem;
}

int Grafo::getGrau() {
    return this->grauGrafo;
}

int Grafo::getNumArestas() {
    return this->numArestas;
}

void Grafo::setListaNos(list<No*> listaNo) {
    this->listaNos = listaNo;
}

void Grafo::setOrdem(int ordem) {
    this->ordem = ordem;
}

No* Grafo::getNo(int id) {
    if(listaNos.size() == 0) {                              //verifica se a lista está vazia
        cout << "Lista de Nos vazia" << endl;
        exit(0);
    } else {
        for(auto it = listaNos.begin(); it != listaNos.end(); it ++) {
            No *no = *it;
            if(no->getID() == id) {
                return no;
                exit(0);
            }
        }
    }
}

/*****************************/
/*                           */
/* INCLUSÃO E REMOÇÃO DE NÓS */
/*                           */
/*****************************/

void Grafo::insereNo(No* no) {
    listaNos.push_back(no);
}

void Grafo::removeNo(No* no) {
    listaNos.remove(no);
}

/******************************/
/*                            */
/* IMPRESSÃO DOS NÓS DO GRAFO */
/*                            */
/******************************/

void Grafo::imprimeLista() {
    if(listaNos.size() == 0) {                                        //verifica se a lista está vazia
        cout << "Lista vazia" << endl;
    } else {
        cout << "Lista de todos os nos do grafo:" << endl;
        for(auto it = listaNos.begin(); it != listaNos.end(); it++) {
            No *no = *it;
            cout << no->getID() << endl;
        }
    }
}

/******************************/
/*                            */
/*   INSERE ARESTA NOS NÓS    */
/*                            */
/******************************/

void Grafo::insereArestaNos(No* origem, No* destino) {
    origem->insereAresta(destino);
}

/******************************/
/*                            */
/*   INFORMA ORDEM DO GRAFO   */
/*                            */
/******************************/

void Grafo::informaOrdem() {
    cout << "A ordem deste grafo eh: " << this->getOrdem() << endl;
}

/********************************/
/*                              */
/* INFORMA SE O GRAFO É TRIVIAL */
/*                              */
/********************************/

void Grafo::trivial() {
    No *no = listaNos.front();
    if(this->getOrdem() == 1 && no->getGrau() == 0) {
        cout << "O grafo eh trivial" << endl;
    } else {
        cout << "O grafo nao eh trivial" << endl;
    }
}

/*******************************/
/*                             */
/*  INFORMA SE O GRAFO É NULO  */
/*                             */
/*******************************/

void Grafo::nulo() {
    if(this->getOrdem() == 0) {
        cout << "O grafo eh nulo" << endl;
    } else {
        cout << "O grafo nao eh nulo" << endl;
    }
}

/************************************/
/*                                  */
/* MOSTRA A VIZINHANÇA ABERTA DO NÓ */
/*                                  */
/************************************/

void Grafo::vizinhancaAbertaNo(int idNo) {
    No *no = getNo(idNo);
    no->vizinhancaAberta();
}

/***********************************/
/*                                 */
/*  MOSTRA A FECHADA ABERTA DO NÓ  */
/*                                 */
/***********************************/

void Grafo::vizinhancaFechadaNo(int idNo) {
    No *no = getNo(idNo);
    no->vizinhancaFechada();
}

/**********************************/
/*                                */
/* VERIFICA SE O GRAFO É COMPLETO */
/*        (GRAFO SIMPLES)         */
/*                                */
/**********************************/

void Grafo::grafoSimplesCompleto() {
    int soma = 0;
    int completo = ((getOrdem()*(getOrdem()-1))/2);
    for(auto i = listaNos.begin(); i != listaNos.end(); i++) {
        No *no = *i;
        soma = soma + no->getGrau();
    }
    if(soma == completo) {
        cout << "O grafo eh completo" << endl;
    } else {
        cout << "O grafo nao eh completo" << endl;
    }
}

/**********************************/
/*                                */
/* APRESENTA A SEQUÊNCIA DE GRAUS */
/*        (NÃO FINALIZADO)        */
/**********************************/

void Grafo::sequenciaGrau() {
    list<int> sequencia;
    int aux = 0;

    for(auto i = listaNos.begin(); i != listaNos.end(); i++) {
        No *no = *i;
        sequencia.push_back(no->getGrau());
    }

    sequencia.sort();
    sequencia.reverse();

    cout << "<";
    for(auto j = sequencia.begin(); j != sequencia.end(); j++) {
        cout << *j;
        aux++;
        if(aux != sequencia.size()){
            cout << ", ";
        }
    }
    cout << ">";
}
