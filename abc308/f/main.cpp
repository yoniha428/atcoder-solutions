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
  int n, m; cin >> n >> m;
  vector<int> p(n), d(m);
  vector<pair<int, int>> l(m);
  for(auto&& pi : p) cin >> pi;
  rep(t, m){
    auto&& [li, i] = l.at(t);
    cin >> li;
    i = t;
  }
  for(auto&& di : d) cin >> di;
  priority_queue<int> q; rep(i, n) q.emplace(0);
  sort(all(p)); sort(all(l));
  auto itr = l.begin();
  int ans = 0;
  for(auto pi : p){
    while(itr != l.end() && itr->first <= pi){
      q.emplace(d.at(itr->second));
      itr++;
    }
    ans += pi - q.top();
    q.pop();
  }
  cout << ans << '\n';
}
/*
値段が安い順に商品を見て、その商品に適用できるうち最もDが大きいクーポンを使う
Lが商品の値段以下なら良い
*/
