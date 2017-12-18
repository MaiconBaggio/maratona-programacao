#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> edge;

vector<int> setSize, rr;

void make(int n){
  for(int i = 0; i <= n; i++){
    setSize[i] = i;
    rr[i] = 0;
  }
}

int FIND(int u){
  return setSize[u] == u ? u : setSize[u] = FIND(setSize[u]);
}

void UNIAO(int u, int v){
  int ru = FIND(u), rv = FIND(v);
  if(ru == rv) return;
  if(rr[v] < rr[u]){
    UNIAO(v, u);
    return;
  }
  setSize[ru] = rv;
  if(rr[u] == rr[v]) rr[v]++;
}


int main(void){
  int n, menor = 0, maior = 0;
  edge grafo;
  
  cin >> n;
  grafo.assign(n, iii());
  setSize.assign(n + 1, 0);
  rr.assign(n + 1, 0);
  
  for(auto &it : grafo)
    cin  >> it.second.first >> it.second.second >> it.first;
 
  sort(grafo.begin(), grafo.end());

  make(n);
  for(auto it : grafo)
    if(FIND(it.second.first) != FIND(it.second.second)){
      menor += it.first;
      UNIAO(it.second.first, it.second.second);
    }
  
  make(n);
  for(int i = n -1; i >=0 ; i--)
    if(FIND(grafo[i].second.first) != FIND(grafo[i].second.second)){
      maior += grafo[i].first;
      UNIAO(grafo[i].second.first, grafo[i].second.second);
    }

  cout << maior << "\n" << menor << "\n";
  return 0;
}
