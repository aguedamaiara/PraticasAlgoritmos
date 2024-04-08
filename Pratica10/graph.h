#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
  // Aresta
  struct Edge {
    int src;    // Origem  da aresta
    int dst;    // Destino da aresta (n� vizinho)
    int weight; // Peso da aresta
    Edge(int src, int dst, int weight) : src(src), dst(dst), weight(weight) {}
  };

  int nVert;       // N�mero de v�rtices
  list<Edge> *adj; // Array de listas de adjac�ncia (list da STL)

public:
  Graph(int nVert);
  ~Graph();

  int size(); // retorna n�mero de v�rtices

  // Pr�tica 09 - TODO
  void edge(int src, int dst, int w); // Cria src -> dst com peso w
  int degree(int vtx);                // retorna grau de um v�rtice
  int weight(int src, int dst);       // retorna peso da aresta de src para dst
  list<int> neighbors(int src);       // retorna lista de vertices ligados a src
  bool isConnected();

  // Pr�tica 10 - TODO (abaixo)
  list<int> dfs(int src);          // Busca em profundidade
  list<int> bfs(int src);          // Busca em largura
  list<int> spf(int src, int dst); // Menor caminho entre src e dst

  void print(); // Exibe o grafo
  friend ostream &operator<<(ostream &out,
                             const Graph::Edge &edge); // usado na exibi�o

private:
  // Pr�tica 10 - TODO
  void DFS(int src, int *visited, list<int> &result);
  void BFS(int src, int *visited, list<int> &result);
  void path(int src, int *prev,
            list<int> &result); // extrai menor caminho de prev
};
