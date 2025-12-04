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
  int n, m; cin >> n >> m;
  vector<tuple<int, int, int>> xyz(n);
  for(auto&& [x, y, z] : xyz) cin >> x >> y >> z;
  int ans = 0;
  rep(i, 1 << 3){
    vector<int> sign(3);
    rep(j, 3) sign.at(j) = (i >> j & 1 ? 1 : -1);
    vector dp(n + 1, vector<int>(m + 1, -(1ll << 60)));
    dp.at(0).at(0) = 0;
    rep(j, n){
      dp.at(j + 1) = dp.at(j);
      auto [x, y, z] = xyz.at(j);
      rep(k, m) chmax(dp.at(j + 1).at(k + 1), dp.at(j).at(k) + x * sign.at(0) + y * sign.at(1) + z * sign.at(2));
    }
    chmax(ans, dp.at(n).at(m));
  }
  cout << ans << '\n';
}
/*
x, y, zそれぞれについて、和の正負でパターン分けすると2^3通り
全部についてN*MのDPで解けるかなと思ったが、正負が設定通りにならない可能性がある
設定通りになったのだけ見ると、ちょろっと調整みたいな反例がありそう
負になったとしたら、そこの符号だけ反転したときの答えが明らかにこれより得なので問題ない
*/