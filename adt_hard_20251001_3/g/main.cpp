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
  int a, b; cin >> a >> b;
  int l = 0, r = 1.1e18;
  auto f = [&](double t) -> double{
    return b * t + a / sqrt(1 + t);
  };
  // int cnt = 500;
  while(r - l > 2){
    double c1 = ((double)l * 2 + (double)r) / 3;
    double c2 = ((double)l + (double)r * 2) / 3;

    if(f(c1) > f(c2)) l = c1;
    else r = c2;
  }
  // cout << l << ' ' << r << '\n';
  cout << fixed << setprecision(30) << min(f(l), f(l + 1)) << '\n';
}
/*
合計でかかる時間はB*t+A/sqrt(1+t)
ある答えxが達成可能かを高速に判定できますか？

微分するとA+B/2*(1+t)^(2/3)
*/
