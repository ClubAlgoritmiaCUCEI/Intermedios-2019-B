#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;
 
vector<int> g[N];
int dist[N];
int n;
 
int bfs(int s){
  fill_n(dist, n, inf);
  queue<int> q;
  dist[s] = 0;
  q.push(s);
  while( !q.empty() ){
    int u = q.front();
    q.pop();
    for(int v: g[u]){
      if( dist[u] + 1 < dist[v] ){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return max_element(dist, dist + n) - dist;
}
 
int main(){ _
  int tt;
  cin >> tt;
  while( tt-- ){
    cin >> n;
    Forn(u, n){
      g[u].clear();
    }
    Forn(i, n - 1){
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    cout << (dist[bfs(bfs(0))] + 1) / 2 << '\n';
  }
  return 0;
}
