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
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  int ydiff = abs(sy - ty);
  const int inf = 1ll << 60;
  bool isleft = (sx + inf) % 2 == (sy + inf) % 2;
  int xmin = sx - ydiff - !isleft; // タイルの右半分にいるか？
  int xmax = sx + ydiff + isleft;
  int x = 0;
  if(tx > xmax){
    bool isleftxmax = (xmax + inf) % 2 == (ty + inf) % 2;
    bool isleftt = (tx + inf) % 2 == (ty + inf) % 2;
    if(!isleftxmax) xmax--;
    if(!isleftt) tx--;
    x = (tx - xmax) / 2;
  }
  if(tx < xmin){
    bool isleftxmin = (xmin + inf) % 2 == (ty + inf) % 2;
    bool isleftt = (tx + inf) % 2 == (ty + inf) % 2;
    if(!isleftxmin) xmin--;
    if(!isleftt) tx--;
    x = (xmin - tx) / 2;
  }
  cout << ydiff + x << '\n';
}
