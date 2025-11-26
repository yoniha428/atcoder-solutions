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
  int n, k, x; cin >> n >> k >> x; x--;
  vector<string> s(n); for(auto&& si : s) cin >> si;
  int prod = 1; rep(i, k) prod *= n;
  vector<string> ans;
  rep(i, prod){
    string ansi;
    int w = i;
    rep(j, k){
      ansi += s.at(w % n);
      w /= n;
    }
    ans.emplace_back(ansi);
  }
  sort(all(ans));
  cout << ans.at(x) << '\n';
}
