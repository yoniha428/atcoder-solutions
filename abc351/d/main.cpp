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
  dsu d(h * w);
  rep(i, h) rep(j, w) if(s.at(i).at(j) == '#'){
    for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti = i + di, tj = j + dj;
      if(ti < 0 || ti >= h || tj < 0 || tj >= w || s.at(ti).at(tj) == '#') continue;
      s.at(ti).at(tj) = '!';
    }
  }
  rep(i, h) rep(j, w) if(s.at(i).at(j) == '.'){
    for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti = i + di, tj = j + dj;
      if(ti < 0 || ti >= h || tj < 0 || tj >= w) continue;
      if(s.at(ti).at(tj) == '.') d.merge(i * w + j, ti * w + tj);
    }
  }
  auto vv = d.groups();
  int ans = 1;
  for(auto&& v : vv){
    int i = v.at(0) / w, j = v.at(0) % w;
    if(s.at(i).at(j) != '.') continue;
    set<pair<int, int>> st;
    for(auto t : v){
      int i = t / w, j = t % w;
      for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
        int ti = i + di, tj = j + dj;
        if(ti < 0 || ti >= h || tj < 0 || tj >= w) continue;
        if(s.at(ti).at(tj) == '!') st.emplace(ti, tj);
      }
    }
    chmax(ans, (int)(v.size() + st.size()));
  }
  cout << ans << '\n';
}
