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
  int n, q; cin >> n >> q;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  vector<tuple<int, int, int>> query(q);
  rep(t, q){
    auto&& [r, x, i] = query.at(t);
    cin >> r >> x; r--;
    i = t;
  }
  sort(all(query));
  // for(auto&& [r, x, i] : query) cout << format("r = {}, x = {}, i = {}", r, x, i) << '\n';
  auto itr = query.begin();
  vector<int> lis(n, 1ll << 60);
  vector<int> ans(q, -1);
  rep(i, n){
    auto&& ai = a.at(i);
    *lower_bound(all(lis), ai) = ai;
    while(itr != query.end()){
      auto [r, x, j] = *itr;
      if(r != i) break;
      // cout << format("r = {}, x = {}, j = {}", r, x, j) << '\n';
      ans.at(j) = upper_bound(all(lis), x) - lis.begin();
      itr++;
    }
  }
  assert(itr == query.end());
  for(auto&& i : ans){
    assert(i != -1);
    cout << i << '\n';
  }
}
