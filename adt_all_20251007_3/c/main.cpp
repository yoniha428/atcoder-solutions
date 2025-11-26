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
  vector<int> a(n); for(auto& ai : a) cin >> ai, ai--;
  vector<int> cnt(m, 0);
  for(auto& ai : a) cnt.at(ai)++;
  for(auto& ci : cnt) if(ci == 0){
    println("0");
    return 0;
  }
  rrep(i, n){
    cnt.at(a.at(i))--;
    if(cnt.at(a.at(i)) == 0){
      println("{}", n - i);
      return 0;
    }
  }
}
