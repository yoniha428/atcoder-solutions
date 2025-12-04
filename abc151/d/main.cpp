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
  int h, w; cin >> h >> w;
  vector<string> s(h); for(auto&& si : s) cin >> si;
  int ans = 0;
  rep(i, h) rep(j, w){
    if(s.at(i).at(j) == '#') continue;
    vector d(h, vector<int>(w, -1)); d.at(i).at(j) = 0;
    deque<pair<int, int>> bfs{{i, j}};
    while(!bfs.empty()){
      auto [fi, fj] = bfs.front(); bfs.pop_front();
      for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
        int ti = fi + di, tj = fj + dj;
        if(ti < 0 || ti >= h || tj < 0 || tj >= w || s.at(ti).at(tj) == '#' || d.at(ti).at(tj) != -1) continue;
        bfs.emplace_back(ti, tj);
        d.at(ti).at(tj) = d.at(fi).at(fj) + 1;
      }
    }
    rep(ni, h) rep(nj, w) chmax(ans, d.at(ni).at(nj));
  }
  cout << ans << '\n';
}
