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
  dsu d(n);
  vector<pair<int, int>> ab(m);
  for(auto&& [a, b] : ab) cin >> a >> b, a--, b--;
  for(auto& [a, b] : ab) d.merge(a, b);
  vector<int> cnt(n, 0);
  for(auto& [a, b] : ab){
    cnt.at(d.leader(a))++;
    cnt.at(d.leader(b))++;
  }
  auto vv = d.groups();
  int ans = 0;
  for(auto v : vv){
    ans += max(0ll, cnt.at(d.leader(v.at(0))) / 2 - ((int)v.size() - 1));
  }
  println("{}", ans);
}
