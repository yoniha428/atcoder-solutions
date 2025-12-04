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
  int n, m, k; cin >> n >> m >> k;
  vector g(2 * n, vector<int>());
  while(m--){
    int u, v, a; cin >> u >> v >> a; u--; v--;
    int x = a ? u : u + n, y = a ? v : v + n;
    g.at(x).emplace_back(y);
    g.at(y).emplace_back(x);
  }
  while(k--){
    int s; cin >> s; s--;
    g.at(s).emplace_back(s + n);
    g.at(s + n).emplace_back(s);
  }
  deque<int> bfs; bfs.emplace_back(0);
  vector<int> d(2 * n, -1); d.at(0) = 0;
  while(!bfs.empty()){
    auto from = bfs.front(); bfs.pop_front();
    for(auto to : g.at(from)){
      if(d.at(to) != -1) continue;
      if(from % n == to % n){
        d.at(to) = d.at(from);
        bfs.emplace_front(to);
      }
      else{
        d.at(to) = d.at(from) + 1;
        bfs.emplace_back(to);
      }
    }
  }

  const int inf = 1ll << 60, ans = min(d.at(n - 1) == -1 ? inf : d.at(n - 1), d.at(2 * n - 1) == -1 ? inf : d.at(2 * n - 1));
  println("{}", ans == inf ? -1 : ans);
}
