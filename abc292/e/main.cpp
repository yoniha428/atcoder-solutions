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
  vector g(n, vector<int>());
  while(m--){
    int u, v; cin >> u >> v; u--; v--;
    g.at(u).emplace_back(v);
  }
  int ans = 0;
  rep(root, n){
    vector<bool> seen(n, false); seen.at(root) = true;
    deque<int> bfs; bfs.emplace_back(root);
    while(!bfs.empty()){
      auto from = bfs.front(); bfs.pop_front();
      for(auto to : g.at(from)) if(!seen.at(to)){
        seen.at(to) = true;
        bfs.emplace_back(to);
      }
    }
    ans += reduce(all(seen), 0ll) - 1 - g.at(root).size();
  }
  cout << ans << '\n';
}
