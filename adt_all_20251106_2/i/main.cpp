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
  const int inf = 1ll << 60;
  vector<pair<int, int>> xy(n + q, {inf, inf}); for(auto&& [x, y] : xy | views::take(n)) cin >> x >> y;
  dsu d(n + q);
  while(q--){
    int op; cin >> op;
    if(op == 1){
      auto&& [x, y] = xy.at(n);
      cin >> x >> y;
      n++;
    }
    if(op == 2){
      auto vv = d.groups();
      bool same = false;
      for(auto& v : vv) same |= v.size() == n;
      if(same){
        println("-1");
        continue;
      }
      int min_d = inf;
      rep(j, n) rep(i, j){
        if(d.same(i, j)) continue;
        auto&& [xi, yi] = xy.at(i);
        auto&& [xj, yj] = xy.at(j);
        chmin(min_d, abs(xi - xj) + abs(yi - yj));
      }
      rep(j, n) rep(i, j){
        auto&& [xi, yi] = xy.at(i);
        auto&& [xj, yj] = xy.at(j);
        if(abs(xi - xj) + abs(yi - yj) == min_d) d.merge(i, j);
      }
      println("{}", min_d);
    }
    if(op == 3){
      int u, v; cin >> u >> v; u--; v--;
      println("{}", d.same(u, v) ? "Yes" : "No");
    }
  }
}
