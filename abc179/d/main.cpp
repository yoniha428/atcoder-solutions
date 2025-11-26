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

using mint = modint998244353;

mint op(mint, mint){return mint(0);}
mint e(){return mint(0);}
mint mapping(mint f, mint x){return f + x;}
mint composition(mint f, mint g){return f + g;}
mint id(){return mint(0);}

signed main(){
  int n, k; cin >> n >> k;
  vector<pair<int, int>> lr(k);
  for(auto&& [l, r] : lr) cin >> l >> r, r++;
  lazy_segtree<mint, op, e, mint, mapping, composition, id> seg(n);
  seg.set(0, mint(1));
  rep(i, n){
    for(auto& [l, r] : lr){
      seg.apply(min(i + l, n), min(i + r, n), seg.get(i));
    }
  }
  cout << seg.get(n - 1).val() << '\n';
}
