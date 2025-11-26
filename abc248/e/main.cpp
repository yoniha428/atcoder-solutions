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
  int n, k; cin >> n >> k;
  if(k == 1){
    cout << "Infinity" << '\n';
    return 0;
  }
  vector<pair<int, int>> xy(n); for(auto&& [x, y] : xy) cin >> x >> y;
  vector<vector<int>> ans;
  rep(j, n) rep(i, j){
    auto [xi, yi] = xy.at(i);
    auto [xj, yj] = xy.at(j);
    vector<int> index;
    rep(l, n){
      auto [xk, yk] = xy.at(l);
      if((yk - yi) * (xj - xi) == (yj - yi) * (xk - xi)) index.emplace_back(l);
    }
    if((int)index.size() >= k) ans.emplace_back(index);
  }
  sort(all(ans)); ans.erase(unique(all(ans)), ans.end());
  cout << ans.size() << '\n';
}
