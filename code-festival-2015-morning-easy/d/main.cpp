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
  int n; string s; cin >> n >> s;
  int ans = 0;
  for(int i = 1; i < n; i++){
    string s1 = s.substr(0, i), s2 = s.substr(i);
    vector dp(i + 1, vector<int>(n - i + 1, 0));
    rep(i1, i) rep(i2, n - i){
      dp.at(i1 + 1).at(i2 + 1) = s1.at(i1) == s2.at(i2) ? dp.at(i1).at(i2) + 1 : max(dp.at(i1).at(i2 + 1), dp.at(i1 + 1).at(i2));
    }
    chmax(ans, dp.at(i).at(n - i));
  }
  cout << n - 2 * ans << '\n';
}
