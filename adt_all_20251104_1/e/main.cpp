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
  const int inf = 1ll << 60;
  int mini = inf, maxi = -1, minj = inf, maxj = -1;
  rep(i, h) rep(j, w) if(s.at(i).at(j) == '#'){
    chmin(mini, i); chmax(maxi, i); chmin(minj, j); chmax(maxj, j);
  }
  for(int i = mini; i <= maxi; i++) for(int j = minj; j <= maxj; j++){
    if(s.at(i).at(j) == '.'){
      println("No");
      return 0;
    }
  }
  println("Yes");
}
