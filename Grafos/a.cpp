#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int clicks[2 * N];
queue<int> q;
int s, t;

int main(){ _
  cin >> s >> t;
  clicks[s] = 0;
  q.push(s);
  while( !q.empty() ){
    int x = q.front();
    q.pop();
    if( x == t ){
      cout << clicks[t] << '\n';
      break;
    }
    if( 2 * x < 2 * N && !clicks[2 * x] ){
      clicks[2 * x] = clicks[x] + 1;
      q.push(2 * x);
    }
    if( x - 1 >= 0 && !clicks[x - 1] ){
      clicks[x - 1] = clicks[x] + 1;
      q.push(x - 1);
    }
  }
  return 0;
}
