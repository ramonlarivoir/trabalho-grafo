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

void Grafo::setOrdem(int ordem) {
    this->ordem = ordem;
}

No* Grafo::getNo(int id) {
    No *percorre = getListaNos();
    if(cabeca == NULL) {                              //verifica se a lista est� vazia
        std::cout << "Lista de Nos vazia" << std::endl;
        exit(0);
    } else {
        if(id == percorre->getID()) {                            //confere se � o primeiro n� da lista
            return percorre;
        } else {
            while(percorre->getProxNo()->getID() != id) {      //percorre a lista at� que o pr�ximo n� seja o que deve ser removido
                percorre = percorre->getProxNo();
            }
            return percorre;
        }
    }
}

/*****************************/
/*                           */
/* INCLUS�O E REMO��O DE N�S */
/*                           */
/*****************************/

void Grafo::insereNo(No* no) {
    No *percorre = getListaNos();                   //cria n� para percorrer a lista de n�s
    if(percorre==NULL) {                            //se a lista est� vazia cria uma nova com o primeiro n�
        cabeca = no;
        setListaNos(no);
    } else {
        while(percorre->getProxNo() != NULL) {      //se n�o est� vazia, vai at� o �ltimo n� e adiciona
            percorre = percorre->getProxNo();
        }
        percorre->setProxNo(no);
    }
}

void Grafo::removeNo(No* no) {
    No *percorre = getListaNos();
    if(cabeca == NULL) {                              //verifica se a lista est� vazia
        std::cout << "Lista de Nos vazia" << std::endl;
    } else {
        if(cabeca == no) {                            //confere se � o primeiro n� da lista
            if(cabeca->getProxNo() == NULL) {
                cabeca = NULL;                        //se for o �nico n� na lista, remove e encerra a lista
            } else {
                percorre = percorre->getProxNo();     //se n�o for o �nico n� apenas remove e torna o pr�ximo n� como n� cabe�a da lista
                delete cabeca;
                cabeca = percorre;
            }
        } else {
            while(percorre->getProxNo() != no) {      //percorre a lista at� que o pr�ximo n� seja o que deve ser removido
                percorre = percorre->getProxNo();
            }
            percorre->setProxNo(no->getProxNo());     //seta o pr�ximo n� como o sucessor do n� que ser� remido e remove o n�
            delete no;
        }
    }
}

/******************************/
/*                            */
/* IMPRESS�O DOS N�S DO GRAFO */
/*                            */
/******************************/

void Grafo::imprimeLista() {
    No* percorre = getListaNos();                               //cria n� para percorrer a lista de n�s
    if(cabeca == NULL) {                                        //verifica se a lista est� vazia
        std::cout << "Lista vazia" << std::endl;
    } else {

        for(percorre = cabeca; percorre->getProxNo() != NULL; percorre = percorre->getProxNo()) {
            std::cout << percorre->getID() << std::endl;        //percorre a lista at� o n� em que o pr�ximo � nulo
        }
        std::cout << percorre->getID() << std::endl;            //imprime o �ltimo n� da lista


    }
}

/******************************/
/*                            */
/*   INSERE ARESTA NOS N�S    */
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
    std::cout << "A ordem deste grafo eh: " << this->getOrdem() << std::endl;
}

/********************************/
/*                              */
/* INFORMA SE O GRAFO � TRIVIAL */
/*                              */
/********************************/

void Grafo::trivial() {
    if(this->getOrdem() == 1 && this->cabeca->getGrau() == 0) {
        std::cout << "O grafo eh trivial" << std::endl;
    } else {
        std::cout << "O grafo nao eh trivial" << std::endl;
    }
}

/*******************************/
/*                             */
/*  INFORMA SE O GRAFO � NULO  */
/*                             */
/*******************************/

void Grafo::nulo() {
    if(this->getOrdem() == 0) {
        std::cout << "O grafo eh nulo" << std::endl;
    } else {
        std::cout << "O grafo nao eh nulo" << std::endl;
    }
}

/************************************/
/*                                  */
/* MOSTRA A VIZINHAN�A ABERTA DO N� */
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
/*  MOSTRA A FECHADA ABERTA DO N�  */
/*                                 */
/***********************************/

void Grafo::vizinhancaFechadaNo(int idNo) {
    No* percorre = getListaNos();
    while(percorre->getID() != idNo) {
        percorre = percorre->getProxNo();
    }
    percorre->vizinhancaFechada();
}

/**********************************/
/*                                */
/* VERIFICA SE O GRAFO � COMPLETO */
/*        (GRAFO SIMPLES)         */
/*                                */
/**********************************/

void Grafo::grafoSimplesCompleto() {
    No* percorre = getListaNos();
    int soma = 0;
    int completo = ((getOrdem()*(getOrdem()-1))/2);
    while(percorre->getProxNo() != NULL) {
        soma = soma + percorre->getGrau();
        percorre = percorre->getProxNo();
    }
    if(soma == completo) {
        std::cout << "O grafo eh completo" << std::endl;
    } else {
        std::cout << "O grafo nao eh completo" << std::endl;
    }
}

/**********************************/
/*                                */
/* APRESENTA A SEQU�NCIA DE GRAUS */
/*        (N�O FINALIZADO)        */
/**********************************/

void Grafo::sequenciaGrau() {
    int tam = getOrdem();
    int seq[tam];
    int i = 0;
    No* percorre = getListaNos();
    while(percorre->getProxNo() != NULL) {
        seq[i] = percorre->getGrau();
        i++;
        percorre = percorre->getProxNo();
    }

    std::sort(seq, seq + tam);

    std::cout << "<";

    for(int j = 0; j < tam; j++) {
        std::cout << seq[j] << ", ";
    }

    std::cout<< ">" << std::endl;
}
