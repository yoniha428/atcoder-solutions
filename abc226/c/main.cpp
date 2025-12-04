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
  vector<int> t(n);
  vector a(n, vector<int>());
  rep(i, n){
    auto&& ai = a.at(i);
    cin >> t.at(i);
    int k; cin >> k;
    ai.resize(k);
    for(auto&& aij : ai) cin >> aij, aij--;
  }
  vector need(n, false); need.at(n - 1) = true;
  int ans = 0;
  rrep(i, n){
    if(!need.at(i)) continue;
    ans += t.at(i);
    for(auto&& aij : a.at(i)) need.at(aij) = true;
  }
  cout << ans << '\n';
}
