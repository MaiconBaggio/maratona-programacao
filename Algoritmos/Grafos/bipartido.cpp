#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

bool isBipartite(vii &grafo, int inicio){
  vi cor(grafo.size(), -1);
  queue<int> fila;
  cor[inicio] = 0;
  fila.push(inicio);
  
  while(!fila.empty()){
    int u = fila.front();
    fila.pop();
    for(auto v : grafo[u])
      if(cor[v] == -1){
	cor[v] = !cor[u];
	fila.push(v);
      }
      else if(cor[u] == cor[v])
	return false;
  }
  return true;
}


int main(void){
  int numeroVertices, numeroArestas, u, v;
  cin >> numeroVertices >> numeroArestas;
  vii grafo(numeroVertices, vi());

  while(numeroArestas--){
    cin >> u >> v;
    grafo[u].push_back(v);
    grafo[v].push_back(u);
  }

  cout << (isBipartite(grafo, 0) ? "SIM\n" : "NAO\n");
  return 0;
}
