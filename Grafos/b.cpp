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
 
int main(){ 
  int tt;
  cin >> tt;
  while( tt-- ){
    cin >> n;
    for(int u = 0; u < n; u++){
      g[u].clear();
    }
    for(int i = 0; i < n - 1; i++){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cout << (dist[bfs(bfs(0))] + 1) / 2 << '\n';
  }
  return 0;
}
