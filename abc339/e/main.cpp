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
  int n, d; cin >> n >> d;
  vector<int> a(n); for(auto&& ai : a) cin >> ai, ai--;
  int amax = 500000;
  segtree<int, [](int a, int b){return max(a, b);}, []{return 0ll;}> seg(amax);
  for(auto ai : a){
    seg.set(ai, seg.prod(max(0ll, ai - d), min(amax, ai + d + 1)) + 1);
  }
  cout << seg.all_prod() << '\n';
}
