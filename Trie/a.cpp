#include <bits/stdc++.h>
using namespace std;

struct nodo{
  int hijo[10];
  bool fin;

  nodo(){
     memset(hijo, -1, sizeof(hijo));
     fin = false;
  }
};

vector<nodo> trie;
string s;
int n;

int nuevo_nodo(){
  trie.push_back(nodo());
  return trie.size() - 1;
}

bool inserta(string &s, int u = 0){
  bool consistente = true;
  for(char c: s){
    if( trie[u].fin ){
      consistente = false;
      break;
    }
    if( trie[u].hijo[c - '0'] == -1 ){
      int v = nuevo_nodo();
      trie[u].hijo[c - '0'] = v;
    }
    u = trie[u].hijo[c - '0'];
  }
  trie[u].fin = true;
  for(int d = 0; d < 10; d++){
    if( trie[u].hijo[d] != -1 ){
      consistente = false;
    }
  }
  return consistente;
}

int main(){
  int t;
  cin >> t;
  while( t-- ){
    trie.clear();
    nuevo_nodo();
    cin >> n;
    bool consistente = true;
    for(int i = 0; i < n; i++){
      cin >> s;
      if( consistente ){
        consistente &= inserta(s);
      }
    }
    cout << (consistente ? "YES": "NO") << '\n';
  }
  return 0;
}
