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
  vector<int> l, r;
  rep(i, 1ll << (n / 2)){
    int sum = 0;
    rep(j, n / 2) if(i >> j & 1) sum += a.at(j);
    l.emplace_back(sum);
  }
  rep(i, 1ll << (n - n / 2)){
    int sum = 0;
    rep(j, n - n / 2) if(i >> j & 1) sum += a.at(n - 1 - j);
    r.emplace_back(sum);
  }
  sort(all(r));
  int ans = 0;
  for(auto i : l){
    if(i > t) continue;
    chmax(ans, *--upper_bound(all(r), t - i) + i);
  }
  cout << ans << '\n';
}
