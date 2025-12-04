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
  int h, w, y; cin >> h >> w >> y;
  vector a(h, vector<int>(w)); for(auto&& ai : a) for(auto&& aij : ai) cin >> aij, aij--;

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
  vector face(h, vector<bool>(w, false));
  if(h == 1 && w == 1){
    q.emplace(a.at(0).at(0), 0, 0);
    face.at(0).at(0) = true;
  }
  else if(h == 1){
    rep(j, w){
      q.emplace(a.at(0).at(j), 0, j);
      face.at(0).at(j) = true;
    }
  }
  else if(w == 1){
    rep(i, h){
      q.emplace(a.at(i).at(0), i, 0);
      face.at(i).at(0) = true;
    }
  }
  else{
    rep(i, h) for(auto j : {0ll, w - 1}){
      q.emplace(a.at(i).at(j), i, j);
      face.at(i).at(j) = true;
    }
    rep(j, w - 2) for(auto i : {0ll, h - 1}){
      q.emplace(a.at(i).at(j + 1), i, j + 1);
      face.at(i).at(j + 1) = true;
    }
  }
  int ans = h * w;
  
  rep(t, y){
    while(!q.empty()){
      auto [aij, i, j] = q.top();
      if(aij > t) break;
      q.pop();
      ans--;
      for(auto [di, dj] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}){
        int ti = i + di, tj = j + dj;
        if(ti < 0 || ti >= h || tj < 0 || tj >= w || face.at(ti).at(tj)) continue;
        face.at(ti).at(tj) = true;
        q.emplace(a.at(ti).at(tj), ti, tj);
      }
    }
    cout << ans << '\n';
  }
}
