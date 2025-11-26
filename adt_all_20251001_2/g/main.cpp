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
  for(int d = 1; d <= 1000000; d++){
    if(n % d != 0) continue;
    __int128_t l = 1, r = 1ll << 40;
    while(r - l > 1){
      __int128_t y = (l + r) / 2;
      ((y + d) * (y + d) * (y + d) - y * y * y <= n ? l : r) = y;
    }
    if((l + d) * (l + d) * (l + d) - l * l * l == n){
      cout << (int)(l + d) << ' ' << (int)l << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
/*
x^3 - y^3 = (x - y) * (x^2 + xy + y^2)
x - y > 10^6 => x > 10^6 =>x^2 >= 10^12

x - y <= 10^6

x - y = dよりx = d + y
*/