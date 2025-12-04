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
  vector<pair<int, int>> ab(m); for(auto&& [a, b] : ab) cin >> a >> b, a--, b--;
  int k; cin >> k;
  vector<pair<int, int>> cd(k); for(auto&& [c, d] : cd) cin >> c >> d, c--, d--;
  int ans = 0;
  rep(i, 1ll << k){
    vector<bool> dish(n, false);
    rep(j, k){
      auto [c, d] = cd.at(j);
      dish.at(i >> j & 1 ? c : d) = true;
    }
    int cnt = 0;
    rep(j, m){
      auto [a, b] = ab.at(j);
      cnt += dish.at(a) && dish.at(b);
    }
    chmax(ans, cnt);
  }
  cout << ans << '\n';
}
