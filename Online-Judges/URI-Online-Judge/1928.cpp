#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii grafo, cartas;
vi pai, nivel, superPai;
int altura;

void dfsMontaArvore(int u, int p, int l){
  pai[u] = p; nivel[u] = l;
  if(l > altura) altura = l;
  for(auto v : grafo[u])
    if(!pai[v])
      dfsMontaArvore(v, u, l + 1);
}

void dfsMontaSuperPai(int u, int p){
  superPai[u] = p;
  for(auto v : grafo[u])
    if(!superPai[v])
      dfsMontaSuperPai(v, nivel[u] % altura == 0 ?  u :  p);
}

int lca(int u, int v){
  while(superPai[u] != superPai[v])
    nivel[u] > nivel[v] ? u = superPai[u] : v = superPai[v];
  for( ; u != v; nivel[u] > nivel[v] ? u = pai[u] : v = pai[v]);
  return u;
}

int main(void){
  int N, u, v;
  
  cin >> N;

  grafo.assign(N + 1, vi());
  cartas.assign(N/2 + 1, vi());
  pai.assign(N + 1, 0);
  superPai.assign(N + 1, 0);
  nivel.assign(N + 1, 0);
  
  for(int i = 1; i <= N; i++){
    cin >> u;
    cartas[u].push_back(i);
  }
 
  for(int i = 1; i < N; i++){
    cin >> u >> v;
    grafo[u].push_back(v);
    grafo[v].push_back(u);
  }

  dfsMontaArvore(1, 1, 0);
  altura = sqrt(altura);
  dfsMontaSuperPai(1, 1);

  u = 0; 
  for(int i = 1; i < (N/2) + 1; i++)
    u += (nivel[cartas[i][0]] + nivel[cartas[i][1]]) - 2 * nivel[lca(cartas[i][0], cartas[i][1])];

  cout << u << '\n';
  
  return 0;
}
