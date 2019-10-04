#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;
int n;

int main(){
  while( cin >> n ){
    int visible = 0;
    cnt.clear();
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      visible = max(visible, ++cnt[x]);
    }
    cout << visible << '\n';
  }
  return 0;
}
