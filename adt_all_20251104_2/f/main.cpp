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
  string s; cin >> s;
  vector<pair<char, int>> rle;
  for(auto c : s){
    if(rle.empty() || rle.back().first != c) rle.emplace_back(c, 1);
    else rle.back().second++;
  }
  int ans = 0;
  for(auto [c, len] : rle){
    if(c == '0') ans += (len + 1) / 2;
    else ans += len;
  }
  println("{}", ans);
}
