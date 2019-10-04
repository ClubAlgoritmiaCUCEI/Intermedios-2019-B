#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

pair<int, int> event[N];
int n;

int main(){
  while( cin >> n ){
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      event[i] = {a, b};
    }
    sort(event, event + n);
    pair<int, int> prev = event[0];
    int tot = 0;
    for (int i = 1; i < n; i++) {
      if( event[i].second < prev.second ){
        tot++;
      }else{
        prev = event[i];
      }
    }
    cout << tot << '\n';
  }
  return 0;
}
