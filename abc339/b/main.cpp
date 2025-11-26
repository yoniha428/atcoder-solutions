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
  int h, w, n; cin >> h >> w >> n;
  vector ans(h, string(w, '.'));
  vector<pair<int, int>> dij{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int i = 0, j = 0, d = 0;
  while(n--){
    if(ans.at(i).at(j) == '.'){
      ans.at(i).at(j) = '#';
      d = (d + 1) % 4;
      auto [di, dj] = dij.at(d);
      i = (i + di + h) % h;
      j = (j + dj + w) % w;
    }
    else{
      ans.at(i).at(j) = '.';
      d = (d + 3) % 4;
      auto [di, dj] = dij.at(d);
      i = (i + di + h) % h;
      j = (j + dj + w) % w;
    }
  }
  for(auto&& si : ans) cout << si << '\n';
}
