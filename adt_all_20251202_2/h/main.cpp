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
  string s; cin >> s;
  segtree<bool, [](bool x, bool y){return x && y;}, []{return true;}> seg(n - 1);
  rep(i, n - 1) seg.set(i, s.at(i) != s.at(i + 1));
  while(q--){
    int op, l, r; cin >> op >> l >> r; l--; r--;
    if(op == 1){
      // l-1とl、rとr+1の関係のみ影響する
      if(l != 0) seg.set(l - 1, !seg.get(l - 1));
      if(r != n - 1) seg.set(r, !seg.get(r));
    }
    if(op == 2){
      println("{}", seg.prod(l, r) ? "Yes" : "No");
    }
  }
}
