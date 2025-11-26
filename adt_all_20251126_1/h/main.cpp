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
  const int inf = 1ll << 60;
  vector g(n + 1, vector<int>(n + 1, inf));
  rep(i, n + 1) g.at(i).at(i) = 0;
  while(m--){
    int a, b, c; cin >> a >> b >> c; a--; b--;
    chmin(g.at(a).at(b), 2 * c);
    chmin(g.at(b).at(a), 2 * c);
  }
  int k, t; cin >> k >> t;
  while(k--){
    int d; cin >> d; d--;
    g.at(d).at(n) = t;
    g.at(n).at(d) = t;
  }
  rep(k, n + 1) rep(i, n + 1) rep(j, n + 1){
    chmin(g.at(i).at(j), g.at(i).at(k) + g.at(k).at(j));
  }
  int q; cin >> q;
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int a, b, c; cin >> a >> b >> c; a--; b--;
      chmin(g.at(a).at(b), 2 * c);
      chmin(g.at(b).at(a), 2 * c);
      for(auto k : {a, b}) rep(i, n + 1) rep(j, n + 1){
        chmin(g.at(i).at(j), g.at(i).at(k) + g.at(k).at(j));
      }
    }
    if(op == 2){
      int d; cin >> d; d--;
      chmin(g.at(d).at(n), t);
      chmin(g.at(n).at(d), t);
      for(auto k : {d, n}) rep(i, n + 1) rep(j, n + 1){
        chmin(g.at(i).at(j), g.at(i).at(k) + g.at(k).at(j));
      }
    }
    if(op == 3){
      int ans = 0;
      rep(i, n) rep(j, n) if(g.at(i).at(j) != inf) ans += g.at(i).at(j) / 2;
      println("{}", ans);
    }
  }
}
