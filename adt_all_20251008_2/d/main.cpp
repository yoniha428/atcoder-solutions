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
  vector f(n, vector(m, false));
  vector<int> p(n);
  rep(i, n){
    int c; cin >> p.at(i) >> c;
    while(c--){
      int fi; cin >> fi; fi--;
      f.at(i).at(fi) = true;
    }
  }
  rep(j, n) rep(i, n){
    bool ok = p.at(i) <= p.at(j);
    rep(k, m) ok &= f.at(i).at(k) >= f.at(j).at(k);
    if(p.at(i) == p.at(j)){
      bool more = false;
      rep(k, m) more |= f.at(i).at(k) > f.at(j).at(k);
      ok &= more;
    }
    if(ok){
      // println("{} {}", i, j);
      println("Yes");
      return 0;
    }
  }
  println("No");
}
