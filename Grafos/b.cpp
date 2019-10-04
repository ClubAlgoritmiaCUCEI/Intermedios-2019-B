#include <bits/stdc++.h>
#define For(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define Rof(i, a, b, c) for(int i = (a); i >= (b); i += (c))
#define Forn(i, n) For(i, 0, (n) - 1, +1)
#define For1(i, n) For(i, 1, (n), +1)
#define Forall(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define size(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define debug(x) cout << #x": " << x << '\n';
 
#define fst first
#define snd second
#define pb push_back
#define lower lower_bound
#define upper upper_bound
#define ENDL '\n'
using namespace std;
 
typedef long long lli;
typedef unsigned long long ulli;
typedef pair<int, int> ii;
 
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
