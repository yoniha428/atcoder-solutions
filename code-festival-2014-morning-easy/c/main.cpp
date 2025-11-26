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
  int n, m, s, t; cin >> n >> m >> s >> t; s--; t--;
  vector g(n, vector<pair<int, int>>());
  while(m--){
    int x, y, d; cin >> x >> y >> d; x--; y--;
    g.at(x).emplace_back(y, d);
    g.at(y).emplace_back(x, d);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dijk;
  const int inf = 1ll << 60;
  vector<int> ds(n, inf), dt(ds);

  dijk.emplace(0, s);
  ds.at(s) = 0;
  while(!dijk.empty()){
    auto [cost, from] = dijk.top(); dijk.pop();
    if(ds.at(from) < cost) continue;
    for(auto [to, d] : g.at(from)){
      if(!chmin(ds.at(to), cost + d)) continue;
      dijk.emplace(cost + d, to);
    }
  }

  dijk.emplace(0, t);
  dt.at(t) = 0;
  while(!dijk.empty()){
    auto [cost, from] = dijk.top(); dijk.pop();
    if(dt.at(from) < cost) continue;
    for(auto [to, d] : g.at(from)){
      if(!chmin(dt.at(to), cost + d)) continue;
      dijk.emplace(cost + d, to);
    }
  }

  rep(i, n) if(ds.at(i) == dt.at(i) && ds.at(i) != inf){
    cout << i + 1 << '\n';
    return 0;
  }
  cout << -1 << '\n';
}
