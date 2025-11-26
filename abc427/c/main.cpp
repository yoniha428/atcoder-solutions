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
  vector g(n, vector<bool>(n, false));
  while(m--){
    int u, v; cin >> u >> v;
    u--; v--;
    g.at(u).at(v) = true;
    g.at(v).at(u) = true;
  }
  int ans = 1ll << 60;
  rep(i, 1ll << n){
    vector<bool> color(n);
    rep(j, n) color.at(j) = i >> j & 1;
    int nans = 0;
    rep(i, n) rep(j, i) if(color.at(i) == color.at(j) && g.at(i).at(j)) nans++;
    chmin(ans, nans);
  }
  cout << ans << '\n';
}
