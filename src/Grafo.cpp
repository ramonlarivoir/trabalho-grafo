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
    if(listaNos.size() == 0) {                              //verifica se a lista est� vazia
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
        cout << "No nao existe" << endl;
        exit(0);
    }
}

/*****************************/
/*                           */
/* INCLUS�O E REMO��O DE N�S */
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
/* IMPRESS�O DOS N�S DO GRAFO */
/*                            */
/******************************/

void Grafo::imprimeLista() {
    if(listaNos.size() == 0) {                                        //verifica se a lista est� vazia
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
/*   INSERE ARESTA NOS N�S    */
/*                            */
/******************************/

void Grafo::insereArestaNos(No* origem, No* destino, int peso) {
    origem->insereAresta(destino, peso);
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
/* INFORMA SE O GRAFO � TRIVIAL */
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
/*  INFORMA SE O GRAFO � NULO  */
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
/* MOSTRA A VIZINHAN�A ABERTA DO N� */
/*                                  */
/************************************/

void Grafo::vizinhancaAbertaNo(int idNo) {
    No *no = getNo(idNo);
    no->vizinhancaAberta();
}

/***********************************/
/*                                 */
/*  MOSTRA A FECHADA ABERTA DO N�  */
/*                                 */
/***********************************/

void Grafo::vizinhancaFechadaNo(int idNo) {
    No *no = getNo(idNo);
    no->vizinhancaFechada();
}

/**********************************/
/*                                */
/* VERIFICA SE O GRAFO � COMPLETO */
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
/* APRESENTA A SEQU�NCIA DE GRAUS */
/*                                */
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

void Grafo::sequenciaGrauEntrada() {
    list<int> sequencia;
    int aux = 0;

    for(auto i = listaNos.begin(); i != listaNos.end(); i++) {
        No *no = *i;
        sequencia.push_back(no->getGrauEntrada());
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

void Grafo::sequenciaGrauSaida() {
    list<int> sequencia;
    int aux = 0;

    for(auto i = listaNos.begin(); i != listaNos.end(); i++) {
        No *no = *i;
        sequencia.push_back(no->getGrauSaida());
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




int Grafo::dijkstra(int orig, int dest) {
    int V = this->getOrdem();
    list<pair<int, int> > *adj = new list<pair<int, int> >[V];
    for(auto i = this->listaNos.begin(); i  != this->listaNos.end(); i++) {
        No *no = *i;
        for(auto j = no->getListaAresta().begin(); j != no->getListaAresta().end(); j++) {
            Aresta *aresta = *j;
            adj[no->getID()].push_back(make_pair(aresta->getIDNo(), aresta->getPesoAresta()));
        }
    }
    // vetor de dist�ncias
    int dist[V];

    /*
       vetor de visitados serve para caso o v�rtice j� tenha sido
       expandido (visitado), n�o expandir mais
    */
    int visitados[V];

    // fila de prioridades de pair (distancia, v�rtice)
    priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    // inicia o vetor de dist�ncias e visitados
    for(int i = 0; i < V; i++) {
        dist[i] = INFINITO;
        visitados[i] = false;
    }

    // a dist�ncia de orig para orig � 0
    dist[orig] = 0;

    // insere na fila
    pq.push(make_pair(dist[orig], orig));

    // loop do algoritmo
    while(!pq.empty()) {
        pair<int, int> p = pq.top(); // extrai o pair do topo
        int u = p.second; // obt�m o v�rtice do pair
        pq.pop(); // remove da fila

        // verifica se o v�rtice n�o foi expandido
        if(visitados[u] == false) {
            // marca como visitado
            visitados[u] = true;

            list<pair<int, int> >::iterator it;

            // percorre os v�rtices "v" adjacentes de "u"
            for(it = adj[u].begin(); it != adj[u].end(); it++) {
                // obt�m o v�rtice adjacente e o custo da aresta
                int v = it->first;
                int custo_aresta = it->second;

                // relaxamento (u, v)
                if(dist[v] > (dist[u] + custo_aresta)) {
                    // atualiza a dist�ncia de "v" e insere na fila
                    dist[v] = dist[u] + custo_aresta;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }

    // retorna a dist�ncia m�nima at� o destino
    return dist[dest];
}
