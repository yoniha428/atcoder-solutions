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
  vector<bool> ans(n, false);
  for(auto c1 : {true, false}) for(auto c2 : {true, false}){
    ans.at(0) = c1; ans.at(1) = c2;
    for(int i = 2; i < n; i++){
      if(ans.at(i - 1)) ans.at(i) = s.at(i - 1) == 'o' ? ans.at(i - 2) : !ans.at(i - 2);
      else ans.at(i) = s.at(i - 1) == 'o' ? !ans.at(i - 2) : ans.at(i - 2);
    }
    // 多分、条件0と条件n-1を見ていない
    bool ok = true;
    ok &= ((s.at(0) == 'o') == (ans.at(1) == ans.at(n - 1))) == ans.at(0);
    ok &= ((s.at(n - 1) == 'o') == (ans.at(n - 2) == ans.at(0))) == ans.at(n - 1);
    if(ok){
      for(auto i : ans) cout << (i ? 'S' : 'W');
      cout << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
/*
0番目と1番目を全探索すれば、それ以降が全部決まる
見てない条件に合致するならそれでok
*/
