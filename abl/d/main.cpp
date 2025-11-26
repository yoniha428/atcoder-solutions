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
  int n, k; cin >> n >> k;
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  segtree<int, [](int x, int y){return max(x, y);}, []{return 0ll;}> seg(300001);
  for(auto ai : a){
    seg.set(ai, max(seg.get(ai), 1 + seg.prod(max(0ll, ai - k), min(300001ll, ai + k + 1))));
  }
  cout << seg.all_prod() << '\n';
}
