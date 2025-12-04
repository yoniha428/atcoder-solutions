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
  int n; string s; cin >> n >> s;
  vector<int> a, b;
  rep(i, 2 * n){
    if(s.at(i) == 'A') a.emplace_back(i);
    else b.emplace_back(i);
  }
  int aans = 0, bans = 0;
  rep(i, n) aans += abs(a.at(i) - 2 * i);
  rep(i, n) bans += abs(b.at(i) - 2 * i);
  println("{}", min(aans, bans));
}
