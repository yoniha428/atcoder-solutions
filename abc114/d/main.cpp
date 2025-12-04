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
  map<int, int> pq;
  for(int i = 2; i <= n; i++){
    int w = i;
    for(int p = 2; p * p <= w; p++){
      while(w % p == 0){
        w /= p;
        if(pq.contains(p)) pq.at(p)++;
        else pq.emplace(p, 1);
      }
    }
    if(w != 1){
      if(pq.contains(w)) pq.at(w)++;
      else pq.emplace(w, 1);
    }
  }
  // for(auto [p, q] : pq) cout << p << ' ' << q << '\n';

  vector<int> dp(76, 0);
  dp.at(1) = 1;
  for(auto [p, q] : pq){
    vector<int> next(76, 0);
    rep(i, 76) rep(j, q + 1){
      if(i * (j + 1) <= 75) next.at(i * (j + 1)) += dp.at(i);
    }
    dp = next;
  }

  cout << dp.at(75) << '\n';
}
/*
75数の性質を考えたい
平方数である必要がある
p1^q1*p2^q2*...と素因数分解したとき、
(q1+1)*(q2+1)*...が75である必要がある

*/
