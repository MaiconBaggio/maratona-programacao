#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii itens;
int numeroItens, capacidade;
vector<vi> memo;

int mochilaRecursiva(int i, int c){
  if(i == numeroItens || c == 0) return 0;
  if(memo[i][c] != -1) return memo[i][c];
  if(itens[i].second > c)
    return memo[i][c] = mochilaRecursiva(i + 1, c);
  return memo[i][c] = max(mochilaRecursiva(i + 1, c), mochilaRecursiva(i + 1, c - itens[i].second) + itens[i].first); 
}

int mochilaIterativa(){
  for(int i = numeroItens; i >= 0; i--)
    for(int c = 0; c <= capacidade; c++){
      if(i == numeroItens) memo[i][c] = 0;
      else if(itens[i].second > c) memo[i][c] = memo[i + 1][c];
      else memo[i][c] = max(memo[i + 1][c], memo[i + 1][c - itens[i].second] + itens[i].first);
    }
  return memo[0][capacidade];
}

void itensNaMochila(){
  for(int i = 1, c = capacidade; i <= numeroItens; i++)
    if(memo[i][c] != memo[i - 1][c]){
      cout << itens[i - 1].first << ' ' << itens[i - 1].second << '\n';
      c -=  itens[i - 1].second; 
    }
}

int main(void){

  cin >> numeroItens >> capacidade;
  itens.assign(numeroItens, ii());

  for(auto &it : itens)
    cin >> it.first >> it.second;
  
  memo.assign(numeroItens + 1, vi(capacidade + 1, -1));
  cout << mochilaRecursiva(0, capacidade) << '\n';
  cout << mochilaIterativa() << '\n';

  cout << "Itens na mochila\n";
  itensNaMochila();
  
  return 0;
}
