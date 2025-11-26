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
  int n, d; cin >> n >> d;
  vector<pair<int, int>> xy(n); for(auto&& [x, y] : xy) cin >> x >> y;
  dsu uf(n);
  rep(j, n) rep(i, j){
    auto&& [xi, yi] = xy.at(i);
    auto&& [xj, yj] = xy.at(j);
    if((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) <= d * d) uf.merge(i, j);
  }
  auto vv = uf.groups();
  vector<bool> ans(n, false);
  for(auto&& v : vv){
    bool f = false;
    for(auto&& i : v) f |= i == 0;
    if(f) for(auto&& i : v) ans.at(i) = true;
  }
  for(auto&& i : ans) println("{}", i ? "Yes" : "No");
}
