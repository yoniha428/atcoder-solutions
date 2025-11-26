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
  int n; cin >> n;
  dsu d(n);
  rep(i, n - 1){
    int u, v; cin >> u >> v; u--; v--;
    if(u != 0) d.merge(u, v);
  }
  auto vv = d.groups();
  int ans = 1ll << 60;
  for(auto& v : vv) chmin(ans, n - (int)v.size());
  println("{}", ans);
}
/*
ある頂点を削除するためには、その頂点の次数を1にする必要がある

*/
