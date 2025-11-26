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
  int n, p, k; cin >> n >> p >> k;
  vector a(n, vector<int>(n));
  for(auto&& ai : a) for(auto&& aij : ai) cin >> aij;
  int ans1, ans2;
  int l = 0, r = 2e9;
  while(r - l > 1){
    int mid = (r + l) / 2;
    vector d(n, vector<int>(n));
    rep(i, n) rep(j, n) d.at(i).at(j) = (a.at(i).at(j) == -1 ? mid : a.at(i).at(j));
    rep(k, n) rep(i, n) rep(j, n) chmin(d.at(i).at(j), d.at(i).at(k) + d.at(k).at(j));
    int cnt = 0;
    rep(j, n) rep(i, j) cnt += d.at(i).at(j) <= p;
    (cnt < k ? r : l) = mid;
  }
  ans1 = r;
  l = 0, r = 2e9;
  while(r - l > 1){
    int mid = (r + l) / 2;
    vector d(n, vector<int>(n));
    rep(i, n) rep(j, n) d.at(i).at(j) = (a.at(i).at(j) == -1 ? mid : a.at(i).at(j));
    rep(k, n) rep(i, n) rep(j, n) chmin(d.at(i).at(j), d.at(i).at(k) + d.at(k).at(j));
    int cnt = 0;
    rep(j, n) rep(i, j) cnt += d.at(i).at(j) <= p;
    (cnt <= k ? r : l) = mid;
  }
  ans2 = r;
  if(ans1 == 2e9 && ans2 != 2e9) cout << "Infinity" << '\n';
  else cout << ans1 - ans2 << '\n';
}
/*
X=1のときの組がK未満なら0
*/