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
  const string snuke = "snuke";
  if(s.at(0).at(0) != snuke.at(0)){
    cout << "No" << '\n';
    return 0;
  }
  deque<pair<int, int>> bfs; bfs.emplace_back(0, 0);
  vector f(h, vector<bool>(w, false)); f.at(0).at(0) = true;
  while(!bfs.empty()){
    auto [fi, fj] = bfs.front(); bfs.pop_front();
    char next = snuke.at((snuke.find(s.at(fi).at(fj)) + 1) % snuke.size());
    for(auto&& [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti = fi + di, tj = fj + dj;
      if(ti < 0 || ti >= h || tj < 0 || tj >= w || f.at(ti).at(tj) || s.at(ti).at(tj) != next) continue;
      f.at(ti).at(tj) = true;
      bfs.emplace_back(ti, tj);
    }
  }
  cout << (f.at(h - 1).at(w - 1) ? "Yes" : "No") << '\n';
}
