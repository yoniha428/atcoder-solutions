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
  int h, w; cin >> h >> w;
  vector<string> s(h); for(auto&& si : s) cin >> si;
  vector edge_u(h, vector(w, false)), edge_d(edge_u);
  rep(i, h - 1) rep(j, w) edge_u.at(i).at(j) = s.at(i).at(j) == '#' && s.at(i + 1).at(j) == '.';
  rep(i, h - 1) rep(j, w) edge_d.at(i).at(j) = s.at(i).at(j) == '.' && s.at(i + 1).at(j) == '#';
  int ans = 0;
  rep(i, h){
    vector<bool> rle;
    rep(j, w){
      if(rle.empty() || rle.back() != edge_u.at(i).at(j)) rle.emplace_back(edge_u.at(i).at(j));
    }
    ans += 2 * reduce(all(rle), 0ll);
  }
  rep(i, h){
    vector<bool> rle;
    rep(j, w){
      if(rle.empty() || rle.back() != edge_d.at(i).at(j)) rle.emplace_back(edge_d.at(i).at(j));
    }
    ans += 2 * reduce(all(rle), 0ll);
  }
  cout << ans << '\n';
}
/*
自分が#で下が.のとき、下に辺がある
自分が#で右が.のとき、右に辺がある
*/
