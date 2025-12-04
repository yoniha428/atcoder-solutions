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
  int n, m; cin >> n >> m;
  vector<string> s(n); for(auto&& si : s) cin >> si;
  vector<int> point(n, 0);
  rep(i, m){
    int zero = 0;
    rep(j, n) zero += s.at(j).at(i) == '0';
    rep(j, n) if(s.at(j).at(i) == (zero * 2 > n ? '1' : '0')) point.at(j)++;
  }
  int max = *max_element(all(point));
  rep(i, n) if(point.at(i) == max) print("{} ", i + 1);
  println();
}
