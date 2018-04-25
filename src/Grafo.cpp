#include "Grafo.h"

Grafo::Grafo() {
    this->ordem          = 0;
    this->grauGrafo      = 0;
    this->numArestas     = 0;
    this->listaNos       = NULL;
    this->cabeca         = NULL;
}

Grafo::~Grafo() {
    //dtor
}

/*****************************/
/*                           */
/*       GETS E SETS         */
/*                           */
/*****************************/

No* Grafo::getListaNos() {
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

void Grafo::setListaNos(No* listaNo) {
    this->listaNos = listaNo;
}

/*****************************/
/*                           */
/* INCLUSÃO E REMOÇÃO DE NÓS */
/*                           */
/*****************************/

void Grafo::insereNo(No* no) {
    No *percorre = getListaNos();                   //cria nó para percorrer a lista de nós
    if(percorre==NULL) {                            //se a lista está vazia cria uma nova com o primeiro nó
        cabeca = no;
        setListaNos(no);
    } else {
        while(percorre->getProxNo() != NULL) {      //se não está vazia, vai até o último nó e adiciona
            percorre = percorre->getProxNo();
        }
        percorre->setProxNo(no);
    }
    this->ordem++;
}

void Grafo::removeNo(No* no) {
    No *percorre = getListaNos();
    if(cabeca == NULL) {                              //verifica se a lista está vazia
        std::cout << "Lista de Nós vazia" << std::endl;
    } else {
        if(cabeca == no) {                            //confere se é o primeiro nó da lista
            if(cabeca->getProxNo() == NULL) {
                cabeca = NULL;                        //se for o único nó na lista, remove e encerra a lista
            } else {
                percorre = percorre->getProxNo();     //se não for o único nó apenas remove e torna o próximo nó como nó cabeça da lista
                delete cabeca;
                cabeca = percorre;
            }
        } else {
            while(percorre->getProxNo() != no) {      //percorre a lista até que o próximo nó seja o que deve ser removido
                percorre = percorre->getProxNo();
            }
            percorre->setProxNo(no->getProxNo());     //seta o próximo nó como o sucessor do nó que será remido e remove o nó
            delete no;
        }
    }
}

/******************************/
/*                            */
/* IMPRESSÃO DOS NÓS DO GRAFO */
/*                            */
/******************************/

void Grafo::imprimeLista() {
    No* percorre = getListaNos();                               //cria nó para percorrer a lista de nós
    if(cabeca == NULL) {                                        //verifica se a lista está vazia
        std::cout << "Lista vazia" << std::endl;
    } else {

        for(percorre = cabeca; percorre->getProxNo() != NULL; percorre = percorre->getProxNo()) {
            std::cout << percorre->getID() << std::endl;        //percorre a lista até o nó em que o próximo é nulo
        }
        std::cout << percorre->getID() << std::endl;            //imprime o último nó da lista


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
    std::cout << "A ordem deste grafo é: " << this->getOrdem() << std::endl;
}

/********************************/
/*                              */
/* INFORMA SE O GRAFO É TRIVIAL */
/*                              */
/********************************/

void Grafo::trivial() {
    if(this->getOrdem() == 1 && this->cabeca->getGrau() == 0) {
        std::cout << "O grafo é trivial" << std::endl;
    } else {
        std::cout << "O grafo não é trivial" << std::endl;
    }
}

/*******************************/
/*                             */
/*  INFORMA SE O GRAFO É NULO  */
/*                             */
/*******************************/

void Grafo::nulo() {
    if(this->getOrdem() == 0) {
        std::cout << "O grafo é nulo" << std::endl;
    } else {
        std::cout << "O grafo não é nulo" << std::endl;
    }
}

/************************************/
/*                                  */
/* MOSTRA A VIZINHANÇA ABERTA DO NÓ */
/*                                  */
/************************************/

void Grafo::vizinhancaAbertaNo(int idNo) {
    No* percorre = getListaNos();
    if(percorre->getID() == idNo) {
        percorre->vizinhancaAberta();
    } else {
        while(percorre->getID() != idNo) {
            percorre = percorre->getProxNo();
        }
        percorre->vizinhancaAberta();
    }
}

/***********************************/
/*                                 */
/*  MOSTRA A FECHADA ABERTA DO NÓ  */
/*                                 */
/***********************************/

void Grafo::vizinhancaFechadaNo(int idNo) {
    No* percorre = getListaNos();
    while(percorre->getID() != idNo) {
        percorre = percorre->getProxNo();
    }
    percorre->vizinhancaFechada();
}
