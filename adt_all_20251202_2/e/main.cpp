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
  int n, m; cin >> n >> m;
  vector a(m, vector<int>());
  for(auto&& ai : a){
    int c; cin >> c;
    ai.resize(c);
    for(auto&& aij : ai) cin >> aij, aij--;
  }
  int ans = 0;
  rep(i, 1ll << m){
    if(i == 0) continue;
    vector<bool> f(n, false);
    rep(j, m) if(i >> j & 1){
      auto&& ai = a.at(j);
      for(auto aij : ai) f.at(aij) = true;
    }
    ans += reduce(all(f), 0ll) == n;
  }
  println("{}", ans);
}
