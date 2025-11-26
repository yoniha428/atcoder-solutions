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
  vector<tuple<int, int, int>> edge(n - 1);
  for(auto&& [w, u, v] : edge){
    cin >> u >> v >> w; u--; v--;
  }
  sort(all(edge));
  dsu d(n);
  int ans = 0;
  for(auto& [w, u, v] : edge){
    ans += w * d.size(u) * d.size(v);
    d.merge(u, v);
  }
  println("{}", ans);
}
/*
安い方から辺を追加していくと、a.sise() * b.size()に対する答えがwになる
*/
