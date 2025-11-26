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
    g.at(v).emplace_back(u);
  }
  string s; cin >> s;
  deque<tuple<int, int, int>> bfs;
  vector<vector<pair<int, int>>> d(n);
  rep(i, n) if(s.at(i) == 'S'){
    bfs.emplace_back(i, i, 0);
    d.at(i).emplace_back(i, 0);
  }
  while(!bfs.empty()){
    auto [from, root, dis] = bfs.front(); bfs.pop_front();
    for(auto& to : g.at(from)){
      if(d.at(to).size() == 2) continue;
      if(d.at(to).size() == 1 && d.at(to).at(0).first == root) continue;
      d.at(to).emplace_back(root, dis + 1);
      bfs.emplace_back(to, root, dis + 1);
    }
  }
  rep(i, n) if(s.at(i) == 'D') cout << d.at(i).at(0).second + d.at(i).at(1).second << '\n';
}
/*
安全な頂点から多始点bfsをすることを考える
ある頂点への距離について、top2しか考えなくて良い

今の頂点、開始地点、距離の3つ
*/