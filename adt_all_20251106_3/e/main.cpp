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
  int n, k, t; cin >> n >> k >> t;
  vector<int> p(n); for(auto&& pi : p) cin >> pi;
  vector<int> presum(n + 1, 0); rep(i, n) presum.at(i + 1) = presum.at(i) + p.at(i);
  vector dp(n + 1, vector<int>(k + 1, 1ll << 60));
  dp.at(0).at(0) = 0;
  rep(i, n){
    rep(j, k + 1) chmin(dp.at(i + 1).at(j), dp.at(i).at(j));
    if(i + t <= n) rep(j, k) chmin(dp.at(i + t).at(j + 1), dp.at(i).at(j) + presum.at(i + t) - presum.at(i));
  }
  println("{}", dp.at(n).at(k));
}
