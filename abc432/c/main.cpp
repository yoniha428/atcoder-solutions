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
  int n, x, y; cin >> n >> x >> y;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  bool ok = true;
  int d = y - x, mod = a.at(0) * x % d;
  for(auto ai : a) ok &= ai * x % d == mod;
  if(!ok){
    println("-1");
    return 0;
  }
  int l = 0, r = 1ll << 60;
  for(auto ai : a){
    chmax(l, ai * x);
    chmin(r, ai * x + ai * d);
  }
  if(l > r){
    println("-1");
    return 0;
  }
  int ans = 0;
  for(auto ai : a) ans += (r - ai * x) / d;
  println("{}", ans);
}
/*
人iに配る飴の質量は、d=y-xとして、ai*x, ai*x+d, ai*x+2*d, ..., ai*x+ai*d
つまりdで割った余りは変化しない
*/