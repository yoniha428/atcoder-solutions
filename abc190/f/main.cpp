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

struct S{
  long long value;
  int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

signed main(){
  int n; cin >> n;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  int ans = 0;
  segtree<int, [](int x, int y){return x + y;}, []{return 0ll;}> seg(n);
  for(auto ai : a){
    ans += seg.prod(ai + 1, n);
    seg.set(ai, seg.get(ai) + 1);
  }
  rep(i, n){
    cout << ans << '\n';
    ans += n - 1 - a.at(i) - a.at(i);
  }
}
/*
3 1 5 4 2 9 6 8 7 0
0+1+0+1+3+0+1+1+2+9=18

0が左から右にいったことの影響はなにか
0の転倒数は0から9になる(n-1-a.at(i))
その他の転倒数は自分より小さいやつの数だから、a.at(i)要素1減る
*/
