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
  int n, k; cin >> n >> k;
  vector<string> s(n); for(auto&& si : s) cin >> si;
  int ans = 0;
  rep(i, 1ll << n){
    vector<int> cnt(26, 0);
    rep(j, n) if(i >> j & 1) for(auto c : s.at(j)) cnt.at(c - 'a')++;
    int nans = 0;
    rep(j, 26) nans += cnt.at(j) == k;
    chmax(ans, nans);
  }
  cout << ans << '\n';
}
