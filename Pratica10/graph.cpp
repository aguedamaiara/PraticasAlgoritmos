#include "graph.h"
#include "heap.h"

#include <queue>

using namespace std;

// Cria array do tipo T com tamanho "size" e inicializa com valor "def"
template <class T> T *array(int size, T def) {
  T *arr = new T[size];
  for (int i = 0; i < size; i++)
    arr[i] = def;
  return arr;
}

Graph::Graph(int nVert) {
  this->nVert = nVert;
  this->adj = new list<Edge>[nVert];
}

Graph::~Graph() { delete[] adj; }

int Graph::size() { return nVert; }

// Cria�o da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
  Edge newEdge(src, dst, w); // Criar um objeto Edge com destino dst e peso w
  adj[src].push_back(
      newEdge); // Adicionar a nova aresta à lista de adjacência de src
}

int Graph::degree(int src) { return adj[src].size(); }

list<int> Graph::neighbors(int src) {
  list<int> result;
  for (const Edge &edge : adj[src]) {
    result.push_back(edge.dst);
  }
  return result;
}

int Graph::weight(int src, int dst) {
  for (const Edge &edge : adj[src]) {
    if (edge.dst == dst) {
      return edge.weight;
    }
  }
  // Caso não haja uma aresta entre src e dst, retorne -1 ou outro valor
  // adequado
  return -1;
}

void Graph::print() {
  for (int i = 0; i < this->size(); i++) {
    int d = this->degree(i);

    cout << i << "(" << d << "): ";

    list<int> nei = this->neighbors(i);
    for (int dst : nei) {
      int w = this->weight(i, dst);
      cout << dst << "[" << w << "]; ";
    }

    cout << endl;
  }
}

bool Graph::isConnected() {
  int group[nVert]; // Array de grupos

  // Inicializa cada vértice em um grupo separado
  for (int i = 0; i < nVert; i++) {
    group[i] = i;
  }

  // Percorre todas as arestas e junta os grupos
  for (int i = 0; i < nVert; i++) {
    for (const Edge &edge : adj[i]) {
      int srcGroup = group[edge.src];
      int dstGroup = group[edge.dst];

      // Junta os grupos se forem diferentes
      if (srcGroup != dstGroup) {
        for (int j = 0; j < nVert; j++) {
          if (group[j] == dstGroup) {
            group[j] = srcGroup;
          }
        }
      }
    }
  }

  // Verifica se todos os vértices pertencem ao mesmo grupo
  int firstGroup = group[0];
  for (int i = 1; i < nVert; i++) {
    if (group[i] != firstGroup) {
      return false; // O grafo não é conexo
    }
  }

  return true; // O grafo é conexo
}

// -------- PRAT 10 --------------//

// Busca em profundidade
list<int> Graph::dfs(int src) {
  list<int> result;
  int *visited = array(nVert, 0);

  DFS(src, visited, result);

  delete[] visited;
  return result;
}

// Busca em profundidade TODO
void Graph::DFS(int src, int *visited, list<int> &result) {
  // Marcar o vértice atual como visitado
  visited[src] = true;

  // Adicionar o vértice atual à lista de resultados
  result.push_back(src);

  // Percorrer todos os vértices adjacentes ao vértice atual
  for (const auto &neighbor : adj[src]) {
    // Verificar se o vértice vizinho não foi visitado
    if (!visited[neighbor.dst]) {
      // Chamada recursiva para o vértice vizinho
      DFS(neighbor.dst, visited, result);
    }
  }
}

// Busca em largura
list<int> Graph::bfs(int src) {
  list<int> result;
  int *visited = array(nVert, 0);

  BFS(src, visited, result);

  delete[] visited;
  return result;
}

// Busca em largura TODO
void Graph::BFS(int src, int *visited, list<int> &result) {

  queue<int> queue;

  visited[src] = true;
  queue.push(src);

  while (!queue.empty()) {
    int current = queue.front();
    queue.pop();

    result.push_back(current);

    for (const auto &neighbor : adj[current]) {
      if (!visited[neighbor.dst]) {
        visited[neighbor.dst] = true;
        queue.push(neighbor.dst);
      }
    }
  }
}

list<int> Graph::spf(int src, int dst) {
  int *dist =
      array(nVert, 99999);      // array de dist�ncias acumuladas; 99999 = INF
  int *prev = array(nVert, -1); // array de v�rtices anteriores
                                //   cont�m menores caminhos
  dist[src] = 0;

  // Cria o heap (m�nimo) baseado na dist�ncia
  Heap<int> pq(nVert, dist);

  while (!(pq.empty())) {
    int node = pq.dequeue(); // pega n� com menor dist�ncia acumulada

    for (Edge e : adj[node]) {
      int v = e.dst;    // n� vizinho
      int w = e.weight; // peso da aresta

      int D = dist[node] + w; // nova dist�ncia

      if (D < dist[v]) { // menor que antiga?
        prev[v] = node;  // atualize anterior
        dist[v] = D;     // atualize dist�ncia
        pq.decrease(v);  // atualize o heap (PQ)
      }
    }
  }

  list<int> result; // menor caminho

  path(dst, prev, result); // extrair caminho em result

  delete[] dist;
  delete[] prev;

  return result;
}

// TODO
void Graph::path(int dst, int *prev, list<int> &result) {
  int current = dst;
  while (current != -1) {
    result.push_front(current);
    current = prev[current];
  }
}
