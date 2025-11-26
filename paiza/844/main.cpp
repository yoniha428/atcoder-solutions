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
  int si = -1, sj = -1, gi = -1, gj = -1;
  vector val(h, vector<int>(w, -1));
  rep(i, h) rep(j, w){
    if(s.at(i).at(j) == 'S'){
      si = i; sj = j;
    }
    else if(s.at(i).at(j) == 'G'){
      gi = i; gj = j;
    }
    else{
      val.at(i).at(j) = s.at(i).at(j) - '0';
    }
  }
  vector d(h, vector<int>(w, 1ll << 60));
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> dijk;
  d.at(si).at(sj) = 0;
  dijk.emplace(0, si, sj);
  while(!dijk.empty()){
    auto [fd, fi, fj] = dijk.top(); dijk.pop();
    if(fd > d.at(fi).at(fj)) continue;
    for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
      int ti = fi + di, tj = fj + dj;
      if(ti < 0 || ti >= h || tj < 0 || tj >= w || (ti == si && tj == sj)) continue;
      if(ti == gi && tj == gj){
        chmin(d.at(ti).at(tj), d.at(fi).at(fj));
        continue;
      }
      if(chmin(d.at(ti).at(tj), d.at(fi).at(fj) + val.at(ti).at(tj))){
        dijk.emplace(d.at(ti).at(tj), ti, tj);
      }
    }
  }
  cout << d.at(gi).at(gj) << '\n';
}
