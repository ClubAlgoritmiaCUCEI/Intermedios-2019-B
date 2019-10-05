// ¡No!, Yo soy el más fácil 

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2005;

vector<int> g[N];
int vis[N];
int n;
 
int bfs(int s){
  queue< pair<int, int> > q;
  q.push({s, 0});
  while( !q.empty() ){
    int u = q.front().first;
    int dist = q.front().second;
    q.pop();
    if( u == s && dist > 0 ){
      return dist;
    }
    for(int v: g[u]){
      if( vis[v] != s ){
        vis[v] = s;
        q.push({v, dist + 1});
      }
    }
  }
  return -1;
}
 
int main(){ 
  cin >> n;
  for(int u = 1; u <= n; u++){
    for(int v = 1; v <= n; v++){
      bool road;
      cin >> road;
      if( road ){
        g[u].push_back(v);
      }
    }
  }
  for(int u = 1; u <= n; u++){
    int dist = bfs(u);
    if( dist == -1 ){
      cout << "NO WAY\n";
    }else{
      cout << dist << '\n';
    }
  }
  return 0;
}
