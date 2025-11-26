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

using mint = modint998244353;

signed main(){
  int n, x; cin >> n >> x;
  vector<int> t(n); for(auto&& ti : t) cin >> ti;
  vector<mint> dp(x + 1);
  dp.at(0) = 1;
  mint ans = 0, ninv = mint(n).inv();
  rep(i, x + 1){
    if(i + t.at(0) > x) ans += dp.at(i) * ninv;
    for(auto ti : t) if(i + ti <= x) dp.at(i + ti) += dp.at(i) * ninv;
  }
  cout << ans.val() << '\n';
}
/*
ある時刻において曲が始まる瞬間である確率が出る
*/
