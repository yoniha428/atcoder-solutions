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
  if(k == 1){
    cout << "Infinity" << '\n';
    return 0;
  }
  vector<pair<int, int>> xy(n); for(auto&& [x, y] : xy) cin >> x >> y;
  set<tuple<int, int, int>> ans;
  rep(j, n) rep(i, j){
    auto& [xi, yi] = xy.at(i);
    auto& [xj, yj] = xy.at(j);
    int a = xj - xi, b = -(yj - yi), c = xi * (yj - yi) - yi * (xj - xi);
    int g = gcd(a, gcd(b, c));
    a /= g; b /= g; c /= g;
    if(a < 0 || (a == 0 && b < 0)){
      a *= -1; b *= -1; c *= -1;
    }
    int cnt = 0;
    rep(l, n){
      auto& [xk, yk] = xy.at(l);
      cnt += a * yk + b * xk + c == 0;
    }
    if(cnt >= k) ans.emplace(a, b, c);
  }
  // for(auto& [a, b, c] : ans) cout << a << ' ' << b << ' ' << c << '\n';
  cout << ans.size() << '\n';
}
/*
候補がN^2くらいある
それぞれK個以上か調べるのにNで、合計N^3
だが、同一直線を重複して数えてしまう

ax+by+c=0として、a>=0かつaとbとcが互いに素になるようにすれば一意？
*/