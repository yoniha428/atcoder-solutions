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
  int h, w, n; cin >> h >> w >> n;
  vector<tuple<int, int, int>> rca(n);
  for(auto&& [r, c, a] : rca){
    cin >> r >> c >> a;
    r--; c--;
  }

  vector<vector<pair<int, int>>> vh(h), vw(w);
  rep(i, n){
    const auto& [r, c, a] = rca.at(i);
    vh.at(r).emplace_back(a, i);
    vw.at(c).emplace_back(a, i);
  }
  scc_graph scc(n);
  vector<vector<int>> g(n);
  for(auto& v : vh){
    sort(all(v));
    rep(i, v.size() - 1){
      auto itr = upper_bound(all(v), pair<int, int>{v.at(i).first, 1ll << 60});
      if(itr != v.end()){
        scc.add_edge(v.at(i).second, itr->second);
        g.at(itr->second).emplace_back(v.at(i).second);
      }
    }
  }
  for(auto& v : vw){
    sort(all(v));
    rep(i, v.size() - 1){
      auto itr = upper_bound(all(v), pair<int, int>{v.at(i).first, 1ll << 60});
      if(itr != v.end()){
        scc.add_edge(v.at(i).second, itr->second);
        g.at(itr->second).emplace_back(v.at(i).second);
      }
    }
  }
  auto vv = scc.scc();
  reverse(all(vv));
  vector<int> ans(n, 0);
  for(auto& v : vv){
    assert(v.size() == 1);
    int from = v.at(0);
    for(auto& to : g.at(from)) chmax(ans.at(to), ans.at(from) + 1);
  }
  rep(i, n) cout << ans.at(i) << '\n';
}
/*
同じ列または行&&Ai<Ajなる頂点i->jに辺を貼る

*/