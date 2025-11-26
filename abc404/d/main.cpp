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
  vector<int> c(2 * n); for(auto&& ci : c | views::take(n)) cin >> ci;
  rep(i, n) c.at(n + i) = c.at(i);
  vector f(2 * n, vector<bool>(m, false));
  rep(i, m){
    int k; cin >> k;
    while(k--){
      int a; cin >> a; a--;
      f.at(a).at(i) = f.at(n + a).at(i) = true;
    }
  }
  int ans = 1ll << 60;
  rep(i, 1ll << (2 * n)){
    vector<int> cnt(m, 0);
    rep(j, 2 * n) if(i >> j & 1) rep(k, m) if(f.at(j).at(k)) cnt.at(k)++;
    bool ok = true;
    for(auto i : cnt) ok &= i >= 2;
    if(ok){
      int nans = 0;
      rep(j, 2 * n) if(i >> j & 1) nans += c.at(j);
      chmin(ans, nans);
    }
  }
  cout << ans << '\n';
}
