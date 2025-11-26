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
  int h, w, d; cin >> h >> w >> d;
  vector<string> s(h); for(auto&& si : s) cin >> si;
  const int inf = 1ll << 60;
  vector dis(h, vector<int>(w, inf));
  deque<pair<int, int>> bfs;
  rep(i, h) rep(j, w) if(s.at(i).at(j) == 'H'){
    dis.at(i).at(j) = 0;
    bfs.emplace_back(i, j);
  }
  while(!bfs.empty()){
    auto [fi, fj] = bfs.front(); bfs.pop_front();
    if(dis.at(fi).at(fj) == d) continue;
    for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti = fi + di, tj = fj + dj;
      if(ti < 0 || ti >= h || tj < 0 || tj >= w || s.at(ti).at(tj) != '.' || dis.at(ti).at(tj) != inf) continue;
      dis.at(ti).at(tj) = dis.at(fi).at(fj) + 1;
      bfs.emplace_back(ti, tj);
    }
  }
  int ans = 0;
  rep(i, h) rep(j, w) ans += dis.at(i).at(j) != inf;
  println("{}", ans);
}
