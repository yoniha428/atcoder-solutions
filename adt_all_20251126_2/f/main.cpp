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
  vector<int> a(n), b(n);
  for(auto&& ai : a) cin >> ai;
  for(auto&& bi : b) cin >> bi;
  sort(all(a), greater()); sort(all(b), greater());
  int sum = 0, ans = n;
  rep(i, n){
    sum += a.at(i);
    if(sum > x) chmin(ans, i + 1);
  }
  sum = 0;
  rep(i, n){
    sum += b.at(i);
    if(sum > y) chmin(ans, i + 1);
  }
  println("{}", ans);
}
