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
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  int m; cin >> m;
  vector<int> b(m); for(auto&& bi : b) cin >> bi;
  int x; cin >> x;
  vector<bool> mochi(x + 1);
  for(auto bi : b) mochi.at(bi) = true;

  vector<bool> can(x + 1, false);
  can.at(0) = true;
  rep(i, x + 1){
    if(!can.at(i)) continue;
    for(auto ai : a){
      if(i + ai > x || mochi.at(i + ai)) continue;
      can.at(i + ai) = true;
    }
  }

  println("{}", can.at(x) ? "Yes" : "No");
}
