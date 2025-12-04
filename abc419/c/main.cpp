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
  const int inf = 1ll << 60;
  int rmin = inf, rmax = -inf, cmin = inf, cmax = -inf;
  while(n--){
    int r, c; cin >> r >> c;
    chmin(rmin, r); chmax(rmax, r);
    chmin(cmin, c); chmax(cmax, c);
  }
  cout << (max(rmax - rmin, cmax - cmin) + 1) / 2 << '\n';
}
