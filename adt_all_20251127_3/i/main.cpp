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
  int n, h; cin >> n >> h;
  vector<pair<int, int>> td(n); for(auto&& [t, d] : td) cin >> t >> d;
  int l = 0, r = 2e18;
  while(r - l > 1){
    int mid = (l + r + 1) / 2;
    multiset<int> full, turn;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(mid, -1);
    rep(i, n){
      auto [t, d] = td.at(i);
      if(t < mid){
        full.emplace(t * d);
        q.emplace(mid - t, i);
      }
      else turn.emplace(d);
    }
    int t = 0, sum = 0;
    while(t < mid){
      // 今の最大を探す
      assert(!full.empty() || !turn.empty());
      int full_max = (full.empty() ? -1 : *full.rbegin()), turn_max = (turn.empty() ? -1 : *turn.rbegin());
      auto [t_next, i] = q.top(); q.pop();
      int damage = (t_next - t) * max(full_max, turn_max * (mid - t));
      assert(damage >= 0);
      println("damage = {}", damage);
      sum += damage;
      if(i != -1){
        auto [t, d] = td.at(i);
        full.erase(full.find(t * d));
        turn.emplace(d);
      }
      t = t_next;
    }
    println("mid = {}, sum = {}", mid, sum);
    (sum >= h ? r : l) = mid;
  }
  println("{}", r);
}
/*
aターンまでで倒すことができるかどうかは貪欲で判定できそう
長方形領域の大きさが大きいのを使えばよい
↑これが簡単にできないと言われている？
tiターン分フルで使えるやつらのトップと減っていっているやつのトップを比較する？

何ターン目になるとfullからturnに以降するか
*/
