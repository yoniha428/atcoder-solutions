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
  int n, k; cin >> n >> k;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  // lazy_segtree<mint,
  //   [](mint a, mint b) -> mint {return mint(0);},
  //   []() -> mint {return mint(0);},
  //   mint,
  //   [](mint f, mint x) -> mint {return f + x;},
  //   [](mint f, mint g) -> mint {return f + g;},
  //   []() -> mint {return mint(0);}> b(0);
  // segtree<mint, [](mint a, mint b){return a + b;}, []{return mint(0);}> c;
  vector dp(n + 1, lazy_segtree<mint,
    [](mint a, mint b){return mint(0);},
    []{return mint(0);},
    mint,
    [](mint f, mint x){return f + x;},
    [](mint f, mint g){return f + g;},
    []{return mint(0);}>(k + 1));
  dp.at(0).set(0, mint(1));
  rep(i, n){
    rep(j, k + 1) dp.at(i + 1).apply(j, min(j + a.at(i) + 1, k + 1), dp.at(i).get(j));
  }
  cout << dp.at(n).get(k).val() << '\n';
}
/*
dp[i][j]=i個見てj個あげたときの場合の数
とすると、iからi+1への寄与はrange_add？
*/