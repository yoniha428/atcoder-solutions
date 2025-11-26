#if __has_include(<yoniha/all.h>)
#include <yoniha/all.h>
using namespace atcoder;
#else
#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#endif
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)((n) - 1); i >= 0; i--)
template <typename T> bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template <typename T> bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

// using mint = modint;

signed main(){
  int q; cin >> q;
  string s;
  int x = 0, minus_cnt = 0;
  while(q--){
    int op; cin >> op;
    if(op == 1){
      char c; cin >> c;
      s += c;
      if(c == '('){
        x++;
      }
      else{
        x--;
        if(x == -1) minus_cnt++;
      }
    }
    if(op == 2){
      char c = s.back();
      if(c == '(') x--;
      else{
        x++;
        if(x == 0) minus_cnt--;
      }
      s.pop_back();
    }
    cout << (x == 0 && minus_cnt == 0 ? "Yes" : "No") << '\n';
  }
}
