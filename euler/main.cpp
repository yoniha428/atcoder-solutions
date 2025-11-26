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
  vector<bool> isprime(n + 1, true); isprime.at(0) = isprime.at(1) = false;
  for(int p = 2; p <= n; p++){
    if(!isprime.at(p)) continue;
    for(int i = 2; i * p <= n; i++) isprime.at(i * p) = false;
  }
  for(int i = 9; i <= n; i += 2){
    if(isprime.at(i)) continue;
    bool ok = false;
    for(int p = 3; p < i; p++){
      if(!isprime.at(p)) continue;
      int root = sqrt((i - p) / 2);
      ok |= p + 2 * root * root == i;
    }
    if(!ok){
      println("{}", i);
      return 0;
    }
  }
}
/*

*/