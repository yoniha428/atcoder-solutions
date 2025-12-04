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
  vector g(n, vector<pair<int, int>>());
  while(m--){
    int a, b, c; cin >> a >> b >> c; a--; b--;
    g.at(a).emplace_back(b, c);
  }
  const int inf = 1ll << 60;
  rep(i, n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> dijk;
    dijk.emplace(0, i);
    vector<int> d(n, inf);
    while(!dijk.empty()){
      auto [cost, from] = dijk.top(); dijk.pop();
      if(d.at(from) < cost) continue;
      for(auto [to, c] : g.at(from)){
        if(!chmin(d.at(to), cost + c)) continue;
        dijk.emplace(cost + c, to);
      }
    }
    cout << (d.at(i) == inf ? -1ll : d.at(i)) << '\n';
  }
}
/*
各頂点からダイクストラするが、rootの距離をinfとしておく
*/
