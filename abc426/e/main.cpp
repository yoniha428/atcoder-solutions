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

void solve(){
  int a0x, a0y, a1x, a1y, b0x, b0y, b1x, b1y;
  cin >> a0x >> a0y >> a1x >> a1y >> b0x >> b0y >> b1x >> b1y;

  double a_time = hypot(a1x - a0x, a1y - a0y), b_time = hypot(b1x - b0x, b1y - b0y);
  double min_time = min(a_time, b_time), max_time = max(a_time, b_time);

  double ax = (a1x - a0x) / a_time, ay = (a1y - a0y) / a_time;
  double bx = (b1x - b0x) / b_time, by = (b1y - b0y) / b_time;
  
  auto f = [&](double t){
    double anowx, anowy, bnowx, bnowy;
    if(t <= a_time){
      anowx = a0x + t * ax;
      anowy = a0y + t * ay;
    }
    else{
      anowx = a1x;
      anowy = a1y;
    }
    if(t <= b_time){
      bnowx = b0x + t * bx;
      bnowy = b0y + t * by;
    }
    else{
      bnowx = b1x;
      bnowy = b1y;
    }
    return hypot(bnowx - anowx, bnowy - anowy);
  };

  double l = 0, r = min_time;
  while(r - l > 2e-12){
    double c1 = (l * 2 + r) / 3;
    double c2 = (l + r * 2) / 3;
    if (f(c1) > f(c2)) l = c1;
    else r = c2;
  }
  double ans = f(l);

  l = min_time; r = max_time;
  while(r - l > 2e-12){
    double c1 = (l * 2 + r) / 3;
    double c2 = (l + r * 2) / 3;
    if (f(c1) > f(c2)) l = c1;
    else r = c2;
  }
  chmin(ans, f(l));

  cout << fixed << setprecision(30) << ans << '\n';
}

signed main(){
  int t; cin >> t;
  while(t--) solve();
}
/*
2人の座標は時刻tでどうなる？
それぞれの方向の単位ベクトルをA, Bとして、
(1) t <= min(Aの時間、Bの時間)のとき A0+tA, B0+tB
(2) それ以外 Aのほうが早く着くならA1, B0+tB

もし距離関数が極値1つなら三分探索できそう
*/