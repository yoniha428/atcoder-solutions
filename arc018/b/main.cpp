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
  vector<pair<int, int>> xy(n); for(auto&& [x, y] : xy) cin >> x >> y;
  int ans = 0;
  rep(k, n) rep(j, k) rep(i, j){
    auto [xi, yi] = xy.at(i);
    auto [xj, yj] = xy.at(j);
    auto [xk, yk] = xy.at(k);
    xj -= xi; xk -= xi;
    yj -= yi; yk -= yi;
    ans += (xj * yk - yj * xk) % 2 == 0 && (xj * yk - yj * xk) != 0;
  }
  cout << ans << '\n';
}
