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
  int n, m; cin >> n >> m;
  vector<pair<int, int>> ba(n); for(auto&& [b, a] : ba) cin >> a >> b, b *= -1;
  sort(all(ba));
  int t = 0, ans = 0;
  for(auto [b, a] : ba){
    if(t + a <= m){
      cout << b << ' ' << a << '\n';
      t++;
      ans += -b;
    }
  }
  cout << ans << '\n';
}
