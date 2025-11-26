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
  vector<int> a(n);
  scc_graph s(n);
  rep(i, n){
    cin >> a.at(i); a.at(i)--;
    s.add_edge(i, a.at(i));
  }
  auto vv = s.scc();
  int ans = 0;
  for(auto&& v : vv) if(v.size() > 1 || a.at(v.at(0)) == v.at(0)) ans += v.size();
  cout << ans << '\n';
}
