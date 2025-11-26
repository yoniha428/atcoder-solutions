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
  string s, t; cin >> s >> t;
  vector<pair<char, int>> rs, rt;
  for(auto c : s){
    if(rs.empty() || c != rs.back().first) rs.emplace_back(c, 1);
    else rs.back().second++;
  }
  for(auto c : t){
    if(rt.empty() || c != rt.back().first) rt.emplace_back(c, 1);
    else rt.back().second++;
  }
  // for(auto [c, l] : rs) print("{} {} ", c, l);
  // println();
  // for(auto [c, l] : rt) print("{} {} ", c, l);
  // println();
  if(rs.size() != rt.size()){
    println("No");
    return 0;
  }
  int n = rs.size();
  bool ok = true;
  rep(i, n){
    auto [cs, ls] = rs.at(i);
    auto [ct, lt] = rt.at(i);
    ok &= cs == ct && (ls == lt || (ls < lt && ls != 1));
  }
  println("{}", ok ? "Yes" : "No");
}
