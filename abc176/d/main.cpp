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
  int h, w, si, sj, gi, gj; cin >> h >> w >> si >> sj >> gi >> gj;
  si--; sj--; gi--; gj--;
  vector<string> s(h); for(auto&& i : s) cin >> i;
  
  int inf = 1ll << 60;
  vector d(h, vector<int>(w, inf)); d.at(si).at(sj) = 0;
  deque<tuple<int, int, int>> bfs; bfs.emplace_back(si, sj, 0);
  while(!bfs.empty()){
    auto [fi, fj, disi] = bfs.front(); bfs.pop_front();
    if(d.at(fi).at(fj) < disi) continue;
    for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti = fi + di, tj = fj + dj;
      if(ti < 0 || ti >= h || tj < 0 || tj >= w || s.at(ti).at(tj) == '#' || !chmin(d.at(ti).at(tj), disi)) continue;
      bfs.emplace_front(ti, tj, disi);
    }
    for(int di = -2; di <= 2; di++) for(int dj = -2; dj <= 2; dj++){
      int ti = fi + di, tj = fj + dj;
      if(ti < 0 || ti >= h || tj < 0 || tj >= w || s.at(ti).at(tj) == '#' || !chmin(d.at(ti).at(tj), disi + 1)) continue;
      bfs.emplace_back(ti, tj, disi + 1);
    }
  }

  cout << (d.at(gi).at(gj) == inf ? -1 : d.at(gi).at(gj)) << '\n';
}
