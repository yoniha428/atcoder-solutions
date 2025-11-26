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
  vector<int> w(n), h(n), b(n);
  rep(i, n) cin >> w.at(i) >> h.at(i) >> b.at(i);
  int sumw = (reduce(all(w)) + 1) / 2;
  vector dp(n + 1, vector<int>(sumw + 1, -1));
  dp.at(0).at(0) = 0;
  rep(i, n){
    rep(j, sumw + 1) if(dp.at(i).at(j) != -1) chmax(dp.at(i + 1).at(j), dp.at(i).at(j) + h.at(i));
    rep(j, sumw + 1) if(dp.at(i).at(j) != -1) chmax(dp.at(i + 1).at(min(sumw, j + w.at(i))), dp.at(i).at(j) + b.at(i));
  }
  println("{}", dp.at(n).at(sumw));
}
/*
パーツをすべてつけるので、体の重さはsum(w)/2以上である必要がある。
*/
