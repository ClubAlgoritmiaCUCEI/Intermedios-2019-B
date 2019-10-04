#include <bits/stdc++.h>
using namespace std;

stack<int> stk;
int n;

int main(){
  while( cin >> n ){
    int cur = 1, reorder = 0;
    stk = stack<int>();
    for (int i = 0; i < 2 * n; i++) {
      string todo; int x;
      cin >> todo;
      if( todo == "add" ){
        cin >> x;
        stk.push(x);
      }else{
        if( stk.size() ){
          if( stk.top() == cur ){
            stk.pop();
          }else{
            stk = stack<int>();
            reorder++;
          }
        }
        cur++;
      }
    }
    cout << reorder << '\n';
  }
  return 0;
}
