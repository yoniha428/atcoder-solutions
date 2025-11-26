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
  vector<int> r(n); for(auto&& ri : r) cin >> ri;
  int prod = reduce(all(r), 1ll, [](int a, int b){return a * b;});
  vector<vector<int>> ans;
  rep(i, prod){
    int sum = 0, w = i;
    vector<int> ansi;
    for(auto ri : r){
      sum += w % ri + 1;
      ansi.emplace_back(w % ri + 1);
      w /= ri;
    }
    if(sum % k == 0) ans.emplace_back(ansi);
  }
  sort(all(ans));
  for(auto& ansi : ans){
    for(auto ansij : ansi) print("{} ", ansij);
    println();
  }
}
