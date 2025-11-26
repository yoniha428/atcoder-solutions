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
  vector<int> a(n); for(auto&& ai : a) cin >> ai, ai--;

  scc_graph s(n);
  rep(i, n) s.add_edge(i, a.at(i));
  auto&& vv = s.scc();
  reverse(all(vv));

  vector<int> cnt(n, -1);
  int ans = 0;
  for(auto&& v : vv){
    if(v.at(0) == a.at(v.at(0)) || v.size() > 1){
      for(auto i : v) cnt.at(i) = v.size();
      ans += v.size() * v.size();
      continue;
    }
    ans += cnt.at(a.at(v.at(0))) + 1;
    cnt.at(v.at(0)) = cnt.at(a.at(v.at(0))) + 1;
  }
  cout << ans << '\n';
}
/*
sccしたdag上でdpをしそう
その塊に到達可能である頂点の数は、(その塊に辺が向いている)

a->b->d
 \>c/
みたいなのがダメそう

ある頂点からどんどん遷移すると、いつかループに入る
ループの中にある頂点をk個とすると、k*kは到達可能
ループ外の頂点をl個とすると、(k+1)+(k+2)+...+(k+l)が達成可能
*/
