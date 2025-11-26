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

  vector to(26, vector<pair<int, int>>());
  deque<pair<int, int>> bfs;
  const int inf = 1ll << 60;
  vector d(h, vector<int>(w, inf));
  int gi = -1, gj = -1;

  rep(i, h) rep(j, w){
    char c = s.at(i).at(j);
    if(c == 'S'){
      d.at(i).at(j) = 0;
      bfs.emplace_back(i, j);
    }
    if(c == 'G'){
      gi = i; gj = j;
    }
    if(islower(c)){
      to.at(c - 'a').emplace_back(i, j);
    }
  }

  vector<bool> seen(26, false);

  while(!bfs.empty()){
    auto [fi, fj] = bfs.front(); bfs.pop_front();
    char c = s.at(fi).at(fj);
    if(islower(c) && !seen.at(c - 'a')){
      seen.at(c - 'a') = true;
      for(auto& [ti, tj] : to.at(c - 'a')) if(d.at(ti).at(tj) == inf){
        d.at(ti).at(tj) = d.at(fi).at(fj) + 1;
        bfs.emplace_back(ti, tj);
      }
    }
    for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti = fi + di, tj = fj + dj;
      if(ti < 0 || ti >= h || tj < 0 || tj >= w || d.at(ti).at(tj) != inf || s.at(ti).at(tj) == '#') continue;
      d.at(ti).at(tj) = d.at(fi).at(fj) + 1;
      bfs.emplace_back(ti, tj);
    }
  }
  cout << (d.at(gi).at(gj) == inf ? -1 : d.at(gi).at(gj)) << '\n';
}
