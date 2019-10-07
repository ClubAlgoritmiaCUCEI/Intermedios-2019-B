#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct nodo{
  int hijo[26];
  int cnt;

  nodo(){
     memset(hijo, -1, sizeof(hijo));
     cnt = 0;
  }
};

string s[N];
vector<nodo> trie;
int n;

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
    trie[u].cnt++;
  }
}

bool seguro(string &s, int u = 0){
  for(char c: s){
    u = trie[u].hijo[c - 'a'];
  }
  return trie[u].cnt == 1;
}

int main(){
  nuevo_nodo();
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s[i];
    inserta(s[i]);
  }
  bool non = true;
  for(int i = 0; i < n; i++){
    if( !seguro(s[i]) ){
      non = false;
      break;
    }
  }
  if( non ){
    cout << "non ";
  }
  cout << "vulnerable\n";
  return 0;
}
