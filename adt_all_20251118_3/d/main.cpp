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
  int n; string t; cin >> n >> t;
  int x = 0, y = 0;
  vector<pair<int, int>> dxy{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  int dir = 0;
  for(auto c : t){
    if(c == 'S'){
      auto [dx, dy] = dxy.at(dir);
      x += dx;
      y += dy;
    }
    if(c == 'R') dir = (dir + 1) % 4;
  }
  println("{} {}", x, y);
}
