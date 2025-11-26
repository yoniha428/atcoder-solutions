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
  vector seen(h, vector<bool>(w, false)), ans(seen); seen.at(1).at(1) = ans.at(1).at(1) = true;
  deque<pair<int, int>> bfs; bfs.emplace_back(1, 1);
  while(!bfs.empty()){
    auto [fi, fj] = bfs.front(); bfs.pop_front();
    for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti = fi, tj = fj;
      while(s.at(ti).at(tj) == '.'){
        ans.at(ti).at(tj) = true;
        ti += di; tj += dj;
      }
      ti -= di; tj -= dj;
      if(!seen.at(ti).at(tj)){
        seen.at(ti).at(tj) = true;
        bfs.emplace_back(ti, tj);
      }
    }
  }
  int cnt = 0; rep(i, h) rep(j, w) cnt += ans.at(i).at(j);
  cout << cnt << '\n';
}
