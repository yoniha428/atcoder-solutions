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
  int n, t; cin >> n >> t;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  int sum = reduce(all(a));
  t %= sum;
  int now = 0;
  rep(i, n){
    if(now + a.at(i) > t){
      println("{} {}", i + 1, t - now);
      return 0;
    }
    now += a.at(i);
  }
}
