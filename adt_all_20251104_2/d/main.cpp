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
  vector<int> a(6), b(6);
  for(auto&& ai : a) cin >> ai;
  for(auto&& bi : b) cin >> bi;
  bool ok = true;
  rep(i, 3) ok &= max(a.at(i), b.at(i)) < min(a.at(i + 3), b.at(i + 3));
  println("{}", ok ? "Yes" : "No");
}
/*
左端の最大値が右端の最小値未満？
*/
