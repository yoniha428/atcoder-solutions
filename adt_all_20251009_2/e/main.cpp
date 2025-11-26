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
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for(auto&& ai : a) cin >> ai;
  for(auto&& bi : b) cin >> bi;
  sort(all(a)); sort(all(b));
  int ans = 1ll << 60;
  for(auto ai : a){
    if(upper_bound(all(a), ai) - a.begin() >= b.end() - lower_bound(all(b), ai)) chmin(ans, ai);
  }
  for(auto bi : b){
    if(upper_bound(all(a), bi + 1) - a.begin() >= b.end() - lower_bound(all(b), bi + 1)) chmin(ans, bi + 1);
  }
  println("{}", ans);
}
