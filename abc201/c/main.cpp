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
  string s; cin >> s;
  int ans = 0;
  rep(i, 10000){
    vector<bool> have(10, false);
    int w = i;
    rep(j, 4){
      have.at(w % 10) = true;
      w /= 10;
    }
    bool ok = true;
    rep(i, 10){
      if(s.at(i) == 'o') ok &= have.at(i);
      if(s.at(i) == 'x') ok &= !have.at(i);
    }
    ans += ok;
  }
  cout << ans << '\n';
}
