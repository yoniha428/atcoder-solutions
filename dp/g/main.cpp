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
  scc_graph s(n);
  vector g(n, vector<int>());
  while(m--){
    int x, y; cin >> x >> y; x--; y--;
    s.add_edge(x, y);
    g.at(x).emplace_back(y);
  }
  auto vv = s.scc();
  reverse(all(vv));
  vector<int> d(n, 0);
  for(auto v : vv){
    assert(v.size() == 1);
    int from = v.at(0);
    for(auto to : g.at(from)) chmax(d.at(from), d.at(to) + 1);
  }
  cout << *max_element(all(d)) << '\n';
}
