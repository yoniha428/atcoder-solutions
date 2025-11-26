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

template<class T>
void show_type(T) {
  cout << __PRETTY_FUNCTION__ << '\n';
}

signed main(){
  int h, w, m; cin >> h >> w >> m;
  vector<int> cnth(h, 0), cntw(w, 0);
  vector bomb(h, vector<int>());
  while(m--){
    int i, j; cin >> i >> j; i--; j--;
    cnth.at(i)++; cntw.at(j)++;
    bomb.at(i).emplace_back(j);
  }
  int ans = 0;
  segtree<int, [](int a, int b){return max(a, b);}, []{return 0ll;}> seg(cntw);
  rep(i, h){
    for(auto j : bomb.at(i)) seg.set(j, seg.get(j) - 1);
    chmax(ans, cnth.at(i) + seg.all_prod());
    for(auto j : bomb.at(i)) seg.set(j, seg.get(j) + 1);
  }
  cout << ans << '\n';
}
