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
  deque<pair<int, int>> bfs;
  vector cnt(h, vector<int>(w, 0));
  vector turn(h, vector<int>(w, -1));
  rep(i, h) rep(j, w) if(s.at(i).at(j) == '#'){
    turn.at(i).at(j) = 0;
    bfs.emplace_back(i, j);
  }
  
  while(!bfs.empty()){
    auto [fi, fj] = bfs.front(); bfs.pop_front();
    if(s.at(fi).at(fj) == '.') continue;
    assert(turn.at(fi).at(fj) != -1);
    for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti = fi + di, tj = fj + dj;
      if(ti < 0 || ti >= h || tj < 0 || tj >= w) continue;
      cnt.at(ti).at(tj)++;
      if(cnt.at(ti).at(tj) == 1 && s.at(ti).at(tj) != '#'){
        s.at(ti).at(tj) = '#';
        turn.at(ti).at(tj) = turn.at(fi).at(fj) + 1;
        bfs.emplace_back(ti, tj);
      }
      else if(turn.at(ti).at(tj) == turn.at(fi).at(fj) + 1){
        // assert(false);
        s.at(ti).at(tj) = '.';
      }
    }
    // for(auto&& si : s) println("{}", si);
    // println();
  }
  int ans = 0;
  for(auto&& si : s) for(auto c : si) ans += c == '#';
  // for(auto&& si : s) println("{}", si);
  println("{}", ans);
}
/*
i回操作した盤面をsiとすると、siの時点で2回以上周囲が#になったら塗らない
逆に、前のターンで候補に入る→今のターンで候補から外れる、がないようにしたい
*/
