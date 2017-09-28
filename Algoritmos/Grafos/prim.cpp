#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define INF 100000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;

int prim(vii &grafo, int numeroVertices, int inicio){
  int resp = 0;
  vector<int> dist(numeroVertices, INF), vis(numeroVertices, 0);
  priority_queue< ii, vector<ii>, greater<ii> > pqueue;
  pqueue.push(ii(0, inicio));
  dist[inicio] = 0;
  
  while(!pqueue.empty()){
    int d = pqueue.top().first, u = pqueue.top().second;
    pqueue.pop();
    if(vis[u]) continue;
    vis[u] = 1; resp += dist[u];
    for(auto v : grafo[u])
      if(v.second < dist[v.first]  && !vis[v.first]){
	dist[v.first] = v.second;
	pqueue.push(ii(dist[v.first], v.first));
      }
  }
  return resp;
}
  
int main(void){
  int numArestas, numVertices, u, v, w;
  cin >> numVertices >> numArestas;
  vii grafo(numVertices, vi());
  
  while(numArestas--){
    cin >> u >> v >> w;
    grafo[u].push_back(ii(v, w));
    grafo[v].push_back(ii(u, w));
  }

  cout << prim(grafo, numVertices, 0) << "\n";
  return 0;
}
