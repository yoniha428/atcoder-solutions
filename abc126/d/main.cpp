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
  vector g(n, vector<pair<int, int>>());
  rep(i, n - 1){
    int u, v, w; cin >> u >> v >> w; u--; v--;
    g.at(u).emplace_back(v, w);
    g.at(v).emplace_back(u, w);
  }
  vector<int> d(n, -1); d.at(0) = 0;
  deque<int> bfs; bfs.emplace_back(0);
  while(!bfs.empty()){
    auto from = bfs.front(); bfs.pop_front();
    for(auto [to, w] : g.at(from)){
      if(d.at(to) != -1) continue;
      d.at(to) = d.at(from) + w;
      bfs.emplace_back(to);
    }
  }
  rep(i, n) cout << d.at(i) % 2 << '\n';
}
