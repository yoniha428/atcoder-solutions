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
  int n, q; cin >> n >> q;
  vector<int> red(n, 0), yellow(n, 0);
  while(q--){
    int op, x; cin >> op >> x; x--;
    if(op == 1) yellow.at(x)++;
    if(op == 2) red.at(x)++;
    if(op == 3) cout << (yellow.at(x) >= 2 || red.at(x) >= 1 ? "Yes" : "No") << '\n';
  }
}
