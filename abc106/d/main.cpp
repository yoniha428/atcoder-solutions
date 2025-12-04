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
  int n, m, q; cin >> n >> m >> q;
  vector g(n, vector<int>());
  while(m--){
    int l, r; cin >> l >> r; l--; r--;
    g.at(l).emplace_back(r);
  }
  for(auto&& gi : g) sort(all(gi));
  while(q--){
    int l, r; cin >> l >> r; l--; r--;
    int ans = 0;
    for(int i = l; i <= r; i++){
      ans += upper_bound(all(g.at(i)), r) - g.at(i).begin();
    }
    cout << ans << '\n';
  }
}
/*
左端全探索、右端二分探索で間に合いそう

*/
