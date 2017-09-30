#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> edge;

class disjointSet{
public:
  int numSets;
  vector<int> setSize, rank;
  disjointSet(int tamanho){
    numSets = tamanho;
    setSize.assign(tamanho, 0);
    rank.assign(tamanho, 0);
    for(int i = 0; i < tamanho; i++)
      setSize[i] = i, rank[i] = 0;
  }
  int find(int x){
    return setSize[x] == x ? x : setSize[x] = find(setSize[x]);
  }
  void unity(int u, int v){
    int ru = find(u), rv = find(v);
    if(ru == rv) return;
    numSets--;
    if(rank[v] < rank[u]){
      unity(v, u);
      return;
    }
    setSize[ru] = rv;
    if(rank[u] == rank[v]) rank[v]++;
  }
};


int kruskal(vector<edge> &arestas, int numVertices){
  int MST = 0;
  disjointSet muf(numVertices);
  sort(arestas.begin(), arestas.end());
  for(auto it : arestas)
    if(muf.find(it.second.first) != muf.find(it.second.second)){
      muf.unity(it.second.first, it.second.second);
      MST += it.first;
    }
  return MST;
}


int main(void){
  int numVertices, numArestas, u, v, w;
  cin >> numVertices >> numArestas;
  vector<edge> arestas(numVertices);
  while(numArestas--){
    cin >> u >> v >> w;
    arestas.push_back(edge(w, ii(u, v)));
  }
  
  cout << kruskal(arestas, numVertices) << '\n';
  return 0;
}
