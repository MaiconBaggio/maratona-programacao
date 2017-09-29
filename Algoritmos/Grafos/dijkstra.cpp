#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;

int dijkstra(vii &grafo, int numVertices, int u, int v){
  priority_queue< ii, vector<ii>, greater<ii> > pqueue;
  vector<int> dist(numVertices, INF);
  dist[u] = 0;
  pqueue.push(ii(0, u));

  while(!pqueue.empty()){
    int u = pqueue.top().second, d = pqueue.top().first;
    pqueue.pop();
    if(d > dist[u]) continue;
    for(auto v : grafo[u])
      if(dist[u] + v.second < dist[v.first]){
	dist[v.first] = dist[u] + v.second;
	pqueue.push(ii(dist[v.first], v.first));
      }
  }
  return dist[v];
}


int main(void){
  int numVertices, numArestas, u, v, w, U, V;
  cin >> numVertices >> numArestas >> U >> V;
  vii grafo(numVertices + 1, vi());
  
  while(numArestas--){
    cin >> u >> v >> w;
    grafo[u].push_back(ii(v, w));
    grafo[v].push_back(ii(u, w));
  }
  
  cout << dijkstra(grafo, numVertices + 1, U, V) << "\n";
  
  return 0;
}
