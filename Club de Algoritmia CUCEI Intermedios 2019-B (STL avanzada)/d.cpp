#include <bits/stdc++.h>
using namespace std;

set<string> st;
int n;

int main(){
  while( cin >> n ){
    st.clear();
    while( n-- ){
      string a, b;
      cin >> a >> b;
      st.insert(a + "#" + b + "$");
    }
    cout << st.size() << '\n';
  }
  return 0;
}
