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
  vector<double> p(n); for(auto&& pi : p) cin >> pi;
  vector q(n + 1, vector<double>(n + 1, 0));
  q.at(0).at(0) = 1;
  rep(i, n){
    rep(j, n + 1) q.at(i + 1).at(j) = (j == 0 ? 0.0 : q.at(i).at(j - 1) * p.at(i)) + q.at(i).at(j) * (1 - p.at(i));
  }
  double ans = 0;
  for(int i = n / 2 + 1; i <= n; i++) ans += q.at(n).at(i);
  cout << fixed << setprecision(30) << ans << '\n';
}
