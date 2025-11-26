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

void solve(){
  int n, m, k; string s; cin >> n >> m >> k >> s;
  vector g(n, vector<int>());
  while(m--){
    int u, v; cin >> u >> v; u--; v--;
    g.at(u).emplace_back(v);
  }

  // trueでalice勝ち
  vector dp(2 * k + 1, vector<bool>(n, false));
  
  rep(i, n) dp.at(0).at(i) = s.at(i) == 'A';
  rep(i, 2 * k){
    // iが偶数のときbの手番、奇数のときaの手番
    rep(from, n){
      bool win = false;
      for(auto to : g.at(from)) win |= dp.at(i).at(to) ^ (i % 2 == 0);
      dp.at(i + 1).at(from) = win ^ (i % 2 == 0);
    }
  }
  println("{}", dp.at(2 * k).at(0) ? "Alice" : "Bob");
}

signed main(){
  int t; cin >> t;
  while(t--) solve();
}
/*
最終的にAにいるならAの勝ち、BにいるならBの勝ち
*/
