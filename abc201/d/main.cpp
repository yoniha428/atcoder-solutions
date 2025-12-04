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
  int h, w; cin >> h >> w;
  vector<string> s(h); for(auto&& si : s) cin >> si;
  vector dp(h, vector<int>(w, 0));
  rrep(i, h) rrep(j, w){
    if(i == h - 1 && j == w - 1) continue;
    if((i + j) % 2 == 0){
      int ma = -(1ll << 60);
      if(i != h - 1) chmax(ma, dp.at(i + 1).at(j) + (s.at(i + 1).at(j) == '+' ? 1 : -1));
      if(j != w - 1) chmax(ma, dp.at(i).at(j + 1) + (s.at(i).at(j + 1) == '+' ? 1 : -1));
      dp.at(i).at(j) = ma;
    }
    else{
      int mi = (1ll << 60);
      if(i != h - 1) chmin(mi, dp.at(i + 1).at(j) + (s.at(i + 1).at(j) == '+' ? -1 : 1));
      if(j != w - 1) chmin(mi, dp.at(i).at(j + 1) + (s.at(i).at(j + 1) == '+' ? -1 : 1));
      dp.at(i).at(j) = mi;
    }
  }
  string ans = "Draw";
  if(dp.at(0).at(0) > 0) ans = "Takahashi";
  if(dp.at(0).at(0) < 0) ans = "Aoki";
  cout << ans << '\n';
}
/*
右下から見ると最適行動が決まりそう
(i+j)%2でどちらのターンか決まる

a-bをaさんは最大化、bさんは最小化したい

*/
