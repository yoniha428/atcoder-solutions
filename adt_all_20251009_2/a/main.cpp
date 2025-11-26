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
  map<int, int> mx, my;
  rep(i, 3){
    int x, y; cin >> x >> y;
    if(mx.contains(x)) mx.at(x)++;
    else mx.emplace(x, 1);
    if(my.contains(y)) my.at(y)++;
    else my.emplace(y, 1);
  }
  int ax = 0, ay = 0;
  for(auto [x, c] : mx) if(c == 1) ax = x;
  for(auto [y, c] : my) if(c == 1) ay = y;
  println("{} {}", ax, ay);
}
