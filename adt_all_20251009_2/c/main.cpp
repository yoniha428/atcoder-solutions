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
  int h, w, si, sj; cin >> h >> w >> si >> sj; si--; sj--;
  vector<string> c(h); for(auto&& ci : c) cin >> ci;
  string x; cin >> x;
  map<char, pair<int, int>> dij{{'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
  for(auto dir : x){
    auto [di, dj] = dij.at(dir);
    int ti = si + di, tj = sj + dj;
    if(ti >= 0 && ti < h && tj >= 0 && tj < w && c.at(ti).at(tj) == '.'){
      si = ti;
      sj = tj;
    }
  }
  println("{} {}", si + 1, sj + 1);
}
