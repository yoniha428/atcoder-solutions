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
  vector idx(n, vector<int>());
  rep(i, 3 * n){
    int ai; cin >> ai; ai--;
    idx.at(ai).emplace_back(i);
  }
  vector<int> ans(n); rep(i, n) ans.at(i) = i;
  sort(all(ans), [&](int i, int j){return idx.at(i).at(1) < idx.at(j).at(1);});
  for(auto i : ans) print("{} ", i + 1);
  println();
}
