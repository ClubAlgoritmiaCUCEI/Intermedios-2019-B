#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int a[N], b[N];
int n;

int main(){
  while( cin >> n ){
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector< pair<int, int> > p;
    for (int i = 0; i < n; i++) {
      int j = i;
      while( j < n && b[j] != a[i] ){
        j++;
      }
      while( j > i ){
        p.push_back({j - 1, j});
        swap(b[j], b[j - 1]);
        j--;
      }
    }
    cout << p.size() << '\n';
    for (auto &[i, j]: p) {
      cout << i + 1 << " " << j + 1 << '\n';
    }
  }
  return 0;
}
