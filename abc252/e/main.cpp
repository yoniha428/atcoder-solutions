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
  vector g(n, vector<tuple<int, int, int>>());
  rep(i, m){
    int a, b, c; cin >> a >> b >> c; a--; b--;
    g.at(a).emplace_back(b, c, i);
    g.at(b).emplace_back(a, c, i);
  }
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> dijk; // 現在のコスト、辺の番号、どこへ行くか
  dijk.emplace(0, -1, 0);
  const int inf = 1ll << 60;
  vector<int> d(n, inf); d.at(0) = 0;
  vector<int> ans;
  while(!dijk.empty()){
    auto [cost, edge_idx, from] = dijk.top(); dijk.pop();
    if(edge_idx != -1){
      if(d.at(from) < cost) continue;
      ans.emplace_back(edge_idx);
    }
    for(auto [to, c, j] : g.at(from)){
      if(chmin(d.at(to), cost + c)) dijk.emplace(cost + c, j, to);
    }
  }
  
  for(auto i : ans) cout << i + 1 << ' ';
  cout << '\n';
}
/*

*/
