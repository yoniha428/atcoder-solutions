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
  vector<string> s(n), t(n);
  for(auto&& si : s) cin >> si;
  for(auto&& ti : t) cin >> ti;
  int ans = n * n;
  rep(rot, 4){
    int nans = rot;
    rep(i, n) rep(j, n) nans += s.at(i).at(j) != t.at(i).at(j);
    chmin(ans, nans);
    vector<string> tnew(t);
    rep(i, n) rep(j, n) tnew.at(i).at(j) = t.at(j).at(n - 1 - i);
    t = tnew;
  }
  cout << ans << '\n';
}
