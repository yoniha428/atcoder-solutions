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
  vector<tuple<int, int, int, int>> udlr(n);
  for(auto&& [u, d, l, r] : udlr) cin >> u >> d >> l >> r, u--, l--;
  vector imos(2001, vector<int>(2001, 0));
  for(auto [u, d, l, r] : udlr){
    imos.at(u).at(l)++;
    imos.at(u).at(r)--;
    imos.at(d).at(l)--;
    imos.at(d).at(r)++;
  }
  rep(i, 2001) rep(j, 2000) imos.at(i).at(j + 1) += imos.at(i).at(j);
  rep(j, 2001) rep(i, 2000) imos.at(i + 1).at(j) += imos.at(i).at(j);
  vector presum(2001, vector<int>(2001, 0));
  rep(i, 2000) rep(j, 2000){
    presum.at(i + 1).at(j + 1) = presum.at(i).at(j + 1) + presum.at(i + 1).at(j) - presum.at(i).at(j) + (imos.at(i).at(j) == 1);
  }
  int sum = 0;
  rep(i, 2000) rep(j, 2000) sum += imos.at(i).at(j) > 0;
  for(auto&& [u, d, l, r] : udlr){
    int ans = sum - (presum.at(d).at(r) - presum.at(d).at(l) - presum.at(u).at(r) + presum.at(u).at(l));
    println("{}", 2000 * 2000 - ans);
  }
}
/*
全部雲があるときの答えはimosで出る
雲を1つ取り除くとき、1である要素がその雲の領域内に何個あるかを知りたい
*/
