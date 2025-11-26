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
  string t; cin >> t;
  vector<string> s(h); for(auto&& si : s) cin >> si;
  reverse(all(t));
  int ans = 0;
  rep(i, h) rep(j, w){
    if(s.at(i).at(j) == '#') continue;
    int iw = i, jw = j;
    bool ok = true;
    for(auto c : t){
      if(c == 'L') jw++;
      if(c == 'R') jw--;
      if(c == 'U') iw++;
      if(c == 'D') iw--;
      if(s.at(iw).at(jw) == '#'){
        ok = false;
        break;
      }
    }
    ans += ok;
  }
  cout << ans << '\n';
}
