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
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  vector dp(n + 1, vector(2, map<int, int>()));
  dp.at(0).at(0).emplace(0, 1);
  rep(i, n){
    // i番目を使わないパターン
    rep(j, 2) for(auto [val, cnt] : dp.at(i).at(j)){
      if(dp.at(i + 1).at(0).contains(val)) dp.at(i + 1).at(0).at(val) += cnt;
      else dp.at(i + 1).at(0).emplace(val, cnt);
    }
    // 使うパターン
    for(auto [val, cnt] : dp.at(i).at(0)){
      int sum = (val + a.at(i)) % m;
      // if(dp.at(i + 1).at(1).contains(sum)) dp.at(i + 1).at(1).at(sum) += cnt;
      dp.at(i + 1).at(1).emplace(sum, cnt);
    }
  }
  // rep(i, n + 1){
  //   cout << "i = " << i << '\n';
  //   rep(j, 2){
  //     cout << "j = " << j << '\n';
  //     for(auto [val, cnt] : dp.at(i).at(j)) cout << val << ": " << cnt << '\n';
  //   }
  //   cout << '\n';
  // }
  cout << dp.at(n).at(0).at(0) + (dp.at(n).at(1).contains(0) ? dp.at(n).at(1).at(0) : 0) << '\n';
  rep(i, 60) cout << (1ll << i) << ' ';
  cout << '\n';
}
/*

*/