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
  int n, m, k; cin >> n >> m >> k; k -= n;
  vector dp(n + 1, vector<mint>(k + 1));
  dp.at(0).at(0) = 1;
  rep(i, n){
    rep(j, k + 1) rep(l, m) if(j + l <= k) dp.at(i + 1).at(j + l) += dp.at(i).at(j);
  }
  cout << reduce(all(dp.at(n))).val() << '\n';
}
