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
  int n, a, b, m; cin >> n >> a >> b >> m; a--; b--;
  vector g(n, vector<int>());
  while(m--){
    int x, y; cin >> x >> y; x--; y--;
    g.at(x).emplace_back(y);
    g.at(y).emplace_back(x);
  }
  vector<int> d(n, -1); d.at(a) = 0;
  deque<int> bfs{a};
  while(!bfs.empty()){
    int from = bfs.front(); bfs.pop_front();
    for(auto to : g.at(from)){
      if(d.at(to) != -1) continue;
      d.at(to) = d.at(from) + 1;
      bfs.emplace_back(to);
    }
  }
  vector<mint> ans(n, 0); ans.at(b) = 1;
  vector<bool> seen(n, false); seen.at(b) = true;
  bfs.emplace_back(b);
  while(!bfs.empty()){
    int from = bfs.front(); bfs.pop_front();
    for(auto to : g.at(from)){
      if(d.at(to) + 1 != d.at(from)) continue;
      ans.at(to) += ans.at(from);
      if(seen.at(to)) continue;
      seen.at(to) = true;
      bfs.emplace_back(to);
    }
  }
  cout << ans.at(a).val() << '\n';
}
