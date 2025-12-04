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
  int ans = 1ll << 60;
  rep(target, 10){
    int cnt = 0, t = 0;
    vector<bool> stop(n, false);
    while(cnt < n){
      rep(i, n) if(s.at(i).at(t % 10) - '0' == target && !stop.at(i)){
        stop.at(i) = true;
        cnt++;
        break;
      }
      t++;
    }
    chmin(ans, t - 1);
  }
  cout << ans << '\n';
}
