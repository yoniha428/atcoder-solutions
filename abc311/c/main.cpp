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
  scc_graph s(n);
  vector<int> a(n);
  rep(i, n){
    cin >> a.at(i); a.at(i)--;
    s.add_edge(i, a.at(i));
  }
  auto vv = s.scc();
  for(auto v : vv) if(v.size() > 1){
    vector<int> ans{v.at(0), a.at(v.at(0))};
    while(ans.back() != v.at(0)) ans.emplace_back(a.at(ans.back()));
    ans.pop_back();
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i + 1 << ' ';
    cout << '\n';
    return 0;
  }
}
