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
  int n, m, q; cin >> n >> m >> q;
  vector<tuple<int, int, int, int>> edges;
  while(m--){
    int a, b, c; cin >> a >> b >> c; a--; b--;
    edges.emplace_back(c, a, b, -1);
  }
  rep(i, q){
    int u, v, w; cin >> u >> v >> w; u--; v--;
    edges.emplace_back(w, u, v, i);
  }
  sort(all(edges));
  vector<bool> ans(q, false);
  dsu d(n);
  for(auto [c, u, v, i] : edges){
    if(d.same(u, v)) continue;
    if(i != -1) ans.at(i) = true;
    else d.merge(u, v);
  }
  for(auto i : ans) println("{}", i ? "Yes" : "No");
}
