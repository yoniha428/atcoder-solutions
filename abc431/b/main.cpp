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
  int x, n; cin >> x >> n;
  vector<int> w(n); for(auto&& wi : w) cin >> wi;
  vector<bool> f(n, false);
  int ans = x;
  int q; cin >> q;
  while(q--){
    int p; cin >> p; p--;
    ans += (f.at(p) ? -1 : 1) * w.at(p);
    println("{}", ans);
    f.at(p) = !f.at(p);
  }
}
