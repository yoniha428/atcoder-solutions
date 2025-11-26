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
  int n; cin >> n;
  vector<double> a(n); for(auto&& ai : a) cin >> ai;
  vector dp(n + 1, vector<double>(n + 1, -1e10));
  dp.at(0).at(0) = 0;
  rep(i, n){
    dp.at(i + 1) = dp.at(i);
    rep(j, n) if(dp.at(i).at(j) != -1e10) chmax(dp.at(i + 1).at(j + 1), dp.at(i).at(j) * 0.9 + a.at(i));
  }
  double ans = -1e10;
  for(int i = 1; i <= n; i++){
    double bunshi = 0, rat = 1;
    rep(j, i){
      bunshi += rat;
      rat *= 0.9;
    }
    chmax(ans, dp.at(n).at(i) / bunshi - 1200 / sqrt(i));
  }
  // rep(i, n + 1) print("{} ", dp.at(n).at(i));
  // println();
  println("{:.30f}", ans);
}
/*
dp[i][j][k]=i番目まで見てj個見た
*/
