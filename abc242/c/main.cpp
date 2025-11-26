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

using mint = modint998244353;

signed main(){
  int n; cin >> n;
  vector dp(n, vector<mint>(9, 0));
  rep(i, 9) dp.at(0).at(i) = 1;
  rep(i, n - 1){
    rep(j, 9){
      if(j != 0) dp.at(i + 1).at(j - 1) += dp.at(i).at(j);
      if(j != 8) dp.at(i + 1).at(j + 1) += dp.at(i).at(j);
      dp.at(i + 1).at(j) += dp.at(i).at(j);
    }
  }
  cout << reduce(all(dp.at(n - 1))).val() << '\n';
}
