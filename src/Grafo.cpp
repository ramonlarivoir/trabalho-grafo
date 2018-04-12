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
        std::cout << "Lista vazia" << std::endl;
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
