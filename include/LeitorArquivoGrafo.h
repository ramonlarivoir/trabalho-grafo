/* Esta classe � respons�vel por realizar a leitura de um arquivo texto e atribuir
 * os dados lidos a um objeto do tipo 'Grafo'. O arquivo passado deve ser disposto da forma:
 *
 * n
 * v1 v2 c1
 * v3 v4 c2
 * ...
 * vn v2 cn
 *
 * 'n' representa a ordem do grafo (quantidade de n�s) e todas as linhas abaixo de 'n'
 * representam os arcos formados pelos n n�s e seus respectivos pesos (c).
 */

#ifndef LEITORARQUIVOGRAFO_H
#define LEITORARQUIVOGRAFO_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "Grafo.h"
#include "Aresta.h"
#include "No.h"

class LeitorArquivoGrafo
{
private:
  static void setSequenciaGrau(Grafo& grafo);
public:
  static void atribuirDados(std::string arquivo, Grafo& grafo);
};

#endif // LEITORARQUIVOGRAFO_H
