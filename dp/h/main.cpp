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

using mint = modint1000000007;

signed main(){
  int h, w; cin >> h >> w;
  vector<string> s(h); for(auto&& si : s) cin >> si;
  vector ans(h, vector<mint>(w, 0)); ans.at(0).at(0) = 1;
  rep(i, h) rep(j, w){
    if(i + 1 < h && s.at(i + 1).at(j) == '.') ans.at(i + 1).at(j) += ans.at(i).at(j);
    if(j + 1 < w && s.at(i).at(j + 1) == '.') ans.at(i).at(j + 1) += ans.at(i).at(j);
  }
  cout << ans.at(h - 1).at(w - 1).val() << '\n';
}
