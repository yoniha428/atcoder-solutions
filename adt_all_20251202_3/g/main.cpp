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
  vector<int> sq;
  for(int i = 1; i * i <= 200000; i++) sq.emplace_back(i * i);
  int ans = 0;
  rep(i, n){
    auto ai = a.at(i);
    if(ai == 0){
      ans += i;
      cnt.at(0)++;
      continue;
    }
    ans += cnt.at(0);
    int base = 1, w = ai;
    for(int p = 2; p * p <= w; p++){
      int cnt = 0;
      while(w % p == 0){
        cnt++;
        w /= p;
      }
      if(cnt % 2) base *= p;
    }
    if(w != 1) base *= w;
    for(auto sqi : sq){
      if(base * sqi > 200000) break;
      ans += cnt.at(base * sqi);
    }
    cnt.at(ai)++;
  }
  println("{}", ans);
}
/*
素因数分解して、数が奇数なところだけかけた数と、その平方数倍が候補になる
*/
