// Yo no soy el más fácil D: 

#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int N = 8;
const lli inf = 1e18;
const int dr[8] = {+2, +2, +1, -1, +1, -1, -2, -2};
const int dc[8] = {-1, +1, +2, +2, -2, -2, +1, -1};

struct state{
  int r, c;
  lli bucks = 0;

  bool operator < (const state &s) const{
    return !(bucks < s.bucks);
  }
};

lli mn[N][N];
state s, t;

bool valid(int r, int c){
  return 0 <= r && r < N && 0 <= c && c < N;
}

lli dijkstra(){
  priority_queue<state> pq;
  mn[s.r][s.c] = 0;
  pq.push(s);
  while( !pq.empty() ){
    state prev = pq.top();
    pq.pop();
    if( mn[prev.r][prev.c] < prev.bucks ){
      continue;
    }
    for(int k = 0; k < 8; k++){
      state cur = prev;
      cur.r += dr[k], cur.c += dc[k];
      if( !valid(cur.r, cur.c) ){
        continue;
      }
      cur.bucks += prev.r * cur.r + prev.c * cur.c;
      if( cur.bucks < mn[cur.r][cur.c] ){
        mn[cur.r][cur.c] = cur.bucks;
        pq.push(cur);
      }
    }
  }
  return mn[t.r][t.c] == inf ? -1: mn[t.r][t.c];
}

int main(){
  while( cin >> s.r >> s.c >> t.r >> t.c ){
    fill_n((lli*) mn, N * N, inf);
    cout << dijkstra() << '\n';
  }
  return 0;
}
