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

void solve(){
  int n, m; cin >> n >> m;
  vector<int> color(n); for(auto&& ci : color) cin >> ci;
  vector edges(n, vector<int>());
  while(m--){
    int u, v; cin >> u >> v; u--; v--;
    edges.at(u).emplace_back(v);
    edges.at(v).emplace_back(u);
  }
  vector g(n, vector(n, vector<pair<int, int>>()));
  rep(fi, n) rep(fj, n){
    for(auto ti : edges.at(fi)) for(auto tj : edges.at(fj)){
      if(color.at(ti) != color.at(tj)) g.at(fi).at(fj).emplace_back(ti, tj);
    }
  }
  vector d(n, vector<int>(n, -1)); d.at(0).at(n - 1) = 0;
  deque<pair<int, int>> bfs{{0, n - 1}};
  while(!bfs.empty()){
    auto [fi, fj] = bfs.front(); bfs.pop_front();
    for(auto [ti, tj] : g.at(fi).at(fj)){
      if(d.at(ti).at(tj) != -1) continue;
      d.at(ti).at(tj) = d.at(fi).at(fj) + 1;
      bfs.emplace_back(ti, tj);
    }
  }
  cout << d.at(n - 1).at(0) << '\n';
}

signed main(){
  int t; cin >> t;
  while(t--) solve();
}
/*
n*n個の頂点だと思う

*/
