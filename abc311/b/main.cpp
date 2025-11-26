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
  int n, d; cin >> n >> d;
  vector<string> s(n); for(auto&& si : s) cin >> si;
  vector<bool> f(d);
  rep(i, d){
    bool ok = true;
    rep(j, n) ok &= s.at(j).at(i) == 'o';
    f.at(i) = ok;
  }
  vector<pair<bool, int>> rle;
  for(auto fi : f){
    if(rle.empty() || rle.back().first != fi) rle.emplace_back(fi, 1);
    else rle.back().second++;
  }
  int ans = 0;
  for(auto [fi, len] : rle) chmax(ans, fi * len);
  cout << ans << '\n';
}
