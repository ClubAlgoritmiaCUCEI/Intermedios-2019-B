#include <bits/stdc++.h>
using namespace std;

set<string> st;
string s;
int n;

int main(){
  while( cin >> n ){
    st.clear();
    while( n-- ){
      cin >> s;
      if( st.count(s) ){
        cout << "YES\n";
      }else{
        cout << "NO\n";
        st.insert(s);
      }
    }
  }
  return 0;
}
