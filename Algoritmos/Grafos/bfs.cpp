#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int bfs(vii &grafo, int numVertices, int U, int V){
  vi dist(numVertices, -1);
  queue<int> fila;
  dist[U] = 0; fila.push(U);

  while(!fila.empty()){
    int u = fila.front();
    fila.pop();
    for(auto v : grafo[u])
      if(dist[v] == -1){
	dist[v] = dist[u] + 1;
	fila.push(v);
      }
  }
  return dist[V];
}


int main(void){
  int numVertices, numArestas, U, V, u, v;
  cin >> numVertices >> numArestas >> U >> V;
  vii grafo(numVertices, vi());
  
  while(numArestas--){
    cin >> u >> v;
    grafo[u].push_back(v);
    grafo[v].push_back(u);
  }
 
  cout << bfs(grafo, numVertices, U, V) << '\n';
  
  return 0;
}
