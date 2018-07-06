#include "LeitorArquivoGrafo.h"

void LeitorArquivoGrafo::atribuirDados(std::string arquivo, Grafo& grafo)
{
  int id1;
  int id2;
  int ordem;
  double pesoArco;
  std::ifstream arq(arquivo);

  if (!arq.is_open())
  {
    std::cout << "Erro na leitura do arquivo" << std::endl;
    exit(0);
  }
  else
  {
    // Eis a primeira linha
    arq >> ordem;
    grafo.setOrdem(ordem); //pega o valor da primeira linha e determina a ordem do grafo

    ///cria os nós para o grafo
    for(int i = 1; i <= ordem; i++) {
      No *no = new No(i);
      grafo.insereNo(no);
    }

    // Demais linhas
    while (arq >> id1 >> id2)
    {
      No *no1 = grafo.getNo(id1);
      No *no2 = grafo.getNo(id2);
      grafo.insereArestaNos(no1, no2);
    }

  }
}

/*void LeitorArquivoGrafo::setSequenciaGrau(Grafo& grafo)
{
  for (auto i = grafo.nos.begin(); i != grafo.nos.end(); i++)
  {
    No *no = *i;
    grafo.sequenciaGrau.push_back(no->grauSaida);
  }
  grafo.sequenciaGrau.sort();
  grafo.sequenciaGrau.reverse();
}*/
