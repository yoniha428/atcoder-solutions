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

const F ID = 8e18;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    if(f != ID) x.value = f*x.size;
    return x;
}
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

signed main(){
  int n; cin >> n;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  segtree<int, [](int a, int b){return max(a, b);}, []{return 0ll;}> minseg(a);
  rep(i, n) seg.set(i, {a.at(i), 1});
  int amax = 0;
  rep(i, n){
    int ai = a.at(i);
    if(chmax(amax, ai)) seg.apply(0, i + 1, ai);
    seg.apply(minseg.min_left(i, [&](int x){return x < ai;}), i + 1, ai);
    cout << seg.prod(0, i + 1).value + 1 << '\n';
  }
}
/*
累計maxが関係あるのかしら
今越えたい壁が今までのmaxなら、幅*高さ+1が答えになる
そうでないとき、自分以上の壁が自分より左にある
そこまでの長方形領域と、
*/
