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
  string siti = "753";
  int ans = 0;
  for(int keta = 1; keta <= 9; keta++){
    int prod = 1; rep(i, keta) prod *= 3;
    rep(i, prod){
      string s;
      int w = i;
      vector<bool> f(3, false);
      rep(j, keta){
        s += siti.at(w % 3);
        f.at(w % 3) = true;
        w /= 3;
      }
      ans += reduce(all(f), 0ll) == 3 && stoll(s) <= n;
    }
  }
  cout << ans << '\n';
}
