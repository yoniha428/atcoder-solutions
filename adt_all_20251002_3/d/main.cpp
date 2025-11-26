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
  vector<string> s(n); for(auto&& si : s) cin >> si;
  bool ans = true;
  rep(j, n) rep(i, j) ans &= s.at(i) != s.at(j);
  for(auto& si : s){
    bool f = false, g = false;
    for(auto c : "HDCS") f |= si.at(0) == c;
    for(auto c : "A23456789TJQK") g |= si.at(1) == c;
    ans &= f && g;
  }
  cout << (ans ? "Yes" : "No") << '\n';
}
