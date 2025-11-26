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
  const int amax = 500000;
  segtree<int, [](int x, int y){return x + y;}, []{return 0ll;}> cnt(amax + 1), sum(amax + 1);
  for(auto ai : a){
    sum.set(ai, sum.get(ai) + ai);
    cnt.set(ai, cnt.get(ai) + 1);
  }
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int x, y; cin >> x >> y; x--;
      sum.set(a.at(x), sum.get(a.at(x)) - a.at(x));
      cnt.set(a.at(x), cnt.get(a.at(x)) - 1);
      a.at(x) = y;
      sum.set(y, sum.get(y) + y);
      cnt.set(y, cnt.get(y) + 1);
    }
    if(op == 2){
      int l, r; cin >> l >> r; r++;
      // if(l <= r) println("{} {} {}", l * cnt.prod(0, l), sum.prod(l, r), r * cnt.prod(r, amax + 1));
      println("{}", l > r ? l * n : sum.prod(l, r) + l * cnt.prod(0, l) + (r - 1) * cnt.prod(r, amax + 1));
    }
  }
}
/*
l<=x<=rについては、全部足す
左のはl-xだけ余計に和を取っているので、

カウント用と総和用で2本セグ木を持つ？
*/
