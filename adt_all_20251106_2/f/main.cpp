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
  int n, q; cin >> n >> q;
  vector<int> f(n), g(n); rep(i, n) f.at(i) = g.at(i) = i;
  while(q--){
    int x; cin >> x; x--;
    int i = f.at(x);
    swap(g.at(i), g.at(i == n - 1 ? i - 1 : i + 1));
    swap(f.at(x), f.at(g.at(i)));
  }
  for(auto i : g) print("{} ", i + 1);
  println();
}
/*
fは番号→場所、gは場所→番号
*/