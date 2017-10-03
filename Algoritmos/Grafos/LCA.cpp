#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii grafo;
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
  int numeroVertices, numeroArestas, u, v, a, b;

  cin >> numeroVertices >> numeroArestas >> a >> b;
  grafo.assign(numeroVertices, vi(numeroArestas));
  pai.assign(numeroVertices, 0);
  nivel.assign(numeroVertices, 0);
  superPai.assign(numeroVertices, 0);
  
  while(numeroArestas--){
    cin >> u >> v;
    grafo[u].push_back(v);
    grafo[v].push_back(u);
  }

  dfsMontaArvore(1, 1, 0);
  altura = sqrt(altura);
  dfsMontaSuperPai(1, 1);
  
  cout <<  (nivel[a] + nivel[b]) - 2 * nivel[lca(a, b)] << '\n'; 
   
  return 0;
}
