#include <bits/stdc++.h>
using namespace std;
 
const int inf = 2e9 + 7;
const int N = 1e5 + 5;
 
vector<int> g[N];
int open[N];
int from[N];
int n, m;

void dfs(int u){
  if( u == 1 ){
    return;
  }
  dfs(from[u]);
  cout << from[u] << " ";
}

void bfs(int s){
  queue<int> q;
  open[1] = 0;
  q.push(1);
  while( !q.empty() ){
    int u = q.front();
    q.pop();
    for(int v: g[u]){
      if( open[u] + 1 < open[v] ){
        open[v] = open[u] + 1;
        from[v] = u;
        q.push(v);
      }
    }
  }
}
 
int main(){ 
  int tt;
  cin >> tt;
  while( tt-- ){
    cin >> n;
    for(int u = 1; u <= n; u++){
      g[u].clear();
      from[u] = -1;
      open[u] = inf;
    }
    for(int u = 1; u <= n - 1; u++){
      cin >> m;
      while( m-- ){
        int v;
        cin >> v;
        g[u].push_back(v);
      }
      sort(g[u].begin(), g[u].end());
    }
    bfs(1);
    if( open[n] == inf ){
      cout << "-1\n";
    }else{
      cout << open[n] << '\n';
      dfs(n);
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}
