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
  int n, h; cin >> n >> h;
  vector<tuple<int, int, int>> tlu(n); for(auto&& [t, l, u] : tlu) cin >> t >> l >> u;
  int t_before = 0, f_l = h, f_r = h;
  bool ok = true;
  for(auto [t, l, u] : tlu){
    int f_l_n = f_l - (t - t_before), f_r_n = f_r + (t - t_before);
    ok &= !(u < f_l_n || l > f_r_n); // [l, r], [nl, nr]が共通部分を持たない
    t_before = t;
    f_l = max(f_l_n, l);
    f_r = min(f_r_n, u);
  }
  println("{}", ok ? "Yes" : "No");
}

signed main(){
  int t; cin >> t;
  while(t--) solve();
}
