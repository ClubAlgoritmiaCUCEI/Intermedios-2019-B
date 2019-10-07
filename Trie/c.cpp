#include <bits/stdc++.h>
using namespace std;

struct nodo{
  int hijo[26];
  bool fin;

  nodo(){
     memset(hijo, -1, sizeof(hijo));
     fin = false;
  }
};

vector<nodo> trie;
string s;
int n, k;

int nuevo_nodo(){
  trie.push_back(nodo());
  return trie.size() - 1;
}

void inserta(string &s, int u = 0){
  for(char c: s){
    if( trie[u].hijo[c - 'a'] == -1 ){
      int v = nuevo_nodo();
      trie[u].hijo[c - 'a'] = v;
    }
    u = trie[u].hijo[c - 'a'];
  }
  trie[u].fin = true;
}

bool dfs(string &s, int u){
  bool alguna = false;
  if( trie[u].fin ){
    cout << s << '\n';
    alguna = true;
  }
  for(char c = 'a'; c <= 'z'; c++){
    if( trie[u].hijo[c - 'a'] != -1 ){
      s.push_back(c);
      alguna |= dfs(s, trie[u].hijo[c - 'a']);
      s.pop_back();
    }
  }
  return alguna;
}

bool compuestas(string &s, int u = 0){
  for(char c: s){
    if( trie[u].hijo[c - 'a'] == -1 ){
      return false;
    }
    u = trie[u].hijo[c - 'a'];
  }
  bool alguna = false;
  for(char c = 'a'; c <= 'z'; c++){
    if( trie[u].hijo[c - 'a'] != -1 ){
      s.push_back(c);
      alguna |= dfs(s, trie[u].hijo[c - 'a']);
      s.pop_back();
    }
  }
  return alguna;
}

int main(){
  cin >> n;
  nuevo_nodo();
  for(int i = 0; i < n; i++){
    cin >> s;
    inserta(s);
  }
  cin >> k;
  for(int t = 1; t <= k; t++){
    cout << "Case #" << t << ":\n";
    cin >> s;
    if( !compuestas(s) ){
      cout << "No match.\n";
    }
  }
  return 0;
}
