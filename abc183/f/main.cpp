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
  vector<map<int, int>> mp(n);
  rep(i, n){
    int c; cin >> c;
    mp.at(i).emplace(c, 1);
  }
  dsu d(n);
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int a, b; cin >> a >> b; a--; b--;
      if(d.same(a, b)) continue;
      int al = d.leader(a), bl = d.leader(b);
      int nl = d.merge(a, b);
      auto&& big = mp.at(nl);
      auto&& small = mp.at(nl == al ? bl : al);
      
      if(small.size() > big.size()) swap(small, big);

      for(const auto& [key, val] : small){
        if(big.contains(key)) big.at(key) += val;
        else big.emplace(key, val);
      }
      small.clear();
    }
    if(op == 2){
      int x, y; cin >> x >> y; x--;
      int xl = d.leader(x);
      cout << (mp.at(xl).contains(y) ? mp.at(xl).at(y) : 0ll) << '\n';
    }
  }
}
