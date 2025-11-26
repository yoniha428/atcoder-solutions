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
  int ans = 0;
  for(int a = 1; a < n; a++){
    for(int b = 1; a * b < n; b++){
      int cd = n - a * b, prod = 1;
      for(int p = 2; p * p <= cd; p++){
        int cnt = 0;
        while(cd % p == 0){
          cd /= p;
          cnt++;
        }
        prod *= cnt + 1;
      }
      if(cd != 1) prod *= 2;
      ans += prod;
    }
  }
  println("{}", ans);
}
