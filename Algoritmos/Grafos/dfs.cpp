#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii grafo;
vi visitado;

void dfs(int u){
  visitado[u] = 1;
  for(auto v : grafo[u])
    if(!visitado[u])
      dfs(v);
}

int main(){
  int numeroVertices, numeroArestas, u, v;

  cin >> numeroVertices >> numeroArestas;
  grafo.assign(numeroVertices + 1, vi());
  visitado.assign(numeroVertices + 1, 0);
  
  while(numeroArestas--){
    cin >> u >> v;
    grafo[u].push_back(v);
    grafo[v].push_back(u);
  }

  dfs(0);
  
  return 0;
}
