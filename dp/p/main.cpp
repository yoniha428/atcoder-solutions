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

using mint = modint1000000007;

signed main(){
  int n; cin >> n;
  vector<vector<int>> g(n);
  rep(i, n - 1){
    int x, y; cin >> x >> y;
    x--; y--;
    g.at(x).emplace_back(y);
    g.at(y).emplace_back(x);
  }
  vector dp(n, vector<mint>(2, 0));
  auto dfs = [&](auto dfs, int root, int from) -> void{
    mint white_prod = 1, all_prod = 1;
    for(auto to : g.at(from)){
      if(to == root) continue;
      dfs(dfs, from, to);
      white_prod *= dp.at(to).at(0);
      all_prod *= dp.at(to).at(0) + dp.at(to).at(1);
    }
    dp.at(from).at(0) = all_prod;
    dp.at(from).at(1) = white_prod;
  };
  dfs(dfs, -1, 0);
  // cout << dp.at(0).at(0).val() << ' ' << dp.at(0).at(1).val() << '\n';
  cout << (dp.at(0).at(0) + dp.at(0).at(1)).val() << '\n';
}
/*
ある頂点を黒で塗るパターンは子をすべて白で塗るパターンの総積
ある頂点を白で塗るパターンはすべてのパターンの総積
*/
