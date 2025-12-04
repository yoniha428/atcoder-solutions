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
  int n; cin >> n;
  vector<pair<int, int>> xr(n); for(auto&& [x, r] : xr) cin >> x >> r;
  map<int, vector<int>> mp;
  rep(i, n){
    auto [x, r] = xr.at(i);
    for(auto val : {x - r, x + r}){
      if(mp.contains(val)) mp.at(val).emplace_back(i);
      else mp.emplace(val, vector<int>{i});
    }
  }
  multiset<pair<int, int>> size_val;
  map<int, int> val_size;
  for(auto&& [val, v] : mp){
    size_val.emplace(v.size(), val);
    val_size.emplace(val, v.size());
  }
  int ans = 0;
  vector<bool> used(n, false);
  while(!size_val.empty()){
    auto [size, val] = *size_val.begin();
    size_val.erase(size_val.begin());
    int use = -1;
    for(auto i : mp.at(val)) if(!used.at(i)) use = i;
    if(use == -1) continue;

    used.at(use) = true;
    ans++;
    auto [x, r] = xr.at(use);
    for(auto val_n : {x - r, x + r}){
      int size_n = val_size.at(val_n);
      if(!size_val.contains(pair<int, int>{size_n, val_n})) continue;
      auto itr = size_val.lower_bound({size_n, val_n});
      size_val.erase(itr);
      size_val.emplace(size_n - 1, val_n);
      assert(val_size.contains(val_n));
      val_size.at(val_n)--;
    }
  }
  println("{}", ans);
}
/*
それぞれのうさぎはx-rかx+rにいることができる

その値を取ることができるiが1つなら、それを取るべき

vの大きさがどんどん変わるので、setか何かで対応したい
*/
