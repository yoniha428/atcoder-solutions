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
  int n; cin >> n;
  vector<string> s(n); for(auto&& si : s) cin >> si;
  vector d(n, vector(n, vector(n, vector<int>(n, -1))));
  int p1i = -1, p1j = -1,  p2i = -1, p2j = -1;
  rep(i, n) rep(j, n) if(s.at(i).at(j) == 'P'){
    if(p1i == -1){
      p1i = i;
      p1j = j;
    }
    else{
      p2i = i;
      p2j = j;
    }
  }
  assert(p1i != -1 && p1j != -1 && p2i != -1 && p2j != -1);
  d.at(p1i).at(p1j).at(p2i).at(p2j) = 0;
  deque<tuple<int, int, int, int>> bfs; bfs.emplace_back(p1i, p1j, p2i, p2j);
  while(!bfs.empty()){
    auto [i1, j1, i2, j2] = bfs.front(); bfs.pop_front();
    if(i1 == i2 && j1 == j2){
      cout << d.at(i1).at(j1).at(i2).at(j2) << '\n';
      return 0;
    }
    for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti1 = i1 + di, tj1 = j1 + dj, ti2 = i2 + di, tj2 = j2 + dj;
      int ri1 = i1, rj1 = j1, ri2 = i2, rj2 = j2;
      if(clamp(ti1, 0ll, n - 1) == ti1 && clamp(tj1, 0ll, n - 1) == tj1 && s.at(ti1).at(tj1) != '#'){
        ri1 = ti1;
        rj1 = tj1;
      }
      if(clamp(ti2, 0ll, n - 1) == ti2 && clamp(tj2, 0ll, n - 1) == tj2 && s.at(ti2).at(tj2) != '#'){
        ri2 = ti2;
        rj2 = tj2;
      }
      if(d.at(ri1).at(rj1).at(ri2).at(rj2) == -1){
        d.at(ri1).at(rj1).at(ri2).at(rj2) = d.at(i1).at(j1).at(i2).at(j2) + 1;
        bfs.emplace_back(ri1, rj1, ri2, rj2);
      }
    }
  }
  cout << -1 << '\n';
}
