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
  int n, m, l; cin >> n >> m >> l;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  vector cost(l, vector<int>(m, 0));
  rep(i, l) rep(j, m){
    for(int k = i; k < n; k += l) cost.at(i).at(j) += (j - a.at(k) + m) % m;
  }
  vector dp(l + 1, vector<int>(m, 1ll << 60)); dp.at(0).at(0) = 0;
  rep(i, l) rep(j, m){
    rep(k, m) chmin(dp.at(i + 1).at((j + k) % m), dp.at(i).at(j) + cost.at(i).at(k));
  }
  cout << dp.at(l).at(0) << '\n';
}
/*
modLで分解して、modMでDPするみたいな？
*/
