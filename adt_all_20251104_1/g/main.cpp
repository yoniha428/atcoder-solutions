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
  vector<int> a(n); for(auto&& ai : a) cin >> ai;
  vector<int> cnt(200001, 0);
  for(auto ai : a) cnt.at(ai)++;
  int ans = 0;
  for(int i = 1; i <= 200000; i++){
    for(int j = 1; j * j <= i; j++) if(i % j == 0){
      int k = i / j;
      ans += cnt.at(i) * cnt.at(j) * cnt.at(k) * (j * j == i ? 1 : 2);
    }
  }
  println("{}", ans);

  // int ansn = 0;
  // rep(i, n) rep(j, n) rep(k, n) if(a.at(i) == a.at(j) * a.at(k)) ansn++;
  // println("{}", ansn);
}
