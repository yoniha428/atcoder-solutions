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
  int n; cin >> n;
  vector<int> p(1ll << n); for(auto&& pi : p) cin >> pi;
  rep(b, n + 1) for(int a = 0; (a + 1) * (1ll << b) <= (1ll << n); a++){
    vector<int> q(p.begin() + (a * (1ll << b)), p.begin() + ((a + 1) * (1ll << b))), qrev(q);
    reverse(all(qrev));
    // for(auto& qi : q) print("{} ", qi);
    // println();
    if(qrev < q) reverse(p.begin() + (a * (1ll << b)), p.begin() + ((a + 1) * (1ll << b)));
  }
  for(auto& pi : p) print("{} ", pi);
  println();
}

signed main(){
  int t; cin >> t;
  while(t--) solve();
}
